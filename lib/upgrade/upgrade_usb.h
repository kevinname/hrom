#ifndef __UPGRADE_USB_H__
#define __UPGRADE_USB_H__

#define PROTOCOL_SOH            0x01    
#define PROTOCOL_EOT            0x04
#define PROTOCOL_ACK            0x06
#define PROTOCOL_NAK            0x15
#define PROTOCOL_CAN            0x18

#define PROTOCOL_PACKDATA_LEN   1024
#define PROTOCOL_PACKAGE_LEN    (PROTOCOL_PACKDATA_LEN + 4)

#define PROTOCOL_RESEND_CNT     (60 * 3)
#define PROTOCOL_RX_EER_CNT     (255)

typedef enum
{
  PROTOCOL_RES_IDLE             ,
  PROTOCOL_RES_START            ,
  PROTOCOL_RES_CANCEL           , /*!< transmit terminate                                      */
  PROTOCOL_RES_NEXT             , /*!< receive a valid package, ready to receive next          */
  PROTOCOL_RES_REPEAT           , /*!< some error have happened, need to repreat transmit      */
  PROTOCOL_RES_END
}hs_protocolres_t;

typedef enum
{
	PROTOCOL_NEW_START            ,
	PROTOCOL_CONTINUE             ,
}hs_protmode_t;


#ifdef __cplusplus
extern "C" {
#endif

int hs_upgrade_usbProc(void);
int32_t hs_upgrade_usbDownload(uint8_t *pu8CmdDataBuf, uint8_t u8CmdDataLen, 
                              uint8_t *pu8ResDataBuf, uint8_t u8ResDataLen);

#ifdef __cplusplus
}
#endif

#endif
