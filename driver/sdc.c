#include <platform.h>
#include <fatfs.h>

#define HAL_SDC_USE_POLL FALSE

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/* Common flag combinations */
#define DW_MCI_DATA_ERROR_FLAGS	(SDHC_INT_DTO | SDHC_INT_DCRC | \
        SDHC_INT_HTO | SDHC_INT_SBE  | \
        SDHC_INT_EBE)
#define DW_MCI_CMD_ERROR_FLAGS	(SDHC_INT_RTO | SDHC_INT_RCRC | \
        SDHC_INT_RESP_ERR)
#define DW_MCI_ERROR_FLAGS	(DW_MCI_DATA_ERROR_FLAGS | \
        DW_MCI_CMD_ERROR_FLAGS  | SDHC_INT_HLE)

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

#define sg_len    ((48 * MMCSD_BLOCK_SIZE + 4096)/4096)

/**
 * @brief   SDCD0 driver identifier.
 */
SDCDriver SDCD0;

struct idmac_desc g_dmabuf[sg_len];
static uint32_t g_cardClk;
static uint32_t g_workClk;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   Buffer for temporary storage during unaligned transfers.
 */
static union {
  uint32_t  alignment;
  uint8_t   buf[MMCSD_BLOCK_SIZE];
} u;

static sd_dev_clk_t g_stSdTiming =
{
  SD_CLK_PHASE_0,
  -1,
  -1
};

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
#define __sd_setTiming(pstTiming)    CPM_SetSdDelay(pstTiming)

int _sd_timTaining(sd_dev_clk_t *pstTiming)
{
  for(; pstTiming->mclk_phase <= SD_CLK_PHASE_180; pstTiming->mclk_phase++)
  {
    for(; pstTiming->smp_half_cycles < 8; pstTiming->smp_half_cycles ++)
    {
      for(; pstTiming->drv_half_cycles < 8; pstTiming->drv_half_cycles ++)
      {
        __sd_setTiming(pstTiming);
        if(HAL_SUCCESS == sdcConnect(&SDCD0))
        {
          if(fsInit() == 0)
            return 0;
        }
      }

      pstTiming->drv_half_cycles = -1;
    }

    pstTiming->smp_half_cycles = -1;
  }

  return -1;
}
/**
 * @brief   Setup card clock.
 *
 * @param[in] cclk      card clock in Hz
 *
 * @notapi
 */
static void sdc_lld_setup_clock(SDCDriver *sdcp, uint32_t cclk) {

  uint32_t div, clk = g_workClk;

  div = clk / cclk;
  if (clk % cclk && clk > cclk)
    /* prevent over-clocking the card */
    div += 1;
  div = (clk != cclk) ? DIV_ROUND_UP(div, 2) : 0;

  /* disable clock and inform CIU */
  HS_SDHC->CLKENA = 0;
  HS_SDHC->CLKSRC = 0;
  sdc_lld_send_cmd_none(sdcp, SDHC_CMD_UPD_CLK, 0);

  /* set clock to desired speed */
  HS_SDHC->CLKDIV = div;
  sdc_lld_send_cmd_none(sdcp, SDHC_CMD_UPD_CLK, 0);

  /* enable clock; only low power if no SDIO */
  HS_SDHC->CLKENA  = (SDHC_CLKEN_ENABLE << sdcp->id) |
    (SDHC_CLKEN_LOW_PWR << sdcp->id);
  sdc_lld_send_cmd_none(sdcp, SDHC_CMD_UPD_CLK, 0);
}

/**
 * @brief   Setup IDMAC descriptor to start transfer data in DMA
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[out] buf      pointer to the DMA buffer
 * @param[in] n         number of blocks to read
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
static bool_t sdc_lld_setup_idmac(SDCDriver *sdcp, uint8_t *buf, uint32_t n) {

  struct idmac_desc *desc;
  uint32_t sg_length = (n * MMCSD_BLOCK_SIZE + 4096)/4096;
  (void)sdcp;
  
  if(sdcp->sg_length < sg_length){
    return HAL_FAILED;
  }
  /* dw_mci_translate_sglist */
  desc = sdcp->sg;

  /* Setting up data transfer.*/
  HS_SDHC->BYTCNT = n * MMCSD_BLOCK_SIZE;
  HS_SDHC->BLKSIZ = MMCSD_BLOCK_SIZE;

  osalDbgAssert(n * MMCSD_BLOCK_SIZE <= 4096 * 4, "too large");
  /* Enable the DMA interface */
  HS_SDHC->CTRL |= SDHC_CTRL_DMA_ENABLE;

  while (TRUE) {
    /* buffer size in 13-bit, 0x1FFF = 8191 */
    uint32_t len = min(n * MMCSD_BLOCK_SIZE, 4096);
    /* Set the OWN bit and disable interrupts for this descriptor */
    desc->des0 = IDMAC_DES0_OWN | IDMAC_DES0_DIC | IDMAC_DES0_CH;
    /* Buffer length */
    desc->des1 = len & 0x1fff;
    /* Physical address to DMA to/from */
    desc->des2 = (uint32_t)buf;
    
    n -= len / MMCSD_BLOCK_SIZE;
    if (n == 0)
      break;
    desc->des3 = (uint32_t)(desc + 1);
    buf += len;
    desc++;
  }

  /* Set first descriptor */
  sdcp->sg->des0 |= IDMAC_DES0_FD;
  /* Set last descriptor */
  desc->des0 &= ~(IDMAC_DES0_CH | IDMAC_DES0_DIC);
  desc->des0 |= IDMAC_DES0_LD;

  desc->des3 = (uint32_t)sdcp->sg;
  HS_SDHC->DBADDR = (uint32_t)sdcp->sg;
  
  /* if DMA transfer is done, DTO (Data Transfer Over) might not done */
  HS_SDHC->INTMASK = SDHC_INT_DATA_OVER;// | DW_MCI_DATA_ERROR_FLAGS;
  HS_SDHC->IDINTEN = SDHC_IDMAC_INT_NI;// | SDHC_IDMAC_INT_RI | SDHC_IDMAC_INT_TI;
