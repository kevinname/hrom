#ifndef __UPGRADE_LED_H__
#define __UPGRADE_LED_H__

typedef enum
{
  CHIP_STATUS_IDLE            = 0,
  CHIP_STATUS_BUSY            ,
}hs_chipstatus_t;

typedef enum
{
  CHIP_RES_OK                 = 0,
  CHIP_RES_ERR                ,
}hs_chipres_t;


void hs_upgrade_ledSetPad(hs_packinfo_t *pstInfo);
void hs_upgrade_ledSetStatus(hs_packinfo_t *pstInfo, hs_chipstatus_t eStatus);
void hs_upgrade_ledSetResult(hs_packinfo_t *pstInfo, hs_chipres_t eRes);

#endif
