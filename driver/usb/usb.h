#ifndef _USB_DRV_H_
#define _USB_DRV_H_


#define USB_POWER_CONTROL_BY_HW             0x00000000
#define USB_POWER_CONTROL_BY_REG            0x00000001
#define USB_POWER_CONTROL_BY_GPIO           0x00000002

#if !defined(HS_USB_USB_IRQ_PRIORITY)
#define HS_USB_USB_IRQ_PRIORITY          3
#endif

#define USB_EP_MODE_TYPE                0x0003  /**< Endpoint type mask.    */
#define USB_EP_MODE_TYPE_CTRL           0x0000  /**< Control endpoint.      */
#define USB_EP_MODE_TYPE_ISOC           0x0001  /**< Isochronous endpoint.  */
#define USB_EP_MODE_TYPE_BULK           0x0002  /**< Bulk endpoint.         */
#define USB_EP_MODE_TYPE_INTR           0x0003  /**< Interrupt endpoint.    */
#define USB_EP_MODE_LINEAR_BUFFER       0x0000  /**< Linear buffer mode.    */
#define USB_EP_MODE_QUEUE_BUFFER        0x0010  /**< Queue buffer mode.     */


/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/
#define USB_RTYPE_DIR_MASK                  0x80
#define USB_RTYPE_DIR_HOST2DEV              0x00
#define USB_RTYPE_DIR_DEV2HOST              0x80
#define USB_RTYPE_TYPE_MASK                 0x60
#define USB_RTYPE_TYPE_STD                  0x00
#define USB_RTYPE_TYPE_CLASS                0x20
#define USB_RTYPE_TYPE_VENDOR               0x40
#define USB_RTYPE_TYPE_RESERVED             0x60
#define USB_RTYPE_RECIPIENT_MASK            0x1F
#define USB_RTYPE_RECIPIENT_DEVICE          0x00
#define USB_RTYPE_RECIPIENT_INTERFACE       0x01
#define USB_RTYPE_RECIPIENT_ENDPOINT        0x02
#define USB_RTYPE_RECIPIENT_OTHER           0x03

#define USB_REQ_GET_STATUS                  0
#define USB_REQ_CLEAR_FEATURE               1
#define USB_REQ_SET_FEATURE                 3
#define USB_REQ_SET_ADDRESS                 5
#define USB_REQ_GET_DESCRIPTOR              6
#define USB_REQ_SET_DESCRIPTOR              7
#define USB_REQ_GET_CONFIGURATION           8
#define USB_REQ_SET_CONFIGURATION           9
#define USB_REQ_GET_INTERFACE               10
#define USB_REQ_SET_INTERFACE               11
#define USB_REQ_SYNCH_FRAME                 12

#define USB_DESCRIPTOR_DEVICE               1
#define USB_DESCRIPTOR_CONFIGURATION        2
#define USB_DESCRIPTOR_STRING               3
#define USB_DESCRIPTOR_INTERFACE            4
#define USB_DESCRIPTOR_ENDPOINT             5
#define USB_DESCRIPTOR_DEVICE_QUALIFIER     6
#define USB_DESCRIPTOR_OTHER_SPEED_CFG      7
#define USB_DESCRIPTOR_INTERFACE_POWER      8
#define USB_DESCRIPTOR_INTERFACE_ASSOCIATION 11

#define USB_FEATURE_ENDPOINT_HALT           0
#define USB_FEATURE_DEVICE_REMOTE_WAKEUP    1
#define USB_FEATURE_TEST_MODE               2

#define USB_EARLY_SET_ADDRESS               0
#define USB_LATE_SET_ADDRESS                1
/**
 * @brief   Maximum endpoint address.
 */
#define USB_ENDOPOINTS_NUMBER               7
#define USB_MAX_ENDPOINTS                   USB_ENDOPOINTS_NUMBER

#define USB_CTRL_EP_PKT_SIZ                 64
#define USB_BULK_EP_PKT_SIZ                 64
#define USB_INT_EP_PKT_SIZ                  64


#define USB_DMA_CH_AUD_OUT                  2
#define USB_DMA_CH_AUD_IN                   3
#define USB_DMA_CH_STOR_OUT                 0
#define USB_DMA_CH_STOR_IN                  1
#define USB_DMA_MAX_CHANNELS                4

#define DMA_MODE_NONE                       0
//#define DMA_MODE_0                          1
//#define DMA_MODE_1                          2

