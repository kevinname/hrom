#include <string.h>
#include "platform.h"

void hs66xx_usb_dma_irq_channel(USBDriver *usbp, uint8_t bchannel);

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

USBDriver USBD1;


/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/**
 * @brief   EP0 state.
 * @note    It is an union because IN and OUT endpoints are never used at the
 *          same time for EP0.
 */
static union {
  USBInEndpointState in;
  USBOutEndpointState out;
} ep0_state;

static uint8_t ep0setup_buffer[8];

static const uint8_t zero_status[] = {0x00, 0x00};
static const uint8_t active_status[] ={0x00, 0x00};
static const uint8_t halted_status[] = {0x01, 0x00};

static uint8_t g_InEpStatus[4] = {0,0,0,0};
static uint8_t g_OutEpStatus[4] = {0,0,0,0};
static uint8_t g_CurrentInterface = 0;

static uint8_t usb_dev_descriptor_buf[18];

static void set_address(USBDriver *usbp) 
{
  osalDbgAssert(usbp, "set_address()");
  usbp->address = usbp->setup[2];
  usb_lld_set_address(usbp);
  _usb_isr_invoke_event_cb(usbp, USB_EVENT_ADDRESS);
  usbp->state = USB_SELECTED;
}

void _usb_reset(USBDriver *usbp) 
{
    unsigned i;

    osalDbgAssert(usbp, "_usb_reset()");
  
    usbp->state         = USB_READY;
    usbp->status        = 0;
    usbp->address       = 0;
    usbp->configuration = 0;
    usbp->transmitting  = 0;
    usbp->receiving     = 0;

    /* Invalidates all endpoints into the USBDriver structure.*/
    for (i = 0; i <= USB_MAX_ENDPOINTS; i++)
        usbp->epc[i] = NULL;

    /* EP0 state machine initialization.*/
    usbp->ep0state = USB_EP0_WAITING_SETUP;

    hsusb_start(usbp);

    /* Low level reset.*/
    usb_lld_reset(usbp);
}


void usbPrepareTransmit(USBDriver *usbp, usbep_t ep,
                        const uint8_t *buf, size_t n, uint8_t dma_mode)
{
  USBInEndpointState *isp = usbp->epc[ep]->in_state;
  volatile uint16_t tx = 2;

  osalDbgAssert(usbp&&buf&&isp, "usbPrepareTransmit()");

  isp->txqueued           = FALSE;
  isp->txbuf              = buf;
  isp->txsize             = n;
  isp->txcnt              = 0;
  isp->dma_mode           = dma_mode;

  while (tx)
    tx = usbGetTransmitStatusI(usbp, ep);
  
  usb_lld_prepare_transmit(usbp, ep);
}

bool_t usbStartTransmitI(USBDriver *usbp, usbep_t ep) 
{
  if (usbGetTransmitStatusI(usbp, ep))
    return TRUE;

  usbp->transmitting |= (1 << ep);
  usb_lld_start_in(usbp, ep);

  return FALSE;
}

void usbPrepareReceive(USBDriver *usbp, usbep_t ep, uint8_t *buf, size_t n, uint8_t dma_mode)
{
  osalDbgAssert(usbp&&buf, "usbPrepareReceive()");

  USBOutEndpointState *osp = usbp->epc[ep]->out_state;

  osalDbgAssert(osp, "usbPrepareReceive()");

  osp->rxqueued           = FALSE;
  osp->rxbuf              = buf;
  osp->rxsize             = n;
  osp->rxcnt              = 0;
  osp->dma_mode           = dma_mode;

  usb_lld_prepare_receive(usbp, ep);
}

uint32_t usbStartReceiveI(USBDriver *usbp, usbep_t ep) 
{
  USBOutEndpointState *osp = usbp->epc[ep]->out_state;
  
  if (usbGetReceiveStatusI(usbp, ep))
    return 0;

  usbp->receiving |= (1 << ep);
  usb_lld_start_out(usbp, ep);
  return osp->rxcnt;
}

void usb_finish_ep0setup(USBDriver *usbp, usbep_t ep)
{
    size_t max;

    (void)ep;
    osalDbgAssert(usbp, "usb_finish_ep0setup()");
    
    usb_lld_servedsetup(!(usbp->setup[6]==0&&usbp->setup[7]==0));

    /* Transfer preparation. The request handler must have populated
         correctly the fields ep0next, ep0n and ep0endcb using the macro
        usbSetupTransfer().*/
    max = usbFetchWord(&usbp->setup[6]);
    
    /* The transfer size cannot exceed the specified amount.*/
    if (usbp->ep0n > max)
    usbp->ep0n = max;

    if ((usbp->setup[0] & USB_RTYPE_DIR_MASK) == USB_RTYPE_DIR_DEV2HOST) 
    {
        /* IN phase.*/
        if (usbp->ep0n > 0) 
        {
          /* Starts the transmit phase.*/
          usbp->ep0state = USB_EP0_TX;
          usbPrepareTransmit(usbp, 0, usbp->ep0next, usbp->ep0n, DMA_MODE_NONE);
          //chSysLockFromIsr();
          usbStartTransmitI(usbp, 0);
          //chSysUnlockFromIsr();      
        }
        else 
        {
          /* No transmission phase, directly receiving the zero sized status
                packet.*/
          usbp->ep0state = USB_EP0_WAITING_STS;
        }
    }
    else 
    {
        /* OUT phase.*/
        if (usbp->ep0n > 0) 
        {
            /* Starts the receive phase.*/
            usbp->ep0state = USB_EP0_RX;
            usbPrepareReceive(usbp, 0, usbp->ep0next, usbp->ep0n, DMA_MODE_NONE);
        }
        else 
        {
            /* No receive phase, directly sending the zero sized status
                    packet.*/
            usbp->ep0state = USB_EP0_SENDING_STS;
        }
    }
}


