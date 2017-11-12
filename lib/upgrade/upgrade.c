#include "lib.h"

void _upgrade_parseStrForBtAddr(char *str, uint8_t addr[])
{
	int i, tmp, flag = 0, index = 0;
	char *ptr;

	strcat(str, " ");

	ptr = str;
	for(i=0; str[i] != '\0'; i++)
	{
		switch(str[i])
		{
			case ' ':			
			case ':':
			case ',':
				str[i] = 0;					
				if((flag == 0) && (ptr[0] != 0))
				{
					tmp= hs_upgrade_asc2bin(ptr);
					addr[index++] = tmp;

					if(index > 5)
						return ;
				}

				flag = 1;
				break;
			default:
				if(flag)
				{
					ptr = &str[i];
					flag = 0;
				}
				break;
		}
	}

	return ;
}

uint32_t _upgrade_asc2dec(const char *str)
{
  uint32_t val = 0, i = 0;

  while((str[i] >= '0') && (str[i] <= '9'))
  {
    val = val * 10 + (str[i] - '0');
    i++;
  }

  return val;
}

uint32_t hs_upgrade_asc2bin(const char *str)
{
  uint32_t val = 0, i = 0;

  while(1)
  {
    if((str[i] >= '0') && (str[i] <= '9')) 
      val = val * 0x10 + (str[i] - '0');
    else if((str[i] >= 'a') && (str[i] <= 'f'))
      val = val * 0x10 + (str[i] - 'a') + 0xa;
    else if((str[i] >= 'A') && (str[i] <= 'F'))
      val = val * 0x10 + (str[i] - 'A') + 0xa;      
    else
      return val;    

    i++;
  }

  return val;
}

void hs_upgrade_str2deci(char *str, uint32_t buf[])
{
  int i, tmp, flag = 0, index = 0;
	char *ptr;

	strcat(str, " ");

	ptr = str;
	for(i=0; str[i] != '\0'; i++)
	{
		switch(str[i])
		{
			case ' ':			
			case ':':
			case ',':
				str[i] = 0;					
				if((flag == 0) && (ptr[0] != 0))
				{
					tmp= _upgrade_asc2dec(ptr);
					buf[index++] = tmp;
				}

				flag = 1;
				break;
			default:
				if(flag)
				{
					ptr = &str[i];
					flag = 0;
				}
				break;
		}
	}
}

uint32_t hs_upgrade_calSum(uint8_t *u8Ptr, uint32_t u32Len)
{
  uint32_t i, u32Sum = 0;

  for(i=0; i<u32Len; i++)
  {
    u32Sum += u8Ptr[i];
  }

  return u32Sum;
}

int hs_upgrade_chkInfo(hs_packinfo_t *pstInfo)
{
  hs_packinfo_t tInfo;
  uint8_t *u8Ptr = (uint8_t *)&tInfo;
  uint32_t u32Sum;

  if((pstInfo->u32InfoFlg != INFO_WR_FLAG) 
      && (pstInfo->u32InfoFlg != INFO_LD_FLAG))
    return HS_ERR;

  memcpy(u8Ptr, pstInfo, INFO_SIZE);
  tInfo.u32InfoChkSum = 0;

  u32Sum = hs_upgrade_calSum(u8Ptr, INFO_SIZE);
  if(u32Sum == pstInfo->u32InfoChkSum)
    return HS_OK;

  return HS_ERR;
}

void hs_upgrade_infoEncrypt(hs_packinfo_t *pstInfo)
{
  pstInfo->u32CipherTxtFlg = IMG_CIPHER;
  pstInfo->u32InfoChkSum = 0;

  pstInfo->u32InfoChkSum = hs_upgrade_calSum((uint8_t *)pstInfo, INFO_SIZE);
}

hs_imginfo_t *hs_upgrade_getImgInfo(uint8_t *u8ImgData)
{
  return (hs_imginfo_t *)(u8ImgData + IMG_INFO_ADDR);  
}

