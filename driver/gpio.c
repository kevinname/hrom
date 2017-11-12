/* ----------------------------------------------------------------------
 * Copyright (C) 2015 HunterSun Limited. All rights reserved.
 *
 * $Date:        16. May 2015
 * $Revision:    V1.0
 *
 * Project:      GPIO Driver definitions for HS6601
 * -------------------------------------------------------------------- */

#include "gpio.h"


/**
  \fn          bool GPIO_PinConfigure (GPIO_Type *pGPIOx, uint32_t pin_num, const GPIO_Config *pCfg)
  \brief       Configure port pin
  \param[in]   pGPIOx        Pointer to GPIO peripheral
  \param[in]   pin_num       Port pin number
  \param[in]   pCfg          Port pin config
  \return      0  - success
               <0 - error
*/
int GPIO_PinConfigure(GPIO_Type *pGPIOx, uint32_t pin_num, const GPIO_Config *pCfg) {

  PMU_Type *pPmu = PMU;
  __IO uint32_t *pReg = pPmu->PADC_CON;
  uint32_t val, mask;

  if( ((pGPIOx != GPIO0) && (pGPIOx != GPIO1)) || (pin_num >= 16))
    return -1;

  pReg += pGPIOx == GPIO0 ? pin_num : 16 + pin_num;    
  val = pCfg->pull == GPIO_PULL_NO ? 0 :
          pCfg->pull == GPIO_PULL_UP ? 1 : 2;
  val <<= GPIO_PULL_BO;
  val |= pCfg->dir & GPIO_DIR_MASK;
  val |= (pCfg->drv & GPIO_DRV_MASK) << GPIO_DRV_BO;
  val |= (pCfg->mode & GPIO_MODE_MASK) << GPIO_MODE_BO;

  *pReg = val;

  if(GPIO_MODE_GPIO == pCfg->mode)
  {
    mask = 1u << pin_num;
    if(pCfg->dir == GPIO_DIR_INPUT) {
      pGPIOx->OUTENCLR = mask;    
    } 
    else {    
      pGPIOx->OUTENSET |= mask;
    }
  }

  if((pGPIOx == GPIO0) && (GPIO_MODE_SD == pCfg->mode)) {
    switch (pin_num) {
      case 6:
        val = 0; 
        break;
      case 8:
        val = 1; 
        break;      
      case 10:
        val = 2; 
        break;      
      case 11:
        val = 3; 
        break;
      case 12:
        val = 4; 
        break;      
      case 13:
        val = 5; 
        break;      
      default:
        val = 6;
    }

    if(val < 6)
      pPmu->GPIO_PL_UP_30K |= (1u << val);
  }
  
  return 0;
}


/**
  \fn          uint32_t GPIO_PinRead (GPIO_Type *pGPIOx, uint32_t pin_num)
  \brief       Read port pin
  \param[in]   pGPIOx     Pointer to GPIO peripheral
  \param[in]   pin_num    Port pin number
  \return      pin value (0 or 1)
*/
uint32_t GPIO_PinRead(GPIO_Type *pGPIOx, uint32_t pin_num) {
  return ((pGPIOx->DATA >> pin_num) & 1);
}

/**
  \fn          uint16_t GPIO_PortRead (GPIO_TypeDef *pGPIOx)
  \brief       Read port pins
  \param[in]   pGPIOx  Pointer to GPIO peripheral
  \return      port pin inputs
*/
uint32_t GPIO_PortRead(GPIO_Type *pGPIOx){
  return pGPIOx->DATA;
}


/**
  \fn          void GPIO_PinWrite (GPIO_TypeDef *GPIOx, uint32_t pin_num, uint32_t pin_val)
  \brief       Write port pin
  \param[in]   GPIOx      Pointer to GPIO peripheral
  \param[in]   pin_num    Port pin number
  \param[in]   pin_val    Port pin value (0 or 1)
*/
void GPIO_PinWrite(GPIO_Type *pGPIOx, uint32_t pin_num, uint32_t pin_val){  
  if(pin_val&1) 
    pGPIOx->DATAOUT |= 1u << pin_num;
  else
    pGPIOx->DATAOUT &= ~(1u << pin_num);
}


/**
  \fn          void GPIO_PortWrite (GPIO_Type *pGPIOx, uint32_t pin_mask, uint32_t pin_val)
  \brief       Write port pins
  \param[in]   pGPIOx     Pointer to GPIO peripheral
  \param[in]   pin_mask   Selected pins
  \param[in]   pin_val    Pin values
*/
void GPIO_PortWrite(GPIO_Type *pGPIOx, uint32_t pin_mask, uint32_t pin_val){ 
  pGPIOx->DATAOUT &= ~pin_mask;
  pGPIOx->DATAOUT |= pin_mask;
}



