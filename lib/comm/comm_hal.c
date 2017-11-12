/*
    bootloader - Copyright (C) 2012~2014 HunterSun Technologies
                 pingping.wu@huntersun.com.cn
 */

/**
 * @file    comm/comm_hal.c
 * @brief   The communication channel.
 * @details 
 * 
 * @addtogroup  comm
 * @details 
 * @{
 */
#include "lib.h"
#include "comm_hal.h"
#include "string.h"

#if UART_DEBUG
//static void _comm_uartRx(uint8_t *pu8Buf, uint32_t u32Len)
//{
//  uint32_t i;
//
//  for(i=0; i<u32Len; i++)
//    pu8Buf[i] = uartGetByte();
//}

static void _comm_uartTx(uint8_t *pu8Buf, uint32_t u32Len)
{
  uint32_t i;

  for(i=0; i<u32Len; i++)
    uartSendByte(pu8Buf[i]);
}
#endif

void printString(char *str)
{
  #if UART_DEBUG
  _comm_uartTx((uint8_t *)str, strlen(str));
  #endif
}

int32_t hs_comm_halRx(uint8_t *pu8Buf, uint32_t u32Len)
{
  if(u32Len == usbRxData(pu8Buf, u32Len))
    return HS_COMM_OK;
  
  return HS_COMM_ERROR;
}

int32_t hs_comm_halTx(uint8_t *pu8Buf, uint32_t u32Len)
{
  if(u32Len == usbTxData(pu8Buf, u32Len))
    return HS_COMM_OK;
  
  return HS_COMM_ERROR;
}

void hs_comm_halClrRxBuf(void)
{
  usbClrFifo();
}

/** @} */
