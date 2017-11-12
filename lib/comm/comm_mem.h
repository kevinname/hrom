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
#ifndef __COMM_MEM_H__
#define __COMM_MEM_H__



#ifdef __cplusplus
extern "C" {
#endif

int32_t hs_comm_readmem(uint8_t *pu8CmdDataBuf, uint8_t u8CmdDataLen, 
                        uint8_t *pu8ResDataBuf, uint8_t u8ResDataLen);

int32_t hs_comm_writemem(uint8_t *pu8CmdDataBuf, uint8_t u8CmdDataLen, 
                         uint8_t *pu8ResDataBuf, uint8_t u8ResDataLen);

int32_t hs_comm_erasemem(uint8_t *pu8CmdDataBuf, uint8_t u8CmdDataLen, 
                         uint8_t *pu8ResDataBuf, uint8_t u8ResDataLen);

#ifdef __cplusplus
}
#endif


#endif
 /** @} */