static bool_t default_handler(USBDriver *usbp) 
{
  const USBDescriptor *dp;
  bool_t ret = FALSE;

  osalDbgAssert(usbp, "default_handler()");
  
  /* Decoding the request.*/
  switch (((usbp->setup[0] & (USB_RTYPE_RECIPIENT_MASK |
                              USB_RTYPE_TYPE_MASK)) |
           (usbp->setup[1] << 8))) {
  case USB_RTYPE_RECIPIENT_DEVICE | (USB_REQ_GET_STATUS << 8):
    /* Just returns the current status word.*/
    usbSetupTransfer(usbp, (uint8_t *)&usbp->status, 2, NULL);
    ret = TRUE;
    break;
  case USB_RTYPE_RECIPIENT_DEVICE | (USB_REQ_CLEAR_FEATURE << 8):
    /* Only the DEVICE_REMOTE_WAKEUP is handled here, any other feature
       number is handled as an error.*/
    if (usbp->setup[2] == USB_FEATURE_DEVICE_REMOTE_WAKEUP) {
      usbp->status &= ~2;
      usbSetupTransfer(usbp, NULL, 0, NULL);
      ret = TRUE;
    }
    break;
    //return FALSE;
  case USB_RTYPE_RECIPIENT_DEVICE | (USB_REQ_SET_FEATURE << 8):
    /* Only the DEVICE_REMOTE_WAKEUP is handled here, any other feature
       number is handled as an error.*/
    if (usbp->setup[2] == USB_FEATURE_DEVICE_REMOTE_WAKEUP) {
      usbp->status |= 2;
      usbSetupTransfer(usbp, NULL, 0, NULL);
      ret = TRUE;
    }
    break;
  case USB_RTYPE_RECIPIENT_DEVICE | (USB_REQ_SET_ADDRESS << 8):
    /* The SET_ADDRESS handling can be performed here or postponed after
       the status packed depending on the USB_SET_ADDRESS_MODE low
       driver setting.*/
   #if USB_SET_ADDRESS_MODE == USB_EARLY_SET_ADDRESS
    if ((usbp->setup[0] == USB_RTYPE_RECIPIENT_DEVICE) &&
        (usbp->setup[1] == USB_REQ_SET_ADDRESS))
      set_address(usbp);
    usbSetupTransfer(usbp, NULL, 0, NULL);
   #else
    //run here, pj
    usbSetupTransfer(usbp, NULL, 0, set_address);
   #endif
    ret = TRUE;
    break;
  case USB_RTYPE_RECIPIENT_DEVICE | (USB_REQ_GET_DESCRIPTOR << 8):
    /* luwei: sanity check to avoid crash */
    if (!usbp->config) {
      ret = FALSE;
      break;
    }
    /* Handling descriptor requests from the host.*/
    dp = usbp->config->get_descriptor_cb(
           usbp, usbp->setup[3], usbp->setup[2],
           usbFetchWord(&usbp->setup[4]));   
    if (dp == NULL)
    {
      ret = FALSE;
    }
    else
    {
        if(USB_DESCRIPTOR_DEVICE==usbp->setup[3])
        {
            memcpy(usb_dev_descriptor_buf,dp->ud_string,dp->ud_size);
            if(usbp->usb_vid)
            {
                memcpy(&usb_dev_descriptor_buf[8],&usbp->usb_vid,2);
            }
            if(usbp->usb_pid)
            {
                memcpy(&usb_dev_descriptor_buf[10],&usbp->usb_pid,2);
            }
            usbSetupTransfer(usbp, usb_dev_descriptor_buf, dp->ud_size, NULL);
        }
        else
        {
            usbSetupTransfer(usbp, (uint8_t *)dp->ud_string, dp->ud_size, NULL);
        }
        ret = TRUE;
    }
    
    if(USB_DESCRIPTOR_CONFIGURATION == usbp->setup[3])
    {
        usbp->remote_wake = (dp->ud_string[7]&(0x01<<5))?TRUE:FALSE;
    }    
    
    break;
  case USB_RTYPE_RECIPIENT_INTERFACE| (USB_REQ_GET_DESCRIPTOR << 8):
    /* luwei: sanity check to avoid crash */
    if (!usbp->config) {
      ret = FALSE;
      break;
    }
    /* Handling descriptor requests from the host.*/
    dp = usbp->config->get_descriptor_cb(
           usbp, usbp->setup[3], usbp->setup[2],
           usbFetchWord(&usbp->setup[4]));   
    if (dp == NULL)
    {
      ret = FALSE;
    }
    else
    {
        usbSetupTransfer(usbp, (uint8_t *)dp->ud_string, dp->ud_size, NULL);
        ret = TRUE;
    }   
    break;
  case USB_RTYPE_RECIPIENT_DEVICE | (USB_REQ_GET_CONFIGURATION << 8):
    /* Returning the last selected configuration.*/
    usbSetupTransfer(usbp, &usbp->configuration, 1, NULL);
    ret = TRUE;
    break;
  case USB_RTYPE_RECIPIENT_DEVICE | (USB_REQ_SET_CONFIGURATION << 8):
    /* Handling configuration selection from the host.*/
    usbp->configuration = usbp->setup[2];
    if (usbp->configuration == 0)
    {
        //usbp->state = USB_SELECTED;
        usbSetupTransfer(usbp, NULL, 0, NULL);
        ret = TRUE;        
    }
    else if(usbp->configuration == 1)
    {
        usbp->state = USB_ACTIVE;
        _usb_isr_invoke_event_cb(usbp, USB_EVENT_CONFIGURED);
        usbSetupTransfer(usbp, NULL, 0, NULL);
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }
    break;
  case USB_RTYPE_RECIPIENT_INTERFACE | (USB_REQ_GET_STATUS << 8):
  case USB_RTYPE_RECIPIENT_ENDPOINT | (USB_REQ_SYNCH_FRAME << 8):
    /* Just sending two zero bytes, the application can change the behavior
       using a hook..*/
    usbSetupTransfer(usbp, (uint8_t *)zero_status, 2, NULL);
    ret = TRUE;
    break;
  case USB_RTYPE_RECIPIENT_ENDPOINT | (USB_REQ_GET_STATUS << 8):
    /* Sending the EP status.*/
    if (usbp->setup[4] & 0x80) {
      if(g_InEpStatus[usbp->setup[4] & 0x0F])
      {
        usbSetupTransfer(usbp, (uint8_t *)halted_status, 2, NULL);
        ret = TRUE;
        break;      
      }
      else
      {
        usbSetupTransfer(usbp, (uint8_t *)active_status, 2, NULL);
        ret = TRUE;
        break;         
      }
    }
    else {
      if(g_OutEpStatus[usbp->setup[4] & 0x0F])
      {
        usbSetupTransfer(usbp, (uint8_t *)halted_status, 2, NULL);
        ret = TRUE;
      }
      else
      {
        usbSetupTransfer(usbp, (uint8_t *)active_status, 2, NULL);
        ret = TRUE;
      }
    }
    break;
  case USB_RTYPE_RECIPIENT_ENDPOINT | (USB_REQ_CLEAR_FEATURE << 8):
    /* Only ENDPOINT_HALT is handled as feature.*/
    if (usbp->setup[2] != USB_FEATURE_ENDPOINT_HALT)
    {
        ret = FALSE;
        break;
    }

    
    /* Clearing the EP status, not valid for EP0, it is ignored in that case.*/
    if ((usbp->setup[4] & 0x0F) > 0) 
    {
      if (usbp->setup[4] & 0x80)
      {
        g_InEpStatus[usbp->setup[4] & 0x0F] = 0;
        //usb_lld_clear_in(usbp, usbp->setup[4] & 0x0F);
      }
      else
      {
        g_OutEpStatus[usbp->setup[4] & 0x0F] = 0;
        //usb_lld_clear_out(usbp, usbp->setup[4] & 0x0F);
      }
    }
    usbSetupTransfer(usbp, NULL, 0, NULL);
    ret = TRUE;
    break;
  case USB_RTYPE_RECIPIENT_ENDPOINT | (USB_REQ_SET_FEATURE << 8):
    /* Only ENDPOINT_HALT is handled as feature.*/
    if (usbp->setup[2] != USB_FEATURE_ENDPOINT_HALT)
    {
        ret = FALSE;
        break;
    }
    /* Stalling the EP, not valid for EP0, it is ignored in that case.*/
    if ((usbp->setup[4] & 0x0F) > 0) {
      if (usbp->setup[4] & 0x80)
      {
        g_InEpStatus[usbp->setup[4] & 0x0F] = 1;
        usb_lld_stall_in(usbp->setup[4] & 0x0F);
      }
      else
      {
        g_OutEpStatus[usbp->setup[4] & 0x0F] = 1;
        usb_lld_stall_out(usbp->setup[4] & 0x0F);
      }       
    }
    usbSetupTransfer(usbp, NULL, 0, NULL);
    ret = TRUE;
    break;
  case USB_RTYPE_RECIPIENT_INTERFACE | (USB_REQ_SET_INTERFACE << 8):
    g_CurrentInterface = usbp->setup[2];
    usbSetupTransfer(usbp, NULL, 0, NULL);
    ret = TRUE;
    break;
  case USB_RTYPE_RECIPIENT_INTERFACE | (USB_REQ_GET_INTERFACE << 8):
    usbSetupTransfer(usbp, (uint8_t *)&g_CurrentInterface, 1, NULL);
    ret = TRUE;
    break;
  case USB_RTYPE_RECIPIENT_DEVICE | (USB_REQ_SET_DESCRIPTOR << 8):
  case USB_RTYPE_RECIPIENT_INTERFACE | (USB_REQ_CLEAR_FEATURE << 8):
  case USB_RTYPE_RECIPIENT_INTERFACE | (USB_REQ_SET_FEATURE << 8):
    /* All the above requests are not handled here, if you need them then
       use the hook mechanism and provide handling.*/
  default:
    break;
  }

  if(ret == TRUE)
  {
    usb_finish_ep0setup(usbp, 0);
  }
  return ret;
}

