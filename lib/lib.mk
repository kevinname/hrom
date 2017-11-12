LIBPATH         = $(PROJ_PATH)/lib

UPGD_PATH       = $(LIBPATH)/upgrade
COMM_PATH       = $(LIBPATH)/comm
INCL_PATH       = $(LIBPATH)/include
DES_PATH        = $(LIBPATH)/des
FATFS_PATH      = $(LIBPATH)/fatfs

UPGD_SRC := \
	${UPGD_PATH}/upgrade.c \
	${UPGD_PATH}/upgrade_sd.c \
	${UPGD_PATH}/upgrade_usb.c \
	${UPGD_PATH}/upgrade_led.c
	
COMM_SRC := \
	${COMM_PATH}/comm_hal.c \
	${COMM_PATH}/comm_mem.c \
	${COMM_PATH}/comm_protocol.c 
	
FATFS_SRC := \
    ${FATFS_PATH}/src/fatfs_diskio.c \
    ${FATFS_PATH}/src/fatfs_syscall.c \
    ${FATFS_PATH}/src/ff.c \
    ${FATFS_PATH}/src/option/unicode.c \
    ${FATFS_PATH}/fatfs.c

DES_SRC := ${DES_PATH}/des.c

LIBSRC = $(UPGD_SRC) \
         $(COMM_SRC) \
         $(DES_SRC) \
         $(FATFS_SRC) 

LIBINC = -I$(INCL_PATH) \
         -I$(UPGD_PATH) \
         -I$(COMM_PATH) \
         -I$(DES_PATH) \
         -I$(FATFS_PATH) \
         -I$(FATFS_PATH)/src



