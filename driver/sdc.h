#ifndef __SDC_H__
#define __SDC_H__

#define SDCD_ERROR_NULLPTR          -10
#define SDCD_ERROR_STATE            -11

#define SDC_MODE_CARDTYPE_MASK              0xFU
#define SDC_MODE_CARDTYPE_SDV11             0U
#define SDC_MODE_CARDTYPE_SDV20             1U
#define SDC_MODE_CARDTYPE_MMC               2U
#define SDC_MODE_HIGH_CAPACITY              0x10U

#define SDC_NO_ERROR                        0U
#define SDC_CMD_CRC_ERROR                   1U
#define SDC_DATA_CRC_ERROR                  2U
#define SDC_DATA_TIMEOUT                    4U
#define SDC_COMMAND_TIMEOUT                 8U
#define SDC_TX_UNDERRUN                     16U
#define SDC_RX_OVERRUN                      32U
#define SDC_STARTBIT_ERROR                  64U
#define SDC_OVERFLOW_ERROR                  128U
#define SDC_UNHANDLED_ERROR                 0xFFFFFFFFU

#define SDC_INIT_RETRY                      100

#define SDC_NICE_WAITING                    TRUE

typedef enum {
  SDC_MODE_1BIT = 0,
  SDC_MODE_4BIT,
  SDC_MODE_8BIT
} sdcbusmode_t;

typedef enum {
  SDC_CLK_25MHz = 0,
  SDC_CLK_50MHz
} sdcbusclk_t;

typedef uint32_t sdcmode_t;

/**
 * @brief   SDC Driver condition flags type.
 */
typedef uint32_t sdcflags_t;

/**
 * @brief   Type of a structure representing an SDC driver.
 */
typedef struct SDCDriver SDCDriver;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  uint32_t                  dummy;
} SDCConfig;

#include "ioblock.h"

#define _mmcsd_block_device_methods                                         \
  _base_block_device_methods

/**
 * @brief   @p MMCSDBlockDevice specific data.
 * @note    It is empty because @p MMCSDBlockDevice is only an interface
 *          without implementation.
 */
#define _mmcsd_block_device_data                                            \
  _base_block_device_data                                                   \
  /* Card CID.*/                                                            \
  uint32_t              cid[4];                                             \
  /* Card CSD.*/                                                            \
  uint32_t              csd[4];                                             \
  /* Total number of blocks in card.*/                                      \
  uint32_t              capacity;

/**
 * @extends BaseBlockDeviceVMT
 *
 * @brief   @p MMCSDBlockDevice virtual methods table.
 */
struct MMCSDBlockDeviceVMT {
  _base_block_device_methods
};

/**
 * @extends BaseBlockDevice
 *
 * @brief   MCC/SD block device class.
 * @details This class represents a, block-accessible, MMC/SD device.
 */
typedef struct {
  /** @brief Virtual Methods Table.*/
  const struct MMCSDBlockDeviceVMT *vmt;
  _mmcsd_block_device_data
} MMCSDBlockDevice;

/**
 * @brief   Unpacked CID register from SDC.
 */
typedef struct {
  uint8_t   mid;
  uint16_t  oid;
  char      pnm[5];
  uint8_t   prv_n;
  uint8_t   prv_m;
  uint32_t  psn;
  uint8_t   mdt_m;
  uint16_t  mdt_y;
  uint8_t   crc;
} unpacked_sdc_cid_t;

/**
 * @brief   Unpacked CID register from MMC.
 */
typedef struct {
  uint8_t   mid;
  uint16_t  oid;
  char      pnm[6];
  uint8_t   prv_n;
  uint8_t   prv_m;
  uint32_t  psn;
  uint8_t   mdt_m;
  uint16_t  mdt_y;
  uint8_t   crc;
} unpacked_mmc_cid_t;

/**
 * @brief   Unpacked CSD v1.0 register from SDC.
 */
typedef struct {
  uint8_t   csd_structure;
  uint8_t   taac;
  uint8_t   nsac;
  uint8_t   tran_speed;
  uint16_t  ccc;
  uint8_t   read_bl_len;
  uint8_t   read_bl_partial;
  uint8_t   write_blk_misalign;
  uint8_t   read_blk_misalign;
  uint8_t   dsr_imp;
  uint16_t  c_size;
  uint8_t   vdd_r_curr_min;
  uint8_t   vdd_r_curr_max;
  uint8_t   vdd_w_curr_min;
  uint8_t   vdd_w_curr_max;
  uint8_t   c_size_mult;
  uint8_t   erase_blk_en;
  uint8_t   erase_sector_size;
  uint8_t   wp_grp_size;
  uint8_t   wp_grp_enable;
  uint8_t   r2w_factor;
  uint8_t   write_bl_len;
  uint8_t   write_bl_partial;
  uint8_t   file_format_grp;
  uint8_t   copy;
  uint8_t   perm_write_protect;
  uint8_t   tmp_write_protect;
  uint8_t   file_format;
  uint8_t   crc;
} unpacked_sdc_csd_10_t;

/**
 * @brief   Unpacked CSD v2.0 register from SDC.
 */
typedef struct {
  uint8_t   csd_structure;
  uint8_t   taac;
  uint8_t   nsac;
  uint8_t   tran_speed;
  uint16_t  ccc;
  uint8_t   read_bl_len;
  uint8_t   read_bl_partial;
  uint8_t   write_blk_misalign;
  uint8_t   read_blk_misalign;
  uint8_t   dsr_imp;
  uint32_t  c_size;
  uint8_t   erase_blk_en;
  uint8_t   erase_sector_size;
  uint8_t   wp_grp_size;
  uint8_t   wp_grp_enable;
  uint8_t   r2w_factor;
  uint8_t   write_bl_len;
  uint8_t   write_bl_partial;
  uint8_t   file_format_grp;
  uint8_t   copy;
  uint8_t   perm_write_protect;
  uint8_t   tmp_write_protect;
  uint8_t   file_format;
  uint8_t   crc;
} unpacked_sdc_csd_20_t;