void usbPrepareTransmit_2(USBDriver *usbp, usbep_t ep)
{

  osalDbgAssert(usbp, "usbPrepareTransmit_2()");
  usb_lld_prepare_transmit(usbp, ep);
}


void _usb_ep0setup(USBDriver *usbp, usbep_t ep) 
{
    osalDbgAssert(usbp&&usbp->config, "_usb_ep0setup()");

    usbp->ep0state = USB_EP0_WAITING_SETUP;
    usbReadSetup(ep, usbp->setup);

    /* luwei: sanity check to avoid crash */
    if (!usbp->config)
      return;
  /* First verify if the application has an handler installed for this
     request.*/
    if (!(usbp->config->requests_hook_cb) ||
      !(usbp->config->requests_hook_cb(usbp))) 
    {
    /* Invoking the default handler, if this fails then stalls the
       endpoint zero as error.*/
        if (((usbp->setup[0] & USB_RTYPE_TYPE_MASK) != USB_RTYPE_TYPE_STD) ||
        !default_handler(usbp)) 
        {
            /* Error response, the state machine goes into an error state, the low
                 level layer will have to reset it to USB_EP0_WAITING_SETUP after
                 receiving a SETUP packet.*/
            usb_lld_stall_in(0);
            //usb_lld_stall_out(usbp, 0);
            _usb_isr_invoke_event_cb(usbp, USB_EVENT_STALLED);
            usbp->ep0state = USB_EP0_WAITING_SETUP;
            return;
        }
    }
}

