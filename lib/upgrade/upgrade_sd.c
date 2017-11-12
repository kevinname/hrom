#include "lib.h"
#include <nds32_intrinsic.h>

#define __upgrade_sdLoadBinError(res, label)    \
  do \
  { \
    res = HS_ERR;\
    goto label;\
  }while(0)


int _upgrade_sdGetStatis(hs_statis_t *pstStatis)
{
  FIL stFile;
  uint32_t u32Len;
  char buf[64];

  if(pstStatis == NULL)
    return HS_ERR;

  if(FR_OK != f_open(&stFile, STAT_FSPATH, FA_READ))
  {
    pstStatis->u32TotalNum = 0;
    pstStatis->u32FailNum = 0;
    pstStatis->u32SuccesNum = 0;
    return HS_ERR;
  }

  memset(buf, 0, 64);
  f_read(&stFile, (void *)buf, 64, (UINT *)&u32Len);
  f_close(&stFile);
  hs_upgrade_str2deci(buf, (uint32_t *)pstStatis);
  return HS_OK;
}

int _upgrade_sdUpdateStatis(hs_statis_t *pstStatis)
{
  FIL stFile;
  char buf[64];

  if(pstStatis == NULL)
    return HS_ERR;

  if(FR_OK != f_open(&stFile, STAT_FSPATH, FA_READ | FA_WRITE))
  {
    return HS_ERR;
  }

  memset(buf, 0, 64);
  f_printf(&stFile, "%d %d %d", pstStatis->u32TotalNum, pstStatis->u32SuccesNum, pstStatis->u32FailNum);
  f_sync(&stFile);
  f_close(&stFile);  
  return HS_OK;
}


int _upgrade_sdGetInfo(hs_packinfo_t *pstPackInfo)
{
  FIL stFile;
  uint32_t u32Len;

  if(pstPackInfo == NULL)
    return HS_ERR;

  if(FR_OK != f_open(&stFile, IMG_FSPATH, FA_READ | FA_WRITE))
    return HS_ERR;

  if(FR_OK != f_read(&stFile, (void *)pstPackInfo, INFO_SIZE, (UINT *)&u32Len))
    return HS_ERR;

  if(HS_OK != hs_upgrade_chkInfo(pstPackInfo))
    return HS_ERR;

  f_close(&stFile);
  return HS_OK;
}

int _upgrade_sdLoadBin(hs_packinfo_t *pstPackInfo)
{
  hs_imginfo_t  *pstImgInfo, *pstImgTmp;
  FIL stFile;
  uint8_t u8ImgBuf[IMG_CIPHER_LEN];
  uint8_t u8TmpBuf[IMG_CIPHER_LEN];
  uint8_t u8Key[8];
  uint32_t u32Offset, u32tmpLen, u32Len;
  uint8_t *pu8FlhPtr = (uint8_t *)FLASH_ADDR;
  int res = HS_OK;
  
  if(FR_OK != f_open(&stFile, IMG_FSPATH, FA_READ | FA_WRITE))
    return HS_ERR;

  f_lseek(&stFile, INFO_SIZE);
  if(FR_OK != f_read(&stFile, u8ImgBuf, IMG_CIPHER_LEN, (UINT *)&u32Len))
    __upgrade_sdLoadBinError(res, __sdprocess_exit);

  pstImgInfo = hs_upgrade_getImgInfo(u8ImgBuf);
  memcpy(u8Key, (char *)pstPackInfo->u32KeyAddr, 8);

  if(pstPackInfo->u32CipherTxtFlg == IMG_CIPHER)
  {  
    DES_Decrypt(u8ImgBuf, u8Key, u8ImgBuf, IMG_CIPHER_LEN);
  }

  /* 
   * data in u8ImgBuf is plaintext 
   */

  if(HS_OK != hs_upgrade_chkImg(u8ImgBuf, 0))
    __upgrade_sdLoadBinError(res, __sdprocess_exit);

  if(HS_OK == hs_upgrade_chkImg(pu8FlhPtr, 1))
  {
    pstImgTmp = hs_upgrade_getImgInfo(pu8FlhPtr);

    if(pstImgTmp->u32Version == pstImgInfo->u32Version)
      __upgrade_sdLoadBinError(res, __sdprocess_exit);
  }

  u32Len = pstPackInfo->u32ImageLen;

  sfErase(0, u32Len);
  sfWrite(0, u8ImgBuf, IMG_CIPHER_LEN);  
  
  u32Offset = IMG_CIPHER_LEN;
  while(u32Len)
  {
    u32tmpLen = u32Len > IMG_CIPHER_LEN ? IMG_CIPHER_LEN : u32Len;
    
    if(FR_OK != f_read(&stFile, u8TmpBuf, u32tmpLen, (UINT *)&u32tmpLen))
      __upgrade_sdLoadBinError(res, __sdprocess_exit);
    
    if(u32tmpLen == 0)
    	break;

    sfWrite(u32Offset, u8TmpBuf, u32tmpLen);

    u32Offset += u32tmpLen;
    u32Len    -= u32tmpLen;
  };

  /* check flash data written is right */
  if(HS_OK != hs_upgrade_chkImg(pu8FlhPtr, 1))
    __upgrade_sdLoadBinError(res, __sdprocess_exit);

  /* increase bt address */
  if(pstPackInfo->u32CfgDataEn)
  {
    f_lseek(&stFile, pstPackInfo->u32BTAddrOffset);
    if(FR_OK != f_read(&stFile, u8TmpBuf, 6, (UINT *)&u32tmpLen))
      __upgrade_sdLoadBinError(res, __sdprocess_exit);

    hs_upgrade_setBtAddr(u8TmpBuf, pstPackInfo);
    
    f_lseek(&stFile, pstPackInfo->u32BTAddrOffset);
    if(FR_OK != f_write(&stFile, u8TmpBuf, 6, (UINT *)&u32tmpLen))
      __upgrade_sdLoadBinError(res, __sdprocess_exit);
  }
  else
  {
    pstPackInfo->u32ChgModeArgc0 ++;
  }

  u32tmpLen = pstPackInfo->u32CipherTxtFlg;
  hs_upgrade_infoEncrypt(pstPackInfo);
  f_lseek(&stFile, 0);
  if(FR_OK != f_write(&stFile, (void *)pstPackInfo, INFO_SIZE, (UINT *)&u32Len))
    __upgrade_sdLoadBinError(res, __sdprocess_exit);

  if(u32tmpLen == IMG_PLAIN)
  {
    DES_Encrypt(u8ImgBuf, u8Key, u8ImgBuf, IMG_CIPHER_LEN);

    if(FR_OK != f_write(&stFile, u8ImgBuf, IMG_CIPHER_LEN, (UINT *)&u32Len))
      __upgrade_sdLoadBinError(res, __sdprocess_exit);
  }

  f_sync(&stFile);
__sdprocess_exit:
  f_close(&stFile);

  return res;
}

