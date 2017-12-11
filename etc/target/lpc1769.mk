################################################################################
#                Target Makefile for LPC1769 microcontroller                   #
################################################################################

# Target name
TARGET_NAME := lpc1769
# Default cross-toolchain
CROSS_PREFIX ?= arm-none-eabi-

# Defined symbols
SYMBOLS := -DDEBUG -DCORE_M3 -D__USE_CMSIS -DCHIP_LPC175X_6X -D__CODE_RED
# Compilation flags
CFLAGS := -Wall -ggdb3 -mcpu=cortex-m3 -mthumb -fdata-sections -ffunction-sections -c
# Linking flags
LFLAGS := -nostdlib -fno-builtin -mcpu=cortex-m3 -mthumb -Xlinker \
			  -Map=$(OUT_PATH)/$(PROJECT_NAME).map -Wl,--gc-sections
# Linker scripts
LD_FILE := -Tetc/ld/lpc1769_lib.ld -Tetc/ld/lpc1769_mem.ld -Tetc/ld/lpc1769.ld