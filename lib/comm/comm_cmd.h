/*
    bootloader - Copyright (C) 2012~2014 HunterSun Technologies
                 pingping.wu@huntersun.com.cn
 */

/**
 * @file    comm/comm_cmd.h
 * @brief   The communication command.
 * @details 
 * 
 * @addtogroup  comm
 * @details 
 * @{
 */
#ifndef __COMM_CMD_H__
#define __COMM_CMD_H__

enum
{
    COMM_CMD_ENTER_DOWNLOAD           = 0,
    COMM_CMD_ERASE_ALLCONFIGDATA      ,
    
    COMM_CMD_MEMORY_READ              = 0x40,
    COMM_CMD_MEMORY_WRITE             ,
    COMM_CMD_MEMORY_ERASE             ,


    COMM_CMD_MAXID               
};

typedef enum 
{
  HS_COMM_OK                        = 0,                  /*!< result ok                          */
    
  HS_COMM_ERROR_RX                  ,                     /*!< receive error                      */
  HS_COMM_ERROR_TX                  ,                     /*!< transmit error                     */

  HS_COMM_CMD_ERROR_ID              = 0x40,               /*!< COMMAND ID ERROR                   */
  HS_COMM_CMD_ERROR_NOTFINDCMD      ,                     /*!< can not find command               */

  HS_COMM_ERROR                     = 0xFF,               /*!< some error have happened           */
} hs_comm_res_t;


#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#endif
 /** @} */
