#include "lib.h"


#if defined(__GNUC__)
static uint8_t g_u8PackBuf[PROTOCOL_PACKAGE_LEN+8] __attribute__((aligned(8)));
#endif
static uint8_t g_u8PackCnt;


static int _upgrade_usbSendNAK(void)
{
  uint8_t u8char = PROTOCOL_NAK;

  hs_comm_halClrRxBuf();
  return hs_comm_halTx(&u8char, 1);
}

static int _upgrade_usbSendACK(void)
{
  uint8_t u8char = PROTOCOL_ACK;

  return hs_comm_halTx(&u8char, 1);
}

static int _upgrade_usbSendCAN(void)
{
  uint8_t u8char = PROTOCOL_CAN;

  hs_comm_halTx(&u8char, 1);
  return hs_comm_halTx(&u8char, 1);
}

static hs_protocolres_t _upgrade_usbRxPackage(uint8_t **ppu8Buf)
{
  uint8_t u8Chksum;
  int ret = HS_ERR;
  uint8_t *pu8Buf = g_u8PackBuf + 1;

  while(HS_OK != hs_comm_halRx(pu8Buf, 1));

  if(pu8Buf[0] == PROTOCOL_EOT)
  {
    return PROTOCOL_RES_END;
  }

  ret = hs_comm_halRx(pu8Buf+1, PROTOCOL_PACKAGE_LEN-1);
  if(ret != HS_OK)
  {
    return PROTOCOL_RES_REPEAT;
  }

  u8Chksum = (uint8_t)hs_upgrade_calSum(&pu8Buf[3], PROTOCOL_PACKDATA_LEN);
  if ((u8Chksum != pu8Buf[PROTOCOL_PACKAGE_LEN-1])
        || (pu8Buf[1] != (~pu8Buf[2] & 0xff))
        || (pu8Buf[1] != (uint8_t)(g_u8PackCnt + 1)))
  {
    return PROTOCOL_RES_REPEAT;
  }

  g_u8PackCnt++;
  *ppu8Buf = g_u8PackBuf + 4;
  
  return PROTOCOL_RES_NEXT;  
}

static int _upgrade_usbSendResponse(hs_protocolres_t enRes)
{
  int enOperRes = HS_ERR;
  uint8_t u8ReSendCnt = PROTOCOL_RESEND_CNT;

  do
  {
    switch(enRes)
    {
      case PROTOCOL_RES_START:
        enOperRes = _upgrade_usbSendNAK();
        g_u8PackCnt = 0;
        break;
        
      case PROTOCOL_RES_CANCEL:
        enOperRes = _upgrade_usbSendCAN();
        break;

      case PROTOCOL_RES_NEXT:
        enOperRes = _upgrade_usbSendACK();
        break;

      case PROTOCOL_RES_REPEAT:
        enOperRes = _upgrade_usbSendNAK();
        break;

      default:
        enOperRes = HS_ERR;
    }

    if(enOperRes != HS_OK)
    {
      u8ReSendCnt -- ;
      if(u8ReSendCnt == 0)
      {
        break;
      }
    }    
  }while(enOperRes != HS_OK);

  return enOperRes;
}

static int _upgrade_usbGetInfo(hs_packinfo_t *pstPackInfo)
{
  uint8_t *pu8Ptr;
  uint32_t i, u32PackNum;
  hs_protocolres_t enResponse;  
  uint8_t u8RxErrCnt = PROTOCOL_RX_EER_CNT;
  int ret;

  u32PackNum = (INFO_SIZE + PROTOCOL_PACKDATA_LEN - 1) / PROTOCOL_PACKDATA_LEN;  
  enResponse = PROTOCOL_RES_START;
  
  for(i = 0; i < u32PackNum; )
  {
    ret = _upgrade_usbSendResponse(enResponse);
    if(ret != HS_OK)
    {
      return HS_ERR;
    } 
    
    enResponse = _upgrade_usbRxPackage(&pu8Ptr);
    if(enResponse == PROTOCOL_RES_END)
    {
      return HS_ERR;
    } 

    if(enResponse == PROTOCOL_RES_NEXT)
    {
      i++;
      u8RxErrCnt = PROTOCOL_RX_EER_CNT;
    }

    if(enResponse == PROTOCOL_RES_REPEAT)
    {      
      u8RxErrCnt --;
      if(u8RxErrCnt == 0)
      {
        return HS_ERR;
      }
      enResponse = PROTOCOL_RES_START;
    }
  }

  memcpy(pstPackInfo, pu8Ptr, INFO_SIZE);

  if(pstPackInfo->u32CipherTxtFlg == IMG_CIPHER)
    return HS_ERR;
  
  return hs_upgrade_chkInfo(pstPackInfo);
}

