#include "usb_serial.h"
#include "string.h"
#include "platform.h"

static USBDriver *g_pstUsb;

static cdc_linecoding_t linecoding = {
  {0x00, 0xc2, 0x01, 0x00},             /* 115200 */
  LC_STOP_1, LC_PARITY_NONE, 8
};


//for usb to serial port device
/*===========================================================================*/
/* USB related stuff.                                                        */
/*===========================================================================*/
const If_Num dev_if_num_serial = {
  0xff, //.Ac_If_Num
  0xff, //.As_Out_IfNum
  0xff, //.As_In_IfNum 
  0x00, //.Serial_IfNum
  0xff, //.Storage_If_Num
};

//const As_Ep_Num dev_ep_num_serial = {
//    .As_Out_EpNum = 0xff,
//    .As_In_EpNum = 0xff,
//};

/*
 * USB Device Descriptor.
 */
static const uint8_t device_descriptor_data[18] = {
  USB_DESC_DEVICE       (0x0110,        /* bcdUSB (1.1).            */
                         0x02,          /* bDeviceClass (CDC).  */
                         0x00,          /* bDeviceSubClass.      */
                         0x00,          /* bDeviceProtocol.        */
                         0x40,          /* bMaxPacketSize.        */
                         USB_VID_HS,    /* idVendor (HS).         */
                         USB_PID_HS_SERIAL,    /* idProduct.     */
                         0x0200,        /* bcdDevice.                 */
                         USB_STR_DESC_IDX_VENDOR, /* iManufacturer. */
                         USB_STR_DESC_IDX_PROD,/* iProduct.*/
                         3,             /* iSerialNumber.             */
                         1)             /* bNumConfigurations.    */
};

const USBDescriptor device_descriptor_serial = {
  sizeof device_descriptor_data,
  device_descriptor_data
};

