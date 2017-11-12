#ifndef __DRV_UART_H__
#define __DRV_UART_H__

#ifndef UART_DEBUG
#define UART_DEBUG    0
#endif

#if UART_DEBUG
int uartGetByte(void);
void uartSendByte(uint8_t ch);
int uartinit(void);
#endif

#endif /* __DRV_UART_H__ */