static int _upgrade_usbLoadBin(hs_packinfo_t *pstPackInfo)
{
  uint8_t *pu8Ptr, *pu8LoadPtr;
  uint32_t u32PackNum = 0;
  uint32_t i, u32BurnAddr, u32Tmp;
  uint8_t u8RxErrCnt = PROTOCOL_RX_EER_CNT;
  hs_protocolres_t enResponse;
  uint8_t *pu8FlhPtr = (uint8_t *)FLASH_ADDR;
  int ret;

  u32PackNum = (pstPackInfo->u32ImageLen + PROTOCOL_PACKDATA_LEN - 1) / PROTOCOL_PACKDATA_LEN;

  u32BurnAddr = 0;
  u32Tmp = PROTOCOL_PACKDATA_LEN - INFO_SIZE;

  pu8LoadPtr = g_u8PackBuf + 4 + INFO_SIZE;
  sfWrite(u32BurnAddr, pu8LoadPtr, u32Tmp);

  u32BurnAddr += u32Tmp;  
  enResponse = PROTOCOL_RES_NEXT;
  for(i = 0; i <= u32PackNum; )
  {
    ret = _upgrade_usbSendResponse(enResponse);
    if(ret != HS_OK)
    {
      break;
    } 
    
    enResponse = _upgrade_usbRxPackage(&pu8Ptr);
    if(enResponse == PROTOCOL_RES_END)
    {
      break;
    }

    if(enResponse == PROTOCOL_RES_REPEAT)
    {
      u8RxErrCnt --;
      if(u8RxErrCnt == 0)
      {
        return HS_ERR;
      }

      continue;
    }

    if(enResponse == PROTOCOL_RES_NEXT)
    {
      i++;
      u8RxErrCnt = PROTOCOL_RX_EER_CNT;

      sfWrite(u32BurnAddr, pu8Ptr, PROTOCOL_PACKDATA_LEN);
      u32BurnAddr += PROTOCOL_PACKDATA_LEN;
    }

  }

  if(enResponse == PROTOCOL_RES_END)
  {
    enResponse = PROTOCOL_RES_NEXT;
    _upgrade_usbSendResponse(enResponse);
  }

  return hs_upgrade_chkImg(pu8FlhPtr, 1);
}

int hs_upgrade_usbProc(void) 
{
  hs_packinfo_t stPackInfo;  
  int ret;
  
  ret = _upgrade_usbGetInfo(&stPackInfo);
  if(ret != HS_OK)
  {
    _upgrade_usbSendCAN();
    return HS_ERR;
  }

  /* begin to transfer */
  hs_upgrade_ledSetPad(&stPackInfo);
  hs_upgrade_ledSetStatus(&stPackInfo, CHIP_STATUS_BUSY);
  hs_upgrade_ledSetResult(&stPackInfo, CHIP_RES_OK);
  
  sfErase(0, stPackInfo.u32ImageLen);  
  ret = _upgrade_usbLoadBin(&stPackInfo);
  if(ret != HS_OK)
  {
    _upgrade_usbSendCAN();
    hs_upgrade_ledSetResult(&stPackInfo, CHIP_RES_ERR);
  }
  else
  {
    hs_upgrade_ledSetResult(&stPackInfo, CHIP_RES_OK);
  }

  hs_upgrade_ledSetStatus(&stPackInfo, CHIP_STATUS_IDLE);    
  return ret;
}

int32_t hs_upgrade_usbDownload(uint8_t *pu8CmdDataBuf, uint8_t u8CmdDataLen, 
                              uint8_t *pu8ResDataBuf, uint8_t u8ResDataLen)
{
  (void)pu8CmdDataBuf;
  (void)pu8ResDataBuf;
  (void)u8CmdDataLen;
  (void)u8ResDataLen;
  
  return hs_upgrade_usbProc();
}



