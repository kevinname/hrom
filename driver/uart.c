#include <nds32_intrinsic.h>
#include <platform.h>

#if UART_DEBUG

static UART_Type *u = UART1;

int uartGetByte(void)
{
	while((u->LSR & 0x1) == 0)
    ;

	return u->RBR;;
}

void uartSendByte(uint8_t ch)
{
  while((u->LSR & 0x20) == 0)
    ;

  u->THR = ch;
}

void uartSetPad(void)
{
  GPIO_Config io_cfg1 = {GPIO_DIR_OUTPUT, GPIO_PULL_NO, GPIO_DRV_3, GPIO_MODE_FUN23};
  GPIO_Config io_cfg2 = {GPIO_DIR_INPUT, GPIO_PULL_NO, GPIO_DRV_3, GPIO_MODE_FUN22};

  GPIO_PinConfigure(GPIO0, 3, &io_cfg1);
  GPIO_PinConfigure(GPIO0, 4, &io_cfg2);
}

int uartinit(void)
{
  CPM_CfgModuleClk(CPM_MODULE_UART1, 16*8*115200);
  uartSetPad();

  u->IER = 0;
  u->LCR = 0x80;
  u->DLH = 0;
  u->DLL = 0;
  u->LCR = 0x00;

  u->MCR = 0x00;
  u->FCR = 0x06;

  u->LCR = 0x80;
  u->DLH = 0x00;
  u->DLL = 0x08;
  u->LCR = 3;

  u->IER = 0; //0x05;

  return 0;
}

#endif

