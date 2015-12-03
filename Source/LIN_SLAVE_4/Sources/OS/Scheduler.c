/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Scheduler.c $
 * $Revision: 2.0 $
 * $Author: Guillermo Ramirez $
 * $Date: 20/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** The scheduler is contained inside a function called kernel, this function is in 
* TASK_Init.c. This function starts by doing an indexing of the task, assigning the 
* offset. This process occurs only once in each execution of the code.
* Then an infinite loop starts, the tick of the scheduler is defined by a flag called 
* ub_TickFlag, which was configured to raise every millisecond. Once it was acquired it is
* restarted to zero. 
* Now, inside the if there is a for cycle which who through all the task accessing to their
* offset with and if, whenever the offset is over zero it will decrease, for every task. 
* When one of the offset, of whichever task, reach zero, the else of the if will be active 
* and will establish the period of the task and will call it using the pointer previously defined.
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
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*         N/A         |   WINDOW LIFTER    |        2.0 TORTOISE SVN         */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: Scheduler.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "OS/Scheduler.h"

/* Variables */
/*============================================================================*/
T_ULONG rul_Count;
T_ULONG rul_Index;
T_ULONG raul_NTask[E_TASK_NUM];
T_UBYTE ub_TickFlag;
extern const S_TASK cas_TaskList[E_TASK_NUM];

/* Private functions */
/*============================================================================*/
void Tick_Flag(void)
{  /* --------------------------------------------------------------------------
	*  Name                 :  Tick_Flag
	*  Description          :  Check if the channel 0 of the STM as reached 1ms
	*  						   and raise a flag when reached
	*  Parameters           :  void 
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
	if (STM.CH[0].CIR.B.CIF)
	{
		ub_TickFlag = 1;
		STM.CH[0].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/* Reset counter		*/
	}
}



/* ------------------------------ DO NOT MODIFY ----------------------------- */
void kernel (void){
	/* ------------------------------------------------------------------------
	 *  Name                 :	kernel
	 *  Description          :  This function starts by doing an indexing of the 
	 *  						task, assigning the offset. This process occurs 
	 *  						only once in each execution of the code.
	 *							Then an infinite loop starts, the tick of the 
	 *							scheduler is defined by a flag called ub_TickFlag, 
	 *							which was configured to raise every millisecond. 
	 *							Once it was acquired it is restarted to zero. 
	 *							Now, inside the if there is a for cycle which who 
	 *							through all the task accessing to their offset with 
	 *							and if, whenever the offset is over zero it will 
	 *							decrease, for every task. When one of the offset, 
	 *							of whichever task, reach zero, the else of the if 
	 *							will be active and will establish the period of the 
	 *							task and will call it using the pointer previously defined. 
	 *  Parameters           :  void
	 *  Return               :  void
	 *  -----------------------------------------------------------------------*/
	for (rul_Index = 0; rul_Index < E_TASK_NUM; rul_Index ++){
		raul_NTask[rul_Index] = cas_TaskList[rul_Index].rul_Offset;
	}
		/* Loop Forever */
		while (1) {
			if (ub_TickFlag){
				ub_TickFlag = 0;
				for(rul_Count = 0; rul_Count < E_TASK_NUM; rul_Count++){
					if (raul_NTask[rul_Count] > 0){
						raul_NTask[rul_Count]--;
					}
					else{
						raul_NTask[rul_Count] = cas_TaskList[rul_Count].rul_Period;
						cas_TaskList[rul_Count].rp_Tasks();
					}
				}
			}
			else{}
		}
	
/* ---------------------------- DO NOT MODIFIED ----------------------------- */
}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