int hs_upgrade_chkImg(uint8_t *u8ImgData, uint8_t u8ChkFlg)
{
  hs_imginfo_t *pstImgInfo;
  uint32_t u32Sum;

  pstImgInfo = hs_upgrade_getImgInfo(u8ImgData);

  if(pstImgInfo->u32ImgFlg == IMG_INFO_N_FLAG)
    return HS_OK;

  if(pstImgInfo->u32ImgFlg != IMG_INFO_FLAG)
    return HS_ERR;

  sfSetMemMode((flashmem_mode_t)pstImgInfo->u32FmemMode);
  if(u8ChkFlg)
  {
    u32Sum = hs_upgrade_calSum(u8ImgData, pstImgInfo->u32ImageLen);
    u32Sum -= u8ImgData[IMG_INFO_ADDR + IMGINFO_SIZE - 1];
    u32Sum -= u8ImgData[IMG_INFO_ADDR + IMGINFO_SIZE - 2];
    u32Sum -= u8ImgData[IMG_INFO_ADDR + IMGINFO_SIZE - 3];
    u32Sum -= u8ImgData[IMG_INFO_ADDR + IMGINFO_SIZE - 4];

    if(u32Sum != pstImgInfo->u32InfoChkSum)
      return HS_ERR;
  }

  return HS_OK;
}

void hs_upgrade_getAddrFromSd(uint8_t *btAddr, uint32_t index)
{
  FIL stFile;
  unsigned int i, u32Len, offset;
  uint8_t buf[BTADDR_LINE_SIZE+5];
  
  if(FR_OK != f_open(&stFile, LIST_FSPATH, FA_READ | FA_WRITE))
    return ;

  u32Len = f_size(&stFile);
  i = u32Len / BTADDR_LINE_SIZE;
  index = index % i;
  offset = index * BTADDR_LINE_SIZE;
  f_lseek(&stFile, offset);
  
  memset(buf, 0, BTADDR_LINE_SIZE+5);
  if(FR_OK != f_read(&stFile, (void *)buf, BTADDR_LINE_SIZE, (UINT *)&u32Len))
    return ;

  f_close(&stFile);
  _upgrade_parseStrForBtAddr((char *)buf, btAddr);
}

void hs_upgrade_incBtAddr(unsigned char * btAddr)
{
  unsigned short val, i;	

  val = btAddr[0] + 1;
  btAddr[0] = val;
  val = (val >> 8) & 0xff;

  for(i=1; i<6; i++)
  {
    if(val == 0)
      break;

    val += btAddr[i];
    btAddr[i] = val;
    val = (val >> 8) & 0xff;
  }
}

void hs_upgrade_decBtAddr(unsigned char * btAddr, uint32_t n)
{
  uint32_t u32Data;
  short val;

  __byte2dword(btAddr, u32Data);
  if(u32Data < n)
  {
    val = btAddr[4] - 1;
    btAddr[4] = val;

    if(val < 0)
      btAddr[5] -= 1;
  }

  u32Data -= n;
  __dword2byte(btAddr, u32Data);
}

void hs_upgrade_setBtAddr(unsigned char *btAddr, hs_packinfo_t *pstInfo)
{
  if(pstInfo->u32CfgDataEn == 0)
  {
    pstInfo->u32ChgModeArgc0 += 1;
    return ;
  }

  if(pstInfo->u32BTAddrChgMode == BTADDR_CHGMODE_FIX)
  {
    pstInfo->u32ChgModeArgc0 += 1;
    return ;
  }

  if(pstInfo->u32BTAddrChgMode == BTADDR_CHGMODE_INC)
  {
    hs_upgrade_incBtAddr(btAddr);
    pstInfo->u32ChgModeArgc0 += 1;
    return ;
  }

  if(pstInfo->u32BTAddrChgMode == BTADDR_CHGMODE_LOOP)
  {
    hs_upgrade_incBtAddr(btAddr);
    pstInfo->u32ChgModeArgc0 += 1;
    if((pstInfo->u32ChgModeArgc0 % pstInfo->u32ChgModeArgc1) == 0)
    {
      hs_upgrade_decBtAddr(btAddr, pstInfo->u32ChgModeArgc1);
    }
    
    return ;
  }

  if(pstInfo->u32BTAddrChgMode == BTADDR_CHGMODE_FILE)
  {
    pstInfo->u32ChgModeArgc0 += 1;
    hs_upgrade_getAddrFromSd(btAddr, pstInfo->u32ChgModeArgc0);    
    return ;
  }
}

