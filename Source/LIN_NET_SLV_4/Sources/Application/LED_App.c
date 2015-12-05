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



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/



/* Exported functions */
/*============================================================================*/
void SetLedState(T_UBYTE lul_LedState)
{
	rub_LedState = lul_LedState;
}

T_ULONG GetLedState(void)
{
	return rub_LedState;
}

void Led_StateMachine(void)
{
	switch (GetLedState())
		{
		case CMD_NONE:
			break;
		case CMD_LED_ON:
			//gpio
			break;
		case CMD_LED_OFF:
			//gpio
			break;
		case CMD_LED_TOGGLING:
			//gpio
			break;
			
		default :
			break;
		}
}