#if !HAL_SD_USE_POLL
  HS_SDHC->CTRL |= SDHC_CTRL_INT_ENABLE;
#endif

  /* Select IDMAC interface */
  HS_SDHC->CTRL |= SDHC_CTRL_USE_IDMAC;
  /* Enable the IDMAC */
  HS_SDHC->BMOD |= SDHC_IDMAC_ENABLE | SDHC_IDMAC_FB;
  
  /* Start it running */
  HS_SDHC->PLDMND = 1;
  return HAL_SUCCESS;
}

/**
 * @brief   Prepares card to handle read transaction.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to read
 * @param[in] n         number of blocks to read
 * @param[in] resp      pointer to the response buffer
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
static bool_t sdc_lld_prepare_read(SDCDriver *sdcp, uint32_t startblk,
                                   uint32_t n, uint32_t *resp) {

  uint32_t cmd;

  /* Driver handles data in 512 bytes blocks (just like HC cards). But if we
     have not HC card than we must convert address from blocks to bytes.*/
  if (!(sdcp->cardmode & SDC_MODE_HIGH_CAPACITY))
    startblk *= MMCSD_BLOCK_SIZE;

  if (n > 1) {
    /* Send read multiple blocks command to card with auto stop. */
    cmd = MMCSD_CMD_READ_MULTIPLE_BLOCK | SDHC_CMD_SEND_STOP | SDHC_CMD_DAT_EXP;
    if (sdc_lld_send_cmd_short_crc(sdcp, cmd,
                                   startblk, resp) || MMCSD_R1_ERROR(resp[0]))
      return HAL_FAILED;
  }
  else{
    /* Send read single block command.*/
    cmd = MMCSD_CMD_READ_SINGLE_BLOCK | SDHC_CMD_DAT_EXP;
    if (sdc_lld_send_cmd_short_crc(sdcp, cmd,
                                   startblk, resp) || MMCSD_R1_ERROR(resp[0]))
      return HAL_FAILED;
  }

  return HAL_SUCCESS;
}

/**
 * @brief   Prepares card to handle write transaction.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to read
 * @param[in] n         number of blocks to write
 * @param[in] resp      pointer to the response buffer
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
static bool_t sdc_lld_prepare_write(SDCDriver *sdcp, uint32_t startblk,
                                    uint32_t n, uint32_t *resp) {

  uint32_t cmd;

  /* Driver handles data in 512 bytes blocks (just like HC cards). But if we
     have not HC card than we must convert address from blocks to bytes.*/
  if (!(sdcp->cardmode & SDC_MODE_HIGH_CAPACITY))
    startblk *= MMCSD_BLOCK_SIZE;

  if (n > 1) {
    /* Write multiple blocks command with auto stop. */
    cmd = MMCSD_CMD_WRITE_MULTIPLE_BLOCK | SDHC_CMD_SEND_STOP | SDHC_CMD_DAT_WR | SDHC_CMD_DAT_EXP | SDHC_CMD_HOLD;
    if (sdc_lld_send_cmd_short_crc(sdcp, cmd,
                                   startblk, resp) || MMCSD_R1_ERROR(resp[0]))
      return HAL_FAILED;
  }
  else{
    /* Write single block command.*/
    cmd = MMCSD_CMD_WRITE_BLOCK | SDHC_CMD_DAT_WR | SDHC_CMD_DAT_EXP | SDHC_CMD_HOLD;
    if (sdc_lld_send_cmd_short_crc(sdcp, cmd,
                                   startblk, resp) || MMCSD_R1_ERROR(resp[0]))
      return HAL_FAILED;
  }

  return HAL_SUCCESS;
}