/* Configuration Descriptor tree for a CDC.*/
const uint8_t configuration_descriptor_data[67] = {
  /* Configuration Descriptor,9.*/
  USB_DESC_CONFIGURATION(67,            /* wTotalLength.                    */
                         0x02,          /* bNumInterfaces.                  */
                         0x01,          /* bConfigurationValue.             */
                         0,             /* iConfiguration.                  */
#ifdef SUPPORT_REMOTE_WAKEUP
                        0xA0,                         //bmAttributes, remote wakeup
#else
                        0x80,                         //bmAttributes
#endif
                         50),           /* bMaxPower (100mA).               */
  /* Interface Descriptor,9.*/
  USB_DESC_INTERFACE    (0x00,          /* bInterfaceNumber.                */
                         0x00,          /* bAlternateSetting.               */
                         0x01,          /* bNumEndpoints.                   */
                         0x02,          /* bInterfaceClass (Communications
                                           Interface Class, CDC section
                                           4.2).                            */
                         0x02,          /* bInterfaceSubClass (Abstract
                                         Control Model, CDC section 4.3).   */
                         0x01,          /* bInterfaceProtocol (AT commands,
                                           CDC section 4.4).                */
                         0),            /* iInterface.                      */
  /* Header Functional Descriptor (CDC section 5.2.3).*/
  USB_DESC_BYTE         (5),            /* bLength.                         */
  USB_DESC_BYTE         (0x24),         /* bDescriptorType (CS_INTERFACE).  */
  USB_DESC_BYTE         (0x00),         /* bDescriptorSubtype (Header
                                           Functional Descriptor.           */
  USB_DESC_BCD          (0x0110),       /* bcdCDC.                          */
  /* Call Management Functional Descriptor. */
  USB_DESC_BYTE         (5),            /* bFunctionLength.                 */
  USB_DESC_BYTE         (0x24),         /* bDescriptorType (CS_INTERFACE).  */
  USB_DESC_BYTE         (0x01),         /* bDescriptorSubtype (Call Management
                                           Functional Descriptor).          */
  USB_DESC_BYTE         (0x00),         /* bmCapabilities (D0+D1).          */
  USB_DESC_BYTE         (0x01),         /* bDataInterface.                  */
  /* ACM Functional Descriptor.*/
  USB_DESC_BYTE         (4),            /* bFunctionLength.                 */
  USB_DESC_BYTE         (0x24),         /* bDescriptorType (CS_INTERFACE).  */
  USB_DESC_BYTE         (0x02),         /* bDescriptorSubtype (Abstract
                                           Control Management Descriptor).  */
  USB_DESC_BYTE         (0x02),         /* bmCapabilities.                  */
  /* Union Functional Descriptor.*/
  USB_DESC_BYTE         (5),            /* bFunctionLength.                 */
  USB_DESC_BYTE         (0x24),         /* bDescriptorType (CS_INTERFACE).  */
  USB_DESC_BYTE         (0x06),         /* bDescriptorSubtype (Union
                                           Functional Descriptor).          */
  USB_DESC_BYTE         (0x00),         /* bMasterInterface (Communication
                                           Class Interface).                */
  USB_DESC_BYTE         (0x01),         /* bSlaveInterface0 (Data Class
                                           Interface).                      */
  /* Endpoint 2 Descriptor.*/
  USB_DESC_ENDPOINT     (0x02|0x80,
                         0x03,          /* bmAttributes (Interrupt).        */
                         0x0008,        /* wMaxPacketSize.                  */
                         0xFF),         /* bInterval.                       */
  /* Interface Descriptor.*/
  USB_DESC_INTERFACE    (0x01,          /* bInterfaceNumber.                */
                         0x00,          /* bAlternateSetting.               */
                         0x02,          /* bNumEndpoints.                   */
                         0x0A,          /* bInterfaceClass (Data Class
                                           Interface, CDC section 4.5).     */
                         0x00,          /* bInterfaceSubClass (CDC section
                                           4.6).                            */
                         0x00,          /* bInterfaceProtocol (CDC section
                                           4.7).                            */
                         0x00),         /* iInterface.                      */
  /* Endpoint 3 Descriptor.*/
  USB_DESC_ENDPOINT     (0x01,       /* bEndpointAddress.*/
                         0x02,          /* bmAttributes (Bulk).             */
                         0x0040,        /* wMaxPacketSize.                  */
                         0x00),         /* bInterval.                       */
  /* Endpoint 1 Descriptor.*/
  USB_DESC_ENDPOINT     (0x01|0x80,    /* bEndpointAddress.*/
                         0x02,          /* bmAttributes (Bulk).             */
                         0x0040,        /* wMaxPacketSize.                  */
                         0x00)          /* bInterval.                       */
};

/*
 * Configuration Descriptor wrapper.
 */
const USBDescriptor configuration_descriptor_serial = {
  sizeof configuration_descriptor_data,
  configuration_descriptor_data
};

/*
 * U.S. English language identifier.
 */
static const uint8_t string0[] = {
  USB_DESC_BYTE(4),                     /* bLength.                         */
  USB_DESC_BYTE(USB_DESCRIPTOR_STRING), /* bDescriptorType.                 */
  USB_DESC_WORD(0x0409)                 /* wLANGID (U.S. English).          */
};

/*
 * Vendor string.
 */
static const uint8_t string1[] = {
  USB_DESC_BYTE(20),                    /* bLength.                         */
  USB_DESC_BYTE(USB_DESCRIPTOR_STRING), /* bDescriptorType.                 */
  'H', 0, 'u', 0, 'n', 0, 't', 0, 'e', 0, 'r', 0, 'S', 0, 'u', 0,
  'n', 0
};

/*
 * Device Description string.
 */
