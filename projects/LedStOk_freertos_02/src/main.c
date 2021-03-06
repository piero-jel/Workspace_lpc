/** \addtogroup main_c main module
 ** @{ */

/********************************[Header File]*************************************//**
 * @file    main.c
 * @brief   Test de la Libreria -> LedStatus, la cual la configuracion/seleccion
 * de led puede ser dinamica (Seleccionar el led en tiempo de ejecucion) o estatica
 * (no se puede variar en tiempo de ejecucion el puerto y el pin).
 * El estado (el numero de blink) es idependiente de esta ultima configuracion
 *
 * @version v1.01
 * @date Dec 9, 2016, compilation
 * @note none
 * @par Luccioni, Jesus Emanuel
 *************************************************************************************/
/** @} doxygen end group definition */

//
#define __main_c__
//
//
/* **********************************************************************************************
 *
 * ==========================[ Begin Include Header File Section ]=========================
 *
 ********************************************************************************************** */
/* -- Archivo de cabecera para las colas -- */
#include <FreeRTOSConfig.h>
#include <FreeRTOS.h>
#include <task.h>
#include <portRTOS.h>
//#include <semphr.h>
//#include <queue.h>

// -- Archivo inc que contiene la declaracion de la variables Globales

#include <LedStatus.h> /* Incluimos el modulo LedStatusOk*/
#include <main.h>
/* **********************************************************************************************
 *
 * ==========================[ End Include Header File Section ]===========================
 *
 * ******************************************************************************************** **/
//
//
//
/* **********************************************************************************************
 *
 * ==========================[ Begin Macros Label declaration ]=========================
 *
 ********************************************************************************************** */
//
/* -- Definimos los tamaños de las pilas por defecto */
#define STACKsIZE_LEDsToK		(configMINIMAL_STACK_SIZE)

#if(LedStatus_ENABLE_TASK_TEST==0)
#define TIME_TEST 5000	/**<@brief Time for task Test */
#endif
/* **********************************************************************************************
 *
 * ==========================[ End Macros Label declaration ]===========================
 *
 * ******************************************************************************************** **/
//
//
//
/* **********************************************************************************************
 *
 * ==========================[ Begin Global Variables declaration ]=========================
 *
 ********************************************************************************************** */
//
/*-- definimos la estrucutura para el modulo Led de estado */
#if(LedStatus_SHOULD_BE_DINAMIC==1)/*Siempre y cuando el modulo sea configurado
como tal, internamente*/
//sType_StatusLed ledP0_22 ={
//		0/* Seleccionamos el Puerto Cero*/
//		,22/* Seleccionamos el Pin 22*/
//		,STATUS_LED_3 /* Definimos el estado con el cual inicializamos*/};
sT_StatusLed ledRed ={ /* p0.22*/
		0/* select Port */
		,22/*select Pin */},\
			 ledBlue ={ /* p3.26*/
				3/* select port */
				,26/* select Pin */},\
			 ledGreen ={ /* p3.25*/
				3/* select port */
				,25/* select Pin */};

#endif

/* **********************************************************************************************
 *
 * ==========================[ End Global Variables declaration ]===========================
 *
 * ******************************************************************************************** **/
//
//
//
/* **********************************************************************************************
 *
 * ==========================[ Begin Main Function Definition ]=========================
 *
 ********************************************************************************************** */
int main( void )
{
	// todo: add las Apis de iniHardware(), iniSoftware()
	 // -- Inicializamos el Hardware que utilizaremos
		INIT_HARDWARE();
	 // -- Inicializaos el software creacion de tareas y asignacion de variables
		INIT_SOFTWARE();
	// -- Inicializamos el SCHEDULER
		vTaskStartScheduler();
	// Bucle Infinito
		while(1)
		{

		}
	    return -1 ;
}


/* **********************************************************************************************
 *
 * ==========================[ End Main Function Definition ]===========================
 *
 * ******************************************************************************************** **/
//
//
//
/* **********************************************************************************************
 *
 * ==========================[ Begin Local Module function Definition ]=========================
 *
 ********************************************************************************************** */
//
//
/*********************************************************************
 * @brief	Inicializacion de Hardware a utilizar
 * @param none
 * @return none
 * @note:
 * Realizar el listado del Hardware qe inicialzamos
 * +
 *********************************************************************/