#define USB_MODE_HOST                       0x00
#define USB_MODE_DEV                        0x01
#define USB_MODE_UNKNOWN                    0xff

#define USB_POWER_VBUS_NONE                 0x00
#define USB_POWER_VBUS_VALID                0x01
#define USB_POWER_VBUS_SESS_VALID           0x02
#define USB_POWER_VBUS_LO_VALID             0x04

#define USB_EPxFIFO_OFFSET(ep)               (0x20+(ep)*4)
#define USB_SET_ADDRESS_MODE                USB_LATE_SET_ADDRESS


#define CDC_SEND_ENCAPSULATED_COMMAND   0x00
#define CDC_GET_ENCAPSULATED_RESPONSE   0x01
#define CDC_SET_COMM_FEATURE            0x02
#define CDC_GET_COMM_FEATURE            0x03
#define CDC_CLEAR_COMM_FEATURE          0x04
#define CDC_SET_AUX_LINE_STATE          0x10
#define CDC_SET_HOOK_STATE              0x11
#define CDC_PULSE_SETUP                 0x12
#define CDC_SEND_PULSE                  0x13
#define CDC_SET_PULSE_TIME              0x14
#define CDC_RING_AUX_JACK               0x15
#define CDC_SET_LINE_CODING             0x20
#define CDC_GET_LINE_CODING             0x21
#define CDC_SET_CONTROL_LINE_STATE      0x22
#define CDC_SEND_BREAK                  0x23
#define CDC_SET_RINGER_PARMS            0x30
#define CDC_GET_RINGER_PARMS            0x31
#define CDC_SET_OPERATION_PARMS         0x32
#define CDC_GET_OPERATION_PARMS         0x33

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

typedef enum {
  USB_EVENT_RESET = 0,                  /**< Driver has been reset by host. */
  USB_EVENT_ADDRESS = 1,                /**< Address assigned.              */
  USB_EVENT_CONFIGURED = 2,             /**< Configuration selected.        */
  USB_EVENT_SUSPEND = 3,                /**< Entering suspend mode.         */
  USB_EVENT_WAKEUP = 4,                 /**< Leaving suspend mode.          */
  USB_EVENT_STALLED = 5                 /**< Endpoint 0 error, stalled.     */
} usbevent_t;

typedef struct USBDriver USBDriver;
typedef uint8_t usbep_t;
typedef struct {
  size_t          ud_size;
  const uint8_t   *ud_string;
} USBDescriptor;

typedef void (*usbcallback_t)(USBDriver *usbp);
typedef void (*usbepcallback_t)(USBDriver *usbp, usbep_t ep);
typedef void (*usbeventcb_t)(USBDriver *usbp, usbevent_t event);
typedef bool_t (*usbreqhandler_t)(USBDriver *usbp);
typedef const USBDescriptor * (*usbgetdescriptor_t)(USBDriver *usbp,
                                                    uint8_t dtype,
                                                    uint8_t dindex,
                                                    uint16_t lang);

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/
typedef enum {
  SDU_UNINIT = 0,                   /**< Not initialized.                   */
  SDU_STOP = 1,                     /**< Stopped.                           */
  SDU_READY = 2                     /**< Ready.                             */
} sdustate_t;

typedef enum {
  USB_UNINIT   = 0,                     /**< Not initialized.               */
  USB_STOP     = 1,                     /**< Stopped.                       */
  USB_READY    = 2,                     /**< Ready, after bus reset.        */
  USB_SELECTED = 3,                     /**< Address assigned.              */
  USB_ACTIVE   = 4                      /**< Active, configuration selected.*/
} usbstate_t;

typedef enum {
  USB_EP0_WAITING_SETUP,                /**< Waiting for SETUP data.        */
  USB_EP0_TX,                           /**< Transmitting.                  */
  USB_EP0_WAITING_TX0,                  /**< Waiting transmit 0.            */
  USB_EP0_WAITING_STS,                  /**< Waiting status.                */
  USB_EP0_RX,                           /**< Receiving.                     */
  USB_EP0_SENDING_STS,                  /**< Sending status.                */
  USB_EP0_ERROR                         /**< Error, EP0 stalled.            */
} usbep0state_t;

typedef enum {
  EP_STATUS_DISABLED = 0,               /**< Endpoint not active.           */
  EP_STATUS_STALLED = 1,                /**< Endpoint opened but stalled.   */
  EP_STATUS_ACTIVE = 2                  /**< Active endpoint.               */
} usbepstatus_t;

