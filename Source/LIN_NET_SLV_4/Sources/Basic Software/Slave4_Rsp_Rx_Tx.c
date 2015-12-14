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
 * $Author: Guillermo Ramírez Vázquez, Óscar Francisco Miranda García
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
#include "Basic Software\Slave4_Rsp_Rx_Tx.h"
/* Constants and types  */
/*============================================================================*/

#define SWITCH_INTERR_FLAG SIU.ISR.B.EIF21

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

void LINFlex_0_RX_ISR(void)
{
	/* --------------------------------------------------------------------------
	*  Name                 :  LINFlex_0_RX_ISR
	*  Description          :  This function is called when a reception id from the filters 
	*  defined match. When this happens the master command is listened and send the command 
	*  either to node state machine or led state machine.							
	*  Parameters           : void
	*  								
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
	
			/* wait for RMB */
	ReleaseMessageBuffer();
	
	/* get the data */
	LinSlaveDataReception(raub_RxData);
	/*Send data either to slave or led machine*/
	rub_CommandFlag = COMMANDRECEIVED;
	ReceptionComplete();
	HeaderReceived();
	ClearMessageBuffer();
}

void LINFlex_0_TX_ISR(void)
{

	/* --------------------------------------------------------------------------
	*  Name                 :  LINFlex_0_TX_ISR
	*  Description          :  This function is called when a data transmission
	*   or a header interrupt take place depending on the filters defined.
	*    If a header interrupt happens, the data transmission
	*   request is made. When data is transmitted, an acknowledge of it is made.
	*  							
	*  Parameters           : void
	*  								
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
	T_UBYTE lub_lin_bidr;
	lub_lin_bidr = GetBufferId();
	/* if  interrupt generated when header received */
	if(GetLINStateMachineState()&0x1)
	{
		
		switch(lub_lin_bidr)
		{
		case SLAVE4_RSP_ID:
			
				
				SetBufferDirection(TRANSMIT); /* BDR direction - write */
			
				/* fill the BDR registers */
				WriteTxBuffer(SENDSTATES);
				
				//LINFLEX_0.BIDR.B.DFL = 1;  Verify page 525, sec. 24.7.2.1
				
				/* trigger the data transmission */
				DataTransmissionRequest();
				HeaderReceived();
			
			break;
		case SLAVE4_ID_ID:

				SetBufferDirection(TRANSMIT); /* BDR direction - write probably not necessary*/
			
				/* fill the BDR registers */
				WriteTxBuffer(SENDTEAMINFO);    
				
				/* trigger the data transmission */
				DataTransmissionRequest();
				HeaderReceived();
			
				break;
		default:
			break;
		}
	}	
	else if(GetLINStateMachineState()&0x2)	/* if interrupt generated when data transmitted */
	{
		 		
		DataTxAcknowledge();
	}	else {/*Do nothing*/}

	
}