/**
 * @brief   Wait end of data transaction and performs finalizations.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] n         number of blocks in transaction
 * @param[in] resp      pointer to the response buffer
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 */
static bool_t sdc_lld_wait_transaction_end(SDCDriver *sdcp, uint32_t n,
                                           uint32_t *resp) {

  uint32_t idsts, rintsts;
  (void)resp;

  while ((HS_SDHC->RINTSTS & SDHC_INT_DATA_OVER) == 0)
    ;

  /* Wait until IDMAC become idle.*/
  while (((HS_SDHC->IDSTS >> 13) & 0x0f) != 0) {
    HS_SDHC->PLDMND = 1;
  }

  /* DMA event flags must be manually cleared.*/
  idsts = HS_SDHC->IDSTS;
  HS_SDHC->IDSTS = idsts;
  rintsts = HS_SDHC->RINTSTS;
  HS_SDHC->RINTSTS = rintsts;

  /* Disable and reset the IDMAC interface */
  HS_SDHC->CTRL &= ~SDHC_CTRL_USE_IDMAC;
  HS_SDHC->CTRL |= SDHC_CTRL_DMA_RESET;
  //* Stop the IDMAC running */
  HS_SDHC->BMOD &= ~(SDHC_IDMAC_ENABLE | SDHC_IDMAC_FB);

  /* Make sure that data transfer over & no abnormal interrupt */
  if ((rintsts & (SDHC_INT_DATA_OVER | SDHC_INT_DCRC)) == 0) {
    return HAL_FAILED;
  }
  if ((idsts & SDHC_IDMAC_INT_AI) != 0) {
    return HAL_FAILED;
  } 

  /* Finalize transaction.*/
  if (n > 1) {
#if 1
    /* wait auto stop done */
    while ((rintsts & SDHC_INT_ACD) == 0)
      rintsts = HS_SDHC->RINTSTS;
    HS_SDHC->RINTSTS = rintsts;
#else
    return sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_STOP_TRANSMISSION, 0, resp);
#endif
  }

  return HAL_SUCCESS;
}

/**
 * @brief   Gets SDC errors.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] sta       value of the STA register
 *
 * @notapi
 */
static void sdc_lld_collect_errors(SDCDriver *sdcp, uint32_t sta) {
  uint32_t errors = SDC_NO_ERROR;

  if (sta & SDHC_INT_RCRC)
    errors |= SDC_CMD_CRC_ERROR;
  if (sta & SDHC_INT_DCRC)
    errors |= SDC_DATA_CRC_ERROR;
  if (sta & SDHC_INT_RTO)
    errors |= SDC_COMMAND_TIMEOUT;
  if (sta & SDHC_INT_DTO)
    errors |= SDC_DATA_TIMEOUT;
  if (sta & SDHC_INT_HTO) //FIXME
    errors |= SDC_TX_UNDERRUN;
  if (sta & SDHC_INT_FRUN)
    errors |= SDC_RX_OVERRUN;
  if (sta & SDHC_INT_SBE)
    errors |= SDC_STARTBIT_ERROR;

  sdcp->errors |= errors;
}

/**
 * @brief   Performs clean transaction stopping in case of errors.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] n         number of blocks in transaction
 * @param[in] resp      pointer to the response buffer
 *
 * @notapi
 */
static void sdc_lld_error_cleanup(SDCDriver *sdcp,
                                  uint32_t n,
                                  uint32_t *resp) {
  uint32_t sta;
  (void)resp;

  sta = HS_SDHC->IDSTS;
  HS_SDHC->IDSTS = sta;

  sta = HS_SDHC->RINTSTS;
  HS_SDHC->RINTSTS = sta;
  sdc_lld_collect_errors(sdcp, sta);
  if (n > 1) {
#if 1
    /* wait auto stop done */
    while ((sta & SDHC_INT_ACD) == 0)
      sta = HS_SDHC->RINTSTS;
    HS_SDHC->RINTSTS = sta;
#else
    sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_STOP_TRANSMISSION, 0, resp);
#endif
  }
}


/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/
static const struct SDCDriverVMT sdc_vmt = {
  (bool (*)(void *))sdc_lld_is_card_inserted,
  (bool (*)(void *))sdc_lld_is_write_protected,
  (bool (*)(void *))sdcConnect,
  (bool (*)(void *))sdcDisconnect,
  (bool (*)(void *, uint32_t, uint8_t *, uint32_t))sdcRead,
  (bool (*)(void *, uint32_t, const uint8_t *, uint32_t))sdcWrite,
  (bool (*)(void *))sdcSync,
  (bool (*)(void *, BlockDeviceInfo *))sdcGetInfo
};

void sdc_lld_init(SDCDriver *sdcp) {

  sdcp->vmt      = &sdc_vmt;
  sdcp->state    = BLK_STOP;
  sdcp->errors   = SDC_NO_ERROR;
  sdcp->config   = NULL;
  sdcp->capacity = 0;
  
  sdcp->id = 0; //one card only
  sdcp->sg_length = sg_len;
  sdcp->sg = g_dmabuf;
  sdcp->sdhc   = HS_SDHC;
}

/**
 * @brief   Configures and activates the SDC peripheral.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @notapi
 */
