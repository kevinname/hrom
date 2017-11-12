
#ifndef __IOBLOCK_H__
#define __IOBLOCK_H__

#include "stdbool.h"

/**
 * @brief   Driver state machine possible states.
 */
typedef enum {
  BLK_UNINIT = 0,                   /**< Not initialized.                   */
  BLK_STOP = 1,                     /**< Stopped.                           */
  BLK_ACTIVE = 2,                   /**< Interface active.                  */
  BLK_CONNECTING = 3,               /**< Connection in progress.            */
  BLK_DISCONNECTING = 4,            /**< Disconnection in progress.         */
  BLK_READY = 5,                    /**< Device ready.                      */
  BLK_READING = 6,                  /**< Read operation in progress.        */
  BLK_WRITING = 7,                  /**< Write operation in progress.       */
  BLK_SYNCING = 8                   /**< Sync. operation in progress.       */
} blkstate_t;

/**
 * @brief   Block device info.
 */
typedef struct {
  uint32_t      blk_size;           /**< @brief Block size in bytes.        */
  uint32_t      blk_num;            /**< @brief Total number of blocks.     */
} BlockDeviceInfo;

/**
 * @brief   @p BaseBlockDevice specific methods.
 */
#define _base_block_device_methods                                          \
  /* Removable media detection.*/                                           \
  bool (*is_inserted)(void *instance);                                      \
  /* Removable write protection detection.*/                                \
  bool (*is_protected)(void *instance);                                     \
  /* Connection to the block device.*/                                      \
  bool (*connect)(void *instance);                                          \
  /* Disconnection from the block device.*/                                 \
  bool (*disconnect)(void *instance);                                       \
  /* Reads one or more blocks.*/                                            \
  bool (*read)(void *instance, uint32_t startblk,                           \
                 uint8_t *buffer, uint32_t n);                              \
  /* Writes one or more blocks.*/                                           \
  bool (*write)(void *instance, uint32_t startblk,                          \
                  const uint8_t *buffer, uint32_t n);                       \
  /* Write operations synchronization.*/                                    \
  bool (*sync)(void *instance);                                             \
  /* Obtains info about the media.*/                                        \
  bool (*get_info)(void *instance, BlockDeviceInfo *bdip);

/**
 * @brief   @p BaseBlockDevice specific data.
 */
#define _base_block_device_data                                             \
  /* Driver state.*/                                                        \
  blkstate_t            state;

/**
 * @brief   @p BaseBlockDevice virtual methods table.
 */
struct BaseBlockDeviceVMT {
  _base_block_device_methods
};

/**
 * @brief   Base block device class.
 * @details This class represents a generic, block-accessible, device.
 */
typedef struct {
  /** @brief Virtual Methods Table.*/
  const struct BaseBlockDeviceVMT *vmt;
  _base_block_device_data
} BaseBlockDevice;

/**
 * @name    Macro Functions (BaseBlockDevice)
 * @{
 */
/**
 * @brief   Returns the driver state.
 * @note    Can be called in ISR context.
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 *
 * @return              The driver state.
 *
 * @special
 */
#define blkGetDriverState(ip) ((ip)->state)

/**
 * @brief   Determines if the device is transferring data.
 * @note    Can be called in ISR context.
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 *
 * @return              The driver state.
 * @retval FALSE        the device is not transferring data.
 * @retval TRUE         the device not transferring data.
 *
 * @special
 */
#define blkIsTransferring(ip) ((((ip)->state) == BLK_CONNECTING) ||         \
                               (((ip)->state) == BLK_DISCONNECTING) ||      \
                               (((ip)->state) == BLK_READING) ||            \
                               (((ip)->state) == BLK_WRITING))

/**
 * @brief   Returns the media insertion status.
 * @note    On some implementations this function can only be called if the
 *          device is not transferring data.
 *          The function @p blkIsTransferring() should be used before calling
 *          this function.
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 *
 * @return              The media state.
 * @retval FALSE        media not inserted.
 * @retval TRUE         media inserted.
 *
 * @api
 */
#define blkIsInserted(ip) ((ip)->vmt->is_inserted(ip))

/**
 * @brief   Returns the media write protection status.
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 *
 * @return              The media state.
 * @retval FALSE        writable media.
 * @retval TRUE         non writable media.
 *
 * @api
 */
#define blkIsWriteProtected(ip) ((ip)->vmt->is_protected(ip))

/**
 * @brief   Performs the initialization procedure on the block device.
 * @details This function should be performed before I/O operations can be
 *          attempted on the block device and after insertion has been
 *          confirmed using @p blkIsInserted().
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @api
 */
