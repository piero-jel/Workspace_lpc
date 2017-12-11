# Autor: Lucioni Jesus Emanuel
##
## Makefile directorio "workspace"
## 
-include project.mk
##
## definimos la ruta de la libreria 
STATIC_LIBRARY = libs/$(TARGET)
##
## Definimos de donde toma
HEADER_LIBRARY = $(STATIC_LIBRARY)/inc

##
## Incluimos el Mekafile del Proyecto
##
INCLUDES = $(addprefix -I,$(PROJECT)/inc) \
			$(addprefix -I,$(HEADER_LIBRARY)) 
##
## Definimos las Rutas de loa Archivos necesarios
##
SRC_PATH := $(PROJECT)/src
INC_PATH := $(PROJECT)/inc libs/inc
OBJ_PATH := obj
OUT_PATH := out

vpath %.o $(OBJ_PATH)
vpath %.c $(SRC_PATH)
vpath %.S $(SRC_PATH) 
vpath %.a $(STATIC_LIBRARY)
##
# source_file := $(wildcard *.c)
source_file_c := $(patsubst $(SRC_PATH)/%.c,%.c,$(wildcard $(SRC_PATH)/*.c))
source_file_asm := $(patsubst $(SRC_PATH)/%.S,%.S,$(wildcard $(SRC_PATH)/*.S))
## Incluimos los Archivos de configuracion para cada Target disponible
include etc/target/$(TARGET).mk
##
##
##
##
##SYMBOLS += -D$(TARGET) -D$(BOARD)
#SYMBOLS += -D$(MODULE) -D$(TARGET)
SYMBOLS += -D$(TARGET) -D$(MODULE)  
#
#
#
#
PROJECT_OBJ_FILES := $(addprefix $(OBJ_PATH)/,$(notdir $(source_file_c:.c=.o)))
PROJECT_OBJ_FILES += $(addprefix $(OBJ_PATH)/,$(notdir $(source_file_asm:.S=.o)))
PROJECT_OBJS := $(notdir $(PROJECT_OBJ_FILES))
PROJECT_NAME := $(notdir $(PROJECT))
##enumeramos la librerias estaticas que tenemos
enumSTATIC_LIBRARY := $(patsubst $(STATIC_LIBRARY)/%.a,%.a,$(wildcard $(STATIC_LIBRARY)/*.a))
enumHEADER_LIBRARY := $(patsubst $(HEADER_LIBRARY)/%.h,%.h,$(wildcard $(HEADER_LIBRARY)/*.h))
#
#
#
#
all : $(PROJECT_NAME)
#
#
%.o: %.c
	@echo "\n\t*** Begin, compiling C file $< ***\n"
	@$(CROSS_PREFIX)gcc $(SYMBOLS) $(CFLAGS) $(INCLUDES) -c $< -o $(OBJ_PATH)/$@
	@$(CROSS_PREFIX)gcc $(SYMBOLS) $(CFLAGS) $(INCLUDES) -c $< -MM > $(OBJ_PATH)/$(@:.o=.d)
	@echo "\n\t*** End , compiling C file $< ***\n"
#
#
#
%.o: %.S
	@echo "\n\t*** compiling asm file $< ***"
	@$(CROSS_PREFIX)gcc $(SYMBOLS) $(CFLAGS) $(INCLUDES) -c $< -o $(OBJ_PATH)/$@
	@$(CROSS_PREFIX)gcc $(SYMBOLS) $(CFLAGS) $(INCLUDES) -c $< -MM > $(OBJ_PATH)/$(@:.o=.d)
	@echo "\t*** End , compiling asm file $< ***\n"
#
#
#
# -include $(wildcard $(OBJ_PATH)/*.d) # no estamso seguro de que sea necesario
#
#
#
##########################################################################################################
# Editamos el archivo para obtener siempre el mismo nombre de salida
# de esta forma siempre ejecutamos el mismo archivo
# y no debemos cambiar desde el IDE que archivo deseamos ejecutar
##########################################################################################################
# $(PROJECT_NAME): $(foreach MOD,$(notdir $(PROJECT_MODULES)),lib$(MOD).a) $(PROJECT_OBJS)
 $(PROJECT_NAME): $(PROJECT_OBJS) 
	@echo "*** linking project $@ ***"
	@$(CROSS_PREFIX)gcc $(LFLAGS) $(LD_FILE) -o $(OUT_PATH)/$(PROJECT_NAME).axf $(PROJECT_OBJ_FILES) $(SLAVE_OBJ_FILE) -L$(STATIC_LIBRARY) \
	$(addprefix -l, $(LIST_STATIC_LIBRARY))
#	@$(CROSS_PREFIX)size --format=$(SIZE_FORMAT) $(OUT_PATH)/$(PROJECT_NAME).axf
#	@$(CROSS_PREFIX)size $(CMD_SIZE_FORMAT) $(OUT_PATH)/$(PROJECT_NAME).axf		
	@$(CROSS_PREFIX)objcopy -v -O binary $(OUT_PATH)/$(PROJECT_NAME).axf $(OUT_PATH)/$(PROJECT_NAME).bin
	@$(CROSS_PREFIX)objcopy -O ihex $(OUT_PATH)/$(PROJECT_NAME).axf $(OUT_PATH)/$(PROJECT_NAME).hex	
#	@echo "\n\n"
#	@$(CROSS_PREFIX)size --format=$(SIZE_FORMAT) $(OUT_PATH)/$(PROJECT_NAME).axf	
	@echo "\n"
	@$(CROSS_PREFIX)size $(CMD_SIZE_FORMAT) $(OUT_PATH)/$(PROJECT_NAME).axf	
	@echo "*** end-build ***"
	@$(POST_BUILD_CMD)
	@echo $(leyend_size)
	$(if $(filter $(GEN_DOC),YES),doxygen $(PROJECT)/$(PROJECT_NAME).doxyfile,)
##########################################################################################################
# 
# 
##########################################################################################################


##########################################################################################################

#
#
#
##########################################################################################################
# 
# 
##########################################################################################################
#
#
#
##########################################################################################################
# 
# Llamado a la generacion de docuentacion, debe estar instalado el paquete
# doxygen
#
##########################################################################################################
doc:
	doxygen $(PROJECT)/$(PROJECT_NAME).doxyfile

#	doxygen doxyfile
##########################################################################################################
# 
# 
##########################################################################################################
#
#
#
##########################################################################################################
# 
# Limpieza de Directorios, eliminamos los archivos gnerados para la compilacion de codigo
#
##########################################################################################################
clean :
	rm -f $(OBJ_PATH)/*.*
	rm -f $(OUT_PATH)/*.*
	rm -f *.launch
	$(if $(filter $(CLEAN_DOC_HTML),YES), rm -r $(PROJECT)/doc/html/,)
	$(if $(filter $(CLEAN_DOC_MAN),YES), rm -r $(PROJECT)/doc/man/,)
# 	
# For Clean document in html folder
clean_doc :
	rm -r $(PROJECT)/doc/

##########################################################################################################
# 
# 
##########################################################################################################
#
#
# 
##########################################################################################################
#
#
#
##########################################################################################################
# 
# Limpiamos todos los Archivos de compilacion, incluyendo las librerias Estaticas
#  y la docuemntacion generada 
#
##########################################################################################################	
clean_all:
	@make TARGET=lpc175x_6x clean --no-print-directory
#
#
##########################################################################################################
# 
# 
##########################################################################################################
#
#
#
download: 
	@echo "\n\t Downloading  $(PROJECT_NAME).bin to $(TARGET), through LPC21ISP"
	@echo "wait..."
	@lpc21isp -bin ./$(OUT_PATH)/$(PROJECT_NAME).bin /dev/ttyUSB0 115200 12000	
#	@echo "Download done."
#
#
#
erase:
	@echo no definido aun 
#
#
##########################################################################################################
# 
# 
##########################################################################################################
#
#
#
##########################################################################################################
# 
# Imprimimos toda la informacion disponible sobre el proyecto 
#
##########################################################################################################	
info:
	@echo "\n"
	@echo "\t" PROJECT_NAME: $(PROJECT_NAME) "\n"
	@echo "\t" TARGET: $(TARGET) "\n"
	@echo "\t" PROJECT_MODULES: $(PROJECT_MODULES) "\n"
	@echo "\t" OBJS: $(PROJECT_OBJS) "\n"
	@echo "\t" INCLUDES: $(INCLUDES) "\n"
	@echo "\t" PROJECT_SRC_FOLDERS: $(PROJECT_SRC_FOLDERS) "\n"
	@echo "\t Variables defined in to "$(TARGET)".mk\n"
	@echo "\t" TARGET_NAME: $(TARGET_NAME) "\n"
	@echo "\t" CROSS_PREFIX: $(CROSS_PREFIX) "\n"
	@echo "\t" CFLAGS: $(CFLAGS) "\n"
	@echo "\t" LFLAGS: $(LFLAGS) "\n"
	@echo "\t" path to ld: $(LD_FILE) "\n"
# CROSS_PREFIX
# Listado de Herramientas a utilizar:	
help:	
	@echo "\n"
	@echo "\t" make : construye el proyecto "\n"
	@echo "\t" make all : construye todo el proyecto "\n"
	@echo "\t" make clean : Limpa el proyecto actual "\n"
	@echo "\t" make clean_all : Limpia todo todo el proyecto y las librerias"\n"
	@echo "\t" make doc : genera la documentacion mediante doxigen tomando el archivo $(PROJECT_NAME).doxyfile"\n"
	@echo "\t" make clean_doc : Limpa el directorio de documentacion actual"\n"
	@echo "\t" make run : aun no definida, tentativa corre el proyecto. No aplicable en embebidos"\n"
	@echo "\t" meke info : Imprime informacion sobre el proyecto actual "\n"
	@echo "\t" make help : Imprime esta informacion "\n"
	@echo "\t" make download : Descarga el archivo Binario, Creado para el proyecto en curso, "\n\t"\
	al Dispositivo. La Herramienta utilizada es LPC21ISP, configurado con una velocidad de "\n\t" \
	115200 y utilizando ttyUSB0. De esta Forma remplazamos el uso de OpenOCD "\n"
	@echo "\t" meke erase : Borra la Memoria del Dispositivo y dependiendo de la herramienta a "\n\t"\
	implementar, descargara un archivo binario sobre la memoria del dispositvo.
	@echo "\t" Fin de la ayuda "\n"
	
# Listado de Herramientas a utilizar:	
#@make leyend_size
leyend_size:	
	@echo "\n"
	@echo "\t" .text:  program code 
	@echo "\t" .rodata: read-only data
	@echo "\t" .data read-write initialized data
	@echo "\t" .bss read-write zero initialized data	
##########################################################################################################
# 
# 
##########################################################################################################
#
#
#
##########################################################################################################
# 
# Limpiamos todos los Archivos de compilacion, incluyendo las librerias Estaticas
#  y la docuemntacion generada 
#
##########################################################################################################
#
#
#
#ctags:
#	@echo "Generating tags file."
#	ctags -R .
###	
update :
	@echo "\n***** descomprimiendo librerias *****"
	tar -xf libs/$(TARGET)/$(MODULE).tar 	