void sdc_lld_start(SDCDriver *sdcp) {

  uint32_t fifo_size;

  /* reset controller */
  HS_SDHC->CTRL   = SDHC_CTRL_RESET | SDHC_CTRL_FIFO_RESET | SDHC_CTRL_DMA_RESET;
  while (HS_SDHC->CTRL & (SDHC_CTRL_RESET | SDHC_CTRL_FIFO_RESET | SDHC_CTRL_DMA_RESET))
    ;

  HS_SDHC->RINTSTS = 0xFFFFFFFF; //clear interrupts
  HS_SDHC->INTMASK = 0; //disable all interrupt
  HS_SDHC->TMOUT   = 0xFFFFFFFF; //max timeout
  fifo_size = ((HS_SDHC->FIFOTH >> 16) & 0x0fff) + 1;
  HS_SDHC->FIFOTH  = (0x2 << 28 ) | ((fifo_size/2 - 1) << 16) | ((fifo_size/2) << 0); //burst size is 8

  /* disable clock to CIU */
  HS_SDHC->CLKENA = 0;
  HS_SDHC->CLKSRC = 0;

  /* enable interrupts: no for IDMAC */
  HS_SDHC->RINTSTS = 0xFFFFFFFF;
  //HS_SDHC->INTMASK = /*SDHC_INT_CMD_DONE | */SDHC_INT_DATA_OVER |
  //  SDHC_INT_TXDR | SDHC_INT_RXDR | DW_MCI_ERROR_FLAGS | SDHC_INT_CD;
#if !HAL_SD_USE_POLL
  HS_SDHC->CTRL    = SDHC_CTRL_INT_ENABLE;
#else
  HS_SDHC->CTRL    = 0;
#endif

  /* IDMAC */
  HS_SDHC->BMOD = SDHC_IDMAC_SWRESET;
  while (HS_SDHC->BMOD & SDHC_IDMAC_SWRESET)
    ;
  /* Mask out interrupts - get Tx & Rx complete only */
  HS_SDHC->IDSTS = 0xFFFFFFFF;
  HS_SDHC->IDINTEN = 0;//SDHC_IDMAC_INT_NI | SDHC_IDMAC_INT_RI | SDHC_IDMAC_INT_TI;

  /* FIXME: regulator enable via GPIO or SDHC */
  HS_SDHC->PWREN = 1 << sdcp->id;

  /* FIXME: get CD# or WP# via GPIO or SDHC */
  //present = HS_SDHC->CDETECT & (1 << sdcp->id) ? 0 : 1;
  //read_only = HS_SDHC->WRTPRT & (1 << sdcp->id) ? 1 : 0;
}

/**
 * @brief   Deactivates the SDC peripheral.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @notapi
 */
void sdc_lld_stop(SDCDriver *sdcp) {

  if (sdcp->state != BLK_STOP) {
    HS_SDHC->PWREN = 0;
    HS_SDHC->CLKENA = 0;
    HS_SDHC->INTMASK = 0;
    HS_SDHC->IDINTEN = 0;
    HS_SDHC->TMOUT   = 0;
  }
}

/**
 * @brief   Starts the SDIO clock and sets it to init mode (400kHz or less).
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @notapi
 */
void sdc_lld_start_clk(SDCDriver *sdcp) {

  (void)sdcp;

  usleep(100);
  
  /* Initial clock setting: 400kHz, 1bit mode.*/
  sdc_lld_setup_clock(sdcp, 400000);
  HS_SDHC->CTYPE = SDHC_CTYPE_1BIT << sdcp->id;
}

/**
 * @brief   Sets the SDIO clock to data mode (25MHz or less).
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @notapi
 */
void sdc_lld_set_data_clk(SDCDriver *sdcp) {

  sdc_lld_setup_clock(sdcp, g_cardClk);
}

/**
 * @brief   Stops the SDIO clock.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @notapi
 */
void sdc_lld_stop_clk(SDCDriver *sdcp) {

  (void)sdcp;

  /* disable clock and inform CIU */
  HS_SDHC->CLKENA = 0;
  HS_SDHC->CLKSRC = 0;
  sdc_lld_send_cmd_none(sdcp, SDHC_CMD_UPD_CLK, 0);
}

/**
 * @brief   Switches the bus to 4 bits mode.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] mode      bus mode
 *
 * @notapi
 */
void sdc_lld_set_bus_mode(SDCDriver *sdcp, sdcbusmode_t mode) {

  (void)sdcp;

  switch (mode) {
  case SDC_MODE_1BIT:
    HS_SDHC->CTYPE = SDHC_CTYPE_1BIT << sdcp->id;
    break;
  case SDC_MODE_4BIT:
    HS_SDHC->CTYPE = SDHC_CTYPE_4BIT << sdcp->id; 
    break;
  case SDC_MODE_8BIT:
    HS_SDHC->CTYPE = SDHC_CTYPE_8BIT << sdcp->id;
    break;
  }
}

/**
 * @brief   Sends an SDIO command with no response expected.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] cmd       card command
 * @param[in] arg       command argument
 *
 * @notapi
 */