#define blkConnect(ip) ((ip)->vmt->connect(ip))

/**
 * @brief   Terminates operations on the block device.
 * @details This operation safely terminates operations on the block device.
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @api
 */
#define blkDisconnect(ip) ((ip)->vmt->disconnect(ip))

/**
 * @brief   Reads one or more blocks.
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 * @param[in] startblk  first block to read
 * @param[out] buf      pointer to the read buffer
 * @param[in] n         number of blocks to read
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @api
 */
#define blkRead(ip, startblk, buf, n)                                       \
  ((ip)->vmt->read(ip, startblk, buf, n))

/**
 * @brief   Writes one or more blocks.
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 * @param[in] startblk  first block to write
 * @param[out] buf      pointer to the write buffer
 * @param[in] n         number of blocks to write
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @api
 */
#define blkWrite(ip, startblk, buf, n)                                      \
  ((ip)->vmt->write(ip, startblk, buf, n))

/**
 * @brief   Ensures write synchronization.
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @api
 */
#define blkSync(ip) ((ip)->vmt->sync(ip))

/**
 * @brief   Returns a media information structure.
 *
 * @param[in] ip        pointer to a @p BaseBlockDevice or derived class
 * @param[out] bdip     pointer to a @p BlockDeviceInfo structure
 *
 * @return              The operation status.
 * @retval HAL_SUCCESS  operation succeeded.
 * @retval HAL_FAILED   operation failed.
 *
 * @api
 */
#define blkGetInfo(ip, bdip) ((ip)->vmt->get_info(ip, bdip))

/** @} */


#define SDHC_CTRL_USE_IDMAC         (1UL << 25)
#define SDHC_CTRL_ENABLE_OD_PULLUP	(1UL << 24) //1-open-drain
#define SDHC_CTRL_CARD_VOLTAGE_B(n)	((n) << 20) //optinal for regulator-B
#define SDHC_CTRL_CARD_VOLTAGE_A(n)	((n) << 16)
#define SDHC_CTRL_CEATA_INT_EN      (1UL << 11) //CE-ATA
#define SDHC_CTRL_SEND_AS_CCSD      (1UL << 10) //CE-ATA
#define SDHC_CTRL_SEND_CCSD         (1UL << 9)  //CE-ATA
#define SDHC_CTRL_ABRT_READ_DATA    (1UL << 8)  //for SDIO suspend occurs
#define SDHC_CTRL_SEND_IRQ_RESP     (1UL << 7)  //send MMC CMD40's response
#define SDHC_CTRL_READ_WAIT         (1UL << 6)  //0-clear 1-assert for SDIO 
#define SDHC_CTRL_DMA_ENABLE        (1UL << 5)
#define SDHC_CTRL_INT_ENABLE        (1UL << 4)
#define SDHC_CTRL_DMA_RESET         (1UL << 2)  //auto clear for all reset bits
#define SDHC_CTRL_FIFO_RESET        (1UL << 1)
#define SDHC_CTRL_RESET             (1UL << 0)

/*******************  Bit definition for SDHC_PWREN register  *****************/
#define SDHC_PWREN_ENABLE		(1UL << 0)  //optional for power switch

/*******************  Bit definition for SDHC_CLKDIV register *****************/
#define CLK_DIVIDER0_MSK        ((uint32)0xFF)                             /*!< clock divider: Fcclk_out = Fcclk / (CLK_DIVIDER0 * 2) */

/*******************  Bit definition for SDHC_CLKSRC register *****************/
#define CLK_SOURCE_MSK          ((uint32)0x3)                             /*!< clock source is always 0, i.e. CLK_DIVIDER0 */

/* Clock Enable register defines */
#define SDHC_CLKEN_LOW_PWR          (1UL << 16) //1-stop clock if card idle
#define SDHC_CLKEN_ENABLE           (1UL << 0)

/* time-out register defines */
#define SDHC_TMOUT_DATA(n)          ((n) << 8)
#define SDHC_TMOUT_DATA_MSK         0xFFFFFF00
#define SDHC_TMOUT_RESP(n)          ((n) & 0xFF)
#define SDHC_TMOUT_RESP_MSK         0xFF

/* card-type register defines */
#define SDHC_CTYPE_8BIT		(1UL << 16)
#define SDHC_CTYPE_4BIT		(1UL << 0)
#define SDHC_CTYPE_1BIT		0

