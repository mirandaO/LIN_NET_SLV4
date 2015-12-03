/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: TASK_Init.h $
 * $Revision: 3.0 $
 * $Author: Guillermo Ramirez $
 * $Date: 21/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Structures and types definitions for the Tasks and the prototypes of these
 *  function
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
/*         N/A         |   WINDOW LIFTER    |        3.0 TORTOISE SVN         */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: TASK_Init.h  $
  ============================================================================*/
#ifndef TASK_Init_H
#define TASK_Init_H

/* Includes */
/*============================================================================*/
#include "OS/Scheduler.h"
#include "MAL/GPIO.h"
#include "driver_channel_MPC5606B.h"
#include "IntcInterrupts.h"
#include "MAL/Global_Init.h"
#include "MPC5606B.h" 
#include "stdtypedef.h"

/* Constants and types */
/*============================================================================*/
#define VALID 1
#define INVALID 0

/* The new tasks must be defined here */
extern enum{
	E_TASK1, 
	E_TASK2,
	
	/*DO NOT MODIFIED OR ERASE*/
	E_TASK_NUM
	
};

typedef struct {
	void(* rp_Tasks)(void); /*Pointer that'll call the task*/
	T_ULONG rul_Period; 	/*Period of task*/
    T_ULONG rul_Offset; 	/*Offset of task*/
}S_TASK;

/* Exported functions prototypes */
/*============================================================================*/

/* The prototype of the function must be declared here */
void VALIDATE(void);
void STATE_MACHINE(void);

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