/**
 * @brief   Type of an IN endpoint state structure.
 */
typedef struct {
  bool_t                        txqueued;
  size_t                        txsize;
  size_t                        txcnt;
  const uint8_t                 *txbuf;
  uint8_t                       dma_mode;  
} USBInEndpointState;

/**
 * @brief   Type of an OUT endpoint state structure.
 */
typedef struct {
  bool_t                        rxqueued;
  size_t                        rxsize;
  size_t                        rxcnt;
  uint8_t                       *rxbuf;
  uint8_t                       dma_mode;
} USBOutEndpointState;

typedef struct{
    uint8_t         dma_ch[2];
    uint8_t         dma_mode[2];
    usbepcallback_t dma_outep_cb;
    usbepcallback_t dma_inep_cb;    
}usb_dma_info;

typedef struct {
  uint32_t                      ep_mode;
  
  usbepcallback_t               setup_cb;
  usbepcallback_t               in_cb;
  usbepcallback_t               out_cb;
  
  uint16_t                      in_maxsize;
  uint16_t                      out_maxsize;
  
  USBInEndpointState            *in_state;
  USBOutEndpointState           *out_state;
  
  uint16_t                      ep_buffers;
  uint8_t                       *setup_buf;

  usb_dma_info                  dma_info;

  bool_t                        inEp_thd_handle_mode;//TRUE, handle in trhead; FALSE, handle in interrupt
  bool_t                        outEp_thd_handle_mode;//TRUE, handle in trhead; FALSE, handle in interrupt
} USBEndpointConfig;



/**
 * @brief   Type of an USB driver configuration structure.
 */
typedef struct {
  usbeventcb_t                  event_cb;
  usbgetdescriptor_t            get_descriptor_cb;
  usbreqhandler_t               requests_hook_cb;
  usbcallback_t                 sof_cb;
} USBConfig;

/**
 * @brief   Structure representing an USB driver.
 */
struct USBDriver {
  usbstate_t                    state;
  const USBConfig               *config;
  
  volatile uint16_t             transmitting;
  volatile uint16_t             receiving;

  const USBEndpointConfig       *epc[USB_MAX_ENDPOINTS + 1];
  
  void                          *in_params[USB_MAX_ENDPOINTS];
  void                          *out_params[USB_MAX_ENDPOINTS];

  usbep0state_t                 ep0state;
  uint8_t                       *ep0next;
  size_t                        ep0n;
  usbcallback_t                 ep0endcb;
  uint8_t                       setup[8];
  uint16_t                      status;
  uint8_t                       address;
  uint8_t                       configuration;

  uint8_t                     remote_wake;

  uint16_t                    usb_vid;
  uint16_t                    usb_pid;
  uint32_t                    usb_pw_sess_mode;
};

typedef struct _FIFO_CONFIG
{
    uint8_t  EpNum;//bit7 = 1 means rx endponit, bit7 = 0 means tx endpoint
    uint8_t  DoubleBuf;// = 1, means doubling buffer is used
    uint16_t StartAddr;
    uint16_t FifoSize;//if  DoubleBuf=1, then actual fifo used is 2*FifoSize
}Fifo_Cfg;

typedef struct SerialUSBConfig SerialUSBConfig;

typedef struct  {
  sdustate_t                state;                                          \
  const SerialUSBConfig     *config;
}SerialUSBDriver;

struct SerialUSBConfig{
  USBDriver                 *usbp;
  usbep_t                   bulk_in;
  usbep_t                   bulk_out;
  usbep_t                   int_in;
} ;
/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @brief   Returns the current frame number.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @return              The current frame number.
 *
 * @notapi
 */
#define usb_lld_get_frame_number(usbp) (HS_USB->USB_FRAME)

#define usb_lld_stall_out_sent()  ((HS_USB->USB_RXCSR&HSUSB_RXCSR_P_SENTSTALL)?TRUE:FALSE)


#define usb_lld_enable_pmu_charger()   (PMU->ANA_CON &= ~(0x01<<5))
#define usb_lld_disable_pmu_charger()   (PMU->ANA_CON |= 0x01<<5)

#define _usb_isr_invoke_setup_cb(usbp, ep) {                                \
  (usbp)->epc[ep]->setup_cb(usbp, ep);                                      \
}

