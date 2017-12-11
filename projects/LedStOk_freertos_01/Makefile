# application name
PROJECT_NAME := $(notdir $(PROJECT))

# Modules needed by the application
PROJECT_MODULES := modules/$(MODULE)/freertos \
                   modules/$(MODULE)/base \
                   modules/$(MODULE)/chip \
                   modules/$(MODULE)/port \
                   modules/$(MODULE)/driverRTOS \
                   modules/$(MODULE)/driver
                   
# source files folder
PROJECT_SRC_FOLDERS := $(PROJECT)/src

# header files folder
PROJECT_INC_FOLDERS := $(PROJECT)/inc

# source files
PROJECT_C_FILES := $(wildcard $(PROJECT)/src/*.c)
PROJECT_ASM_FILES := $(wildcard $(PROJECT)/src/*.S)