/* Interrupt status & mask register defines */
#define SDHC_INT_SDIO(n)		(1UL << (16 + (n)))
#define SDHC_INT_EBE			(1UL << 15) //End Bit Error
#define SDHC_INT_ACD			(1UL << 14) //Auto Command Done
#define SDHC_INT_SBE			(1UL << 13) //Start Bit Error
#define SDHC_INT_HLE			(1UL << 12) //Hardware Locked Error
#define SDHC_INT_FRUN			(1UL << 11) //FIFO UnderrunOverrun Error
#define SDHC_INT_HTO			(1UL << 10) //Data Starvation 
#define SDHC_INT_DTO			(1UL << 9) //Data Read TimeOut
#define SDHC_INT_RTO			(1UL << 8) //Response TimeOut
#define SDHC_INT_DCRC			(1UL << 7) //Data CRC Error
#define SDHC_INT_RCRC			(1UL << 6) //Response CRC Error
#define SDHC_INT_RXDR			(1UL << 5) //Receive FIFO Data Request
#define SDHC_INT_TXDR			(1UL << 4) //Transmit FIFO Data Request
#define SDHC_INT_DATA_OVER		(1UL << 3) //Data Transfer Over
#define SDHC_INT_CMD_DONE		(1UL << 2) //Command Done
#define SDHC_INT_RESP_ERR		(1UL << 1) //Response Error
#define SDHC_INT_CD			(1UL << 0) //Card Detect
#define SDHC_INT_ERROR			0xbfc2

/* Command register defines */
#define SDHC_CMD_START			(1UL << 31)
#define SDHC_CMD_CCS_EXP		(1UL << 23)
#define SDHC_CMD_HOLD				(1UL << 29)
#define SDHC_CMD_CEATA_RD		(1UL << 22)
#define SDHC_CMD_UPD_CLK		(1UL << 21)
#define SDHC_CMD_INIT			(1UL << 15)
#define SDHC_CMD_STOP			(1UL << 14)
#define SDHC_CMD_PRV_DAT_WAIT		(1UL << 13)
#define SDHC_CMD_SEND_STOP		(1UL << 12)
#define SDHC_CMD_STRM_MODE		(1UL << 11) //0-block; 1-stream mode
#define SDHC_CMD_DAT_WR			(1UL << 10) //0-read;  1-write
#define SDHC_CMD_DAT_EXP		(1UL << 9)  //0-no data expected
#define SDHC_CMD_RESP_CRC		(1UL << 8)
#define SDHC_CMD_RESP_LONG		(1UL << 7)
#define SDHC_CMD_RESP_EXP		(1UL << 6)
#define SDHC_CMD_INDX(n)		((n) & 0x1F)

/* Status register defines */
#define SDHC_STATUS_DMA_REQ		(1UL << 31)
#define SDHC_STATUS_DMA_ACK		(1UL << 30)
#define SDHC_GET_FCNT(x)		(((x)>>17) & 0x1FFF)
#define SDHC_STATUS_DATA0_BUSY		(1UL << 9) //card busy:    !cdata[0]
#define SDHC_STATUS_DATA3_CD		(1UL << 8) //card present: !cdata[3]
#define SDHC_STATUS_FIFO_FULL		(1UL << 3)
#define SDHC_STATUS_FIFO_EMPTY		(1UL << 2)

/* Internal DMAC interrupt defines */
#define SDHC_IDMAC_INT_AI		(1UL << 9) //abnormal: FBE, DU, CES
#define SDHC_IDMAC_INT_NI		(1UL << 8) //normal:   TI, RI
#define SDHC_IDMAC_INT_CES		(1UL << 5) //card error interrupt
#define SDHC_IDMAC_INT_DU		(1UL << 4) //descriptor unavailable
#define SDHC_IDMAC_INT_FBE		(1UL << 2) //fatal bus error
#define SDHC_IDMAC_INT_RI		(1UL << 1)
#define SDHC_IDMAC_INT_TI		(1UL << 0)

/* Internal DMAC bus mode bits */
#define SDHC_IDMAC_ENABLE		(1UL << 7)
#define SDHC_IDMAC_FB			(1UL << 1) //fixed burst
#define SDHC_IDMAC_SWRESET		(1UL << 0)

#define MMCSD_BLOCK_SIZE                512U
#define MMCSD_R1_ERROR_MASK             0xFDFFE008U
#define MMCSD_CMD8_PATTERN              0x000001AAU

