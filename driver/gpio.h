/* ----------------------------------------------------------------------
 * Copyright (C) 2015 HunterSun Limited. All rights reserved.
 *
 * $Date:        16. May 2015
 * $Revision:    V1.0
 *
 * Project:      GPIO Driver definitions for HS6600
 * -------------------------------------------------------------------- */

#ifndef __GPIO_HS6601_H
#define __GPIO_HS6601_H

#include "platform.h"

#define GPIO_PULL_BO      1
#define GPIO_DRV_BO       3
#define GPIO_MODE_BO      5

#define GPIO_DIR_MASK     0x1
#define GPIO_DRV_MASK     0x3
#define GPIO_MODE_MASK    0x3f

typedef enum
{
  GPIO_DIR_OUTPUT      = 0,
  GPIO_DIR_INPUT     ,
}GPIO_DIR;

typedef enum
{
  GPIO_PULL_NO      = 0,
  GPIO_PULL_UP      ,
  GPIO_PULL_DOWN    ,
}GPIO_PULL;

typedef enum
{
  GPIO_DRV_0        = 0,
  GPIO_DRV_1        ,
  GPIO_DRV_2        ,
  GPIO_DRV_3
}GPIO_DRV;

typedef enum
{
  GPIO_MODE_JTAG        = 0,
  GPIO_MODE_DEBUG       ,
  GPIO_MODE_TIMER       ,
  GPIO_MODE_SFLASH      ,
  GPIO_MODE_SD          ,
  GPIO_MODE_GPIO        ,
  GPIO_MODE_I2S         ,
  GPIO_MODE_CODEC       ,
  GPIO_MODE_I2C_SCK     ,
  GPIO_MODE_I2C_SDA     ,
  GPIO_MODE_FUN10       ,
  GPIO_MODE_FUN11       ,
  GPIO_MODE_FUN12       ,
  GPIO_MODE_FUN13       ,
  GPIO_MODE_FUN14       ,
  GPIO_MODE_FUN15       ,
  GPIO_MODE_FUN16       ,
  GPIO_MODE_FUN17       ,
  GPIO_MODE_FUN18       ,
  GPIO_MODE_FUN19       ,
  GPIO_MODE_FUN20       ,
  GPIO_MODE_FUN21       ,
  GPIO_MODE_FUN22       ,
  GPIO_MODE_FUN23       ,
  GPIO_MODE_FUN24       ,
  GPIO_MODE_FUN25       ,
  GPIO_MODE_FUN26       ,
  GPIO_MODE_FUN27       ,
  GPIO_MODE_FUN28       ,
  GPIO_MODE_FUN29       ,
  GPIO_MODE_FUN30       ,
  GPIO_MODE_FUN31       ,
  GPIO_MODE_FUN32       ,
  GPIO_MODE_FUN33       ,
  GPIO_MODE_FUN34       ,
  GPIO_MODE_FUN35       ,
  GPIO_MODE_FUN36       ,
  GPIO_MODE_FUN37       ,
  GPIO_MODE_FUN38       ,
  GPIO_MODE_FUN39       ,
  GPIO_MODE_FUN40       ,
  GPIO_MODE_FUN41       ,
  GPIO_MODE_FUN42       ,
  GPIO_MODE_FUN43       ,
  GPIO_MODE_FUN44       ,
  GPIO_MODE_FUN45       ,
  GPIO_MODE_FUN46       ,
  GPIO_MODE_FUN47       ,
  GPIO_MODE_FUN48       ,
  GPIO_MODE_FUN49       ,
}GPIO_MODE;

typedef struct
{
  GPIO_DIR    dir;
  GPIO_PULL   pull;
  GPIO_DRV    drv;
  GPIO_MODE   mode;
}GPIO_Config;

/**
  \fn          bool GPIO_PinConfigure (GPIO_Type *pGPIOx, uint32_t pin_num, const GPIO_Config *pCfg)
  \brief       Configure port pin
  \param[in]   pGPIOx        Pointer to GPIO peripheral
  \param[in]   pin_num       Port pin number
  \param[in]   pCfg          Port pin config
  \return      true  - success
               false - error
*/
int GPIO_PinConfigure(GPIO_Type *pGPIOx, uint32_t pin_num, const GPIO_Config *pCfg);

/**
  \fn          uint32_t GPIO_PinRead (GPIO_Type *pGPIOx, uint32_t pin_num)
  \brief       Read port pin
  \param[in]   pGPIOx     Pointer to GPIO peripheral
  \param[in]   pin_num    Port pin number
  \return      pin value (0 or 1)
*/
uint32_t GPIO_PinRead(GPIO_Type *pGPIOx, uint32_t pin_num);

/**
  \fn          uint16_t GPIO_PortRead (GPIO_TypeDef *pGPIOx)
  \brief       Read port pins
  \param[in]   pGPIOx  Pointer to GPIO peripheral
  \return      port pin inputs
*/
uint32_t GPIO_PortRead(GPIO_Type *pGPIOx);

/**
  \fn          void GPIO_PinWrite (GPIO_TypeDef *GPIOx, uint32_t pin_num, uint32_t pin_val)
  \brief       Write port pin
  \param[in]   GPIOx      Pointer to GPIO peripheral
  \param[in]   pin_num    Port pin number
  \param[in]   pin_val    Port pin value (0 or 1)
*/
void GPIO_PinWrite(GPIO_Type *pGPIOx, uint32_t pin_num, uint32_t pin_val);

/**
  \fn          void GPIO_PortWrite (GPIO_Type *pGPIOx, uint32_t pin_mask, uint32_t pin_val)
  \brief       Write port pins
  \param[in]   pGPIOx     Pointer to GPIO peripheral
  \param[in]   pin_mask   Selected pins
  \param[in]   pin_val    Pin values
*/
void GPIO_PortWrite(GPIO_Type *pGPIOx, uint32_t pin_mask, uint32_t pin_val);


#endif /* __GPIO_HS6600_H */