#define _usb_isr_invoke_in_cb(usbp, ep) {                                   \
  (usbp)->transmitting &= ~(1 << (ep));                                     \
  (usbp)->epc[ep]->in_cb(usbp, ep);                                         \
}

#define _usb_isr_invoke_out_cb(usbp, ep) {                                  \
  (usbp)->receiving &= ~(1 << (ep));                                        \
  (usbp)->epc[ep]->out_cb(usbp, ep);                                        \
}

#define usbReadSetup(ep, buf)         usb_lld_read_setup(ep, buf)
#define usbSetupTransfer(usbp, buf, n, endcb) {                             \
  (usbp)->ep0next  = (buf);                                                 \
  (usbp)->ep0n     = (n);                                                   \
  (usbp)->ep0endcb = (endcb);                                               \
}

#define _usb_isr_invoke_event_cb(usbp, evt) {                               \
  if ((usbp) && (usbp)->config && (usbp)->config->event_cb)                 \
    (usbp)->config->event_cb(usbp, evt);                                    \
}

#define usbFetchWord(p) ((uint16_t)*(p) | ((uint16_t)*((p) + 1) << 8))

#define usbGetTransmitStatusI(usbp, ep) ((usbp)->transmitting & (1 << (ep)))
#define usbSetTransmitStatusI(usbp, ep) ((usbp)->transmitting |= (1 << (ep)))
#define usbClearTransmitStatusI(usbp, ep)((usbp)->transmitting &= ~(1 << (ep)))

#define usbGetReceiveStatusI(usbp, ep) ((usbp)->receiving & (1 << (ep)))
#define usbSetReceiveStatusI(usbp, ep) ((usbp)->receiving |= (1 << (ep)))
#define usbClearReceiveStatusI(usbp, ep)((usbp)->receiving &= ~(1 << (ep)))

#define  usbConnectBus(usbp)      usb_lld_connect_bus(usbp)
#define  usbDisconnectBus(usbp)   usb_lld_disconnect_bus(usbp)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern USBDriver USBD1;

#ifdef __cplusplus
extern "C" {
#endif
  void usb_lld_init(void);
  void usb_lld_start(USBDriver *usbp);
  void usb_lld_reset(USBDriver *usbp);
  void usb_lld_set_address(USBDriver *usbp);
  void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep);
  usbepstatus_t usb_lld_get_status_in(usbep_t ep);
  usbepstatus_t usb_lld_get_status_out(usbep_t ep);
  void usb_lld_read_setup(usbep_t ep, uint8_t *buf);
  void usb_lld_prepare_receive(USBDriver *usbp, usbep_t ep);
  void usb_lld_prepare_transmit(USBDriver *usbp, usbep_t ep);
  void usb_lld_start_out(USBDriver *usbp, usbep_t ep);
  void usb_lld_start_in(USBDriver *usbp, usbep_t ep);
  void usb_lld_stall_out(usbep_t ep);
  void usb_lld_stall_in(usbep_t ep);
  void usb_lld_clear_out(usbep_t ep);
  void usb_lld_clear_in(usbep_t ep);
  void hsusb_start(USBDriver *usbp);
  void hsusb_fifo_setup(const Fifo_Cfg* cfg);
  void usb_lld_servedsetup(uint8_t bHasDataPhase);
  void hsusb_ep_int_enable(USBDriver *usbp, uint8_t epnum, uint8_t IsTx);

void hsusb_ep_select(uint8_t epnum);
void hsusb_ep_int_enable(USBDriver *usbp, uint8_t epnum, uint8_t IsTx);
void usb_lld_connect_bus(USBDriver *usbp);
void usb_lld_disconnect_bus(USBDriver *usbp);
void usb_packet_write_from_buffer(USBDriver *usbp, usbep_t ep,
                                         const uint8_t *buf,
                                         size_t n);
void usb_packet_read_to_buffer(USBDriver *usbp,usbep_t ep, uint8_t *buf, size_t n) ;
void usb_ldd_clear_datatoggle(usbep_t ep, uint8_t IsInEp);
uint8_t usb_lld_stall_in_sent(usbep_t ep);
uint8_t usb_lld_get_rx_data_len(usbep_t ep);
uint8_t usb_lld_read_power_reg(void);

void usb_finish_ep0setup(USBDriver *usbp, usbep_t ep);
void fifo_config(uint8_t num, const Fifo_Cfg* cfg);