static const uint8_t string2[] = {
  USB_DESC_BYTE(60),                    /* bLength.                         */
  USB_DESC_BYTE(USB_DESCRIPTOR_STRING), /* bDescriptorType.                 */
  'H', 0, 'u', 0, 'n', 0, 't', 0, 'e', 0, 'r', 0, 's', 0, 'u', 0,
  'n', 0, ' ', 0, 'U', 0, 'S', 0, 'B', 0, '-', 0, 'S', 0, 'e', 0,
  'r', 0, 'i', 0, 'a', 0, 'l', 0, ' ', 0, 'C', 0, 'O', 0, 'M', 0, 
  ' ', 0, 'P', 0, 'o', 0, 'r', 0, 't', 0
};

/*
 * Serial Number string.
 */
static const uint8_t string3[] = {
  USB_DESC_BYTE(8),                     /* bLength.                         */
  USB_DESC_BYTE(USB_DESCRIPTOR_STRING), /* bDescriptorType.                 */
  '0' + CH_KERNEL_MAJOR, 0,
  '0' + CH_KERNEL_MINOR, 0,
  '0' + CH_KERNEL_PATCH, 0
};

/*
 * Strings wrappers array.
 */
const USBDescriptor strings_serial[] = {
  {sizeof string0, string0},
  {sizeof string1, string1},
  {sizeof string2, string2},
  {sizeof string3, string3}
};




/**
 * @brief   IN EP1 state.
 */
static USBInEndpointState ep1instate_serial;

/**
 * @brief   OUT EP1 state.
 */
static USBOutEndpointState ep1outstate_serial;


void sduDataTransmitted(USBDriver *usbp, usbep_t ep) 
{  
  (void)usbp;
  (void)ep;
}

void sduDataReceived(USBDriver *usbp, usbep_t ep) 
{
  (void)usbp;
  (void)ep;
}

void usbInitEndpointI(USBDriver *usbp, usbep_t ep,
                      const USBEndpointConfig *epcp) 
{

  osalDbgAssert(usbp->state == USB_ACTIVE, "usbEnableEndpointI(), #1");

  /* Logically enabling the endpoint in the USBDriver structure.*/
  if (epcp->in_state != NULL)
    memset(epcp->in_state, 0, sizeof(USBInEndpointState));
  if (epcp->out_state != NULL)
    memset(epcp->out_state, 0, sizeof(USBOutEndpointState));

  usbp->epc[ep] = epcp;

  if(epcp->in_cb)
  {
    hsusb_ep_int_enable(usbp, ep, TRUE);
  }
  if(epcp->out_cb)
  {
    hsusb_ep_int_enable(usbp, ep, FALSE);
  }
  
  /* Low level endpoint activation.*/
  usb_lld_init_endpoint(usbp, ep);
}

bool_t class_req_handler_serial_if(USBDriver *usbp) {

  if ((usbp->setup[0] & USB_RTYPE_TYPE_MASK) == USB_RTYPE_TYPE_CLASS) {
    switch (usbp->setup[1]) {
    case CDC_GET_LINE_CODING:
      usbSetupTransfer(usbp, (uint8_t *)&linecoding, sizeof(linecoding), NULL);
      usb_finish_ep0setup(usbp, (usbep_t)0);
      return TRUE;
    case CDC_SET_LINE_CODING:
      usbSetupTransfer(usbp, (uint8_t *)&linecoding, sizeof(linecoding), NULL);
      usb_finish_ep0setup(usbp, 0);
      return TRUE;
    case CDC_SET_CONTROL_LINE_STATE:
      /* Nothing to do, there are no control lines.*/
      usbSetupTransfer(usbp, NULL, 0, NULL);
      usb_finish_ep0setup(usbp, 0);
      return TRUE;
    default:
      return FALSE;
    }
  }
  return FALSE;
}



/**
 * @brief   EP1 initialization structure (both IN and OUT).
 */
