/* ----------------------------------------------------------------------
 * Copyright (C) 2015 HunterSun Limited. All rights reserved.
 *
 * $Date:        16. May 2015
 * $Revision:    V1.0
 *
 * Project:      CPM Driver definitions for HS6601
 * -------------------------------------------------------------------- */

#include "cpm.h"

static uint32_t g_xclk = XTAL_CLOCK_16M;

static void _cpm_startPll(void)
{
  PMU_Type *pPmu = PMU;
  uint32_t *ptr = (uint32_t *)0x4000F010;
  uint32_t i=200000;  
  
  pPmu->BASIC &= ~(1u<<1);
  pPmu->BASIC |= 1u<<30;
  usleep(40);

  pPmu->BASIC &= ~(1u<<0);
  pPmu->BASIC |= 1u<<30;
  usleep(80);

  pPmu->BASIC |= (1u<<1);
  pPmu->BASIC |= 1u<<30;
  usleep(40);
 
  *ptr |= (1u <<9);
  usleep(60);
  *ptr &= ~(1u <<9);
  usleep(500);

  while(i--) {
    if(pPmu->BASIC & 0x80000000u)
      break;
  }
}

uint32_t CPM_GetPllClk(void)
{
  CPM_Type *pCpmPmu = CPM;
  
  return (pCpmPmu->CLK_SRC & 1) == 0 ? g_xclk : PLL_CLOCK_192M;
}

/**
  \fn          void CPM_SetXclk(uint32_t clk)
  \brief       set xclk value
  \param[in]   clk        xclk value, default value = 16Mhz
*/
void CPM_SetXclk(uint32_t clk)
{
  g_xclk = clk;
  if(g_xclk == XTAL_CLOCK_24M)
    PMU->PMU_CLOCK_MUX |=  1u << 31;
  else
    PMU->PMU_CLOCK_MUX &=  ~(1u << 31);
}

/**
  \fn          bool CPM_StartPll(CPM_PLLCLK clk)
  \brief       Configure port pin
  \param[in]   clk          select pll clock
  \return      0  - success
               <0 - error
*/
int CPM_StartPll(CPM_PLLCLK clk)
{	
  CPM_Type *pCpmPmu = CPM; 
  PMU_Type *pPmu = PMU;

  pPmu->BASIC &= ~(1u<<6);
  pPmu->BASIC |= 1u<<30;
  usleep(40);
  
  switch(clk)
  {
    case CPM_PLLCLK_XCLK:
      pCpmPmu->CLK_SRC = 0;
      __wait_done();
      break;

    case CPM_PLLCLK_192M:
      pCpmPmu->CLK_SRC = 0;
      __wait_done();
      
      _cpm_startPll();    
      
      pCpmPmu->CLK_SRC = 1;
      __wait_done();
      usleep(10);
      break;

    default:
      return -1;
  }

  return 0;
}