void usbPrepareTransmit(USBDriver *usbp, usbep_t ep,
                        const uint8_t *buf, size_t n, uint8_t dma_mode);
bool_t usbStartTransmitI(USBDriver *usbp, usbep_t ep);

void usbPrepareReceive(USBDriver *usbp, usbep_t ep, uint8_t *buf, size_t n, uint8_t dma_mode);
uint32_t usbStartReceiveI(USBDriver *usbp, usbep_t ep);

void usbStart(USBDriver *usbp, const USBConfig *config);

#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* HS usb declarations.                                                    */
/*===========================================================================*/
/*
 * Common USB registers
 */
/* POWER */
#define      HSUSB_POWER_ISOUPDATE	0x80
#define      HSUSB_POWER_VBUSVAL     0x40
#define      HSUSB_POWER_VBUSSESS    0x20
#define      HSUSB_POWER_VBUSLO      0x10
#define      HSUSB_POWER_RESET	    0x08
#define      HSUSB_POWER_RESUME	    0x04
#define      HSUSB_POWER_SUSPENDM	0x02
#define      HSUSB_POWER_ENSUSPEND	0x01

/* INTRUSB */
#define      HSUSB_INTR_SUSPEND      0x01
#define      HSUSB_INTR_RESUME       0x02
#define      HSUSB_INTR_RESET		0x04
#define      HSUSB_INTR_BABBLE	    0x04
#define      HSUSB_INTR_SOF		    0x08
#define      HSUSB_INTR_CONNECT	    0x10
#define      HSUSB_INTR_DISCONNECT	0x20
#define      HSUSB_INTR_SESSREQ	    0x40
#define      HSUSB_INTR_VBUSERROR	0x80	/* For SESSION end */


/* DEVCTL */
#define      HSUSB_DEVCTL_BDEVICE	0x80
#define      HSUSB_DEVCTL_FSDEV	    0x40
#define      HSUSB_DEVCTL_LSDEV      0x20
#define      HSUSB_DEVCTL_PUCON		0x10
#define      HSUSB_DEVCTL_PDCON		0x08
#define      HSUSB_DEVCTL_HM		    0x04
#define      HSUSB_DEVCTL_HR		    0x02
#define      HSUSB_DEVCTL_SESSION	0x01


/*
 * USB INDEXED registers
 */
/* CSR0 */
#define HSUSB_CSR0_FLUSHFIFO	0x0100
#define HSUSB_CSR0_TXPKTRDY	0x0002
#define HSUSB_CSR0_RXPKTRDY	0x0001
/* CSR0 in Peripheral mode */
#define HSUSB_CSR0_P_SVDSETUPEND	0x0080
#define HSUSB_CSR0_P_SVDRXPKTRDY	0x0040
#define HSUSB_CSR0_P_SENDSTALL	0x0020
#define HSUSB_CSR0_P_SETUPEND	0x0010
#define HSUSB_CSR0_P_DATAEND	0x0008
#define HSUSB_CSR0_P_SENTSTALL	0x0004
/* CSR0 in Host mode */
#define HSUSB_CSR0_H_DIS_PING		0x0800
#define HSUSB_CSR0_H_WR_DATATOGGLE	0x0400	/* Set to allow setting: */
#define HSUSB_CSR0_H_DATATOGGLE		0x0200	/* Data toggle control */
#define HSUSB_CSR0_H_NAKTIMEOUT		0x0080
#define HSUSB_CSR0_H_STATUSPKT		0x0040
#define HSUSB_CSR0_H_REQPKT		0x0020
#define HSUSB_CSR0_H_ERROR		0x0010
#define HSUSB_CSR0_H_SETUPPKT		0x0008
#define HSUSB_CSR0_H_RXSTALL		0x0004
/* CSR0 bits to avoid zeroing (write zero clears, write 1 ignored) */
#define HSUSB_CSR0_P_WZC_BITS	\
	(HSUSB_CSR0_P_SENTSTALL)
#define HSUSB_CSR0_H_WZC_BITS	\
	(HSUSB_CSR0_H_NAKTIMEOUT | HSUSB_CSR0_H_RXSTALL \
	| HSUSB_CSR0_RXPKTRDY)