void sdc_lld_send_cmd_none(SDCDriver *sdcp, uint32_t cmd, uint32_t arg) {

  (void)sdcp;

  HS_SDHC->CMDARG = arg;
  /* FIXME: Send initialization sequence (80 clocks) before sending this command */
  if (MMCSD_CMD_GO_IDLE_STATE == cmd) {
    cmd |= SDHC_CMD_INIT;
  }
  HS_SDHC->CMD = cmd | SDHC_CMD_START;

  if (cmd & SDHC_CMD_UPD_CLK) {
    /* internal command needn't command done interrupt */
    while ((HS_SDHC->CMD & SDHC_CMD_START) != 0)
      ;
    HS_SDHC->RINTSTS = 0xFFFFFFFF; //clear interrupts
  } else {
    uint32_t rintsts;
    while (((rintsts = HS_SDHC->RINTSTS) & SDHC_INT_CMD_DONE) == 0)
      ;
    HS_SDHC->RINTSTS = rintsts;
  }
}

/**
 * @brief   Sends an SDIO command with a short response expected.
 * @note    The CRC is not verified.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] cmd       card command
 * @param[in] arg       command argument
 * @param[out] resp     pointer to the response buffer (one word)
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
bool sdc_lld_send_cmd_short(SDCDriver *sdcp, uint32_t cmd, uint32_t arg,
                              uint32_t *resp) {

  uint32_t rintsts;
  (void)sdcp;

  HS_SDHC->CMDARG = arg;
  HS_SDHC->CMD = cmd | SDHC_CMD_START | SDHC_CMD_RESP_EXP;
  /* command done means command sent & response received or response timeout */
  while (((rintsts = HS_SDHC->RINTSTS) &
	  (SDHC_INT_CMD_DONE /*| SDHC_INT_ERROR*/)) == 0)
    ;
  HS_SDHC->RINTSTS = SDHC_INT_CMD_DONE | SDHC_INT_ERROR;//rintsts;
  if ((rintsts & SDHC_INT_ERROR) != 0) {
    sdc_lld_collect_errors(sdcp, rintsts);
    return HAL_FAILED;
  }
  *resp = HS_SDHC->RESP0;
  return HAL_SUCCESS;
}

/**
 * @brief   Sends an SDIO command with a short response expected and CRC.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] cmd       card command
 * @param[in] arg       command argument
 * @param[out] resp     pointer to the response buffer (one word)
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
bool sdc_lld_send_cmd_short_crc(SDCDriver *sdcp, uint32_t cmd, uint32_t arg,
                                  uint32_t *resp) {

  uint32_t rintsts;
  (void)sdcp;

  HS_SDHC->CMDARG = arg;
  HS_SDHC->CMD = cmd | SDHC_CMD_START | SDHC_CMD_RESP_EXP | SDHC_CMD_RESP_CRC;
  while (((rintsts = HS_SDHC->RINTSTS) &
	  (SDHC_INT_CMD_DONE /*| SDHC_INT_ERROR*/)) == 0)
    ;
  HS_SDHC->RINTSTS = SDHC_INT_CMD_DONE | SDHC_INT_ERROR;//rintsts;
  if ((rintsts & SDHC_INT_ERROR) != 0) {
    sdc_lld_collect_errors(sdcp, rintsts);
    return HAL_FAILED;
  }
  *resp = HS_SDHC->RESP0;
  return HAL_SUCCESS;
}

/**
 * @brief   Sends an SDIO command with a long response expected and CRC.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] cmd       card command
 * @param[in] arg       command argument
 * @param[out] resp     pointer to the response buffer (four words)
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
bool sdc_lld_send_cmd_long_crc(SDCDriver *sdcp, uint32_t cmd, uint32_t arg,
                                 uint32_t *resp) {

  uint32_t rintsts;
  (void)sdcp;

  HS_SDHC->CMDARG = arg;
  HS_SDHC->CMD = cmd | SDHC_CMD_START | SDHC_CMD_RESP_EXP | SDHC_CMD_RESP_LONG | SDHC_CMD_RESP_CRC;
  while (((rintsts = HS_SDHC->RINTSTS) &
	  (SDHC_INT_CMD_DONE /*| SDHC_INT_ERROR*/)) == 0)
    ;
  HS_SDHC->RINTSTS = SDHC_INT_CMD_DONE | SDHC_INT_ERROR;//rintsts;
  if ((rintsts & SDHC_INT_ERROR) != 0) {
    sdc_lld_collect_errors(sdcp, rintsts);
    return HAL_FAILED;
  }
  *resp++ = HS_SDHC->RESP0; //LSB
  *resp++ = HS_SDHC->RESP1;
  *resp++ = HS_SDHC->RESP2;
  *resp   = HS_SDHC->RESP3; //MSB
  return HAL_SUCCESS;
}

/**
 * @brief   Reads one or more blocks.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to read
 * @param[out] buf      pointer to the read buffer
 * @param[in] n         number of blocks to read
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
bool sdc_lld_read_aligned(SDCDriver *sdcp, uint32_t startblk,
                            uint8_t *buf, uint32_t n) {
  uint32_t resp[1];

  osalDbgAssert((n <= sg_len), " ");

  /* Checks for errors and waits for the card to be ready for reading.*/
  if (_sdc_wait_for_transfer_state(sdcp))
    return HAL_FAILED;

  if (sdc_lld_setup_idmac(sdcp, (uint8_t *)buf, n))
    return HAL_FAILED;

  /* Talk to card what we want from it.*/
  if (sdc_lld_prepare_read(sdcp, startblk, n, resp) == TRUE)
    goto error;

  if (sdc_lld_wait_transaction_end(sdcp, n, resp) == TRUE)
    goto error;

  return HAL_SUCCESS;

