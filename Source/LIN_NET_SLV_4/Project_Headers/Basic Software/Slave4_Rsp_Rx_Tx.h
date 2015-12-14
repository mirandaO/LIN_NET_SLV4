/*
 * SLAVE4_RSP_RX_TX.c
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
 * $Source: Slave4_Rsp_Rx_Rt.c $
 * $Revision: 18 $
* $Author: Guillermo Ramírez Vázquez, Óscar Francisco Miranda García
 * $Date: 12/06/2015 $
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
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: GPIO.h  $
  ============================================================================*/
#ifndef SLAVE4_RSP_RX_TX_C_
#define SLAVE4_RSP_RX_TX_C_

/* Includes */
/*============================================================================*/
#include "MAL\LIN_Init.h"

/* Constants and types */
/*============================================================================*/
#define SENDSTATES 1
#define	SENDTEAMINFO 0
#define COMMANDRECEIVED 1

/* Exported Variables */
/*============================================================================*/
T_UBYTE rub_CommandFlag;
T_UBYTE raub_RxData[8];
/* Exported functions prototypes */
/*============================================================================*/

/*Interrupts Beginnig*/
void LINFlex_0_RX_ISR(void);
void LINFlex_0_TX_ISR(void);
/*Interrupts End*/


#endif /* SLAVE4_RSP_RX_TX_C_ */