#define MMCSD_STS_IDLE                  0U
#define MMCSD_STS_READY                 1U
#define MMCSD_STS_IDENT                 2U
#define MMCSD_STS_STBY                  3U
#define MMCSD_STS_TRAN                  4U
#define MMCSD_STS_DATA                  5U
#define MMCSD_STS_RCV                   6U
#define MMCSD_STS_PRG                   7U
#define MMCSD_STS_DIS                   8U

#define MMCSD_CMD_GO_IDLE_STATE         0U
#define MMCSD_CMD_INIT                  1U
#define MMCSD_CMD_ALL_SEND_CID          2U
#define MMCSD_CMD_SEND_RELATIVE_ADDR    3U
#define MMCSD_CMD_SET_BUS_WIDTH         6U
#define MMCSD_CMD_SWITCH                MMCSD_CMD_SET_BUS_WIDTH
#define MMCSD_CMD_SEL_DESEL_CARD        7U
#define MMCSD_CMD_SEND_IF_COND          8U
#define MMCSD_CMD_SEND_EXT_CSD          MMCSD_CMD_SEND_IF_COND
#define MMCSD_CMD_SEND_CSD              9U
#define MMCSD_CMD_SEND_CID              10U
#define MMCSD_CMD_STOP_TRANSMISSION     12U
#define MMCSD_CMD_SEND_STATUS           13U
#define MMCSD_CMD_SET_BLOCKLEN          16U
#define MMCSD_CMD_READ_SINGLE_BLOCK     17U
#define MMCSD_CMD_READ_MULTIPLE_BLOCK   18U
#define MMCSD_CMD_SET_BLOCK_COUNT       23U
#define MMCSD_CMD_WRITE_BLOCK           24U
#define MMCSD_CMD_WRITE_MULTIPLE_BLOCK  25U
#define MMCSD_CMD_ERASE_RW_BLK_START    32U
#define MMCSD_CMD_ERASE_RW_BLK_END      33U
#define MMCSD_CMD_ERASE                 38U
#define MMCSD_CMD_APP_OP_COND           41U
#define MMCSD_CMD_LOCK_UNLOCK           42U
#define MMCSD_CMD_APP_CMD               55U
#define MMCSD_CMD_READ_OCR              58U

#define MMCSD_CSD_MMC_CSD_STRUCTURE_SLICE       127U,126U
#define MMCSD_CSD_MMC_SPEC_VERS_SLICE           125U,122U
#define MMCSD_CSD_MMC_TAAC_SLICE                119U,112U
#define MMCSD_CSD_MMC_NSAC_SLICE                111U,104U
#define MMCSD_CSD_MMC_TRAN_SPEED_SLICE          103U,96U
#define MMCSD_CSD_MMC_CCC_SLICE                 95U,84U
#define MMCSD_CSD_MMC_READ_BL_LEN_SLICE         83U,80U
#define MMCSD_CSD_MMC_READ_BL_PARTIAL_SLICE     79U,79U
#define MMCSD_CSD_MMC_WRITE_BLK_MISALIGN_SLICE  78U,78U
#define MMCSD_CSD_MMC_READ_BLK_MISALIGN_SLICE   77U,77U
#define MMCSD_CSD_MMC_DSR_IMP_SLICE             76U,76U
#define MMCSD_CSD_MMC_C_SIZE_SLICE              73U,62U
#define MMCSD_CSD_MMC_VDD_R_CURR_MIN_SLICE      61U,59U
#define MMCSD_CSD_MMC_VDD_R_CURR_MAX_SLICE      58U,56U
#define MMCSD_CSD_MMC_VDD_W_CURR_MIN_SLICE      55U,53U
#define MMCSD_CSD_MMC_VDD_W_CURR_MAX_SLICE      52U,50U
#define MMCSD_CSD_MMC_C_SIZE_MULT_SLICE         49U,47U
#define MMCSD_CSD_MMC_ERASE_GRP_SIZE_SLICE      46U,42U
#define MMCSD_CSD_MMC_ERASE_GRP_MULT_SLICE      41U,37U
#define MMCSD_CSD_MMC_WP_GRP_SIZE_SLICE         36U,32U
#define MMCSD_CSD_MMC_WP_GRP_ENABLE_SLICE       31U,31U
#define MMCSD_CSD_MMC_DEFAULT_ECC_SLICE         30U,29U
#define MMCSD_CSD_MMC_R2W_FACTOR_SLICE          28U,26U
#define MMCSD_CSD_MMC_WRITE_BL_LEN_SLICE        25U,22U
#define MMCSD_CSD_MMC_WRITE_BL_PARTIAL_SLICE    21U,21U
#define MMCSD_CSD_MMC_CONTENT_PROT_APP_SLICE    16U,16U
#define MMCSD_CSD_MMC_FILE_FORMAT_GRP_SLICE     15U,15U
#define MMCSD_CSD_MMC_COPY_SLICE                14U,14U
#define MMCSD_CSD_MMC_PERM_WRITE_PROTECT_SLICE  13U,13U
#define MMCSD_CSD_MMC_TMP_WRITE_PROTECT_SLICE   12U,12U
#define MMCSD_CSD_MMC_FILE_FORMAT_SLICE         11U,10U
#define MMCSD_CSD_MMC_ECC_SLICE                 9U,8U
#define MMCSD_CSD_MMC_CRC_SLICE                 7U,1U