void initHardware(void)
{
	// Inicializamos el clock for el core
	SystemCoreClockUpdate();
	// fixme: Initialization GPIO/IOCON Power and clock
	// -- Inicializamos el Hardware
#if(LedStatus_SHOULD_BE_DINAMIC==1)
	LedStatus_INIT(ledRed,STATUS_LED_4);
	LedStatus_INIT(ledBlue,STATUS_LED_3);
	LedStatus_INIT(ledGreen,STATUS_LED_1);
#else
	LedStatus_INIT(STATUS_LED_2);
#endif
	// -- Inicializacion del WDT
	//DriverWwdt_Init();
}
//
//
/*********************************************************************
 * @brief	Inicializacion de Software, configuracion de Registros
 * para Funciones y Creacion de Tareas. Inicializacion de Registros
 * para los modulos.
 * @return none
 * @note
 *
 *********************************************************************/
void initSoftware(void)
{
#if(LedStatus_SHOULD_BE_DINAMIC==1)
	LedStatus_CreateContext(STACKsIZE_LEDsToK,ledRed,(tskIDLE_PRIORITY+1),NULL);
	LedStatus_CreateContext(STACKsIZE_LEDsToK,ledBlue,(tskIDLE_PRIORITY+1),NULL);
	LedStatus_CreateContext(STACKsIZE_LEDsToK,ledGreen,(tskIDLE_PRIORITY+1),NULL);
	/*-- creamos la terea de TEST*/
	xTaskCreate( \
		(pdTASK_CODE) vTask_Test,	/*-- Puntero a la Funcion*/\
		(signed char*) "vTask_Test",/*-- Nombre asignado p/Debbug, "Marca de Agua" hasta 16-Char*/\
		configMINIMAL_STACK_SIZE,	/*-- Longitud de la Pila en Word*/\
		NULL ,/*(void*) &ledGreen,*//*-- Referencia al Argumento de la Tarea, en este caso ninguna */\
		(tskIDLE_PRIORITY+1),				/*-- Nivel de Prioridad para la Tarea*/\
		NULL /*-- Identificador de la Tarea Creada*/\
		);
#else//#if(LedStatusDinamic==1)
	LedStatus_CreateContext(configMINIMAL_STACK_SIZE,(tskIDLE_PRIORITY+1),NULL)
#endif//#if(LedStatusDinamic==1)
}

//
/*******************************************************************//**
 * @brief Prototipo de tarea para realizar el Test
 * @return None
 *********************************************************************/
void vTask_Test(void *ptrArg)
{
	// -- Inicializamos el Acumulador de Tiempo para la Funcion
	sT_StatusLed *ptrLedSt = (sT_StatusLed *) ptrArg;
	static portTickType acuTime;
	static uint32_t time;
	LedStatus_SetStatus(ptrLedSt,STATUS_LED_1);
	uint8_t raise =0;
	portRTOS_INIdELAYmS(acuTime);
	/* Infinite loop*/
	while(1)
	{
		if(raise==0)
		{
			switch(LedStatus_GetStatus(ptrLedSt))
			{
			case STATUS_LED_1:
				time = 2*TIME_TEST;
				break;
			case STATUS_LED_2:
				time = 3*TIME_TEST;
				break;
			case STATUS_LED_3:
				time = 4*TIME_TEST;
				break;
			default :
				raise =1;
				continue;
			}
			LedStatus_ShiftUpStatus(ptrLedSt);
		}
		else
		{
			switch(LedStatus_GetStatus(ptrLedSt))
				{
				case STATUS_LED_4:
					time = 3*TIME_TEST;
					break;
				case STATUS_LED_3:
					time = 2*TIME_TEST;
					break;
				case STATUS_LED_2:
					time =TIME_TEST;
					break;
				default :
					raise =0;
					continue;
				}
			LedStatus_ShiftDownStatus(ptrLedSt);
		}
		portRTOS_DELAYuNTILmS(acuTime,time);

	}
	vTaskDelete(NULL);
}
//
//
/* **********************************************************************************************
 *
 * ==========================[ End  Local Module function Definition]===========================
 *
 * ******************************************************************************************** **/