void _usb_ep0in(USBDriver *usbp, usbep_t ep) 
{  
	(void)ep;
    osalDbgAssert(usbp, "_usb_ep0in()");

    switch (usbp->ep0state) 
    {
        case USB_EP0_TX:
            usbPrepareTransmit_2(usbp, 0);      
            //chSysLockFromIsr();
            usbStartTransmitI(usbp, 0);
            //chSysUnlockFromIsr(); 
            return;
        case USB_EP0_WAITING_STS:
            /* Status packet received, it must be zero sized, invoking the callback
                    if defined.*/
            if (usbp->ep0endcb != NULL)
            {
                usbp->ep0endcb(usbp);
            }
            usbp->ep0state = USB_EP0_WAITING_SETUP;
            return;    
        default:
            ;
    }
    /* Error response, the state machine goes into an error state, the low
        level layer will have to reset it to USB_EP0_WAITING_SETUP after
        receiving a SETUP packet.*/
    usb_lld_stall_in(0);
    usb_lld_stall_out(0);
    _usb_isr_invoke_event_cb(usbp, USB_EVENT_STALLED);
    usbp->ep0state = USB_EP0_ERROR;
}

void _usb_ep0out(USBDriver *usbp, usbep_t ep) 
{
  (void)ep;
  osalDbgAssert(usbp, "_usb_ep0out()");
  switch (usbp->ep0state) {
  case USB_EP0_RX:
    usbStartReceiveI(usbp, 0);
    return;
  case USB_EP0_SENDING_STS:
    /* Status packet sent, invoking the callback if defined.*/
    if (usbp->ep0endcb != NULL)
      usbp->ep0endcb(usbp);
    usbp->ep0state = USB_EP0_WAITING_SETUP;
    return;    
  default:
    ;
  }
  /* Error response, the state machine goes into an error state, the low
     level layer will have to reset it to USB_EP0_WAITING_SETUP after
     receiving a SETUP packet.*/
  usb_lld_stall_in(0);
  usb_lld_stall_out(0);
  _usb_isr_invoke_event_cb(usbp, USB_EVENT_STALLED);
  usbp->ep0state = USB_EP0_ERROR;
}



/**
 * @brief   EP0 initialization structure.
 */
static const USBEndpointConfig ep0config = {
  USB_EP_MODE_TYPE_CTRL,
  _usb_ep0setup,
  _usb_ep0in,
  _usb_ep0out,
  USB_CTRL_EP_PKT_SIZ,
  USB_CTRL_EP_PKT_SIZ,
  &ep0_state.in,
  &ep0_state.out, 
  1,
  ep0setup_buffer,
  {
    {0xFF, 0xFF},
    {DMA_MODE_NONE, DMA_MODE_NONE},
    NULL,
    NULL,    
  },
  0, 0
};

const Fifo_Cfg fifo_cfg_ep0[] = 
{   
    //EP0 out
    {
        0x00,
        0,
        0,
        64,
    },
    //EP0 In
    {
        0x80,
        0,
        0,
        64,
    },    
};

uint8_t g_UsbMode = USB_MODE_UNKNOWN;

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/
void hsusb_ep_select(uint8_t epnum)
{
    HS_USB->USB_INDEX = epnum&0x0f;
}

void hsusb_ep_int_enable(USBDriver *usbp, uint8_t epnum, uint8_t IsTx)
{
    uint16_t IntEn = IsTx?HS_USB->USB_INTTXEN:HS_USB->USB_INTRXEN;

    osalDbgAssert(usbp, "hsusb_ep_int_enable()"); 
    
    IntEn |= 1<<epnum;
    if(IsTx)
    {
        HS_USB->USB_INTTXEN = IntEn;
    }
    else
    {
        HS_USB->USB_INTRXEN = IntEn;
    }
}
void hsusb_start(USBDriver *usbp)
{
    osalDbgAssert(usbp,"hsusb_start()"); 
    
	/*  Set INT enable registers, enable interrupts */
    HS_USB->USB_INTTXEN = 0x0000;
    HS_USB->USB_INTRXEN = 0x0000;
    hsusb_ep_int_enable(usbp, 0, TRUE);
    HS_USB->USB_INTUSBEN = 0xf7;
    HS_USB->USB_ADDR = 0x00;   
 
}

void hsusb_fifo_setup(const Fifo_Cfg* cfg)
{
    uint16_t siz = cfg->FifoSize;
    uint16_t offset = cfg->StartAddr;
    uint16_t regval = 0;
    uint8_t  epnum = cfg->EpNum&0x7f;

    osalDbgAssert(cfg, "hsusb_fifo_setup()"); 
    
    if(siz<8||(siz%8))
    {
        return;
    }
    switch(siz)
    {
        case 16: 
            regval = 1;
            break;
        case 32:
            regval = 2;
            break;
        case 64:
            regval = 3;
            break;
        case 128:
            regval = 4;
            break;
        case 256:
            regval = 5;
            break;
        case 8:
        default:
            regval = 0;
            break;
    }
    regval <<=13;
    regval |= (offset>>3);
    if(cfg->DoubleBuf)
    {
        regval|= 1<<12;
    }
    hsusb_ep_select(epnum);
    if(cfg->EpNum&0x80)
    {  
        HS_USB->USB_TXFIFO = regval;
    }
    else
    {
        HS_USB->USB_RXFIFO = regval;
    }
}

uint8_t usb_lld_check_host_mode(void)
{   
    if(HS_USB->USB_DEVCTL&0x80)
    {
        //dev mode
        return USB_MODE_DEV;
    }
    else
    {
        //hostmode
        return USB_MODE_HOST;
    }
}


/**
 * @brief   Reads from a dedicated packet buffer for OUT EP
 *
 * @param[in] udp       pointer to a @p stm32_usb_descriptor_t
 * @param[out] buf      buffer where to copy the packet data
 * @param[in] n         maximum number of bytes to copy. This value must
 *                      not exceed the maximum packet size for this endpoint.
 *
 * @notapi
 */
void usb_packet_read_to_buffer(USBDriver *usbp,usbep_t ep, uint8_t *buf, size_t n) 
{
    (void)usbp;
    
    size_t i = 0;
    volatile uint8_t  *pb =    (uint8_t *) (OTG_BASE+USB_EPxFIFO_OFFSET(ep));

    for(i= 0;i<n;i++)
    {
        buf[i] = *pb;
    }
}