/**
  \fn          bool CPM_CfgModuleClk(CPM_MODULE mod, uint32_t clk)
  \brief       Configure module clock
  \param[in]   mod        module
  \param[in]   clk        clock value
  \return      0  - success
               <0 - error
*/
int CPM_CfgModuleClk(CPM_MODULE mod, uint32_t clk)
{
  CLK_Type *pClk = CLK;
  CPM_Type *pCpm = CPM;
  PMU_Type *pPmu = PMU;
  uint32_t pll_clk, div = 1, val;
#if UART_DEBUG
  float db;
  uint32_t frc;
#endif

  pll_clk = CPM_GetPllClk();  
  if(clk != 0)
    div = __cal_div(pll_clk, clk);
  
  switch(mod)
  {
    case CPM_MODULE_APB:
      val = pClk->PSO_APB_CFG;

      div /= 2;
      __set_bitsVal(val, 8, 14, div);
      __set_bitsVal(val, 0, 2, 0x5);

      pClk->PSO_APB_CFG = val;
      break;
      
    case CPM_MODULE_SF:
      val = pClk->PSO_SFLASH_CFG;
      
      if(clk != 0){
        __set_bitsVal(val, 8, 11, div);
        __set_bitsVal(val, 0, 4, 0x1d);
      }
      else {
        __set_bitVal(val, 1, 1);
      }

      pClk->PSO_SFLASH_CFG = val;
      __wait_done();
      break;

    case CPM_MODULE_USB:
      val = pClk->PSO_USB_CFP;
      
      if(clk != 0){
        __set_bitVal(val, 1, 0);
        __set_bitVal(val, 3, 0);
      }
      else {
        __set_bitVal(val, 1, 1);
        __set_bitVal(val, 3, 1);
      }
      
      pClk->PSO_USB_CFP = val;

      pPmu->ANA_CON &= ~(1u << 24);
      pPmu->BASIC |= 1u<<30;
      usleep(40);
      break;

    case CPM_MODULE_SD:
      val = pClk->PSO_SD_CFG;
      
      if(clk != 0){
        div /= 2;
        __set_bitsVal(val, 8, 12, div);
        __set_bitVal(val, 0, 1);
      }
      else {
        __set_bitVal(val, 1, 0);
      }

      pClk->PSO_SD_CFG = val;
      break;

#if UART_DEBUG
    case CPM_MODULE_UART0:
      val = pClk->PSO_UART0_CFG;
      
      if(clk != 0){
        db = pll_clk;
        db = db / clk;
        div = db;
        frc = ((pll_clk - div * clk) << 6) / clk;

        __set_bitsVal(val, 16, 21, frc);
        __set_bitsVal(val, 8, 13, div);
        __set_bitVal(val, 0, 1);
      }
      else {
        __set_bitVal(val, 0, 0);
      }

      pClk->PSO_UART0_CFG = val;
      break;

    case CPM_MODULE_UART1:
      val = pClk->PSO_UART1_CFG;
      
      if(clk != 0){
        db = pll_clk;
        db = db / clk;
        div = db;
        frc = ((pll_clk - div * clk) << 6) / clk;

        __set_bitsVal(val, 16, 21, frc);
        __set_bitsVal(val, 8, 13, div);
        __set_bitVal(val, 0, 1);
      }
      else {
        __set_bitVal(val, 0, 0);
      }


      pClk->PSO_UART1_CFG = val;
      break;
#endif
  	default:
  	  break;
  };

  pClk->PSO_REG_UDP = 1;
  pCpm->UPD = 1;
  
  return 0;
}

void CPM_SetSfClk(uint32_t val)
{
  CLK->PSO_SFLASH_CFG = val;
  __wait_done();

  CLK->PSO_REG_UDP = 1;
}

void usleep(uint32_t us)
{
  us *= 50;
  __delay_nops(us);
}

void PMU_WaitForUpdate(void)
{
  uint32_t ak = 0x10000;  

  while((ak--) && ((PMU->BASIC & (1u << 8)) == 0));
}

void CPM_SetSdDelay(sd_dev_clk_t *sd_dev_clk) 
{
	int32_t drv_val = sd_dev_clk->drv_half_cycles;
	int32_t smp_val = sd_dev_clk->smp_half_cycles;

	if (sd_dev_clk->mclk_phase == SD_CLK_PHASE_0)
		CLK->PSO_SD_DEV_CFG &= (~(CPM_BIT(SD_DEV_MCLK_INV)));
	else if(sd_dev_clk->mclk_phase == SD_CLK_PHASE_180)
		CLK->PSO_SD_DEV_CFG |= CPM_BIT(SD_DEV_MCLK_INV);

	if (smp_val == -1)
		CLK->PSO_SD_DEV_CFG |= CPM_BIT(SD_DEV_SMP_DELAY_BYPASS);
	else if (smp_val < 8) {
		CLK->PSO_SD_DEV_CFG &= (~(CPM_BIT(SD_DEV_SMP_DELAY_BYPASS)));
		CLK->PSO_SD_DEV_CFG = CPM_BFINS(SD_DEV_SMP_DELAY_OFFSET, smp_val-1, CLK->PSO_SD_DEV_CFG);
	}else{
		/* if half_cycle>8 defalt bypass */
		CLK->PSO_SD_DEV_CFG |= CPM_BIT(SD_DEV_SMP_DELAY_BYPASS);
	}

	if (drv_val == -1)
		CLK->PSO_SD_DEV_CFG |= CPM_BIT(SD_DEV_DRV_DELAY_BYPASS);
	else if (drv_val < 8) {
		CLK->PSO_SD_DEV_CFG &= (~(CPM_BIT(SD_DEV_DRV_DELAY_BYPASS)));
		CLK->PSO_SD_DEV_CFG = CPM_BFINS(SD_DEV_DRV_DELAY_OFFSET, drv_val-1, CLK->PSO_SD_DEV_CFG);
	}else{
		/* if half_cycle>8 defalt 3 */
		CLK->PSO_SD_DEV_CFG &= (~CPM_BIT(SD_DEV_DRV_DELAY_BYPASS));
		CLK->PSO_SD_DEV_CFG = CPM_BFINS(SD_DEV_DRV_DELAY_OFFSET, 3, CLK->PSO_SD_DEV_CFG);
	}
}


