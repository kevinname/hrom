/*
    bootloader - Copyright (C) 2012~2014 HunterSun Technologies
                 pingping.wu@huntersun.com.cn
 */

/**
 * @file    comm/comm_protocol.h
 * @brief   The communication protocol between host and hs66xx.
 * @details 
 * 
 * @addtogroup  comm
 * @details 
 * @{
 */
#ifndef __COMM_PROTOCOL_H__
#define __COMM_PROTOCOL_H__

#include <stdint.h>

/*===========================================================================*/
/* macros default.                                                           */
/*===========================================================================*/
#define COMM_CMD_DATA_LEN           258
#define COMM_EVENT_DATA_LEN         258

#define COMM_HCI_OPCODE             0xfd60u

#define COMM_CMD_HEADER             1
#define COMM_EVENT_HEADER           4
#define COMM_EVENT_COMPLETE         0xe
#define COMM_EVENT_TOTALHEAD_LEN    9   //7
#define COMM_EVENT_LASTHEAD_LEN     6
/*===========================================================================*/
/* data structure and data type.                                             */
/*===========================================================================*/
typedef struct
{
  uint8_t *pu8CmdDataBuf;         /*!< command data, input paramter           */
  uint8_t   u8CmdDataLen;         /*!< command data length, input paramter    */
  uint8_t *pu8ResDataBuf;         /*!< response data, output paramter         */
  uint8_t   u8ResDataLen;         /*!< response data length, output paramter  */
}hs_comm_cmdpara_t;

/* command execute OK, return 0. return value is not 0, is false */
typedef int32_t (*hs_pCommCmd_t)(uint8_t *pu8CmdDataBuf, uint8_t u8CmdDataLen, uint8_t *pu8ResDataBuf, uint8_t u8ResDataLen);
typedef struct
{
  uint16_t        u16Cmd;
  hs_pCommCmd_t   pfnCmdPro;
}hs_comm_cmd_t;



/*===========================================================================*/
/* macros function default.                                                  */
/*===========================================================================*/


#ifdef __cplusplus
extern "C" {
#endif

int hs_comm_RxLoop(void);

#ifdef __cplusplus
}
#endif


#endif
 /** @} */