/**
 * @brief   Writes to a dedicated packet buffer for In EP
 *
 * @param[in] udp       pointer to a @p stm32_usb_descriptor_t
 * @param[in] buf       buffer where to fetch the packet data
 * @param[in] n         maximum number of bytes to copy. This value must
 *                      not exceed the maximum packet size for this endpoint.
 *
 * @notapi
 */
void usb_packet_write_from_buffer(USBDriver *usbp, usbep_t ep,
                                         const uint8_t *buf,
                                         size_t n) 
{
    size_t i = 0;
    volatile uint8_t  *pb = (uint8_t *)(OTG_BASE+USB_EPxFIFO_OFFSET(ep));

    osalDbgAssert(usbp&&buf&&pb, "usb_packet_write_from_buffer()"); 

    for(i= 0;i<n;i++)
    {
        *pb = buf[i];
    }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/
void usb_global_handler(USBDriver *usbp, uint8_t int_usb)
{

    uint8_t power;

    osalDbgAssert(usbp, "func()"); 

    power = HS_USB->USB_POWER;
    if(int_usb & HSUSB_INTR_RESUME)
    {
        //handle resume
        if (!(power & HSUSB_POWER_VBUSVAL)) 
        {
            uint8_t int_usb_new = int_usb;
            int_usb_new |= HSUSB_INTR_DISCONNECT;
            int_usb_new &= ~HSUSB_INTR_SUSPEND;
            HS_USB->USB_INTUSB = int_usb_new;
        }
        _usb_isr_invoke_event_cb(usbp, USB_EVENT_WAKEUP);
    }
    if (int_usb & HSUSB_INTR_SESSREQ)
    {
        //handle session
    }
    if (int_usb & HSUSB_INTR_VBUSERROR)
    {
        //handle vbus error
    }
    if (int_usb & HSUSB_INTR_SUSPEND)
    {
        //handle suspend
        _usb_isr_invoke_event_cb(usbp, USB_EVENT_SUSPEND);
        //test suspend/resume
        //HS_SYS->USB_CTRL|=(0x0001<<8);
    }
    //if (int_usb & HSUSB_INTR_CONNECT)
    //{
    
    //}
    if(int_usb & HSUSB_INTR_DISCONNECT)
    {
        g_UsbMode = USB_MODE_UNKNOWN;
        _usb_reset(usbp);
        _usb_isr_invoke_event_cb(usbp, USB_EVENT_RESET); 
    }
    if (int_usb & HSUSB_INTR_RESET)    
    {
        _usb_reset(usbp);
        _usb_isr_invoke_event_cb(usbp, USB_EVENT_RESET);    
        //HS_USB->USB_POWER|=0x01;//test suspend/resume
    }
}


void usb_ep0_handler(USBDriver *usbp)
{
    osalDbgAssert(usbp, "func()");
    
    hsusb_ep_select(0);

    if(HS_USB->USB_CSR0&HSUSB_CSR0_P_SENTSTALL)
    {
        usb_lld_clear_in(0);
        //usb_lld_clear_out(usbp, 0);
    }
    
    if(usbp->ep0state == USB_EP0_WAITING_SETUP)
    {
        if(HS_USB->USB_CSR0&HSUSB_CSR0_RXPKTRDY)
        {
            _usb_isr_invoke_setup_cb(usbp, 0);
        }
        else
        {
        }
    }
    else
    {
        if((usbp->setup[0] & USB_RTYPE_DIR_MASK) == USB_RTYPE_DIR_DEV2HOST)
        {
            _usb_isr_invoke_in_cb(usbp, 0);        
        }
        else
        {
            _usb_isr_invoke_out_cb(usbp, 0);
        }
    }
}

void usb_tx_epx_handler(USBDriver *usbp, uint8_t ep_num)
{

    osalDbgAssert(usbp, "func()"); 

    hsusb_ep_select(ep_num);
    if(HS_USB->USB_TXCSR&HSUSB_TXCSR_P_SENTSTALL)
    {
        usb_lld_clear_in(ep_num);
        usbp->transmitting &= ~(1 <<ep_num); 
        return;
    }

    _usb_isr_invoke_in_cb(usbp,ep_num);    
}

void usb_rx_epx_handler(USBDriver *usbp, uint8_t ep_num)
{

    osalDbgAssert(usbp, "func()");

    hsusb_ep_select(ep_num);
    if(HS_USB->USB_RXCSR & HSUSB_RXCSR_P_SENTSTALL)
    {
        usb_lld_clear_out(ep_num);
        return;
    }

    _usb_isr_invoke_out_cb(usbp,ep_num);
}

static void hs66xx_usb_irq(USBDriver *usbp) 
{
  uint8_t int_usb = HS_USB->USB_INTUSB;
  uint16_t int_tx = HS_USB->USB_INTTX;
  uint16_t int_rx = HS_USB->USB_INTRX;

  osalDbgAssert(usbp, "hs66xx_usb_irq()");
    
  if(g_UsbMode == USB_MODE_UNKNOWN)
  {
    if(int_usb&(HSUSB_INTR_RESET|HSUSB_INTR_CONNECT))
    {
      g_UsbMode = usb_lld_check_host_mode();            
    }
    else
    {
      return;
    }
  }
  
  if(int_usb)
  {
    usb_global_handler(usbp, int_usb);
  }
  
  if(int_rx)
  {
    uint16_t reg = int_rx >> 1;
    uint8_t ep_num = 1;
    while (reg) 
    {
      if (reg & 1) 
      {
        usb_rx_epx_handler(usbp, ep_num);//ep out
      }
      
      reg >>= 1;
      ep_num++;
    }          
  }
        
  if(int_tx)
  {
    if(int_tx&0x0001)
    {
      usb_ep0_handler(usbp);
    }
    else
    {
      uint16_t reg = int_tx >> 1;
      uint8_t ep_num = 1;
      while (reg) 
      {
        if (reg & 1) 
        {
          usb_tx_epx_handler(usbp, ep_num);//ep in
        }
        
        reg >>= 1;
        ep_num++;
      }    
    }
  }
}

/**
 * @brief   USB interrupt handler.
 *
 * @isr
 */
void OTG_IRQHandler(void) 
{
    hs66xx_usb_irq(&USBD1);
}

void fifo_config(uint8_t num, const Fifo_Cfg* cfg)
{
    uint8_t i = 0;

    osalDbgAssert(cfg, "fifo_config()");
    
    for(i=0;i<num;i++)
    {
        hsusb_fifo_setup(&cfg[i]);                        
    }
}

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level USB driver initialization.
 *
 * @notapi
 */
void usb_lld_init(void) 
{
  unsigned i;

  USBD1.state        = USB_STOP;
  USBD1.config       = NULL;
  for (i = 0; i < USB_MAX_ENDPOINTS; i++) {
    USBD1.in_params[i]  = NULL;
    USBD1.out_params[i] = NULL;
  }
  USBD1.transmitting = 0;
  USBD1.receiving    = 0;
}

/**
 * @brief   Configures and activates the USB peripheral.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
 
void usb_lld_start(USBDriver *usbp) 
{
    osalDbgAssert(usbp, "usb_lld_start()"); 

    if (usbp->state == USB_STOP) 
    {  
        _usb_reset(usbp); 

        NVIC_EnableIRQ(IRQ_USBHOST);
        NVIC_SetPriority(IRQ_USBHOST, 3);
    }
}

/**
 * @brief   USB low level reset routine.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_reset(USBDriver *usbp) 
{
    osalDbgAssert(usbp, "usb_lld_reset()");

    usbp->epc[0] = &ep0config;  
    fifo_config(2, fifo_cfg_ep0);

}

/**
 * @brief   Sets the USB address.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_set_address(USBDriver *usbp) 
{
    osalDbgAssert(usbp, "func()"); 

    HS_USB->USB_ADDR = usbp->address;
}

/**
 * @brief   Enables an endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_init_endpoint(USBDriver *usbp, usbep_t ep) 
{

    const USBEndpointConfig *epcp = usbp->epc[ep];
    uint16_t regval;

    osalDbgAssert(usbp&&epcp, "usb_lld_init_endpoint()"); 

    //enable EPx int
    hsusb_ep_select(ep);  
    if(epcp->in_cb)
    {
        if(ep)
        {
            uint16_t pktsize = epcp->in_maxsize/8;
            HS_USB->USB_TXMAXP = pktsize;
            regval = HSUSB_TXCSR_CLRDATATOG;
            if (HS_USB->USB_TXCSR&HSUSB_TXCSR_FIFONOTEMPTY)
            {
              regval |= HSUSB_TXCSR_FLUSHFIFO;
            }
            if((epcp->ep_mode & USB_EP_MODE_TYPE) == USB_EP_MODE_TYPE_ISOC)
            {   
              regval |= HSUSB_TXCSR_P_ISO;
            }

            /* set twice in case of double buffering */
            HS_USB->USB_TXCSR = regval;
            /* REVISIT may be inappropriate w/o FIFONOTEMPTY ... */
            HS_USB->USB_TXCSR = regval;
        }
    }
    if(epcp->out_cb)
    {
        if(ep)
        {
            uint16_t pktsize = epcp->out_maxsize/8;
            HS_USB->USB_RXMAXP = pktsize;
            regval = HSUSB_RXCSR_FLUSHFIFO | HSUSB_RXCSR_CLRDATATOG;
            if ((epcp->ep_mode & USB_EP_MODE_TYPE) == USB_EP_MODE_TYPE_ISOC)
            {   
              regval |= HSUSB_TXCSR_P_ISO;
            }

            /* set twice in case of double buffering */
            HS_USB->USB_RXCSR = regval;
            /* REVISIT may be inappropriate w/o FIFONOTEMPTY ... */
            HS_USB->USB_RXCSR = regval;
        }
    } 
}