#define MMCSD_CSD_20_CRC_SLICE                  7U,1U
#define MMCSD_CSD_20_FILE_FORMAT_SLICE          11U,10U
#define MMCSD_CSD_20_TMP_WRITE_PROTECT_SLICE    12U,12U
#define MMCSD_CSD_20_PERM_WRITE_PROTECT_SLICE   13U,13U
#define MMCSD_CSD_20_COPY_SLICE                 14U,14U
#define MMCSD_CSD_20_FILE_FORMAT_GRP_SLICE      15U,15U
#define MMCSD_CSD_20_WRITE_BL_PARTIAL_SLICE     21U,21U
#define MMCSD_CSD_20_WRITE_BL_LEN_SLICE         25U,12U
#define MMCSD_CSD_20_R2W_FACTOR_SLICE           28U,26U
#define MMCSD_CSD_20_WP_GRP_ENABLE_SLICE        31U,31U
#define MMCSD_CSD_20_WP_GRP_SIZE_SLICE          38U,32U
#define MMCSD_CSD_20_ERASE_SECTOR_SIZE_SLICE    45U,39U
#define MMCSD_CSD_20_ERASE_BLK_EN_SLICE         46U,46U
#define MMCSD_CSD_20_C_SIZE_SLICE               69U,48U
#define MMCSD_CSD_20_DSR_IMP_SLICE              76U,76U
#define MMCSD_CSD_20_READ_BLK_MISALIGN_SLICE    77U,77U
#define MMCSD_CSD_20_WRITE_BLK_MISALIGN_SLICE   78U,78U
#define MMCSD_CSD_20_READ_BL_PARTIAL_SLICE      79U,79U
#define MMCSD_CSD_20_READ_BL_LEN_SLICE          83U,80U
#define MMCSD_CSD_20_CCC_SLICE                  95U,84U
#define MMCSD_CSD_20_TRANS_SPEED_SLICE          103U,96U
#define MMCSD_CSD_20_NSAC_SLICE                 111U,104U
#define MMCSD_CSD_20_TAAC_SLICE                 119U,112U
#define MMCSD_CSD_20_CSD_STRUCTURE_SLICE        127U,126U