error:
  sdc_lld_error_cleanup(sdcp, n, resp);
  return HAL_FAILED;
}

/**
 * @brief   Writes one or more blocks.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to write
 * @param[out] buf      pointer to the write buffer
 * @param[in] n         number of blocks to write
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
bool sdc_lld_write_aligned(SDCDriver *sdcp, uint32_t startblk,
                             const uint8_t *buf, uint32_t n) {
  uint32_t resp[1];

  osalDbgAssert((n <= sg_len), " ");

  /* Checks for errors and waits for the card to be ready for writing.*/
  if (_sdc_wait_for_transfer_state(sdcp))
    return HAL_FAILED;

  if (sdc_lld_setup_idmac(sdcp, (uint8_t *)buf, n))
    return HAL_FAILED;

  /* Talk to card what we want from it.*/
  if (sdc_lld_prepare_write(sdcp, startblk, n, resp) == TRUE)
    goto error;

  if (sdc_lld_wait_transaction_end(sdcp, n, resp) == TRUE)
    goto error;

  return HAL_SUCCESS;

error:
  sdc_lld_error_cleanup(sdcp, n, resp);
  return HAL_FAILED;
}

/**
 * @brief   Reads one or more blocks.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to read
 * @param[out] buf      pointer to the read buffer
 * @param[in] n         number of blocks to read
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
bool sdc_lld_read(SDCDriver *sdcp, uint32_t startblk,
                    uint8_t *buf, uint32_t n) {

  if (((unsigned)buf & 3) != 0) {
    uint32_t i;
    for (i = 0; i < n; i++) {
      if (sdc_lld_read_aligned(sdcp, startblk, u.buf, 1))
        return HAL_FAILED;
      memcpy(buf, u.buf, MMCSD_BLOCK_SIZE);
      buf += MMCSD_BLOCK_SIZE;
      startblk++;
    }
    return HAL_SUCCESS;
  }
  return sdc_lld_read_aligned(sdcp, startblk, buf, n);
}

/**
 * @brief   Writes one or more blocks.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @param[in] startblk  first block to write
 * @param[out] buf      pointer to the write buffer
 * @param[in] n         number of blocks to write
 *
 * @return              The operation status.
 * @retval CH_SUCCESS  operation succeeded.
 * @retval CH_FAILED    operation failed.
 *
 * @notapi
 */
bool sdc_lld_write(SDCDriver *sdcp, uint32_t startblk,
                     const uint8_t *buf, uint32_t n) {

  if (((unsigned)buf & 3) != 0) {
    uint32_t i;
    for (i = 0; i < n; i++) {
      memcpy(u.buf, buf, MMCSD_BLOCK_SIZE);
      buf += MMCSD_BLOCK_SIZE;
      if (sdc_lld_write_aligned(sdcp, startblk, u.buf, 1))
        return HAL_FAILED;
      startblk++;
    }
    return HAL_SUCCESS;
  }
  return sdc_lld_write_aligned(sdcp, startblk, buf, n);
}

/**
 * @brief   Waits for card idle condition.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 *
 * @return              The operation status.
 * @retval CH_SUCCESS   the operation succeeded.
 * @retval CH_FAILED    the operation failed.
 *
 * @api
 */
bool sdc_lld_sync(SDCDriver *sdcp) {

  (void)sdcp;
 
  return HAL_SUCCESS;
}

/**
 * @brief   Returns the card insertion status.
 *
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @return              The card state.
 * @retval FALSE        card not inserted.
 * @retval TRUE         card inserted.
 *
 * @api
 */
bool_t sdc_lld_is_card_inserted(SDCDriver *sdcp, int pos) {

  (void)sdcp;
  (void)pos;

  return TRUE;
}

/**
 * @brief   Returns the write protect status.
 * @param[in] sdcp      pointer to the @p SDCDriver object
 * @return              The card state.
 * @retval FALSE        not write protected.
 * @retval TRUE         write protected.
 *
 * @api
 */
bool_t sdc_lld_is_write_protected(SDCDriver *sdcp){

  (void)sdcp;

  return FALSE;
}







uint32_t _mmcsd_get_slice(const uint32_t *data,
                          uint32_t end,
                          uint32_t start) {
  unsigned startidx, endidx, startoff;
  uint32_t endmask;

  startidx = start / 32U;
  startoff = start % 32U;
  endidx   = end / 32U;
  endmask  = ((uint64_t)1U << ((end % 32U) + 1U)) - 1U; /* nds32le-elf-gcc workaround */

  /* One or two pieces?*/
  if (startidx < endidx) {
    return (data[startidx] >> startoff) |               /* Two pieces case. */
           ((data[endidx] & endmask) << (32U - startoff));
  }
  return (data[startidx] & endmask) >> startoff;        /* One piece case.  */
}