/**
 * @brief   Disables all the active endpoints except the endpoint zero.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 *
 * @notapi
 */
void usb_lld_disable_endpoints(USBDriver *usbp) 
{
    osalDbgAssert(usbp, "usb_lld_disable_endpoints()");
}

/**
 * @brief   Returns the status of an OUT endpoint.
 *
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_out(usbep_t ep) 
{
    uint16_t regval = 0;
    
    hsusb_ep_select(ep);
    if(ep)
    {
        regval = HS_USB->USB_TXCSR;
        if(regval&HSUSB_TXCSR_P_SENTSTALL)
        {
            return EP_STATUS_STALLED;
        }

    }
    else
    {
        regval = HS_USB->USB_CSR0;
        if(regval&HSUSB_CSR0_P_SENTSTALL)        
        {
            return EP_STATUS_STALLED;
        }    
    }
    return EP_STATUS_ACTIVE;    
}

/**
 * @brief   Returns the status of an IN endpoint.
 *
 * @param[in] ep        endpoint number
 * @return              The endpoint status.
 * @retval EP_STATUS_DISABLED The endpoint is not active.
 * @retval EP_STATUS_STALLED  The endpoint is stalled.
 * @retval EP_STATUS_ACTIVE   The endpoint is active.
 *
 * @notapi
 */
usbepstatus_t usb_lld_get_status_in(usbep_t ep) 
{

    uint16_t regval = 0;
   
    hsusb_ep_select(ep);
    if(ep)
    {
        regval = HS_USB->USB_RXCSR;
        if(regval&HSUSB_RXCSR_P_SENTSTALL)
        {
            return EP_STATUS_STALLED;
        }

    }
    else
    {
        regval = HS_USB->USB_CSR0;
        if(regval&HSUSB_CSR0_P_SENTSTALL)        
        {
            return EP_STATUS_STALLED;
        }    
    }
    return EP_STATUS_ACTIVE;   
  
}

