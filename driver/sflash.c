#include "sflash.h"

#define SF_CS_SELECT			0

#define sf_inw(reg)           (reg)
#define sf_outw(reg, data)    ((reg) = (data))

static const flash_info_t g_stFlashInfo[] = 
{
  /* name         mid     page  sector   otp  qe  qe_bit  */
  {"GD25Q80C", 0xc84014,  256,  4*1024,  10,  1,     9   },
  {"GD25Q16B", 0xc84015,  256,  4*1024,  10,  1,     9   },
    
  {"PN25F08",  0xe04014,  256,  4*1024,  11,  1,     9   },  /* is same as BY25Q80A */
  {"PN25F08B", 0x5e4014,  256,  4*1024,  -1,  0,    -1   },
  {"PN25F04C", 0x1c3113,  256,  4*1024,  -1,  1,    -1   },
    
  {"BY25D80",  0x684014,  256,  4*1024,  -1,  0,    -1   },
  {"BY25D40",  0x684013,  256,  4*1024,  -1,  0,    -1   },

  {"MD25D80",  0x514014,  256,  4*1024,  -1,  0,    -1   },
  {"MD25D40",  0x514013,  256,  4*1024,  -1,  0,    -1   },

  {"W25Q80DV", 0xef4014,  256,  4*1024,  11,  1,     9   },
  {"W25Q40CL", 0xef4013,  256,  4*1024,  11,  1,     9   },

  {"Default",  0x123456,  256,  4*1024,  -1,  0,    -1   },
};

static const uint32_t g_u32FlashNum = sizeof(g_stFlashInfo) / sizeof(flash_info_t);
static flash_info_t const * g_pstFlashInfo;

static uint32_t g_u32FlashIsLock = 0;

/*===========================================*/
/*   SPI driver                              */
/*===========================================*/
void n12_dcache_invalidate(void);
void nds32_dcache_clean(void);

void sf_wait(void)
{
  uint32_t t=0x10000000;
  
  while(((sf_inw(SFLASH->RAW_INTR_STATUS) & 1) == 0) && (t--)) ;

  sf_outw(SFLASH->RAW_INTR_STATUS, sf_inw(SFLASH->RAW_INTR_STATUS));
}

static uint32_t sf_read_mid(void) 
{
  uint32_t mid, cmd_r = 0; 
  uint32_t fcfg = SFLASH->CONFIGURATION_1;

  SFLASH->CONFIGURATION_1 = 0;

  cmd_r |= SF_CMD_WIDTH(32);
  cmd_r |= (SF_CS_SELECT & 3) << 4;
  cmd_r |= SF_CMD_READ;
  cmd_r |= SF_CMD_KEEPCS;

  SFLASH->RAW_INTR_STATUS   = SFLASH->RAW_INTR_STATUS;
  SFLASH->COMMAND_DATA0_REG = SF_CMD_RDID;
  SFLASH->COMMAND = cmd_r;

  sf_wait();
  mid = SFLASH->READ0_REG & 0xffffff;

  SFLASH->CONFIGURATION_1 = fcfg;
  return mid;   
}

static uint32_t sf_read_status_0(void) {
  uint32_t status, cmd_r = 0;
  uint32_t fcfg = SFLASH->CONFIGURATION_1;

  SFLASH->CONFIGURATION_1 = 0;

  cmd_r |= SF_CMD_WIDTH(16);
  cmd_r |= (SF_CS_SELECT & 3) << 4;
  cmd_r |= SF_CMD_READ;
  cmd_r |= SF_CMD_KEEPCS;

  SFLASH->RAW_INTR_STATUS   = SFLASH->RAW_INTR_STATUS;
  SFLASH->COMMAND_DATA0_REG = SF_CMD_RDSTAS;
  SFLASH->COMMAND = cmd_r;

  sf_wait();

  status = SFLASH->READ0_REG & 0xff;
  SFLASH->CONFIGURATION_1 = fcfg;
 
  return status;   
}

static uint32_t sf_read_status_1(void) {
  uint32_t status, cmd_r = 0;
  uint32_t fcfg = SFLASH->CONFIGURATION_1;

  SFLASH->CONFIGURATION_1 = 0;

  cmd_r |= SF_CMD_WIDTH(16);
  cmd_r |= (SF_CS_SELECT & 3) << 4;
  cmd_r |= SF_CMD_READ;
  cmd_r |= SF_CMD_KEEPCS;

  SFLASH->RAW_INTR_STATUS   = SFLASH->RAW_INTR_STATUS;
  SFLASH->COMMAND_DATA0_REG = SF_CMD_RDSTAS1;
  SFLASH->COMMAND = cmd_r;

  sf_wait();

  status = SFLASH->READ0_REG & 0xff;
  SFLASH->CONFIGURATION_1 = fcfg;

  return status;   
}

uint32_t sf_read_status(void){
  uint32_t status;

  status  = sf_read_status_1();
  status = sf_read_status_0() + (status << 8);

  return status;
}