/* TXCSR in Peripheral and Host mode */
#define HSUSB_TXCSR_AUTOSET		0x8000
#define HSUSB_TXCSR_MODE			0x2000
#define HSUSB_TXCSR_DMAENAB		0x1000
#define HSUSB_TXCSR_FRCDATATOG	0x0800
#define HSUSB_TXCSR_DMAMODE		0x0400
#define HSUSB_TXCSR_CLRDATATOG	0x0040
#define HSUSB_TXCSR_FLUSHFIFO	0x0008
#define HSUSB_TXCSR_FIFONOTEMPTY	0x0002
#define HSUSB_TXCSR_TXPKTRDY		0x0001
/* TXCSR in Peripheral mode */
#define HSUSB_TXCSR_P_ISO		    0x4000
#define HSUSB_TXCSR_P_INCOMPTX		0x0080
#define HSUSB_TXCSR_P_SENTSTALL		0x0020
#define HSUSB_TXCSR_P_SENDSTALL		0x0010
#define HSUSB_TXCSR_P_UNDERRUN		0x0004
/* TXCSR in Host mode */
#define HSUSB_TXCSR_H_WR_DATATOGGLE	0x0200
#define HSUSB_TXCSR_H_DATATOGGLE		0x0100
#define HSUSB_TXCSR_H_NAKTIMEOUT		0x0080
#define HSUSB_TXCSR_H_RXSTALL		0x0020
#define HSUSB_TXCSR_H_ERROR		    0x0004

/* TXCSR bits to avoid zeroing (write zero clears, write 1 ignored) */
#define HSUSB_TXCSR_P_WZC_BITS	\
	( HSUSB_TXCSR_P_SENTSTALL | HSUSB_TXCSR_P_UNDERRUN \
        | HSUSB_TXCSR_FIFONOTEMPTY)
#define HSUSB_TXCSR_H_WZC_BITS	\
	(HSUSB_TXCSR_H_NAKTIMEOUT | HSUSB_TXCSR_H_RXSTALL \
	| HSUSB_TXCSR_H_ERROR | HSUSB_TXCSR_FIFONOTEMPTY)

/* RXCSR in Peripheral and Host mode */
#define HSUSB_RXCSR_AUTOCLEAR		0x8000
#define HSUSB_RXCSR_DMAENAB		    0x2000
#define HSUSB_RXCSR_DMAMODE		    0x1000
#define HSUSB_RXCSR_CLRDATATOG		0x0080
#define HSUSB_RXCSR_FLUSHFIFO		0x0010
#define HSUSB_RXCSR_DATAERROR		0x0008
#define HSUSB_RXCSR_FIFOFULL		    0x0002
#define HSUSB_RXCSR_RXPKTRDY		    0x0001
/* RXCSR in Peripheral mode */
#define HSUSB_RXCSR_P_ISO		    0x4000
#define HSUSB_RXCSR_P_SENTSTALL		0x0040
#define HSUSB_RXCSR_P_SENDSTALL		0x0020
#define HSUSB_RXCSR_P_OVERRUN		0x0004
/* RXCSR in Host mode */
#define HSUSB_RXCSR_H_AUTOREQ		0x4000
#define HSUSB_RXCSR_H_RXSTALL		0x0040
#define HSUSB_RXCSR_H_REQPKT		0x0020
#define HSUSB_RXCSR_H_ERROR		0x0004
/* RXCSR bits to avoid zeroing (write zero clears, write 1 ignored) */
#define HSUSB_RXCSR_P_WZC_BITS	\
	(HSUSB_RXCSR_P_SENTSTALL | HSUSB_RXCSR_P_OVERRUN \
	| HSUSB_RXCSR_RXPKTRDY)
#define HSUSB_RXCSR_H_WZC_BITS	\
	(HSUSB_RXCSR_H_RXSTALL | HSUSB_RXCSR_H_ERROR \
	| HSUSB_RXCSR_DATAERROR | HSUSB_RXCSR_RXPKTRDY)

#define HSUSB_TYPE_PROTO		0x30	/* Implicitly zero for ep0 */
#define HSUSB_TYPE_PROTO_SHIFT	4
#define HSUSB_TYPE_REMOTE_END	0xf	/* Implicitly zero for ep0 */

#define HSUSB_FIFO_ADD_SHIFT             0
#define HSUSB_FIFO_SIZE_SHIFT            13
/* Allocate for double-packet buffering (effectively doubles assigned _SIZE) */
#define HSUSB_FIFOSZ_DPB	        0x100
/* Allocation size (8, 16, 32, ... 4096) */
#define HSUSB_FIFOSZ_SIZE	0x07



#endif /* _USB_LLD_H_ */

/** @} */
