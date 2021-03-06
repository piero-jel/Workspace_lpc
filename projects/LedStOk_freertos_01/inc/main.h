/* Copyright 2016, Luccioni Jesus Emanuel
 * All rights reserved.
 */
/** \addtogroup main_h main_h module
 ** @{ */

/********************************[Header File]*************************************//**
 * @file    main.h
 * @brief	Archivo que contine las Definiciones_inc de APIs del modulo main
 * @version version
 * @date   Apr 23, 2017
 * @note none
 * @par jel, Luccioni Jesus Emanuel
 *************************************************************************************/
/*
// -- Definimos el Nombre del modulo
*/
#ifndef __main_h__
#define __main_h__

/*
// ============================[Open, cplusplus]============================
*/
#ifdef __cplusplus
extern "C" {
#endif
/*
//
*/
/* **********************************************************************************************
 *
 * =================================[ Begin include header file ]================================
 *
 * ******************************************************************************************** */
/*
// TODO: include header file sector, "only in case especific"
*/
/** @example : #include <nmbHeaderFile.h> */
/*
 * */
#define INITsOFTWARE_ENABLE 1 /**@brief  Habilitamos/deshabilitamos el inico de software */
#define INIThARDWARE_ENABLE 1 /**@brief  Habilitamos/deshabilitamos el inico de hardware*/
#define IDLE_THREAD_ENABLE 1/**@brief  */
/* **********************************************************************************************
 *
 * ==================================[ End include header file ]=================================
 *
 * ******************************************************************************************** */
/*
//
*/
/* **********************************************************************************************
 *
 *=============================[ Begin Global definition Variables ]=============================
 *
 * ******************************************************************************************** */
//
// TODO: Global definition Variables
//



//
//
/* **********************************************************************************************
 *
 * ==============================[ End Global definition Variables ]=============================
 *
 * ******************************************************************************************** */
/*
 *
 * */
/* **********************************************************************************************
 *
 * ==========================[ Begin Macros/labels definition]===========================
 *
 * ******************************************************************************************** **/
/*
// TODO : Macros/labels definition
*/



/* **********************************************************************************************
 *
 * ==========================[ End Macros/labels definitions ]===========================
 *
 * ******************************************************************************************** **/
/*
//
*/
/* **********************************************************************************************
 *
 * ===========================[ Begin Main APIs Declaration ]============================
 *
 * ******************************************************************************************** */
/*
// TODO :  Main APIs Declaration
*/
/*******************************************************************//**
 * @brief	Funcion Principal
 * @param 	None
 * @return	La funcion Principal para esta aplicacion nunca debe
 * retornar un valor. En caso de Hacerlo retorna un error
 *********************************************************************/
int main(void);
/*
//
*/
/*******************************************************************//**
 * @param 	None
 * @brief	Function for initialization of hardware object
 * @return	None
 *********************************************************************/
void initHardware(void);
//
//
//
/*******************************************************************//**
 * @brief Function for initialization of software object *
 * @param None
 * @return None
 *********************************************************************/
void initSoftware(void);
//
//
/*
//
*/
/* **********************************************************************************************
 *
 * ===========================[ End Main APIs Declaration ]============================
 *
 * ******************************************************************************************** */
/*
//
*/
/* **********************************************************************************************
 *
 * ===========================[ Begin Macros APIs Definitions ]============================
 *
 * ******************************************************************************************** */
/**
 * @brief Macro definition for hardware initialization
 */
#if(INIThARDWARE_ENABLE==1)
#define	INIT_HARDWARE() initHardware()
#else
#define	INIT_HARDWARE()
#endif
//
//
/**
 * @brief Macro definition for software initialization
 */
#if(INITsOFTWARE_ENABLE==1)
#define INIT_SOFTWARE() initSoftware()
#else
#define INIT_SOFTWARE()
#endif



/* **********************************************************************************************
 *
 * ===========================[ End Macros APIs Definitions ]============================
 *
 * ******************************************************************************************** */

/*
//============================[close, cplusplus]============================
*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef __main_h__ */