#define MMCSD_CSD_10_CRC_SLICE                  MMCSD_CSD_20_CRC_SLICE
#define MMCSD_CSD_10_FILE_FORMAT_SLICE          MMCSD_CSD_20_FILE_FORMAT_SLICE
#define MMCSD_CSD_10_TMP_WRITE_PROTECT_SLICE    MMCSD_CSD_20_TMP_WRITE_PROTECT_SLICE
#define MMCSD_CSD_10_PERM_WRITE_PROTECT_SLICE   MMCSD_CSD_20_PERM_WRITE_PROTECT_SLICE
#define MMCSD_CSD_10_COPY_SLICE                 MMCSD_CSD_20_COPY_SLICE
#define MMCSD_CSD_10_FILE_FORMAT_GRP_SLICE      MMCSD_CSD_20_FILE_FORMAT_GRP_SLICE
#define MMCSD_CSD_10_WRITE_BL_PARTIAL_SLICE     MMCSD_CSD_20_WRITE_BL_PARTIAL_SLICE
#define MMCSD_CSD_10_WRITE_BL_LEN_SLICE         MMCSD_CSD_20_WRITE_BL_LEN_SLICE
#define MMCSD_CSD_10_R2W_FACTOR_SLICE           MMCSD_CSD_20_R2W_FACTOR_SLICE
#define MMCSD_CSD_10_WP_GRP_ENABLE_SLICE        MMCSD_CSD_20_WP_GRP_ENABLE_SLICE
#define MMCSD_CSD_10_WP_GRP_SIZE_SLICE          MMCSD_CSD_20_WP_GRP_SIZE_SLICE
#define MMCSD_CSD_10_ERASE_SECTOR_SIZE_SLICE    MMCSD_CSD_20_ERASE_SECTOR_SIZE_SLICE
#define MMCSD_CSD_10_ERASE_BLK_EN_SLICE         MMCSD_CSD_20_ERASE_BLK_EN_SLICE
#define MMCSD_CSD_10_C_SIZE_MULT_SLICE          49U,47U
#define MMCSD_CSD_10_VDD_W_CURR_MAX_SLICE       52U,50U
#define MMCSD_CSD_10_VDD_W_CURR_MIN_SLICE       55U,53U
#define MMCSD_CSD_10_VDD_R_CURR_MAX_SLICE       58U,56U
#define MMCSD_CSD_10_VDD_R_CURR_MIX_SLICE       61U,59U
#define MMCSD_CSD_10_C_SIZE_SLICE               73U,62U
#define MMCSD_CSD_10_DSR_IMP_SLICE              MMCSD_CSD_20_DSR_IMP_SLICE
#define MMCSD_CSD_10_READ_BLK_MISALIGN_SLICE    MMCSD_CSD_20_READ_BLK_MISALIGN_SLICE
#define MMCSD_CSD_10_WRITE_BLK_MISALIGN_SLICE   MMCSD_CSD_20_WRITE_BLK_MISALIGN_SLICE
#define MMCSD_CSD_10_READ_BL_PARTIAL_SLICE      MMCSD_CSD_20_READ_BL_PARTIAL_SLICE
#define MMCSD_CSD_10_READ_BL_LEN_SLICE          83U,80U
#define MMCSD_CSD_10_CCC_SLICE                  MMCSD_CSD_20_CCC_SLICE
#define MMCSD_CSD_10_TRANS_SPEED_SLICE          MMCSD_CSD_20_TRANS_SPEED_SLICE
#define MMCSD_CSD_10_NSAC_SLICE                 MMCSD_CSD_20_NSAC_SLICE
#define MMCSD_CSD_10_TAAC_SLICE                 MMCSD_CSD_20_TAAC_SLICE
#define MMCSD_CSD_10_CSD_STRUCTURE_SLICE        MMCSD_CSD_20_CSD_STRUCTURE_SLICE

#define MMCSD_CID_SDC_CRC_SLICE                 7U,1U
#define MMCSD_CID_SDC_MDT_M_SLICE               11U,8U
#define MMCSD_CID_SDC_MDT_Y_SLICE               19U,12U
#define MMCSD_CID_SDC_PSN_SLICE                 55U,24U
#define MMCSD_CID_SDC_PRV_M_SLICE               59U,56U
#define MMCSD_CID_SDC_PRV_N_SLICE               63U,60U
#define MMCSD_CID_SDC_PNM0_SLICE                71U,64U
#define MMCSD_CID_SDC_PNM1_SLICE                79U,72U
#define MMCSD_CID_SDC_PNM2_SLICE                87U,80U
#define MMCSD_CID_SDC_PNM3_SLICE                95U,88U
#define MMCSD_CID_SDC_PNM4_SLICE                103U,96U
#define MMCSD_CID_SDC_OID_SLICE                 119U,104U
#define MMCSD_CID_SDC_MID_SLICE                 127U,120U

#define MMCSD_CID_MMC_CRC_SLICE                 7U,1U
#define MMCSD_CID_MMC_MDT_Y_SLICE               11U,8U
#define MMCSD_CID_MMC_MDT_M_SLICE               15U,12U
#define MMCSD_CID_MMC_PSN_SLICE                 47U,16U
#define MMCSD_CID_MMC_PRV_M_SLICE               51U,48U
#define MMCSD_CID_MMC_PRV_N_SLICE               55U,52U
#define MMCSD_CID_MMC_PNM0_SLICE                63U,56U
#define MMCSD_CID_MMC_PNM1_SLICE                71U,64U
#define MMCSD_CID_MMC_PNM2_SLICE                79U,72U
#define MMCSD_CID_MMC_PNM3_SLICE                87U,80U
#define MMCSD_CID_MMC_PNM4_SLICE                95U,88U
#define MMCSD_CID_MMC_PNM5_SLICE                103U,96U
#define MMCSD_CID_MMC_OID_SLICE                 119U,104U
#define MMCSD_CID_MMC_MID_SLICE                 127U,120U

#endif /* __IOBLOCK_H__ */

/** @} */