uint32_t _mmcsd_get_capacity(const uint32_t *csd) {
  uint32_t a, b, c;

  switch (_mmcsd_get_slice(csd, MMCSD_CSD_10_CSD_STRUCTURE_SLICE)) {
  case 0:
    /* CSD version 1.0 */
    a = _mmcsd_get_slice(csd, MMCSD_CSD_10_C_SIZE_SLICE);
    b = _mmcsd_get_slice(csd, MMCSD_CSD_10_C_SIZE_MULT_SLICE);
    c = _mmcsd_get_slice(csd, MMCSD_CSD_10_READ_BL_LEN_SLICE);
    return ((a + 1U) << (b + 2U)) << (c - 9U);  /* 2^9 == MMCSD_BLOCK_SIZE. */
  case 1:
    /* CSD version 2.0.*/
    return 1024U * (_mmcsd_get_slice(csd, MMCSD_CSD_20_C_SIZE_SLICE) + 1U);
  default:
    /* Reserved value detected.*/
    break;
  }
  return 0U;
}

bool _sdc_wait_for_transfer_state(SDCDriver *sdcp) {
  uint32_t resp[1];
  int tmp;

  while (TRUE) {
    if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_SEND_STATUS,
                                   sdcp->rca, resp) ||
        MMCSD_R1_ERROR(resp[0])) {
      return HAL_FAILED;
    }

    switch (MMCSD_R1_STS(resp[0])) {
    case MMCSD_STS_TRAN:
      return HAL_SUCCESS;
    case MMCSD_STS_DATA:
    case MMCSD_STS_RCV:
    case MMCSD_STS_PRG:
      tmp=0x10000;
      while(tmp--);
      continue;
    default:
      /* The card should have been initialized so any other state is not
         valid and is reported as an error.*/
      return HAL_FAILED;
    }
  }
}





bool sdcConnect(SDCDriver *sdcp) {
  uint32_t resp[1];

  osalDbgAssert((sdcp->state == BLK_ACTIVE) || (sdcp->state == BLK_READY),
                "invalid state");

  /* Connection procedure in progress.*/
  sdcp->state = BLK_CONNECTING;

  /* Card clock initialization.*/
  sdc_lld_start_clk(sdcp);

  /* Enforces the initial card state.*/
  sdc_lld_send_cmd_none(sdcp, MMCSD_CMD_GO_IDLE_STATE, 0);

  /* V2.0 cards detection.*/
  if (!sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_SEND_IF_COND,
                                  MMCSD_CMD8_PATTERN, resp)) {
    sdcp->cardmode = SDC_MODE_CARDTYPE_SDV20;
    /* Voltage verification.*/
    if (((resp[0] >> 8) & 0xF) != 1)
      goto failed;
    if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_APP_CMD, 0, resp) ||
        MMCSD_R1_ERROR(resp[0]))
      goto failed;
  }
  else {
    sdcp->cardmode = SDC_MODE_CARDTYPE_SDV11;
    sdc_lld_send_cmd_none(sdcp, MMCSD_CMD_GO_IDLE_STATE, 0);
  }

  {
    unsigned i;
    uint32_t ocr;

    /* SD initialization.*/
    if ((sdcp->cardmode &  SDC_MODE_CARDTYPE_MASK) == SDC_MODE_CARDTYPE_SDV20)
      ocr = 0xC0100000;
    else
      ocr = 0x80100000;

    /* SD-type initialization. */
    i = 0;
    while (TRUE) {
      if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_APP_CMD, 0, resp) ||
        MMCSD_R1_ERROR(resp[0]))
        goto failed;
      if (sdc_lld_send_cmd_short(sdcp, MMCSD_CMD_APP_OP_COND, ocr, resp))
        goto failed;
      if ((resp[0] & 0x80000000) != 0) {
        if (resp[0] & 0x40000000)
          sdcp->cardmode |= SDC_MODE_HIGH_CAPACITY;
        break;
      }
      if (++i >= SDC_INIT_RETRY)
        goto failed;

      int tmp=0x100000;
      while(tmp--) ;      
    }
  }

  /* Reads CID.*/
  if (sdc_lld_send_cmd_long_crc(sdcp, MMCSD_CMD_ALL_SEND_CID, 0, sdcp->cid)) {
    goto failed;
  }

  /* Asks for the RCA.*/
  if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_SEND_RELATIVE_ADDR,
                                 0, &sdcp->rca)) {
    goto failed;
  }

  /* Reads CSD.*/
  if (sdc_lld_send_cmd_long_crc(sdcp, MMCSD_CMD_SEND_CSD,
                                sdcp->rca, sdcp->csd))
    goto failed;

  /* Switches to high speed.*/
  sdc_lld_set_data_clk(sdcp);

  /* Selects the card for operations.*/
  if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_SEL_DESEL_CARD,
                                 sdcp->rca, resp))
    goto failed;

  /* Block length fixed at 512 bytes.*/
  if (sdc_lld_send_cmd_short_crc(sdcp, MMCSD_CMD_SET_BLOCKLEN,
                                 MMCSD_BLOCK_SIZE, resp) ||
      MMCSD_R1_ERROR(resp[0])) {
    goto failed;
  }
  
  /* Determine capacity.*/
  sdcp->capacity = _mmcsd_get_capacity(sdcp->csd);  //, sdcp->cardmode & SDC_MODE_HIGH_CAPACITY);
  if (sdcp->capacity == 0)
    goto failed;

  /* Initialization complete.*/
  sdcp->state = BLK_READY;
  return HAL_SUCCESS;

  /* Connection failed, state reset to BLK_ACTIVE.*/
