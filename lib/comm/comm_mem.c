/*
    bootloader - Copyright (C) 2012~2014 HunterSun Technologies
                 pingping.wu@huntersun.com.cn
 */

/**
 * @file    comm/comm_cmd.c
 * @brief   command file.
 * @details 
 *
 * @addtogroup  comm
 * @details 
 * @{
 */
#include "comm_cmd.h"
#include "comm_protocol.h"
#include "comm_hal.h"
#include "platform.h"

static uint8_t g_u8TmpBuf[8] __attribute__((aligned(8)));

int32_t hs_comm_readmem(uint8_t *pu8CmdDataBuf, uint8_t u8CmdDataLen, 
                        uint8_t *pu8ResDataBuf, uint8_t u8ResDataLen)
{
  uint8_t *pu8Ptr;
  uint32_t address;

  if ((u8CmdDataLen != 4) || sfIsLock())
    return HS_COMM_ERROR;
  
  __byte2dword(pu8CmdDataBuf, address);
  pu8Ptr = (uint8_t *)address;
  memcpy(pu8ResDataBuf, pu8Ptr, u8ResDataLen);  

  return HS_COMM_OK;
}

int32_t hs_comm_writemem(uint8_t *pu8CmdDataBuf, uint8_t u8CmdDataLen, 
                         uint8_t *pu8ResDataBuf, uint8_t u8ResDataLen)
{
  uint8_t  *pu8Ptr;
  uint16_t *pu16Ptr, u16Val;
  uint32_t *pu32Ptr, u32Val;
  uint32_t address, len;
  
  __byte2dword(pu8CmdDataBuf, address);  

  len = u8CmdDataLen - 4;
  pu8CmdDataBuf += 4;

  if((address & 0xf0000000) == 0x80000000)
  {
    address &= 0xfffffff;
    memcpy(g_u8TmpBuf, pu8CmdDataBuf, len);
    sfWrite(address, g_u8TmpBuf, len);

    return HS_COMM_OK;
  }
  
  if(len == 2)
  {
    __byte2word(pu8CmdDataBuf[0], pu8CmdDataBuf[1], u16Val);

    pu16Ptr = (uint16_t *)address;
    *pu16Ptr = u16Val;
  }
  else if(len == 4)
  {
    __byte2dword(pu8CmdDataBuf, u32Val);

    pu32Ptr = (uint32_t *)address;
    *pu32Ptr = u32Val;
  }
  else
  {
    pu8Ptr = (uint8_t *)address;
    memcpy(pu8Ptr, pu8CmdDataBuf, len);  
  }

  return HS_COMM_OK;
}

int32_t hs_comm_erasemem(uint8_t *pu8CmdDataBuf, uint8_t u8CmdDataLen, 
                         uint8_t *pu8ResDataBuf, uint8_t u8ResDataLen)
{
  uint32_t offset, len;

  if(u8CmdDataLen != 8)
    return HS_COMM_ERROR;
  
  __byte2dword(pu8CmdDataBuf, offset);
  __byte2dword((pu8CmdDataBuf + 4), len);

  offset &= 0xfff000;
  sfErase(offset, len);  

  return HS_COMM_OK;
}


/** @} */