/**
 * @brief   Unpacked CSD register from MMC.
 */
typedef struct {
  uint8_t   csd_structure;
  uint8_t   spec_vers;
  uint8_t   taac;
  uint8_t   nsac;
  uint8_t   tran_speed;
  uint16_t  ccc;
  uint8_t   read_bl_len;
  uint8_t   read_bl_partial;
  uint8_t   write_blk_misalign;
  uint8_t   read_blk_misalign;
  uint8_t   dsr_imp;
  uint16_t  c_size;
  uint8_t   vdd_r_curr_min;
  uint8_t   vdd_r_curr_max;
  uint8_t   vdd_w_curr_min;
  uint8_t   vdd_w_curr_max;
  uint8_t   c_size_mult;
  uint8_t   erase_grp_size;
  uint8_t   erase_grp_mult;
  uint8_t   wp_grp_size;
  uint8_t   wp_grp_enable;
  uint8_t   default_ecc;
  uint8_t   r2w_factor;
  uint8_t   write_bl_len;
  uint8_t   write_bl_partial;
  uint8_t   content_prot_app;
  uint8_t   file_format_grp;
  uint8_t   copy;
  uint8_t   perm_write_protect;
  uint8_t   tmp_write_protect;
  uint8_t   file_format;
  uint8_t   ecc;
  uint8_t   crc;
} unpacked_mmc_csd_t;

/**
 * @brief   @p SDCDriver specific methods.
 */
#define _sdc_driver_methods                                                 \
  _mmcsd_block_device_methods

/**
 * @extends MMCSDBlockDeviceVMT
 *
 * @brief   @p SDCDriver virtual methods table.
 */
struct SDCDriverVMT {
  _sdc_driver_methods
};


#define IDMAC_DES0_DIC	(1UL << 1)
#define IDMAC_DES0_LD	(1UL << 2)
#define IDMAC_DES0_FD	(1UL << 3)
#define IDMAC_DES0_CH	(1UL << 4)
#define IDMAC_DES0_ER	(1UL << 5)
#define IDMAC_DES0_CES	(1UL << 30)
#define IDMAC_DES0_OWN	(1UL << 31)
#define IDMAC_SET_BUFFER1_SIZE(d, s) \
  ((d)->des1 = ((d)->des1 & 0x03ffe000) | ((s) & 0x1fff))


struct idmac_desc {
  uint32_t  des0;	/* Control Descriptor */
  uint32_t  des1;	/* Buffer sizes */
  uint32_t  des2;	/* buffer 1 physical address */
  uint32_t  des3;	/* buffer 2 physical address */
};

/**
 * @brief   Structure representing an SDC driver.
 */
struct SDCDriver {
  const struct SDCDriverVMT *vmt;
  _mmcsd_block_device_data
  const SDCConfig           *config;
  sdcmode_t                 cardmode;
  sdcflags_t                errors;
  uint32_t                  rca;
  HS_SDHC_Type              *sdhc;
  uint16_t                   id;
  
  uint16_t                   sg_length;
  struct idmac_desc          *sg;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/
#define sdcIsCardInserted(sdcp, pos)    (sdc_lld_is_card_inserted(sdcp, pos))
#define sdcIsWriteProtected(sdcp)       (sdc_lld_is_write_protected(sdcp))

#define MMCSD_R1_ERROR(r1)              (((r1) & MMCSD_R1_ERROR_MASK) != 0U)
#define MMCSD_R1_STS(r1)                (((r1) >> 9U) & 15U)
#define MMCSD_R1_IS_CARD_LOCKED(r1)     ((((r1) >> 21U) & 1U) != 0U)
#define mmcsdGetCardCapacity(ip)        ((ip)->capacity)

/**
 * @name    R1 response utilities
 * @{
 */
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(__DOXYGEN__)
extern SDCDriver SDCD0;
#endif

#ifdef __cplusplus
extern "C" {
#endif

void sdc_lld_send_cmd_none(SDCDriver *sdcp, uint32_t cmd, uint32_t arg);
bool sdc_lld_send_cmd_short_crc(SDCDriver *sdcp, uint32_t cmd, 
                                uint32_t arg, uint32_t *resp);
bool_t sdc_lld_is_card_inserted(SDCDriver *sdcp, int pos);
bool_t sdc_lld_is_write_protected(SDCDriver *sdcp);
bool _sdc_wait_for_transfer_state(SDCDriver *sdcp);


bool sdcConnect(SDCDriver *sdcp);
bool sdcDisconnect(SDCDriver *sdcp);
bool sdcRead(SDCDriver *sdcp, uint32_t startblk, uint8_t *buf, uint32_t n);
bool sdcWrite(SDCDriver *sdcp, uint32_t startblk, const uint8_t *buf, uint32_t n);
bool sdcSync(SDCDriver *sdcp);
bool sdcGetInfo(SDCDriver *sdcp, BlockDeviceInfo *bdip);
int  sdcStart(SDCDriver *sdcp, const SDCConfig *config);

int  sdInit(void);


#ifdef __cplusplus
}
#endif

#endif /* _SDC_LLD_H_ */

/** @} */