failed:
  sdc_lld_stop_clk(sdcp);
  sdcp->state = BLK_ACTIVE;
  return HAL_FAILED;
}

bool sdcDisconnect(SDCDriver *sdcp) {

  osalDbgAssert((sdcp->state == BLK_ACTIVE) || (sdcp->state == BLK_READY),
                "invalid state");
  if (sdcp->state == BLK_ACTIVE) {
    return HAL_SUCCESS;
  }
  sdcp->state = BLK_DISCONNECTING;

  /* Waits for eventual pending operations completion.*/
  if (_sdc_wait_for_transfer_state(sdcp)) {
    sdc_lld_stop_clk(sdcp);
    sdcp->state = BLK_ACTIVE;
    return HAL_FAILED;
  }

  /* Card clock stopped.*/
  sdc_lld_stop_clk(sdcp);
  sdcp->state = BLK_ACTIVE;
  return HAL_SUCCESS;
}

bool sdcRead(SDCDriver *sdcp, uint32_t startblk, uint8_t *buf, uint32_t n) {
  bool status;

  osalDbgAssert(sdcp->state == BLK_READY, "invalid state");

  if ((startblk + n - 1U) > sdcp->capacity){
    sdcp->errors |= SDC_OVERFLOW_ERROR;
    return HAL_FAILED;
  }

  /* Read operation in progress.*/
  sdcp->state = BLK_READING;

  status = sdc_lld_read(sdcp, startblk, buf, n);

  /* Read operation finished.*/
  sdcp->state = BLK_READY;
  return status;
}

bool sdcWrite(SDCDriver *sdcp, uint32_t startblk,
              const uint8_t *buf, uint32_t n) {
  bool status;

  osalDbgAssert(sdcp->state == BLK_READY, "invalid state");

  if ((startblk + n - 1U) > sdcp->capacity){
    sdcp->errors |= SDC_OVERFLOW_ERROR;
    return HAL_FAILED;
  }

  /* Write operation in progress.*/
  sdcp->state = BLK_WRITING;

  status = sdc_lld_write(sdcp, startblk, buf, n);

  /* Write operation finished.*/
  sdcp->state = BLK_READY;
  return status;
}

bool sdcSync(SDCDriver *sdcp) {
  bool result;

  if (sdcp->state != BLK_READY) {
    return HAL_FAILED;
  }

  /* Synchronization operation in progress.*/
  sdcp->state = BLK_SYNCING;

  result = sdc_lld_sync(sdcp);

  /* Synchronization operation finished.*/
  sdcp->state = BLK_READY;
  return result;
}

bool sdcGetInfo(SDCDriver *sdcp, BlockDeviceInfo *bdip) {

  if (sdcp->state != BLK_READY) {
    return HAL_FAILED;
  }

  bdip->blk_num = sdcp->capacity;
  bdip->blk_size = MMCSD_BLOCK_SIZE;

  return HAL_SUCCESS;
}

int sdcStart(SDCDriver *sdcp, const SDCConfig *config) {
  if (sdcp == NULL) {
    return SDCD_ERROR_NULLPTR;
  }

  sdc_lld_init(sdcp);

  if ((sdcp->state != BLK_STOP) && (sdcp->state != BLK_ACTIVE)) {
    return SDCD_ERROR_STATE;
  }
  
  sdcp->config = config;
  sdc_lld_start(sdcp);
  sdcp->state = BLK_ACTIVE;
  return 0;
}

void sdSetPad(void)
{
  GPIO_Config io_cfg1 = {GPIO_DIR_OUTPUT, GPIO_PULL_NO, GPIO_DRV_3, GPIO_MODE_SD};
  GPIO_Config io_cfg2 = {GPIO_DIR_INPUT, GPIO_PULL_UP, GPIO_DRV_3, GPIO_MODE_SD};

  GPIO_PinConfigure(GPIO0, 10, &io_cfg1);
  GPIO_PinConfigure(GPIO0,  6, &io_cfg2);
  GPIO_PinConfigure(GPIO0,  8, &io_cfg2);
}

int sdInit(void)
{
  if(0 == CPM_GetVersion())
  {
    g_cardClk = 12000000;
    g_workClk = 24000000;
  }
  else
  {
    g_cardClk = 4000000;
    g_workClk = 4000000;
  }
  
  CPM_CfgModuleClk(CPM_MODULE_SD, g_workClk);
  sdSetPad();
  
  sdcStart(&SDCD0, NULL);

  return _sd_timTaining(&g_stSdTiming);
}


/** @} */
