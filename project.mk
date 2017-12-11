##################################################
## current project
##################################################
#
## asignamos el proyecto a compilar
##
#PROJECT = projects/LedStOk_freertos_01
#PROJECT = projects/LedStOk_freertos_02
PROJECT = projects/LedStOk_freertos_03

#
## asignamos el direcotorio de generacion de 
#	codigo automatico 
##
#GEN_DIRECTORY =GenWebserver
#GEN_DIRECTORY =GenWebserver_01

##################################################
## -- current target (only for MCU) 
##################################################
## Definimos el conjunto de librerias 
MODULE = lpc175x_6x
## Definimos el Dispositivo, el dispositivo a utilizar
TARGET = lpc1769



## En caso de utilizar libreias estaticas externas
LIST_STATIC_LIBRARY := base chip driver driverRTOS freertos port




## y la ruta de Header File

## en este caso el nombre de la libreria coincide 
#con el directorio contenedor




################################################################################
#                            DO NOT EDIT THIS FILE!                            #
#           Copy project.mk.template to project.mk and use project.mk.         #
################################################################################
##
##
# make -> compilar
# make clean -> para limpiar, antes de cambiar un proyecto a compilar
# make run -> para Ejecutar el programa compilado	
#

##
##
##################################################
## -- Example, in case of test example_xx
##################################################
#PROJECT = examples/GPIO/LedBlinky
#
#PROJECT = examples/example_03
#PROJECT = examples/example_04
#PROJECT = examples/example_05
#PROJECT = examples/example_06
#PROJECT = examples/example_07
#PROJECT = examples/example_08
#PROJECT = examples/example_09
#PROJECT = examples/example_10
##
##

##
##

##
##
##################################################
## -- size format current file *.axf  
##################################################
##
# formato Berkeley, formato por defecto 
SIZE_FORMAT = Berkeley
#CMD_SIZE_FORMAT	= -B
##
# Formato con conversion del Sistema, full
#SIZE_FORMAT = SysV
CMD_SIZE_FORMAT	= -B
##
##
##################################################
## -- Enable/Disable Clean Doc, whit clean
##################################################
##
##
#CLEAN_DOC_HTML = YES ## enable clean doc directory
CLEAN_DOC_HTML = NO ## disable clean doc directory
#CLEAN_DOC_MAN = YES ## enable clean doc directory
CLEAN_DOC_MAN = NO ## disable clean doc directory

#GEN_DOC = YES
GEN_DOC = NO
##
##
##
##################################################
## -- extra
##################################################
##
## Definimos el formato de visualizacion del archivo *.afx
##
## Tenemos diversos dispositivos
## Que utilizan las mismas Librerias
##
##################################################
## -- NOTE 
##################################################
#@note: en caso del msj -> gcc-arm-none-eabi no instalado, en este mismo archivo
# nos paramos en Project-> Properties, seleccionamos [tool chain editor]
# tildamos la Opcion {Display complatible tool chain only} y seleccionamos
# la Correspondiente a NXP [only for MCU].
#leyend_size = "\n\t .text:  program code" \
			"\n\t .rodata: read-only data" \
			"\n\t .data read-write initialized data" \
			"\n\t .bss read-write without explicit initialized, zero initialized data"