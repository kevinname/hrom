/* ----------------------------------------------------------------------
 * Copyright (C) 2015 HunterSun Limited. All rights reserved.
 *
 * $Date:        16. May 2015
 * $Revision:    V1.0
 *
 * Project:      System definitions for HS6600
 * -------------------------------------------------------------------- */

#ifndef __SYSTEM_HS6600_H
#define __SYSTEM_HS6600_H

#include "stdint.h"
#include "string.h"
#include <nds32_intrinsic.h>

typedef enum
{
  IRQ_BTBB          = 0,
  IRQ_CODEC         = 1,
  IRQ_DMA_COMBO     = 2,
  IRQ_GPIO_COMBO    = 3,
  IRQ_TIMER_COMBO   = 4,
  IRQ_USBHOST       = 5,
  IRQ_SDHOST        = 6,
  IRQ_RTC           = 7,
  IRQ_UART0         = 8,
  IRQ_UART1         = 9,
  IRQ_I2C           = 10,
  IRQ_I2S_COMBO     = 11,
  IRQ_ADC           = 12,
  IRQ_SPIM0         = 13,
  IRQ_SPIM1         = 14,
  IRQ_BTPHY         = 15,
                    
  IRQ_TIM1          = 16,
  IRQ_TIM2          = 17,
  IRQ_TIM3          = 18,
  IRQ_RESERVE19     = 19,
  IRQ_RESERVE20     = 20,
  IRQ_RESERVE21     = 21,
  IRQ_RESERVE22     = 22,
  IRQ_RESERVE23     = 23,
  IRQ_RESERVE24     = 24,
  IRQ_RESERVE25     = 25,
  IRQ_RESERVE26     = 26,
  IRQ_RESERVE27     = 27,
                    
  IRQ_TIM0          = 28,
  IRQ_WDT           = 29,
  IRQ_SFLASH        = 30,
  IRQ_SWINT         = 31,
} IRQn_Type;

#ifndef NULL
#define NULL    0
#endif

#define __delay_nops(cnt)         \
do{                               \
  while (cnt-- > 0)               \
    __asm__ volatile (" nop  \n\t");     \
}while(0)


#define __clr_bit(val, bit)  (val) &= ~(1u << bit)
#define __set_bit(val, bit)  (val) |= (1u << bit)

#define __set_bitVal(val, bit, bitval)              \
do{                                                 \
  uint32_t mask;                                    \
  mask = 1u<<(bit);                                 \
  (val) = ((val)&~mask) | (((bitval)<<(bit))&mask); \
}while(0)

#define __set_bitsVal(val, s, e, bitval)            \
do{                                                 \
  uint32_t mask;                                    \
  mask = ((1u<<((e)-(s)+1)) - 1) << (s);            \
  (val) = ((val)&~mask) | (((bitval)<<(s))&mask);   \
}while(0)

#define __set_bitsMaskVal(val, mask, bitval)        \
do{                                                 \
  val &= ~(mask);                                   \
  val |= bitval;                                    \
}while(0)

#define __byte2word(lbyte, hbyte, word)         \
{                                               \
  word = hbyte & 0xff;                          \
  word = (word << 8) + lbyte;                   \
}

#define __byte2dword(buf, word)                 \
do                                              \
{                                               \
  word = buf[3];                                \
  word = (word << 8) + buf[2];                  \
  word = (word << 8) + buf[1];                  \
  word = (word << 8) + buf[0];                  \
}while(0)

#define __dword2byte(buf, word)                 \
do                                              \
{                                               \
  buf[0] = (word >> 0) & 0xff;                  \
  buf[1] = (word >> 8) & 0xff;                  \
  buf[2] = (word >> 16) & 0xff;                 \
  buf[3] = (word >> 24) & 0xff;                 \
}while(0)


#define SR_CLRB32(reg, bit) \
{     \
	int mask = __nds32__mfsr(reg)& ~(1<<bit); \
  __nds32__mtsr(mask, reg);           \
  __nds32__dsb(); \
}

#define SR_SETB32(reg,bit)\
{\
	int mask = __nds32__mfsr(reg)|(1<<bit);\
  __nds32__mtsr(mask, reg);     \
  __nds32__dsb();               \
}

#define SR_SETBS32(reg, s, e, bitval)      \
do{                                                 \
  uint32_t mask;                                    \
  mask = ((1u<<((e)-(s)+1)) - 1) << (s);              \
  __nds32__mtsr( ((__nds32__mfsr((reg)) & ~mask) | (((bitval)<<(s)) & mask)), reg);   \
  __nds32__dsb();       \
}while(0)

static inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  SR_SETB32(NDS32_SR_INT_MASK2, IRQn); /* enable interrupt */
}

static inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 16) {
    SR_SETBS32(NDS32_SR_INT_PRI, (IRQn*2), (IRQn*2+1), priority);
  } /* set Priority for 0-15 Interrupts */
  else {
    SR_SETBS32(NDS32_SR_INT_PRI2, (IRQn*2), (IRQn*2+1), priority);   
  }        /* set Priority for 16-31 Interrupts  */
}

#endif /* __SYSTEM_HS6600_H */
