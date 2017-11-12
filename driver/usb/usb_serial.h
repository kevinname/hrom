#ifndef _USBSUBDEV_SERIAL_H_
#define _USBSUBDEV_SERIAL_H_

#include <platform.h>

#define USBD1_SERIAL_BULK_OUT_EP        1 //audio out endpoint
#define USBD1_SERIAL_BULK_IN_EP         USBD1_SERIAL_BULK_OUT_EP //audio in endpoint
#define USBD1_SERIAL_INT_IN_EP          2 //audio in endpoint

#define USBD1_SERIAL_BULK_EP            1

#define USB_VID_HS              0xF012 
#define USB_PID_HS_SERIAL       0x0001

#define USB_STR_DESC_IDX_VENDOR   1
#define USB_STR_DESC_IDX_PROD     2

#define LC_STOP_1                       0
#define LC_STOP_1P5                     1
#define LC_STOP_2                       2

#define LC_PARITY_NONE                  0
#define LC_PARITY_ODD                   1
#define LC_PARITY_EVEN                  2
#define LC_PARITY_MARK                  3
#define LC_PARITY_SPACE                 4

typedef struct _IF_NUM
{
    uint8_t Ac_If_Num;
    uint8_t As_Out_IfNum;
    uint8_t As_In_IfNum;
    uint8_t Serial_IfNum;
    uint8_t Storage_If_Num;
}If_Num;

typedef struct _EP_NUM
{
    uint8_t As_Out_EpNum;
    uint8_t As_In_EpNum;
}As_Ep_Num;

typedef struct _USB_CFG_INFO
{
    char  Usb_VendorStr[64];//vendor string, should be <=31bytes
    char  Usb_ProdStr[64];//product string, should be <=31bytes
}USB_CFG_INFO;

typedef struct {
  uint8_t                       dwDTERate[4];
  uint8_t                       bCharFormat;
  uint8_t                       bParityType;
  uint8_t                       bDataBits;
} cdc_linecoding_t;


#define USB_DESC_INDEX(i) ((uint8_t)(i))
#define USB_DESC_BYTE(b) ((uint8_t)(b))
#define USB_DESC_WORD(w)                                                    \
  (uint8_t)((w) & 255),                                                     \
  (uint8_t)(((w) >> 8) & 255)
#define USB_DESC_BCD(bcd)                                                   \
  (uint8_t)((bcd) & 255),                                                   \
  (uint8_t)(((bcd) >> 8) & 255)


#define USB_DESC_DEVICE(bcdUSB, bDeviceClass, bDeviceSubClass,              \
                        bDeviceProtocol, bMaxPacketSize, idVendor,          \
                        idProduct, bcdDevice, iManufacturer,                \
                        iProduct, iSerialNumber, bNumConfigurations)        \
  USB_DESC_BYTE(18),                                                        \
  USB_DESC_BYTE(USB_DESCRIPTOR_DEVICE),                                     \
  USB_DESC_BCD(bcdUSB),                                                     \
  USB_DESC_BYTE(bDeviceClass),                                              \
  USB_DESC_BYTE(bDeviceSubClass),                                           \
  USB_DESC_BYTE(bDeviceProtocol),                                           \
  USB_DESC_BYTE(bMaxPacketSize),                                            \
  USB_DESC_WORD(idVendor),                                                  \
  USB_DESC_WORD(idProduct),                                                 \
  USB_DESC_BCD(bcdDevice),                                                  \
  USB_DESC_INDEX(iManufacturer),                                            \
  USB_DESC_INDEX(iProduct),                                                 \
  USB_DESC_INDEX(iSerialNumber),                                            \
  USB_DESC_BYTE(bNumConfigurations)

/**
 * @brief   Configuration Descriptor helper macro.
 */
#define USB_DESC_CONFIGURATION(wTotalLength, bNumInterfaces,                \
                               bConfigurationValue, iConfiguration,         \
                               bmAttributes, bMaxPower)                     \
  USB_DESC_BYTE(9),                                                         \
  USB_DESC_BYTE(USB_DESCRIPTOR_CONFIGURATION),                              \
  USB_DESC_WORD(wTotalLength),                                              \
  USB_DESC_BYTE(bNumInterfaces),                                            \
  USB_DESC_BYTE(bConfigurationValue),                                       \
  USB_DESC_INDEX(iConfiguration),                                           \
  USB_DESC_BYTE(bmAttributes),                                              \
  USB_DESC_BYTE(bMaxPower)

/**
 * @brief   Interface Descriptor helper macro.
 */
#define USB_DESC_INTERFACE(bInterfaceNumber, bAlternateSetting,             \
                           bNumEndpoints, bInterfaceClass,                  \
                           bInterfaceSubClass, bInterfaceProtocol,          \
                           iInterface)                                      \
  USB_DESC_BYTE(9),                                                         \
  USB_DESC_BYTE(USB_DESCRIPTOR_INTERFACE),                                  \
  USB_DESC_BYTE(bInterfaceNumber),                                          \
  USB_DESC_BYTE(bAlternateSetting),                                         \
  USB_DESC_BYTE(bNumEndpoints),                                             \
  USB_DESC_BYTE(bInterfaceClass),                                           \
  USB_DESC_BYTE(bInterfaceSubClass),                                        \
  USB_DESC_BYTE(bInterfaceProtocol),                                        \
  USB_DESC_INDEX(iInterface)

/**
 * @brief   Interface Association Descriptor helper macro.
 */
#define USB_DESC_INTERFACE_ASSOCIATION(bFirstInterface,                     \
                           bInterfaceCount, bFunctionClass,                 \
                           bFunctionSubClass, bFunctionProcotol,            \
                           iInterface)                                      \
  USB_DESC_BYTE(8),                                                         \
  USB_DESC_BYTE(USB_DESCRIPTOR_INTERFACE_ASSOCIATION),                      \
  USB_DESC_BYTE(bFirstInterface),                                           \
  USB_DESC_BYTE(bInterfaceCount),                                           \
  USB_DESC_BYTE(bFunctionClass),                                            \
  USB_DESC_BYTE(bFunctionSubClass),                                         \
  USB_DESC_BYTE(bFunctionProcotol),                                         \
  USB_DESC_INDEX(iInterface)

/**
 * @brief   Endpoint Descriptor helper macro.
 */
#define USB_DESC_ENDPOINT(bEndpointAddress, bmAttributes, wMaxPacketSize,   \
                          bInterval)                                        \
  USB_DESC_BYTE(7),                                                         \
  USB_DESC_BYTE(USB_DESCRIPTOR_ENDPOINT),                                   \
  USB_DESC_BYTE(bEndpointAddress),                                          \
  USB_DESC_BYTE(bmAttributes),                                              \
  USB_DESC_WORD(wMaxPacketSize),                                            \
  USB_DESC_BYTE(bInterval)
/** @} */

#define USBDEV    (&USBD1)






int32_t usbSerialOpen(void);

uint32_t usbTxData(const uint8_t *buf, uint32_t len);
uint32_t usbRxData(uint8_t *buf, uint32_t len);
void usbClrFifo(void);

void usbTxString(const char *buf);




#endif
