#include "lib.h"


void hs_upgrade_ledSetPad(hs_packinfo_t *pstInfo)
{
  GPIO_Config io_cfg = {GPIO_DIR_OUTPUT, GPIO_PULL_NO, GPIO_DRV_3, GPIO_MODE_GPIO};

  if(pstInfo->u32StatusIO > 15)
    GPIO_PinConfigure(GPIO1, (pstInfo->u32StatusIO - 16), &io_cfg);
  else
    GPIO_PinConfigure(GPIO0, pstInfo->u32StatusIO, &io_cfg);

  if(pstInfo->u32ResultIO > 15)
    GPIO_PinConfigure(GPIO1, (pstInfo->u32ResultIO - 16), &io_cfg);
  else
    GPIO_PinConfigure(GPIO0, pstInfo->u32ResultIO, &io_cfg);
}

void hs_upgrade_ledSetStatus(hs_packinfo_t *pstInfo, hs_chipstatus_t eStatus)
{
  GPIO_Type *pstGpio = pstInfo->u32StatusIO > 15 ? GPIO1 : GPIO0;
  uint32_t u32Pin = pstInfo->u32StatusIO > 15 ? (pstInfo->u32StatusIO - 16) 
                                                : pstInfo->u32StatusIO;

  
  if(eStatus == CHIP_STATUS_BUSY)
    GPIO_PinWrite(pstGpio, u32Pin, pstInfo->u32StatusIOLvl);
  else
    GPIO_PinWrite(pstGpio, u32Pin, (~pstInfo->u32StatusIOLvl) & 1);
}

void hs_upgrade_ledSetResult(hs_packinfo_t *pstInfo, hs_chipres_t eRes)
{
  GPIO_Type *pstGpio = pstInfo->u32ResultIO > 15 ? GPIO1 : GPIO0;
  uint32_t u32Pin = pstInfo->u32ResultIO > 15 ? (pstInfo->u32ResultIO - 16) 
                                                : pstInfo->u32ResultIO;

  
  if(eRes == CHIP_RES_OK)
    GPIO_PinWrite(pstGpio, u32Pin, pstInfo->u32ResultIOLvl);
  else
    GPIO_PinWrite(pstGpio, u32Pin, (~pstInfo->u32ResultIOLvl) & 1);
}