static const USBEndpointConfig ep1config_serial = {
  USB_EP_MODE_TYPE_BULK,
  NULL,
  sduDataTransmitted,
  sduDataReceived,
  0x0040,
  0x0040,
  &ep1instate_serial,
  &ep1outstate_serial,
  1,
  NULL,
  {
    {0xFF, 0xFF},
    {DMA_MODE_NONE, DMA_MODE_NONE},
    NULL,
    NULL,    
  },
  TRUE,
  TRUE
};


/**
 * @brief   IN EP2 state.
 */
static USBInEndpointState ep2instate;

void sduInterruptTransmitted(USBDriver *usbp, usbep_t ep) 
{
  (void)usbp;
  (void)ep;
}

/**
 * @brief   EP2 initialization structure (IN only).
 */
static const USBEndpointConfig ep2config_serial = {
  USB_EP_MODE_TYPE_INTR,
  NULL,
  sduInterruptTransmitted,
  NULL,
  0x0010,
  0x0000,
  &ep2instate,
  NULL,
  1,
  NULL,
  {
    {0xFF, 0xFF},
    {DMA_MODE_NONE, DMA_MODE_NONE},
    NULL,
    NULL,    
  },
  FALSE,
  FALSE
};

//fifo config for EPx, not including EP0
const Fifo_Cfg fifo_cfg[] = 
{   
    //EP1 out
    {
        0x01,
        0,
        64,
        64,
    },
    //EP1 IN
    {
        0x81,
        0,
        128,
        64,
    },
    //EP2 IN
    {
        0x82,
        0,
        192,
        64,
    },
};

/*
 * Serial over USB driver configuration.
 */
const SerialUSBConfig serusbcfg = {
  &USBD1,
  USBD1_SERIAL_BULK_IN_EP,
  USBD1_SERIAL_BULK_OUT_EP,
  USBD1_SERIAL_INT_IN_EP,
};


USBDescriptor g_usbstring;
USB_CFG_INFO  g_UsbCfgInfo =
{
  "Huntersun", 
  "HS6601 Serial"
};

/*
 * Handles the USB driver global events.
 */
void serial_event(USBDriver *usbp, usbevent_t event) 
{
    osalDbgAssert(usbp, "serial_event()");
  switch (event) {
  case USB_EVENT_RESET:
    fifo_config(sizeof(fifo_cfg)/sizeof(Fifo_Cfg), fifo_cfg);
    return;
  case USB_EVENT_ADDRESS:
    return;
  case USB_EVENT_CONFIGURED:
    //chSysLockFromIsr();

    /* Enables the endpoints specified into the configuration.
       Note, this callback is invoked from an ISR so I-Class functions
       must be used.*/
    usbInitEndpointI(usbp, USBD1_SERIAL_BULK_OUT_EP, &ep1config_serial);
    usbInitEndpointI(usbp, USBD1_SERIAL_INT_IN_EP, &ep2config_serial);
    
    //chSysUnlockFromIsr();
    return;
  case USB_EVENT_SUSPEND:
    return;
  case USB_EVENT_WAKEUP:
    return;
  case USB_EVENT_STALLED:
    return;
  }
  return;
}


bool_t serial_req_handler(USBDriver *usbp) 
{
    bool_t ret = FALSE;

    osalDbgAssert(usbp, "serial_req_handler()"); 
    
    if ((usbp->setup[0] & USB_RTYPE_TYPE_MASK) == USB_RTYPE_TYPE_CLASS
        &&(usbp->setup[0]&USB_RTYPE_RECIPIENT_MASK)==USB_RTYPE_RECIPIENT_INTERFACE
        &&usbp->setup[4] == dev_if_num_serial.Serial_IfNum) 
    {
        ret = class_req_handler_serial_if(usbp); 
    }
   return ret;
}


/*
 * Handles the GET_DESCRIPTOR callback. All required descriptors must be
 * handled here.
 */