void sf_write_status(uint32_t status) 
{
  uint32_t cmd_r = 0, cmd_data = 0;
  uint32_t fcfg = SFLASH->CONFIGURATION_1;

  SFLASH->CONFIGURATION_1 = 0;

  cmd_r |= SF_CMD_WIDTH(24);
  cmd_r |= (SF_CS_SELECT & 3) << 4;
  cmd_r |= SF_CMD_WRITE;
  cmd_r |= SF_CMD_KEEPCS;

  cmd_data = SF_CMD_WRSTAS;
  cmd_data |= (status & 0xff) << 16;
  cmd_data |= ((status >> 8) & 0xff) << 8;

  SFLASH->RAW_INTR_STATUS   = SFLASH->RAW_INTR_STATUS;
  SFLASH->COMMAND_DATA0_REG = cmd_data;
  SFLASH->COMMAND = cmd_r;     

  sf_wait();
  SFLASH->CONFIGURATION_1 = fcfg;

  while(1) 
  {
    status = sf_read_status();
    if((status & 1) == 0)
    {
      break;
    }
  } 
}

void sf_write_enable(void) 
{
  uint32_t cmd_r = 0;
  uint32_t fcfg = SFLASH->CONFIGURATION_1;

  SFLASH->CONFIGURATION_1 = 0;

  cmd_r |= SF_CMD_WIDTH(8);
  cmd_r |= (SF_CS_SELECT & 3) << 4;
  cmd_r |= SF_CMD_WRITE;
  cmd_r |= SF_CMD_KEEPCS;

  SFLASH->RAW_INTR_STATUS   = SFLASH->RAW_INTR_STATUS;
  SFLASH->COMMAND_DATA0_REG = SF_CMD_WREN;
  SFLASH->COMMAND = cmd_r;

  sf_wait();
  SFLASH->CONFIGURATION_1 = fcfg;
}

void sf_wrStart(void)
{
  uint32_t status;
  status = sf_read_status();

  sf_write_enable();
  sf_write_status((status&0xff83));
}

void sf_setflash_wren(void) 
{
  uint32_t status;

  status = sf_read_status();
 
  while(1) {
    sf_write_enable();

    status = sf_read_status();
    if((status & 0x3) == 2) {
      break;
    }
    
    if((status & 0x1c) != 0) {
      sf_write_status((status&0x783) | 0x200);
    }
  }
}

void sf_chip_erase(void) 
{
  uint32_t status, cmd_r = 0;
  uint32_t fcfg = SFLASH->CONFIGURATION_1;

  SFLASH->CONFIGURATION_1 = 0;
  
  sf_setflash_wren();
  
  cmd_r |= SF_CMD_WIDTH(8);
  cmd_r |= (SF_CS_SELECT & 3) << 4;
  cmd_r |= SF_CMD_WRITE;
  cmd_r |= SF_CMD_KEEPCS;

  SFLASH->RAW_INTR_STATUS   = SFLASH->RAW_INTR_STATUS;
  SFLASH->COMMAND_DATA0_REG = SF_CMD_CE;
  SFLASH->COMMAND           = cmd_r;

  sf_wait();
  SFLASH->CONFIGURATION_1 = fcfg;

  while(1) {
    status = sf_read_status();
    if((status & 1) == 0) {
      break;
    }
  }     
}

void sf_sector_erase(uint32_t offset) 
{
  uint32_t status, cmd_r = 0, cmd_d = 0;
  uint32_t fcfg = SFLASH->CONFIGURATION_1;

  SFLASH->CONFIGURATION_1 = 0;
  
  sf_setflash_wren();

  cmd_r |= SF_CMD_WIDTH(32);
  cmd_r |= (SF_CS_SELECT & 3) << 4;
  cmd_r |= SF_CMD_WRITE;
  cmd_r |= SF_CMD_KEEPCS;

  cmd_d |= SF_CMD_SE;
  cmd_d |= offset & 0xffffff;

  SFLASH->RAW_INTR_STATUS   = SFLASH->RAW_INTR_STATUS;
  SFLASH->COMMAND_DATA0_REG = cmd_d;
  SFLASH->COMMAND           = cmd_r;

  sf_wait();
  SFLASH->CONFIGURATION_1 = fcfg;

  while(1) {
    status = sf_read_status();
    if((status & 1) == 0) {
      break;
    }
  }     
}

void sf_page_write(uint32_t offset, unsigned char *wrbuf, int len) 
{
  uint32_t status, cmd_r = 0, cmd_d = 0;
  int page_size = FLASH_PPPAGE_SIZE;
  uint32_t fcfg = SFLASH->CONFIGURATION_1;

  SFLASH->CONFIGURATION_1 = 0;

  if(len > page_size) 
  {
    return ;
  }

  sf_setflash_wren();
  
  cmd_r |= SF_DATA_CNT(len);
  cmd_r |= SF_CMD_WIDTH(32);
  cmd_r |= (SF_CS_SELECT & 3) << 4;
  cmd_r |= SF_CMD_WRITE;
  cmd_r |= SF_CMD_KEEPCS;

  cmd_d |= SF_CMD_PP;
  cmd_d |= offset & 0xffffff;

  SFLASH->RAW_INTR_STATUS   = SFLASH->RAW_INTR_STATUS;
  sf_outw(SFLASH->COMMAND_DATA0_REG, cmd_d);
  sf_outw(SFLASH->ADDRESS_REG, (uint32_t)wrbuf);
  sf_outw(SFLASH->COMMAND, cmd_r);

  sf_wait();
  SFLASH->CONFIGURATION_1 = fcfg;

  while(1) 
  {
    status = sf_read_status();
    if((status & 1) == 0) 
    {
      break;
    }
  }   
}

int sfErase(uint32_t offset, uint32_t len) 
{
  uint32_t i, setor_num = 0;

  if(!g_pstFlashInfo)
    return 0;

  sf_wrStart();
  
  if(len == 0) 
  {
    sf_chip_erase();
    return 0;
  }

  setor_num = (len + FLASH_SECTOR_SIZE - 1) / FLASH_SECTOR_SIZE;

  for(i = 0; i < setor_num; i++) 
  {
    sf_sector_erase(offset);
    offset += FLASH_SECTOR_SIZE;
  }

  n12_dcache_invalidate();
  return 0;
}

int sfWrite(uint32_t offset, uint8_t *wrbuf, int len) 
{  
  unsigned char *bufp;
  uint32_t i, cnt, transLen;

  if(!g_pstFlashInfo)
    return 0;

  nds32_dcache_clean();

  bufp = wrbuf;

  if(offset % FLASH_PPPAGE_SIZE) 
  {
    transLen = FLASH_PPPAGE_SIZE - (offset % FLASH_PPPAGE_SIZE);
    
    transLen = len > transLen ? transLen : len;

    sf_page_write(offset, bufp, transLen);

    offset += transLen;
    bufp += transLen;
    len -= transLen;  
    
    if(len == 0)
      return 0;
  }

  if(len % FLASH_PPPAGE_SIZE)
    cnt = len / FLASH_PPPAGE_SIZE + 1;
  else
    cnt = len / FLASH_PPPAGE_SIZE;

  for(i = 0; i < cnt; i++) 
  {
    if(len > FLASH_PPPAGE_SIZE)
      transLen = FLASH_PPPAGE_SIZE;
    else
      transLen = len;
	
    sf_page_write(offset, bufp, transLen);

    offset += transLen;
    bufp += transLen;
    len -= transLen;
  }

  n12_dcache_invalidate();
  return 0;
}

void sfQuadEn(int8_t qe_bit)
{
  uint32_t status;  

  if(qe_bit >= 0)
  {
    sf_write_enable();
    status = sf_read_status();  
    sf_write_status(status | (1u << qe_bit));  
  }
}

void sfSetClkCfg(uint32_t u32Cfg)
{
  SFLASH->CONFIGURATION_0 = u32Cfg;
}

void sfSetMemMode(flashmem_mode_t mode)
{
  uint32_t m = mode & 0xff;

  if(!g_pstFlashInfo)
    return ;

  m = (m << 8) + m;
  SFLASH->READ_OPCODE_REG = m;

  if((mode == FLASHMEM_MODE_QUAD) && (g_pstFlashInfo->qe_support))
  {
    sfQuadEn(g_pstFlashInfo->qe_bit);
    SFLASH->CONFIGURATION_1 &= ~(1u << 10);
  }

  if(mode == FLASHMEM_MODE_DUAL)
    SFLASH->CONFIGURATION_1 |= (1u << 10);
    
  n12_dcache_invalidate();
}

bool sfChkFlash(void) 
{
  uint32_t i, mid;
  
  usleep(200);
  mid = sf_read_mid();

  if(((mid & 0xffffff) == 0xffffff) || ((mid & 0xffffff) == 0))
    return FALSE;

  for(i=0; i<(g_u32FlashNum - 1); i++)
  {
    if(mid == g_stFlashInfo[i].mid)
    {
      g_pstFlashInfo = &g_stFlashInfo[i];
      break;
    }
  }

  if(i >= (g_u32FlashNum - 1))
    g_pstFlashInfo = &g_stFlashInfo[g_u32FlashNum - 1];

  return g_pstFlashInfo->otp_bit > 0 ? TRUE : FALSE;
}

bool sfIsLock(void)
{
  return (g_u32FlashIsLock ? TRUE : FALSE);
}

void sfInit(void)
{
  uint32_t pclk;
  
  pclk = CPM_GetPllClk();
  CPM_CfgModuleClk(CPM_MODULE_SF, pclk / 2);
  
  if(1 == CPM_GetVersion())
    sf_outw(SFLASH->CONFIGURATION_0, 2);
  else  
    sf_outw(SFLASH->CONFIGURATION_0, 8);

  sf_outw(SFLASH->INTR_MASK, 0x00000000);
  SF_SELECT_INTER();

  if(sfChkFlash())
    g_u32FlashIsLock = (sf_read_status() >> g_pstFlashInfo->otp_bit) & 0x1;
  else
    g_u32FlashIsLock = 0; 
  
  if(g_pstFlashInfo)
  {
    if(g_pstFlashInfo->qe_support)
      sfSetMemMode(FLASHMEM_MODE_QUAD);
    else
      sfSetMemMode(FLASHMEM_MODE_DUAL);
  }
}


