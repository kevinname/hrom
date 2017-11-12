#ifndef __PLAT_HS6601__
#define __PLAT_HS6601__

#include <platform.h>
#include "stdbool.h"

#define SF_CMD_WREN          0x06000000
#define SF_CMD_RDSTAS        0x05000000
#define SF_CMD_RDSTAS1       0x35000000
#define SF_CMD_WRSTAS        0x01000000
#define SF_CMD_FTRD          0x0b000000
#define SF_CMD_RD            0x03000000
#define SF_CMD_PP            0x02000000
#define SF_CMD_SE            0x20000000
#define SF_CMD_BE            0xd8000000
#define SF_CMD_CE            0xc7000000
#define SF_CMD_RDID          0x9f000000
#define SF_CMD_DEEPPD        0xB9000000
#define SF_CMD_RELEASEPD     0xAB000000

#define SF_DATA_CNT(len)     ((len) << 16)
#define SF_CMD_WIDTH(bits)   ((bits) << 8)
#define SF_CMD_KEEPCS        (0u  << 6)
#define SF_CMD_READ          1
#define SF_CMD_WRITE         2

#define FLASH_PPPAGE_SIZE    256
#define FLASH_SECTOR_SIZE    (4*1024)

#define PLL_CLOCK_96M        96000000

#define RAM_BASE_ADDR        0x10000000
#define FLASHROM_BASE_ADDR   0x80000000


#define SF_SELECT_OUTER()         \
  do{ \
    PMU->BASIC &= ~(1u<<3); \
    PMU->BASIC |= (1u<<30); \
    PMU_WaitForUpdate();\
  }while(0)
  
#define SF_SELECT_INTER()         \
  do { \
    PMU->BASIC |= (1u<<3);  \
    PMU->BASIC |= (1u<<30); \
    PMU_WaitForUpdate();\
  }while(0)

typedef enum
{
  FLASHMEM_MODE_SINGLE    = 0x03,
  FLASHMEM_MODE_DUAL      = 0xBB,
  FLASHMEM_MODE_QUAD      = 0xEB,
}flashmem_mode_t;

typedef struct 
{
  const char    name[32];
  uint32_t      mid;
  uint32_t      page_size;
  uint32_t      sector_size;

  int8_t        otp_bit;
  int8_t        qe_support;
  int8_t        qe_bit;
}flash_info_t;


void sfInit(void);
int sfErase(uint32_t offset, uint32_t len);
int sfWrite(uint32_t offset, uint8_t *wrbuf, int len);

void sfSetClkCfg(uint32_t u32Cfg);
void sfSetMemMode(flashmem_mode_t mode);

bool sfIsLock(void);

#endif

