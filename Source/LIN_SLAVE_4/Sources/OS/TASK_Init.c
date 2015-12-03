/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: TASK_Init.c $
 * $Revision: 3.0 $
 * $Author: Guillermo Ramirez $
 * $Date: 21/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** In this function the task of the scheduler are defined and configured
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*         N/A         |   WINDOW LIFTER    |        3.0 TORTOISE SVN         */
/*----------------------------------------------------------------------------*/
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: TASK_Init.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "OS/TASK_Init.h"


/* Constants and types  */
/*============================================================================*/

#define taskPeriod1 1
#define taskPeriod2 40
#define taskOffset1 1
#define taskOffset2 2

const S_TASK cas_TaskList[E_TASK_NUM] = {
  /*{Pointer to function, 		 Period, 	Offset		}*/
	{VALIDATE  			, 	taskPeriod1, 	taskOffset1	},
	{STATE_MACHINE		, 	taskPeriod2, 	taskOffset2	}
};
 
/* Variables */
/*============================================================================*/
/*extern T_UBYTE Main_StateFlag;
extern T_UBYTE Valid;*/

/* Private functions */
/*============================================================================*/
/* ============= The functions of the tasks must be defined here ============ */
void VALIDATE(void)
{ /* ------------------------------------------------------------------------
	*  Name                 :  	VALIDATE  
	*  Description          :  	Read the state of the UP and DOWN switches, if
	*  							one of them is on it will call the WL_CheckValid
	*  							function to verify if its valid. This will happen
	*  							as long as the state_flag is E_DEFAULT, this to 
	*  							prevent that the function is called once it had been
	*  							validated and the window is in movement.
	*  Parameters           :  	void 
	*  Return               :  	void
	*  -----------------------------------------------------------------------
	*/
	
}

void STATE_MACHINE(void)
{ /* ------------------------------------------------------------------------
	*  Name                 :  	STATE_MACHINE  
	*  Description          :  	This function calls the state machine that controls
	*  							the window movement, depending on the flags defined
	*  							by the previous functions. It will always be called. 
	*  Parameters           :  	void 
	*  Return               :  	void
	* 
    */

	
}
/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */
