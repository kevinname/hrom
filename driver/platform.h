
/****************************************************************************************************//**
 * @file     platform.h
 *
 * @brief    CMSIS Cortex-M3 Peripheral Access Layer Header File for
 *           HS6600 from <unknown Vendor>.
 *
 * @version  V1.0
 * @date     24. April 2015
 *
 * @note     Generated with SVDConv V2.75 
 *           from CMSIS SVD File 'HS66xx.svd' Version 1.0,
 *******************************************************************************************************/



/** @addtogroup (null)
  * @{
  */

/** @addtogroup platform
  * @{
  */

#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "N12_def.h"

#define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#define   __O     volatile             /*!< Defines 'write only' permissions                */
#define   __IO    volatile             /*!< Defines 'read / write' permissions              */

#define   __HS6601_FPGA       1

typedef enum {FALSE=0, TRUE=1}  bool_t;
typedef uint32_t        size_t;
/** @addtogroup Configuration_of_CMSIS
  * @{
  */
#include "system.h"     

/* ================================================================================ */
/* ================                     BT_JAL                     ================ */
/* ================================================================================ */


/**
  * @brief Bluetooth JAL controller (BT_JAL)
  */

typedef struct {                                    /*!< BT_JAL Structure                                                      */
  
  union {
    __IO uint32_t  JAL_COM_CTRL_BD_LO;              /*!< Bluetooth Device Address                                              */
    
    struct {
      __IO uint32_t  LAP        : 24;               /*!< (null)                                                                */
      __IO uint32_t  UAP        :  8;               /*!< (null)                                                                */
    } JAL_COM_CTRL_BD_LO_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_COM_CTRL_BD_HI;              /*!< Bluetooth Device Address                                              */
    
    struct {
      __IO uint32_t  NAP        : 16;               /*!< (null)                                                                */
    } JAL_COM_CTRL_BD_HI_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_COM_CTRL_SYNC_LO;            /*!< Device Sync Word                                                      */
    
    struct {
      __IO uint32_t  SYNC_LO    : 32;               /*!< (null)                                                                */
    } JAL_COM_CTRL_SYNC_LO_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_COM_CTRL_SYNC_HI;            /*!< Device Sync Word                                                      */
    
    struct {
      __IO uint32_t  SYNC_HI    : 32;               /*!< (null)                                                                */
    } JAL_COM_CTRL_SYNC_HI_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_COM_CTRL_INTRASLOT_OFFSET;   /*!< Intraslot Offset                                                      */
    
    struct {
      __IO uint32_t  INTRASLOT_OFFSET: 11;          /*!< (null)                                                                */
    } JAL_COM_CTRL_INTRASLOT_OFFSET_b;              /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0;
  
  union {
    __IO uint32_t  JAL_COM_CTRL_BT_CLK_READ_or_OFFSET_WR;/*!< Bluetooth Clock Offset or Bluetooth Clock                        */
    
    struct {
      __I  uint32_t  BT_CLK_or_BT_CLK_OFFSET: 28;   /*!< (null)                                                                */
    } JAL_COM_CTRL_BT_CLK_READ_or_OFFSET_WR_b;      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_COM_CTRL_NATIVE_CLK;         /*!< Native Bluetooth Clock                                                */
    
    struct {
      __IO uint32_t  NATIVE_BT_CLK: 28;             /*!< (null)                                                                */
    } JAL_COM_CTRL_NATIVE_CLK_b;                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_COM_CTRL_GP1;                /*!< common control reg1                                                   */
    
    struct {
      __IO uint32_t  AM_ADDR    :  3;               /*!< (null)                                                                */
      __IO uint32_t  ENCRYPT    :  2;               /*!< (null)                                                                */
      __IO uint32_t  USE_LF     :  1;               /*!< (null)                                                                */
      __IO uint32_t  SLAVE      :  1;               /*!< (null)                                                                */
      __IO uint32_t  PAGE       :  1;               /*!< (null)                                                                */
      __IO uint32_t  SCO_CFG0   :  4;               /*!< (null)                                                                */
      __IO uint32_t  SCO_CFG1   :  4;               /*!< (null)                                                                */
      __IO uint32_t  SCO_CFG2   :  4;               /*!< (null)                                                                */
      __IO uint32_t  SCO_FIFO   :  2;               /*!< (null)                                                                */
      __IO uint32_t  VCI_CLK_SEL:  2;               /*!< (null)                                                                */
      __IO uint32_t  CRC_INIT   :  8;               /*!< (null)                                                                */
    } JAL_COM_CTRL_GP1_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_COM_CTRL_GP2;                /*!< common control reg2                                                   */
    
    struct {
      __IO uint32_t  LOOP       :  1;               /*!< (null)                                                                */
      __IO uint32_t  TEST_ECO   :  1;               /*!< (null)                                                                */
      __IO uint32_t  ECO_ERR    :  4;               /*!< (null)                                                                */
      __IO uint32_t  TEST_CRC   :  1;               /*!< (null)                                                                */
      __IO uint32_t  TEST_HEC   :  1;               /*!< (null)                                                                */
      __IO uint32_t  TEST_RADIO :  1;               /*!< (null)                                                                */
      __IO uint32_t  VCI_CLK_SEL_MAP:  1;           /*!< (null)                                                                */
      __IO uint32_t  TEST_FORCE_NO_DDW:  1;         /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TEST_TX_SHIFT:  3;             /*!< (null)                                                                */
      __IO uint32_t  USE_HAB_CRL1:  1;              /*!< (null)                                                                */
      __IO uint32_t  DWH_INIT   :  6;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  DWH_BY_BT_CLK:  1;             /*!< (null)                                                                */
      __IO uint32_t  DWH2_INIT  :  6;               /*!< (null)                                                                */
      __IO uint32_t  DOUBLE_BUF :  1;               /*!< (null)                                                                */
      __IO uint32_t  WHITEN     :  1;               /*!< (null)                                                                */
    } JAL_COM_CTRL_GP2_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_COM_CTRL_IRQ;                /*!< common control irq int                                                */
    
    struct {
      __IO uint32_t  TIM_INTR_MASK:  4;             /*!< (null)                                                                */
      __IO uint32_t  PKD_INTR_MASK:  1;             /*!< (null)                                                                */
      __IO uint32_t  AUX_TMR_INTR_MASK:  1;         /*!< (null)                                                                */
      __IO uint32_t  PKA_INTR_MASK:  1;             /*!< (null)                                                                */
      __IO uint32_t  PKD_RX_HDR_INTR_MASK:  1;      /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  AES_INTR_MASK:  1;             /*!< (null)                                                                */
      __IO uint32_t  NO_PKT_RCVD_INTR_MASK:  1;     /*!< (null)                                                                */
      __IO uint32_t  SYNC_DET_INTR_MASK:  1;        /*!< (null)                                                                */
      __IO uint32_t  TX_RX_AUX1_PKT:  1;            /*!< (null)                                                                */
      __IO uint32_t  TIM_INTR_CLR_0:  1;            /*!< (null)                                                                */
      __IO uint32_t  TIM_INTR_CLR_1:  1;            /*!< (null)                                                                */
      __IO uint32_t  TIM_INTR_CLR_2:  1;            /*!< (null)                                                                */
      __IO uint32_t  TIM_INTR_CLR_3:  1;            /*!< (null)                                                                */
      __IO uint32_t  PKD_INTR_CLR:  1;              /*!< (null)                                                                */
      __IO uint32_t  AUX_TMR_INTR_CLR:  1;          /*!< (null)                                                                */
      __IO uint32_t  PKA_INTR_CLR:  1;              /*!< (null)                                                                */
      __IO uint32_t  PKD_RX_HDR_INTR_CLR:  1;       /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  SPI_NOW_CONFLICT_CLR:  1;      /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  SER0_WR_CLR:  1;               /*!< (null)                                                                */
      __IO uint32_t  AES_INTR_CLR:  1;              /*!< (null)                                                                */
      __IO uint32_t  NO_PKT_RCVD_INTR_CLR:  1;      /*!< (null)                                                                */
      __IO uint32_t  SYNC_DET_INTR_CLR:  1;         /*!< (null)                                                                */
      __IO uint32_t  VCI_SYNC_DIR:  1;              /*!< (null)                                                                */
    } JAL_COM_CTRL_IRQ_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_COM_STAT_IRQ;                /*!< common int status register                                            */
    
    struct {
      __IO uint32_t  TIM_INTR   :  4;               /*!< (null)                                                                */
      __IO uint32_t  PKD_INTR   :  1;               /*!< (null)                                                                */
      __IO uint32_t  AUX_TMR_INTR:  1;              /*!< (null)                                                                */
      __IO uint32_t  PKA_INTR   :  1;               /*!< (null)                                                                */
      __IO uint32_t  PKD_RX_HDR_INTR:  1;           /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  SPI_NOW_CONFLICT:  1;          /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  AES_INTR   :  1;               /*!< (null)                                                                */
      __IO uint32_t  NO_PKT_RCVD_INTR:  1;          /*!< (null)                                                                */
      __IO uint32_t  SYNC_DET_INTR:  1;             /*!< (null)                                                                */
      __IO uint32_t  SLEEP      :  1;               /*!< (null)                                                                */
    } JAL_COM_STAT_IRQ_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_TX_CTRL;                     /*!< Transmit Control                                                      */
    
    struct {
      __IO uint32_t  TX_LEN     :  9;               /*!< (null)                                                                */
      __IO uint32_t  TX_TYPE    :  4;               /*!< (null)                                                                */
      __IO uint32_t  TX_FLOW    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TX_ARQN    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TX_SEQN    :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TX_MODE    :  2;               /*!< (null)                                                                */
      __IO uint32_t  TX_L_CH    :  2;               /*!< (null)                                                                */
      __IO uint32_t  TX_P_FLOW  :  1;               /*!< (null)                                                                */
    } JAL_TX_CTRL_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_ESCO_CTRL;                   /*!< eSCO packet control                                                   */
    
    struct {
      __IO uint32_t  TX_LEN_ESCO:  8;               /*!< (null)                                                                */
      __IO uint32_t  RX_LEN_ESCO:  8;               /*!< (null)                                                                */
      __IO uint32_t  ESCO_LT_ADDR:  3;              /*!< (null)                                                                */
      __IO uint32_t  SCO_ROUTE  :  1;               /*!< (null)                                                                */
    } JAL_ESCO_CTRL_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_NATIVE_BIT_CNT;              /*!< native bit count                                                      */
    
    struct {
      __I  uint32_t  native_bitcnt: 11;             /*!< (null)                                                                */
    } JAL_NATIVE_BIT_CNT_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_CODEC_TYPE;                  /*!< codec type                                                            */
    
    struct {
      __IO uint32_t  CODEC_TYPE :  3;               /*!< (null)                                                                */
    } JAL_CODEC_TYPE_b;                             /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[2];
  
  union {
    __IO uint32_t  JAL_RX_CTRL;                     /*!< receive control                                                       */
    
    struct {
      __IO uint32_t  RX_MODE    :  2;               /*!< (null)                                                                */
      __IO uint32_t  SYNC_ERR   :  5;               /*!< (null)                                                                */
      __IO uint32_t  ABORT_ON_FEC_FAIL:  1;         /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  ERR_SEL    :  3;               /*!< (null)                                                                */
      __IO uint32_t  WIN_EXT    : 10;               /*!< (null)                                                                */
      __IO uint32_t  FREEZE_BIT_CNT:  1;            /*!< (null)                                                                */
      __IO uint32_t  ABORT_ON_WRONG_AM_ADDR:  1;    /*!< (null)                                                                */
    } JAL_RX_CTRL_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  JAL_RX_STATUS_GP1;               /*!< receive status reg1                                                   */
    
    struct {
      __I  uint32_t  RX_LEN     :  9;               /*!< (null)                                                                */
      __I  uint32_t  RX_TYPE    :  4;               /*!< (null)                                                                */
      __I  uint32_t  RX_FLOW    :  1;               /*!< (null)                                                                */
      __I  uint32_t  RX_ARQN    :  1;               /*!< (null)                                                                */
      __I  uint32_t  RX_SEQN    :  1;               /*!< (null)                                                                */
      __I  uint32_t  RX_AM_ADDR :  3;               /*!< (null)                                                                */
      __I  uint32_t  RX_L_CH    :  2;               /*!< (null)                                                                */
      __I  uint32_t  RX_P_FLOW  :  1;               /*!< (null)                                                                */
           uint32_t             :  2;
      __I  uint32_t  RX_PKT     :  1;               /*!< (null)                                                                */
      __I  uint32_t  HEC_ERR    :  1;               /*!< (null)                                                                */
      __I  uint32_t  CRC_ERR    :  1;               /*!< (null)                                                                */
      __I  uint32_t  RX_HDR     :  1;               /*!< (null)                                                                */
      __I  uint32_t  FEC_ABORT  :  1;               /*!< (null)                                                                */
      __I  uint32_t  AM_ADDR_ABORT:  1;             /*!< (null)                                                                */
    } JAL_RX_STATUS_GP1_b;                          /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3;
  
  union {
    __I  uint32_t  JAL_RX_STATUS_GP2;               /*!< receive status reg2                                                   */
    
    struct {
      __I  uint32_t  PKD_POS_ERR:  7;               /*!< (null)                                                                */
    } JAL_RX_STATUS_GP2_b;                          /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4;
  
  union {
    __IO uint32_t  JAL_SER_CFG_or_JTAG;             /*!< Serial Interface config                                               */
    
    struct {
      __IO uint32_t  Address_length:  5;            /*!< (null)                                                                */
      __IO uint32_t  Packet_length:  5;             /*!< (null)                                                                */
      __IO uint32_t  Clk_Pol    :  1;               /*!< (null)                                                                */
      __IO uint32_t  Data_Pol   :  1;               /*!< (null)                                                                */
      __IO uint32_t  Enable     :  4;               /*!< (null)                                                                */
      __IO uint32_t  Clock_Low  :  4;               /*!< (null)                                                                */
      __IO uint32_t  Clock_High :  3;               /*!< (null)                                                                */
      __IO uint32_t  Clk_Byp    :  1;               /*!< (null)                                                                */
      __IO uint32_t  SEL_Pol    :  1;               /*!< (null)                                                                */
      __IO uint32_t  lsb_first  :  1;               /*!< (null)                                                                */
      __IO uint32_t  low_enable :  1;               /*!< (null)                                                                */
      __IO uint32_t  Dbus_En    :  1;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  SER_MODE   :  1;               /*!< (null)                                                                */
      __I  uint32_t  SER_BUSY   :  1;               /*!< (null)                                                                */
    } JAL_SER_CFG_or_JTAG_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_ESER_CTRL;               /*!< enhanced SER control                                                  */
    
    struct {
      __IO uint32_t  SER_MASK   : 16;               /*!< (null)                                                                */
      __IO uint32_t  SER_COMBINE:  3;               /*!< (null)                                                                */
      __IO uint32_t  SER_ONE_SHOT:  1;              /*!< (null)                                                                */
      __IO uint32_t  SER_NOW    :  1;               /*!< (null)                                                                */
      __IO uint32_t  SER_SEQ    :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  SER_MAP_SEL:  1;               /*!< (null)                                                                */
    } JAL_SER_ESER_CTRL_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_ESER_TIME;               /*!< enhanced SER timing                                                   */
    
    struct {
           uint32_t             : 16;
      __IO uint32_t  SER_TIME_EARLY_EN:  4;         /*!< (null)                                                                */
      __IO uint32_t  SER_TIME_LATE_EN:  4;          /*!< (null)                                                                */
    } JAL_SER_ESER_TIME_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_READ_DATA;               /*!< Serial interface read data                                            */
    
    struct {
      __I  uint32_t  SER_READ_DATA: 32;             /*!< (null)                                                                */
    } JAL_SER_READ_DATA_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_ESER_TIME0;              /*!< enhanced SER timing 0                                                 */
    
    struct {
      __IO uint32_t  SER_TIME_0 :  4;               /*!< (null)                                                                */
    } JAL_SER_ESER_TIME0_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_ESER_TIME1;              /*!< enhanced SER timing 1                                                 */
    
    struct {
           uint32_t             :  4;
      __IO uint32_t  SER_TIME_1 :  4;               /*!< (null)                                                                */
    } JAL_SER_ESER_TIME1_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_ESER_TIME2;              /*!< enhanced SER timing 2                                                 */
    
    struct {
      __IO uint32_t  SER_TIME_2 :  4;               /*!< (null)                                                                */
    } JAL_SER_ESER_TIME2_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_ESER_TIME3;              /*!< enhanced SER timing 3                                                 */
    
    struct {
           uint32_t             :  4;
      __IO uint32_t  SER_TIME_3 :  4;               /*!< (null)                                                                */
    } JAL_SER_ESER_TIME3_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_STB_CFG;                     /*!< STB config or SCO codec                                               */
    
    struct {
      __IO uint32_t  STB_CFG    : 26;               /*!< (null)                                                                */
           uint32_t             :  5;
      __I  uint32_t  STB_BUSY   :  1;               /*!< (null)                                                                */
    } JAL_STB_CFG_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED5[3];
  
  union {
    __IO uint32_t  JAL_HIGH_SER;                    /*!< high SER reg                                                          */
    
    struct {
      __IO uint32_t  HIGH_SER0  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_SER0_EXT:  2;             /*!< (null)                                                                */
      __IO uint32_t  HIGH_SER0_OVERRIDE:  1;        /*!< (null)                                                                */
      __IO uint32_t  HIGH_SER1  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_SER1_EXT:  2;             /*!< (null)                                                                */
      __IO uint32_t  HIGH_SER1_OVERRIDE:  1;        /*!< (null)                                                                */
    } JAL_HIGH_SER_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LOW_SER;                     /*!< LOW SER reg                                                           */
    
    struct {
      __IO uint32_t  LOW_SER0   : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_SER0_EXT:  2;              /*!< (null)                                                                */
      __IO uint32_t  LOW_SER0_OVERRIDE:  1;         /*!< (null)                                                                */
      __IO uint32_t  LOW_SER1   : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_SER1_EXT:  2;              /*!< (null)                                                                */
      __IO uint32_t  LOW_SER1_OVERRIDE:  1;         /*!< (null)                                                                */
    } JAL_LOW_SER_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED6;
  
  union {
    __IO uint32_t  JAL_CODEC_VOL_CTL;               /*!< codec vol control                                                     */
    
    struct {
      __IO uint32_t  sco_vol_att:  3;               /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  PF3_BYPASS :  1;               /*!< (null)                                                                */
    } JAL_CODEC_VOL_CTL_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_AUX_TIMER;                   /*!< auxiliary timer                                                       */
    
    struct {
      __IO uint32_t  AUX_TIMER  : 14;               /*!< (null)                                                                */
    } JAL_AUX_TIMER_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_PIA_DATA;                    /*!< Parallel Interface Adaptor Data                                       */
    
    struct {
      __IO uint32_t  P_DATA_0   :  8;               /*!< (null)                                                                */
      __IO uint32_t  P_DATA_1   :  8;               /*!< (null)                                                                */
      __IO uint32_t  P_DATA_2   :  8;               /*!< (null)                                                                */
      __IO uint32_t  P_DATA_3   :  8;               /*!< (null)                                                                */
    } JAL_PIA_DATA_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_PIA_CTRL;                    /*!< Parallel Interface Adaptor Control                                    */
    
    struct {
      __IO uint32_t  P_SETUP    :  8;               /*!< (null)                                                                */
      __IO uint32_t  P_MASK     :  4;               /*!< (null)                                                                */
      __IO uint32_t  P_NOW      :  1;               /*!< (null)                                                                */
      __IO uint32_t  P_SEQ      :  1;               /*!< (null)                                                                */
      __IO uint32_t  P_DATA_DIR :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  P_RDATA    :  7;               /*!< (null)                                                                */
    } JAL_PIA_CTRL_b;                               /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED7;
  
  union {
    __IO uint32_t  JAL_PATH_DELAYS;                 /*!< Receive_Transmit Path Delay                                           */
    
    struct {
      __IO uint32_t  RX_DELAY   :  7;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TX_DELAY   :  4;               /*!< (null)                                                                */
    } JAL_PATH_DELAYS_b;                            /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED8;
  
  union {
    __IO uint32_t  JAL_ENC_KEY_LENGTH;              /*!< Encryption Key Length                                                 */
    
    struct {
      __IO uint32_t  ENC_KEY_LEN:  4;               /*!< (null)                                                                */
    } JAL_ENC_KEY_LENGTH_b;                         /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED9;
  
  union {
    __IO uint32_t  JAL_ENCRYPTION_KEY0;             /*!< Encryption Key 0                                                      */
    
    struct {
      __IO uint32_t  ENC_KEY0   : 32;               /*!< (null)                                                                */
    } JAL_ENCRYPTION_KEY0_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_ENCRYPTION_KEY1;             /*!< Encryption Key 1                                                      */
    
    struct {
      __IO uint32_t  ENC_KEY1   : 32;               /*!< (null)                                                                */
    } JAL_ENCRYPTION_KEY1_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_ENCRYPTION_KEY2;             /*!< Encryption Key 2                                                      */
    
    struct {
      __IO uint32_t  ENC_KEY2   : 32;               /*!< (null)                                                                */
    } JAL_ENCRYPTION_KEY2_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_ENCRYPTION_KEY3;             /*!< Encryption Key 3                                                      */
    
    struct {
      __IO uint32_t  ENC_KEY3   : 32;               /*!< (null)                                                                */
    } JAL_ENCRYPTION_KEY3_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_HSE_BT_CLK;                  /*!< Hop Selection Engine BT clock                                         */
    
    struct {
      __IO uint32_t  HSE_BT_CLK : 28;               /*!< (null)                                                                */
    } JAL_HSE_BT_CLK_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_HSE_UAP_LAP;                 /*!< Hop Selection Engine UAP LAP                                          */
    
    struct {
      __IO uint32_t  HSE_UAP_LAP: 28;               /*!< (null)                                                                */
    } JAL_HSE_UAP_LAP_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_HSE_SUM;                     /*!< HSE summation for the re-mapping function                             */
    
    struct {
      __I  uint32_t  HSE_SUM    : 26;               /*!< (null)                                                                */
    } JAL_HSE_SUM_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_HSE_RF_CHAN_INDEX;           /*!< HSE hop-79 connection state channel index                             */
    
    struct {
      __I  uint32_t  HSE_RF_CHAN_INDEX:  7;         /*!< (null)                                                                */
    } JAL_HSE_RF_CHAN_INDEX_b;                      /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED10[4];
  
  union {
    __IO uint32_t  JAL_BT_CLK_CTL;                  /*!< BT clock control                                                      */
    
    struct {
      __IO uint32_t  ADD_BT_CLK_RELATIVE:  1;       /*!< (null)                                                                */
      __IO uint32_t  WRITE_ABSOLUTE_BT_CLK:  1;     /*!< (null)                                                                */
      __IO uint32_t  DELAYED_BT_CLK_UPDATE:  1;     /*!< (null)                                                                */
      __IO uint32_t  FREEZE_BT_CLOCK:  1;           /*!< (null)                                                                */
      __IO uint32_t  SCO_REP_MODE:  1;              /*!< (null)                                                                */
    } JAL_BT_CLK_CTL_b;                             /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED11;
  
  union {
    __I  uint32_t  JAL_REV_CODE;                    /*!< LC Revision Code                                                      */
    
    struct {
      __I  uint32_t  MINOR_REV  :  8;               /*!< (null)                                                                */
      __I  uint32_t  MAJOR_REV  :  8;               /*!< (null)                                                                */
    } JAL_REV_CODE_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_RST_CTL;                     /*!< LC Reset Controls                                                     */
    
    struct {
           uint32_t             : 23;
      __IO uint32_t  RST_CODE   :  8;               /*!< (null)                                                                */
    } JAL_RST_CTL_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED12[4];
  
  union {
    __IO uint32_t  JAL_WR_RX_HPF_FILT;              /*!< CVSD Receive Initial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_RX_HPF_FILT: 16;            /*!< (null)                                                                */
    } JAL_WR_RX_HPF_FILT_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_RX_PF1_FILT_A;            /*!< CVSD Receive Initial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_RX_PF1_FILT_A: 32;          /*!< (null)                                                                */
    } JAL_WR_RX_PF1_FILT_A_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_RX_PF1_FILT_B;            /*!< CVSD Receive Initial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_RX_PF1_FILT_B: 32;          /*!< (null)                                                                */
    } JAL_WR_RX_PF1_FILT_B_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_RX_PF2_FILT;              /*!< CVSD Receive Initial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_RX_PF2_FILT: 32;            /*!< (null)                                                                */
    } JAL_WR_RX_PF2_FILT_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_RX_PF3_FILT;              /*!< CVSD Receive Initial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_RX_PF3_FILT: 32;            /*!< (null)                                                                */
    } JAL_WR_RX_PF3_FILT_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_RX_CVSD_FILT_A;           /*!< CVSD Receive Initial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_RX_CVSD_FILT_A: 26;         /*!< (null)                                                                */
    } JAL_WR_RX_CVSD_FILT_A_b;                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LD_WR_RX_CVSD_FILT_B;        /*!< CVSD Receive Initial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_RX_CVSD_FILT_B: 26;         /*!< (null)                                                                */
      __IO uint32_t  LD_RX      :  1;               /*!< (null)                                                                */
    } JAL_LD_WR_RX_CVSD_FILT_B_b;                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED13;
  
  union {
    __IO uint32_t  JAL_WR_TX_HPF_FILT;              /*!< CVSD TransmitInitial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_TX_HPF_FILT: 16;            /*!< (null)                                                                */
    } JAL_WR_TX_HPF_FILT_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_TX_PF1_FILT_A;            /*!< CVSD TransmitInitial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_TX_PF1_FILT_A: 32;          /*!< (null)                                                                */
    } JAL_WR_TX_PF1_FILT_A_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_TX_PF1_FILT_B;            /*!< CVSD TransmitInitial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_TX_PF1_FILT_B: 32;          /*!< (null)                                                                */
    } JAL_WR_TX_PF1_FILT_B_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_TX_PF2_FILT;              /*!< CVSD TransmitInitial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_TX_PF2_FILT: 32;            /*!< (null)                                                                */
    } JAL_WR_TX_PF2_FILT_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_TX_PF3_FILT;              /*!< CVSD TransmitInitial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_TX_PF3_FILT: 32;            /*!< (null)                                                                */
    } JAL_WR_TX_PF3_FILT_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_WR_TX_CVSD_FILT_A;           /*!< CVSD TransmitInitial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_TX_CVSD_FILT_A: 26;         /*!< (null)                                                                */
    } JAL_WR_TX_CVSD_FILT_A_b;                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LD_WR_TX_CVSD_FILT_B;        /*!< CVSD TransmitInitial Value Registers                                  */
    
    struct {
      __IO uint32_t  WR_TX_CVSD_FILT_B: 26;         /*!< (null)                                                                */
      __IO uint32_t  LD_TX      :  1;               /*!< (null)                                                                */
    } JAL_LD_WR_TX_CVSD_FILT_B_b;                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED14;
  
  union {
    __I  uint32_t  JAL_TX_HPF_FILT;                 /*!< CVSD Transmit Final Value Registers                                   */
    
    struct {
      __I  uint32_t  TX_HPF_FILT: 16;               /*!< (null)                                                                */
    } JAL_TX_HPF_FILT_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_TX_PF1_FILT_A;               /*!< CVSD Transmit Final Value Registers                                   */
    
    struct {
      __I  uint32_t  TX_PF1_FILT_A: 32;             /*!< (null)                                                                */
    } JAL_TX_PF1_FILT_A_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_TX_PF1_FILT_B;               /*!< CVSD Transmit Final Value Registers                                   */
    
    struct {
      __I  uint32_t  TX_PF1_FILT_B: 32;             /*!< (null)                                                                */
    } JAL_TX_PF1_FILT_B_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_TX_PF2_FILT;                 /*!< CVSD Transmit Final Value Registers                                   */
    
    struct {
      __I  uint32_t  TX_PF2_FILT: 32;               /*!< (null)                                                                */
    } JAL_TX_PF2_FILT_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_TX_PF3_FILT;                 /*!< CVSD Transmit Final Value Registers                                   */
    
    struct {
      __I  uint32_t  TX_PF3_FILT: 32;               /*!< (null)                                                                */
    } JAL_TX_PF3_FILT_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_TX_CVSD_FILT_A;              /*!< CVSD Transmit Final Value Registers                                   */
    
    struct {
      __I  uint32_t  TX_CVSD_FILT_A: 26;            /*!< (null)                                                                */
    } JAL_TX_CVSD_FILT_A_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_TX_CVSD_FILT_B;              /*!< CVSD Transmit Final Value Registers                                   */
    
    struct {
      __I  uint32_t  TX_CVSD_FILT_B: 26;            /*!< (null)                                                                */
    } JAL_TX_CVSD_FILT_B_b;                         /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED15;
  
  union {
    __I  uint32_t  JAL_RX_HPF_FILT;                 /*!< CVSD Receive Final Value registers                                    */
    
    struct {
      __I  uint32_t  RX_HPF_FILT: 16;               /*!< (null)                                                                */
    } JAL_RX_HPF_FILT_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_RX_PF1_FILT_A;               /*!< CVSD Receive Final Value registers                                    */
    
    struct {
      __I  uint32_t  RX_PF1_FILT_A: 32;             /*!< (null)                                                                */
    } JAL_RX_PF1_FILT_A_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_RX_PF1_FILT_B;               /*!< CVSD Receive Final Value registers                                    */
    
    struct {
      __I  uint32_t  RX_PF1_FILT_B: 32;             /*!< (null)                                                                */
    } JAL_RX_PF1_FILT_B_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_RX_PF2_FILT;                 /*!< CVSD Receive Final Value registers                                    */
    
    struct {
      __I  uint32_t  RX_PF2_FILT: 32;               /*!< (null)                                                                */
    } JAL_RX_PF2_FILT_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_RX_PF3_FILT;                 /*!< CVSD Receive Final Value registers                                    */
    
    struct {
      __I  uint32_t  RX_PF3_FILT: 32;               /*!< (null)                                                                */
    } JAL_RX_PF3_FILT_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_RX_CVSD_FILT_A;              /*!< CVSD Receive Final Value registers                                    */
    
    struct {
      __I  uint32_t  RX_CVSD_FILT_A: 32;            /*!< (null)                                                                */
    } JAL_RX_CVSD_FILT_A_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  JAL_RX_CVSD_FILT_B;              /*!< CVSD Receive Final Value registers                                    */
    
    struct {
      __I  uint32_t  RX_CVSD_FILT_B: 32;            /*!< (null)                                                                */
    } JAL_RX_CVSD_FILT_B_b;                         /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED16[5];
  
  union {
    __IO uint32_t  JAL_SCO_TX_FIFO_CTL_STATUS;      /*!< SCO transmit fifo control status                                      */
    
    struct {
      __IO uint32_t  SCO_CHAN_FIFO_MODE0:  1;       /*!< (null)                                                                */
      __IO uint32_t  SCO_CHAN_16_8BIT0:  1;         /*!< (null)                                                                */
      __IO uint32_t  SCO_CHAN_FIFO_RST0:  1;        /*!< (null)                                                                */
      __I  uint32_t  SCO_RX_FIFO_LOW0:  1;          /*!< (null)                                                                */
      __I  uint32_t  SCO_TX_FIFO_HIGH0:  1;         /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  SCO_RX_FIFO_THRESHOLD0:  6;    /*!< (null)                                                                */
      __IO uint32_t  SCO_TX_FIFO_THRESHOLD0:  6;    /*!< (null)                                                                */
      __I  uint32_t  SCO_RX_FIFO_FILL_LEVEL0:  6;   /*!< (null)                                                                */
      __I  uint32_t  SCO_TX_FIFO_FILL_LEVEL0:  6;   /*!< (null)                                                                */
    } JAL_SCO_TX_FIFO_CTL_STATUS_b;                 /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED17[279];
  
  union {
    __IO uint32_t  JAL_SER_DATA0;                   /*!< SER Data 0                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA0: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA0_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA1;                   /*!< SER Data 1                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA1: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA1_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA2;                   /*!< SER Data 2                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA2: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA2_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA3;                   /*!< SER Data 3                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA3: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA3_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA4;                   /*!< SER Data 4                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA4: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA4_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA5;                   /*!< SER Data 5                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA5: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA5_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA6;                   /*!< SER Data 6                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA6: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA6_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA7;                   /*!< SER Data 7                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA7: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA7_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA8;                   /*!< SER Data 8                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA8: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA8_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA9;                   /*!< SER Data 9                                                            */
    
    struct {
      __IO uint32_t  JAL_SER_DATA9: 32;             /*!< (null)                                                                */
    } JAL_SER_DATA9_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA10;                  /*!< SER Data 10                                                           */
    
    struct {
      __IO uint32_t  JAL_SER_DATA10: 32;            /*!< (null)                                                                */
    } JAL_SER_DATA10_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA11;                  /*!< SER Data 11                                                           */
    
    struct {
      __IO uint32_t  JAL_SER_DATA11: 32;            /*!< (null)                                                                */
    } JAL_SER_DATA11_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA12;                  /*!< SER Data 12                                                           */
    
    struct {
      __IO uint32_t  JAL_SER_DATA12: 32;            /*!< (null)                                                                */
    } JAL_SER_DATA12_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA13;                  /*!< SER Data 13                                                           */
    
    struct {
      __IO uint32_t  JAL_SER_DATA13: 32;            /*!< (null)                                                                */
    } JAL_SER_DATA13_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA14;                  /*!< SER Data 14                                                           */
    
    struct {
      __IO uint32_t  JAL_SER_DATA14: 32;            /*!< (null)                                                                */
    } JAL_SER_DATA14_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_SER_DATA15;                  /*!< SER Data 15                                                           */
    
    struct {
      __IO uint32_t  JAL_SER_DATA15: 32;            /*!< (null)                                                                */
    } JAL_SER_DATA15_b;                             /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED18[48];
  
  union {
    __IO uint32_t  JAL_EDR_CTRL;                    /*!< EDR control                                                           */
    
    struct {
      __IO uint32_t  ENABLE_EDR :  1;               /*!< (null)                                                                */
      __IO uint32_t  PTT_ACL    :  1;               /*!< (null)                                                                */
      __IO uint32_t  PTT_ESCO   :  1;               /*!< (null)                                                                */
      __IO uint32_t  EDR_SYNC_ERROR:  5;            /*!< (null)                                                                */
      __IO uint32_t  RX_EDR_DELAY:  4;              /*!< (null)                                                                */
      __IO uint32_t  TX_EDR_DELAY:  4;              /*!< (null)                                                                */
    } JAL_EDR_CTRL_b;                               /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED19[3];
  
  union {
    __IO uint32_t  JAL_TX_CTRL_EDR;                 /*!< Transmit Control                                                      */
    
    struct {
      __IO uint32_t  TX_LEN     : 10;               /*!< (null)                                                                */
      __IO uint32_t  TX_TYPE    :  4;               /*!< (null)                                                                */
      __IO uint32_t  TX_FLOW    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TX_ARQN    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TX_SEQN    :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TX_MODE    :  2;               /*!< (null)                                                                */
      __IO uint32_t  TX_L_CH    :  2;               /*!< (null)                                                                */
      __IO uint32_t  TX_P_FLOW  :  1;               /*!< (null)                                                                */
    } JAL_TX_CTRL_EDR_b;                            /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED20[3];
  
  union {
    __IO uint32_t  JAL_ESCO_CTRL_EDR;               /*!< ESCO control                                                          */
    
    struct {
      __IO uint32_t  TX_LEN_ESCO: 10;               /*!< (null)                                                                */
      __IO uint32_t  ESCO_LT_ADDR:  3;              /*!< (null)                                                                */
      __IO uint32_t  SCO_ROUTE  :  1;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  RX_LEN_ESCO: 10;               /*!< (null)                                                                */
    } JAL_ESCO_CTRL_EDR_b;                          /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED21[3];
  
  union {
    __IO uint32_t  JAL_RX_STATUS_GP_EDR;            /*!< receive status                                                        */
    
    struct {
      __I  uint32_t  RX_LEN     : 10;               /*!< (null)                                                                */
      __I  uint32_t  RX_TYPE    :  4;               /*!< (null)                                                                */
      __I  uint32_t  RX_FLOW    :  1;               /*!< (null)                                                                */
      __I  uint32_t  RX_ARQN    :  1;               /*!< (null)                                                                */
      __I  uint32_t  RX_SEQN    :  1;               /*!< (null)                                                                */
      __I  uint32_t  RX_AM_ADDR :  3;               /*!< (null)                                                                */
      __I  uint32_t  RX_L_CH    :  2;               /*!< (null)                                                                */
      __I  uint32_t  RX_P_FLOW  :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  RX_PKT     :  1;               /*!< (null)                                                                */
      __I  uint32_t  HEC_ERR    :  1;               /*!< (null)                                                                */
      __I  uint32_t  CRC_ERR    :  1;               /*!< (null)                                                                */
      __I  uint32_t  RX_HDR     :  1;               /*!< (null)                                                                */
      __I  uint32_t  FEC_ABORT  :  1;               /*!< (null)                                                                */
      __I  uint32_t  AM_ADDR_ABORT:  1;             /*!< (null)                                                                */
      __I  uint32_t  NO_EDR_SYNC:  1;               /*!< (null)                                                                */
    } JAL_RX_STATUS_GP_EDR_b;                       /*!< BitSize                                                               */
  };
} BT_JAL_Type;


/* ================================================================================ */
/* ================                     BT_HAB                     ================ */
/* ================================================================================ */


/**
  * @brief Bluetooth HAB controller (BT_HAB)
  */

typedef struct {                                    /*!< BT_HAB Structure                                                      */
  __I  uint32_t  RESERVED0[2];
  
  union {
    __IO uint32_t  HAB_RX_CTRL_GP1;                 /*!< receive control reg                                                   */
    
    struct {
      __IO uint32_t  SYNC_ERROR :  6;               /*!< (null)                                                                */
      __IO uint32_t  RXMODE     :  1;               /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  FDB_DIS    :  1;               /*!< (null)                                                                */
           uint32_t             :  8;
      __IO uint32_t  SYM_MASK   :  1;               /*!< (null)                                                                */
           uint32_t             :  7;
      __IO uint32_t  SYM_GN     :  1;               /*!< (null)                                                                */
      __IO uint32_t  SYM_ENB    :  1;               /*!< (null)                                                                */
      __IO uint32_t  OCL_FB_MODE:  1;               /*!< (null)                                                                */
    } HAB_RX_CTRL_GP1_b;                            /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[5];
  
  union {
    __IO uint32_t  HAB_INTR_CTRL_GP1;               /*!< Radio Interrupt control                                               */
    
    struct {
      __IO uint32_t  RIF_INTR_MASK0:  2;            /*!< (null)                                                                */
      __IO uint32_t  RIF_INTR_MASK1:  2;            /*!< (null)                                                                */
      __IO uint32_t  RIF_INTR_MASK2:  2;            /*!< (null)                                                                */
      __IO uint32_t  RIF_INTR_MASK3:  2;            /*!< (null)                                                                */
      __IO uint32_t  LTR_INTR_MASK:  1;             /*!< (null)                                                                */
    } HAB_INTR_CTRL_GP1_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  HAB_INTR_CLR;                    /*!< Radio Interrupt clear                                                 */
    
    struct {
      __I  uint32_t  RIF_INTR_CLR:  4;              /*!< (null)                                                                */
      __I  uint32_t  LTR_INTR_CLR:  1;              /*!< (null)                                                                */
    } HAB_INTR_CLR_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_PHY_CONFIG;                  /*!< PHY Configuration                                                     */
    
    struct {
      __IO uint32_t  REFCLK_DIV :  5;               /*!< (null)                                                                */
      __IO uint32_t  REFCLK_DIR :  1;               /*!< (null)                                                                */
      __IO uint32_t  PHYCLK_GATE:  1;               /*!< (null)                                                                */
      __IO uint32_t  LPOCLK_DIV :  1;               /*!< (null)                                                                */
      __IO uint32_t  OPEN_DRAIN :  1;               /*!< (null)                                                                */
      __IO uint32_t  RST_DIR    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TXDATA_DIR :  1;               /*!< (null)                                                                */
      __IO uint32_t  TXDATA_FRC :  2;               /*!< (null)                                                                */
      __IO uint32_t  RXBDW_DIR  :  2;               /*!< (null)                                                                */
      __IO uint32_t  REFCLK_INV :  1;               /*!< (null)                                                                */
      __IO uint32_t  SYNC_INV   :  1;               /*!< (null)                                                                */
      __IO uint32_t  SYNC_RX    :  1;               /*!< (null)                                                                */
      __IO uint32_t  SYNC_TX    :  2;               /*!< (null)                                                                */
      __IO uint32_t  TX_INV     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TXDIR_INV  :  1;               /*!< (null)                                                                */
      __IO uint32_t  TX_FMT     :  1;               /*!< (null)                                                                */
      __IO uint32_t  RX_FMT     :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  DAT_BYP    :  1;               /*!< (null)                                                                */
      __IO uint32_t  OCL_BYP    :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  GAU_BYP    :  1;               /*!< (null)                                                                */
      __IO uint32_t  LTR_BYP    :  1;               /*!< (null)                                                                */
      __IO uint32_t  RX_INV     :  1;               /*!< (null)                                                                */
      __IO uint32_t  Ceva_Reserved:  1;             /*!< (null)                                                                */
    } HAB_PHY_CONFIG_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  HAB_STAT_GP1;                    /*!< status reg                                                            */
    
    struct {
           uint32_t             :  5;
      __I  uint32_t  LTR_LONG_PERIOD:  1;           /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  LTR_INTR   :  1;               /*!< (null)                                                                */
      __I  uint32_t  RIF_INTR   :  4;               /*!< (null)                                                                */
      __I  uint32_t  GIO_STATUS :  4;               /*!< (null)                                                                */
      __I  uint32_t  Ceva_Reserved: 16;             /*!< (null)                                                                */
    } HAB_STAT_GP1_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_HIGH_CTRL_1_AND_0;       /*!< GIO Control_Ext_Override High Position 0 and 1                        */
    
    struct {
      __IO uint32_t  HIGH_0_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_0_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_0_OVERRIDE:  1;           /*!< (null)                                                                */
      __IO uint32_t  HIGH_1_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_1_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_1_OVERRIDE:  1;           /*!< (null)                                                                */
    } HAB_GIO_HIGH_CTRL_1_AND_0_b;                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_HIGH_CTRL_3_AND_2;       /*!< GIO Control_Ext_Override High Position 2 and 3                        */
    
    struct {
      __IO uint32_t  HIGH_2_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_2_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_2_OVERRIDE:  1;           /*!< (null)                                                                */
      __IO uint32_t  HIGH_3_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_3_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_3_OVERRIDE:  1;           /*!< (null)                                                                */
    } HAB_GIO_HIGH_CTRL_3_AND_2_b;                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_HIGH_CTRL_5_AND_4;       /*!< GIO Control_Ext_Override High Position 4 and 5                        */
    
    struct {
      __IO uint32_t  HIGH_4_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_4_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_4_OVERRIDE:  1;           /*!< (null)                                                                */
      __IO uint32_t  HIGH_5_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_5_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_5_OVERRIDE:  1;           /*!< (null)                                                                */
    } HAB_GIO_HIGH_CTRL_5_AND_4_b;                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_HIGH_CTRL_7_AND_6;       /*!< GIO Control_Ext_Override High Position 6 and 7                        */
    
    struct {
      __IO uint32_t  HIGH_6_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_6_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_6_OVERRIDE:  1;           /*!< (null)                                                                */
      __IO uint32_t  HIGH_7_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_7_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_7_OVERRIDE:  1;           /*!< (null)                                                                */
    } HAB_GIO_HIGH_CTRL_7_AND_6_b;                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_HIGH_CTRL_9_AND_8;       /*!< GIO Control_Ext_Override High Position 8 and 9                        */
    
    struct {
      __IO uint32_t  HIGH_8_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_8_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_8_OVERRIDE:  1;           /*!< (null)                                                                */
      __IO uint32_t  HIGH_9_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_9_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_9_OVERRIDE:  1;           /*!< (null)                                                                */
    } HAB_GIO_HIGH_CTRL_9_AND_8_b;                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_HIGH_CTRL_B_AND_A;       /*!< GIO Control_Ext_Override High Position A and B                        */
    
    struct {
      __IO uint32_t  HIGH_10_VAL: 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_10_EXT:  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_10_OVERRIDE:  1;          /*!< (null)                                                                */
      __IO uint32_t  HIGH_11_VAL: 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  HIGH_11_EXT:  2;               /*!< (null)                                                                */
      __IO uint32_t  HIGH_11_OVERRIDE:  1;          /*!< (null)                                                                */
    } HAB_GIO_HIGH_CTRL_B_AND_A_b;                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_LOW_CTRL_1_AND_0;        /*!< GIO Control_Ext_Override Low Position 0 and 1                         */
    
    struct {
      __IO uint32_t  LOW_0_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_0_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_0_OVERRIDE:  1;            /*!< (null)                                                                */
      __IO uint32_t  LOW_1_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_1_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_1_OVERRIDE:  1;            /*!< (null)                                                                */
    } HAB_GIO_LOW_CTRL_1_AND_0_b;                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_LOW_CTRL_3_AND_2;        /*!< GIO Control_Ext_Override Low Position 2 and 3                         */
    
    struct {
      __IO uint32_t  LOW_2_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_2_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_2_OVERRIDE:  1;            /*!< (null)                                                                */
      __IO uint32_t  LOW_3_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_3_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_3_OVERRIDE:  1;            /*!< (null)                                                                */
    } HAB_GIO_LOW_CTRL_3_AND_2_b;                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_LOW_CTRL_5_AND_4;        /*!< GIO Control_Ext_Override Low Position 4 and 5                         */
    
    struct {
      __IO uint32_t  LOW_4_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_4_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_4_OVERRIDE:  1;            /*!< (null)                                                                */
      __IO uint32_t  LOW_5_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_5_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_5_OVERRIDE:  1;            /*!< (null)                                                                */
    } HAB_GIO_LOW_CTRL_5_AND_4_b;                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_LOW_CTRL_7_AND_6;        /*!< GIO Control_Ext_Override Low Position 6 and 7                         */
    
    struct {
      __IO uint32_t  LOW_6_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_6_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_6_OVERRIDE:  1;            /*!< (null)                                                                */
      __IO uint32_t  LOW_7_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_7_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_7_OVERRIDE:  1;            /*!< (null)                                                                */
    } HAB_GIO_LOW_CTRL_7_AND_6_b;                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_LOW_CTRL_9_AND_8;        /*!< GIO Control_Ext_Override Low Position 8 and 9                         */
    
    struct {
      __IO uint32_t  LOW_8_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_8_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_8_OVERRIDE:  1;            /*!< (null)                                                                */
      __IO uint32_t  LOW_9_VAL  : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_9_EXT  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_9_OVERRIDE:  1;            /*!< (null)                                                                */
    } HAB_GIO_LOW_CTRL_9_AND_8_b;                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_LOW_CTRL_B_AND_A;        /*!< GIO Control_Ext_Override Low Position A and B                         */
    
    struct {
      __IO uint32_t  LOW_10_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_10_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_10_OVERRIDE:  1;           /*!< (null)                                                                */
      __IO uint32_t  LOW_11_VAL : 11;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  LOW_11_EXT :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOW_11_OVERRIDE:  1;           /*!< (null)                                                                */
    } HAB_GIO_LOW_CTRL_B_AND_A_b;                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_CTRL_COMB_3_2_1_0;       /*!< GIO Auto-Extension Control 0_1_2_3                                    */
    
    struct {
      __IO uint32_t  GIO_COMBINE_0:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_0 :  1;               /*!< (null)                                                                */
      __IO uint32_t  GIO_COMBINE_1:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_1 :  1;               /*!< (null)                                                                */
      __IO uint32_t  GIO_COMBINE_2:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_2 :  1;               /*!< (null)                                                                */
      __IO uint32_t  GIO_COMBINE_3:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_3 :  1;               /*!< (null)                                                                */
    } HAB_GIO_CTRL_COMB_3_2_1_0_b;                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_CTRL_COMB_7_6_5_4;       /*!< GIO Auto-Extension Control 4_5_6_7                                    */
    
    struct {
      __IO uint32_t  GIO_COMBINE_4:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_4 :  1;               /*!< (null)                                                                */
      __IO uint32_t  GIO_COMBINE_5:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_5 :  1;               /*!< (null)                                                                */
      __IO uint32_t  GIO_COMBINE_6:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_6 :  1;               /*!< (null)                                                                */
      __IO uint32_t  GIO_COMBINE_7:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_7 :  1;               /*!< (null)                                                                */
    } HAB_GIO_CTRL_COMB_7_6_5_4_b;                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_CTRL_COMB_B_A_9_8;       /*!< GIO Auto-Extension Control 8_9_A_B                                    */
    
    struct {
      __IO uint32_t  GIO_COMBINE_8:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_8 :  1;               /*!< (null)                                                                */
      __IO uint32_t  GIO_COMBINE_9:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_9 :  1;               /*!< (null)                                                                */
      __IO uint32_t  GIO_COMBINE_A:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_10:  1;               /*!< (null)                                                                */
      __IO uint32_t  GIO_COMBINE_B:  6;             /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  AUTO_EXT_11:  1;               /*!< (null)                                                                */
    } HAB_GIO_CTRL_COMB_B_A_9_8_b;                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  HAB_RF_SUPPORT;                  /*!< RF Support Register                                                   */
    
    struct {
      __IO uint32_t  RF_SUPPORT :  3;               /*!< (null)                                                                */
    } HAB_RF_SUPPORT_b;                             /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3[3];
  
  union {
    __IO uint32_t  HAB_GIO_WIN_EXT_H;               /*!< GIO Window Extension Control HIGH                                     */
    
    struct {
      __IO uint32_t  HIGH_EARLY_EN: 12;             /*!< (null)                                                                */
      __IO uint32_t  HIGH_LATE_EN: 12;              /*!< (null)                                                                */
    } HAB_GIO_WIN_EXT_H_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HAB_GIO_WIN_EXT_L;               /*!< GIO Window Extension Control LOW                                      */
    
    struct {
      __IO uint32_t  LOW_EARLY_EN: 12;              /*!< (null)                                                                */
      __IO uint32_t  LOW_LATE_EN: 12;               /*!< (null)                                                                */
    } HAB_GIO_WIN_EXT_L_b;                          /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4[6];
  
  union {
    __IO uint32_t  HAB_RF_MUX_CLK_DIV;              /*!< RF MUX clock reg                                                      */
    
    struct {
      __IO uint32_t  SYNC_RXBDW_TRCLK:  1;          /*!< (null)                                                                */
      __IO uint32_t  SYNC_RXBDW_TRCLK_EDGE:  1;     /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  RFMUX      :  3;               /*!< (null)                                                                */
      __IO uint32_t  Ceva_Reserved1:  2;            /*!< (null)                                                                */
      __IO uint32_t  AUTO_WAKEUP:  3;               /*!< (null)                                                                */
      __IO uint32_t  Ceva_Reserved2:  8;            /*!< (null)                                                                */
    } HAB_RF_MUX_CLK_DIV_b;                         /*!< BitSize                                                               */
  };
} BT_HAB_Type;


/* ================================================================================ */
/* ================                      BT_LE                     ================ */
/* ================================================================================ */


/**
  * @brief Bluetooth LE controller (BT_LE)
  */

typedef struct {                                    /*!< BT_LE Structure                                                       */
  
  union {
    __IO uint32_t  JAL_LE_COM_CTRL_GP1;             /*!< common control reg                                                    */
    
    struct {
      __IO uint32_t  LE_MODE    :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  MASTER_MODE:  1;               /*!< (null)                                                                */
      __IO uint32_t  ADV_STATE  :  1;               /*!< (null)                                                                */
      __IO uint32_t  TX_EN      :  1;               /*!< (null)                                                                */
      __IO uint32_t  AES_MODE   :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  AES_ENABLE :  1;               /*!< (null)                                                                */
      __IO uint32_t  T_IFS_DEFAULT:  1;             /*!< (null)                                                                */
      __IO uint32_t  T_IFS_ABORT:  1;               /*!< (null)                                                                */
      __IO uint32_t  T_IFS_DELAY:  6;               /*!< (null)                                                                */
      __IO uint32_t  WHITEN_INIT:  6;               /*!< (null)                                                                */
      __IO uint32_t  WHITEN_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  TEST_CRC   :  1;               /*!< (null)                                                                */
      __IO uint32_t  DELAY_SRCH_WIN:  6;            /*!< (null)                                                                */
      __IO uint32_t  AES_START  :  1;               /*!< (null)                                                                */
      __IO uint32_t  AES_DATA_READY:  1;            /*!< (null)                                                                */
    } JAL_LE_COM_CTRL_GP1_b;                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0[4];
  
  union {
    __IO uint32_t  JAL_LE_ACC_ADDR;                 /*!< Access Address                                                        */
    
    struct {
      __IO uint32_t  ACC_ADDR   : 32;               /*!< (null)                                                                */
    } JAL_LE_ACC_ADDR_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_PREAMBLE_CRC_ERR;         /*!< Preamble and CRC error                                                */
    
    struct {
      __I  uint32_t  PREAMBLE   :  8;               /*!< (null)                                                                */
      __IO uint32_t  CRC_ERROR  :  1;               /*!< (null)                                                                */
    } JAL_LE_PREAMBLE_CRC_ERR_b;                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_CRC_INIT;                 /*!< CRC initial value                                                     */
    
    struct {
      __IO uint32_t  CRC_INIT   : 24;               /*!< (null)                                                                */
    } JAL_LE_CRC_INIT_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_KEY0;                 /*!< AES KEY Word 0 in Big Endian                                          */
    
    struct {
      __IO uint32_t  AES_KEY0   : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_KEY0_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_KEY1;                 /*!< AES KEY Word 1 in Big Endian                                          */
    
    struct {
      __IO uint32_t  AES_KEY1   : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_KEY1_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_KEY2;                 /*!< AES KEY Word 2 in Big Endian                                          */
    
    struct {
      __IO uint32_t  AES_KEY2   : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_KEY2_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_KEY3;                 /*!< AES KEY Word 3 in Big Endian                                          */
    
    struct {
      __IO uint32_t  AES_KEY    : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_KEY3_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_IV_L;                 /*!< AES Initialisation Vector Low word in Big Endian                      */
    
    struct {
      __IO uint32_t  AES_IV_L   : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_IV_L_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_IV_H;                 /*!< AES Initialisation Vector High half word in Big Endian                */
    
    struct {
      __IO uint32_t  AES_IV_H   : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_IV_H_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_PKTCNT_L;             /*!< AES Packet counter Low word                                           */
    
    struct {
      __IO uint32_t  AES_PKT_CNT_L: 32;             /*!< (null)                                                                */
    } JAL_LE_AES_PKTCNT_L_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_PKT_CNTH_LLID_LEN;    /*!< AES Packet counter High Byte and LLID and LEN                         */
    
    struct {
      __IO uint32_t  AES_PKT_CNT_H:  8;             /*!< (null)                                                                */
      __IO uint32_t  AES_PKT_LENGTH:  5;            /*!< (null)                                                                */
      __IO uint32_t  AES_PKT_LLID:  2;              /*!< (null)                                                                */
    } JAL_LE_AES_PKT_CNTH_LLID_LEN_b;               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_TX_HEADER_PDU;            /*!< Transmitter Advertising or Data Channel Header                        */
    
    struct {
      __IO uint32_t  PDU_TYPE   :  4;               /*!< (null)                                                                */
      __IO uint32_t  RFU_ADV_1_0:  2;               /*!< (null)                                                                */
      __IO uint32_t  TX_ADD     :  1;               /*!< (null)                                                                */
      __IO uint32_t  RX_ADD     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TX_LENGTH_ADV:  6;             /*!< (null)                                                                */
      __IO uint32_t  RFU_ADV_3_2:  2;               /*!< (null)                                                                */
      __IO uint32_t  LLID       :  2;               /*!< (null)                                                                */
      __IO uint32_t  NESN       :  1;               /*!< (null)                                                                */
      __IO uint32_t  SN         :  1;               /*!< (null)                                                                */
      __IO uint32_t  MD         :  1;               /*!< (null)                                                                */
      __IO uint32_t  RFU_DATA_2_0:  3;              /*!< (null)                                                                */
      __IO uint32_t  TX_LENGTH_DATA:  5;            /*!< (null)                                                                */
      __IO uint32_t  RFU_DATA_5_3:  3;              /*!< (null)                                                                */
    } JAL_LE_TX_HEADER_PDU_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_RX_HEADER_APDU_or_DPDU;   /*!< Advertising or Data Channel Header received                           */
    
    struct {
      __IO uint32_t  LLID       :  2;               /*!< (null)                                                                */
      __IO uint32_t  NESN       :  1;               /*!< (null)                                                                */
      __IO uint32_t  SN         :  1;               /*!< (null)                                                                */
      __IO uint32_t  MD         :  1;               /*!< (null)                                                                */
      __IO uint32_t  RFU_DATA_2_0:  3;              /*!< (null)                                                                */
      __IO uint32_t  TX_LENGTH_DATA:  5;            /*!< (null)                                                                */
      __IO uint32_t  RFU_DATA_5_3:  3;              /*!< (null)                                                                */
    } JAL_LE_RX_HEADER_APDU_or_DPDU_b;              /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[3];
  
  union {
    __IO uint32_t  JAL_LE_STATUS;                   /*!< AES Status                                                            */
    
    struct {
      __I  uint32_t  MIC_STATUS :  1;               /*!< (null)                                                                */
      __IO uint32_t  AES_ACTIVE :  1;               /*!< (null)                                                                */
      __IO uint32_t  AES_FINISHED:  1;              /*!< (null)                                                                */
           uint32_t             :  3;
      __I  uint32_t  TIFS_ABORTED:  1;              /*!< (null)                                                                */
      __I  uint32_t  CRC_ERROR  :  1;               /*!< (null)                                                                */
      __I  uint32_t  LE_RX_FILTERED:  3;            /*!< (null)                                                                */
      __I  uint32_t  TARGET_ADDR_MATCH:  1;         /*!< (null)                                                                */
    } JAL_LE_STATUS_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_ADV_CTRL;                 /*!< Advanced LE Control                                                   */
    
    struct {
      __IO uint32_t  SPI_TIMED_EN:  1;              /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  MASTER_MODE:  1;               /*!< (null)                                                                */
      __IO uint32_t  ADV_STATE  :  1;               /*!< (null)                                                                */
      __IO uint32_t  TX_EN      :  1;               /*!< (null)                                                                */
      __IO uint32_t  LE_FILTER_MODE:  3;            /*!< (null)                                                                */
      __IO uint32_t  T_IFS_DEFAULT:  1;             /*!< (null)                                                                */
      __IO uint32_t  T_IFS_ABORT:  1;               /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  USE_ADDR_FLTRS:  1;            /*!< (null)                                                                */
      __IO uint32_t  USE_ADDR_FLTRS_CON_REQ:  1;    /*!< (null)                                                                */
      __IO uint32_t  USE_ADDR_FLTRS_SCAN_REQ:  1;   /*!< (null)                                                                */
      __IO uint32_t  FLTR_0_LOADED:  1;             /*!< (null)                                                                */
      __IO uint32_t  FLTR_1_LOADED:  1;             /*!< (null)                                                                */
      __IO uint32_t  FLTR_2_LOADED:  1;             /*!< (null)                                                                */
      __IO uint32_t  FLTR_3_LOADED:  1;             /*!< (null)                                                                */
      __IO uint32_t  FLTR_4_LOADED:  1;             /*!< (null)                                                                */
      __IO uint32_t  FLTR_5_LOADED:  1;             /*!< (null)                                                                */
      __IO uint32_t  FLTR_IMD_LOADED:  1;           /*!< (null)                                                                */
    } JAL_LE_ADV_CTRL_b;                            /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  JAL_LE_FLTR_ADDR_0_L;            /*!< LE Address Filter 0 Low word                                          */
    
    struct {
      __IO uint32_t  FLTR_ADDR_0_L: 32;             /*!< (null)                                                                */
    } JAL_LE_FLTR_ADDR_0_L_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_CTRL_ST_ADDR_0_H;    /*!< LE Address Filter 0 High and control and matched                      */
    
    struct {
      __IO uint32_t  FLTR_ADDR_0_H: 16;             /*!< (null)                                                                */
           uint32_t             : 13;
      __I  uint32_t  FLTR_MATCHED_0:  1;            /*!< (null)                                                                */
      __IO uint32_t  FLTR_ADDR_TYPE_0:  1;          /*!< (null)                                                                */
      __IO uint32_t  FLTR_0_LOADED:  1;             /*!< (null)                                                                */
    } JAL_LE_FLTR_CTRL_ST_ADDR_0_H_b;               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_ADDR_1_L;            /*!< LE Address Filter 1 Low word                                          */
    
    struct {
      __IO uint32_t  FLTR_ADDR_1_L: 32;             /*!< (null)                                                                */
    } JAL_LE_FLTR_ADDR_1_L_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_CTRL_ST_ADDR_1_H;    /*!< LE Address Filter 1 High and control and matched                      */
    
    struct {
      __IO uint32_t  FLTR_ADDR_1_H: 16;             /*!< (null)                                                                */
           uint32_t             : 13;
      __I  uint32_t  FLTR_MATCHED_1:  1;            /*!< (null)                                                                */
      __IO uint32_t  FLTR_ADDR_TYPE_1:  1;          /*!< (null)                                                                */
      __IO uint32_t  FLTR_1_LOADED:  1;             /*!< (null)                                                                */
    } JAL_LE_FLTR_CTRL_ST_ADDR_1_H_b;               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_ADDR_2_L;            /*!< LE Address Filter 2 Low word                                          */
    
    struct {
      __IO uint32_t  FLTR_ADDR_2_L: 32;             /*!< (null)                                                                */
    } JAL_LE_FLTR_ADDR_2_L_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_CTRL_ST_ADDR_2_H;    /*!< LE Address Filter 2 High and control and matched                      */
    
    struct {
      __IO uint32_t  FLTR_ADDR_2_H: 16;             /*!< (null)                                                                */
           uint32_t             : 13;
      __I  uint32_t  FLTR_MATCHED_2:  1;            /*!< (null)                                                                */
      __IO uint32_t  FLTR_ADDR_TYPE_2:  1;          /*!< (null)                                                                */
      __IO uint32_t  FLTR_2_LOADED:  1;             /*!< (null)                                                                */
    } JAL_LE_FLTR_CTRL_ST_ADDR_2_H_b;               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_ADDR_3_L;            /*!< LE Address Filter 3 Low word                                          */
    
    struct {
      __IO uint32_t  FLTR_ADDR_3_L: 32;             /*!< (null)                                                                */
    } JAL_LE_FLTR_ADDR_3_L_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_CTRL_ST_ADDR_3_H;    /*!< LE Address Filter 3 High and control and matched                      */
    
    struct {
      __IO uint32_t  FLTR_ADDR_3_H: 16;             /*!< (null)                                                                */
           uint32_t             : 13;
      __I  uint32_t  FLTR_MATCHED_3:  1;            /*!< (null)                                                                */
      __IO uint32_t  FLTR_ADDR_TYPE_3:  1;          /*!< (null)                                                                */
      __IO uint32_t  FLTR_3_LOADED:  1;             /*!< (null)                                                                */
    } JAL_LE_FLTR_CTRL_ST_ADDR_3_H_b;               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_ADDR_4_L;            /*!< LE Address Filter 4 Low word                                          */
    
    struct {
      __IO uint32_t  FLTR_ADDR_4_L: 32;             /*!< (null)                                                                */
    } JAL_LE_FLTR_ADDR_4_L_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_CTRL_ST_ADDR_4_H;    /*!< LE Address Filter 4 High and control and matched                      */
    
    struct {
      __IO uint32_t  FLTR_ADDR_4_H: 16;             /*!< (null)                                                                */
           uint32_t             : 13;
      __I  uint32_t  FLTR_MATCHED_4:  1;            /*!< (null)                                                                */
      __IO uint32_t  FLTR_ADDR_TYPE_4:  1;          /*!< (null)                                                                */
      __IO uint32_t  FLTR_4_LOADED:  1;             /*!< (null)                                                                */
    } JAL_LE_FLTR_CTRL_ST_ADDR_4_H_b;               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_ADDR_5_L;            /*!< LE Address Filter 5 Low word                                          */
    
    struct {
      __IO uint32_t  FLTR_ADDR_5_L: 32;             /*!< (null)                                                                */
    } JAL_LE_FLTR_ADDR_5_L_b;                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_CTRL_ST_ADDR_5_H;    /*!< LE Address Filter 5 High and control and matched                      */
    
    struct {
      __IO uint32_t  FLTR_ADDR_5_H: 16;             /*!< (null)                                                                */
           uint32_t             : 13;
      __I  uint32_t  FLTR_MATCHED_5:  1;            /*!< (null)                                                                */
      __IO uint32_t  FLTR_ADDR_TYPE_5:  1;          /*!< (null)                                                                */
      __IO uint32_t  FLTR_5_LOADED:  1;             /*!< (null)                                                                */
    } JAL_LE_FLTR_CTRL_ST_ADDR_5_H_b;               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_ADDR_DIRECT_L;       /*!< LE Direct Address Filter Low word                                     */
    
    struct {
      __IO uint32_t  FLTR_ADDR_DIRECT_L: 32;        /*!< (null)                                                                */
    } JAL_LE_FLTR_ADDR_DIRECT_L_b;                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_FLTR_CTRL_ST_ADDR_DIRECT_H;/*!< LE Direct Address Filter High and control and matched                */
    
    struct {
      __IO uint32_t  FLTR_ADDR_DIRECT_H: 16;        /*!< (null)                                                                */
           uint32_t             : 13;
      __I  uint32_t  FLTR_MATCHED_DIRECT:  1;       /*!< (null)                                                                */
      __IO uint32_t  FLTR_ADDR_TYPE_DIRECT:  1;     /*!< (null)                                                                */
      __IO uint32_t  FLTR_DIRECT_LOADED:  1;        /*!< (null)                                                                */
    } JAL_LE_FLTR_CTRL_ST_ADDR_DIRECT_H_b;          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_LOCAL_ADDR_L;             /*!< LE Local Address Filter Low word                                      */
    
    struct {
      __IO uint32_t  LE_LOCAL_ADDR_L: 32;           /*!< (null)                                                                */
    } JAL_LE_LOCAL_ADDR_L_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_LOCAL_CTRL_ST_ADDR_H;     /*!< LE Local Address Filter High and control and matched                  */
    
    struct {
      __IO uint32_t  LE_LOCAL_ADDR_H: 16;           /*!< (null)                                                                */
           uint32_t             : 13;
      __I  uint32_t  LE_LOCAL_ADDR_MATCHED:  1;     /*!< (null)                                                                */
      __IO uint32_t  LE_LOCAL_ADDR_TYPE:  1;        /*!< (null)                                                                */
    } JAL_LE_LOCAL_CTRL_ST_ADDR_H_b;                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3[88];
  
  union {
    __IO uint32_t  JAL_LE_AES_MIC;                  /*!< AES MIC in Big Endian                                                 */
    
    struct {
      __IO uint32_t  AES_MIC    : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_MIC_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_DATA_0;               /*!< AES Data Word 0                                                       */
    
    struct {
      __IO uint32_t  AES_DATA_0 : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_DATA_0_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_DATA_1;               /*!< AES Data Word 1                                                       */
    
    struct {
      __IO uint32_t  AES_DATA_1 : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_DATA_1_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_DATA_2;               /*!< AES Data Word 2                                                       */
    
    struct {
      __IO uint32_t  AES_DATA_2 : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_DATA_2_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_DATA_3;               /*!< AES Data Word 3                                                       */
    
    struct {
      __IO uint32_t  AES_DATA_3 : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_DATA_3_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_DATA_4;               /*!< AES Data Word 4                                                       */
    
    struct {
      __IO uint32_t  AES_DATA_4 : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_DATA_4_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_DATA_5;               /*!< AES Data Word 5                                                       */
    
    struct {
      __IO uint32_t  AES_DATA_5 : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_DATA_5_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  JAL_LE_AES_DATA_6;               /*!< AES Data Word 6                                                       */
    
    struct {
      __IO uint32_t  AES_DATA_6 : 32;               /*!< (null)                                                                */
    } JAL_LE_AES_DATA_6_b;                          /*!< BitSize                                                               */
  };
} BT_LE_Type;


/* ================================================================================ */
/* ================                     BT_PHY                     ================ */
/* ================================================================================ */


/**
  * @brief Bluetooth PHY (BT_PHY)
  */

typedef struct {                                    /*!< BT_PHY Structure                                                      */
  
  union {
    __IO uint32_t  rx_str_en;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  gfsk_str_en:  1;               /*!< (null)                                                                */
    } rx_str_en_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  xcorr_mod_sel;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ble_xcorr_mod_sel:  1;         /*!< (null)                                                                */
    } xcorr_mod_sel_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ble_xcorr_th;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ble_xcorr_th:  4;              /*!< (null)                                                                */
    } ble_xcorr_th_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fsync_det_sel_idx;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fsync_det_sel_idx:  4;         /*!< (null)                                                                */
    } fsync_det_sel_idx_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cfo_fb_cnt_th_sel;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cfo_fb_cnt_th_sel:  4;         /*!< (null)                                                                */
    } cfo_fb_cnt_th_sel_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cfo_cap_th;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cfo_cap_th :  6;               /*!< (null)                                                                */
    } cfo_cap_th_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  en_cfo_est;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  en_cfo_est :  1;               /*!< (null)                                                                */
    } en_cfo_est_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cfo_for_dpsk_sel;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cfo_for_dpsk_sel:  1;          /*!< (null)                                                                */
    } cfo_for_dpsk_sel_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cfo_cap_fsync;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cfo_cap_fsync:  1;             /*!< (null)                                                                */
    } cfo_cap_fsync_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rx_top_cfo_mode;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rx_top_cfo_mode:  1;           /*!< (null)                                                                */
    } rx_top_cfo_mode_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  h_idx;                           /*!< no description                                                        */
    
    struct {
      __IO uint32_t  h_idx      :  1;               /*!< (null)                                                                */
    } h_idx_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  tx_filt_gain_cmp;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  tx_filt_gain_cmp:  6;          /*!< (null)                                                                */
    } tx_filt_gain_cmp_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  en_gfsk_24x_sat;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  en_gfsk_24x_sat:  1;           /*!< (null)                                                                */
    } en_gfsk_24x_sat_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  tx_edr2_dly_sel;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  tx_edr2_dly_sel:  6;           /*!< (null)                                                                */
    } tx_edr2_dly_sel_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  en_dc_removal;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  en_dc_removal:  1;             /*!< (null)                                                                */
    } en_dc_removal_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dcnotch_k_sel;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dcnotch_k_sel:  4;             /*!< (null)                                                                */
    } dcnotch_k_sel_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  res_32x_en;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  res_32x_en :  1;               /*!< (null)                                                                */
    } res_32x_en_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  err_scale_sel;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  err_scale_sel:  2;             /*!< (null)                                                                */
    } err_scale_sel_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k1_gfsk_sel;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k1_gfsk_sel:  3;               /*!< (null)                                                                */
    } k1_gfsk_sel_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k2_gfsk_sel;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k2_gfsk_sel:  3;               /*!< (null)                                                                */
    } k2_gfsk_sel_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k1_dpsk_sel;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k1_dpsk_sel:  3;               /*!< (null)                                                                */
    } k1_dpsk_sel_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k2_dpsk_sel;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k2_dpsk_sel:  3;               /*!< (null)                                                                */
    } k2_dpsk_sel_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k2_bypass;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k2_bypass  :  1;               /*!< (null)                                                                */
    } k2_bypass_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sw_vld_dly_sel;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  sw_vld_dly_sel:  3;            /*!< (null)                                                                */
    } sw_vld_dly_sel_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sw_win_lth_offset;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  sw_win_lth_offset:  4;         /*!< (null)                                                                */
    } sw_win_lth_offset_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sw_win_hth_offset;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  sw_win_hth_offset:  4;         /*!< (null)                                                                */
    } sw_win_hth_offset_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dem_dly_bkoff_gfsk;              /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dem_dly_bkoff_gfsk:  4;        /*!< (null)                                                                */
    } dem_dly_bkoff_gfsk_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dem_dly_bkoff_dpsk;              /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dem_dly_bkoff_dpsk:  4;        /*!< (null)                                                                */
    } dem_dly_bkoff_dpsk_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  n_extra_offset_sel;              /*!< no description                                                        */
    
    struct {
      __IO uint32_t  n_extra_offset_sel:  1;        /*!< (null)                                                                */
    } n_extra_offset_sel_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  n_ftune_gfsk_sel;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  n_ftune_gfsk_sel:  2;          /*!< (null)                                                                */
    } n_ftune_gfsk_sel_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  n_ftune_dpsk_sel;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  n_ftune_dpsk_sel:  2;          /*!< (null)                                                                */
    } n_ftune_dpsk_sel_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  xcorr_th_gfsk_sel;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  xcorr_th_gfsk_sel:  4;         /*!< (null)                                                                */
    } xcorr_th_gfsk_sel_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  xcorr_th_dpsk_sel;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  xcorr_th_dpsk_sel:  4;         /*!< (null)                                                                */
    } xcorr_th_dpsk_sel_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  xcorr_th_ble_sel;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  xcorr_th_ble_sel:  4;          /*!< (null)                                                                */
    } xcorr_th_ble_sel_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cnt2th;                          /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cnt2th     :  3;               /*!< (null)                                                                */
    } cnt2th_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_fix0_2_timeout_sl;             /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_fix0_2_timeout_sl:  3;       /*!< (null)                                                                */
    } k_fix0_2_timeout_sl_b;                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0[2];
  
  union {
    __IO uint32_t  fbfb_acc_fix_fsync;              /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fbfb_acc_fix_fsync:  1;        /*!< (null)                                                                */
    } fbfb_acc_fix_fsync_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rx_fe_cfo_est_k;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rx_fe_cfo_est_k:  3;           /*!< (null)                                                                */
    } rx_fe_cfo_est_k_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  chf_ini_sel;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  chf_ini_sel:  1;               /*!< (null)                                                                */
    } chf_ini_sel_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  en_cfo_cmp;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  en_cfo_cmp :  1;               /*!< (null)                                                                */
    } en_cfo_cmp_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cfo_cmp_dis_lth;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cfo_cmp_dis_lth:  3;           /*!< (null)                                                                */
    } cfo_cmp_dis_lth_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cfo_cmp_dis_hth;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cfo_cmp_dis_hth:  3;           /*!< (null)                                                                */
    } cfo_cmp_dis_hth_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  en_fagc;                         /*!< no description                                                        */
    
    struct {
      __IO uint32_t  en_fagc    :  1;               /*!< (null)                                                                */
    } en_fagc_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  lwin;                            /*!< no description                                                        */
    
    struct {
      __IO uint32_t  lwin       :  1;               /*!< (null)                                                                */
    } lwin_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rx_fagc_ref;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rx_fagc_ref:  2;               /*!< (null)                                                                */
    } rx_fagc_ref_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  gfagc_reg;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  gfagc_reg  : 16;               /*!< (null)                                                                */
    } gfagc_reg_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  gfagc_wen;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  gfagc_wen  :  1;               /*!< (null)                                                                */
    } gfagc_wen_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  snr_est;                         /*!< no description                                                        */
    
    struct {
      __IO uint32_t  snr_est    :  6;               /*!< (null)                                                                */
    } snr_est_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rssi_timeout_cnst;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rssi_timeout_cnst:  4;         /*!< (null)                                                                */
    } rssi_timeout_cnst_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rssi_save_mode;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rssi_save_mode:  2;            /*!< (null)                                                                */
    } rssi_save_mode_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rssi_k_sel;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rssi_k_sel :  2;               /*!< (null)                                                                */
    } rssi_k_sel_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rssi_est_sel;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rssi_est_sel:  1;              /*!< (null)                                                                */
    } rssi_est_sel_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rssi_est_real_time;              /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rssi_est_real_time:  1;        /*!< (null)                                                                */
    } rssi_est_real_time_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sig_dbm_est;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  sig_dbm_est:  8;               /*!< (null)                                                                */
    } sig_dbm_est_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_chg_ini0;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_chg_ini0 :  4;               /*!< (null)                                                                */
    } k_chg_ini0_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_chg_ini1;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_chg_ini1 :  4;               /*!< (null)                                                                */
    } k_chg_ini1_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_dcy_ini0;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_dcy_ini0 :  4;               /*!< (null)                                                                */
    } k_dcy_ini0_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_dcy_ini1;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_dcy_ini1 :  4;               /*!< (null)                                                                */
    } k_dcy_ini1_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  maxmin0_lim;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  maxmin0_lim:  2;               /*!< (null)                                                                */
    } maxmin0_lim_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  maxmin1_lim;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  maxmin1_lim:  2;               /*!< (null)                                                                */
    } maxmin1_lim_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dc_lim;                          /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dc_lim     :  2;               /*!< (null)                                                                */
    } dc_lim_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dcy_cond_th_sel;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dcy_cond_th_sel:  2;           /*!< (null)                                                                */
    } dcy_cond_th_sel_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  var_dcy_fsync_en;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  var_dcy_fsync_en:  1;          /*!< (null)                                                                */
    } var_dcy_fsync_en_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_chg_lim;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_chg_lim  :  3;               /*!< (null)                                                                */
    } k_chg_lim_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_dcy_lim;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_dcy_lim  :  3;               /*!< (null)                                                                */
    } k_dcy_lim_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cnt_chg_th_sel;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cnt_chg_th_sel:  2;            /*!< (null)                                                                */
    } cnt_chg_th_sel_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cnt_dcy_th_sel;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cnt_dcy_th_sel:  2;            /*!< (null)                                                                */
    } cnt_dcy_th_sel_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fine_dcy_sel;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fine_dcy_sel:  1;              /*!< (null)                                                                */
    } fine_dcy_sel_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dc_lpf_sel;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dc_lpf_sel :  1;               /*!< (null)                                                                */
    } dc_lpf_sel_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ref_th_sel;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ref_th_sel :  2;               /*!< (null)                                                                */
    } ref_th_sel_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_dcy_cnt_en;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_dcy_cnt_en:  1;              /*!< (null)                                                                */
    } k_dcy_cnt_en_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_dcy_ref_en;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_dcy_ref_en:  1;              /*!< (null)                                                                */
    } k_dcy_ref_en_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_dcy_cond_en;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_dcy_cond_en:  1;             /*!< (null)                                                                */
    } k_dcy_cond_en_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_chg_cnt_en;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_chg_cnt_en:  1;              /*!< (null)                                                                */
    } k_chg_cnt_en_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_chg_ref_en;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_chg_ref_en:  1;              /*!< (null)                                                                */
    } k_chg_ref_en_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_chg_cond_en;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_chg_cond_en:  1;             /*!< (null)                                                                */
    } k_chg_cond_en_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_slope_sel;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_slope_sel:  1;               /*!< (null)                                                                */
    } k_slope_sel_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  k_dc_lpf;                        /*!< no description                                                        */
    
    struct {
      __IO uint32_t  k_dc_lpf   :  2;               /*!< (null)                                                                */
    } k_dc_lpf_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  var_dcy_slope0;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  var_dcy_slope0:  2;            /*!< (null)                                                                */
    } var_dcy_slope0_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  var_dcy_slope1;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  var_dcy_slope1:  2;            /*!< (null)                                                                */
    } var_dcy_slope1_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  var_dx_en_range0;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  var_dx_en_range0:  2;          /*!< (null)                                                                */
    } var_dx_en_range0_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  var_dx_en_range1;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  var_dx_en_range1:  2;          /*!< (null)                                                                */
    } var_dx_en_range1_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  var_dcy0_en;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  var_dcy0_en:  1;               /*!< (null)                                                                */
    } var_dcy0_en_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  var_dcy1_en;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  var_dcy1_en:  1;               /*!< (null)                                                                */
    } var_dcy1_en_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  noise_det_en;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  noise_det_en:  1;              /*!< (null)                                                                */
    } noise_det_en_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  maxmin_lim_sel;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  maxmin_lim_sel:  1;            /*!< (null)                                                                */
    } maxmin_lim_sel_b;                             /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  tx_edr3_dly_sel;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  tx_edr3_dly_sel:  6;           /*!< (null)                                                                */
    } tx_edr3_dly_sel_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  gau_dly_cnt;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  gau_dly_cnt:  8;               /*!< (null)                                                                */
    } gau_dly_cnt_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  guard_dly_cnt;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  guard_dly_cnt:  8;             /*!< (null)                                                                */
    } guard_dly_cnt_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  tx_ext_sel;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  tx_ext_sel :  8;               /*!< (null)                                                                */
    } tx_ext_sel_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TX_RX_EN;                        /*!< no description                                                        */
    
    struct {
      __IO uint32_t  reg_tx_en  :  1;               /*!< (null)                                                                */
      __IO uint32_t  reg_rx_en  :  1;               /*!< (null)                                                                */
      __IO uint32_t  reg_tx_en_sel:  1;             /*!< (null)                                                                */
      __IO uint32_t  fsync_sel  :  1;               /*!< (null)                                                                */
    } TX_RX_EN_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  bt_phy_id;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  bt_phy_id  : 32;               /*!< (null)                                                                */
    } bt_phy_id_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3[3];
  
  union {
    __IO uint32_t  rx_gainc1;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rx_gainc_lut_0:  5;            /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  rx_gainc_lut_1:  5;            /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  rx_gainc_lut_2:  5;            /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  rx_gainc_lut_3:  5;            /*!< (null)                                                                */
    } rx_gainc1_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rx_gainc2;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rx_gainc_lut_4:  5;            /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  rx_gainc_lut_5:  5;            /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  rx_gainc_lut_6:  5;            /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  rx_gainc_lut_7:  5;            /*!< (null)                                                                */
    } rx_gainc2_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rx_gainc3;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rx_gainc_lut_8:  5;            /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  rx_gainc_lut_9:  5;            /*!< (null)                                                                */
    } rx_gainc3_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_RFAGC1;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rfagc_lut_0: 10;               /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  rfagc_lut_1: 10;               /*!< (null)                                                                */
    } RX_RFAGC1_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_RFAGC2;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rfagc_lut_2: 10;               /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  rfagc_lut_3: 10;               /*!< (null)                                                                */
    } RX_RFAGC2_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_RFAGC3;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rfagc_lut_4: 10;               /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  rfagc_lut_5: 10;               /*!< (null)                                                                */
    } RX_RFAGC3_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_RFAGC4;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rfagc_lut_6: 10;               /*!< (null)                                                                */
    } RX_RFAGC4_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_IFAGC1;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ifagc_lut1_0: 10;              /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  ifagc_lut1_1: 10;              /*!< (null)                                                                */
    } RX_IFAGC1_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_IFAGC2;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ifagc_lut1_2: 10;              /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  ifagc_lut1_3: 10;              /*!< (null)                                                                */
    } RX_IFAGC2_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_IFAGC3;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ifagc_lut1_4: 10;              /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  ifagc_lut1_5: 10;              /*!< (null)                                                                */
    } RX_IFAGC3_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_IFAGC4;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ifagc_lut1_6: 10;              /*!< (null)                                                                */
    } RX_IFAGC4_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_IFAGC5;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ifagc_lut2_0: 10;              /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  ifagc_lut2_1: 10;              /*!< (null)                                                                */
    } RX_IFAGC5_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_IFAGC6;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ifagc_lut2_2: 10;              /*!< (null)                                                                */
           uint32_t             :  6;
      __I  uint32_t  ifagc_lut2_3: 10;              /*!< (null)                                                                */
    } RX_IFAGC6_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_IFAGC7;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ifagc_lut2_4: 10;              /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  ifagc_lut2_5: 10;              /*!< (null)                                                                */
    } RX_IFAGC7_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RX_IFAGC8;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ifagc_lut2_6: 10;              /*!< (null)                                                                */
    } RX_IFAGC8_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dis_pld_cfo_cmp;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dis_pld_cfo_cmp:  1;           /*!< (null)                                                                */
    } dis_pld_cfo_cmp_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  en_anti_intf;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  en_anti_intf:  1;              /*!< (null)                                                                */
    } en_anti_intf_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  maxmin0_lim2;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  maxmin0_lim2:  2;              /*!< (null)                                                                */
    } maxmin0_lim2_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  maxmin1_lim2;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  maxmin1_lim2:  2;              /*!< (null)                                                                */
    } maxmin1_lim2_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  clr_th;                          /*!< no description                                                        */
    
    struct {
      __IO uint32_t  clr_th     :  4;               /*!< (null)                                                                */
    } clr_th_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  en_clr;                          /*!< no description                                                        */
    
    struct {
      __IO uint32_t  en_clr     :  1;               /*!< (null)                                                                */
    } en_clr_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dem_dly_bkoff_gfsk2;             /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dem_dly_bkoff_gfsk2:  3;       /*!< (null)                                                                */
    } dem_dly_bkoff_gfsk2_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rx_en_str_st1_wrt;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rx_en_str_st1_wrt:  1;         /*!< (null)                                                                */
    } rx_en_str_st1_wrt_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  en_cfo_acc_clr;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  en_cfo_acc_clr:  1;            /*!< (null)                                                                */
    } en_cfo_acc_clr_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  en_cfo_clr_after_sync;           /*!< no description                                                        */
    
    struct {
      __IO uint32_t  en_cfo_clr_after_sync:  1;     /*!< (null)                                                                */
    } en_cfo_clr_after_sync_b;                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cfo_acc_sat_lim;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cfo_acc_sat_lim:  3;           /*!< (null)                                                                */
    } cfo_acc_sat_lim_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dcnotch_k2;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dcnotch_k2 :  3;               /*!< (null)                                                                */
    } dcnotch_k2_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dc_mode;                         /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dc_mode    :  2;               /*!< (null)                                                                */
    } dc_mode_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  str_xcorr_cut;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  str_xcorr_cut:  1;             /*!< (null)                                                                */
    } str_xcorr_cut_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  th_sel;                          /*!< no description                                                        */
    
    struct {
      __IO uint32_t  th_sel     :  4;               /*!< (null)                                                                */
    } th_sel_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  adc_clr_dur_sel;                 /*!< no description                                                        */
    
    struct {
      __IO uint32_t  adc_clr_dur_sel:  3;           /*!< (null)                                                                */
    } adc_clr_dur_sel_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  sat_cnt_th_sel;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  sat_cnt_th_sel:  4;            /*!< (null)                                                                */
    } sat_cnt_th_sel_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cnt_mode;                        /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cnt_mode   :  1;               /*!< (null)                                                                */
    } cnt_mode_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  a_reg;                           /*!< no description                                                        */
    
    struct {
      __IO uint32_t  a_reg      :  2;               /*!< (null)                                                                */
    } a_reg_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  c_reg;                           /*!< no description                                                        */
    
    struct {
      __IO uint32_t  c_reg      :  3;               /*!< (null)                                                                */
    } c_reg_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pd_clr_dur_sel;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  pd_clr_dur_sel:  3;            /*!< (null)                                                                */
    } pd_clr_dur_sel_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  din_sel;                         /*!< no description                                                        */
    
    struct {
      __IO uint32_t  din_sel    :  1;               /*!< (null)                                                                */
    } din_sel_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  pd_det_mode;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  pd_det_mode:  2;               /*!< (null)                                                                */
    } pd_det_mode_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  buf_l_sel;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  buf_l_sel  :  2;               /*!< (null)                                                                */
    } buf_l_sel_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  th_analog;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  th_analog  :  4;               /*!< (null)                                                                */
    } th_analog_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ble_xcorr_win_th;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  ble_xcorr_win_hth:  3;         /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  ble_xcorr_win_lth:  3;         /*!< (null)                                                                */
    } ble_xcorr_win_th_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  gfsk_xcorr_win_th;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  gfsk_xcorr_win_hth:  3;        /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  gfsk_xcorr_win_lth:  3;        /*!< (null)                                                                */
    } gfsk_xcorr_win_th_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  dpsk_xcorr_win_th;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  dpsk_xcorr_win_hth:  4;        /*!< (null)                                                                */
      __IO uint32_t  dpsk_xcorr_win_lth:  4;        /*!< (null)                                                                */
    } dpsk_xcorr_win_th_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  if_reg;                          /*!< no description                                                        */
    
    struct {
      __IO uint32_t  if_reg     : 12;               /*!< (null)                                                                */
    } if_reg_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  iq_in_swap;                      /*!< no description                                                        */
    
    struct {
      __IO uint32_t  iq_in_swap :  1;               /*!< (null)                                                                */
    } iq_in_swap_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fm_mode;                         /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fm_mode    :  1;               /*!< (null)                                                                */
    } fm_mode_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fm_rssi;                         /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fm_rssi_k_sel:  2;             /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  fm_snr     :  8;               /*!< (null)                                                                */
      __IO uint32_t  fm_rssi    :  8;               /*!< (null)                                                                */
    } fm_rssi_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rmv2_deem;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fm_dc_rmv2_k:  2;              /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  fm_dc_rmv2_en:  1;             /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  fm_deemphasis_tao:  1;         /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  fm_deemphasis_en:  1;          /*!< (null)                                                                */
    } rmv2_deem_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fm_fagc;                         /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fm_fagc_lpg:  2;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  fm_fagc_ref:  8;               /*!< (null)                                                                */
      __IO uint32_t  fm_fagc_en :  1;               /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  fm_fagc_gain: 12;              /*!< (null)                                                                */
    } fm_fagc_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fm_chhc_filt;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fm_chhc_snr_thl:  8;           /*!< (null)                                                                */
      __IO uint32_t  fm_chhc_snr_thh:  8;           /*!< (null)                                                                */
      __IO uint32_t  fm_chhc_filt_en:  1;           /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  fm_hc_mode :  1;               /*!< (null)                                                                */
    } fm_chhc_filt_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fm_lrhc_filt;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fm_lrhc_snr_thl:  8;           /*!< (null)                                                                */
      __IO uint32_t  fm_lrhc_snr_thh:  8;           /*!< (null)                                                                */
      __IO uint32_t  fm_lrhc_filt_en:  1;           /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  fm_fir_ram_clr:  1;            /*!< (null)                                                                */
    } fm_lrhc_filt_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  spi_apb_switch;                  /*!< no description                                                        */
    
    struct {
      __IO uint32_t  spi_apb_switch:  1;            /*!< (null)                                                                */
    } spi_apb_switch_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cfo_est_acc_trunc;               /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cfo_est_acc_trunc: 10;         /*!< (null)                                                                */
    } cfo_est_acc_trunc_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fsync_early;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fsync_early:  1;               /*!< (null)                                                                */
    } fsync_early_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  cfo_cap_for_dpsk;                /*!< no description                                                        */
    
    struct {
      __IO uint32_t  cfo_cap_for_dpsk: 10;          /*!< (null)                                                                */
    } cfo_cap_for_dpsk_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  tx_iq_mux;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  tx_i_reg   : 12;               /*!< (null)                                                                */
      __IO uint32_t  tx_i_mn    :  1;               /*!< (null)                                                                */
      __IO uint32_t  tx_q_mn    :  1;               /*!< (null)                                                                */
      __IO uint32_t  trx_calib_iq_mn:  1;           /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  tx_q_reg   : 12;               /*!< (null)                                                                */
    } tx_iq_mux_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fm_cordic_bp;                    /*!< no description                                                        */
    
    struct {
      __IO uint32_t  fm_cordic_bp:  1;              /*!< (null)                                                                */
      __IO uint32_t  iq_mismatch_enlarge:  1;       /*!< (null)                                                                */
      __IO uint32_t  enlarge_iqmis:  2;             /*!< (null)                                                                */
      __IO uint32_t  adc_clr_reg_clr:  1;           /*!< (null)                                                                */
      __IO uint32_t  adc_clr_o_reg:  1;             /*!< (null)                                                                */
      __IO uint32_t  phy_reg_reserv_l: 10;          /*!< (null)                                                                */
      __IO uint32_t  phy_reg_reserv_h: 16;          /*!< (null)                                                                */
    } fm_cordic_bp_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  tx_if_reg;                       /*!< no description                                                        */
    
    struct {
      __IO uint32_t  gau_out_reg: 11;               /*!< (null)                                                                */
      __IO uint32_t  tx_if_reg_sel:  1;             /*!< (null)                                                                */
      __IO uint32_t  tx_iq_swp  :  1;               /*!< (null)                                                                */
      __IO uint32_t  tx_inv_clk :  1;               /*!< (null)                                                                */
      __IO uint32_t  rx_inv_clk :  1;               /*!< (null)                                                                */
    } tx_if_reg_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  fm_decimation;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  decimation_o_s: 16;            /*!< (null)                                                                */
    } fm_decimation_b;                              /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4;
  
  union {
    __IO uint32_t  iq_com_single;                   /*!< no description                                                        */
    
    struct {
      __IO uint32_t  iq_com_single:  1;             /*!< (null)                                                                */
    } iq_com_single_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxi_offset1;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rxi_offset_lut_0:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_1:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_2:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_3:  8;          /*!< (null)                                                                */
    } rxi_offset1_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxi_offset2;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rxi_offset_lut_4:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_5:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_6:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_7:  8;          /*!< (null)                                                                */
    } rxi_offset2_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxi_offset3;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rxi_offset_lut_8:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_9:  8;          /*!< (null)                                                                */
    } rxi_offset3_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxq_offset1;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rxi_offset_lut_0:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_1:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_2:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_3:  8;          /*!< (null)                                                                */
    } rxq_offset1_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxq_offset2;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rxi_offset_lut_4:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_5:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_6:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_7:  8;          /*!< (null)                                                                */
    } rxq_offset2_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  rxq_offset3;                     /*!< no description                                                        */
    
    struct {
      __IO uint32_t  rxi_offset_lut_8:  8;          /*!< (null)                                                                */
      __IO uint32_t  rxi_offset_lut_9:  8;          /*!< (null)                                                                */
    } rxq_offset3_b;                                /*!< BitSize                                                               */
  };
  
  uint8_t x298_x3ff[0x400-0x298];
  
  __IO uint32_t ANALOGUE[0x100];               //offset address: 0x400-0x7FF
  
  __IO uint32_t ADC_INTR;                      //offset address: 0x800, adc: 0x200
  __IO uint32_t ADC_INTR_MASK;
  __IO uint32_t ADC_CR;
  __IO uint32_t ADC_CFG;
  __IO uint32_t ADC_CHSELR;                    //offset address: 0x810, adc: 0x204 
  __IO uint32_t TESTCTRL0;
  __IO uint32_t TESTCTRL1;
  __IO uint32_t TESTCTRL2;
  __IO uint32_t TESTCTRL3;                     //offset address: 0x820, adc: 0x208 
  __IO uint32_t TESTCTRL4;
  __IO uint32_t TESTCTRL5;
  __IO uint32_t TESTCTRL6;
  __IO uint32_t TESTCTRL7;                     //offset address: 0x830, adc: 0x20C
  __IO uint32_t CHK0_DATA;
  __IO uint32_t CHK1_DATA;
  __IO uint32_t CHK2_DATA;
  __IO uint32_t CHK3_DATA;                     //offset address: 0x840, adc: 0x210 
  __IO uint32_t CHK4_DATA;
  __IO uint32_t CHK5_DATA;
  __IO uint32_t CHK6_DATA;
  __IO uint32_t TESTCFG;                       //offset address: 0x850, adc: 0x214
  __IO uint32_t CHK0_TIME;
  __IO uint32_t CHK1_TIME;
  __IO uint32_t CHK2_TIME;
  __IO uint32_t CHK3_TIME;                     //offset address: 0x860, adc: 0x218
  __IO uint32_t CHK4_TIME;
  __IO uint32_t CHK5_TIME;
  __IO uint32_t CHK6_TIME;
  __IO uint32_t TIMER_SEL;                     //offset address: 0x870, adc: 0x21C
  __IO uint32_t TESTDATA_REG;                  //offset address: 0x874, adc: 0x21D
} BT_PHY_Type;	  


/* ================================================================================ */
/* ================                    ROMPATCH                    ================ */
/* ================================================================================ */


/**
  * @brief ROM Patch Controller (ROMPATCH)
  */

typedef struct {                                    /*!< ROMPATCH Structure                                                    */
  
  union {
    __IO uint32_t  ENL;                             /*!< Enable-Low register                                                   */
    
    struct {
      __IO uint32_t  enable     : 32;               /*!< (null)                                                                */
    } ENL_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ENH;                             /*!< Enable-High register                                                  */
    
    struct {
      __IO uint32_t  enable     : 32;               /*!< (null)                                                                */
    } ENH_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR0;                           /*!< Address 0 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR0_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA0;                           /*!< Data 0 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA0_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR1;                           /*!< Address 1 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR1_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA1;                           /*!< Data 1 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA1_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR2;                           /*!< Address 2 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR2_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA2;                           /*!< Data 2 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA2_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR3;                           /*!< Address 3 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR3_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA3;                           /*!< Data 3 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA3_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR4;                           /*!< Address 4 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR4_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA4;                           /*!< Data 4 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA4_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR5;                           /*!< Address 5 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR5_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA5;                           /*!< Data 5 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA5_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR6;                           /*!< Address 6 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR6_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA6;                           /*!< Data 6 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA6_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR7;                           /*!< Address 7 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR7_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA7;                           /*!< Data 7 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA7_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR8;                           /*!< Address 8 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR8_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA8;                           /*!< Data 8 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA8_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR9;                           /*!< Address 9 register                                                    */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR9_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA9;                           /*!< Data 9 register                                                       */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA9_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR10;                          /*!< Address 10 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR10_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA10;                          /*!< Data 10 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA10_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR11;                          /*!< Address 11 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR11_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA11;                          /*!< Data 11 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA11_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR12;                          /*!< Address 12 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR12_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA12;                          /*!< Data 12 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA12_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR13;                          /*!< Address 13 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR13_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA13;                          /*!< Data 13 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA13_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR14;                          /*!< Address 14 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR14_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA14;                          /*!< Data 14 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA14_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR15;                          /*!< Address 15 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR15_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA15;                          /*!< Data 15 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA15_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR16;                          /*!< Address 16 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR16_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA16;                          /*!< Data 16 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA16_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR17;                          /*!< Address 17 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR17_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA17;                          /*!< Data 17 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA17_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR18;                          /*!< Address 18 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR18_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA18;                          /*!< Data 18 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA18_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR19;                          /*!< Address 19 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR19_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA19;                          /*!< Data 19 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA19_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR20;                          /*!< Address 20 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR20_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA20;                          /*!< Data 20 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA20_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR21;                          /*!< Address 21 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR21_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA21;                          /*!< Data 21 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA21_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR22;                          /*!< Address 22 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR22_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA22;                          /*!< Data 22 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA22_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR23;                          /*!< Address 23 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR23_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA23;                          /*!< Data 23 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA23_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR24;                          /*!< Address 24 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR24_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA24;                          /*!< Data 24 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA24_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR25;                          /*!< Address 25 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR25_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA25;                          /*!< Data 25 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA25_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR26;                          /*!< Address 26 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR26_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA26;                          /*!< Data 26 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA26_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR27;                          /*!< Address 27 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR27_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA27;                          /*!< Data 27 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA27_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR28;                          /*!< Address 28 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR28_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA28;                          /*!< Data 28 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA28_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR29;                          /*!< Address 29 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR29_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA29;                          /*!< Data 29 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA29_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR30;                          /*!< Address 30 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR30_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA30;                          /*!< Data 30 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA30_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR31;                          /*!< Address 31 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR31_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA31;                          /*!< Data 31 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA31_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADDR32;                          /*!< Address 32 register                                                   */
    
    struct {
      __IO uint32_t  address    : 32;               /*!< (null)                                                                */
    } ADDR32_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DATA32;                          /*!< Data 32 register                                                      */
    
    struct {
      __IO uint32_t  data       : 32;               /*!< (null)                                                                */
    } DATA32_b;                                     /*!< BitSize                                                               */
  };
} ROMPATCH_Type;


/* ================================================================================ */
/* ================                      DMAC                      ================ */
/* ================================================================================ */


/**
  * @brief DMA controller (DMAC)
  */

typedef struct {                                    /*!< DMAC Structure                                                        */
  
  union {
    __IO uint32_t  SAR0;                            /*!< Channel 0 Source Address Register                                     */
    
    struct {
      __IO uint32_t  SAR        : 32;               /*!< (null)                                                                */
    } SAR0_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0;
  
  union {
    __IO uint32_t  DAR0;                            /*!< Channel 0 Destination Address Register                                */
    
    struct {
      __IO uint32_t  DAR        : 32;               /*!< (null)                                                                */
    } DAR0_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  LLP0;                            /*!< Channel 0 Linked List Pointer Register                                */
    
    struct {
      __IO uint32_t  LMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOC        : 30;               /*!< (null)                                                                */
    } LLP0_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  CTL0_L;                          /*!< Channel 0 Control Register Low word                                   */
    
    struct {
      __IO uint32_t  INT_EN     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  SRC_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  DINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  SINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  DEST_MSIZE :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_MSIZE  :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_GATHER_EN:  1;             /*!< (null)                                                                */
      __IO uint32_t  DST_SCATTER_EN:  1;            /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TT_FC      :  3;               /*!< (null)                                                                */
      __IO uint32_t  DMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  SMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LLP_DST_EN :  1;               /*!< (null)                                                                */
      __IO uint32_t  LLP_SRC_EN :  1;               /*!< (null)                                                                */
    } CTL0_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTL0_H;                          /*!< Channel 0 Control Register High word                                  */
    
    struct {
      __IO uint32_t  BLOCK_TS   : 12;               /*!< (null)                                                                */
      __IO uint32_t  DONE       :  1;               /*!< (null)                                                                */
    } CTL0_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SSTAT0;                          /*!< Channel 0 Source Status Register                                      */
    
    struct {
      __IO uint32_t  SSTAT      : 32;               /*!< (null)                                                                */
    } SSTAT0_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3;
  
  union {
    __IO uint32_t  DSTAT0;                          /*!< Channel 0 Destination Status Register                                 */
    
    struct {
      __IO uint32_t  DSTAT      : 32;               /*!< (null)                                                                */
    } DSTAT0_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4;
  
  union {
    __IO uint32_t  SSTATAR0;                        /*!< Channel 0 Source Status Address Register                              */
    
    struct {
      __IO uint32_t  SSTATAR    : 32;               /*!< (null)                                                                */
    } SSTATAR0_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED5;
  
  union {
    __IO uint32_t  DSTATAR0;                        /*!< Channel 0 Destination Status Address Register                         */
    
    struct {
      __IO uint32_t  DSTATAR    : 32;               /*!< (null)                                                                */
    } DSTATAR0_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED6;
  
  union {
    __IO uint32_t  CFG0_L;                          /*!< Channel 0 Configuration Register Low word                             */
    
    struct {
           uint32_t             :  5;
      __IO uint32_t  CH_PRIOR   :  3;               /*!< (null)                                                                */
      __IO uint32_t  CH_SUSP    :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_EMPTY :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_DST :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH_L  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B_L   :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH    :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  MAX_ABRST  : 10;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_DST :  1;               /*!< (null)                                                                */
    } CFG0_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG0_H;                          /*!< Channel 0 Configuration Register High word                            */
    
    struct {
      __IO uint32_t  FCMODE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_MODE  :  1;               /*!< (null)                                                                */
      __IO uint32_t  PROTCTL    :  3;               /*!< (null)                                                                */
      __IO uint32_t  DS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_PER    :  4;               /*!< (null)                                                                */
      __IO uint32_t  DEST_PER   :  4;               /*!< (null)                                                                */
    } CFG0_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SGR0;                            /*!< Channel 0 Source Gather Register                                      */
    
    struct {
      __IO uint32_t  SGI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  SGC        : 12;               /*!< (null)                                                                */
    } SGR0_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED7;
  
  union {
    __IO uint32_t  DSR0;                            /*!< Channel 0 Destination Scatter Register                                */
    
    struct {
      __IO uint32_t  DSI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  DSC        : 12;               /*!< (null)                                                                */
    } DSR0_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED8;
  
  union {
    __IO uint32_t  SAR1;                            /*!< Channel 1 Source Address Register                                     */
    
    struct {
      __IO uint32_t  SAR        : 32;               /*!< (null)                                                                */
    } SAR1_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED9;
  
  union {
    __IO uint32_t  DAR1;                            /*!< Channel 1 Destination Address Register                                */
    
    struct {
      __IO uint32_t  DAR        : 32;               /*!< (null)                                                                */
    } DAR1_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED10;
  
  union {
    __IO uint32_t  LLP1;                            /*!< Channel 1 Linked List Pointer                                         */
    
    struct {
      __IO uint32_t  LMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOC        : 30;               /*!< (null)                                                                */
    } LLP1_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED11;
  
  union {
    __IO uint32_t  CTL1_L;                          /*!< Channel 1 Control Register Low word                                   */
    
    struct {
      __IO uint32_t  INT_EN     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  SRC_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  DINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  SINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  DEST_MSIZE :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_MSIZE  :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_GATHER_EN:  1;             /*!< (null)                                                                */
      __IO uint32_t  DST_SCATTER_EN:  1;            /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TT_FC      :  3;               /*!< (null)                                                                */
      __IO uint32_t  DMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  SMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LLP_DST_EN :  1;               /*!< (null)                                                                */
      __IO uint32_t  LLP_SRC_EN :  1;               /*!< (null)                                                                */
    } CTL1_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTL1_H;                          /*!< Channel 1 Control Register High word                                  */
    
    struct {
      __IO uint32_t  BLOCK_TS   : 12;               /*!< (null)                                                                */
      __IO uint32_t  DONE       :  1;               /*!< (null)                                                                */
    } CTL1_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SSTAT1;                          /*!< Channel 1 Source Status Register                                      */
    
    struct {
      __IO uint32_t  SSTAT      : 32;               /*!< (null)                                                                */
    } SSTAT1_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED12;
  
  union {
    __IO uint32_t  DSTAT1;                          /*!< Channel 1 Destination Status Register                                 */
    
    struct {
      __IO uint32_t  DSTAT      : 32;               /*!< (null)                                                                */
    } DSTAT1_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED13;
  
  union {
    __IO uint32_t  SSTATAR1;                        /*!< Channel 1 Source Status Address                                       */
    
    struct {
      __IO uint32_t  SSTATAR    : 32;               /*!< (null)                                                                */
    } SSTATAR1_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED14;
  
  union {
    __IO uint32_t  DSTATAR1;                        /*!< Channel 1 Destination Status Address                                  */
    
    struct {
      __IO uint32_t  DSTATAR    : 32;               /*!< (null)                                                                */
    } DSTATAR1_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED15;
  
  union {
    __IO uint32_t  CFG1_L;                          /*!< Channel 1 Configuration Register Low word                             */
    
    struct {
           uint32_t             :  5;
      __IO uint32_t  CH_PRIOR   :  3;               /*!< (null)                                                                */
      __IO uint32_t  CH_SUSP    :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_EMPTY :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_DST :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH_L  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B_L   :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH    :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  MAX_ABRST  : 10;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_DST :  1;               /*!< (null)                                                                */
    } CFG1_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG1_H;                          /*!< Channel 1 Configuration Register High word                            */
    
    struct {
      __IO uint32_t  FCMODE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_MODE  :  1;               /*!< (null)                                                                */
      __IO uint32_t  PROTCTL    :  3;               /*!< (null)                                                                */
      __IO uint32_t  DS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_PER    :  4;               /*!< (null)                                                                */
      __IO uint32_t  DEST_PER   :  4;               /*!< (null)                                                                */
    } CFG1_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SGR1;                            /*!< Channel 1 Source Gather Register                                      */
    
    struct {
      __IO uint32_t  SGI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  SGC        : 12;               /*!< (null)                                                                */
    } SGR1_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED16;
  
  union {
    __IO uint32_t  DSR1;                            /*!< Channel 1 Destination Scatter Register                                */
    
    struct {
      __IO uint32_t  DSI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  DSC        : 12;               /*!< (null)                                                                */
    } DSR1_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED17;
  
  union {
    __IO uint32_t  SAR2;                            /*!< Channel 2 Source Address Register                                     */
    
    struct {
      __IO uint32_t  SAR        : 32;               /*!< (null)                                                                */
    } SAR2_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED18;
  
  union {
    __IO uint32_t  DAR2;                            /*!< Channel 2 Destination Address Register                                */
    
    struct {
      __IO uint32_t  DAR        : 32;               /*!< (null)                                                                */
    } DAR2_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED19;
  
  union {
    __IO uint32_t  LLP2;                            /*!< Channel 2 Linked List Pointer                                         */
    
    struct {
      __IO uint32_t  LMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOC        : 30;               /*!< (null)                                                                */
    } LLP2_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED20;
  
  union {
    __IO uint32_t  CTL2_L;                          /*!< Channel 2 Control Register Low word                                   */
    
    struct {
      __IO uint32_t  INT_EN     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  SRC_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  DINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  SINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  DEST_MSIZE :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_MSIZE  :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_GATHER_EN:  1;             /*!< (null)                                                                */
      __IO uint32_t  DST_SCATTER_EN:  1;            /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TT_FC      :  3;               /*!< (null)                                                                */
      __IO uint32_t  DMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  SMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LLP_DST_EN :  1;               /*!< (null)                                                                */
      __IO uint32_t  LLP_SRC_EN :  1;               /*!< (null)                                                                */
    } CTL2_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTL2_H;                          /*!< Channel 2 Control Register High word                                  */
    
    struct {
      __IO uint32_t  BLOCK_TS   : 12;               /*!< (null)                                                                */
      __IO uint32_t  DONE       :  1;               /*!< (null)                                                                */
    } CTL2_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SSTAT2;                          /*!< Channel 2 Source Status Register                                      */
    
    struct {
      __IO uint32_t  SSTAT      : 32;               /*!< (null)                                                                */
    } SSTAT2_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED21;
  
  union {
    __IO uint32_t  DSTAT2;                          /*!< Channel 2 Destination Status Register                                 */
    
    struct {
      __IO uint32_t  DSTAT      : 32;               /*!< (null)                                                                */
    } DSTAT2_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED22;
  
  union {
    __IO uint32_t  SSTATAR2;                        /*!< Channel 2 Source Status Address                                       */
    
    struct {
      __IO uint32_t  SSTATAR    : 32;               /*!< (null)                                                                */
    } SSTATAR2_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED23;
  
  union {
    __IO uint32_t  DSTATAR2;                        /*!< Channel 2 Destination Status Address                                  */
    
    struct {
      __IO uint32_t  DSTATAR    : 32;               /*!< (null)                                                                */
    } DSTATAR2_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED24;
  
  union {
    __IO uint32_t  CFG2_L;                          /*!< Channel 2 Configuration Register Low word                             */
    
    struct {
           uint32_t             :  5;
      __IO uint32_t  CH_PRIOR   :  3;               /*!< (null)                                                                */
      __IO uint32_t  CH_SUSP    :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_EMPTY :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_DST :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH_L  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B_L   :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH    :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  MAX_ABRST  : 10;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_DST :  1;               /*!< (null)                                                                */
    } CFG2_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG2_H;                          /*!< Channel 2 Configuration Register High word                            */
    
    struct {
      __IO uint32_t  FCMODE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_MODE  :  1;               /*!< (null)                                                                */
      __IO uint32_t  PROTCTL    :  3;               /*!< (null)                                                                */
      __IO uint32_t  DS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_PER    :  4;               /*!< (null)                                                                */
      __IO uint32_t  DEST_PER   :  4;               /*!< (null)                                                                */
    } CFG2_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SGR2;                            /*!< Channel 2 Source Gather Register                                      */
    
    struct {
      __IO uint32_t  SGI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  SGC        : 12;               /*!< (null)                                                                */
    } SGR2_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED25;
  
  union {
    __IO uint32_t  DSR2;                            /*!< Channel 2 Destination Scatter Register                                */
    
    struct {
      __IO uint32_t  DSI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  DSC        : 12;               /*!< (null)                                                                */
    } DSR2_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED26;
  
  union {
    __IO uint32_t  SAR3;                            /*!< Channel 3 Source Address Register                                     */
    
    struct {
      __IO uint32_t  SAR        : 32;               /*!< (null)                                                                */
    } SAR3_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED27;
  
  union {
    __IO uint32_t  DAR3;                            /*!< Channel 3 Destination Address Register                                */
    
    struct {
      __IO uint32_t  DAR        : 32;               /*!< (null)                                                                */
    } DAR3_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED28;
  
  union {
    __IO uint32_t  LLP3;                            /*!< Channel 3 Linked List Pointer                                         */
    
    struct {
      __IO uint32_t  LMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOC        : 30;               /*!< (null)                                                                */
    } LLP3_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED29;
  
  union {
    __IO uint32_t  CTL3_L;                          /*!< Channel 3 Control Register Low word                                   */
    
    struct {
      __IO uint32_t  INT_EN     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  SRC_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  DINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  SINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  DEST_MSIZE :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_MSIZE  :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_GATHER_EN:  1;             /*!< (null)                                                                */
      __IO uint32_t  DST_SCATTER_EN:  1;            /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TT_FC      :  3;               /*!< (null)                                                                */
      __IO uint32_t  DMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  SMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LLP_DST_EN :  1;               /*!< (null)                                                                */
      __IO uint32_t  LLP_SRC_EN :  1;               /*!< (null)                                                                */
    } CTL3_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTL3_H;                          /*!< Channel 3 Control Register High word                                  */
    
    struct {
      __IO uint32_t  BLOCK_TS   : 12;               /*!< (null)                                                                */
      __IO uint32_t  DONE       :  1;               /*!< (null)                                                                */
    } CTL3_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SSTAT3;                          /*!< Channel 3 Source Status Register                                      */
    
    struct {
      __IO uint32_t  SSTAT      : 32;               /*!< (null)                                                                */
    } SSTAT3_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED30;
  
  union {
    __IO uint32_t  DSTAT3;                          /*!< Channel 3 Destination Status Register                                 */
    
    struct {
      __IO uint32_t  DSTAT      : 32;               /*!< (null)                                                                */
    } DSTAT3_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED31;
  
  union {
    __IO uint32_t  SSTATAR3;                        /*!< Channel 3 Source Status Address                                       */
    
    struct {
      __IO uint32_t  SSTATAR    : 32;               /*!< (null)                                                                */
    } SSTATAR3_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED32;
  
  union {
    __IO uint32_t  DSTATAR3;                        /*!< Channel 3 Destination Status Address                                  */
    
    struct {
      __IO uint32_t  DSTATAR    : 32;               /*!< (null)                                                                */
    } DSTATAR3_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED33;
  
  union {
    __IO uint32_t  CFG3_L;                          /*!< Channel 3 Configuration Register Low word                             */
    
    struct {
           uint32_t             :  5;
      __IO uint32_t  CH_PRIOR   :  3;               /*!< (null)                                                                */
      __IO uint32_t  CH_SUSP    :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_EMPTY :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_DST :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH_L  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B_L   :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH    :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  MAX_ABRST  : 10;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_DST :  1;               /*!< (null)                                                                */
    } CFG3_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG3_H;                          /*!< Channel 3 Configuration Register High word                            */
    
    struct {
      __IO uint32_t  FCMODE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_MODE  :  1;               /*!< (null)                                                                */
      __IO uint32_t  PROTCTL    :  3;               /*!< (null)                                                                */
      __IO uint32_t  DS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_PER    :  4;               /*!< (null)                                                                */
      __IO uint32_t  DEST_PER   :  4;               /*!< (null)                                                                */
    } CFG3_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SGR3;                            /*!< Channel 3 Source Gather Register                                      */
    
    struct {
      __IO uint32_t  SGI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  SGC        : 12;               /*!< (null)                                                                */
    } SGR3_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED34;
  
  union {
    __IO uint32_t  DSR3;                            /*!< Channel 3 Destination Scatter Register                                */
    
    struct {
      __IO uint32_t  DSI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  DSC        : 12;               /*!< (null)                                                                */
    } DSR3_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED35;
  
  union {
    __IO uint32_t  SAR4;                            /*!< Channel 4 Source Address Register                                     */
    
    struct {
      __IO uint32_t  SAR        : 32;               /*!< (null)                                                                */
    } SAR4_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED36;
  
  union {
    __IO uint32_t  DAR4;                            /*!< Channel 4 Destination Address Register                                */
    
    struct {
      __IO uint32_t  DAR        : 32;               /*!< (null)                                                                */
    } DAR4_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED37;
  
  union {
    __IO uint32_t  LLP4;                            /*!< Channel 4 Linked List Pointer                                         */
    
    struct {
      __IO uint32_t  LMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOC        : 30;               /*!< (null)                                                                */
    } LLP4_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED38;
  
  union {
    __IO uint32_t  CTL4_L;                          /*!< Channel 4 Control Register Low word                                   */
    
    struct {
      __IO uint32_t  INT_EN     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  SRC_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  DINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  SINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  DEST_MSIZE :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_MSIZE  :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_GATHER_EN:  1;             /*!< (null)                                                                */
      __IO uint32_t  DST_SCATTER_EN:  1;            /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TT_FC      :  3;               /*!< (null)                                                                */
      __IO uint32_t  DMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  SMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LLP_DST_EN :  1;               /*!< (null)                                                                */
      __IO uint32_t  LLP_SRC_EN :  1;               /*!< (null)                                                                */
    } CTL4_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTL4_H;                          /*!< Channel 4 Control Register High word                                  */
    
    struct {
      __IO uint32_t  BLOCK_TS   : 12;               /*!< (null)                                                                */
      __IO uint32_t  DONE       :  1;               /*!< (null)                                                                */
    } CTL4_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SSTAT4;                          /*!< Channel 4 Source Status Register                                      */
    
    struct {
      __IO uint32_t  SSTAT      : 32;               /*!< (null)                                                                */
    } SSTAT4_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED39;
  
  union {
    __IO uint32_t  DSTAT4;                          /*!< Channel 4 Destination Status Register                                 */
    
    struct {
      __IO uint32_t  DSTAT      : 32;               /*!< (null)                                                                */
    } DSTAT4_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED40;
  
  union {
    __IO uint32_t  SSTATAR4;                        /*!< Channel 4 Source Status Address                                       */
    
    struct {
      __IO uint32_t  SSTATAR    : 32;               /*!< (null)                                                                */
    } SSTATAR4_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED41;
  
  union {
    __IO uint32_t  DSTATAR4;                        /*!< Channel 4 Destination Status Address                                  */
    
    struct {
      __IO uint32_t  DSTATAR    : 32;               /*!< (null)                                                                */
    } DSTATAR4_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED42;
  
  union {
    __IO uint32_t  CFG4_L;                          /*!< Channel 4 Configuration Register Low word                             */
    
    struct {
           uint32_t             :  5;
      __IO uint32_t  CH_PRIOR   :  3;               /*!< (null)                                                                */
      __IO uint32_t  CH_SUSP    :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_EMPTY :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_DST :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH_L  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B_L   :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH    :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  MAX_ABRST  : 10;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_DST :  1;               /*!< (null)                                                                */
    } CFG4_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG4_H;                          /*!< Channel 4 Configuration Register High word                            */
    
    struct {
      __IO uint32_t  FCMODE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_MODE  :  1;               /*!< (null)                                                                */
      __IO uint32_t  PROTCTL    :  3;               /*!< (null)                                                                */
      __IO uint32_t  DS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_PER    :  4;               /*!< (null)                                                                */
      __IO uint32_t  DEST_PER   :  4;               /*!< (null)                                                                */
    } CFG4_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SGR4;                            /*!< Channel 4 Source Gather Register                                      */
    
    struct {
      __IO uint32_t  SGI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  SGC        : 12;               /*!< (null)                                                                */
    } SGR4_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED43;
  
  union {
    __IO uint32_t  DSR4;                            /*!< Channel 4 Destination Scatter Register                                */
    
    struct {
      __IO uint32_t  DSI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  DSC        : 12;               /*!< (null)                                                                */
    } DSR4_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED44;
  
  union {
    __IO uint32_t  SAR5;                            /*!< Channel 5 Source Address Register                                     */
    
    struct {
      __IO uint32_t  SAR        : 32;               /*!< (null)                                                                */
    } SAR5_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED45;
  
  union {
    __IO uint32_t  DAR5;                            /*!< Channel 5 Destination Address Register                                */
    
    struct {
      __IO uint32_t  DAR        : 32;               /*!< (null)                                                                */
    } DAR5_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED46;
  
  union {
    __IO uint32_t  LLP5;                            /*!< Channel 5 Linked List Pointer                                         */
    
    struct {
      __IO uint32_t  LMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOC        : 30;               /*!< (null)                                                                */
    } LLP5_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED47;
  
  union {
    __IO uint32_t  CTL5_L;                          /*!< Channel 5 Control Register Low word                                   */
    
    struct {
      __IO uint32_t  INT_EN     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  SRC_TR_WIDTH:  3;              /*!< (null)                                                                */
      __IO uint32_t  DINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  SINC       :  2;               /*!< (null)                                                                */
      __IO uint32_t  DEST_MSIZE :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_MSIZE  :  3;               /*!< (null)                                                                */
      __IO uint32_t  SRC_GATHER_EN:  1;             /*!< (null)                                                                */
      __IO uint32_t  DST_SCATTER_EN:  1;            /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  TT_FC      :  3;               /*!< (null)                                                                */
      __IO uint32_t  DMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  SMS        :  2;               /*!< (null)                                                                */
      __IO uint32_t  LLP_DST_EN :  1;               /*!< (null)                                                                */
      __IO uint32_t  LLP_SRC_EN :  1;               /*!< (null)                                                                */
    } CTL5_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CTL5_H;                          /*!< Channel 5 Control Register High word                                  */
    
    struct {
      __IO uint32_t  BLOCK_TS   : 12;               /*!< (null)                                                                */
      __IO uint32_t  DONE       :  1;               /*!< (null)                                                                */
    } CTL5_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SSTAT5;                          /*!< Channel 5 Source Status Register                                      */
    
    struct {
      __IO uint32_t  SSTAT      : 32;               /*!< (null)                                                                */
    } SSTAT5_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED48;
  
  union {
    __IO uint32_t  DSTAT5;                          /*!< Channel 5 Destination Status Register                                 */
    
    struct {
      __IO uint32_t  DSTAT      : 32;               /*!< (null)                                                                */
    } DSTAT5_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED49;
  
  union {
    __IO uint32_t  SSTATAR5;                        /*!< Channel 5 Source Status Address                                       */
    
    struct {
      __IO uint32_t  SSTATAR    : 32;               /*!< (null)                                                                */
    } SSTATAR5_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED50;
  
  union {
    __IO uint32_t  DSTATAR5;                        /*!< Channel 5 Destination Status Address                                  */
    
    struct {
      __IO uint32_t  DSTATAR    : 32;               /*!< (null)                                                                */
    } DSTATAR5_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED51;
  
  union {
    __IO uint32_t  CFG5_L;                          /*!< Channel 5 Configuration Register Low word                             */
    
    struct {
           uint32_t             :  5;
      __IO uint32_t  CH_PRIOR   :  3;               /*!< (null)                                                                */
      __IO uint32_t  CH_SUSP    :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_EMPTY :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_DST :  1;               /*!< (null)                                                                */
      __IO uint32_t  HS_SEL_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH_L  :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B_L   :  2;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_CH    :  1;               /*!< (null)                                                                */
      __IO uint32_t  LOCK_B     :  1;               /*!< (null)                                                                */
      __IO uint32_t  DST_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_HS_POL :  1;               /*!< (null)                                                                */
      __IO uint32_t  MAX_ABRST  : 10;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_SRC :  1;               /*!< (null)                                                                */
      __IO uint32_t  RELOAD_DST :  1;               /*!< (null)                                                                */
    } CFG5_L_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG5_H;                          /*!< Channel 5 Configuration Register High word                            */
    
    struct {
      __IO uint32_t  FCMODE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  FIFO_MODE  :  1;               /*!< (null)                                                                */
      __IO uint32_t  PROTCTL    :  3;               /*!< (null)                                                                */
      __IO uint32_t  DS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SS_UPD_EN  :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRC_PER    :  4;               /*!< (null)                                                                */
      __IO uint32_t  DEST_PER   :  4;               /*!< (null)                                                                */
    } CFG5_H_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SGR5;                            /*!< Channel 5 Source Gather Register                                      */
    
    struct {
      __IO uint32_t  SGI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  SGC        : 12;               /*!< (null)                                                                */
    } SGR5_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED52;
  
  union {
    __IO uint32_t  DSR5;                            /*!< Channel 5 Destination Scatter Register                                */
    
    struct {
      __IO uint32_t  DSI        : 20;               /*!< (null)                                                                */
      __IO uint32_t  DSC        : 12;               /*!< (null)                                                                */
    } DSR5_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED53[45];
  
  union {
    __I  uint32_t  RawTfr;                          /*!< Raw Status for IntTfr Interrupt                                       */
    
    struct {
      __IO uint32_t  RAW        :  8;               /*!< (null)                                                                */
    } RawTfr_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED54;
  
  union {
    __I  uint32_t  RawBlock;                        /*!< Raw Status for IntBlock Interrupt                                     */
    
    struct {
      __IO uint32_t  RAW        :  8;               /*!< (null)                                                                */
    } RawBlock_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED55;
  
  union {
    __I  uint32_t  RawSrcTran;                      /*!< Raw Status for IntSrcTran Interrupt                                   */
    
    struct {
      __IO uint32_t  RAW        :  8;               /*!< (null)                                                                */
    } RawSrcTran_b;                                 /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED56;
  
  union {
    __I  uint32_t  RawDstTran;                      /*!< Raw Status for IntDstTran Interrupt                                   */
    
    struct {
      __IO uint32_t  RAW        :  8;               /*!< (null)                                                                */
    } RawDstTran_b;                                 /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED57;
  
  union {
    __I  uint32_t  RawErr;                          /*!< Raw Status for IntErr Interrupt                                       */
    
    struct {
      __IO uint32_t  RAW        :  8;               /*!< (null)                                                                */
    } RawErr_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED58;
  
  union {
    __I  uint32_t  StatusTfr;                       /*!< Status for IntTfr Interrupt                                           */
    
    struct {
      __I  uint32_t  STATUS     :  8;               /*!< (null)                                                                */
    } StatusTfr_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED59;
  
  union {
    __I  uint32_t  StatusBlock;                     /*!< Status for IntBlock Interrupt                                         */
    
    struct {
      __I  uint32_t  STATUS     :  8;               /*!< (null)                                                                */
    } StatusBlock_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED60;
  
  union {
    __I  uint32_t  StatusSrcTran;                   /*!< Status for IntSrcTran Interrupt                                       */
    
    struct {
      __I  uint32_t  STATUS     :  8;               /*!< (null)                                                                */
    } StatusSrcTran_b;                              /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED61;
  
  union {
    __I  uint32_t  StatusDstTran;                   /*!< Status for IntDstTran Interrupt                                       */
    
    struct {
      __I  uint32_t  STATUS     :  8;               /*!< (null)                                                                */
    } StatusDstTran_b;                              /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED62;
  
  union {
    __I  uint32_t  StatusErr;                       /*!< Status for IntErr Interrupt                                           */
    
    struct {
      __I  uint32_t  STATUS     :  8;               /*!< (null)                                                                */
    } StatusErr_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED63;
  
  union {
    __IO uint32_t  MaskTfr;                         /*!< Mask for IntTfr Interrupt                                             */
    
    struct {
      __IO uint32_t  INT_MASK   :  8;               /*!< (null)                                                                */
      __O  uint32_t  INT_MASK_WE:  8;               /*!< (null)                                                                */
    } MaskTfr_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED64;
  
  union {
    __IO uint32_t  MaskBlock;                       /*!< Mask for IntBlock Interrupt                                           */
    
    struct {
      __IO uint32_t  INT_MASK   :  8;               /*!< (null)                                                                */
      __O  uint32_t  INT_MASK_WE:  8;               /*!< (null)                                                                */
    } MaskBlock_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED65;
  
  union {
    __IO uint32_t  MaskSrcTran;                     /*!< Mask for IntSrcTran Interrupt                                         */
    
    struct {
      __IO uint32_t  INT_MASK   :  8;               /*!< (null)                                                                */
      __O  uint32_t  INT_MASK_WE:  8;               /*!< (null)                                                                */
    } MaskSrcTran_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED66;
  
  union {
    __IO uint32_t  MaskDstTran;                     /*!< Mask for IntDstTran Interrupt                                         */
    
    struct {
      __IO uint32_t  INT_MASK   :  8;               /*!< (null)                                                                */
      __O  uint32_t  INT_MASK_WE:  8;               /*!< (null)                                                                */
    } MaskDstTran_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED67;
  
  union {
    __IO uint32_t  MaskErr;                         /*!< Mask for IntErr Interrupt                                             */
    
    struct {
      __IO uint32_t  INT_MASK   :  8;               /*!< (null)                                                                */
      __O  uint32_t  INT_MASK_WE:  8;               /*!< (null)                                                                */
    } MaskErr_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED68;
  
  union {
    __O  uint32_t  ClearTfr;                        /*!< Clear for IntTfr Interrupt                                            */
    
    struct {
      __O  uint32_t  CLEAR      :  8;               /*!< (null)                                                                */
    } ClearTfr_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED69;
  
  union {
    __O  uint32_t  ClearBlock;                      /*!< Clear for IntBlock Interrupt                                          */
    
    struct {
      __O  uint32_t  CLEAR      :  8;               /*!< (null)                                                                */
    } ClearBlock_b;                                 /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED70;
  
  union {
    __O  uint32_t  ClearSrcTran;                    /*!< Clear for IntSrcTran Interrupt                                        */
    
    struct {
      __O  uint32_t  CLEAR      :  8;               /*!< (null)                                                                */
    } ClearSrcTran_b;                               /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED71;
  
  union {
    __O  uint32_t  ClearDstTran;                    /*!< Clear for IntDstTran Interrupt                                        */
    
    struct {
      __O  uint32_t  CLEAR      :  8;               /*!< (null)                                                                */
    } ClearDstTran_b;                               /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED72;
  
  union {
    __O  uint32_t  ClearErr;                        /*!< Clear for IntErr Interrupt                                            */
    
    struct {
      __O  uint32_t  CLEAR      :  8;               /*!< (null)                                                                */
    } ClearErr_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED73;
  
  union {
    __O  uint32_t  StatusInt;                       /*!< Status for each interrupt type                                        */
    
    struct {
      __I  uint32_t  TFR        :  1;               /*!< (null)                                                                */
      __I  uint32_t  BLOCK      :  1;               /*!< (null)                                                                */
      __I  uint32_t  SRCT       :  1;               /*!< (null)                                                                */
      __I  uint32_t  DSTT       :  1;               /*!< (null)                                                                */
      __I  uint32_t  ERR        :  1;               /*!< (null)                                                                */
    } StatusInt_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED74;
  
  union {
    __IO uint32_t  ReqSrcReg;                       /*!< Source Software Transaction Request Register                          */
    
    struct {
      __IO uint32_t  SRC_REQ    :  8;               /*!< (null)                                                                */
      __O  uint32_t  SRC_REQ_WE :  8;               /*!< (null)                                                                */
    } ReqSrcReg_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED75;
  
  union {
    __IO uint32_t  ReqDstReg;                       /*!< Destination SoftwareTransaction Request Register                      */
    
    struct {
      __IO uint32_t  DST_REQ    :  8;               /*!< (null)                                                                */
      __O  uint32_t  DST_REQ_WE :  8;               /*!< (null)                                                                */
    } ReqDstReg_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED76;
  
  union {
    __IO uint32_t  SglReqSrcReg;                    /*!< Single Source Transaction Request Register                            */
    
    struct {
      __IO uint32_t  SRC_SGLREQ :  8;               /*!< (null)                                                                */
      __O  uint32_t  SRC_SGLREQ_WE:  8;             /*!< (null)                                                                */
    } SglReqSrcReg_b;                               /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED77;
  
  union {
    __IO uint32_t  SglReqDstReg;                    /*!< Single Destination Transaction Request Register                       */
    
    struct {
      __IO uint32_t  DST_SGLREQ :  8;               /*!< (null)                                                                */
      __O  uint32_t  DST_SGLREQ_WE:  8;             /*!< (null)                                                                */
    } SglReqDstReg_b;                               /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED78;
  
  union {
    __IO uint32_t  LstSrcReg;                       /*!< Last Source Transaction Request Register                              */
    
    struct {
      __IO uint32_t  LSTSRC     :  8;               /*!< (null)                                                                */
      __O  uint32_t  LSTSRC_WE  :  8;               /*!< (null)                                                                */
    } LstSrcReg_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED79;
  
  union {
    __IO uint32_t  LstDstReg;                       /*!< Last Destination Transaction Request Register                         */
    
    struct {
      __IO uint32_t  LSTDST     :  8;               /*!< (null)                                                                */
      __O  uint32_t  LSTDST_WE  :  8;               /*!< (null)                                                                */
    } LstDstReg_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED80;
  
  union {
    __IO uint32_t  DmaCfgReg;                       /*!< DMA Configuration Register                                            */
    
    struct {
      __IO uint32_t  DMA_EN     :  1;               /*!< (null)                                                                */
    } DmaCfgReg_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED81;
  
  union {
    __IO uint32_t  ChEnReg;                         /*!< DMA Channel Enable Register                                           */
    
    struct {
      __IO uint32_t  CH_EN      :  8;               /*!< (null)                                                                */
      __O  uint32_t  CH_EN_WE   :  8;               /*!< (null)                                                                */
    } ChEnReg_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED82;
  
  union {
    __I  uint32_t  DmaIdReg;                        /*!< DMA ID Register                                                       */
    
    struct {
      __I  uint32_t  DMA_ID     : 32;               /*!< (null)                                                                */
    } DmaIdReg_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED83;
  
  union {
    __IO uint32_t  DmaTestReg;                      /*!< DMA Test Register                                                     */
    
    struct {
      __IO uint32_t  TEST_SLV_IF:  1;               /*!< (null)                                                                */
    } DmaTestReg_b;                                 /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED84[8];
  
  union {
    __I  uint32_t  DMA_COMP_PARAMS_5_H;             /*!< dmac Component Parameters Register 5 High word                        */
    
    struct {
      __I  uint32_t  CH5_DTW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH5_STW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH5_STAT_DST:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH5_STAT_SRC:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH5_DST_SCA_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH5_SRC_GAT_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH5_LOCK_EN:  1;               /*!< (null)                                                                */
      __I  uint32_t  CH5_MULTI_BLK_EN:  1;          /*!< (null)                                                                */
      __I  uint32_t  CH5_CTL_WB_EN:  1;             /*!< (null)                                                                */
      __I  uint32_t  CH5_HC_LLP :  1;               /*!< (null)                                                                */
      __I  uint32_t  CH5_FC     :  2;               /*!< (null)                                                                */
      __I  uint32_t  CH5_MAX_MULT_SIZE:  3;         /*!< (null)                                                                */
      __I  uint32_t  CH5_DMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH5_LMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH5_SMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH5_FIFO_DEPTH:  3;            /*!< (null)                                                                */
    } DMA_COMP_PARAMS_5_H_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_COMP_PARAMS_4_L;             /*!< dmac Component Parameters Register 4 Low word                         */
    
    struct {
      __I  uint32_t  CH4_DTW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH4_STW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH4_STAT_DST:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH4_STAT_SRC:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH4_DST_SCA_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH4_SRC_GAT_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH4_LOCK_EN:  1;               /*!< (null)                                                                */
      __I  uint32_t  CH4_MULTI_BLK_EN:  1;          /*!< (null)                                                                */
      __I  uint32_t  CH4_CTL_WB_EN:  1;             /*!< (null)                                                                */
      __I  uint32_t  CH4_HC_LLP :  1;               /*!< (null)                                                                */
      __I  uint32_t  CH4_FC     :  2;               /*!< (null)                                                                */
      __I  uint32_t  CH4_MAX_MULT_SIZE:  3;         /*!< (null)                                                                */
      __I  uint32_t  CH4_DMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH4_LMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH4_SMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH4_FIFO_DEPTH:  3;            /*!< (null)                                                                */
    } DMA_COMP_PARAMS_4_L_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_COMP_PARAMS_4_H;             /*!< dmac Component Parameters Register 4 High word                        */
    
    struct {
      __I  uint32_t  CH3_DTW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH3_STW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH3_STAT_DST:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH3_STAT_SRC:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH3_DST_SCA_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH3_SRC_GAT_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH3_LOCK_EN:  1;               /*!< (null)                                                                */
      __I  uint32_t  CH3_MULTI_BLK_EN:  1;          /*!< (null)                                                                */
      __I  uint32_t  CH3_CTL_WB_EN:  1;             /*!< (null)                                                                */
      __I  uint32_t  CH3_HC_LLP :  1;               /*!< (null)                                                                */
      __I  uint32_t  CH3_FC     :  2;               /*!< (null)                                                                */
      __I  uint32_t  CH3_MAX_MULT_SIZE:  3;         /*!< (null)                                                                */
      __I  uint32_t  CH3_DMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH3_LMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH3_SMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH3_FIFO_DEPTH:  3;            /*!< (null)                                                                */
    } DMA_COMP_PARAMS_4_H_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_COMP_PARAMS_3;               /*!< dmac Component Parameters Register 3 Low Word                         */
    
    struct {
      __I  uint32_t  CH2_DTW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH2_STW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH2_STAT_DST:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH2_STAT_SRC:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH2_DST_SCA_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH2_SRC_GAT_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH2_LOCK_EN:  1;               /*!< (null)                                                                */
      __I  uint32_t  CH2_MULTI_BLK_EN:  1;          /*!< (null)                                                                */
      __I  uint32_t  CH2_CTL_WB_EN:  1;             /*!< (null)                                                                */
      __I  uint32_t  CH2_HC_LLP :  1;               /*!< (null)                                                                */
      __I  uint32_t  CH2_FC     :  2;               /*!< (null)                                                                */
      __I  uint32_t  CH2_MAX_MULT_SIZE:  3;         /*!< (null)                                                                */
      __I  uint32_t  CH2_DMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH2_LMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH2_SMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH2_FIFO_DEPTH:  3;            /*!< (null)                                                                */
    } DMA_COMP_PARAMS_3_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_COMP_PARAMS_3_H;             /*!< dmac Component Parameters Register 3 High word                        */
    
    struct {
      __I  uint32_t  CH1_DTW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH1_STW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH1_STAT_DST:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH1_STAT_SRC:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH1_DST_SCA_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH1_SRC_GAT_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH1_LOCK_EN:  1;               /*!< (null)                                                                */
      __I  uint32_t  CH1_MULTI_BLK_EN:  1;          /*!< (null)                                                                */
      __I  uint32_t  CH1_CTL_WB_EN:  1;             /*!< (null)                                                                */
      __I  uint32_t  CH1_HC_LLP :  1;               /*!< (null)                                                                */
      __I  uint32_t  CH1_FC     :  2;               /*!< (null)                                                                */
      __I  uint32_t  CH1_MAX_MULT_SIZE:  3;         /*!< (null)                                                                */
      __I  uint32_t  CH1_DMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH1_LMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH1_SMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH1_FIFO_DEPTH:  3;            /*!< (null)                                                                */
    } DMA_COMP_PARAMS_3_H_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_COMP_PARAMS_2;               /*!< dmac Component Parameters Register 2 Low Word                         */
    
    struct {
      __I  uint32_t  CH0_DTW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH0_STW    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH0_STAT_DST:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH0_STAT_SRC:  1;              /*!< (null)                                                                */
      __I  uint32_t  CH0_DST_SCA_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH0_SRC_GAT_EN:  1;            /*!< (null)                                                                */
      __I  uint32_t  CH0_LOCK_EN:  1;               /*!< (null)                                                                */
      __I  uint32_t  CH0_MULTI_BLK_EN:  1;          /*!< (null)                                                                */
      __I  uint32_t  CH0_CTL_WB_EN:  1;             /*!< (null)                                                                */
      __I  uint32_t  CH0_HC_LLP :  1;               /*!< (null)                                                                */
      __I  uint32_t  CH0_FC     :  2;               /*!< (null)                                                                */
      __I  uint32_t  CH0_MAX_MULT_SIZE:  3;         /*!< (null)                                                                */
      __I  uint32_t  CH0_DMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH0_LMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH0_SMS    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CH0_FIFO_DEPTH:  3;            /*!< (null)                                                                */
    } DMA_COMP_PARAMS_2_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_COMP_PARAMS_2_H;             /*!< dmac Component Parameters Register 2 High word                        */
    
    struct {
      __I  uint32_t  CH0_MULTI_BLK_TYPE:  4;        /*!< (null)                                                                */
      __I  uint32_t  CH1_MULTI_BLK_TYPE:  4;        /*!< (null)                                                                */
      __I  uint32_t  CH2_MULTI_BLK_TYPE:  4;        /*!< (null)                                                                */
      __I  uint32_t  CH3_MULTI_BLK_TYPE:  4;        /*!< (null)                                                                */
      __I  uint32_t  CH4_MULTI_BLK_TYPE:  4;        /*!< (null)                                                                */
      __I  uint32_t  CH5_MULTI_BLK_TYPE:  4;        /*!< (null)                                                                */
      __I  uint32_t  CH6_MULTI_BLK_TYPE:  4;        /*!< (null)                                                                */
      __I  uint32_t  CH7_MULTI_BLK_TYPE:  4;        /*!< (null)                                                                */
    } DMA_COMP_PARAMS_2_H_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_COMP_PARAMS_1_L;             /*!< dmac Component Parameters Register 1 Low word                         */
    
    struct {
      __I  uint32_t  CH0_MAX_BLK_SIZE:  4;          /*!< (null)                                                                */
      __I  uint32_t  CH1_MAX_BLK_SIZE:  4;          /*!< (null)                                                                */
      __I  uint32_t  CH2_MAX_BLK_SIZE:  4;          /*!< (null)                                                                */
      __I  uint32_t  CH3_MAX_BLK_SIZE:  4;          /*!< (null)                                                                */
      __I  uint32_t  CH4_MAX_BLK_SIZE:  4;          /*!< (null)                                                                */
      __I  uint32_t  CH5_MAX_BLK_SIZE:  4;          /*!< (null)                                                                */
    } DMA_COMP_PARAMS_1_L_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_COMP_PARAMS_1_H;             /*!< dmac Component Parameters Register 1 High word                        */
    
    struct {
      __I  uint32_t  BIG_ENDIAN :  1;               /*!< (null)                                                                */
      __I  uint32_t  INTR_IO    :  2;               /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  MABRST     :  4;               /*!< (null)                                                                */
      __I  uint32_t  NUM_CHANNELS:  3;              /*!< (null)                                                                */
      __I  uint32_t  NUM_MASTER_INT:  2;            /*!< (null)                                                                */
      __I  uint32_t  S_HDATA_WIDTH:  2;             /*!< (null)                                                                */
      __I  uint32_t  M1_HDATA_WIDTH:  2;            /*!< (null)                                                                */
      __I  uint32_t  M2_HDATA_WIDTH:  2;            /*!< (null)                                                                */
      __I  uint32_t  M3_HDATA_WIDTH:  2;            /*!< (null)                                                                */
      __I  uint32_t  M4_HDATA_WIDTH:  2;            /*!< (null)                                                                */
      __I  uint32_t  NUM_HS_INT :  5;               /*!< (null)                                                                */
      __I  uint32_t  ADD_ENCODED_PARAMS:  1;        /*!< (null)                                                                */
      __I  uint32_t  STATIC_ENDIAN_SELECT:  1;      /*!< Component version register                                            */
    } DMA_COMP_PARAMS_1_H_b;                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_Component_ID_L;              /*!< DMA Component ID Register Low word                                    */
    
    struct {
      __I  uint32_t  DMA_COMP_TYPE: 32;             /*!< (null)                                                                */
    } DMA_Component_ID_L_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMA_Component_ID_H;              /*!< DMA Component ID Register High word                                   */
    
    struct {
      __I  uint32_t  DMA_COMP_VERSION: 32;          /*!< (null)                                                                */
    } DMA_Component_ID_H_b;                         /*!< BitSize                                                               */
  };
} DMAC_Type;


/* ================================================================================ */
/* ================                     SFLASH                     ================ */
/* ================================================================================ */


/**
  * @brief Serial Flash Interface (SFLASH)
  */
typedef struct
{
  __I  uint32_t INTR_STATUS;
  __IO uint32_t RAW_INTR_STATUS;
  __IO uint32_t INTR_MASK;
  __IO uint32_t COMMAND;
  __IO uint32_t COMMAND_DATA0_REG;
  __IO uint32_t COMMAND_DATA1_REG;
  __IO uint32_t READ0_REG;
  __IO uint32_t READ1_REG;
  __IO uint32_t ADDRESS_REG;
  __IO uint32_t READ_OPCODE_REG;
  __IO uint32_t CONFIGURATION_0;
  __IO uint32_t CS_CONFIGURATION_0;
  __IO uint32_t CONFIGURATION_1;
  __IO uint32_t CS_CONFIGURATION_1;
  __IO uint32_t CONFIGURATION_2;
  __IO uint32_t CS_CONFIGURATION_2;
  __IO uint32_t CONFIGURATION_3;
  __IO uint32_t CS_CONFIGURATION_3;
} SFLASH_Type;


/* ================================================================================ */
/* ================                      GPIO0                     ================ */
/* ================================================================================ */


/**
  * @brief GPIO0 Controller (GPIO0)
  */

typedef struct {                                    /*!< GPIO0 Structure                                                       */
  
  union {
    __IO uint16_t  DATA;                            /*!< Data value [15:0]                                                     */
    
    struct {
      __IO uint16_t  data       : 16;               /*!< (null)                                                                */
    } DATA_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED0;
  
  union {
    __IO uint16_t  DATAOUT;                         /*!< Data output Register value [15:0]                                     */
    
    struct {
      __IO uint16_t  data_output: 16;               /*!< (null)                                                                */
    } DATAOUT_b;                                    /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED1[5];
  
  union {
    __IO uint16_t  OUTENSET;                        /*!< Output enable set [15:0]                                              */
    
    struct {
      __IO uint16_t  out_enable : 16;               /*!< (null)                                                                */
    } OUTENSET_b;                                   /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED2;
  
  union {
    __IO uint16_t  OUTENCLR;                        /*!< Output enable clear [15:0]                                            */
    
    struct {
      __IO uint16_t  outen_clr  : 16;               /*!< (null)                                                                */
    } OUTENCLR_b;                                   /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED3;
  
  union {
    __IO uint16_t  ALTFUNCSET;                      /*!< Alternative function set [15:0]                                       */
    
    struct {
      __IO uint16_t  ALTFUNC_set: 16;               /*!< (null)                                                                */
    } ALTFUNCSET_b;                                 /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED4;
  
  union {
    __IO uint16_t  ALTFUNCCLR;                      /*!< Alternative function clear [15:0]                                     */
    
    struct {
      __IO uint16_t  ALTFUNC_clr: 16;               /*!< (null)                                                                */
    } ALTFUNCCLR_b;                                 /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED5;
  
  union {
    __IO uint16_t  INTENSET;                        /*!< Interrupt enable set [15:0]                                           */
    
    struct {
      __IO uint16_t  Int_en_set : 16;               /*!< (null)                                                                */
    } INTENSET_b;                                   /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED6;
  
  union {
    __IO uint16_t  INTENCLR;                        /*!< Interrupt enable clear [15:0]                                         */
    
    struct {
      __IO uint16_t  Int_en_clr : 16;               /*!< (null)                                                                */
    } INTENCLR_b;                                   /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED7;
  
  union {
    __IO uint16_t  INTTYPESET;                      /*!< Interrupt type set [15:0]                                             */
    
    struct {
      __IO uint16_t  Int_type_set: 16;              /*!< (null)                                                                */
    } INTTYPESET_b;                                 /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED8;
  
  union {
    __IO uint16_t  INTTYPECLR;                      /*!< Interrupt type clear [15:0]                                           */
    
    struct {
      __IO uint16_t  Int_type_clr: 16;              /*!< (null)                                                                */
    } INTTYPECLR_b;                                 /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED9;
  
  union {
    __IO uint16_t  INTPOLSET;                       /*!< "Polarity-level," edge IRQ configuration [15:0]                       */
    
    struct {
      __IO uint16_t  Int_polarity_set: 16;          /*!< (null)                                                                */
    } INTPOLSET_b;                                  /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED10;
  
  union {
    __IO uint16_t  INTPOLCLR;                       /*!< "Polarity-level," edge IRQ configuration [15:0]                       */
    
    struct {
      __IO uint16_t  Int_polarity_clr: 16;          /*!< (null)                                                                */
    } INTPOLCLR_b;                                  /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED11;
  
  union {
    __IO uint16_t  INTSTATUS;                       /*!< Write one to clear interrupt request:                                 */
    
    struct {
      __IO uint16_t  Int_status : 16;               /*!< (null)                                                                */
    } INTSTATUS_b;                                  /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED12[1995];
  
  union {
    __I  uint8_t   PID4;                            /*!< Peripheral ID Register 4:00                                           */
    
    struct {
      __I  uint8_t   jep106_c_code:  4;             /*!< (null)                                                                */
      __I  uint8_t   block_count:  4;               /*!< (null)                                                                */
    } PID4_b;                                       /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED13[15];
  
  union {
    __I  uint8_t   PID0;                            /*!< Peripheral ID Register 0:00                                           */
    
    struct {
      __I  uint8_t   part_number__7_0:  8;          /*!< (null)                                                                */
    } PID0_b;                                       /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED14[3];
  
  union {
    __I  uint8_t   PID1;                            /*!< Peripheral ID Register 1:00                                           */
    
    struct {
      __I  uint8_t   part_number__11_8:  4;         /*!< (null)                                                                */
      __I  uint8_t   jep106_id_3_0:  4;             /*!< (null)                                                                */
    } PID1_b;                                       /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED15[3];
  
  union {
    __I  uint8_t   PID2;                            /*!< Peripheral ID Register 2:00                                           */
    
    struct {
      __I  uint8_t   jep106_id_6_4:  3;             /*!< (null)                                                                */
      __I  uint8_t   jedec_used :  1;               /*!< (null)                                                                */
      __I  uint8_t   Revision   :  4;               /*!< (null)                                                                */
    } PID2_b;                                       /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED16[3];
  
  union {
    __I  uint8_t   PID3;                            /*!< Peripheral ID Register 3:00                                           */
    
    struct {
      __I  uint8_t   ECO_revision:  4;              /*!< (null)                                                                */
      __I  uint8_t   custom_modify_no:  4;          /*!< (null)                                                                */
    } PID3_b;                                       /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED17[3];
  
  union {
    __I  uint8_t   CID0;                            /*!< Component ID Register 0                                               */
    
    struct {
      __I  uint8_t   component_ID_0:  8;            /*!< (null)                                                                */
    } CID0_b;                                       /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED18[3];
  
  union {
    __I  uint8_t   CID1;                            /*!< Component ID Register 1                                               */
    
    struct {
      __I  uint8_t   component_ID_1:  8;            /*!< (null)                                                                */
    } CID1_b;                                       /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED19[3];
  
  union {
    __I  uint8_t   CID2;                            /*!< Component ID Register 2                                               */
    
    struct {
      __I  uint8_t   component_ID_2:  8;            /*!< (null)                                                                */
    } CID2_b;                                       /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED20[3];
  
  union {
    __I  uint8_t   CID3;                            /*!< Component ID Register 3                                               */
    
    struct {
      __I  uint8_t   component_ID_3:  8;            /*!< (null)                                                                */
    } CID3_b;                                       /*!< BitSize                                                               */
  };
} GPIO_Type;


/* ================================================================================ */
/* ================                  USB_PERIPH_0                  ================ */
/* ================================================================================ */


/**
  * @brief USB DEVICE OTG Controller (USB_PERIPH_0)
  */

typedef struct {                                    /*!< USB_PERIPH_0 Structure                                                */
  
  union {
    __IO uint8_t   FAddr;                           /*!< Function address register                                             */
    
    struct {
      __IO uint8_t   Func_Addr  :  7;               /*!< (null)                                                                */
    } FAddr_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint8_t   Power;                           /*!< Power management register                                             */
    
    struct {
      __IO uint8_t   Enable_Suspend:  1;            /*!< (null)                                                                */
      __IO uint8_t   Suspend_Mode:  1;              /*!< (null)                                                                */
      __IO uint8_t   Resume     :  1;               /*!< (null)                                                                */
      __IO uint8_t   Reset      :  1;               /*!< (null)                                                                */
      __I  uint8_t   Vbus_Lo    :  1;               /*!< (null)                                                                */
      __I  uint8_t   Vbus_Sess  :  1;               /*!< (null)                                                                */
      __I  uint8_t   Vbus_Val   :  1;               /*!< (null)                                                                */
      __IO uint8_t   ISO_Update :  1;               /*!< (null)                                                                */
    } Power_b;                                      /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED0;
  __I  uint8_t   RESERVED1;
  
  union {
    __IO uint8_t   IntrTx1E;                        /*!< Interrupt enable register for IntrTx1                                 */
    
    struct {
      __IO uint8_t   EP0        :  1;               /*!< (null)                                                                */
      __IO uint8_t   EP1        :  1;               /*!< (null)                                                                */
      __IO uint8_t   EP2        :  1;               /*!< (null)                                                                */
      __IO uint8_t   EP3        :  1;               /*!< (null)                                                                */
    } IntrTx1E_b;                                   /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED2;
  __I  uint8_t   RESERVED3;
  
  union {
    __IO uint8_t   IntrRx1E;                        /*!< Interrupt enable register for IntrRx1                                 */
    
    struct {
           uint8_t              :  1;
      __IO uint8_t   EP1        :  1;               /*!< (null)                                                                */
      __IO uint8_t   EP2        :  1;               /*!< (null)                                                                */
      __IO uint8_t   EP3        :  1;               /*!< (null)                                                                */
    } IntrRx1E_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint8_t   IntrUSBE;                        /*!< Interrupt enable register for IntrUSB                                 */
    
    struct {
      __IO uint8_t   Suspend    :  1;               /*!< (null)                                                                */
      __IO uint8_t   Resume     :  1;               /*!< (null)                                                                */
      __IO uint8_t   Reset_Babble:  1;              /*!< (null)                                                                */
      __IO uint8_t   SOF        :  1;               /*!< (null)                                                                */
      __IO uint8_t   Conn       :  1;               /*!< (null)                                                                */
      __IO uint8_t   Discon     :  1;               /*!< (null)                                                                */
      __IO uint8_t   Sess_Req   :  1;               /*!< (null)                                                                */
      __IO uint8_t   Vbus_Error :  1;               /*!< (null)                                                                */
    } IntrUSBE_b;                                   /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED4[1];
  
  union {
    __I  uint8_t   Frame1;                          /*!< Frame number bits 0 to 7                                              */
    
    struct {
      __I  uint8_t   FRAME_NUM_L:  8;               /*!< (null)                                                                */
    } Frame1_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint8_t   Frame2;                          /*!< Frame number bits 8 to 10                                             */
    
    struct {
      __I  uint8_t   FRAME_NUM_H:  3;               /*!< (null)                                                                */
    } Frame2_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint8_t   Index;                           /*!< Index register for selecting the endpoint status and control
                                                         registers                                                             */
    
    struct {
      __IO uint8_t   SEL_ENDPOINT:  4;              /*!< (null)                                                                */
    } Index_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint8_t   DevCtl;                          /*!< USB device control register                                           */
    
    struct {
      __IO uint8_t   Session    :  1;               /*!< (null)                                                                */
      __IO uint8_t   Host_Req   :  1;               /*!< (null)                                                                */
      __I  uint8_t   Host_Mode  :  1;               /*!< (null)                                                                */
      __I  uint8_t   PDCON      :  1;               /*!< (null)                                                                */
      __I  uint8_t   PUCON      :  1;               /*!< (null)                                                                */
      __I  uint8_t   LSDev      :  1;               /*!< (null)                                                                */
      __I  uint8_t   FSDev      :  1;               /*!< (null)                                                                */
      __I  uint8_t   CID        :  1;               /*!< (null)                                                                */
    } DevCtl_b;                                     /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED5;
  
  union {
    __IO uint8_t   CSR0;                            /*!< Main Control Status register for Endpoint 0                           */
    
    struct {
      __I  uint8_t   RxPktRdy   :  1;               /*!< (null)                                                                */
      __IO uint8_t   TxPktRdy   :  1;               /*!< (null)                                                                */
      __IO uint8_t   SentStall  :  1;               /*!< (null)                                                                */
      __IO uint8_t   DataEnd    :  1;               /*!< (null)                                                                */
      __I  uint8_t   SetupEnd   :  1;               /*!< (null)                                                                */
      __IO uint8_t   SendStall  :  1;               /*!< (null)                                                                */
      __IO uint8_t   ServicedRxPktRdy:  1;          /*!< (null)                                                                */
      __IO uint8_t   ServicedSetupEnd:  1;          /*!< (null)                                                                */
    } CSR0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint8_t   CSR02;                           /*!< Subsidiary Control Status register for Endpoint 0                     */
    
    struct {
      __O  uint8_t   FlushFIFO  :  1;               /*!< (null)                                                                */
    } CSR02_b;                                      /*!< BitSize                                                               */
  };
  __I  uint8_t   RESERVED6[1];
  __I  uint8_t   RESERVED7;
  
  union {
    __I  uint8_t   Count0;                          /*!< Number of received bytes in Endpoint 0 FIFO                           */
    
    struct {
      __I  uint8_t   Endpoint_0_Count:  8;          /*!< (null)                                                                */
    } Count0_b;                                     /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED8[3];
  
  union {
    __I  uint8_t   TxFIFO1;                         /*!< the start address AD7~0 of Tx endpoint FIFO                           */
    
    struct {
      __I  uint8_t   AD__7_0    :  8;               /*!< (null)                                                                */
    } TxFIFO1_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint8_t   TxFIFO2;                         /*!< the start address AD11~8 and size of Tx endpoint FIFO                 */
    
    struct {
      __I  uint8_t   AD__11_8   :  4;               /*!< (null)                                                                */
      __I  uint8_t   DPB        :  1;               /*!< (null)                                                                */
      __I  uint8_t   SZ         :  3;               /*!< (null)                                                                */
    } TxFIFO2_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint8_t   RxFIFO1;                         /*!< the start address AD7~0 of Rx endpoint FIFO                           */
    
    struct {
      __I  uint8_t   AD__7_0    :  8;               /*!< (null)                                                                */
    } RxFIFO1_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint8_t   RxFIFO2;                         /*!< the start address AD11~8 and size of Rx endpoint FIFO                 */
    
    struct {
      __I  uint8_t   AD__11_8   :  4;               /*!< (null)                                                                */
      __I  uint8_t   DPB        :  1;               /*!< (null)                                                                */
      __I  uint8_t   SZ         :  3;               /*!< (null)                                                                */
    } RxFIFO2_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED9[121];
  
  union {
    __IO uint16_t  DMA_CNTL1;                       /*!< DMA Channel 1 Control                                                 */
    
    struct {
      __IO uint16_t  DMA_EN     :  1;               /*!< (null)                                                                */
      __IO uint16_t  DIRECT     :  1;               /*!< (null)                                                                */
      __IO uint16_t  DMA_MODE   :  1;               /*!< (null)                                                                */
      __IO uint16_t  INT_EN     :  1;               /*!< (null)                                                                */
      __IO uint16_t  ENDPOINT_NUM:  4;              /*!< (null)                                                                */
      __IO uint16_t  MAX_PACK_SZ_8B:  7;            /*!< (null)                                                                */
      __IO uint16_t  BUS_ERROR  :  1;               /*!< (null)                                                                */
    } DMA_CNTL1_b;                                  /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED10;
  
  union {
    __IO uint32_t  DMA_ADDR1;                       /*!< DMA Channel 1 AHB Memory Address                                      */
    
    struct {
      __IO uint32_t  DMA_ADDR1  : 32;               /*!< (null)                                                                */
    } DMA_ADDR1_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DMA_COUNT1;                      /*!< DMA Channel 1 Byte Count                                              */
    
    struct {
      __IO uint32_t  DMA_COUNT1 : 32;               /*!< (null)                                                                */
    } DMA_COUNT1_b;                                 /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED11;
  
  union {
    __IO uint16_t  DMA_CNTL2;                       /*!< DMA Channel 2 Control                                                 */
    
    struct {
      __IO uint16_t  DMA_EN     :  1;               /*!< (null)                                                                */
      __IO uint16_t  DIRECT     :  1;               /*!< (null)                                                                */
      __IO uint16_t  DMA_MODE   :  1;               /*!< (null)                                                                */
      __IO uint16_t  INT_EN     :  1;               /*!< (null)                                                                */
      __IO uint16_t  ENDPOINT_NUM:  4;              /*!< (null)                                                                */
      __IO uint16_t  MAX_PACK_SZ_8B:  7;            /*!< (null)                                                                */
      __IO uint16_t  BUS_ERROR  :  1;               /*!< (null)                                                                */
    } DMA_CNTL2_b;                                  /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED12;
  
  union {
    __IO uint32_t  DMA_ADDR2;                       /*!< DMA Channel 2 AHB Memory Address                                      */
    
    struct {
      __IO uint32_t  DMA_ADDR2  : 32;               /*!< (null)                                                                */
    } DMA_ADDR2_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DMA_COUNT2;                      /*!< DMA Channel 2 Byte Count                                              */
    
    struct {
      __IO uint32_t  DMA_COUNT2 : 32;               /*!< (null)                                                                */
    } DMA_COUNT2_b;                                 /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED13;
  
  union {
    __IO uint16_t  DMA_CNTL3;                       /*!< DMA Channel 1 Control                                                 */
    
    struct {
      __IO uint16_t  DMA_EN     :  1;               /*!< (null)                                                                */
      __IO uint16_t  DIRECT     :  1;               /*!< (null)                                                                */
      __IO uint16_t  DMA_MODE   :  1;               /*!< (null)                                                                */
      __IO uint16_t  INT_EN     :  1;               /*!< (null)                                                                */
      __IO uint16_t  ENDPOINT_NUM:  4;              /*!< (null)                                                                */
      __IO uint16_t  MAX_PACK_SZ_8B:  7;            /*!< (null)                                                                */
      __IO uint16_t  BUS_ERROR  :  1;               /*!< (null)                                                                */
    } DMA_CNTL3_b;                                  /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED14;
  
  union {
    __IO uint32_t  DMA_ADDR3;                       /*!< DMA Channel 1 AHB Memory Address                                      */
    
    struct {
      __IO uint32_t  DMA_ADDR3  : 32;               /*!< (null)                                                                */
    } DMA_ADDR3_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DMA_COUNT3;                      /*!< DMA Channel 1 Byte Count                                              */
    
    struct {
      __IO uint32_t  DMA_COUNT3 : 32;               /*!< (null)                                                                */
    } DMA_COUNT3_b;                                 /*!< BitSize                                                               */
  };
} USB_PERIPH_0_Type;


/* ================================================================================ */
/* ================                     MMC_SD                     ================ */
/* ================================================================================ */


/**
  * @brief MMC SD controller (MMC_SD)
  */

typedef struct
{
  __IO uint32_t CTRL;
  __IO uint32_t PWREN;
  __IO uint32_t CLKDIV;
  __IO uint32_t CLKSRC;
  __IO uint32_t CLKENA;
  __IO uint32_t TMOUT;
  __IO uint32_t CTYPE;
  __IO uint32_t BLKSIZ;
  __IO uint32_t BYTCNT;
  __IO uint32_t INTMASK;
  __IO uint32_t CMDARG;
  __IO uint32_t CMD;
  __I  uint32_t RESP0;
  __I  uint32_t RESP1;
  __I  uint32_t RESP2;
  __I  uint32_t RESP3;
  __I  uint32_t MINTSTS;
  __IO uint32_t RINTSTS;
  __I  uint32_t STATUS;
  __IO uint32_t FIFOTH;
  __I  uint32_t CDETECT;
  __I  uint32_t WRTPRT;
  __IO uint32_t GPIO;
  __I  uint32_t TCBCNT;
  __I  uint32_t TBBCNT;
  __IO uint32_t DEBNCE;
  __IO uint32_t USRID;
  __I  uint32_t VERID;	/* H'5342240a */
  __I  uint32_t HCON;	/* IP configuration */
  __IO uint32_t UHS_REG;/* UHS-1: DDR, High Voltage */
  __IO uint32_t RST_n;	/* reset card: 1-active mode, 0-reset */
       uint32_t Reserved7c;
  __IO uint32_t BMOD;	/* IDMAC */
  __O  uint32_t PLDMND;	/* poll demand */
  __IO uint32_t DBADDR;	/* descriptor list base address */
  __IO uint32_t IDSTS;	/* IDMAC status */
  __IO uint32_t IDINTEN;/* IDMAC interrupt enable */
  __I  uint32_t DSCADDR;/* current host descriptor address */
  __I  uint32_t BUFADDR;/* current buffer descriptor address */
       uint8_t Reserved09c_0ff[0x100-0x09c];
  __IO uint32_t CardThrCtl;	/* card threshold control */
  __IO uint32_t Back_end_power; /* 0-off, 1-supply */
       uint8_t Reserved108_1ff[0x200-0x108];
  __IO uint32_t DATA;	/* data FIFO */
} HS_SDHC_Type;


/* ================================================================================ */
/* ================                      UART0                     ================ */
/* ================================================================================ */


/**
  * @brief UART0 controller (UART0)
  */

typedef struct {                                    /*!< UART0 Structure                                                       */
  union
  {
    __I  uint32_t RBR;
    __O  uint32_t THR;
    __IO uint32_t DLL;	
  };
  
  union {
    __IO uint32_t  DLH;                             /*!< Divisor Latch High LCR[7]=1                                           */
    __IO uint32_t  IER; 
    struct {
      __IO uint32_t  DLH_B      : 32;               /*!< (null)                                                                */
    } DLH_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  IIR;                             /*!< Interrupt Identification Register                                     */
    __O  uint32_t  FCR;
    struct {
      __IO uint32_t  IIR_B      : 32;               /*!< (null)                                                                */
    } IIR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  LCR;                             /*!< Line Control Register                                                 */
    
    struct {
      __IO uint32_t  DLS        :  2;               /*!< Data Length Select                                                    */
      __IO uint32_t  STOP       :  1;               /*!< Number of stop bits                                                   */
      __IO uint32_t  PEN        :  1;               /*!< Parity Enable                                                         */
      __IO uint32_t  EPS        :  1;               /*!< Even Parity Select                                                    */
           uint32_t             :  1;
      __IO uint32_t  BC         :  1;               /*!< Break Control Bit                                                     */
      __IO uint32_t  DLAB       :  1;               /*!< Divisor Latch Access Bit                                              */
    } LCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  MCR;                             /*!< Modem Control Register                                                */
    
    struct {
      __IO uint32_t  DTR        :  1;               /*!< Data Terminal Ready                                                   */
      __IO uint32_t  RTS        :  1;               /*!< Request to Send                                                       */
      __IO uint32_t  OUT1       :  1;               /*!< control the user-designated Output1                                   */
      __IO uint32_t  OUT2       :  1;               /*!< control the user-designated Output2                                   */
      __IO uint32_t  LB         :  1;               /*!< LoopBack Bit                                                          */
      __IO uint32_t  AFCE       :  1;               /*!< Auto Flow Control Enable                                              */
      __IO uint32_t  SIRE       :  1;               /*!< SIR Mode Enable                                                       */
    } MCR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint32_t LSR;
  __I  uint32_t MSR;
  
  union {
    __IO uint32_t  SCR;                             /*!< Scratchpad Register                                                   */
    
    struct {
      __IO uint32_t  Scratchpad :  8;               /*!< use as a temporary storage space                                      */
    } SCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  LPDLL;                           /*!< Low Power Divisor Latch (Low) Register                                */
    
    struct {
      __I  uint32_t  LPDLL      :  8;               /*!< 8-bits of baud rate divisor to give 115.2k for SIR low power          */
    } LPDLL_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  LPDLH;                           /*!< Low Power Divisor Latch (High) Register                               */
    
    struct {
      __IO uint32_t  LPDLH      :  8;               /*!< upper 8-bits of baud rate divisor to give 115.2k for SIR low
                                                         power                                                                 */
    } LPDLH_b;                                      /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[2];
  
  union
  {
    __I  uint32_t SRBR[16];
    __O  uint32_t STHR[16];
  };
  
  union {
    __IO uint32_t  FAR;                             /*!< FIFO Access Register                                                  */
    
    struct {
      __IO uint32_t  FAR        :  1;               /*!< (null)                                                                */
    } FAR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TFR;                             /*!< Transmit FIFO Read                                                    */
    
    struct {
      __IO uint32_t  TFR        :  8;               /*!< (null)                                                                */
    } TFR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  RFW;                             /*!< Receive FIFO Write                                                    */
    
    struct {
      __IO uint32_t  RFWD       :  8;               /*!< (null)                                                                */
      __IO uint32_t  RFPE       :  1;               /*!< (null)                                                                */
      __IO uint32_t  RFFE       :  1;               /*!< (null)                                                                */
    } RFW_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  USR;                             /*!< UART Status Register                                                  */
    
    struct {
      __IO uint32_t  BUSY       :  1;               /*!< UART Busy                                                             */
      __IO uint32_t  TFNF       :  1;               /*!< Transmit FIFO Not Full                                                */
      __IO uint32_t  TFE        :  1;               /*!< Transmit FIFO Empty                                                   */
      __IO uint32_t  RFNE       :  1;               /*!< Receive FIFO Not Empty                                                */
      __IO uint32_t  RFF        :  1;               /*!< Receive FIFO Full                                                     */
    } USR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TFL;                             /*!< Transmit FIFO Level                                                   */
    
    struct {
      __IO uint32_t  TFL        :  4;               /*!< Transmit FIFO Level                                                   */
    } TFL_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RFL;                             /*!< Receive FIFO Level                                                    */
    
    struct {
      __IO uint32_t  RFL        :  4;               /*!< Receive FIFO Level                                                    */
    } RFL_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  SRR;                             /*!< Software Reset Register                                               */
    
    struct {
      __IO uint32_t  UR         :  1;               /*!< (null)                                                                */
      __IO uint32_t  RFR        :  1;               /*!< (null)                                                                */
      __IO uint32_t  XFR        :  1;               /*!< (null)                                                                */
    } SRR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SRTS;                            /*!< Shadow Request to Send                                                */
    
    struct {
      __IO uint32_t  SRTS       :  1;               /*!< Shadow Request to Send.                                               */
    } SRTS_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SBCR;                            /*!< Shadow Break Control Register                                         */
    
    struct {
      __IO uint32_t  SBCR       :  1;               /*!< (null)                                                                */
    } SBCR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SDMAM;                           /*!< Shadow DMA Mode                                                       */
    
    struct {
      __IO uint32_t  SDMAM      :  1;               /*!< (null)                                                                */
    } SDMAM_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SFE;                             /*!< Shadow FIFO Enable                                                    */
    
    struct {
      __IO uint32_t  SFE        :  1;               /*!< (null)                                                                */
    } SFE_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SRT;                             /*!< Shadow RCVR Trigger                                                   */
    
    struct {
      __IO uint32_t  SRT        :  2;               /*!< (null)                                                                */
    } SRT_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  STET;                            /*!< Shadow TX Empty Trigger                                               */
    
    struct {
      __IO uint32_t  STET       :  2;               /*!< (null)                                                                */
    } STET_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  HTX;                             /*!< Halt TX                                                               */
    
    struct {
      __IO uint32_t  HTX        :  1;               /*!< (null)                                                                */
    } HTX_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  DMASA;                           /*!< DMA Software Acknowledge                                              */
    
    struct {
      __IO uint32_t  DMASA      :  1;               /*!< (null)                                                                */
    } DMASA_b;                                      /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3[18];
  
  union {
    __I  uint32_t  CPR;                             /*!< Component Parameter Register                                          */
    
    struct {
      __I  uint32_t  APB_DATA_WIDTH:  2;            /*!< (null)                                                                */
           uint32_t             :  2;
      __I  uint32_t  AFCE_MODE  :  1;               /*!< (null)                                                                */
      __I  uint32_t  THRE_MODE  :  1;               /*!< (null)                                                                */
      __I  uint32_t  SIR_MODE   :  1;               /*!< (null)                                                                */
      __I  uint32_t  SIR_LP_MODE:  1;               /*!< (null)                                                                */
      __I  uint32_t  NEW_FEAT   :  1;               /*!< (null)                                                                */
      __I  uint32_t  FIFO_ACCESS:  1;               /*!< (null)                                                                */
      __I  uint32_t  FIFO_STAT  :  1;               /*!< (null)                                                                */
      __I  uint32_t  SHADOW     :  1;               /*!< (null)                                                                */
      __I  uint32_t  UART_ADD_ENCODED_PARAMS:  1;   /*!< (null)                                                                */
      __I  uint32_t  DMA_EXTRA  :  1;               /*!< (null)                                                                */
           uint32_t             :  2;
      __I  uint32_t  FIFO_MODE  :  8;               /*!< (null)                                                                */
    } CPR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  UCV;                             /*!< UART Component Version                                                */
    
    struct {
      __I  uint32_t  UART_component_version: 32;    /*!< (null)                                                                */
    } UCV_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CTR;                             /*!< Component Type Register                                               */
    
    struct {
      __I  uint32_t  Peripheral_ID: 32;             /*!< (null)                                                                */
    } CTR_b;                                        /*!< BitSize                                                               */
  };
} UART_Type;


/* ================================================================================ */
/* ================                      SPI0                      ================ */
/* ================================================================================ */


/**
  * @brief SPI0 (SPI0)
  */

typedef struct {                                    /*!< SPI0 Structure                                                        */
  
  union {
    __IO uint32_t  SPI_CTL;                         /*!< SPI Control Register                                                  */
    
    struct {
      __IO uint32_t  clk_divider: 16;               /*!< (null)                                                                */
      __IO uint32_t  master_enable_h:  1;           /*!< (null)                                                                */
      __IO uint32_t  mode1_h    :  1;               /*!< (null)                                                                */
      __IO uint32_t  master_ce_at_end:  1;          /*!< (null)                                                                */
      __IO uint32_t  soft_reset_h:  1;              /*!< (null)                                                                */
      __IO uint32_t  msb_first_h:  1;               /*!< (null)                                                                */
      __IO uint32_t  invert_clock_h:  1;            /*!< (null)                                                                */
      __IO uint32_t  use_rdy_out_h:  1;             /*!< (null)                                                                */
      __IO uint32_t  bidirect_data_h:  1;           /*!< (null)                                                                */
      __IO uint32_t  active_do_enl:  1;             /*!< (null)                                                                */
      __IO uint32_t  inactive_do_enl:  1;           /*!< (null)                                                                */
      __IO uint32_t  rx_trigger_level:  2;          /*!< (null)                                                                */
      __IO uint32_t  rx_clr_fifo:  1;               /*!< (null)                                                                */
      __IO uint32_t  tx_clr_fifo:  1;               /*!< (null)                                                                */
      __IO uint32_t  rx_fifo_enable:  1;            /*!< (null)                                                                */
      __IO uint32_t  tx_fifo_enable:  1;            /*!< (null)                                                                */
    } SPI_CTL_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0[2];
  
  union {
    __IO uint32_t  SPI_STAT;                        /*!< Status register                                                       */
    
    struct {
      __IO uint32_t  rx_notempty_h:  1;             /*!< (null)                                                                */
      __IO uint32_t  rx_fifo_overrun:  1;           /*!< (null)                                                                */
      __IO uint32_t  tx_fifo_overrun:  1;           /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  tx_empty_int_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  tx_empty   :  1;               /*!< (null)                                                                */
      __IO uint32_t  rx_trig_int_en:  1;            /*!< (null)                                                                */
      __IO uint32_t  rx_fifo_trig:  1;              /*!< (null)                                                                */
      __IO uint32_t  rx_byte_cnt:  8;               /*!< (null)                                                                */
      __IO uint32_t  tx_byte_cnt:  8;               /*!< (null)                                                                */
      __I  uint32_t  spi_active_h:  1;              /*!< (null)                                                                */
      __I  uint32_t  spi_rdy_in :  1;               /*!< (null)                                                                */
      __I  uint32_t  spi_rdy_out:  1;               /*!< (null)                                                                */
      __I  uint32_t  waiting_for_rdy_h:  1;         /*!< (null)                                                                */
      __I  uint32_t  bit_count  :  3;               /*!< (null)                                                                */
      __IO uint32_t  spi_int    :  1;               /*!< (null)                                                                */
    } SPI_STAT_b;                                   /*!< BitSize                                                               */
  };
} SPI0_Type;


/* ================================================================================ */
/* ================                      SPI1                      ================ */
/* ================================================================================ */


/**
  * @brief SPI1 (DW apb ssi) (SPI1)
  */

typedef struct {                                    /*!< SPI1 Structure                                                        */
  
  union {
    __IO uint32_t  CTRLR0;                          /*!< Control Register 0                                                    */
    
    struct {
      __IO uint32_t  DFS        :  4;               /*!< (null)                                                                */
      __IO uint32_t  FRF        :  2;               /*!< (null)                                                                */
      __IO uint32_t  SCPH       :  1;               /*!< (null)                                                                */
      __IO uint32_t  SCPOL      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TMOD       :  2;               /*!< (null)                                                                */
      __IO uint32_t  SLV_OE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  SRL        :  1;               /*!< (null)                                                                */
      __IO uint32_t  CFS        :  4;               /*!< (null)                                                                */
    } CTRLR0_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CTRLR1;                          /*!< Register 1                                                            */
    
    struct {
      __IO uint32_t  NDF        : 16;               /*!< (null)                                                                */
    } CTRLR1_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  SSIENR;                          /*!< Enable Register                                                       */
    
    struct {
      __IO uint32_t  SSI_EN     :  1;               /*!< (null)                                                                */
    } SSIENR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  MWCR;                            /*!< Control Register                                                      */
    
    struct {
      __IO uint32_t  MWMOD      :  1;               /*!< (null)                                                                */
      __IO uint32_t  MDD        :  1;               /*!< (null)                                                                */
      __IO uint32_t  MHS        :  1;               /*!< (null)                                                                */
    } MWCR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  SER;                             /*!< Enable Register                                                       */
    
    struct {
      __IO uint32_t  SER        :  4;               /*!< (null)                                                                */
    } SER_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  BAUDR;                           /*!< Rate Select                                                           */
    
    struct {
      __IO uint32_t  SCKDV      : 16;               /*!< (null)                                                                */
    } BAUDR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TXFTLR;                          /*!< FIFO Threshold Level                                                  */
    
    struct {
      __IO uint32_t  TFT        :  4;               /*!< (null)                                                                */
    } TXFTLR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RXFTLR;                          /*!< FIFO Threshold Level                                                  */
    
    struct {
      __IO uint32_t  RFT        :  4;               /*!< (null)                                                                */
    } RXFTLR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TXFLR;                           /*!< FIFO Level Register                                                   */
    
    struct {
      __I  uint32_t  TXTFL      :  4;               /*!< (null)                                                                */
    } TXFLR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RXFLR;                           /*!< FIFO Level Register                                                   */
    
    struct {
      __I  uint32_t  RXTFL      :  4;               /*!< (null)                                                                */
    } RXFLR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  SR;                              /*!< Register                                                              */
    
    struct {
      __I  uint32_t  BUSY       :  1;               /*!< (null)                                                                */
      __I  uint32_t  TFNF       :  1;               /*!< (null)                                                                */
      __I  uint32_t  TFE        :  1;               /*!< (null)                                                                */
      __I  uint32_t  RFNE       :  1;               /*!< (null)                                                                */
      __I  uint32_t  RFF        :  1;               /*!< (null)                                                                */
      __I  uint32_t  TXE        :  1;               /*!< (null)                                                                */
      __I  uint32_t  DCOL       :  1;               /*!< (null)                                                                */
    } SR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  IMR;                             /*!< Mask Register                                                         */
    
    struct {
      __IO uint32_t  TXEIM      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TXOIM      :  1;               /*!< (null)                                                                */
      __IO uint32_t  RXUIM      :  1;               /*!< (null)                                                                */
      __IO uint32_t  RXOIM      :  1;               /*!< (null)                                                                */
      __IO uint32_t  RXFIM      :  1;               /*!< (null)                                                                */
      __IO uint32_t  MSTIM      :  1;               /*!< (null)                                                                */
    } IMR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  ISR;                             /*!< Status Register                                                       */
    
    struct {
      __I  uint32_t  TXEIS      :  1;               /*!< (null)                                                                */
      __I  uint32_t  TXOIS      :  1;               /*!< (null)                                                                */
      __I  uint32_t  RXUIS      :  1;               /*!< (null)                                                                */
      __I  uint32_t  RXOIS      :  1;               /*!< (null)                                                                */
      __I  uint32_t  RXFIS      :  1;               /*!< (null)                                                                */
      __I  uint32_t  MSTIS      :  1;               /*!< (null)                                                                */
    } ISR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RISR;                            /*!< Interrupt Status Register                                             */
    
    struct {
      __I  uint32_t  TXEIR      :  1;               /*!< (null)                                                                */
      __I  uint32_t  TXOIR      :  1;               /*!< (null)                                                                */
      __I  uint32_t  RXUIR      :  1;               /*!< (null)                                                                */
      __I  uint32_t  RXOIR      :  1;               /*!< (null)                                                                */
      __I  uint32_t  RXFIR      :  1;               /*!< (null)                                                                */
      __I  uint32_t  MSTIR      :  1;               /*!< (null)                                                                */
    } RISR_b;                                       /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0[5];
  
  union {
    __I  uint32_t  DMACR;                           /*!< Control Register                                                      */
    
    struct {
      __IO uint32_t  RDMAE      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TDMAE      :  1;               /*!< (null)                                                                */
    } DMACR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMATDLR;                         /*!< Transmit Data Level                                                   */
    
    struct {
      __IO uint32_t  DMATDL     :  4;               /*!< (null)                                                                */
    } DMATDLR_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  DMARDLR;                         /*!< Receive Data Level                                                    */
    
    struct {
      __IO uint32_t  DMARDL     :  4;               /*!< (null)                                                                */
    } DMARDLR_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  IDR;                             /*!< Register                                                              */
    
    struct {
      __I  uint32_t  IDCODE     : 32;               /*!< (null)                                                                */
    } IDR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  SSI_COMP_VERSION;                /*!< version ID register                                                   */
    
    struct {
      __I  uint32_t  SSI_COMP_VERSION: 32;          /*!< (null)                                                                */
    } SSI_COMP_VERSION_b;                           /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[36];
  
  union {
    __I  uint32_t  RX_SAMPLE_DLY;                   /*!< Sample Delay Register                                                 */
    
    struct {
      __IO uint32_t  RSD        : 15;               /*!< (null)                                                                */
    } RX_SAMPLE_DLY_b;                              /*!< BitSize                                                               */
  };
} SPI1_Type;


/* ================================================================================ */
/* ================                       I2C                      ================ */
/* ================================================================================ */


/**
  * @brief I2C controller (I2C)
  */

typedef struct {                                    /*!< I2C Structure                                                         */
  
  union {
    __IO uint16_t  CON;                             /*!< I2C Control Register                                                  */
    
    struct {
      __IO uint16_t  MASTER_MODE:  1;               /*!< enable master                                                         */
      __IO uint16_t  SPEED      :  2;               /*!< speed setting                                                         */
      __IO uint16_t  IC_10BITADDR_SLAVE:  1;        /*!< 7- or 10- bit address selection when slave                            */
      __IO uint16_t  IC_10BITADDR_MASTER:  1;       /*!< 7- or 10- bit address selection when master                           */
      __IO uint16_t  IC_RESTART_EN:  1;             /*!< Determines whether RESTART conditions may be sent when as a
                                                         master                                                                */
      __IO uint16_t  IC_SLAVE_DISABLE:  1;          /*!< disable slave                                                         */
    } CON_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED0;
  
  union {
    __IO uint16_t  TAR;                             /*!< I2C Target Address                                                    */
    
    struct {
      __IO uint16_t  IC_TAR     : 10;               /*!< Target address                                                        */
      __IO uint16_t  GC_OR_START:  1;               /*!< general call or START BYTE                                            */
      __IO uint16_t  SPECIAL    :  1;               /*!< IC_TAR or GC_OR_START                                                 */
      __IO uint16_t  IC_10BITADDR_MASTER:  1;       /*!< address mode when master                                              */
    } TAR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED1;
  
  union {
    __IO uint16_t  SAR;                             /*!< I2C Slave Address                                                     */
    
    struct {
      __IO uint16_t  IC_SAR     : 10;               /*!< address as a slave                                                    */
    } SAR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED2;
  
  union {
    __IO uint16_t  HS_MADDR;                        /*!< I2C HS Master Mode Code Address                                       */
    
    struct {
      __IO uint16_t  IC_HS_MAR  :  3;               /*!< HS mode master code                                                   */
    } HS_MADDR_b;                                   /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED3[3];
  
  union {
    __IO uint16_t  SS_SCL_HCNT;                     /*!< Standard speed I2C Clock SCL High Count                               */
    
    struct {
      __IO uint16_t  IC_SS_SCL_HCNT: 16;            /*!< Standard Speed scl high count                                         */
    } SS_SCL_HCNT_b;                                /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED4;
  
  union {
    __IO uint16_t  SS_SCL_LCNT;                     /*!< Standard speed I2C Clock SCL Low Count                                */
    
    struct {
      __IO uint16_t  IC_SS_SCL_LCNT: 16;            /*!< Standard Speed scl low count                                          */
    } SS_SCL_LCNT_b;                                /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED5;
  
  union {
    __IO uint16_t  FS_SCL_HCNT;                     /*!< Fast speed I2C Clock SCL High Count                                   */
    
    struct {
      __IO uint16_t  IC_FS_SCL_HCNT: 16;            /*!< Fast Speed scl high count                                             */
    } FS_SCL_HCNT_b;                                /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED6;
  
  union {
    __IO uint16_t  FS_SCL_LCNT;                     /*!< Fast speed I2C Clock SCL Low Count                                    */
    
    struct {
      __IO uint16_t  IC_FS_SCL_LCNT: 16;            /*!< Fast Speed scl low count                                              */
    } FS_SCL_LCNT_b;                                /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED7;
  
  union {
    __IO uint16_t  HS_SCL_HCNT;                     /*!< High speed I2C Clock SCL High Count                                   */
    
    struct {
      __IO uint16_t  IC_HS_SCL_HCNT: 16;            /*!< High Speed scl high count                                             */
    } HS_SCL_HCNT_b;                                /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED8;
  
  union {
    __IO uint16_t  HS_SCL_LCNT;                     /*!< High speed I2C Clock SCL Low Count                                    */
    
    struct {
      __IO uint16_t  IC_HS_SCL_LCNT: 16;            /*!< High Speed scl low count                                              */
    } HS_SCL_LCNT_b;                                /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED9;
  
  union {
    __I  uint16_t  INTR_STAT;                       /*!< I2C Interrupt Status                                                  */
    
    struct {
      __I  uint16_t  R_RX_UNDER :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_RX_OVER  :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_RX_FULL  :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_TX_OVER  :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_TX_EMPTY :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_RD_REQ   :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_TX_ABRT  :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_RX_DONE  :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_ACTIVITY :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_STOP_DET :  1;               /*!< (null)                                                                */
      __I  uint16_t  R_START_DET:  1;               /*!< (null)                                                                */
      __I  uint16_t  R_GEN_CALL :  1;               /*!< (null)                                                                */
    } INTR_STAT_b;                                  /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED10;
  
  union {
    __IO uint16_t  INTR_MASK;                       /*!< I2C Interrupt MAsk                                                    */
    
    struct {
      __IO uint16_t  M_RX_UNDER :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_RX_OVER  :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_RX_FULL  :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_TX_OVER  :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_TX_EMPTY :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_RD_REQ   :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_TX_ABRT  :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_RX_DONE  :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_ACTIVITY :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_STOP_DET :  1;               /*!< (null)                                                                */
      __IO uint16_t  M_START_DET:  1;               /*!< (null)                                                                */
      __IO uint16_t  M_GEN_CALL :  1;               /*!< (null)                                                                */
    } INTR_MASK_b;                                  /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED11;
  
  union {
    __I  uint16_t  RAW_INTR_STAT;                   /*!< I2C Raw Interrupt Status                                              */
    
    struct {
      __I  uint16_t  RX_UNDER   :  1;               /*!< (null)                                                                */
      __I  uint16_t  RX_OVER    :  1;               /*!< (null)                                                                */
      __I  uint16_t  RX_FULL    :  1;               /*!< (null)                                                                */
      __I  uint16_t  TX_OVER    :  1;               /*!< (null)                                                                */
      __I  uint16_t  TX_EMPTY   :  1;               /*!< (null)                                                                */
      __I  uint16_t  RD_REQ     :  1;               /*!< (null)                                                                */
      __I  uint16_t  TX_ABRT    :  1;               /*!< (null)                                                                */
      __I  uint16_t  RX_DONE    :  1;               /*!< (null)                                                                */
      __I  uint16_t  ACTIVITY   :  1;               /*!< (null)                                                                */
      __I  uint16_t  STOP_DET   :  1;               /*!< (null)                                                                */
      __I  uint16_t  START_DET  :  1;               /*!< start or restart                                                      */
      __I  uint16_t  GEN_CALL   :  1;               /*!< general call                                                          */
    } RAW_INTR_STAT_b;                              /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED12;
  
  union {
    __IO uint16_t  RX_TL;                           /*!< I2C Receive FIFO Threshold                                            */
    
    struct {
      __IO uint16_t  RX_TL      :  8;               /*!< (null)                                                                */
    } RX_TL_b;                                      /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED13;
  
  union {
    __IO uint16_t  TX_TL;                           /*!< I2C Transmit FIFO Threshold                                           */
    
    struct {
      __IO uint16_t  TX_TL      :  8;               /*!< (null)                                                                */
    } TX_TL_b;                                      /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED14[23];
  
  union {
    __IO uint16_t  ENABLE;                          /*!< I2C Enable                                                            */
    
    struct {
      __IO uint16_t  ENABLE     :  1;               /*!< (null)                                                                */
    } ENABLE_b;                                     /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED15;
  
  union {
    __I  uint32_t  STATUS;                          /*!< I2C Status Register                                                   */
    
    struct {
      __I  uint32_t  ACTIVITY   :  1;               /*!< (null)                                                                */
      __I  uint32_t  TFNF       :  1;               /*!< (null)                                                                */
      __I  uint32_t  TFE        :  1;               /*!< (null)                                                                */
      __I  uint32_t  RFNE       :  1;               /*!< (null)                                                                */
      __I  uint32_t  RFF        :  1;               /*!< (null)                                                                */
      __I  uint32_t  MST_ACTIVITY:  1;              /*!< (null)                                                                */
      __I  uint32_t  SLV_ACTIVITY:  1;              /*!< (null)                                                                */
    } STATUS_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TXFLR;                           /*!< Transmit FIFO Level Register                                          */
    
    struct {
      __I  uint32_t  TXFLR      :  4;               /*!< (null)                                                                */
    } TXFLR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  RXFLR;                           /*!< Receive FIFO Level Register                                           */
    
    struct {
      __I  uint32_t  RXFLR      :  4;               /*!< (null)                                                                */
    } RXFLR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SDA_HOLD;                        /*!< SDA hold time length register                                         */
    
    struct {
      __IO uint32_t  IC_SDA_HOLD: 16;               /*!< (null)                                                                */
    } SDA_HOLD_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TX_ABRT_SOURCE;                  /*!< I2C Transmit Abort Status Register                                    */
    
    struct {
      __I  uint32_t  ABRT_7B_ADDR_NOACK:  1;        /*!< (null)                                                                */
      __I  uint32_t  ABRT_10ADDR1_NOACK:  1;        /*!< (null)                                                                */
      __I  uint32_t  ABRT_10ADDR2_NOACK:  1;        /*!< (null)                                                                */
      __I  uint32_t  ABRT_TXDATA_NOACK:  1;         /*!< (null)                                                                */
      __I  uint32_t  ABRT_GCALL_NOACK:  1;          /*!< (null)                                                                */
      __I  uint32_t  ABRT_GCALL_READ:  1;           /*!< (null)                                                                */
      __I  uint32_t  ABRT_HS_ACKDET:  1;            /*!< (null)                                                                */
      __I  uint32_t  ABRT_SBYTE_ACKDET:  1;         /*!< (null)                                                                */
      __I  uint32_t  ABRT_HS_NORSTRT:  1;           /*!< (null)                                                                */
      __I  uint32_t  ABRT_SBYTE_NORSTRT:  1;        /*!< (null)                                                                */
      __I  uint32_t  ABRT_10B_RD_NORSTRT:  1;       /*!< (null)                                                                */
      __I  uint32_t  ABRT_MASTER_DIS:  1;           /*!< (null)                                                                */
      __I  uint32_t  ARB_LOST   :  1;               /*!< (null)                                                                */
      __I  uint32_t  ABRT_SLVFLUSH_TXFIFO:  1;      /*!< (null)                                                                */
      __I  uint32_t  ABRT_SLV_ARBLOST:  1;          /*!< (null)                                                                */
      __I  uint32_t  ABRT_SLVRD_INTX:  1;           /*!< (null)                                                                */
    } TX_ABRT_SOURCE_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SLV_DATA_NACK_ONLY;              /*!< Generate SLV_DATA_NACK Register                                       */
    
    struct {
      __IO uint32_t  NACK       :  1;               /*!< (null)                                                                */
    } SLV_DATA_NACK_ONLY_b;                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DMA_CR;                          /*!< DMA Control Register for transmit and receive                         */
    
    struct {
      __IO uint32_t  TDMAE      :  1;               /*!< (null)                                                                */
      __IO uint32_t  RDMAE      :  1;               /*!< (null)                                                                */
    } DMA_CR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DMA_TDLR;                        /*!< DMA Transmit Data Level                                               */
    
    struct {
      __IO uint32_t  DMATDL     :  3;               /*!< (null)                                                                */
    } DMA_TDLR_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DMA_RDLR;                        /*!< DMA Receive Data Level                                                */
    
    struct {
      __IO uint32_t  DMARDL     :  3;               /*!< (null)                                                                */
    } DMA_RDLR_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SDA_SETUP;                       /*!< I2C SDA Setup Register                                                */
    
    struct {
      __IO uint32_t  SDA_SETUP  :  8;               /*!< (null)                                                                */
    } SDA_SETUP_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ACK_GENERAL_CALL;                /*!< I2C ACK General Call Register                                         */
    
    struct {
      __IO uint32_t  ACK_GEN_CALL:  1;              /*!< (null)                                                                */
    } ACK_GENERAL_CALL_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  ENABLE_STATUS;                   /*!< I2C Enable Status Register                                            */
    
    struct {
      __I  uint32_t  IC_EN      :  1;               /*!< (null)                                                                */
      __I  uint32_t  SLV_RX_ABORTED:  1;            /*!< (null)                                                                */
      __I  uint32_t  SLV_FIFO_FILLED_AND_FLUSHED:  1;/*!< (null)                                                               */
    } ENABLE_STATUS_b;                              /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED16[21];
  
  union {
    __I  uint32_t  IC_COMP_PARAM_1;                 /*!< Component Parameter Register                                          */
    
    struct {
      __I  uint32_t  APB_DATA_WIDTH:  2;            /*!< (null)                                                                */
      __I  uint32_t  MAX_SPEED_MODE:  2;            /*!< (null)                                                                */
      __I  uint32_t  HC_COUNT_VALUES:  1;           /*!< (null)                                                                */
      __I  uint32_t  INTR_IO    :  1;               /*!< (null)                                                                */
      __I  uint32_t  HAS_DMA    :  1;               /*!< (null)                                                                */
      __I  uint32_t  ADD_ENCODED_PARAMS:  1;        /*!< (null)                                                                */
      __I  uint32_t  RX_BUFFER_DEPTH:  8;           /*!< (null)                                                                */
      __I  uint32_t  TX_BUFFER_DEPTH:  8;           /*!< (null)                                                                */
    } IC_COMP_PARAM_1_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  IC_COMP_VERSION;                 /*!< Component Version ID                                                  */
    
    struct {
      __I  uint32_t  IC_COMP_VERSION: 32;           /*!< (null)                                                                */
    } IC_COMP_VERSION_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  IC_COMP_TYPE;                    /*!< DesignWare Component Type Register                                    */
    
    struct {
      __I  uint32_t  IC_COMP_TYPE: 32;              /*!< (null)                                                                */
    } IC_COMP_TYPE_b;                               /*!< BitSize                                                               */
  };
} I2C_Type;


/* ================================================================================ */
/* ================                       I2S                      ================ */
/* ================================================================================ */


/**
  * @brief I2S controller (I2S)
  */

typedef struct {                                    /*!< I2S Structure                                                         */
  
  union {
    __IO uint32_t  IER;                             /*!< DW_apb_i2s Enable Register                                            */
    
    struct {
      __IO uint32_t  IEN        :  1;               /*!< (null)                                                                */
    } IER_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IRER;                            /*!< I2S Receiver Block Enable Register                                    */
    
    struct {
      __IO uint32_t  RXEN       :  1;               /*!< (null)                                                                */
    } IRER_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ITER;                            /*!< I2S Transmitter Block Enable Register                                 */
    
    struct {
      __IO uint32_t  TXEN       :  1;               /*!< (null)                                                                */
    } ITER_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CER;                             /*!< Clock Enable Register                                                 */
    
    struct {
      __IO uint32_t  CLKEN      :  1;               /*!< (null)                                                                */
    } CER_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CCR;                             /*!< Clock Configuration Register                                          */
    
    struct {
      __IO uint32_t  SCLKG      :  3;               /*!< (null)                                                                */
      __IO uint32_t  WSS        :  2;               /*!< (null)                                                                */
    } CCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  RXFFR;                           /*!< Receiver Block FIFO Reset Register                                    */
    
    struct {
      __O  uint32_t  RXFFR      :  1;               /*!< (null)                                                                */
    } RXFFR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  TXFFR;                           /*!< Transmitter Block FIFO Reset Register                                 */
    
    struct {
      __O  uint32_t  TXFFR      :  1;               /*!< (null)                                                                */
    } TXFFR_b;                                      /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0[3];
  
  union {
    __IO uint32_t  RER;                             /*!< channel 0 Receive Enable Register 0                                   */
    
    struct {
      __IO uint32_t  RXCHEN0    :  1;               /*!< (null)                                                                */
    } RER_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TER;                             /*!< channel 0 Transmit Enable Register 0                                  */
    
    struct {
      __IO uint32_t  TXCHEN0    :  1;               /*!< (null)                                                                */
    } TER_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RCR;                             /*!< channel 0 Receive Configuration Register 0                            */
    
    struct {
      __IO uint32_t  WLEN       :  3;               /*!< (null)                                                                */
    } RCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TCR;                             /*!< channel 0 Transmit Configuration Register 0                           */
    
    struct {
      __IO uint32_t  WLEN       :  3;               /*!< (null)                                                                */
    } TCR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  ISR;                             /*!< channel 0 Interrupt Status Register 0                                 */
    
    struct {
      __I  uint32_t  RXDA       :  1;               /*!< (null)                                                                */
      __I  uint32_t  RXFO       :  1;               /*!< (null)                                                                */
           uint32_t             :  2;
      __I  uint32_t  TXFE       :  1;               /*!< (null)                                                                */
      __I  uint32_t  TXFO       :  1;               /*!< (null)                                                                */
    } ISR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  IMR;                             /*!< channel 0 Interrupt Mask Register 0                                   */
    
    struct {
      __IO uint32_t  RXDAM      :  1;               /*!< (null)                                                                */
      __IO uint32_t  RXFOM      :  1;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  TXFEM      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TXFOM      :  1;               /*!< (null)                                                                */
    } IMR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[2];
  
  union {
    __IO uint32_t  RFCR;                            /*!< channel 0 Receive FIFO Configuration Register 0                       */
    
    struct {
      __IO uint32_t  RXCHDT     :  4;               /*!< (null)                                                                */
    } RFCR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TFCR;                            /*!< channel 0 Transmit FIFO Configuration Register 0                      */
    
    struct {
      __IO uint32_t  TXCHET     :  4;               /*!< (null)                                                                */
    } TFCR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  RFF;                             /*!< channel 0 Receive FIFO Flush 0                                        */
    
    struct {
      __O  uint32_t  RXCHFR     :  1;               /*!< (null)                                                                */
    } RFF_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  TFF;                             /*!< channel 0 Transmit FIFO Flush 0                                       */
    
    struct {
      __O  uint32_t  TXCHFR     :  1;               /*!< (null)                                                                */
    } TFF_b;                                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[91];
  
  union {
    __O  uint32_t  RRXDMA;                          /*!< Reset Receiver Block DMA Register                                     */
    
    struct {
      __O  uint32_t  RRXDMA     :  1;               /*!< (null)                                                                */
    } RRXDMA_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3;
  
  union {
    __O  uint32_t  RTXDMA;                          /*!< Reset Transmitter Block DMA Register                                  */
    
    struct {
      __O  uint32_t  RTXDMA     :  1;               /*!< (null)                                                                */
    } RTXDMA_b;                                     /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED4[8];
  
  union {
    __I  uint32_t  I2S_COMP_PARAM_2;                /*!< Component Parameter 2 Register                                        */
    
    struct {
      __I  uint32_t  I2S_RX_WORDSIZE_0:  3;         /*!< (null)                                                                */
      __I  uint32_t  I2S_RX_WORDSIZE_1:  3;         /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  I2S_RX_WORDSIZE_2:  3;         /*!< (null)                                                                */
      __I  uint32_t  I2S_RX_WORDSIZE_3:  3;         /*!< (null)                                                                */
    } I2S_COMP_PARAM_2_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  I2S_COMP_PARAM_1;                /*!< Component Parameter 1 Register                                        */
    
    struct {
      __I  uint32_t  APB_DATA_WIDTH:  2;            /*!< (null)                                                                */
      __I  uint32_t  I2S_FIFO_DEPTH_GLOBAL:  2;     /*!< (null)                                                                */
      __I  uint32_t  I2S_MODE_EN:  1;               /*!< (null)                                                                */
      __I  uint32_t  I2S_TRANSMITTER_BLOCK:  1;     /*!< (null)                                                                */
      __I  uint32_t  I2S_RECEIVER_BLOCK:  1;        /*!< (null)                                                                */
      __I  uint32_t  I2S_RX_CHANNELS:  2;           /*!< (null)                                                                */
      __I  uint32_t  I2S_TX_CHANNELS:  2;           /*!< (null)                                                                */
           uint32_t             :  5;
      __I  uint32_t  I2S_TX_WORDSIZE_0:  3;         /*!< (null)                                                                */
      __I  uint32_t  I2S_TX_WORDSIZE_1:  3;         /*!< (null)                                                                */
      __I  uint32_t  I2S_TX_WORDSIZE_2:  3;         /*!< (null)                                                                */
      __I  uint32_t  I2S_TX_WORDSIZE_3:  3;         /*!< (null)                                                                */
    } I2S_COMP_PARAM_1_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  I2S_COMP_VERSION;                /*!< Component Version ID                                                  */
    
    struct {
      __I  uint32_t  I2S_COMP_VERSION: 32;          /*!< (null)                                                                */
    } I2S_COMP_VERSION_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  I2S_COMP_TYPE;                   /*!< DesignWare Component Type                                             */
    
    struct {
      __I  uint32_t  I2S_COMP_TYPE: 32;             /*!< (null)                                                                */
    } I2S_COMP_TYPE_b;                              /*!< BitSize                                                               */
  };
} I2S_Type;


/* ================================================================================ */
/* ================                       PWM                      ================ */
/* ================================================================================ */


/**
  * @brief PWM Timer0/1/2/3 (PWM)
  */

typedef struct {                                    /*!< PWM Structure                                                         */
  
  union {
    __IO uint32_t  TCR0;                            /*!< PWM Timer 0 Control Register                                          */
    
    struct {
      __IO uint32_t  TM_EN      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_INVT    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_AUTO    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_SIM     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_LPSI    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_LPDI    :  1;               /*!< (null)                                                                */
    } TCR0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSR0;                            /*!< PWM Timer 0 Pre-scalar Value Register                                 */
    
    struct {
      __IO uint32_t  TM_PSV     : 10;               /*!< (null)                                                                */
    } PSR0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PVR0;                            /*!< PWM Timer 0 Period Value Register                                     */
    
    struct {
      __IO uint32_t  TM_PV      : 12;               /*!< (null)                                                                */
    } PVR0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DVR0;                            /*!< PWM Timer 0 Duty Value Register                                       */
    
    struct {
      __IO uint32_t  TM_DV      : 12;               /*!< (null)                                                                */
    } DVR0_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TCR1;                            /*!< PWM Timer 1 Control Register                                          */
    
    struct {
      __IO uint32_t  TM_EN      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_INVT    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_AUTO    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_SIM     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_LPSI    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_LPDI    :  1;               /*!< (null)                                                                */
    } TCR1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSR1;                            /*!< PWM Timer 1 Pre-scalar Value Register                                 */
    
    struct {
      __IO uint32_t  TM_PSV     : 10;               /*!< (null)                                                                */
    } PSR1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PVR1;                            /*!< PWM Timer 1 Period Value Register                                     */
    
    struct {
      __IO uint32_t  TM_PV      : 12;               /*!< (null)                                                                */
    } PVR1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DVR1;                            /*!< PWM Timer 1 Duty Value Register                                       */
    
    struct {
      __IO uint32_t  TM_DV      : 12;               /*!< (null)                                                                */
    } DVR1_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TCR2;                            /*!< PWM Timer 2 Control Register                                          */
    
    struct {
      __IO uint32_t  TM_EN      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_INVT    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_AUTO    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_SIM     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_LPSI    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_LPDI    :  1;               /*!< (null)                                                                */
    } TCR2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSR2;                            /*!< PWM Timer 2 Pre-scalar Value Register                                 */
    
    struct {
      __IO uint32_t  TM_PSV     : 10;               /*!< (null)                                                                */
    } PSR2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PVR2;                            /*!< PWM Timer 2 Period Value Register                                     */
    
    struct {
      __IO uint32_t  TM_PV      : 12;               /*!< (null)                                                                */
    } PVR2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DVR2;                            /*!< PWM Timer 2 Duty Value Register                                       */
    
    struct {
      __IO uint32_t  TM_DV      : 12;               /*!< (null)                                                                */
    } DVR2_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TCR3;                            /*!< PWM Timer 3 Control Register                                          */
    
    struct {
      __IO uint32_t  TM_EN      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_INVT    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_AUTO    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_SIM     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_LPSI    :  1;               /*!< (null)                                                                */
      __IO uint32_t  TM_LPDI    :  1;               /*!< (null)                                                                */
    } TCR3_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSR3;                            /*!< PWM Timer 3 Pre-scalar Value Register                                 */
    
    struct {
      __IO uint32_t  TM_PSV     : 10;               /*!< (null)                                                                */
    } PSR3_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PVR3;                            /*!< PWM Timer 3 Period Value Register                                     */
    
    struct {
      __IO uint32_t  TM_PV      : 12;               /*!< (null)                                                                */
    } PVR3_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DVR3;                            /*!< PWM Timer 3 Duty Value Register                                       */
    
    struct {
      __IO uint32_t  TM_DV      : 12;               /*!< (null)                                                                */
    } DVR3_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TSR;                             /*!< PWM Timer Status Register                                             */
    
    struct {
      __I  uint32_t  TM0_CRSS   :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM0_PSRSS  :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM0_PVRSS  :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM0_DVRSS  :  1;               /*!< (null)                                                                */
           uint32_t             :  4;
      __I  uint32_t  TM1_CRSS   :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM1_PSRSS  :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM1_PVRSS  :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM1_DVRSS  :  1;               /*!< (null)                                                                */
           uint32_t             :  4;
      __I  uint32_t  TM2_CRSS   :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM2_PSRSS  :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM2_PVRSS  :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM2_DVRSS  :  1;               /*!< (null)                                                                */
           uint32_t             :  4;
      __I  uint32_t  TM3_CRSS   :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM3_PSRSS  :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM3_PVRSS  :  1;               /*!< (null)                                                                */
      __I  uint32_t  TM3_DVRSS  :  1;               /*!< (null)                                                                */
    } TSR_b;                                        /*!< BitSize                                                               */
  };
} PWM_Type;


/* ================================================================================ */
/* ================                     TIMER0                     ================ */
/* ================================================================================ */


/**
  * @brief TIMER0 (TIMER0)
  */

typedef struct {                                    /*!< TIMER0 Structure                                                      */
  
  union {
    __IO uint16_t  CR1;                             /*!< control register 1                                                    */
    
    struct {
      __IO uint16_t  CEN        :  1;               /*!< (null)                                                                */
      __IO uint16_t  UDIS       :  1;               /*!< (null)                                                                */
      __IO uint16_t  URS        :  1;               /*!< (null)                                                                */
      __IO uint16_t  OPM        :  1;               /*!< (null)                                                                */
      __IO uint16_t  DIR        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CMS        :  2;               /*!< (null)                                                                */
      __IO uint16_t  ARPE       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CKD        :  2;               /*!< (null)                                                                */
    } CR1_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED0;
  
  union {
    __IO uint16_t  CR2;                             /*!< control register 2                                                    */
    
    struct {
      __IO uint16_t  CCPC       :  1;               /*!< (null)                                                                */
           uint16_t             :  1;
      __IO uint16_t  CCUS       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CCDS       :  1;               /*!< (null)                                                                */
      __IO uint16_t  MMS        :  3;               /*!< (null)                                                                */
      __IO uint16_t  TI1S       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS1       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS1N      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS2       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS2N      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS3       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS3N      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS4       :  1;               /*!< (null)                                                                */
    } CR2_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED1;
  
  union {
    __IO uint16_t  SMCR;                            /*!< slave mode control register                                           */
    
    struct {
      __IO uint16_t  SMS        :  3;               /*!< (null)                                                                */
           uint16_t             :  1;
      __IO uint16_t  TS         :  3;               /*!< (null)                                                                */
      __IO uint16_t  MSM        :  1;               /*!< (null)                                                                */
      __IO uint16_t  ETF        :  4;               /*!< (null)                                                                */
      __IO uint16_t  ETPS       :  2;               /*!< (null)                                                                */
      __IO uint16_t  ECE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  ETP        :  1;               /*!< (null)                                                                */
    } SMCR_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED2;
  
  union {
    __IO uint16_t  DIER;                            /*!< DMA/interrupt enable register                                         */
    
    struct {
      __IO uint16_t  UIE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMIE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  TIE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  BIE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  UDE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMDE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  TDE        :  1;               /*!< (null)                                                                */
    } DIER_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED3;
  
  union {
    __IO uint16_t  SR;                              /*!< status register                                                       */
    
    struct {
      __IO uint16_t  UIF        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMIF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  TIF        :  1;               /*!< (null)                                                                */
      __IO uint16_t  BIF        :  1;               /*!< (null)                                                                */
           uint16_t             :  1;
      __IO uint16_t  CC1OF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2OF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3OF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4OF      :  1;               /*!< (null)                                                                */
    } SR_b;                                         /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED4;
  
  union {
    __IO uint16_t  EGR;                             /*!< event generation register                                             */
    
    struct {
      __IO uint16_t  UG         :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMG       :  1;               /*!< (null)                                                                */
      __IO uint16_t  TG         :  1;               /*!< (null)                                                                */
      __IO uint16_t  BG         :  1;               /*!< (null)                                                                */
    } EGR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED5;
  
  union {
    __IO uint16_t  CCMR1_COMPARE;                   /*!< capture/compare mode register 1                                       */
    
    struct {
      __IO uint16_t  CC1S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC1FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC1PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC1M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC1CE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC2FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC2PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC2M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC2CE      :  1;               /*!< (null)                                                                */
    } CCMR1_COMPARE_b;                              /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED6;
  
  union {
    __IO uint16_t  CCMR2_COMPARE;                   /*!< capture/compare mode register 2                                       */
    
    struct {
      __IO uint16_t  CC3S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC3FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC3PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC3M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC3CE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC4FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC4PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC4M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC4CE      :  1;               /*!< (null)                                                                */
    } CCMR2_COMPARE_b;                              /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED7;
  
  union {
    __IO uint16_t  CCER;                            /*!< capture/compare enable register                                       */
    
    struct {
      __IO uint16_t  CC1E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1P       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1NE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1NP      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2P       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2NE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2NP      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3P       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3NE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3NP      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4P       :  1;               /*!< (null)                                                                */
    } CCER_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED8;
  
  union {
    __IO uint16_t  CNT;                             /*!< counter                                                               */
    
    struct {
      __IO uint16_t  CNT        : 16;               /*!< (null)                                                                */
    } CNT_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED9;
  
  union {
    __IO uint16_t  PSC;                             /*!< prescaler                                                             */
    
    struct {
      __IO uint16_t  PSC        : 16;               /*!< (null)                                                                */
    } PSC_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED10;
  
  union {
    __IO uint16_t  ARR;                             /*!< auto-reload register                                                  */
    
    struct {
      __IO uint16_t  ARR        : 16;               /*!< (null)                                                                */
    } ARR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED11;
  
  union {
    __IO uint16_t  RCR;                             /*!< repetition counter register                                           */
    
    struct {
      __IO uint16_t  REP        :  8;               /*!< (null)                                                                */
    } RCR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED12[9];
  
  union {
    __IO uint16_t  BDTR;                            /*!< break and dead-time register                                          */
    
    struct {
      __IO uint16_t  DTG        :  8;               /*!< (null)                                                                */
      __IO uint16_t  LOCK       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OSSI       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OSSR       :  1;               /*!< (null)                                                                */
      __IO uint16_t  BKE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  BKP        :  1;               /*!< (null)                                                                */
      __IO uint16_t  AOE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  MOE        :  1;               /*!< (null)                                                                */
    } BDTR_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED13;
  
  union {
    __IO uint16_t  DCR;                             /*!< DMA control register                                                  */
    
    struct {
      __IO uint16_t  DBA        :  5;               /*!< (null)                                                                */
           uint16_t             :  3;
      __IO uint16_t  DBL        :  5;               /*!< (null)                                                                */
    } DCR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED14;
  
  union {
    __IO uint16_t  DMAR;                            /*!< DMA address for full transfer                                         */
    
    struct {
      __IO uint16_t  DMAB       : 16;               /*!< (null)                                                                */
    } DMAR_b;                                       /*!< BitSize                                                               */
  };
} TIMER0_Type;


/* ================================================================================ */
/* ================                     TIMER1                     ================ */
/* ================================================================================ */


/**
  * @brief TIMER1 (TIMER1)
  */

typedef struct {                                    /*!< TIMER1 Structure                                                      */
  
  union {
    __IO uint16_t  CR1;                             /*!< control register 1                                                    */
    
    struct {
      __IO uint16_t  CEN        :  1;               /*!< (null)                                                                */
      __IO uint16_t  UDIS       :  1;               /*!< (null)                                                                */
      __IO uint16_t  URS        :  1;               /*!< (null)                                                                */
      __IO uint16_t  OPM        :  1;               /*!< (null)                                                                */
      __IO uint16_t  DIR        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CMS        :  2;               /*!< (null)                                                                */
      __IO uint16_t  ARPE       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CKD        :  2;               /*!< (null)                                                                */
    } CR1_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED0;
  
  union {
    __IO uint16_t  CR2;                             /*!< control register 2                                                    */
    
    struct {
      __IO uint16_t  CCPC       :  1;               /*!< (null)                                                                */
           uint16_t             :  1;
      __IO uint16_t  CCUS       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CCDS       :  1;               /*!< (null)                                                                */
      __IO uint16_t  MMS        :  3;               /*!< (null)                                                                */
      __IO uint16_t  TI1S       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS1       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS1N      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS2       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS2N      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS3       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS3N      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS4       :  1;               /*!< (null)                                                                */
    } CR2_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED1;
  
  union {
    __IO uint16_t  SMCR;                            /*!< slave mode control register                                           */
    
    struct {
      __IO uint16_t  SMS        :  3;               /*!< (null)                                                                */
           uint16_t             :  1;
      __IO uint16_t  TS         :  3;               /*!< (null)                                                                */
      __IO uint16_t  MSM        :  1;               /*!< (null)                                                                */
      __IO uint16_t  ETF        :  4;               /*!< (null)                                                                */
      __IO uint16_t  ETPS       :  2;               /*!< (null)                                                                */
      __IO uint16_t  ECE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  ETP        :  1;               /*!< (null)                                                                */
    } SMCR_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED2;
  
  union {
    __IO uint16_t  DIER;                            /*!< DMA/interrupt enable register                                         */
    
    struct {
      __IO uint16_t  UIE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMIE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  TIE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  BIE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  UDE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMDE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  TDE        :  1;               /*!< (null)                                                                */
    } DIER_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED3;
  
  union {
    __IO uint16_t  SR;                              /*!< status register                                                       */
    
    struct {
      __IO uint16_t  UIF        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMIF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  TIF        :  1;               /*!< (null)                                                                */
      __IO uint16_t  BIF        :  1;               /*!< (null)                                                                */
           uint16_t             :  1;
      __IO uint16_t  CC1OF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2OF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3OF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4OF      :  1;               /*!< (null)                                                                */
    } SR_b;                                         /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED4;
  
  union {
    __IO uint16_t  EGR;                             /*!< event generation register                                             */
    
    struct {
      __IO uint16_t  UG         :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMG       :  1;               /*!< (null)                                                                */
      __IO uint16_t  TG         :  1;               /*!< (null)                                                                */
      __IO uint16_t  BG         :  1;               /*!< (null)                                                                */
    } EGR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED5;
  
  union {
    __IO uint16_t  CCMR1_COMPARE;                   /*!< capture/compare mode register 1                                       */
    
    struct {
      __IO uint16_t  CC1S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC1FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC1PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC1M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC1CE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC2FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC2PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC2M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC2CE      :  1;               /*!< (null)                                                                */
    } CCMR1_COMPARE_b;                              /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED6;
  
  union {
    __IO uint16_t  CCMR2_COMPARE;                   /*!< capture/compare mode register 2                                       */
    
    struct {
      __IO uint16_t  CC3S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC3FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC3PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC3M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC3CE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC4FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC4PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC4M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC4CE      :  1;               /*!< (null)                                                                */
    } CCMR2_COMPARE_b;                              /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED7;
  
  union {
    __IO uint16_t  CCER;                            /*!< capture/compare enable register                                       */
    
    struct {
      __IO uint16_t  CC1E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1P       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1NE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1NP      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2P       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2NE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2NP      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3P       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3NE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3NP      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4P       :  1;               /*!< (null)                                                                */
    } CCER_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED8;
  
  union {
    __IO uint16_t  CNT;                             /*!< counter                                                               */
    
    struct {
      __IO uint16_t  CNT        : 16;               /*!< (null)                                                                */
    } CNT_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED9;
  
  union {
    __IO uint16_t  PSC;                             /*!< prescaler                                                             */
    
    struct {
      __IO uint16_t  PSC        : 16;               /*!< (null)                                                                */
    } PSC_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED10;
  
  union {
    __IO uint16_t  ARR;                             /*!< auto-reload register                                                  */
    
    struct {
      __IO uint16_t  ARR        : 16;               /*!< (null)                                                                */
    } ARR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED11;
  
  union {
    __IO uint16_t  RCR;                             /*!< repetition counter register                                           */
    
    struct {
      __IO uint16_t  REP        :  8;               /*!< (null)                                                                */
    } RCR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED12[9];
  
  union {
    __IO uint16_t  BDTR;                            /*!< break and dead-time register                                          */
    
    struct {
      __IO uint16_t  DTG        :  8;               /*!< (null)                                                                */
      __IO uint16_t  LOCK       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OSSI       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OSSR       :  1;               /*!< (null)                                                                */
      __IO uint16_t  BKE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  BKP        :  1;               /*!< (null)                                                                */
      __IO uint16_t  AOE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  MOE        :  1;               /*!< (null)                                                                */
    } BDTR_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED13;
  
  union {
    __IO uint16_t  DCR;                             /*!< DMA control register                                                  */
    
    struct {
      __IO uint16_t  DBA        :  5;               /*!< (null)                                                                */
           uint16_t             :  3;
      __IO uint16_t  DBL        :  5;               /*!< (null)                                                                */
    } DCR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED14;
  
  union {
    __IO uint16_t  DMAR;                            /*!< DMA address for full transfer                                         */
    
    struct {
      __IO uint16_t  DMAB       : 16;               /*!< (null)                                                                */
    } DMAR_b;                                       /*!< BitSize                                                               */
  };
} TIMER1_Type;


/* ================================================================================ */
/* ================                     TIMER2                     ================ */
/* ================================================================================ */


/**
  * @brief TIMER2 (TIMER2)
  */

typedef struct {                                    /*!< TIMER2 Structure                                                      */
  
  union {
    __IO uint16_t  CR1;                             /*!< control register 1                                                    */
    
    struct {
      __IO uint16_t  CEN        :  1;               /*!< (null)                                                                */
      __IO uint16_t  UDIS       :  1;               /*!< (null)                                                                */
      __IO uint16_t  URS        :  1;               /*!< (null)                                                                */
      __IO uint16_t  OPM        :  1;               /*!< (null)                                                                */
      __IO uint16_t  DIR        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CMS        :  2;               /*!< (null)                                                                */
      __IO uint16_t  ARPE       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CKD        :  2;               /*!< (null)                                                                */
    } CR1_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED0;
  
  union {
    __IO uint16_t  CR2;                             /*!< control register 2                                                    */
    
    struct {
      __IO uint16_t  CCPC       :  1;               /*!< (null)                                                                */
           uint16_t             :  1;
      __IO uint16_t  CCUS       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CCDS       :  1;               /*!< (null)                                                                */
      __IO uint16_t  MMS        :  3;               /*!< (null)                                                                */
      __IO uint16_t  TI1S       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS1       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS1N      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS2       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS2N      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS3       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS3N      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OIS4       :  1;               /*!< (null)                                                                */
    } CR2_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED1;
  
  union {
    __IO uint16_t  SMCR;                            /*!< slave mode control register                                           */
    
    struct {
      __IO uint16_t  SMS        :  3;               /*!< (null)                                                                */
           uint16_t             :  1;
      __IO uint16_t  TS         :  3;               /*!< (null)                                                                */
      __IO uint16_t  MSM        :  1;               /*!< (null)                                                                */
      __IO uint16_t  ETF        :  4;               /*!< (null)                                                                */
      __IO uint16_t  ETPS       :  2;               /*!< (null)                                                                */
      __IO uint16_t  ECE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  ETP        :  1;               /*!< (null)                                                                */
    } SMCR_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED2;
  
  union {
    __IO uint16_t  DIER;                            /*!< DMA/interrupt enable register                                         */
    
    struct {
      __IO uint16_t  UIE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4IE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMIE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  TIE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  BIE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  UDE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4DE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMDE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  TDE        :  1;               /*!< (null)                                                                */
    } DIER_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED3;
  
  union {
    __IO uint16_t  SR;                              /*!< status register                                                       */
    
    struct {
      __IO uint16_t  UIF        :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4IF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMIF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  TIF        :  1;               /*!< (null)                                                                */
      __IO uint16_t  BIF        :  1;               /*!< (null)                                                                */
           uint16_t             :  1;
      __IO uint16_t  CC1OF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2OF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3OF      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4OF      :  1;               /*!< (null)                                                                */
    } SR_b;                                         /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED4;
  
  union {
    __IO uint16_t  EGR;                             /*!< event generation register                                             */
    
    struct {
      __IO uint16_t  UG         :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4G       :  1;               /*!< (null)                                                                */
      __IO uint16_t  COMG       :  1;               /*!< (null)                                                                */
      __IO uint16_t  TG         :  1;               /*!< (null)                                                                */
      __IO uint16_t  BG         :  1;               /*!< (null)                                                                */
    } EGR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED5;
  
  union {
    __IO uint16_t  CCMR1_COMPARE;                   /*!< capture/compare mode register 1                                       */
    
    struct {
      __IO uint16_t  CC1S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC1FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC1PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC1M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC1CE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC2FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC2PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC2M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC2CE      :  1;               /*!< (null)                                                                */
    } CCMR1_COMPARE_b;                              /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED6;
  
  union {
    __IO uint16_t  CCMR2_COMPARE;                   /*!< capture/compare mode register 2                                       */
    
    struct {
      __IO uint16_t  CC3S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC3FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC3PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC3M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC3CE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4S       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OC4FE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC4PE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  OC4M       :  3;               /*!< (null)                                                                */
      __IO uint16_t  OC4CE      :  1;               /*!< (null)                                                                */
    } CCMR2_COMPARE_b;                              /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED7;
  
  union {
    __IO uint16_t  CCER;                            /*!< capture/compare enable register                                       */
    
    struct {
      __IO uint16_t  CC1E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1P       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1NE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC1NP      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2P       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2NE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC2NP      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3P       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3NE      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC3NP      :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4E       :  1;               /*!< (null)                                                                */
      __IO uint16_t  CC4P       :  1;               /*!< (null)                                                                */
    } CCER_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED8;
  
  union {
    __IO uint16_t  CNT;                             /*!< counter                                                               */
    
    struct {
      __IO uint16_t  CNT        : 16;               /*!< (null)                                                                */
    } CNT_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED9;
  
  union {
    __IO uint16_t  PSC;                             /*!< prescaler                                                             */
    
    struct {
      __IO uint16_t  PSC        : 16;               /*!< (null)                                                                */
    } PSC_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED10;
  
  union {
    __IO uint16_t  ARR;                             /*!< auto-reload register                                                  */
    
    struct {
      __IO uint16_t  ARR        : 16;               /*!< (null)                                                                */
    } ARR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED11;
  
  union {
    __IO uint16_t  RCR;                             /*!< repetition counter register                                           */
    
    struct {
      __IO uint16_t  REP        :  8;               /*!< (null)                                                                */
    } RCR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED12[9];
  
  union {
    __IO uint16_t  BDTR;                            /*!< break and dead-time register                                          */
    
    struct {
      __IO uint16_t  DTG        :  8;               /*!< (null)                                                                */
      __IO uint16_t  LOCK       :  2;               /*!< (null)                                                                */
      __IO uint16_t  OSSI       :  1;               /*!< (null)                                                                */
      __IO uint16_t  OSSR       :  1;               /*!< (null)                                                                */
      __IO uint16_t  BKE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  BKP        :  1;               /*!< (null)                                                                */
      __IO uint16_t  AOE        :  1;               /*!< (null)                                                                */
      __IO uint16_t  MOE        :  1;               /*!< (null)                                                                */
    } BDTR_b;                                       /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED13;
  
  union {
    __IO uint16_t  DCR;                             /*!< DMA control register                                                  */
    
    struct {
      __IO uint16_t  DBA        :  5;               /*!< (null)                                                                */
           uint16_t             :  3;
      __IO uint16_t  DBL        :  5;               /*!< (null)                                                                */
    } DCR_b;                                        /*!< BitSize                                                               */
  };
  __I  uint16_t  RESERVED14;
  
  union {
    __IO uint16_t  DMAR;                            /*!< DMA address for full transfer                                         */
    
    struct {
      __IO uint16_t  DMAB       : 16;               /*!< (null)                                                                */
    } DMAR_b;                                       /*!< BitSize                                                               */
  };
} TIMER2_Type;


/* ================================================================================ */
/* ================                       WDT                      ================ */
/* ================================================================================ */


/**
  * @brief WDT controller (WDT)
  */

typedef struct {                                    /*!< WDT Structure                                                         */
  
  union {
    __IO uint32_t  CR;                              /*!< Control register                                                      */
    
    struct {
      __IO uint32_t  WDT_EN     :  1;               /*!< WDT enable                                                            */
      __IO uint32_t  RMOD       :  1;               /*!< response mode                                                         */
      __IO uint32_t  RPL        :  3;               /*!< reset pulse length                                                    */
    } CR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TORR;                            /*!< Timeout range register                                                */
    
    struct {
      __IO uint32_t  TOP        :  4;               /*!< Timeout period                                                        */
      __IO uint32_t  TOP_INIT   :  4;               /*!< Timeout period for initialization                                     */
    } TORR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  CCVR;                            /*!< Current counter value register                                        */
    
    struct {
      __I  uint32_t  CCVR       : 32;               /*!< current value of the internal                                         */
    } CCVR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  CRR;                             /*!< Counter restart register                                              */
    
    struct {
      __O  uint32_t  CRR        :  8;               /*!< restart the WDT counter                                               */
    } CRR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  STAT;                            /*!< Interrupt status register                                             */
    
    struct {
      __I  uint32_t  STAT       :  1;               /*!< WDT interrupt status                                                  */
    } STAT_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  EOI;                             /*!< EOI                                                                   */
    
    struct {
      __I  uint32_t  EOI        : 32;               /*!< (null)                                                                */
    } EOI_b;                                        /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0;
  
  union {
    __IO  uint32_t  CLOCK_EN;                        /*!< EOI                                                                   */
    
    struct {
      __IO uint32_t  CLOCK_EN   :  1;               /*!< (null)                                                                */
    } CLOCK_EN_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[49];
  
  union {
    __I  uint32_t  WDT_COMP_PARAMS_5;               /*!< Component Parameters Register 5                                       */
    
    struct {
      __I  uint32_t  CP_WDT_USER_TOP_MAX: 32;       /*!< (null)                                                                */
    } WDT_COMP_PARAMS_5_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  WDT_COMP_PARAMS_4;               /*!< Component Parameters Register 4                                       */
    
    struct {
      __I  uint32_t  CP_WDT_USER_TOP_INIT_MAX: 32;  /*!< (null)                                                                */
    } WDT_COMP_PARAMS_4_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  WDT_COMP_PARAMS_3;               /*!< Component Parameters Register 3                                       */
    
    struct {
      __I  uint32_t  CD_WDT_TOP_RST: 32;            /*!< (null)                                                                */
    } WDT_COMP_PARAMS_3_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  WDT_COMP_PARAMS_2;               /*!< Component Parameters Register 2                                       */
    
    struct {
      __I  uint32_t  CP_WDT_CNT_RST: 32;            /*!< (null)                                                                */
    } WDT_COMP_PARAMS_2_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  WDT_COMP_PARAMS_1;               /*!< Component Parameters Register 1                                       */
    
    struct {
      __I  uint32_t  CP_WDT_ALWAYS_EN:  1;          /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_DFLT_RMOD:  1;          /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_DUAL_TOP:  1;           /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_HC_RMOD:  1;            /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_HC_RPL:  1;             /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_HC_TOP:  1;             /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_USE_FIX_TOP:  1;        /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_PAUSE:  1;              /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_APB_DATA_WIDTH:  2;     /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_DFLT_RPL:  3;           /*!< (null)                                                                */
      __I  uint32_t  Reserve    :  3;               /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_DFLT_TOP:  4;           /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_DFLT_TOP_INIT:  4;      /*!< (null)                                                                */
      __I  uint32_t  CP_WDT_CNT_WIDTH:  5;          /*!< (null)                                                                */
    } WDT_COMP_PARAMS_1_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  WDT_COMP_VERSION;                /*!< DesignWare Component Version register                                 */
    
    struct {
      __I  uint32_t  WDT_COMP_VERSION: 32;          /*!< (null)                                                                */
    } WDT_COMP_VERSION_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  WDT_COMP_TYPE;                   /*!< DesignWare Component Type register                                    */
    
    struct {
      __I  uint32_t  WDT_COMP_TYPE: 32;             /*!< (null)                                                                */
    } WDT_COMP_TYPE_b;                              /*!< BitSize                                                               */
  };
} WDT_Type;


/* ================================================================================ */
/* ================                       ADC                      ================ */
/* ================================================================================ */


/**
  * @brief SAR ADC (ADC)
  */

typedef struct {                                    /*!< ADC Structure                                                         */
  
  union {
    __IO uint32_t  INTR;                            /*!< Interrupt Status Register                                             */
    
    struct {
      __IO uint32_t  EOC0       :  1;               /*!< (null)                                                                */
      __IO uint32_t  EOC1       :  1;               /*!< (null)                                                                */
      __IO uint32_t  EOC2       :  1;               /*!< (null)                                                                */
      __IO uint32_t  EOC3       :  1;               /*!< (null)                                                                */
      __IO uint32_t  EOC4       :  1;               /*!< (null)                                                                */
      __IO uint32_t  EOC5       :  1;               /*!< (null)                                                                */
      __IO uint32_t  EOC6       :  1;               /*!< (null)                                                                */
      __IO uint32_t  EOS        :  1;               /*!< (null)                                                                */
    } INTR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  INTR_MASK;                       /*!< Interrupt Mask Register                                               */
    
    struct {
      __IO uint32_t  MASK_EOC0  :  1;               /*!< (null)                                                                */
      __IO uint32_t  MASK_EOC1  :  1;               /*!< (null)                                                                */
      __IO uint32_t  MASK_EOC2  :  1;               /*!< (null)                                                                */
      __IO uint32_t  MASK_EOC3  :  1;               /*!< (null)                                                                */
      __IO uint32_t  MASK_EOC4  :  1;               /*!< (null)                                                                */
      __IO uint32_t  MASK_EOC5  :  1;               /*!< (null)                                                                */
      __IO uint32_t  MASK_EOC6  :  1;               /*!< (null)                                                                */
      __IO uint32_t  MASK_EOS   :  1;               /*!< (null)                                                                */
    } INTR_MASK_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CR;                              /*!< Control Register                                                      */
    
    struct {
      __IO uint32_t  SW_START   :  1;               /*!< (null)                                                                */
      __IO uint32_t  ADC_STOP   :  1;               /*!< (null)                                                                */
    } CR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG;                             /*!< Configuration Register                                                */
    
    struct {
      __IO uint32_t  CONT       :  1;               /*!< (null)                                                                */
      __IO uint32_t  ALIGN_0_right:  1;             /*!< (null)                                                                */
      __IO uint32_t  HW_START_EN:  1;               /*!< (null)                                                                */
      __IO uint32_t  SCANDIR_0_inc:  1;             /*!< (null)                                                                */
      __IO uint32_t  START_SRC  :  2;               /*!< (null)                                                                */
      __IO uint32_t  START_MODE_00_posedge:  2;     /*!< (null)                                                                */
      __IO uint32_t  DISCEN_0_continue:  1;         /*!< (null)                                                                */
      __IO uint32_t  TEST_MODE  :  1;               /*!< (null)                                                                */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHSELR;                          /*!< Channel Select Register                                               */
    
    struct {
      __IO uint32_t  CHMAP      :  7;               /*!< (null)                                                                */
    } CHSELR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTCTRL0;                       /*!< Common Analog Control Register                                        */
    
    struct {
      __IO uint32_t  pd_sheld   :  1;               /*!< (null)                                                                */
      __IO uint32_t  pd_core_lv :  1;               /*!< (null)                                                                */
      __IO uint32_t  pd_ldo_hv  :  1;               /*!< (null)                                                                */
    } TESTCTRL0_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTCTRL1;                       /*!< Channel 0 Analog Control Register                                     */
    
    struct {
      __IO uint32_t  chk0_en_rail:  1;              /*!< (null)                                                                */
      __IO uint32_t  chk0_gain_amp:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk0_sel_vcm:  4;              /*!< (null)                                                                */
      __IO uint32_t  chk0_rf_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  chk0_sel_amp_hv:  2;           /*!< (null)                                                                */
      __IO uint32_t  chk0_ctrl_ldo:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk0_chopper_freq:  2;         /*!< (null)                                                                */
      __IO uint32_t  chk0_en_chopper:  1;           /*!< (null)                                                                */
    } TESTCTRL1_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTCTRL2;                       /*!< Channel 1 Analog Control Register                                     */
    
    struct {
      __IO uint32_t  chk1_en_rail:  1;              /*!< (null)                                                                */
      __IO uint32_t  chk1_gain_amp:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk1_sel_vcm:  4;              /*!< (null)                                                                */
      __IO uint32_t  chk1_rf_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  chk1_sel_amp_hv:  2;           /*!< (null)                                                                */
      __IO uint32_t  chk1_ctrl_ldo:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk1_chopper_freq:  2;         /*!< (null)                                                                */
      __IO uint32_t  chk1_en_chopper:  1;           /*!< (null)                                                                */
    } TESTCTRL2_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTCTRL3;                       /*!< Channel 2 Analog Control Register                                     */
    
    struct {
      __IO uint32_t  chk2_en_rail:  1;              /*!< (null)                                                                */
      __IO uint32_t  chk2_gain_amp:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk2_sel_vcm:  4;              /*!< (null)                                                                */
      __IO uint32_t  chk2_rf_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  chk2_sel_amp_hv:  2;           /*!< (null)                                                                */
      __IO uint32_t  chk2_ctrl_ldo:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk2_chopper_freq:  2;         /*!< (null)                                                                */
      __IO uint32_t  chk2_en_chopper:  1;           /*!< (null)                                                                */
    } TESTCTRL3_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTCTRL4;                       /*!< Channel 3 Analog Control Register                                     */
    
    struct {
      __IO uint32_t  chk3_en_rail:  1;              /*!< (null)                                                                */
      __IO uint32_t  chk3_gain_amp:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk3_sel_vcm:  4;              /*!< (null)                                                                */
      __IO uint32_t  chk3_rf_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  chk3_sel_amp_hv:  2;           /*!< (null)                                                                */
      __IO uint32_t  chk3_ctrl_ldo:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk3_chopper_freq:  2;         /*!< (null)                                                                */
      __IO uint32_t  chk3_en_chopper:  1;           /*!< (null)                                                                */
    } TESTCTRL4_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTCTRL5;                       /*!< Channel 4 Analog Control Register                                     */
    
    struct {
      __IO uint32_t  chk4_en_rail:  1;              /*!< (null)                                                                */
      __IO uint32_t  chk4_gain_amp:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk4_sel_vcm:  4;              /*!< (null)                                                                */
      __IO uint32_t  chk4_rf_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  chk4_sel_amp_hv:  2;           /*!< (null)                                                                */
      __IO uint32_t  chk4_ctrl_ldo:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk4_chopper_freq:  2;         /*!< (null)                                                                */
      __IO uint32_t  chk4_en_chopper:  1;           /*!< (null)                                                                */
    } TESTCTRL5_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTCTRL6;                       /*!< Channel 5 Analog Control Register                                     */
    
    struct {
      __IO uint32_t  chk5_en_rail:  1;              /*!< (null)                                                                */
      __IO uint32_t  chk5_gain_amp:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk5_sel_vcm:  4;              /*!< (null)                                                                */
      __IO uint32_t  chk5_rf_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  chk5_sel_amp_hv:  2;           /*!< (null)                                                                */
      __IO uint32_t  chk5_ctrl_ldo:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk5_chopper_freq:  2;         /*!< (null)                                                                */
      __IO uint32_t  chk5_en_chopper:  1;           /*!< (null)                                                                */
    } TESTCTRL6_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTCTRL7;                       /*!< Channel 6 Analog Control Register                                     */
    
    struct {
      __IO uint32_t  chk6_en_rail:  1;              /*!< (null)                                                                */
      __IO uint32_t  chk6_gain_amp:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk6_sel_vcm:  4;              /*!< (null)                                                                */
      __IO uint32_t  chk6_rf_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  chk6_sel_amp_hv:  2;           /*!< (null)                                                                */
      __IO uint32_t  chk6_ctrl_ldo:  2;             /*!< (null)                                                                */
      __IO uint32_t  chk6_chopper_freq:  2;         /*!< (null)                                                                */
      __IO uint32_t  chk6_en_chopper:  1;           /*!< (null)                                                                */
    } TESTCTRL7_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK0_DATA;                       /*!< Channel 0 Data Register                                               */
    
    struct {
      __IO uint32_t  chk0_data  : 32;               /*!< (null)                                                                */
    } CHK0_DATA_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK1_DATA;                       /*!< Channel 0 Data Register                                               */
    
    struct {
      __IO uint32_t  chk1_data  : 32;               /*!< (null)                                                                */
    } CHK1_DATA_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK2_DATA;                       /*!< Channel 0 Data Register                                               */
    
    struct {
      __IO uint32_t  chk2_data  : 32;               /*!< (null)                                                                */
    } CHK2_DATA_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK3_DATA;                       /*!< Channel 0 Data Register                                               */
    
    struct {
      __IO uint32_t  chk3_data  : 32;               /*!< (null)                                                                */
    } CHK3_DATA_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK4_DATA;                       /*!< Channel 0 Data Register                                               */
    
    struct {
      __IO uint32_t  chk4_data  : 32;               /*!< (null)                                                                */
    } CHK4_DATA_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK5_DATA;                       /*!< Channel 0 Data Register                                               */
    
    struct {
      __IO uint32_t  chk6_data  : 32;               /*!< (null)                                                                */
    } CHK5_DATA_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK6_DATA;                       /*!< Channel 0 Data Register                                               */
    
    struct {
      __IO uint32_t  chk6_data  : 32;               /*!< (null)                                                                */
    } CHK6_DATA_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTCFG;                         /*!< Sample and Convert Time Config                                        */
    
    struct {
      __IO uint32_t  time_stable: 10;               /*!< (null)                                                                */
    } TESTCFG_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK0_TIME;                       /*!< Channel 0 Switch Time Config                                          */
    
    struct {
      __IO uint32_t  chk0_time_switch: 10;          /*!< (null)                                                                */
    } CHK0_TIME_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK1_TIME;                       /*!< Channel 1 Switch Time Config                                          */
    
    struct {
      __IO uint32_t  chk1_time_switch: 10;          /*!< (null)                                                                */
    } CHK1_TIME_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK2_TIME;                       /*!< Channel 2 Switch Time Config                                          */
    
    struct {
      __IO uint32_t  chk2_time_switch: 10;          /*!< (null)                                                                */
    } CHK2_TIME_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK3_TIME;                       /*!< Channel 3 Switch Time Config                                          */
    
    struct {
      __IO uint32_t  chk3_time_switch: 10;          /*!< (null)                                                                */
    } CHK3_TIME_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK4_TIME;                       /*!< Channel 4 Switch Time Config                                          */
    
    struct {
      __IO uint32_t  chk4_time_switch: 10;          /*!< (null)                                                                */
    } CHK4_TIME_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK5_TIME;                       /*!< Channel 5 Switch Time Config                                          */
    
    struct {
      __IO uint32_t  chk5_time_switch: 10;          /*!< (null)                                                                */
    } CHK5_TIME_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHK6_TIME;                       /*!< Channel 6 Switch Time Config                                          */
    
    struct {
      __IO uint32_t  chk6_time_switch: 10;          /*!< (null)                                                                */
    } CHK6_TIME_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TIMER_SEL;                       /*!< Hardware Time Channel Select                                          */
    
    struct {
      __IO uint32_t  timer1_select:  2;             /*!< (null)                                                                */
      __IO uint32_t  timer2_select:  2;             /*!< (null)                                                                */
      __IO uint32_t  timer3_select:  2;             /*!< (null)                                                                */
    } TIMER_SEL_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TESTDATA;                        /*!< Test Data Register for debug                                          */
    
    struct {
      __IO uint32_t  testdata   : 10;               /*!< (null)                                                                */
    } TESTDATA_b;                                   /*!< BitSize                                                               */
  };
} ADC_Type;


/* ================================================================================ */
/* ================                      CODEC                     ================ */
/* ================================================================================ */


/**
  * @brief CODEC controller (CODEC)
  */

typedef struct {                                    /*!< CODEC Structure                                                       */
  
  union {
    __IO uint32_t  ADC_CTRL;                        /*!< ADC status control                                                    */
    
    struct {
      __IO uint32_t  adc_en     :  1;               /*!< (null)                                                                */
      __IO uint32_t  adc_sw_reset_x:  1;            /*!< (null)                                                                */
      __IO uint32_t  dmic_en    :  1;               /*!< (null)                                                                */
      __IO uint32_t  adc_dc_en  :  1;               /*!< (null)                                                                */
      __IO uint32_t  adc_cic_scale:  3;             /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  adc_sr_1x  :  1;               /*!< (null)                                                                */
      __IO uint32_t  adc_sr_2x  :  1;               /*!< (null)                                                                */
      __IO uint32_t  adc_sr_4x  :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  adc_sr_48k :  1;               /*!< (null)                                                                */
      __IO uint32_t  adc_sr_44k :  1;               /*!< (null)                                                                */
      __IO uint32_t  adc_sr_32k :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  adc_input_inv:  1;             /*!< (null)                                                                */
    } ADC_CTRL_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_11;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b1_a1: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b1_a2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_11_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_12;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b1_b0: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b1_b1: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_12_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_13;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b1_b2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_13_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_21;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b2_a1: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b2_a2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_21_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_22;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b2_b0: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b2_b1: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_22_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_23;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b2_b2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_23_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_31;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b3_a1: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b3_a2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_31_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_32;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b3_b0: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b3_b1: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_32_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_33;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b3_b2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_33_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_41;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b4_a1: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b4_a2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_41_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_42;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b4_b0: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b4_b1: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_42_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_43;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b4_b2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_43_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_51;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b5_a1: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b5_a2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_51_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_52;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b5_b0: 16;            /*!< (null)                                                                */
      __IO uint32_t  adc_deci_b5_b1: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_52_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DECI_FILT_53;                /*!< ADC decimation filter coefficients                                    */
    
    struct {
      __IO uint32_t  adc_deci_b5_b2: 16;            /*!< (null)                                                                */
    } ADC_DECI_FILT_53_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_IIR_FILT_11;                 /*!< ADC iir filter coefficients                                           */
    
    struct {
      __IO uint32_t  adc_iir_b1_a1: 16;             /*!< (null)                                                                */
      __IO uint32_t  adc_iir_b1_a2: 16;             /*!< (null)                                                                */
    } ADC_IIR_FILT_11_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_IIR_FILT_12;                 /*!< ADC iir filter coefficients                                           */
    
    struct {
      __IO uint32_t  adc_iir_b1_b0: 16;             /*!< (null)                                                                */
      __IO uint32_t  adc_iir_b1_b1: 16;             /*!< (null)                                                                */
    } ADC_IIR_FILT_12_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_IIR_FILT_13;                 /*!< ADC iir filter coefficients                                           */
    
    struct {
      __IO uint32_t  adc_iir_b1_b2: 16;             /*!< (null)                                                                */
      __IO uint32_t  adc_iir_bps:  1;               /*!< (null)                                                                */
    } ADC_IIR_FILT_13_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_IIR_FILT_21;                 /*!< ADC iir filter coefficients                                           */
    
    struct {
      __IO uint32_t  adc_iir_b2_a1: 16;             /*!< (null)                                                                */
      __IO uint32_t  adc_iir_b2_a2: 16;             /*!< (null)                                                                */
    } ADC_IIR_FILT_21_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_IIR_FILT_22;                 /*!< ADC iir filter coefficients                                           */
    
    struct {
      __IO uint32_t  adc_iir_b2_b0: 16;             /*!< (null)                                                                */
      __IO uint32_t  adc_iir_b2_b1: 16;             /*!< (null)                                                                */
    } ADC_IIR_FILT_22_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_IIR_FILT_23;                 /*!< ADC iir filter coefficients                                           */
    
    struct {
      __IO uint32_t  adc_iir_b2_b2: 16;             /*!< (null)                                                                */
    } ADC_IIR_FILT_23_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_IIR_FILT_31;                 /*!< ADC iir filter coefficients                                           */
    
    struct {
      __IO uint32_t  adc_iir_b3_a1: 16;             /*!< (null)                                                                */
      __IO uint32_t  adc_iir_b3_a2: 16;             /*!< (null)                                                                */
    } ADC_IIR_FILT_31_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_IIR_FILT_32;                 /*!< ADC iir filter coefficients                                           */
    
    struct {
      __IO uint32_t  adc_iir_b3_b0: 16;             /*!< (null)                                                                */
      __IO uint32_t  adc_iir_b3_b1: 16;             /*!< (null)                                                                */
    } ADC_IIR_FILT_32_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_IIR_FILT_33;                 /*!< ADC iir filter coefficients                                           */
    
    struct {
      __IO uint32_t  adc_iir_b3_b2: 16;             /*!< (null)                                                                */
    } ADC_IIR_FILT_33_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DRC_CTRL_1;                  /*!< ADC drc control registers                                             */
    
    struct {
      __IO uint32_t  adc_drc_at0: 16;               /*!< (null)                                                                */
      __IO uint32_t  adc_drc_at1: 16;               /*!< (null)                                                                */
    } ADC_DRC_CTRL_1_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DRC_CTRL_2;                  /*!< ADC drc control registers                                             */
    
    struct {
      __IO uint32_t  adc_drc_rt0: 16;               /*!< (null)                                                                */
      __IO uint32_t  adc_drc_rt1: 16;               /*!< (null)                                                                */
    } ADC_DRC_CTRL_2_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DRC_CTRL_3;                  /*!< ADC drc control registers                                             */
    
    struct {
      __IO uint32_t  adc_drc_mode_sel:  2;          /*!< (null)                                                                */
      __IO uint32_t  adc_drc_lt :  5;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  adc_drc_ct :  7;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  adc_drc_et :  7;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  adc_drc_nt :  3;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  adc_drc_gain_jitter_limit:  4; /*!< (null)                                                                */
    } ADC_DRC_CTRL_3_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DRC_CTRL_4;                  /*!< ADC drc control registers                                             */
    
    struct {
      __IO uint32_t  adc_drc_cs :  3;               /*!< (null)                                                                */
      __IO uint32_t  adc_drc_es :  3;               /*!< (null)                                                                */
      __IO uint32_t  adc_drc_delay:  2;             /*!< (null)                                                                */
      __IO uint32_t  adc_drc_ns_mode:  1;           /*!< (null)                                                                */
      __IO uint32_t  adc_drc_es_inv:  1;            /*!< (null)                                                                */
      __IO uint32_t  adc_drc_gain_shft:  2;         /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  adc_drc_gain_pos_limit:  8;    /*!< (null)                                                                */
      __IO uint32_t  adc_drc_gain_neg_limit:  8;    /*!< (null)                                                                */
    } ADC_DRC_CTRL_4_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DRC_CTRL_5;                  /*!< ADC drc control registers                                             */
    
    struct {
      __IO uint32_t  adc_drc_tav: 16;               /*!< (null)                                                                */
      __IO uint32_t  adc_drc_rms_en:  1;            /*!< (null)                                                                */
    } ADC_DRC_CTRL_5_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_VOL_CTRL;                    /*!< ADC volume control registers                                          */
    
    struct {
      __IO uint32_t  adcmu      :  1;               /*!< (null)                                                                */
      __IO uint32_t  adcunmu    :  1;               /*!< (null)                                                                */
      __IO uint32_t  adc_mute_bypass:  1;           /*!< (null)                                                                */
      __IO uint32_t  adc_mix_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  adc_mute_rate:  4;             /*!< (null)                                                                */
      __IO uint32_t  ladcvol    :  8;               /*!< (null)                                                                */
      __IO uint32_t  radcvol    :  8;               /*!< (null)                                                                */
      __IO uint32_t  adc_vol_update:  1;            /*!< (null)                                                                */
    } ADC_VOL_CTRL_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_SIDE_CTRL;                   /*!< ADC side control register                                             */
    
    struct {
      __IO uint32_t  adc_side_gl:  8;               /*!< (null)                                                                */
      __IO uint32_t  adc_side_gr:  8;               /*!< (null)                                                                */
      __IO uint32_t  adc_side_en:  1;               /*!< (null)                                                                */
    } ADC_SIDE_CTRL_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_EQ_CTRL_1;                   /*!< DAC eq control registers                                              */
    
    struct {
      __IO uint32_t  dac_eq_b1_a: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_eq_b1_ga:  5;              /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  dac_eq_bps :  1;               /*!< (null)                                                                */
    } DAC_EQ_CTRL_1_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_EQ_CTRL_2;                   /*!< DAC eq control registers                                              */
    
    struct {
      __IO uint32_t  dac_eq_b2_a: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_eq_b2_b: 16;               /*!< (null)                                                                */
    } DAC_EQ_CTRL_2_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_EQ_CTRL_3;                   /*!< DAC eq control registers                                              */
    
    struct {
      __IO uint32_t  dac_eq_b3_a: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_eq_b3_b: 16;               /*!< (null)                                                                */
    } DAC_EQ_CTRL_3_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_EQ_CTRL_4;                   /*!< DAC eq control registers                                              */
    
    struct {
      __IO uint32_t  dac_eq_b4_a: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_eq_b4_b: 16;               /*!< (null)                                                                */
    } DAC_EQ_CTRL_4_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_EQ_CTRL_5;                   /*!< DAC eq control registers                                              */
    
    struct {
      __IO uint32_t  dac_eq_b5_a: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_eq_b5_b: 16;               /*!< (null)                                                                */
    } DAC_EQ_CTRL_5_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_EQ_CTRL_6;                   /*!< DAC eq control registers                                              */
    
    struct {
      __IO uint32_t  dac_eq_b6_a: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_eq_b6_b: 16;               /*!< (null)                                                                */
    } DAC_EQ_CTRL_6_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_EQ_CTRL_7;                   /*!< DAC eq control registers                                              */
    
    struct {
      __IO uint32_t  dac_eq_b7_a: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_eq_b6_ga:  5;              /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  dac_eq_b7_ga:  5;              /*!< (null)                                                                */
    } DAC_EQ_CTRL_7_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_EQ_CTRL_8;                   /*!< DAC eq control registers                                              */
    
    struct {
      __IO uint32_t  dac_eq_b2_ga:  5;              /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  dac_eq_b3_ga:  5;              /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  dac_eq_b4_ga:  5;              /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  dac_eq_b5_ga:  5;              /*!< (null)                                                                */
    } DAC_EQ_CTRL_8_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_DRC_CTRL_1;                  /*!< DAC drc control registers                                             */
    
    struct {
      __IO uint32_t  dac_drc_at0: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_drc_at1: 16;               /*!< (null)                                                                */
    } DAC_DRC_CTRL_1_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_DRC_CTRL_2;                  /*!< DAC drc control registers                                             */
    
    struct {
      __IO uint32_t  dac_drc_rt0: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_drc_rt1: 16;               /*!< (null)                                                                */
    } DAC_DRC_CTRL_2_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_DRC_CTRL_3;                  /*!< DAC drc control registers                                             */
    
    struct {
      __IO uint32_t  dac_drc_mode_sel:  2;          /*!< (null)                                                                */
      __IO uint32_t  dac_drc_lt :  5;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  dac_drc_ct :  7;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  dac_drc_et :  7;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  dac_drc_nt :  3;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  dac_drc_gain_jitter_limit:  4; /*!< (null)                                                                */
    } DAC_DRC_CTRL_3_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_DRC_CTRL_4;                  /*!< DAC drc control registers                                             */
    
    struct {
      __IO uint32_t  dac_drc_cs :  3;               /*!< (null)                                                                */
      __IO uint32_t  dac_drc_es :  3;               /*!< (null)                                                                */
      __IO uint32_t  dac_drc_delay:  2;             /*!< (null)                                                                */
      __IO uint32_t  dac_drc_ns_mode:  1;           /*!< (null)                                                                */
      __IO uint32_t  dac_drc_es_inv:  1;            /*!< (null)                                                                */
      __IO uint32_t  dac_drc_gain_shft:  2;         /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  dac_drc_gain_pos_limit:  8;    /*!< (null)                                                                */
      __IO uint32_t  dac_drc_gain_neg_limit:  8;    /*!< (null)                                                                */
    } DAC_DRC_CTRL_4_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_DRC_CTRL_5;                  /*!< DAC drc control registers                                             */
    
    struct {
      __IO uint32_t  dac_drc_tav: 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_drc_rms_en:  1;            /*!< (null)                                                                */
    } DAC_DRC_CTRL_5_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_VOL_CTRL;                    /*!< DAC volume control registers                                          */
    
    struct {
      __IO uint32_t  dacmu      :  1;               /*!< (null)                                                                */
      __IO uint32_t  dacunmu    :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_mute_bypass:  1;           /*!< (null)                                                                */
      __IO uint32_t  dac_mix_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_mute_rate:  4;             /*!< (null)                                                                */
      __IO uint32_t  ldacvol    :  8;               /*!< (null)                                                                */
      __IO uint32_t  rdacvol    :  8;               /*!< (null)                                                                */
      __IO uint32_t  dac_vol_update:  1;            /*!< (null)                                                                */
    } DAC_VOL_CTRL_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_MOD_CTRL;                    /*!< DAC modulator control regiseters                                      */
    
    struct {
      __IO uint32_t  dac_dither_in_sel:  1;         /*!< (null)                                                                */
      __IO uint32_t  dac_dither_en:  1;             /*!< (null)                                                                */
      __IO uint32_t  dac_dither_static_en:  1;      /*!< (null)                                                                */
      __IO uint32_t  dac_dither_rpdf_en:  1;        /*!< (null)                                                                */
      __IO uint32_t  dac_dither_scale:  2;          /*!< (null)                                                                */
    } DAC_MOD_CTRL_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_CTRL;                        /*!< DAC status control                                                    */
    
    struct {
      __IO uint32_t  dac_sr_1x  :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_sr_2x  :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_sr_4x  :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  dac_sr_48k :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_sr_44k :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_sr_32k :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_sr_96k :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_en     :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_sw_reset_x:  1;            /*!< (null)                                                                */
      __IO uint32_t  dac_fir_clr:  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_rom_sel_32k:  1;           /*!< (null)                                                                */
    } DAC_CTRL_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TEST_MODE;                       /*!< codec test mode control registers                                     */
    
    struct {
      __IO uint32_t  adc_loopbk :  1;               /*!< (null)                                                                */
      __IO uint32_t  a2dloop    :  1;               /*!< (null)                                                                */
      __IO uint32_t  dac_phy_mode:  1;              /*!< (null)                                                                */
      __IO uint32_t  codec_full_loop:  1;           /*!< (null)                                                                */
      __IO uint32_t  codec_typass:  1;              /*!< (null)                                                                */
    } TEST_MODE_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  GAIN_READ;                       /*!< adc/dac gain control read out                                         */
    
    struct {
      __I  uint32_t  adc_gainl_mon:  8;             /*!< (null)                                                                */
      __I  uint32_t  adc_gainr_mon:  8;             /*!< (null)                                                                */
      __I  uint32_t  dac_gainl_mon:  8;             /*!< (null)                                                                */
      __I  uint32_t  dac_gainr_mon:  8;             /*!< (null)                                                                */
    } GAIN_READ_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLK_CTRL_1;                      /*!< audio clock contorl registers                                         */
    
    struct {
      __IO uint32_t  codec_rstn_reg:  1;            /*!< (null)                                                                */
      __IO uint32_t  codec_clk_en_reg:  1;          /*!< (null)                                                                */
      __IO uint32_t  pcm_clk_inv:  1;               /*!< (null)                                                                */
    } CLK_CTRL_1_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLK_CTRL_2;                      /*!< audio clock control registers                                         */
    
    struct {
      __IO uint32_t  div_clk_en :  4;               /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  dmic_clk_sel:  1;              /*!< (null)                                                                */
      __IO uint32_t  i2s_tx_sel :  3;               /*!< (null)                                                                */
      __IO uint32_t  i2s_tx_odd :  1;               /*!< (null)                                                                */
      __IO uint32_t  i2s_tx_high_num:  8;           /*!< (null)                                                                */
      __IO uint32_t  i2s_rx_sel :  3;               /*!< (null)                                                                */
      __IO uint32_t  i2s_rx_odd :  1;               /*!< (null)                                                                */
      __IO uint32_t  i2s_rx_high_num:  8;           /*!< (null)                                                                */
    } CLK_CTRL_2_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DITHER_CTRL_1;               /*!< adc dither control registers                                          */
    
    struct {
      __IO uint32_t  adc_dither_thd: 12;            /*!< (null)                                                                */
      __IO uint32_t  adc_dither_pd:  1;             /*!< (null)                                                                */
      __IO uint32_t  adc_dither_en:  1;             /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  pnoise_en  :  1;               /*!< (null)                                                                */
    } ADC_DITHER_CTRL_1_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_DITHER_CTRL_2;               /*!< adc dither control registers                                          */
    
    struct {
      __IO uint32_t  adc_dither_at: 16;             /*!< (null)                                                                */
      __IO uint32_t  adc_dither_rt: 16;             /*!< (null)                                                                */
    } ADC_DITHER_CTRL_2_b;                          /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_DITHER_CTRL;                 /*!< dac dither control registers                                          */
    
    struct {
      __IO uint32_t  dac_dither_at: 16;             /*!< (null)                                                                */
      __IO uint32_t  dac_dither_rt: 16;             /*!< (null)                                                                */
    } DAC_DITHER_CTRL_b;                            /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  INT_STATUS;                      /*!< codec interrupt status                                                */
    
    struct {
      __I  uint32_t  plug_det_int:  1;              /*!< (null)                                                                */
      __I  uint32_t  unplug_det_int:  1;            /*!< (null)                                                                */
      __I  uint32_t  drv_ocp_l_int:  1;             /*!< (null)                                                                */
      __I  uint32_t  drv_ocp_r_int:  1;             /*!< (null)                                                                */
      __I  uint32_t  codec_int  :  1;               /*!< (null)                                                                */
           uint32_t             :  3;
      __I  uint32_t  plug_det_sync:  1;             /*!< (null)                                                                */
      __I  uint32_t  drv_ocp_l_sync:  1;            /*!< (null)                                                                */
      __I  uint32_t  drv_ocp_r_sync:  1;            /*!< (null)                                                                */
      __I  uint32_t  micbias_cmp_out_sync:  1;      /*!< (null)                                                                */
    } INT_STATUS_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  INT_CTRL;                        /*!< codec interrupt control                                               */
    
    struct {
      __IO uint32_t  plug_det_int_im:  1;           /*!< (null)                                                                */
      __IO uint32_t  unplug_det_int_im:  1;         /*!< (null)                                                                */
      __IO uint32_t  drv_ocp_l_int_im:  1;          /*!< (null)                                                                */
      __IO uint32_t  drv_ocp_r_int_im:  1;          /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  plug_det_db_en:  1;            /*!< (null)                                                                */
      __IO uint32_t  drv_ocp_l_db_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  drv_ocp_r_db_en:  1;           /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  plug_det_edge_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  drv_ocp_l_edge_en:  1;         /*!< (null)                                                                */
      __IO uint32_t  drv_ocp_r_edge_en:  1;         /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  plug_det_pol_sel:  1;          /*!< (null)                                                                */
      __IO uint32_t  drv_ocp_l_pol_sel:  1;         /*!< (null)                                                                */
      __IO uint32_t  drv_ocp_r_pol_sel:  1;         /*!< (null)                                                                */
      __IO uint32_t  codec_int_pol_sel:  1;         /*!< (null)                                                                */
    } INT_CTRL_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ANA_CTRL_1;                      /*!< analog control registers                                              */
    
    struct {
      __IO uint32_t  reg_PD_ADC_L:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_PD_ADC_R:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_PD_AUREF:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_PD_BIAS_GEN:  1;           /*!< (null)                                                                */
      __IO uint32_t  reg_PD_CLK :  1;               /*!< (null)                                                                */
      __IO uint32_t  reg_PD_DAC_L:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_PD_DAC_R:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_PD_DRV_L:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_PD_DRV_R:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_PD_LDO_AUD:  1;            /*!< (null)                                                                */
      __IO uint32_t  reg_PD_LDO_AVDD12:  1;         /*!< (null)                                                                */
      __IO uint32_t  reg_PD_LDO_DRV:  1;            /*!< (null)                                                                */
      __IO uint32_t  reg_PD_LDO_DVDD:  1;           /*!< (null)                                                                */
      __IO uint32_t  reg_PD_MICBIAS:  1;            /*!< (null)                                                                */
      __IO uint32_t  reg_PD_MICBIAS_CALI:  1;       /*!< (null)                                                                */
      __IO uint32_t  reg_PD_PGA_L:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_PD_PGA_R:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_PD_TIA_DRV_L:  1;          /*!< (null)                                                                */
      __IO uint32_t  reg_PD_TIA_DRV_R:  1;          /*!< (null)                                                                */
      __IO uint32_t  reg_PD_plug_detect:  1;        /*!< (null)                                                                */
      __IO uint32_t  reg_EN_ADC_DEM:  1;            /*!< (null)                                                                */
      __IO uint32_t  reg_EN_ADC_DITHER:  1;         /*!< (null)                                                                */
      __IO uint32_t  reg_ADDA_seltest:  1;          /*!< (null)                                                                */
      __IO uint32_t  reg_AUADC_TSTSEL:  3;          /*!< (null)                                                                */
      __IO uint32_t  reg_AUDIO_BIAS_TST:  1;        /*!< (null)                                                                */
      __IO uint32_t  reg_AUDIO_TSTSEL:  3;          /*!< (null)                                                                */
      __IO uint32_t  reg_DAC_DEM:  1;               /*!< (null)                                                                */
      __IO uint32_t  reg_DET_SEL:  1;               /*!< (null)                                                                */
    } ANA_CTRL_1_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ANA_CTRL_2;                      /*!< analog control register2                                              */
    
    struct {
      __IO uint32_t  reg_DRV_GAIN:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_DRV_OCP_EN:  1;            /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  reg_LDO_AUD_CTRL:  2;          /*!< (null)                                                                */
      __IO uint32_t  reg_LDO_DRV_CTRL:  2;          /*!< (null)                                                                */
      __IO uint32_t  reg_MICBIAS_CC:  1;            /*!< (null)                                                                */
      __IO uint32_t  reg_MICBIAS_tune:  4;          /*!< (null)                                                                */
      __IO uint32_t  reg_PGA_GAIN:  3;              /*!< (null)                                                                */
      __IO uint32_t  reg_Rctune :  4;               /*!< (null)                                                                */
      __IO uint32_t  reg_REF_BYP:  1;               /*!< (null)                                                                */
      __IO uint32_t  reg_REF_fast:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_REF_ADC:  1;               /*!< (null)                                                                */
      __IO uint32_t  reg_SEL_ADC_INPUT:  1;         /*!< (null)                                                                */
      __IO uint32_t  reg_SEL_PGA_INPUT:  1;         /*!< (null)                                                                */
      __IO uint32_t  reg_SHRT_ADC:  1;              /*!< (null)                                                                */
      __IO uint32_t  reg_TST_AUADC_ibias:  1;       /*!< (null)                                                                */
      __IO uint32_t  reg_TST_EN :  1;               /*!< (null)                                                                */
      __IO uint32_t  reg_bias_sel:  2;              /*!< (null)                                                                */
    } ANA_CTRL_2_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RSVD_1;                          /*!< reserved registers                                                    */
    
    struct {
      __IO uint32_t  rsvd_reg_1 : 32;               /*!< (null)                                                                */
    } RSVD_1_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ADC_PEAK_READ;                   /*!< adc signal peak value                                                 */
    
    struct {
      __IO uint32_t  adc_peak_l : 16;               /*!< (null)                                                                */
      __IO uint32_t  adc_peak_r : 16;               /*!< (null)                                                                */
    } ADC_PEAK_READ_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DAC_PEAK_READ;                   /*!< dac signal peak value                                                 */
    
    struct {
      __IO uint32_t  dac_peak_l : 16;               /*!< (null)                                                                */
      __IO uint32_t  dac_peak_r : 16;               /*!< (null)                                                                */
    } DAC_PEAK_READ_b;                              /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0;
  
  union {
    __IO uint32_t  IF_CTRL;                         /*!< Interface control                                                     */
    
    struct {
      __IO uint32_t  i2s_output_track_sel_l:  1;    /*!< (null)                                                                */
      __IO uint32_t  i2s_output_track_sel_r:  1;    /*!< (null)                                                                */
      __IO uint32_t  i2s_input_track_sel:  2;       /*!< (null)                                                                */
      __IO uint32_t  i2s_pcm_mode:  1;              /*!< (null)                                                                */
      __IO uint32_t  receive_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  transmit_en:  1;               /*!< (null)                                                                */
      __IO uint32_t  i2s_con_ctrl:  1;              /*!< (null)                                                                */
      __IO uint32_t  pcm_con_ctrl:  1;              /*!< (null)                                                                */
      __IO uint32_t  pcm_mode_ctrl:  1;             /*!< (null)                                                                */
    } IF_CTRL_b;                                    /*!< BitSize                                                               */
  };
} CODEC_Type;


/* ================================================================================ */
/* ================                       RTC                      ================ */
/* ================================================================================ */


/**
  * @brief RTC controller (RTC)
  */

typedef struct {                                    /*!< RTC Structure                                                         */
  
  union {
    __IO uint32_t  TR;                              /*!< RTC time register                                                     */
    
    struct {
      __IO uint32_t  SU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  ST         :  3;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  MNU        :  4;               /*!< (null)                                                                */
      __IO uint32_t  MNT        :  3;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  HU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  HT         :  2;               /*!< (null)                                                                */
      __IO uint32_t  PM         :  1;               /*!< (null)                                                                */
    } TR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  DR;                              /*!< RTC date register                                                     */
    
    struct {
      __IO uint32_t  DU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  DT         :  2;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  MU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  MT         :  1;               /*!< (null)                                                                */
      __IO uint32_t  WDU        :  3;               /*!< (null)                                                                */
      __IO uint32_t  YU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  YT         :  4;               /*!< (null)                                                                */
    } DR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CR;                              /*!< RTC control register                                                  */
    
    struct {
      __IO uint32_t  WUCKSEL    :  3;               /*!< (null)                                                                */
      __IO uint32_t  TSEDGE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  REFCKON    :  1;               /*!< (null)                                                                */
      __IO uint32_t  BYPSHAD    :  1;               /*!< (null)                                                                */
      __IO uint32_t  FMT        :  1;               /*!< (null)                                                                */
      __IO uint32_t  DCE        :  1;               /*!< (null)                                                                */
      __IO uint32_t  ALRAE      :  1;               /*!< (null)                                                                */
      __IO uint32_t  ALRBE      :  1;               /*!< (null)                                                                */
      __IO uint32_t  WUTE       :  1;               /*!< (null)                                                                */
      __IO uint32_t  TSE        :  1;               /*!< (null)                                                                */
      __IO uint32_t  ALRAIE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  ALRBIE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  WUTIE      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TSIE       :  1;               /*!< (null)                                                                */
      __O  uint32_t  ADD1H      :  1;               /*!< (null)                                                                */
      __O  uint32_t  SUB1H      :  1;               /*!< (null)                                                                */
      __IO uint32_t  BKP        :  1;               /*!< (null)                                                                */
      __IO uint32_t  COSEL      :  1;               /*!< (null)                                                                */
      __IO uint32_t  POL        :  1;               /*!< (null)                                                                */
      __IO uint32_t  OSEL       :  2;               /*!< (null)                                                                */
      __IO uint32_t  COE        :  1;               /*!< (null)                                                                */
    } CR_b;                                         /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ISR;                             /*!< RTC initialization and status register                                */
    
    struct {
      __I  uint32_t  ALRAWF     :  1;               /*!< (null)                                                                */
      __I  uint32_t  ALRBWF     :  1;               /*!< (null)                                                                */
      __I  uint32_t  WUTWF      :  1;               /*!< (null)                                                                */
      __IO uint32_t  SHPF       :  1;               /*!< (null)                                                                */
      __I  uint32_t  INITS      :  1;               /*!< (null)                                                                */
      __IO uint32_t  RSF        :  1;               /*!< (null)                                                                */
      __I  uint32_t  INITF      :  1;               /*!< (null)                                                                */
      __IO uint32_t  INIT       :  1;               /*!< (null)                                                                */
      __IO uint32_t  ALRAF      :  1;               /*!< (null)                                                                */
      __IO uint32_t  ALRBF      :  1;               /*!< (null)                                                                */
      __IO uint32_t  WUTF       :  1;               /*!< (null)                                                                */
      __IO uint32_t  TSF        :  1;               /*!< (null)                                                                */
      __IO uint32_t  TSOVF      :  1;               /*!< (null)                                                                */
      __IO uint32_t  TAMP1F     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TAMP2F     :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  RECALPF    :  1;               /*!< (null)                                                                */
    } ISR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PRER;                            /*!< RTC prescaler register                                                */
    
    struct {
      __IO uint32_t  PREDIV_S   : 15;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  PREDIV_A   :  7;               /*!< (null)                                                                */
    } PRER_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  WUTR;                            /*!< RTC wakeup timer register                                             */
    
    struct {
      __IO uint32_t  WUT        : 16;               /*!< (null)                                                                */
    } WUTR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CALIBR;                          /*!< RTC calibration register                                              */
    
    struct {
      __IO uint32_t  DC         :  5;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  DCS        :  1;               /*!< (null)                                                                */
    } CALIBR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ALRMAR;                          /*!< RTC alarm A register                                                  */
    
    struct {
      __IO uint32_t  SU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  ST         :  3;               /*!< (null)                                                                */
      __IO uint32_t  MSK1       :  1;               /*!< (null)                                                                */
      __IO uint32_t  MNU        :  4;               /*!< (null)                                                                */
      __IO uint32_t  MNT        :  3;               /*!< (null)                                                                */
      __IO uint32_t  MSK2       :  1;               /*!< (null)                                                                */
      __IO uint32_t  HU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  HT         :  2;               /*!< (null)                                                                */
      __IO uint32_t  PM         :  1;               /*!< (null)                                                                */
      __IO uint32_t  MSK3       :  1;               /*!< (null)                                                                */
      __IO uint32_t  DU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  DT         :  2;               /*!< (null)                                                                */
      __IO uint32_t  WDSEL      :  1;               /*!< (null)                                                                */
      __IO uint32_t  MSK4       :  1;               /*!< (null)                                                                */
    } ALRMAR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ALRMBR;                          /*!< RTC alarm B register                                                  */
    
    struct {
      __IO uint32_t  SU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  ST         :  3;               /*!< (null)                                                                */
      __IO uint32_t  MSK1       :  1;               /*!< (null)                                                                */
      __IO uint32_t  MNU        :  4;               /*!< (null)                                                                */
      __IO uint32_t  MNT        :  3;               /*!< (null)                                                                */
      __IO uint32_t  MSK2       :  1;               /*!< (null)                                                                */
      __IO uint32_t  HU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  HT         :  2;               /*!< (null)                                                                */
      __IO uint32_t  PM         :  1;               /*!< (null)                                                                */
      __IO uint32_t  MSK3       :  1;               /*!< (null)                                                                */
      __IO uint32_t  DU         :  4;               /*!< (null)                                                                */
      __IO uint32_t  DT         :  2;               /*!< (null)                                                                */
      __IO uint32_t  DSEL       :  1;               /*!< (null)                                                                */
      __IO uint32_t  MSK4       :  1;               /*!< (null)                                                                */
    } ALRMBR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  WPR;                             /*!< RTC write protection register                                         */
    
    struct {
      __O  uint32_t  KEY        :  8;               /*!< (null)                                                                */
    } WPR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  SSR;                             /*!< RTC sub second register                                               */
    
    struct {
      __I  uint32_t  SS         : 16;               /*!< (null)                                                                */
    } SSR_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __O  uint32_t  SHIFTR;                          /*!< RTC shift control register                                            */
    
    struct {
      __O  uint32_t  SUBFS      : 15;               /*!< (null)                                                                */
           uint32_t             : 16;
      __O  uint32_t  ADD1S      :  1;               /*!< (null)                                                                */
    } SHIFTR_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TSTR;                            /*!< RTC time stamp time register                                          */
    
    struct {
      __I  uint32_t  SU         :  4;               /*!< (null)                                                                */
      __I  uint32_t  ST         :  3;               /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  MNU        :  4;               /*!< (null)                                                                */
      __I  uint32_t  MNT        :  3;               /*!< (null)                                                                */
           uint32_t             :  1;
      __I  uint32_t  HU         :  4;               /*!< (null)                                                                */
      __I  uint32_t  HT         :  2;               /*!< (null)                                                                */
      __I  uint32_t  PM         :  1;               /*!< (null)                                                                */
    } TSTR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TSDR;                            /*!< RTC time stamp date register                                          */
    
    struct {
      __I  uint32_t  DU         :  4;               /*!< (null)                                                                */
      __I  uint32_t  DT         :  2;               /*!< (null)                                                                */
           uint32_t             :  2;
      __I  uint32_t  MU         :  4;               /*!< (null)                                                                */
      __I  uint32_t  MT         :  1;               /*!< (null)                                                                */
      __I  uint32_t  WDU        :  3;               /*!< (null)                                                                */
    } TSDR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  TSSSR;                           /*!< RTC timestamp sub second register                                     */
    
    struct {
      __I  uint32_t  SS         : 16;               /*!< (null)                                                                */
    } TSSSR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CALR;                            /*!< RTC calibration register                                              */
    
    struct {
      __IO uint32_t  CALM       :  9;               /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  CALW16     :  1;               /*!< (null)                                                                */
      __IO uint32_t  CALW8      :  1;               /*!< (null)                                                                */
      __IO uint32_t  CALP       :  1;               /*!< (null)                                                                */
    } CALR_b;                                       /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  TAFCR;                           /*!< RTC tamper and alternate function configuration register              */
    
    struct {
      __IO uint32_t  TAMP1E     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TAMP1TRG   :  1;               /*!< (null)                                                                */
      __IO uint32_t  TAMPIE     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TAMP2E     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TAMP2TRG   :  1;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  TAMPTS     :  1;               /*!< (null)                                                                */
      __IO uint32_t  TAMPFREQ   :  3;               /*!< (null)                                                                */
      __IO uint32_t  TAMPFLT    :  2;               /*!< (null)                                                                */
      __IO uint32_t  TAMPPRCH   :  2;               /*!< (null)                                                                */
      __IO uint32_t  TAMPPUDIS  :  1;               /*!< (null)                                                                */
      __IO uint32_t  TAMP1INSEL :  1;               /*!< (null)                                                                */
      __IO uint32_t  TSINSEL    :  1;               /*!< (null)                                                                */
      __IO uint32_t  ALARMOUTTYPE:  1;              /*!< (null)                                                                */
    } TAFCR_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ALRMASSR;                        /*!< RTC alarm A sub second register                                       */
    
    struct {
      __IO uint32_t  SS         : 15;               /*!< (null)                                                                */
           uint32_t             :  9;
      __IO uint32_t  MASKSS     :  4;               /*!< (null)                                                                */
    } ALRMASSR_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ALRMBSSR;                        /*!< RTC alarm B sub second register                                       */
    
    struct {
      __IO uint32_t  SS         : 15;               /*!< (null)                                                                */
           uint32_t             :  9;
      __IO uint32_t  MASKSS     :  4;               /*!< (null)                                                                */
    } ALRMBSSR_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0;
  
  union {
    __IO uint32_t  BKP0R;                           /*!< RTC backup register 0                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP0R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP1R;                           /*!< RTC backup register 1                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP1R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP2R;                           /*!< RTC backup register 2                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP2R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP3R;                           /*!< RTC backup register 3                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP3R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP4R;                           /*!< RTC backup register 4                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP4R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP5R;                           /*!< RTC backup register 5                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP5R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP6R;                           /*!< RTC backup register 6                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP6R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP7R;                           /*!< RTC backup register 7                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP7R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP8R;                           /*!< RTC backup register 8                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP8R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP9R;                           /*!< RTC backup register 9                                                 */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP9R_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP10R;                          /*!< RTC backup register 10                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP10R_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP11R;                          /*!< RTC backup register 11                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP11R_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP12R;                          /*!< RTC backup register 12                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP12R_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP13R;                          /*!< RTC backup register 13                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP13R_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP14R;                          /*!< RTC backup register 14                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP14R_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP15R;                          /*!< RTC backup register 15                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP15R_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP16R;                          /*!< RTC backup register 16                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP16R_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP17R;                          /*!< RTC backup register 17                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP17R_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP18R;                          /*!< RTC backup register 18                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP18R_b;                                     /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  BKP19R;                          /*!< RTC backup register 19                                                */
    
    struct {
      __IO uint32_t  BKP        : 32;               /*!< (null)                                                                */
    } BKP19R_b;                                     /*!< BitSize                                                               */
  };
} RTC_Type;


/* ================================================================================ */
/* ================                       SYS                      ================ */
/* ================================================================================ */


/**
  * @brief System module (SYS)
  */

typedef struct {                                    /*!< SYS Structure                                                         */
  
  union {
    __IO uint32_t  CHIP_ID;                         /*!< Chip ID register                                                      */
    
    struct {
      __IO uint32_t  id         : 32;               /*!< (null)                                                                */
    } CHIP_ID_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0[5];
  
  union {
    __IO uint32_t  CPU_SYS_TICK;                    /*!< SysTick Calib config register                                         */
    
    struct {
      __IO uint32_t  value      : 24;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  noref      :  1;               /*!< (null)                                                                */
    } CPU_SYS_TICK_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  USB_CTRL;                        /*!< USB Control register                                                  */
    
    struct {
      __IO uint32_t  usb_test_mode:  1;             /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  usb_vbus_valid:  1;            /*!< (null)                                                                */
      __IO uint32_t  usb_vbus_session:  1;          /*!< (null)                                                                */
      __IO uint32_t  usb_vbus_lo:  1;               /*!< (null)                                                                */
      __IO uint32_t  usb_sess_ctrl_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  usb_bus_mon_en:  1;            /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  usb_bus_active:  1;            /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  pd_vbus_det:  1;               /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  usb_vbus_state:  3;            /*!< (null)                                                                */
    } USB_CTRL_b;                                   /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1[6];
  
  union {
    __IO uint32_t  DEBUG_MON_ID;                    /*!< Monitor Bus ID register                                               */
    
    struct {
      __IO uint32_t  id         : 16;               /*!< (null)                                                                */
    } DEBUG_MON_ID_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHIP_REG_UPD;                    /*!< Update Clock register                                                 */
    
    struct {
      __IO uint32_t  update     :  1;               /*!< (null)                                                                */
    } CHIP_REG_UPD_b;                               /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CHARGER_STATE;                   /*!< Charger State register                                                */
    
    struct {
      __IO uint32_t  charger_state:  3;             /*!< (null)                                                                */
    } CHARGER_STATE_b;                              /*!< BitSize                                                               */
  };
} SYS_Type;


/* ================================================================================ */
/* ================                       PMU                      ================ */
/* ================================================================================ */


/**
  * @brief PMU controller (PMU)
  */

typedef struct {                                    /*!< PMU Structure                                                         */

  __IO uint32_t BASIC;
  __IO uint32_t PSO_PM_CON;
  __IO uint32_t RETEN_PM_CON;
  __IO uint32_t RAM_PM_CON;
  __IO uint32_t CEVA0_PM_CON;
  __IO uint32_t CEVA1_PM_CON;
  __IO uint32_t POWER_PIN; //0X18
  __IO uint32_t SCRATCH;
  __IO uint32_t SCRATCH1;
  __IO uint32_t EXT; //0X24
       uint8_t x28_x39[0x40-0x28];
  __IO uint32_t PADC_CON[24]; //0x40 ~ 0x9C
  __IO uint32_t PADC_CSF;
  __IO uint32_t CHIP_PM_PIN;
       uint8_t xa8_xbf[0xc0-0xa8];
  __IO uint32_t GPIO_STATUS[2]; //0xc0 0xc4
  __IO uint32_t GPIO_PL_UP_30K; //pull up 30ohm for gpio[23:16], i.e. SD
       uint32_t RESET_EN;       //0xcc
  __IO uint32_t OPT_RESET_CON;
       uint32_t xd4_xdb[2];
  __IO uint32_t PMU_CLOCK_MUX;  //0xDC
       uint8_t xE0_xfb[0xfc-0xe0];
  __IO uint32_t ANA_CON; //system LDO & PLL

  #if 0
  union {
    __IO uint32_t  BASIC;                           /*!< Basic register                                                        */
    
    struct {
      __IO uint32_t  pso_power_fsm_reset:  1;       /*!< (null)                                                                */
      __IO uint32_t  ram0_power_fsm_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  ram1_power_fsm_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  ram2_power_fsm_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  ram3_power_fsm_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  ram4_power_fsm_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  ram5_power_fsm_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  ram6_power_fsm_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  ram7_power_fsm_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  ram8_power_fsm_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  ram9_power_fsm_reset:  1;      /*!< (null)                                                                */
           uint32_t             : 13;
      __IO uint32_t  update     :  1;               /*!< (null)                                                                */
      __IO uint32_t  pso_power_pin_edge:  1;        /*!< (null)                                                                */
      __IO uint32_t  pso_power_pin_hold_key:  1;    /*!< (null)                                                                */
      __IO uint32_t  pso_power_pin_source:  4;      /*!< (null)                                                                */
      __IO uint32_t  pll_lock   :  1;               /*!< (null)                                                                */
    } BASIC_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_CON;                         /*!< PSO Power Control register                                            */
    
    struct {
      __IO uint32_t  pso_power_on:  1;              /*!< (null)                                                                */
      __IO uint32_t  pso_power_gaten_en:  1;        /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  pso_reset_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  sflash_inner_enable:  1;       /*!< (null)                                                                */
      __IO uint32_t  pso_power_status:  1;          /*!< (null)                                                                */
    } PSO_CON_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM0_CON;                        /*!< RAM0 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM0_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM1_CON;                        /*!< RAM1 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM1_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM2_CON;                        /*!< RAM2 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM2_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM3_CON;                        /*!< RAM3 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM3_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM4_CON;                        /*!< RAM4 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM4_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM5_CON;                        /*!< RAM5 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM5_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM6_CON;                        /*!< RAM6 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM6_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM7_CON;                        /*!< RAM7 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM7_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM8_CON;                        /*!< RAM8 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM8_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RAM9_CON;                        /*!< RAM9 Power Control register                                           */
    
    struct {
      __IO uint32_t  power_on   :  1;               /*!< (null)                                                                */
      __IO uint32_t  power_gaten_en:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  pso_clamp_delay:  8;           /*!< (null)                                                                */
      __IO uint32_t  power_status:  1;              /*!< (null)                                                                */
    } RAM9_CON_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  POWER_PIN;                       /*!< Power Pin register                                                    */
    
    struct {
      __IO uint32_t  basic_cycle:  4;               /*!< (null)                                                                */
           uint32_t             : 12;
      __IO uint32_t  on_cycle   :  4;               /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  reset_cycle:  5;               /*!< (null)                                                                */
      __IO uint32_t  reset_en   :  1;               /*!< (null)                                                                */
      __IO uint32_t  level      :  1;               /*!< (null)                                                                */
    } POWER_PIN_b;                                  /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0;
  
  union {
    __IO uint32_t  SCRATCH;                         /*!< Retention register                                                    */
    
    struct {
      __IO uint32_t  pm_con0    : 32;               /*!< (null)                                                                */
    } SCRATCH_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  REMAP;                           /*!< Remap register                                                        */
    
    struct {
      __IO uint32_t  ahb_bus_remap:  4;             /*!< (null)                                                                */
      __IO uint32_t  mcu_soft_reset:  1;            /*!< (null)                                                                */
      __IO uint32_t  ahb_bus_remap_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  wdt_reset_status:  1;          /*!< (null)                                                                */
      __IO uint32_t  pmu_reset_status:  1;          /*!< (null)                                                                */
      __IO uint32_t  pso_reset_status:  1;          /*!< (null)                                                                */
      __IO uint32_t  pll_soft_reset:  1;            /*!< (null)                                                                */
      __IO uint32_t  cry_soft_power_off:  1;        /*!< (null)                                                                */
      __IO uint32_t  pll_clk_0_96m_1_128m:  1;      /*!< (null)                                                                */
      __IO uint32_t  pll_soft_power_off:  1;        /*!< (null)                                                                */
    } REMAP_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON0;                       /*!< Pad Control 0 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON0_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON1;                       /*!< Pad Control 1 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON1_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON2;                       /*!< Pad Control 2 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON2_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON3;                       /*!< Pad Control 3 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON3_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON4;                       /*!< Pad Control 4 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON4_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON5;                       /*!< Pad Control 5 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON5_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON6;                       /*!< Pad Control 6 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON6_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON7;                       /*!< Pad Control 7 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON7_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON8;                       /*!< Pad Control 8 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON8_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON9;                       /*!< Pad Control 9 register                                                */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON9_b;                                  /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON10;                      /*!< Pad Control 10 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON10_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON11;                      /*!< Pad Control 11 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON11_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON12;                      /*!< Pad Control 12 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON12_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON13;                      /*!< Pad Control 13 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON13_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON14;                      /*!< Pad Control 14 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON14_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON15;                      /*!< Pad Control 15 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON15_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON16;                      /*!< Pad Control 16 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON16_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON17;                      /*!< Pad Control 17 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON17_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON18;                      /*!< Pad Control 18 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON18_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON19;                      /*!< Pad Control 19 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON19_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON20;                      /*!< Pad Control 20 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON20_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON21;                      /*!< Pad Control 21 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON21_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON22;                      /*!< Pad Control 22 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON22_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON23;                      /*!< Pad Control 23 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON23_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON24;                      /*!< Pad Control 24 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON24_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON25;                      /*!< Pad Control 25 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON25_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON26;                      /*!< Pad Control 26 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON26_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON27;                      /*!< Pad Control 27 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON27_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON28;                      /*!< Pad Control 28 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON28_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON29;                      /*!< Pad Control 29 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON29_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON30;                      /*!< Pad Control 30 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON30_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PADC_CON31;                      /*!< Pad Control 31 register                                               */
    
    struct {
      __IO uint32_t  mod        :  5;               /*!< (null)                                                                */
      __IO uint32_t  mux        :  4;               /*!< (null)                                                                */
    } PADC_CON31_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  GPIO_STATUS_0;                   /*!< GPIO Port 0 Latch register                                            */
    
    struct {
      __IO uint32_t  din_hold_low: 32;              /*!< (null)                                                                */
    } GPIO_STATUS_0_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  GPIO_STATUS_1;                   /*!< GPIO Port 1 Latch register                                            */
    
    struct {
      __IO uint32_t  din_hold_high: 32;             /*!< (null)                                                                */
    } GPIO_STATUS_1_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  GPIO_PL_UP_30K;                  /*!< Pull up 30k ohm register                                              */
    
    struct {
      __IO uint32_t  sd_clk     :  1;               /*!< (null)                                                                */
      __IO uint32_t  sd_dat0    :  1;               /*!< (null)                                                                */
      __IO uint32_t  sd_dat1    :  1;               /*!< (null)                                                                */
      __IO uint32_t  sd_dat2    :  1;               /*!< (null)                                                                */
      __IO uint32_t  sd_dat3    :  1;               /*!< (null)                                                                */
      __IO uint32_t  sd_cmd     :  1;               /*!< (null)                                                                */
      __IO uint32_t  sd_cd      :  1;               /*!< (null)                                                                */
      __IO uint32_t  sd_wp      :  1;               /*!< (null)                                                                */
    } GPIO_PL_UP_30K_b;                             /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  OSC_SEL;                         /*!< Oscillator Select register                                            */
    
    struct {
      __IO uint32_t  sel0_16mhz :  1;               /*!< (null)                                                                */
    } OSC_SEL_b;                                    /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2[10];
  
  union {
    __IO uint32_t  ANA_CON;                         /*!< Analog Interface Control register                                     */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  pd_buck    :  1;               /*!< (null)                                                                */
      __IO uint32_t  pd_ldo_anadig:  1;             /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  pd_chg     :  1;               /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  pd_ldo_v1p5_adda:  1;          /*!< (null)                                                                */
      __IO uint32_t  pd_ldo_v1p5_ana:  1;           /*!< (null)                                                                */
      __IO uint32_t  pd_ldo_v1p5_rf:  1;            /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  pd_pmu_bias:  1;               /*!< (null)                                                                */
      __IO uint32_t  pd_rf_ldo_v2p8:  1;            /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  pd_top_ldo_v1p8:  1;           /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  sys_pll_gt_24m_a:  1;          /*!< (null)                                                                */
      __IO uint32_t  sys_pll_gt_24m_d:  1;          /*!< (null)                                                                */
      __IO uint32_t  sys_pll_gt_32m:  1;            /*!< (null)                                                                */
      __IO uint32_t  sys_pll_gt_48m:  1;            /*!< (null)                                                                */
      __IO uint32_t  sys_pll_gt_cpu:  1;            /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  pd_io_ldo_v3p3:  2;            /*!< (null)                                                                */
    } ANA_CON_b;                                    /*!< BitSize                                                               */
  };
  #endif
} PMU_Type;


/* ================================================================================ */
/* ================                       CPM                      ================ */
/* ================================================================================ */


/**
  * @brief Low Clock module (CPM)
  */

typedef struct {                                    /*!< CPM Structure                                                         */
  
  union {
    __IO uint32_t  REV;                             /*!< CPM Revision register                                                 */
    
    struct {
      __IO uint32_t  rev        : 32;               /*!< (null)                                                                */
    } REV_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  UPD;                             /*!< CPM Update register                                                   */
    
    struct {
      __IO uint32_t  update     :  1;               /*!< (null)                                                                */
    } UPD_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CFG;                             /*!< CPM Config register                                                   */
    
    struct {
           uint32_t             :  3;
      __IO uint32_t  apb_reg_gate_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  apb_soft_reset:  1;            /*!< (null)                                                                */
      __IO uint32_t  soft_reset :  1;               /*!< (null)                                                                */
    } CFG_b;                                        /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RTC_CFG;                         /*!< RTC Clock Config register                                             */
    
    struct {
      __IO uint32_t  src_0xtal_1rc:  1;             /*!< (null)                                                                */
      __IO uint32_t  apb_reg_gate_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  apb_soft_reset:  1;            /*!< (null)                                                                */
      __IO uint32_t  reg_gate_en:  1;               /*!< (null)                                                                */
      __IO uint32_t  soft_reset :  1;               /*!< (null)                                                                */
    } RTC_CFG_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CRY_CFG;                         /*!< XTAL Config register                                                  */
    
    struct {
      __IO uint32_t  div_en     :  1;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  reg_gate_en:  1;               /*!< (null)                                                                */
      __IO uint32_t  soft_reset :  1;               /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  div_coeff  :  9;               /*!< (null)                                                                */
    } CRY_CFG_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CLK_SRC;                         /*!< Clock Source register                                                 */
    
    struct {
      __IO uint32_t  src_0xtal_1pll:  1;            /*!< (null)                                                                */
    } CLK_SRC_b;                                    /*!< BitSize                                                               */
  };
} CPM_Type;


/* ================================================================================ */
/* ================                       CLK                      ================ */
/* ================================================================================ */


/**
  * @brief PSO (CLK)
  */

typedef struct {                                    /*!< CLK Structure                                                         */
  
  union {
    __IO uint32_t  PSO_REV;                         /*!< PSO revision                                                          */
    
    struct {
      __IO uint32_t  PSO_REV    : 32;               /*!< (null)                                                                */
    } PSO_REV_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_CPU_CFG;                     /*!< CPU clock configuration                                               */
    
    struct {
           uint32_t             :  3;
      __IO uint32_t  cpu_div_gate_en:  1;           /*!< (null)                                                                */
           uint32_t             :  7;
      __IO uint32_t  cpu_div_coeff:  5;             /*!< (null)                                                                */
    } PSO_CPU_CFG_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_REG_UDP;                     /*!< Update shadow register                                                */
    
    struct {
      __O  uint32_t  cpm_reg_upd:  1;               /*!< (null)                                                                */
    } PSO_REG_UDP_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_APB_CFG;                     /*!< APB clock configuration                                               */
    
    struct {
      __IO uint32_t  apb_div_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  apb_reg_gate_en:  1;           /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  apb_soft_reset:  1;            /*!< (null)                                                                */
           uint32_t             :  4;
      __IO uint32_t  apb_div_coeff:  7;             /*!< (null)                                                                */
    } PSO_APB_CFG_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_SFLASH_CFG;                  /*!< sflash clock configuration                                            */
    
    struct {
      __IO uint32_t  sf_div_en  :  1;               /*!< (null)                                                                */
      __IO uint32_t  sf_ahb_reg_gate_en:  1;        /*!< (null)                                                                */
      __IO uint32_t  sf_ahb_soft_reset:  1;         /*!< (null)                                                                */
      __IO uint32_t  sf_reg_gate_en:  1;            /*!< (null)                                                                */
           uint32_t             :  8;
      __IO uint32_t  sf_div_coeff:  4;              /*!< (null)                                                                */
      __IO uint32_t  sf_delay_offset:  2;           /*!< (null)                                                                */
      __IO uint32_t  sf_delay_bypass:  1;           /*!< (null)                                                                */
    } PSO_SFLASH_CFG_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_USB_CFP;                     /*!< USB clock configuration                                               */
    
    struct {
      __IO uint32_t  usb_div_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  usb_ahb_reg_gate_en:  1;       /*!< (null)                                                                */
      __IO uint32_t  usb_ahb_soft_reset:  1;        /*!< (null)                                                                */
      __IO uint32_t  usb_reg_gate_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  usb_soft_reset:  1;            /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  usb_div_coeff:  5;             /*!< (null)                                                                */
    } PSO_USB_CFP_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_SD_CFG;                      /*!< SD clock configuration                                                */
    
    struct {
      __IO uint32_t  sd_div_en  :  1;               /*!< (null)                                                                */
      __IO uint32_t  sd_ahb_reg_gate_en:  1;        /*!< (null)                                                                */
      __IO uint32_t  sd_ahb_soft_reset:  1;         /*!< (null)                                                                */
      __IO uint32_t  sd_reg_gate_en:  1;            /*!< (null)                                                                */
           uint32_t             :  7;
      __IO uint32_t  sd_div_coeff:  5;              /*!< (null)                                                                */
    } PSO_SD_CFG_b;                                 /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_SD_DEV_CFG;                  /*!< sd dev clock configuration                                            */
    
    struct {
           uint32_t             : 16;
      __IO uint32_t  sd_dev_clk_inv_en:  1;         /*!< (null)                                                                */
           uint32_t             :  1;
      __IO uint32_t  sd_drv_delay_bypass:  1;       /*!< (null)                                                                */
      __IO uint32_t  sd_drv_div_offset:  2;         /*!< (null)                                                                */
           uint32_t             :  5;
      __IO uint32_t  sd_smp_delay_bypass:  1;       /*!< (null)                                                                */
      __IO uint32_t  sd_smp_div_offset:  2;         /*!< (null)                                                                */
    } PSO_SD_DEV_CFG_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_TIMER1_CFG;                  /*!< timer1 clock configuration                                            */
    
    struct {
      __IO uint32_t  timer1_div_en:  1;             /*!< (null)                                                                */
      __IO uint32_t  timer1_apb_reg_gate_en:  1;    /*!< (null)                                                                */
      __IO uint32_t  timer1_apb_soft_reset:  1;     /*!< (null)                                                                */
      __IO uint32_t  timer1_reg_gate_en:  1;        /*!< (null)                                                                */
      __IO uint32_t  timer1_soft_reset:  1;         /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  timer1_div_coeff:  5;          /*!< (null)                                                                */
    } PSO_TIMER1_CFG_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_TIMER2_CFG;                  /*!< timer2 clock configuration                                            */
    
    struct {
      __IO uint32_t  timer2_div_en:  1;             /*!< (null)                                                                */
      __IO uint32_t  timer2_apb_reg_gate_en:  1;    /*!< (null)                                                                */
      __IO uint32_t  timer2_apb_soft_reset:  1;     /*!< (null)                                                                */
      __IO uint32_t  timer2_reg_gate_en:  1;        /*!< (null)                                                                */
      __IO uint32_t  timer2_soft_reset:  1;         /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  timer2_div_coeff:  5;          /*!< (null)                                                                */
    } PSO_TIMER2_CFG_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_TIMER3_CFG;                  /*!< timer3 clock configuration                                            */
    
    struct {
      __IO uint32_t  timer3_div_en:  1;             /*!< (null)                                                                */
      __IO uint32_t  timer3_apb_reg_gate_en:  1;    /*!< (null)                                                                */
      __IO uint32_t  timer3_apb_soft_reset:  1;     /*!< (null)                                                                */
      __IO uint32_t  timer3_reg_gate_en:  1;        /*!< (null)                                                                */
      __IO uint32_t  timer3_soft_reset:  1;         /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  timer3_div_coeff:  5;          /*!< (null)                                                                */
    } PSO_TIMER3_CFG_b;                             /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED0;
  
  union {
    __IO uint32_t  PSO_UART0_CFG;                   /*!< uart0 clock configuration                                             */
    
    struct {
      __IO uint32_t  uart0_div_en:  1;              /*!< (null)                                                                */
      __IO uint32_t  uart0_apb_reg_gate_en:  1;     /*!< (null)                                                                */
      __IO uint32_t  uart0_apb_soft_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  uart0_reg_gate_en:  1;         /*!< (null)                                                                */
      __IO uint32_t  uart0_soft_reset:  1;          /*!< (null)                                                                */
           uint32_t             :  5;
      __IO uint32_t  uart0_div_coeff_int:  6;       /*!< (null)                                                                */
           uint32_t             :  8;
      __IO uint32_t  uart0_div_coeff_frc:  6;       /*!< (null)                                                                */
    } PSO_UART0_CFG_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_UART1_CFG;                   /*!< uart1 clock configuration                                             */
    
    struct {
      __IO uint32_t  uart1_div_en:  1;              /*!< (null)                                                                */
      __IO uint32_t  uart1_apb_reg_gate_en:  1;     /*!< (null)                                                                */
      __IO uint32_t  uart1_apb_soft_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  uart1_reg_gate_en:  1;         /*!< (null)                                                                */
      __IO uint32_t  uart1_soft_reset:  1;          /*!< (null)                                                                */
           uint32_t             :  5;
      __IO uint32_t  uart1_div_coeff_int:  6;       /*!< (null)                                                                */
           uint32_t             :  8;
      __IO uint32_t  uart1_div_coeff_frc:  6;       /*!< (null)                                                                */
    } PSO_UART1_CFG_b;                              /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_I2C_CFG;                     /*!< I2C clock configuration                                               */
    
    struct {
      __IO uint32_t  i2c_div_en :  1;               /*!< (null)                                                                */
      __IO uint32_t  i2c_apb_reg_gate_en:  1;       /*!< (null)                                                                */
      __IO uint32_t  i2c_apb_soft_reset:  1;        /*!< (null)                                                                */
      __IO uint32_t  i2c_reg_gate_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  i2c_soft_reset:  1;            /*!< (null)                                                                */
           uint32_t             :  5;
      __IO uint32_t  i2c_div_coeff:  6;             /*!< (null)                                                                */
    } PSO_I2C_CFG_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_I2S_CFG;                     /*!< I2S clock configuration                                               */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  i2s_apb_reg_gate_en:  1;       /*!< (null)                                                                */
      __IO uint32_t  i2s_apb_soft_reset:  1;        /*!< (null)                                                                */
    } PSO_I2S_CFG_b;                                /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED1;
  
  union {
    __IO uint32_t  PSO_AUDIO_CFG;                   /*!< AUDIO clock configuration                                             */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  audio_apb_reg_gate_en:  1;     /*!< (null)                                                                */
      __IO uint32_t  audio_apb_soft_reset:  1;      /*!< (null)                                                                */
    } PSO_AUDIO_CFG_b;                              /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED2;
  
  union {
    __IO uint32_t  PSO_BT_PHY_CFG;                  /*!< BT_PHY clock configuration                                            */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  bt_lpo_apb_reg_gate_en:  1;    /*!< (null)                                                                */
      __IO uint32_t  bt_lpo_apb_soft_reset:  1;     /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  bt_lpo_clk_source:  1;         /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  bt_clk_24_gate_en:  1;         /*!< (null)                                                                */
      __IO uint32_t  bt_clk_24_soft_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  bt_clk_32_gate_en:  1;         /*!< (null)                                                                */
      __IO uint32_t  bt_clk_32_soft_reset:  1;      /*!< (null)                                                                */
      __IO uint32_t  bt_clk_48_gate_en:  1;         /*!< (null)                                                                */
      __IO uint32_t  bt_clk_48_soft_reset:  1;      /*!< (null)                                                                */
    } PSO_BT_PHY_CFG_b;                             /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_SPI0_MST_CFG;                /*!< SPI0 Master clock configuration                                       */
    
    struct {
           uint32_t             :  3;
      __IO uint32_t  spi_mst0_reg_gate_en:  1;      /*!< (null)                                                                */
      __IO uint32_t  spi_mst0_soft_reset:  1;       /*!< (null)                                                                */
    } PSO_SPI0_MST_CFG_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_SPI1_MST_CFG;                /*!< SPI1 Master clock configuration                                       */
    
    struct {
      __IO uint32_t  spi_mst1_div_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  spi_mst1_apb_reg_gate_en:  1;  /*!< (null)                                                                */
      __IO uint32_t  spi_mst1_apb_soft_reset:  1;   /*!< (null)                                                                */
      __IO uint32_t  spi_mst1_reg_gate_en:  1;      /*!< (null)                                                                */
      __IO uint32_t  spi_mst1_soft_reset:  1;       /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  spi_mst1_div_coeff:  5;        /*!< (null)                                                                */
    } PSO_SPI1_MST_CFG_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_WDT_CFG;                     /*!< WDT rst and clock configuartion                                       */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  spi_wdt_reg_gate_en:  1;       /*!< (null)                                                                */
    } PSO_WDT_CFG_b;                                /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  PSO_CPU_TCLK_CFG;                /*!< CPU Tclk rst and clock configuration                                  */
    
    struct {
      __IO uint32_t  cpu_tclk_div_en:  1;           /*!< (null)                                                                */
           uint32_t             :  2;
      __IO uint32_t  cpu_tclk_reg_gate_en:  1;      /*!< (null)                                                                */
      __IO uint32_t  cpu_tclk_soft_reset:  1;       /*!< (null)                                                                */
           uint32_t             :  6;
      __IO uint32_t  cpu_tclk_div_coeff:  5;        /*!< (null)                                                                */
    } PSO_CPU_TCLK_CFG_b;                           /*!< BitSize                                                               */
  };
  __I  uint32_t  RESERVED3[4];
  
  union {
    __IO uint32_t  PSO_AHB_GATE_CFG;                /*!< AHB Gate configuration                                                */
    
    struct {
      __IO uint32_t  gpio_reg_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  gpio_soft_reset:  1;           /*!< (null)                                                                */
      __IO uint32_t  dma_reg_gate_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  dma_soft_reset:  1;            /*!< (null)                                                                */
    } PSO_AHB_GATE_CFG_b;                           /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  CPM_GATE_CFG;                    /*!< CPM gate configuration                                                */
    
    struct {
      __IO uint32_t  pso_clk_gate_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  ram0_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram1_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram2_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram3_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram4_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram5_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram6_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram7_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram8_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram9_clk_gate_en:  1;          /*!< (null)                                                                */
      __IO uint32_t  ram_auto_gate:  1;             /*!< (null)                                                                */
      __IO uint32_t  pso_cpm_soft_reset:  1;        /*!< (null)                                                                */
      __IO uint32_t  pso_reg_gate_en:  1;           /*!< (null)                                                                */
      __IO uint32_t  pso_soft_reset:  1;            /*!< (null)                                                                */
    } CPM_GATE_CFG_b;                               /*!< BitSize                                                               */
  };  
} CLK_Type;


/* ================================================================================ */
/* ================                     MAC6200                    ================ */
/* ================================================================================ */


/**
  * @brief MAC6200 (MAC6200)
  */

typedef struct {                                    /*!< MAC6200 Structure                                                     */
  
  union {
    __IO uint32_t  SPIRCON;                         /*!< MAC6200 SPI Control register                                          */
    
    struct {
      __IO uint32_t  maskIrqTxFifoReady:  1;        /*!< (null)                                                                */
      __IO uint32_t  maskIrqTxFifoEmpty:  1;        /*!< (null)                                                                */
      __IO uint32_t  maskIrqRxDataReady:  1;        /*!< (null)                                                                */
      __IO uint32_t  maskIrqRxFifoFull:  1;         /*!< (null)                                                                */
           uint32_t             :  3;
      __IO uint32_t  MAC_SEL    :  1;               /*!< (null)                                                                */
    } SPIRCON_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __I  uint32_t  SPIRSTAT;                        /*!< MAC6200 SPI Master status register                                    */
    
    struct {
      __I  uint32_t  Txfifo_ready:  1;              /*!< (null)                                                                */
      __I  uint32_t  Txfifo_empty:  1;              /*!< (null)                                                                */
      __I  uint32_t  Rxdata_ready:  1;              /*!< (null)                                                                */
      __I  uint32_t  Rxfifo_full:  1;               /*!< (null)                                                                */
      __I  uint32_t  spi_busy   :  1;               /*!< (null)                                                                */
    } SPIRSTAT_b;                                   /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  SPIRDAT;                         /*!< MAC6200 SPI Master data register                                      */
    
    struct {
      __IO uint32_t  DATA       :  8;               /*!< (null)                                                                */
    } SPIRDAT_b;                                    /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  RFCON;                           /*!< MAC6200 RF R/W control                                                */
    
    struct {
      __IO uint32_t  RF_CE      :  1;               /*!< (null)                                                                */
      __IO uint32_t  RF_CSN     :  1;               /*!< (null)                                                                */
    } RFCON_b;                                      /*!< BitSize                                                               */
  };
  
  union {
    __IO uint32_t  ICR;                             /*!< MAC6200 Clear SPI interrupt                                           */
    
    struct {
           uint32_t             :  1;
      __IO uint32_t  icr        :  1;               /*!< (null)                                                                */
    } ICR_b;                                        /*!< BitSize                                                               */
  };
} MAC6200_Type;

struct _HS_USB_Type
{
  __IO uint8_t      USB_ADDR;       //00
  __IO uint8_t      USB_POWER;      //01
  __IO uint16_t     USB_INTTX;      //02
  __IO uint16_t     USB_INTRX;      //04
  __IO uint8_t      USB_INTUSB;     //06
  __IO uint16_t     USB_INTTXEN;    //07
  __IO uint16_t     USB_INTRXEN;    //09
  __IO uint8_t      USB_INTUSBEN;   //0b
  __IO uint16_t     USB_FRAME;      //0c
  __IO uint8_t      USB_INDEX;      //0e
  __IO uint8_t      USB_DEVCTL;     //0f
  __IO uint8_t      USB_TXMAXP;     //10
  union
  {
    __IO uint16_t   USB_CSR0;       //11
    __IO uint16_t   USB_TXCSR;
  };  
  __IO uint8_t      USB_RXMAXP;     //13
  __IO uint16_t     USB_RXCSR;      //14
  union
  {
    __IO uint8_t    USB_COUNT0;     //16
    __IO uint8_t    USB_RXCOUNT1;
  }; 
  __IO uint8_t      USB_RXCOUNT2;   //17
  __IO uint8_t      USB_TXTYPE;     //18
  union
  {
    __IO uint8_t    USB_NAKLIMIT0;  //19
    __IO uint8_t    USB_TXINTERVAL;
  };   
  __IO uint8_t      USB_RXTYPE;     //1a
  __IO uint8_t      USB_RXINTERVAL; //1b
  __IO uint16_t     USB_TXFIFO;     //1c
  __IO uint16_t     USB_RXFIFO;     //1e
  __IO uint32_t     USB_EPxFIFO[4]; //20
} __attribute__ ((packed));

struct _HS_USB_DMA_Type
{
    __IO uint8_t    USB_DMA_INTR;       
    __IO uint8_t    USB_DMA_RESERVED1[3];//not used
    __IO uint16_t   USB_DMA_CTL;
    __IO uint16_t   USB_DMA_RESERVED2;
    __IO uint32_t   USB_DMA_ADDR;       
    __IO uint32_t   USB_DMA_CNT;
} __attribute__ ((packed));

typedef struct _HS_USB_Type     HS_USB_Type;
typedef struct _HS_USB_DMA_Type HS_USB_DMA_Type;

typedef struct
{
  __IO uint32_t PD_CFG[4];              // 0x00
  __IO uint32_t COMMON_CFG[2];
  __IO uint32_t RC_CALIB_CNS;
  __IO uint32_t reserve;
  __IO uint32_t MAIN_ST_CFG[2];
  __IO uint32_t ADCOC_CNS;
  __IO uint32_t TRX_COMP_CFG[2];
  __IO uint32_t LDO_CALIB_CNS;
  __IO uint32_t reserve0[2];
  __IO uint32_t COMMON_PACK[10];        // 0x10 * 4
  __IO uint32_t FM_CFG[2];
  __IO uint32_t FM_AGC_CFG[3];
  __IO uint32_t reserve1;
  __IO uint32_t RX_AGC_CFG[5];          // 0x20 * 4
  __IO uint32_t RX_AGC_OS_REG;
  __IO uint32_t RX_GAINC_LUT_REG[9];
  __IO uint32_t FILT_GAINC_LUT_REG;
  __IO uint32_t RF_AGC_LUT_REG[4];      // 0x30 * 4
  __IO uint32_t IF_AGC_LUT_REG[6];
  __IO uint32_t FILT_AGC_LUT_REG[2];
  __IO uint32_t reserve2[4];
  __IO uint32_t VCO_AFC_CFG[2];         // 0x40 * 4
  __IO uint32_t AFC_TWD;
  __IO uint32_t reserve3;
  __IO uint32_t VTRACK_CFG;
  __IO uint32_t PEAKDET_CFG;
  __IO uint32_t INTER_FREQ;
  __IO uint32_t COR_REG;
  __IO uint32_t SDM_CFG;
  __IO uint32_t LNA_CLOAD_CFG;
  __IO uint32_t AU_ANA_CFG[2];
  __IO uint32_t reserve4[0x24];
  __IO uint32_t DBG_IDX;                // 0x70 * 4
  __IO uint32_t DBG_RDATA;
  __IO uint32_t reserve5[14];
  __IO uint32_t DCOC_LUT_REG[50];       // 0xb2 * 4
}HS_ANA_Type;



/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
  /* leave anonymous unions enabled */
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler type
#endif




/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define BT_JAL_BASE                     0x40016000UL
#define BT_HAB_BASE                     0x40018000UL
#define BT_LE_BASE                      0x4001A000UL
#define BT_PHY_BASE                     0x40020000UL
#define DMAC_BASE                       0x41100000UL
#define SFLASH_BASE                     0x42800000UL
#define GPIO0_BASE                      0x43000000UL
#define GPIO1_BASE                      0x44000000UL
#define USB_PERIPH_0_BASE               0x45000000UL
#define MMC_SD_BASE                     0x46000000UL
#define UART0_BASE                      0x40030000UL
#define UART1_BASE                      0x40040000UL
#define SPI0_BASE                       0x40050000UL
#define SPI1_BASE                       0x40060000UL
#define I2C_BASE                        0x40070000UL
#define I2S_TX_BASE                     0x40080000UL
#define I2S_RX_BASE                     0x40090000UL
#define PWM_BASE                        0x400A0000UL
#define TIMER0_BASE                     0x400C0000UL
#define TIMER1_BASE                     0x400C0100UL
#define TIMER2_BASE                     0x400C0200UL
#define WDT_BASE                        0x400D0000UL
#define ADC_BASE                        0x40020800UL
#define CODEC_BASE                      0x400B0000UL
#define RTC_BASE                        0x400F0000UL
#define SYS_BASE                        0x40000000UL
#define PMU_BASE                        0x400E0000UL
#define CPM_BASE                        0x40002000UL
#define CLK_BASE                        0x40001000UL
#define MAC6200_BASE                    0x40004000UL
#define ANA_BASE                        0x4000F000UL
#define OTG_BASE                        0x45000000UL


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define BT_JAL                          ((BT_JAL_Type             *) BT_JAL_BASE)
#define BT_HAB                          ((BT_HAB_Type             *) BT_HAB_BASE)
#define BT_LE                           ((BT_LE_Type              *) BT_LE_BASE)
#define BT_PHY                          ((BT_PHY_Type             *) BT_PHY_BASE)
#define DMAC                            ((DMAC_Type               *) DMAC_BASE)
#define SFLASH                          ((SFLASH_Type             *) SFLASH_BASE)
#define GPIO0                           ((GPIO_Type               *) GPIO0_BASE)
#define GPIO1                           ((GPIO_Type               *) GPIO1_BASE)
#define USB_PERIPH_0                    ((USB_PERIPH_0_Type       *) USB_PERIPH_0_BASE)
#define HS_SDHC                         ((HS_SDHC_Type            *) MMC_SD_BASE)
#define UART0                           ((UART_Type               *) UART0_BASE)
#define UART1                           ((UART_Type               *) UART1_BASE)
#define SPI0                            ((SPI0_Type               *) SPI0_BASE)
#define SPI1                            ((SPI1_Type               *) SPI1_BASE)
#define I2C                             ((I2C_Type                *) I2C_BASE)
#define I2S_TX                          ((I2S_Type                *) I2S_TX_BASE)
#define I2S_RX                          ((I2S_Type                *) I2S_RX_BASE)
#define PWM                             ((PWM_Type                *) PWM_BASE)
#define TIMER0                          ((TIMER0_Type             *) TIMER0_BASE)
#define TIMER1                          ((TIMER1_Type             *) TIMER1_BASE)
#define TIMER2                          ((TIMER2_Type             *) TIMER2_BASE)
#define WDT                             ((WDT_Type                *) WDT_BASE)
#define ADC                             ((ADC_Type                *) ADC_BASE)
#define CODEC                           ((CODEC_Type              *) CODEC_BASE)
#define RTC                             ((RTC_Type                *) RTC_BASE)
#define SYS                             ((SYS_Type                *) SYS_BASE)
#define PMU                             ((PMU_Type                *) PMU_BASE)
#define CPM                             ((CPM_Type                *) CPM_BASE)
#define CLK                             ((CLK_Type                *) CLK_BASE)
#define MAC6200                         ((MAC6200_Type            *) MAC6200_BASE)
#define HS_USB                          ((HS_USB_Type             *) OTG_BASE)
#define HS_ANA                          ((HS_ANA_Type             *) ANA_BASE)


/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group HS6600 */
/** @} */ /* End of group (null) */


#define CH_KERNEL_MAJOR         3
#define CH_KERNEL_MINOR         0
#define CH_KERNEL_PATCH         1

#define HAL_SUCCESS             0
#define HAL_FAILED              1


#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define DIV_ROUND(n,d) (((n) + ((d) / 2)) / (d))
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define osalDbgAssert(con, str)   while(!(con));

#include "cpm.h"
#include "gpio.h"
#include "sflash.h"
#include "uart.h"
#include "usb.h"
#include "usb_serial.h"
#include "sdc.h"

#ifdef __cplusplus
}
#endif


#endif  /* HS6600_H */

