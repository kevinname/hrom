
CROSS_COMPILE ?= nds32le-elf-

CC	:= $(CROSS_COMPILE)gcc
OBJCOPY	:= $(CROSS_COMPILE)objcopy
AR	:= $(CROSS_COMPILE)ar
AS	:= $(CROSS_COMPILE)as
OBJDUMP := $(CROSS_COMPILE)objdump
NM := $(CROSS_COMPILE)nm -n -l -C
RD := $(CROSS_COMPILE)readelf -a

DEBUG ?= 1
NOPLL ?= 0
TARGET := bootrom

ifeq ($(DEBUG),1)
OPTIM	:= -O0 -g3
else
OPTIM	:= -Os2 -g3
endif

RM := rm -rf

PROJ_PATH       := .
include $(PROJ_PATH)/driver/drv.mk
include $(PROJ_PATH)/lib/lib.mk
include $(PROJ_PATH)/start/cpu.mk

INCLUDE_PATH := \
	${LIBINC} \
	$(DRVINC) \
	$(CPUINC) 

LDSCRIPT        := $(CPUPATH)/ld/hs6601.ld

#Check GCC version
VERSION := $(shell $(CC) --version | grep ^$(CC) | sed 's/^.* //g')
GCC_VERSION := $(shell echo $(VERSION)| sed -e 's/\.\([0-9][0-9]\)/\1/g' -e 's/\.\([0-9]\)/0\1/g' -e 's/^[0-9]\{3,4\}$$/&00/' )

# GCC version before 4.8.2 doesn't support -mcmodel
ifneq ($(shell expr `echo $(GCC_VERSION)` \< 40802 ),1)
	CMODEL := -mcmodel=large
endif

CFLAGS := \
	$(INCLUDE_PATH) \
	-Wall \
	$(LIB_SDL_DEF) \
	$(OS_DEF) \
	-fno-builtin -fomit-frame-pointer -funroll-loops -nostdlib \
	-fno-strict-aliasing -ffunction-sections \
	$(CMODEL) \
	$(OPTIM) \
	$(OSC_DEF) \
	$(OSC_DEBUG_DEF) \
	$(CFLAGS_EXT)

LD_FLAGS	:= $(OPTIM) -fno-builtin -nostartfiles -static -Wl,--gc-sections $(CMODEL)

AFLAGS		:= -fno-builtin

# For awareness debugging, add the FreeRTOS version symbol for auto detecting.
# Remove the '--gcc-sections' option to keep the symbol to be GLOBAL binded.
ifeq ($(DEBUG),1)
#LD_FLAGS	:= $(subst --gc-sections,--undefine=__rtos_signature_freertos_v8_0_0,$(LD_FLAGS))
endif

# Add `-fno-delete-null-pointer-checks` flag if the compiler supports it.
# GCC assumes that programs cannot safely dereference null pointers, 
# and that no code or data element resides there.
# However, 0x0 is the vector table memory location, so the test must not be removed.
ifeq ($(shell $(CC) -fno-delete-null-pointer-checks -E - 2>/dev/null >/dev/null </dev/null ; echo $$?),0)
CFLAGS += -fno-delete-null-pointer-checks
LD_FLAGS += -fno-delete-null-pointer-checks
endif


CFLAGS += -mno-ifc -DCONFIG_NO_NDS32_EXT_IFC
LD_FLAGS += -Wl,--mno-ifc

CFLAGS += -mno-ex9 -DCONFIG_NO_NDS32_EXT_EX9
LD_FLAGS += -Wl,--mno-ex9



# HWZOL check
ifeq ($(HWZOL),1)
ifeq ($(shell echo | $(CC) -E -dM -mext-zol - | grep '\<__NDS32_EXT_ZOL__\>' > /dev/null && echo "ZOL"), ZOL)
CFLAGS += -DCONFIG_HWZOL
LD_FLAGS += -mext-zol
else
$(error this toolchain do not support ZOL extension)
endif
endif

#################################################################
#								#
# Source code to each application				#
#								#
#################################################################
C_SRCS := \
	${LIBSRC} \
	${DRVSRC} \
	$(CPUPATH)/cpu_def/cache.c \
	${PROJ_PATH}/main.c

AS_SRCS	:= ${CPUSRC}

# % can match to all the strings
C_OBJS := $(patsubst %.S,%.o,$(patsubst %.c,%.o,${C_SRCS}))
AS_OBJS := $(patsubst %.S,%.o,${AS_SRCS})

OBJS = ${AS_OBJS} ${C_OBJS}

.PHONY: all clean distclean

all: ${TARGET}.elf ${TARGET}.bin
	if test ! -d ./build; then \
		mkdir ./build; \
	fi
	mv ${TARGET}.elf ${TARGET}.bin ./build
	$(OBJDUMP) -D ./build/${TARGET}.elf >./build/${TARGET}.s
	$(OBJDUMP) -x --syms ./build/${TARGET}.elf >./build/${TARGET}.dump
	$(OBJCOPY) ./build/${TARGET}.elf -O ihex ./build/${TARGET}.hex
	$(NM)  "./build/${TARGET}.elf" > ./build/symbol.txt
	$(RD)  "./build/${TARGET}.elf" > ./build/readelf.txt
	

clean:
	$(RM) $(OBJS)
	$(RM) ./build/*.*
	$(RM) build/


.SUFFIXES : .o .c .S

.c.o :
	$(CC) -c $(CFLAGS) $< -o $@
.S.o :
	$(CC) -c $(CFLAGS) $(AFLAGS) $< -o $@

${TARGET}.elf: ${OBJS}
	$(CC) -T$(LDSCRIPT) ${C_OBJS} ${AS_OBJS} $(LD_FLAGS) $(LFLAGS_EXT) -o $@

${TARGET}.bin: ${TARGET}.elf
	$(OBJCOPY) ${TARGET}.elf -O binary ${TARGET}.bin	