static const USBDescriptor *serial_get_descriptor(USBDriver *usbp,
                                                  uint8_t dtype,
                                                  uint8_t dindex,
                                                  uint16_t lang) 
{
  osalDbgAssert(usbp, "serial_get_descriptor()"); 
  
  (void)lang;
  switch (dtype) {
  case USB_DESCRIPTOR_DEVICE:
    return &device_descriptor_serial;
        
  case USB_DESCRIPTOR_CONFIGURATION:
    return &configuration_descriptor_serial;
      
  case USB_DESCRIPTOR_STRING:
    if (dindex < 4)
      return &strings_serial[dindex];
    
    return NULL;
  }
  
  return NULL;
}

const USBConfig serialUsbCfg = {
  serial_event,
  serial_get_descriptor,
  serial_req_handler,
  NULL
};


void usbSetPad(void)
{
  GPIO_Config io_cfg1 = {GPIO_DIR_INPUT, GPIO_PULL_UP, GPIO_DRV_3, GPIO_MODE_SD};
  GPIO_Config io_cfg2 = {GPIO_DIR_INPUT, GPIO_PULL_NO, GPIO_DRV_3, GPIO_MODE_SD};

  GPIO_PinConfigure(GPIO1,  1, &io_cfg1);
  GPIO_PinConfigure(GPIO0, 14, &io_cfg2);
  GPIO_PinConfigure(GPIO1,  0, &io_cfg2);
}

bool_t usbReady(void)
{
  if(g_pstUsb)
    return (g_pstUsb->state == USB_ACTIVE);

  return FALSE;
}

int32_t usbSerialOpen(void)
{  
  volatile bool_t rdy = FALSE;
  
  CPM_CfgModuleClk(CPM_MODULE_USB, 48000000);  
  GIE_ENABLE();

  usbSetPad();

  g_pstUsb = (USBDriver *)USBDEV;
  usbDisconnectBus(g_pstUsb); 
  
  usbStart(g_pstUsb, &serialUsbCfg);
  usbConnectBus(g_pstUsb);

  rdy = usbReady();
  while(!rdy)
    rdy = usbReady();
  
  return 0;
}

uint32_t usbTxData(const uint8_t *buf, uint32_t len)
{
  int res = 1;
  int tmp, tx_len = len;
  
  if(g_pstUsb)
  {
    while(tx_len > 0)
    {
      tmp = tx_len > 0x40 ? 0x40 : tx_len;

      usbPrepareTransmit(g_pstUsb, USBD1_SERIAL_BULK_EP, buf, tmp, DMA_MODE_NONE);      
      res = usbStartTransmitI(g_pstUsb, USBD1_SERIAL_BULK_EP);

      if(res == 0)
      {
        tx_len -= tmp;
        buf += tmp;
        
      }
    }
  }

  return len;
}

uint32_t usbRxData(uint8_t *buf, uint32_t len)
{
  uint32_t cnt = 0;
  int tmout, rx_len = len;
  int tmp;

  if(len == 0)
    return 0;
  
  if(!g_pstUsb)
    return 0;

  tmout = 0x100000;
  while((rx_len > 0) && (tmout--))
  {
    tmp = rx_len > 0x40 ? 0x40 : rx_len;

    usbPrepareReceive(g_pstUsb, USBD1_SERIAL_BULK_EP, buf, tmp, DMA_MODE_NONE);    
    cnt = usbStartReceiveI(g_pstUsb, USBD1_SERIAL_BULK_EP);

    if(cnt)
    {
      rx_len -= cnt;
      buf += cnt;
    }
  }  
  
  return (len - rx_len);
}

void usbClrFifo(void)
{
  int tmout;
  uint8_t buf[0x40];

  tmout = 0x12;
  while(tmout--)
  {    
    usbPrepareReceive(g_pstUsb, USBD1_SERIAL_BULK_EP, buf, 0x40, DMA_MODE_NONE);
    usbStartReceiveI(g_pstUsb, USBD1_SERIAL_BULK_EP);
  }  
}

void usbTxString(const char *buf)
{
  usbTxData((const uint8_t *)buf, strlen(buf));
}

