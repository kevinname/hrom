#include "lib.h"
#include "string.h"
#include "platform.h"

void _mem_init(void)
{
  extern char __rw_lma_start[];
  extern char __rw_lma_end[];
  extern char __rw_vma_start[];

  unsigned int size = __rw_lma_end - __rw_lma_start;
  memcpy(__rw_vma_start, __rw_lma_start, size);
}

void _disable_jtag(void)
{
  GPIO_Config io_cfg1 = {GPIO_DIR_INPUT, GPIO_PULL_NO, GPIO_DRV_3, GPIO_MODE_GPIO};

  GPIO_PinConfigure(GPIO0, 2, &io_cfg1);
  GPIO_PinConfigure(GPIO1, 7, &io_cfg1);
}

void _platform_Init(void) 
{
  uint32_t xclk;
  hs_xtalsel_t xtalSel;

  xtalSel = (hs_xtalsel_t)CPM_GetXtalSel();
  xclk = xtalSel == XTAL_SEL_16M ? XTAL_CLOCK_16M : XTAL_CLOCK_24M;
  CPM_SetXclk(xclk);

  if(1 == CPM_GetVersion())
    CPM_StartPll(CPM_PLLCLK_XCLK);
  else
    CPM_StartPll(CPM_PLLCLK_192M);

  sfInit();

  if(sfIsLock())
    _disable_jtag();
  
  #if UART_DEBUG
  uartinit();
  #endif  
}

int _sd_fs_init(void)
{  
  return sdInit();
}

void main_loop(void)
{
  if(0 == CPM_GetVersion())
  {
    usbSerialOpen();
    hs_comm_RxLoop();
  }

  while(1);
}

int main(void) 
{
  uint8_t *pu8FlhPtr = (uint8_t *)FLASH_ADDR;
  hs_bootsel_t bootSel;
  
  _mem_init();
  _platform_Init();

  #if UART_DEBUG
  printString("bootrom start!\r\n");
  #endif

  if(HS_OK == _sd_fs_init())
  {
    if(HS_OK == hs_upgrade_sdProc())
    	main_loop();
  }

  bootSel = (hs_bootsel_t)CPM_GetBootSel();
  if(BOOT_SEL_FLASH == bootSel)
  {
    if(HS_OK != hs_upgrade_chkImg(pu8FlhPtr, 1))
      main_loop();

    hs_imginfo_t *pstImgInfo;

    pstImgInfo = hs_upgrade_getImgInfo(pu8FlhPtr);
    if(pstImgInfo->u32ClkUsed == 1)
    {
      CPM_SetSfClk(pstImgInfo->u32CpmRegSf);
      sfSetClkCfg(pstImgInfo->u32SFRegCfg);
    }
    
    ((void (*)(void))(pu8FlhPtr))();
  }

  main_loop();
  return 0;
}
