/* ----------------------------------------------------------------------
 * Copyright (C) 2015 HunterSun Limited. All rights reserved.
 *
 * $Date:        16. May 2015
 * $Revision:    V1.0
 *
 * Project:      CPM Driver definitions for HS6600
 * -------------------------------------------------------------------- */

#ifndef __CPM_HS6600_H
#define __CPM_HS6600_H

#include "platform.h"

#define  PLL_CLOCK_96M          96000000
#define  PLL_CLOCK_128M         128000000
#define  PLL_CLOCK_192M         192000000
#define  XTAL_CLOCK_16M         16000000
#define  XTAL_CLOCK_24M         24000000

#define  XTAL_SEL_PIN           20u
#define  BOOT_SEL_PIN           19u
#define  SW_VERSION_BIT         3

#define CPM_SD_DEV_DRV_DELAY_BYPASS_Pos   1
#define CPM_SD_DEV_DRV_DELAY_OFFSET_Pos   8
#define CPM_SD_DEV_DRV_DELAY_OFFSET_Msk   (0x07 << CPM_SD_DEV_DRV_DELAY_OFFSET_Pos)
#define CPM_SD_DEV_SMP_DELAY_BYPASS_Pos   2
#define CPM_SD_DEV_SMP_DELAY_OFFSET_Pos   16
#define CPM_SD_DEV_SMP_DELAY_OFFSET_Msk   (0x07 << CPM_SD_DEV_SMP_DELAY_OFFSET_Pos)
#define CPM_SD_DEV_MCLK_INV_Pos           0

typedef enum
{
  CPM_PLLCLK_XCLK       = 0,
  CPM_PLLCLK_192M       ,
}CPM_PLLCLK;

typedef enum
{
  CPM_MODULE_CPU        = 0,
  CPM_MODULE_RAM        ,
  CPM_MODULE_AHB        ,
  CPM_MODULE_APB        ,
  CPM_MODULE_SF         ,
  CPM_MODULE_USB        ,
  CPM_MODULE_SD         ,
  CPM_MODULE_TIMER1     ,
  CPM_MODULE_TIMER2     ,
  CPM_MODULE_TIMER3     ,
  CPM_MODULE_UART0      ,
  CPM_MODULE_UART1      ,
  CPM_MODULE_I2C        ,
  CPM_MODULE_I2S        ,
  CPM_MODULE_CODEC      ,
  CPM_MODULE_BTPHY      ,
  CPM_MODULE_SPI0       ,
  CPM_MODULE_SPI1       ,
  CPM_MODULE_WDT        ,
  CPM_MODULE_DMA        ,
  CPM_MODULE_GPIO       ,
}CPM_MODULE;

typedef enum 
{
	SD_CLK_PHASE_0,
	SD_CLK_PHASE_180,
}sd_dev_mclk_phase_t;

typedef struct 
{
	sd_dev_mclk_phase_t mclk_phase;
	int8_t              smp_half_cycles;
	int8_t              drv_half_cycles;
}sd_dev_clk_t;


#define __cal_div(n,d)  (((n) + ((d) / 2)) / (d)) 

#define CPM_BIT(name)				\
  (1 << CPM_##name##_Pos)

#define CPM_BF(name,value)			\
  (((value) << CPM_##name##_Pos) & CPM_##name##_Msk)

#define CPM_BFINS(name,value,old)		\
  (((old) & ~CPM_##name##_Msk) | CPM_BF(name,value))


static inline void __wait_done(void)
{
  __asm__ volatile ("standby 2");
}

void usleep(uint32_t us);
/**
  \fn          void CPM_SetXclk(uint32_t clk)
  \brief       set xclk value
  \param[in]   clk        xclk value, default value = 16Mhz
*/
void CPM_SetXclk(uint32_t clk);
uint32_t CPM_GetPllClk(void);

/**
  \fn          bool CPM_StartPll(CPM_PLLCLK clk)
  \brief       Configure port pin
  \param[in]   clk          select pll clock
  \return      true  - success
               false - error
*/
int CPM_StartPll(CPM_PLLCLK clk);

/**
  \fn          bool CPM_CfgModuleClk(CPM_MODULE mod, uint32_t clk)
  \brief       Configure module clock
  \param[in]   mod        module
  \param[in]   clk        clock value
  \return      true  - success
               false - error
*/
int CPM_CfgModuleClk(CPM_MODULE mod, uint32_t clk);

/**
  \fn          void CPM_RstModule(CPM_MODULE mod)
  \brief       reset a module
  \param[in]   mod        module
  \return      true  - success
               false - error
*/
void CPM_RstModule(CPM_MODULE mod);

void CPM_SetSfClk(uint32_t val);
void CPM_SetSdDelay(sd_dev_clk_t *sd_dev_clk);

void PMU_WaitForUpdate(void);

#define CPM_GetXtalSel()      ( (PMU->GPIO_STATUS[0] >> XTAL_SEL_PIN  ) & 0x1u )
#define CPM_GetBootSel()      ( (PMU->GPIO_STATUS[0] >> BOOT_SEL_PIN  ) & 0x1u )
#define CPM_GetVersion()      ( (SYS->CHIP_ID        >> SW_VERSION_BIT) & 0x1u )

#endif /* __CPM_HS6600_H */
