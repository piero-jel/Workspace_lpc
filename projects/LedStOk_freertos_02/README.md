# workspace
- En caso de errores, Debemos incluir el Archivo "chip.h" (#include "chip.h"), en el archivo "clock_17xx_40xx.h"


## Supported targets:
- LPC11U68
- LPC1769 {lpc175x_6x}
- LPC4337 (M4 and M0 cores)
- LPC54102 (M4 and M0+ cores)

## Supported boards:
- LPCXpresso with LPC1769


## Supported toolchains:
- gcc-arm-none-eabi


## Modules:
- BlinkyLed
- DriverEEPROM24LC64
- DriverWH1602C_2C4D
- DriverLed
- SysTickTimer
- FSM_Pulsador

## Brief Modules:
- BlinkyLed: Parpadeo de un Led con la finalidad de detectar si el Sistema queda detenido en algun punto de Codigo.
	
- DriverEEPROM24LC64: Contiene las APIs para escritura/lectura de Datos/Bloques de datos Sobre una Memoria EEPROM conectada a un Bus I2C, cualquiera de los tres que posee esta familia de Micro Controladores [I2C0/1/2]

- DriverWH1602C_2C4D: Controlador para Modulo LCD Modelo WH1602C.

- DriverLed: son las APIs para controlar led (parpadeo), los cuales se utilizan como testigos de diferentes puntos de codigo. En este caso para interatuar y testear las APIs de MEmoria EEPROM.

- SysTick: Modulo que contiene las Apis para la configuracion, como asi tambien de ISR del SysTick Timer.
 Tambien Encontramos las Apis para leer el valor del Acumulador y la de Consulta de tiempo trasncurrido

- FSM_Pulsador: son las Apis Generadas por la codificacion de la maquina de estado, para manipulacion de Pulsadores.

## Usage



## Topologia de conexion:
- Topologia, filtrado de ruido por Hardware.
 
                   +3v3
                    (+)
                     |
                     |
                    .-.
                    | |
                    | |10k
                    '-'
                     |
                     |                       ___       |
                     o---------o------------|___|------|<> Px.n
                     |         |              R        |
                     |         o  |          1k
             100 nF-----         <|=| SW2/3
                   -----       o  |
                     |         |
                     |         |
                    ===       ===
                    GND       GND



## Autores:
- Luccioni Jesus Emanuel
