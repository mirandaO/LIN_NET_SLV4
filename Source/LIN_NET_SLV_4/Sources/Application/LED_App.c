/*
 * LED_App.c
 *
 *  Created on: Dec 4, 2015
 *      Author: x
 */


/*
 * Slave4_Rsp_Rx_Tx.c
 *
 *  Created on: Dec 4, 2015
 *      Author: x
 */

/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: filename.c $
 * $Revision: version $
 * $Author: author $
 * $Date: date $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
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
/*                     |LIN NETWORK 1 SLAVE |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "Application\LED_App.h"
/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/
/*Initial state = OFF*/
T_UBYTE rub_LedState = OFF;

/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/
void ChangeLedState(T_UBYTE);


/* Exported functions */
/*============================================================================*/
void ChangeLedState(T_UBYTE lul_LedState)
{
	rub_LedState = lul_LedState;
}

T_UBYTE GetLedState(void)
{
	return rub_LedState;
}

void Led_StateMachine(void)
{
	static T_UBYTE lub_TickCounter = RESET_COUNTER;
	switch (GetLedState())
		{
	
		case OFF:
			
			if(ENABLED == rub_NodeState)
			{
				GPIO_SetState(LED1,TURN_OFF);
				/*Change state variable into the requested command*/
				ChangeLedState(rub_LedFlag);
			}
			else
			{
			 //do nothing
			}
			break;
		case ON:
			if(ENABLED == rub_NodeState)
			{
				GPIO_SetState(LED1,TURN_ON);
				/*Change state variable into the requested command*/
				ChangeLedState(rub_LedFlag);
			}
			else
			{
			 /*do nothing*/
			}
			break;
		case TOGGLING:
			if(ENABLED == rub_NodeState)
			{
				if(HOLD_ON == lub_TickCounter )
				{
					GPIO_SetState(LED1,TURN_ON);
				}
				else {}
				
				if(HOLD_OFF == lub_TickCounter )
				{
					GPIO_SetState(LED1,TURN_OFF);
				}
				else {}
				
				/*If a complete cycle has been reached increase lub_TickCounter
				  otherwise reset it*/
				if(COMPLETE_CYCLE != lub_TickCounter) 	
				{
					lub_TickCounter++;
				}
				else
				{
					lub_TickCounter = RESET_COUNTER;
				}
				/*Change state variable into the requested command*/
				ChangeLedState(rub_LedFlag);
			}
			else
			{
			 /*do nothing*/
			}
			break;
			
		default :
			break;
		}
}
