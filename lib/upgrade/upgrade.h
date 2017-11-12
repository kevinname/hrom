#ifndef __UPGRADE_H__
#define __UPGRADE_H__

#define INFO_WR_FLAG              0x31305257
#define INFO_LD_FLAG              0x3130444c
#define INFO_SIZE                 sizeof(hs_packinfo_t)
#define IMGINFO_SIZE              sizeof(hs_imginfo_t)
#define BTADDR_LINE_SIZE          0x13

#define PAGE_SIZE                 256
#define SIZE_1K                   1024
#define SIZE_4K                   (4 * 1024)
#define SIZE_16K                  (16 * 1024)
#define SIZE_64K                  (64 * 1024)
#define SIZE_512K                 (512 * 1024)
#define SIZE_1M                   (1024 * 1024)

#define HS_OK                     0
#define HS_ERR                    -1

#define IMG_PLAIN                 0
#define IMG_CIPHER                1

#define IMG_INFO_ADDR             0x10
#define IMG_INFO_FLAG             0x01664B50
#define IMG_INFO_N_FLAG           0x09000064

#define FLASH_ADDR                0x80000000
#define FLASH_SIZE                SIZE_1M
#define KEY_ADDR                  (FLASH_ADDR + FLASH_SIZE - FLASH_SECTOR_SIZE)

typedef enum
{
  XTAL_SEL_16M        = 0,
  XTAL_SEL_24M        = 1,
}hs_xtalsel_t;

typedef enum
{
  BOOT_SEL_USB        = 0,
  BOOT_SEL_FLASH      = 1,
}hs_bootsel_t;

enum
{
  BTADDR_CHGMODE_FIX        = 0,
  BTADDR_CHGMODE_INC        ,
  BTADDR_CHGMODE_LOOP       ,
  BTADDR_CHGMODE_FILE       ,
};

typedef struct 
{
  uint32_t      u32InfoFlg;          /*!< Info Flag                          */
  uint32_t      u32InfoChkSum;       /*!< Info checksum                      */
  uint32_t      u32InfoDate;         /*!< Info generate date                 */
  
  uint32_t      u32ImageLen;         /*!< Image length                       */
  uint32_t      u32CipherTxtFlg;
  
  uint32_t      u32CfgDataEn;
  uint32_t      u32BTAddrOffset;
  uint32_t      u32BTAddrChgMode;
  uint32_t      u32ChgModeArgc0;
  uint32_t      u32ChgModeArgc1;
  
  uint32_t      u32StatusIO;
  uint32_t      u32StatusIOLvl;

  uint32_t      u32ResultIO;
  uint32_t      u32ResultIOLvl;

  uint32_t      u32KeyAddr;

  uint32_t      u32Reserve[17];
} hs_packinfo_t;


typedef struct 
{
  uint32_t      u32ImgFlg;          
  uint32_t      u32Version;  
  uint32_t      u32ImageLen; 

  uint32_t      u32FmemMode;

  uint32_t      u32ClkUsed;
  uint32_t      u32SFRegCfg;
  uint32_t      u32CpmRegSf;  
  
  uint32_t      u32InfoChkSum;    
} hs_imginfo_t;

typedef struct 
{
  int      u32TotalNum;          
  int      u32SuccesNum;      
  int      u32FailNum;   
}hs_statis_t;


uint32_t hs_upgrade_calSum(uint8_t *u8Ptr, uint32_t u32Len);
uint32_t hs_upgrade_asc2bin(const char *str);
void hs_upgrade_str2deci(char *str, uint32_t buf[]);
int hs_upgrade_chkInfo(hs_packinfo_t *pstInfo);
void hs_upgrade_infoEncrypt(hs_packinfo_t *pstInfo);
hs_imginfo_t *hs_upgrade_getImgInfo(uint8_t *u8ImgData);
int hs_upgrade_chkImg(uint8_t *u8ImgData, uint8_t u8ChkFlg);
void hs_upgrade_incBtAddr(unsigned char * btAddr);
void hs_upgrade_setBtAddr(unsigned char *btAddr, hs_packinfo_t *pstInfo);
  

#endif