/**
 * @brief   Reads a setup packet from the dedicated packet buffer.
 * @details This function must be invoked in the context of the @p setup_cb
 *          callback in order to read the received setup packet.
 * @pre     In order to use this function the endpoint must have been
 *          initialized as a control endpoint.
 * @post    The endpoint is ready to accept another packet.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 * @param[out] buf      buffer where to copy the packet data
 *
 * @notapi
 */
void usb_lld_read_setup(usbep_t ep, uint8_t *buf) 
{
    uint8_t i=0;
    uint8_t *pb = (uint8_t *)(OTG_BASE+USB_EPxFIFO_OFFSET(0));
    
    (void)ep;
    for(i=0;i<8;i++)
    {
        buf[i] = *pb;
    }
}

/**
 * @brief   Prepares for a receive operation for OUT EP
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_prepare_receive(USBDriver *usbp, usbep_t ep) 
{
    osalDbgAssert(usbp, "func()"); 
    (void)ep;
}

/**
 * @brief   Prepares for a transmit operation for IN ep
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_prepare_transmit(USBDriver *usbp, usbep_t ep) 
{
    size_t n;
    USBInEndpointState *isp = usbp->epc[ep]->in_state;

    osalDbgAssert(usbp&&isp, "func()"); 

    /* Transfer initialization.*/
    //hsusb_ep_select(usbp, ep);
    n = isp->txsize-isp->txcnt;
    if (n > (size_t)usbp->epc[ep]->in_maxsize)
    {
        n = (size_t)usbp->epc[ep]->in_maxsize;
    }

    hsusb_ep_select(ep);
    if(isp->dma_mode == DMA_MODE_NONE)
    {
        uint16_t csr = HS_USB->USB_TXCSR;
        csr &= ~(HSUSB_TXCSR_DMAMODE|HSUSB_TXCSR_AUTOSET|HSUSB_TXCSR_DMAENAB);
        HS_USB->USB_TXCSR = csr;
        usb_packet_write_from_buffer(usbp, ep,
                                     &isp->txbuf[isp->txcnt], n);
        isp->txcnt+=n;
    }    

}

/**
 * @brief   Starts a receive operation on an OUT endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_out(USBDriver *usbp, usbep_t ep) 
{

    uint16_t csr;
    USBOutEndpointState *osp = usbp->epc[ep]->out_state;
    uint8_t count;

    osalDbgAssert(usbp&&osp, "func()"); 
    
    hsusb_ep_select(ep);
    if(ep==0)
    {
        uint16_t csr = HS_USB->USB_CSR0;
        if(usbp->ep0state == USB_EP0_RX)
        {
            count = HS_USB->USB_COUNT0;
           
            usb_packet_read_to_buffer(usbp,
                                      ep,
                                      &osp->rxbuf[osp->rxcnt],
                                      count);  
            osp->rxcnt += count;
            if(osp->rxsize==osp->rxcnt)
            {
                csr |= HSUSB_CSR0_P_DATAEND|HSUSB_CSR0_P_SVDRXPKTRDY;
                usbp->ep0state = USB_EP0_SENDING_STS;
            }
            else
            {
                csr |= HSUSB_CSR0_P_SVDRXPKTRDY;
            } 
        }
        else if(usbp->ep0state == USB_EP0_WAITING_STS)
        {
        }
    
        HS_USB->USB_CSR0 = csr;
    }
    else
    {        
        if(osp->dma_mode == DMA_MODE_NONE)
        {
            count = HS_USB->USB_RXCOUNT1;
            if(count)
            {
              usleep(10);
              count = (osp->rxsize > count) ? count : osp->rxsize;
              usb_packet_read_to_buffer(usbp, ep, &osp->rxbuf[osp->rxcnt], count);
              
              osp->rxcnt = count;
              osp->rxsize -= count;  

              if(HS_USB->USB_RXCOUNT1 == 0)
              {
                hsusb_ep_select(ep);
                csr = HS_USB->USB_RXCSR;
                csr &= ~HSUSB_RXCSR_RXPKTRDY;
                HS_USB->USB_RXCSR = csr;                
              }
            }  

            usbp->receiving &= ~(1<<ep);
        }           
    }
}

/**
 * @brief   Starts a transmit operation on an IN endpoint.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_start_in(USBDriver *usbp, usbep_t ep) 
{
    uint16_t csr;

    osalDbgAssert(usbp, "usb_lld_start_in()"); 
    
    hsusb_ep_select(ep);
    if(ep==0)
    {
        csr = HS_USB->USB_CSR0;
        if(usbp->ep0state == USB_EP0_TX)
        {
            if(usbp->epc[0]->in_state->txcnt==usbp->epc[0]->in_state->txsize)
            {
                csr |= HSUSB_CSR0_P_DATAEND|HSUSB_CSR0_TXPKTRDY;
                usbp->ep0state = USB_EP0_WAITING_STS;
            }
            else
            {
                csr |= HSUSB_CSR0_TXPKTRDY;
                usbp->ep0state = USB_EP0_TX;
            }    
        }
        else if(usbp->ep0state == USB_EP0_SENDING_STS)
        {
        }

        HS_USB->USB_CSR0 = csr;
        
    }
    else
    {
        USBInEndpointState *isp = usbp->epc[ep]->in_state;
        if(isp->dma_mode == DMA_MODE_NONE)
        {
            csr = HS_USB->USB_TXCSR;
            csr |= HSUSB_TXCSR_TXPKTRDY;
            HS_USB->USB_TXCSR = csr;
            
        }      
    }
}



/**
 * @brief   Brings an IN endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_stall_in(usbep_t ep) 
{
    uint16_t csr;
   
    hsusb_ep_select(ep);
    if(ep)
    {
        csr = HS_USB->USB_TXCSR;
        csr |= HSUSB_TXCSR_P_SENDSTALL;
        HS_USB->USB_TXCSR = csr;
    }
    else
    {
        csr = HS_USB->USB_CSR0;
        csr |= HSUSB_CSR0_P_SENDSTALL|HSUSB_CSR0_P_SVDRXPKTRDY;
        HS_USB->USB_CSR0 = csr;
    }
}
/**
 * @brief   Brings an OUT endpoint in the stalled state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */

