DRVPATH         = $(PROJ_PATH)/driver

DRVSRC := \
	${DRVPATH}/cpm.c \
	${DRVPATH}/gpio.c \
	${DRVPATH}/sflash.c \
	${DRVPATH}/sdc.c \
	${DRVPATH}/usb/usb.c \
	${DRVPATH}/usb/usb_serial.c \
	${DRVPATH}/uart.c 

DRVINC = \
    -I$(DRVPATH) \
    -I$(DRVPATH)/usb



