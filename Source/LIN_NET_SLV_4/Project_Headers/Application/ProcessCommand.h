/*
 * ProccesCommand.h
 *
 *  Created on: Dec 13, 2015
 *      Author: x
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
#ifndef PROCCESCOMMAND_H_
#define PROCCESCOMMAND_H_
/* Includes */
/*============================================================================*/
#include "MAL\LIN_Init.h"

#define COMMANDDISPATCHED 0
#define COMMANDINQUEUE 1
/* Exported Variables */
/*============================================================================*/
extern T_UBYTE rub_CommandFlag;
extern T_UBYTE raub_RxData[8];
extern e_cmdType;
T_UBYTE rub_LedFlag = OFF;
T_UBYTE rub_NodeFlag = DISABLED;
/* Exported functions prototypes */
/*============================================================================*/


extern T_UBYTE GetNodeState(void);
extern T_UBYTE GetLedState(void);

void ProcessCommand(void);
void SendLedCommand(T_UBYTE);
void SendNodeCommand(T_UBYTE);

#endif /* PROCCESCOMMAND_H_ */