int _upgrade_sdLoadRun(hs_packinfo_t *pstPackInfo)
{
  FIL stFile;
  uint8_t  u8TmpB[SIZE_4K], *pu8ImgPtr;
  uint32_t u32Len, u32TmpLen;

  if(FR_OK != f_open(&stFile, IMG_FSPATH, FA_READ | FA_WRITE))
    return HS_ERR;

  f_lseek(&stFile, INFO_SIZE);

  __nds32__mtsr(pstPackInfo->u32ChgModeArgc0 | 0x1, NDS32_SR_ILMB);
  __nds32__isb();

  pu8ImgPtr = (uint8_t *)pstPackInfo->u32ChgModeArgc0;
  u32Len = pstPackInfo->u32ImageLen;
  while(u32Len)
  {
    u32TmpLen = u32Len > SIZE_4K ? SIZE_4K : u32Len;
    if(FR_OK != f_read(&stFile, u8TmpB, u32TmpLen, (UINT *)&u32TmpLen))
      return HS_ERR;

    memcpy(pu8ImgPtr, u8TmpB, u32TmpLen);

    u32Len -= u32TmpLen;
    pu8ImgPtr += u32TmpLen;
  }

  pu8ImgPtr = (uint8_t *)pstPackInfo->u32ChgModeArgc0;
  if(HS_OK != hs_upgrade_chkImg(pu8ImgPtr, 1))
    return HS_ERR;

  ((void (*)(void))(pu8ImgPtr))();
  return HS_OK;
}

int hs_upgrade_sdProc(void) 
{
  hs_packinfo_t stPackInfo;  
  hs_statis_t   stStatis;
  int ret;  
  
  ret = _upgrade_sdGetInfo(&stPackInfo);
  if(ret != HS_OK)
  {
    return HS_ERR;
  }

  if(INFO_LD_FLAG == stPackInfo.u32InfoFlg)
  {
    if(sfIsLock() == FALSE)
      return _upgrade_sdLoadRun(&stPackInfo);
    else
      return HS_ERR;
  }

  _upgrade_sdGetStatis(&stStatis);
  if((stStatis.u32TotalNum > 0) && (stStatis.u32SuccesNum > stStatis.u32TotalNum))
  {
    return HS_ERR;
  }

  /* begin to transfer */
  hs_upgrade_ledSetPad(&stPackInfo);
  hs_upgrade_ledSetStatus(&stPackInfo, CHIP_STATUS_BUSY);
  hs_upgrade_ledSetResult(&stPackInfo, CHIP_RES_OK);
  
  ret = _upgrade_sdLoadBin(&stPackInfo);
  if(ret != HS_OK)
  {
    hs_upgrade_ledSetResult(&stPackInfo, CHIP_RES_ERR);
    stStatis.u32FailNum += 1;
  }
  else
  {
    hs_upgrade_ledSetResult(&stPackInfo, CHIP_RES_OK);    
  }
  stStatis.u32SuccesNum = stPackInfo.u32ChgModeArgc0;

  _upgrade_sdUpdateStatis(&stStatis);
  hs_upgrade_ledSetStatus(&stPackInfo, CHIP_STATUS_IDLE);  
  return ret;
}