void usb_lld_stall_out(usbep_t ep) 
{
  uint16_t csr;
   
  hsusb_ep_select(ep);
    if(ep)
    {
        csr = HS_USB->USB_RXCSR;
        csr |= HSUSB_RXCSR_P_SENDSTALL;
        HS_USB->USB_RXCSR = csr;
    }
    else
    {
        csr = HS_USB->USB_CSR0;
        csr |= HSUSB_CSR0_P_SENDSTALL|HSUSB_CSR0_P_SVDRXPKTRDY;
        HS_USB->USB_CSR0 = csr;
    }
}
/**
 * @brief   Brings an IN endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */

void usb_lld_clear_in(usbep_t ep) 
{

  uint16_t csr;
    
    hsusb_ep_select(ep);
    if(ep)
    {
        csr = HS_USB->USB_TXCSR;
        csr &= ~(HSUSB_TXCSR_P_SENDSTALL|HSUSB_TXCSR_P_SENTSTALL);
        HS_USB->USB_TXCSR = csr;
    }
    else
    {
        csr = HS_USB->USB_CSR0;
        csr &= ~(HSUSB_CSR0_P_SENDSTALL|HSUSB_CSR0_P_SENTSTALL);
        HS_USB->USB_CSR0 = csr;
    }
}

/**
 * @brief   Brings an OUT endpoint in the active state.
 *
 * @param[in] usbp      pointer to the @p USBDriver object
 * @param[in] ep        endpoint number
 *
 * @notapi
 */
void usb_lld_clear_out(usbep_t ep) 
{
  uint16_t csr;
  
    hsusb_ep_select(ep);
    if(ep)
    {
        csr = HS_USB->USB_RXCSR;
        csr &= ~(HSUSB_RXCSR_P_SENDSTALL|HSUSB_RXCSR_P_SENTSTALL);
        HS_USB->USB_RXCSR = csr;
    }
    else
    {
        csr = HS_USB->USB_CSR0;
        csr &= ~(HSUSB_CSR0_P_SENDSTALL|HSUSB_CSR0_P_SENTSTALL);
        HS_USB->USB_CSR0 = csr;
    }
}

void usb_lld_servedsetup(uint8_t bHasDataPhase)
{
    uint16_t csr;
    
    hsusb_ep_select(0);
    csr = HS_USB->USB_CSR0;
    csr |= HSUSB_CSR0_P_SVDRXPKTRDY;
    if(!bHasDataPhase)
    {
        csr |= HSUSB_CSR0_P_DATAEND;
    } 
    HS_USB->USB_CSR0 = csr;
}

void usb_lld_connect_bus(USBDriver *usbp)
{
    //HS_SYS->USB_CTRL
    //bit0 -- 1: test mode, 0: normal mode
    //bit4 -- 1: vbus_valid
    //bit5 -- 1: vbus_session
    //bit6 -- 1: vbus_lo
    //bit7 -- 1: reg control; 0: HW control    usbp->usb_pw_sess_mode
    //bit16 -- 1, turnoff hw power detect, 0, turn on
    /* pd_vbus_det */
    SYS->USB_CTRL &= ~(1 << 16);
        
    SYS->USB_CTRL &= ~0x01;
    SYS->USB_CTRL |= (0x01<<4)|(0x01<<5)|(0x01<<6)|(0x01<<7);    
}

void usb_lld_disconnect_bus(USBDriver *usbp)
{
    //HS_SYS->USB_CTRL
    //bit0 -- 1: test mode, 0: normal mode
    //bit4 -- 1: vbus_valid
    //bit5 -- 1: vbus_session
    //bit6 -- 1: vbus_lo
    //bit7 -- 1: reg control; 0: HW control    usbp->usb_pw_sess_mode
    //bit16 -- 1, turnoff hw power detect, 0, turn on 
    SYS->USB_CTRL &= ~0x01;
    SYS->USB_CTRL &= ~((0x01<<4)|(0x01<<5)|(0x01<<6)|(0x01<<7));  
}

void usb_ldd_clear_datatoggle(usbep_t ep, uint8_t IsInEp)
{
    if(ep)
    {
        hsusb_ep_select(ep);
        if(IsInEp)
        {
            HS_USB->USB_TXCSR |= HSUSB_TXCSR_CLRDATATOG;
        }
        else
        {
            HS_USB->USB_RXCSR |= HSUSB_RXCSR_CLRDATATOG;
        }
    }
}

uint8_t usb_lld_stall_in_sent(usbep_t ep)
{
    if(ep)
    {
        hsusb_ep_select(ep);
        if(HS_USB->USB_TXCSR&HSUSB_TXCSR_P_SENDSTALL)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        return 0;
    }
}

uint8_t usb_lld_get_rx_data_len(usbep_t ep)
{
    hsusb_ep_select(ep);
    return HS_USB->USB_RXCOUNT1;
    
}

uint8_t usb_lld_read_power_reg(void)
{
    return HS_USB->USB_POWER;
}


/***************************************************************************************
 * output
 ***************************************************************************************/
void usbStart(USBDriver *usbp, const USBConfig *config) 
{
  unsigned i;
  
  osalDbgAssert(usbp && config, "usbStart(), #1");
  usb_lld_init();
  
  osalDbgAssert((usbp->state == USB_STOP) || (usbp->state == USB_READY), "usbStart(), #2");  
  usbp->config = config;
  for (i = 0; i <= USB_MAX_ENDPOINTS; i++)
    usbp->epc[i] = NULL;
  usb_lld_start(usbp);
  usbp->state = USB_READY;
}




