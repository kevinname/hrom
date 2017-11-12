/*
    bootloader - Copyright (C) 2012~2014 HunterSun Technologies
                 pingping.wu@huntersun.com.cn
 */

/**
 * @file    comm/comm_hal.h
 * @brief   The communication channel.
 * @details 
 * 
 * @addtogroup  comm
 * @details 
 * @{
 */
#ifndef __COMM_HAL_H__
#define __COMM_HAL_H__

#include "comm_cmd.h"

/*===========================================================================*/
/* macros default.                                                           */
/*===========================================================================*/

#define COMM_TIME_UNIT_S              1000
#define COMM_TIME_UNIT_M              (1000u * 60)
#define COMM_CHNSCAN_INTERAL_TIME     (COMM_TIME_UNIT_S * 1)

#define BOOT_DEVICE_UART       (&SD1)
#define BOOT_DEVICE_USB        (&SDU1) 

/*===========================================================================*/
/* data structure and data type.                                             */
/*===========================================================================*/

typedef enum
{
  COMM_HALSCAN_DISABLE        = 0,
  COMM_HALSCAN_ENABLE         ,
} hs_comm_halScanEn_t;

typedef int32_t (*hs_pCommRxTx_t)(uint8_t *pu8Buf, uint32_t u32Len, uint16_t u16Timeout);

typedef struct
{
  hs_pCommRxTx_t        pfnCommTx;
  hs_pCommRxTx_t        pfnCommRx;
}hs_comm_hal_t;

/*===========================================================================*/
/* macros function default.                                                  */
/*===========================================================================*/


#ifdef __cplusplus
extern "C" {
#endif

void printString(char *str);

int32_t hs_comm_halRx(uint8_t *pu8Buf, uint32_t u32Len);
int32_t hs_comm_halTx(uint8_t *pu8Buf, uint32_t u32Len);
void hs_comm_halClrRxBuf(void);

#ifdef __cplusplus
}
#endif


#endif
 /** @} */
