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

#include "platform.h"
#include "comm_hal.h"
#include "comm_protocol.h"
#include "comm_cmd.c"

static uint16_t _comm_packetResponse(hs_comm_res_t enRes, uint16_t u16OpCode, uint16_t u16Cmd, uint8_t u8TxLen, uint8_t *pu8ResponsePtr)
{
  uint16_t u16Offset = 0;

  if(pu8ResponsePtr == NULL)
  {
    return u16Offset;
  }

  pu8ResponsePtr[u16Offset++] = COMM_EVENT_HEADER;
  pu8ResponsePtr[u16Offset++] = COMM_EVENT_COMPLETE;
  pu8ResponsePtr[u16Offset++] = (enRes == HS_COMM_OK) ? 
                                (u8TxLen + COMM_EVENT_LASTHEAD_LEN) : COMM_EVENT_LASTHEAD_LEN;
  pu8ResponsePtr[u16Offset++] = 1;

  pu8ResponsePtr[u16Offset++] = u16OpCode;
  pu8ResponsePtr[u16Offset++] = u16OpCode >> 8;

  pu8ResponsePtr[u16Offset++] = enRes;

  pu8ResponsePtr[u16Offset++] = u16Cmd;
  pu8ResponsePtr[u16Offset++] = u16Cmd >> 8;

  if(enRes == HS_COMM_OK)
  {
    u16Offset += u8TxLen;
  }

  return u16Offset;
}

static hs_comm_res_t _comm_dispatch(uint16_t u16Cmd, hs_comm_cmdpara_t *pstPara)
{
  uint16_t i, u16CmdCnt;
  hs_comm_res_t enRes = HS_COMM_OK;

  if(u16Cmd >= COMM_CMD_MAXID)
  {
    return HS_COMM_CMD_ERROR_ID;
  }
  
  u16CmdCnt = sizeof(g_stCommCmd) / sizeof(hs_comm_cmd_t);
  for(i=0; i<u16CmdCnt; i++)
  {
    if((g_stCommCmd[i].u16Cmd == u16Cmd) && (g_stCommCmd[i].pfnCmdPro != NULL))
    {
      enRes = (hs_comm_res_t)g_stCommCmd[i].pfnCmdPro(pstPara->pu8CmdDataBuf, pstPara->u8CmdDataLen, 
                                                      pstPara->pu8ResDataBuf, pstPara->u8ResDataLen);
      break;
    }
  }

  if(i >= u16CmdCnt)
  {
    enRes = HS_COMM_CMD_ERROR_NOTFINDCMD;
  }

  return enRes;
}

static uint8_t g_u8Cmd[COMM_CMD_DATA_LEN], g_u8Res[COMM_CMD_DATA_LEN];

int hs_comm_RxLoop(void) 
{
  uint8_t *pu8CmdPtr, *pu8CmdBuf, *pu8EventBuf;
  uint8_t u8PLen;
  uint16_t u16OpCode, u16Cmd, u16TxLen;
  hs_comm_cmdpara_t stPara;
  hs_comm_res_t enRes;

  pu8CmdBuf = g_u8Cmd;
  pu8EventBuf = g_u8Res;
  
  while(1)
  {
    pu8CmdPtr = pu8CmdBuf;

    /* rx command header */
    enRes = hs_comm_halRx(pu8CmdPtr, 4);
    if( (enRes != HS_COMM_OK) || (pu8CmdPtr[0] != COMM_CMD_HEADER))
    {
      continue;
    }

    __byte2word(pu8CmdPtr[1], pu8CmdPtr[2], u16OpCode);
    u8PLen = pu8CmdPtr[3];
    pu8CmdPtr += 4;

    /* rx cmd or payload of HCI/TCI command */
    if(u8PLen > 0)
    {
      enRes = hs_comm_halRx(pu8CmdPtr, u8PLen);
      if(enRes != HS_COMM_OK)
      {
        continue;
      }
    }

    if(u16OpCode == COMM_HCI_OPCODE)
    {
      __byte2word(pu8CmdPtr[0], pu8CmdPtr[1], u16Cmd);
      stPara.pu8CmdDataBuf = pu8CmdPtr + 3;
      stPara.u8CmdDataLen = u8PLen - 3;
      stPara.pu8ResDataBuf = pu8EventBuf + COMM_EVENT_TOTALHEAD_LEN;
      stPara.u8ResDataLen = pu8CmdPtr[2];

      enRes = _comm_dispatch(u16Cmd, &stPara);
      u16TxLen = _comm_packetResponse(enRes, u16OpCode, u16Cmd, stPara.u8ResDataLen, pu8EventBuf);

      /* send response */
      if((pu8EventBuf) && (u16TxLen > 0))
      {
        hs_comm_halTx(pu8EventBuf, u16TxLen);
      }
    }
  }

  return 0;
}


/** @} */
