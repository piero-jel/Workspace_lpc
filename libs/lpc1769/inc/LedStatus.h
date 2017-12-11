#define LedStatus_projectEnable 1 /**<@brief enable/disable the project in case of version */
/** \addtogroup LedStatus_h LedStatus.h module
 ** @{ */
/********************************[ copyright ]*************************************//**
 *@copyright 2017, Luccioni Jesús Emanuel
 * All rights reserved.
 * This file is part of insertname
 * Redistribution is not allowed on binary and source forms,
 * with or without modification.
 * Use is permitted with prior authorization by
 * the copyright holder
 * \n meil :
 * 	- piero.jel@gmail.com
 *************************************************************************************/
//
/********************************[Header File]*************************************//**
 * @file    LedStatus.h.h
 * @brief	<descripcion breve> ej. port para tareas de uso comun de FREE RTOS
 * @version v01.01
 * @date   Dec 8, 2017
 * @note none
 * @author Luccioni, Jesus Emanuel
 *************************************************************************************/
//
// -- Definimos el Nombre del modulo
//
#ifndef __LedStatus_h__
#define __LedStatus_h__
//
//
#if(LedStatus_projectEnable == 1)
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * =======================================[begin of project file]=======================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
//
//
//
/*============================[Open, cplusplus]============================*/
//
#ifdef __cplusplus
extern "C" {
#endif
//
//
//
/* **********************************************************************************************
 *
 * =================================[ Begin include header file ]================================
 *
 * ******************************************************************************************** */
//
// TODO: include header file sector, "only in case specific"
//
/** example : #include <nmbHeaderFile.h> */

//
/* **********************************************************************************************
 *
 * ==================================[ End include header file ]=================================
 *
 * ******************************************************************************************** **/

/* **********************************************************************************************
 *
 * ==========================[ Begin labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** **/
//
// TODO: labels enable/disable functions
//
// -- local
#define LedStatus_USE_LocalData 0 /**<@brief enable/disable the use Global Data */
#define LedStatus_USE_LocalFunctions 0 /**<@brief enable/disable the use Gobal functions */
#define LedStatus_USE_LocalMacroApis 0 /**<@brief enable/disable the use Local macros functions */
#define LedStatus_USE_ISR 0 /**<@brief enable/disable the use ISR apis */
// -- global
#define LedStatus_USE_GlobalMacro 0  /**<@brief enable/disable the use Global Macros/Labels */
#define LedStatus_USE_GlobalTypedef 1 /**<@brief enable/disable the use Global Typedef */
#define LedStatus_USE_GlobalData 0 /**<@brief enable/disable the use Global Data */
#define LedStatus_USE_GlobalFunctions 1 /**<@brief enable/disable the use Gobal functions */
#define LedStatus_USE_GlobalMacroApis 1 /**<@brief enable/disable the use Gobal macros functions */
//
#define LedStatus_SHOULD_BE_DINAMIC 1 /**<@brief Specifies whether the module should be dynamic */
#define LedStatus_ENABLE_TASK_TEST 0 /**<@brief Enable/disable task for test */
/**/
#if(LedStatus_ENABLE_TASK_TEST==1)
#define TIME_TEST 5000	/**<@brief Time for task Test */
#endif




/* **********************************************************************************************
 *
 * ==========================[ End labels enable/disable functions ]===========================
 *
 * ******************************************************************************************** **/
//
//
//
/* **********************************************************************************************
 *
 * ==========================[ Begin Global Macros/labels definition]===========================
 *
 * ******************************************************************************************** **/
#if(LedStatus_USE_GlobalMacro==1)
//
// TODO : Macros/labels definition
//
#define LedStatus_MACRO_1	0 /**<@brief example of macro definitions  */
#define LedStatus_LABEL_A /**<@brief example of Labels Definitions */
//
//
//
#endif //#if(LedStatus_USE_GlobalMacro==1)
/* **********************************************************************************************
 *
 * ==========================[ End Macros/labels Globals ]===========================
 *
 * ******************************************************************************************** **/
//
//
//
/* **********************************************************************************************
 *
 * ====================================[Begin Global typedef]====================================
 *
 * ******************************************************************************************** */
#if(LedStatus_USE_GlobalTypedef==1)
//
// TODO: Global typedef
//
 /** @brief enumeration type for diferent satus of LEDs */
typedef enum
{
	STATUS_LED_1 = 2, /**<@brief Status 1, Blink 50 / 50 */
	STATUS_LED_2 = 4, /**<@brief Status 1, two Blinks of Time On y one time off */
	STATUS_LED_3 = 6, /**<@brief Status 1, Three Blinks of Time On y one time off */
	STATUS_LED_4 = 8, /**<@brief Status 1, Forth Blinks of Time On y one time off */
}eT_StatusLed;

#if(LedStatus_SHOULD_BE_DINAMIC==1)
#if 1//fixme update
/** @brief Estructura de datos para la tarea led status */
typedef struct
{
	const uint8_t numPort;/**<@brief Status 1, Blink 50 / 50 */
	const uint8_t numPin;/**<@brief Status 1, Blink 50 / 50 */
	const uint16_t TimeOn; /**<@brief Status 1, Blink 50 / 50 */
	const uint16_t TimeOff; /**<@brief Status 1, Blink 50 / 50 */
//	const Bool PullUp;/**<@brief Status 1, Blink 50 / 50 */
	eT_StatusLed status;/**<@brief Status 1, Blink 50 / 50 */
	uint8_t count;
	portTickType acuTime;/**<@brief Status 1, Blink 50 / 50 */
}sT_StatusLed;
#else
/** @brief Estructura de datos para la tarea led status */
typedef struct
{
	uint8_t numPort;/**<@brief Status 1, Blink 50 / 50 */
	uint8_t numPin;/**<@brief Status 1, Blink 50 / 50 */
	eType_StatusLed status;/**<@brief Status 1, Blink 50 / 50 */
	uint8_t count;
	portTickType acuTime;/**<@brief Status 1, Blink 50 / 50 */
}sT_StatusLed;

#endif
//
//
#endif
//
//
//
#endif//#if(LedStatus_USE_GlobalTypedef==1)
/* **********************************************************************************************
 *
 * ====================================[End Global typedef]====================================
 *
 * ******************************************************************************************** */
//
//
//
//
#ifdef __LedStatus_c__
/* **********************************************************************************************
 *
 * ==================================[ Begin local declaration ]=================================
 *
 ********************************************************************************************** */
//
//
//
//
//
//
/* ---------------------------------------------------------------------------------
 *
 * ==================[Begin export data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/
#if(LedStatus_USE_GlobalData==1)
//
// TODO : Global data declaration
//
unsigned int globalExample; /**<@brief variable global example, brief of data */

//
//
#endif//#if(LedStatus_USE_GlobalTypedef==1)
/* ---------------------------------------------------------------------------------
 *
 * ==================[End Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/
//
//
//
/* **********************************************************************************************
 *
 * ==================================[ End local declaration ]=================================
 *
 ********************************************************************************************** */
//
//
#else // ifdef __LedStatus_c__
//
//
/* **********************************************************************************************
 *
 * ==============================[ Begin Only externa declaration ]=============================
 *
 ********************************************************************************************** */
/* SECTOR excluido de -> LedStatus.c, utlizar con cuidado*/
//
// TODO : Only external declaration
//
//
//
//
/* ---------------------------------------------------------------------------------
 *
 * ==================[Begin export data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/
#if(LedStatus_USE_GlobalData==1)
//
// TODO : Global data declaration
//
extern unsigned int globalExample; /**<@brief variable global example, brief of data */

//
//
#endif//#if(LedStatus_USE_GlobalTypedef==1)
/* ---------------------------------------------------------------------------------
 *
 * ==================[End Global data declaration]==============================
 *
 * --------------------------------------------------------------------------------*/

//
//
/* **********************************************************************************************
 *
 * ==============================[ End Only externa declaration ]=============================
 *
 ********************************************************************************************** */
//
//
//
 #endif // ifdef __LedStatus_c__
//
//
//
//
/* **********************************************************************************************
 *
 * ==================================[ Begin Global declaration ]=================================
 *
 ********************************************************************************************** */
//
//
//
/* ---------------------------------------------------------------------------------
 *
 * ==================[Begin Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------*/
#if(LedStatus_USE_GlobalFunctions==1)
/*******************************************************************//**
 * @brief	API  for creation of context of all tasks of the module
 * @param ptrInst : Pointer for Instation of the Task
 * should be :
 * 		+ ....
 * 		+ .....
 * @param Priority	: priority for the Task
 * @param stackSize : Stack Size for The Task
 * @return none
 *********************************************************************/
 void LedStatus_CreateContext(void *ptrInst/* Inatcnciacion de la Tareas*/\
		,uint32_t Priority/*Prioridad de la Tarea*/\
		,uint32_t stackSize/* TAmaño de la pila asignad a la Tarea*/);
 /**/
#if(LedStatus_SHOULD_BE_DINAMIC==1)
 //
 //
 /*******************************************************************//**
  * @brief	API  for Initialization of all the hardware
  * used in the module
  * @return none
  *********************************************************************/
 void LedStatus_Init(sT_StatusLed *ptrLedSt);
 //
 //
 /*******************************************************************//**
  * @brief	API  for Set a new status on the LED of STATUS
  * @param newStaus : New status desired
  * should be:
  *  + STATUS_LED_1 : 1-Blink in On, 1-Blink in Off (30/70 %, in time)
  *  + STATUS_LED_2 : 2-Blink with Time On, 1-Blink with Time Off
  *  + STATUS_LED_3 : 3-Blink with Time On, 1-Blink with Time Off
  *  + STATUS_LED_4 : 4-Blink with Time On, 1-Blink with Time Off
  * @return none
  *********************************************************************/
 void LedStatus_SetStatus(sT_StatusLed *ptrLedSt \
 		,eT_StatusLed newStatus);
 //
 //
 //
 /*******************************************************************//**
  * @brief	API  for Get the current status on the LED of STATUS
  * @return Current Status
  * should be:
  *  + STATUS_LED_1 : 1-Blink in On, 1-Blink in Off (30/70 %, in time)
  *  + STATUS_LED_2 : 2-Blink with Time On, 1-Blink with Time Off
  *  + STATUS_LED_3 : 3-Blink with Time On, 1-Blink with Time Off
  *  + STATUS_LED_4 : 4-Blink with Time On, 1-Blink with Time Off *
  *********************************************************************/
 eT_StatusLed LedStatus_GetStatus(sT_StatusLed *ptrLedSt);
 //
 //
 /*******************************************************************//**
  * @brief	API  for shift descendant format the status of LED
  * @return none
  *********************************************************************/
 void LedStatus_ShiftDownStatus(sT_StatusLed *ptrLedSt);
 //
 //
 /*******************************************************************//**
  * @brief	API  for shift ascendent format the status of LED
  * @return none
  *********************************************************************/
 void LedStatus_ShiftUpStatus(sT_StatusLed *ptrLedSt);
 /* **********************************************************************************************
  *
  * =================================[ Begin task declaration ]==================================
  *
  * ******************************************************************************************** */
//
 //
 /*******************************************************************//**
  * @brief	Task to control the status led
  * @return none, A task never returns
  *********************************************************************/
 void vTask_LedStatus(void *ptrArg);
#else//#if(LedStatus_SHOULD_BE_DINAMIC==1)
//
//
/*******************************************************************//**
 * @brief	API  for Initialization of all the hardware
 * used in the module
 * @return none
 *********************************************************************/
void LedStatus_Init(void);
//
//
/*******************************************************************//**
 * @brief	API  for Set a new status on the LED of STATUS
 * @param newStaus : New status desired
 * should be:
 *  + STATUS_LED_1 : 1-Blink in On, 1-Blink in Off (30/70 %, in time)
 *  + STATUS_LED_2 : 2-Blink with Time On, 1-Blink with Time Off
 *  + STATUS_LED_3 : 3-Blink with Time On, 1-Blink with Time Off
 *  + STATUS_LED_4 : 4-Blink with Time On, 1-Blink with Time Off
 * @return none
 *********************************************************************/
void LedStatus_SetStatus(eT_StatusLed newStatus);
//
//
//
/*******************************************************************//**
 * @brief	API  for Get the current status on the LED of STATUS
 * @return Current Status
 * should be:
 *  + STATUS_LED_1 : 1-Blink in On, 1-Blink in Off (30/70 %, in time)
 *  + STATUS_LED_2 : 2-Blink with Time On, 1-Blink with Time Off
 *  + STATUS_LED_3 : 3-Blink with Time On, 1-Blink with Time Off
 *  + STATUS_LED_4 : 4-Blink with Time On, 1-Blink with Time Off *
 *********************************************************************/
eT_StatusLed LedStatus_GetStatus(void);
//
//
/*******************************************************************//**
 * @brief	API  for shift descendant format the status of LED
 * @return none
 *********************************************************************/
void LedStatus_ShiftDownStatus(void);
//
//
/*******************************************************************//**
 * @brief	API  for shift ascendent format the status of LED
 * @return none
 *********************************************************************/
void LedStatus_ShiftUpStatus(void);
/* **********************************************************************************************
 *
 * =================================[ Begin task declaration ]==================================
 *
 * ******************************************************************************************** */
//
// TODO : task declaration
//
//
//
/*******************************************************************//**
 * @brief	Task to control the status led
 * @return none, A task never returns
 *********************************************************************/
void vTask_LedStatus(void);
//
#endif//#if(LedStatus_SHOULD_BE_DINAMIC==1)

/* **********************************************************************************************
 *
 * =================================[ End task declaration ]==================================
 *
 * ******************************************************************************************** */
//
//
//

#endif//#if(LedStatus_USE_GlobalFunctions==1)
/* ---------------------------------------------------------------------------------
 *
 * ==================[End Global functions declaration]=========================
 *
 * --------------------------------------------------------------------------------*/
//
//
//
/* **********************************************************************************************
 *
 * ===========================[ Begin Global Macros functions ]==================================
 *
 ********************************************************************************************** */
 #if(LedStatus_USE_GlobalMacroApis==1)
//
//
//

#if(LedStatus_SHOULD_BE_DINAMIC==1)
#define LedStatus_INIT(strLED,status) \
{\
	LedStatus_Init(&strLED);\
	LedStatus_SetStatus(&strLED,status);\
}
#else
#define LedStatus_INIT(status) \
{\
	LedStatus_Init();\
	LedStatus_SetStatus(status);\
}
#endif


#if(LedStatus_ENABLE_TASK_TEST==1)
/**/
void vTask_TestTask(void *ptrArg);
/**/
#define CREATE_TASK_TEST(stackSIZE,ptrStrLedSt,nPriority) \
xTaskCreate( \
(pdTASK_CODE) vTask_TestTask,	/*-- Puntero a la Funcion*/\
(signed char*) "vTask_TestTask",/*-- Nombre asignado p/Debbug, "Marca de Agua" hasta 16-Char*/\
stackSIZE,	/*-- Longitud de la Pila en Word*/\
(void*) &ptrStrLedSt,/*-- Referencia al Argumento de la Tarea, en este caso ninguna */\
nPriority,				/*-- Nivel de Prioridad para la Tarea*/\
NULL /*-- Identificador de la Tarea Creada*/\
)

#else
#define CREATE_TASK_TEST(stackSIZE,ptrStrLedSt,nPriority)
#endif



#if(LedStatus_SHOULD_BE_DINAMIC==1)

/*******************************************************************//**
 * @brief	API  for creation of context of all tasks of the module
 * @param Priority	: priority for the Task
 *  should be :
 *   + (tskIDLE_PRIORITY+1)
 *   + (tskIDLE_PRIORITY+2)
 *   + ...
 * @param stackSize : Stack Size for The Task
 *  should be :
 *   + configMINIMAL_STACK_SIZE
 *   + (configMINIMAL_STACK_SIZE)*2
 *   + (configMINIMAL_STACK_SIZE)*3
 *   + (configMINIMAL_STACK_SIZE)*4
 *   + ...
 * @param Handler : Handler for the Task
 *  should be :
 *  	+ NULL : in case not use Handler
 *  	variable predefined as 'xTaskHandle NameHandler'
 * @return none
 * *********************************************************************/
#define	LedStatus_CreateContext(stackSize,ptrLedSt,Priority,Handler); \
{  \
/*********************************************************************
 * @brief	API  for creation of context of all tasks of the module
 * @param Priority	: priority for the Task
 *  should be :
 *   + (tskIDLE_PRIORITY+1)
 *   + (tskIDLE_PRIORITY+2)
 *   + ...
 * @param stackSize : Stack Size for The Task
 *  should be :
 *   + configMINIMAL_STACK_SIZE
 *   + (configMINIMAL_STACK_SIZE)*2
 *   + (configMINIMAL_STACK_SIZE)*3
 *   + (configMINIMAL_STACK_SIZE)*4
 *   + ...
 * @param Handler : Handler for the Task
 *  should be :
 *  	+ NULL : in case not use Handler
 *  	variable predefined as 'xTaskHandle NameHandler'
 * @return none
 * *********************************************************************/\
 xTaskCreate( \
	(pdTASK_CODE) vTask_LedStatus,	/*-- Puntero a la Funcion*/\
	(signed char*) "vTaskLedStOk",/*-- Nombre asignado p/Debbug, "Marca de Agua" hasta 16-Char*/\
	stackSize,	/*-- Longitud de la Pila en Word*/\
	(void*) &ptrLedSt,/*-- Referencia al Argumento de la Tarea, en este caso ninguna */\
	Priority,				/*-- Nivel de Prioridad para la Tarea*/\
	Handler /*-- Identificador de la Tarea Creada*/\
	);\
CREATE_TASK_TEST(stackSize,ptrLedSt,Priority);\
}
#else
/*******************************************************************//**
 * @brief	API  for creation of context of all tasks of the module
 * @param Priority	: priority for the Task
 *  should be :
 *   + (tskIDLE_PRIORITY+1)
 *   + (tskIDLE_PRIORITY+2)
 *   + ...
 * @param stackSize : Stack Size for The Task
 *  should be :
 *   + configMINIMAL_STACK_SIZE
 *   + (configMINIMAL_STACK_SIZE)*2
 *   + (configMINIMAL_STACK_SIZE)*3
 *   + (configMINIMAL_STACK_SIZE)*4
 *   + ...
 * @param Handler : Handler for the Task
 *  should be :
 *  	+ NULL : in case not use Handler
 *  	variable predefined as 'xTaskHandle NameHandler'
 * @return none
 * *********************************************************************/
#define	LedStatus_CreateContext(stackSize,Priority,Handler); \
{  \
/*********************************************************************
 * @brief	API  for creation of context of all tasks of the module
 * @param stackSize : Stack Size for The Task
 *  should be :
 *   + configMINIMAL_STACK_SIZE
 *   + (configMINIMAL_STACK_SIZE)*2
 *   + (configMINIMAL_STACK_SIZE)*3
 *   + (configMINIMAL_STACK_SIZE)*4
 *   + ...
 * @param Priority	: priority for the Task
 *  should be :
 *   + (tskIDLE_PRIORITY+1)
 *   + (tskIDLE_PRIORITY+2)
 *   + ...
 * @param Handler : Handler for the Task
 *  should be :
 *  	+ NULL : in case not use Handler
 *  	variable predefined as 'xTaskHandle NameHandler'
 * @return none
 * *********************************************************************/\
		xTaskCreate( \
		(pdTASK_CODE) vTask_LedStatus,	/*-- Puntero a la Funcion*/\
		(signed char*) "vTaskLedStOk",/*-- Nombre asignado p/Debbug, "Marca de Agua" hasta 16-Char*/\
		stackSize,	/*-- Longitud de la Pila en Word*/\
		NULL,			/*-- Referencia al Argumento de la Tarea, en este caso ninguna */\
		Priority,				/*-- Nivel de Prioridad para la Tarea*/\
		Handler /*-- Identificador de la Tarea Creada*/\
		);\
}
#endif


//
//
//
#endif// #if(LedStatus_USE_GlobalMacroApis==1)
/* **********************************************************************************************
 *
 * ===========================[ End Global Macros functions ]==================================
 *
 ********************************************************************************************** */


 //
 //
 //
/* **********************************************************************************************
 *
 * ==================================[ END GLOBAL declaration ]=================================
 *
 ********************************************************************************************** */
//
/*============================[close, cplusplus]============================*/
//
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/*==============================[end of file]==============================*/
#endif //#ifndef __LedStatus_h__
//
//
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *
 * ========================================[end of project file]========================================
 *
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#endif//#if(LedStatus_projectEnable == 1)
