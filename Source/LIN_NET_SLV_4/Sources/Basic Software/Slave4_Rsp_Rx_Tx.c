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
#include "Basic Software\Slave4_Rsp_Rx_Tx.h"
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

void LINFlex_0_RX_ISR(void)
{
	/*******************************************************************************
	Function Name : LINFlex_0_RX_ISR
	Parameters    : NONE
	Modifies      : rx_data - received data
	Returns       : NONE
	Notes         : Rx data ISR on LINFlex_0. 
					Called if there is match with RX filter and data is received 
	*******************************************************************************/
	T_UBYTE lin_bidr;
	T_UBYTE laub_RxData[8];
	T_ULONG lub_LinStatus;
	
		lin_bidr = (T_UBYTE)LINFLEX_0.BIDR.B.ID;
	    switch(lin_bidr)
	    {
			case MASTER_CMD_ALL_ID:
				
				
				lub_LinStatus = GetLINStateMachineState();
					/* wait for RMB */
				ReleaseMessageBuffer();
				
				/* get the data */
				LinSlaveDataReception(laub_RxData);
				ProcessCommand(laub_RxData);
				ReceptionComplete();
				ClearMessageBuffer();
				HeaderReceived();
				
				break;
			case MASTER_CMD_SLV4_ID:
				
				lub_LinStatus = GetLINStateMachineState();
					/* wait for RMB */
				ReleaseMessageBuffer();
				
				/* get the data */
				LinSlaveDataReception(laub_RxData);
				ProcessCommand(laub_RxData);
				ReceptionComplete();
				ClearMessageBuffer();
				HeaderReceived();
				
				break;
			default:
				break;
	    }

}

void LINFlex_0_TX_ISR(void)
{
	T_UBYTE lin_bidr;
	lin_bidr = (T_UBYTE)LINFLEX_0.BIDR.B.ID;
    switch(lin_bidr)
    {
    case SLAVE4_RSP_ID:
    	if(GetLINStateMachineState()&0x1)		/* if header received */
    	{
    		
    		LINFLEX_0.BIDR.B.DIR = 0; /* BDR direction - write */
        
    	    /* fill the BDR registers */
    		/*Return Led status*/
    	    LINFLEX_0.BDRL.B.DATA0 = GetLedState();
    	    /*Return Node status*/
    	    LINFLEX_0.BDRL.B.DATA1 = GetNodeState();    
    	    
    	    /* trigger the data transmission */
    	    DataTransmissionRequest();
    	    HeaderReceived();
    	}
    	else
    	{
    		
    	}
    	
    	if(GetLINStateMachineState()&0x2)	/* if data transmitted */
    	{
    		
    		LINFLEX_0.LINSR.R = 0x2;
    	}
    	else
    	{
    		
    	}
    	break;
    case SLAVE4_ID_ID:
    	if(GetLINStateMachineState()&0x1)		/* if header received */
    	{
    		
    		LINFLEX_0.BIDR.B.DIR = 0; /* BDR direction - write */
        
    	    /* fill the BDR registers */
    	    LINFLEX_0.BDRL.B.DATA0 = 4;
    	    LINFLEX_0.BDRL.B.DATA1 = 'G';
    	    LINFLEX_0.BDRL.B.DATA2 = 'R';
    	    LINFLEX_0.BDRL.B.DATA3 = 'V';
    	    LINFLEX_0.BDRM.B.DATA4 = 'O';
    	    LINFLEX_0.BDRM.B.DATA5 = 'M';
    	    LINFLEX_0.BDRM.B.DATA6 = 'G';       
    	    
    	    /* trigger the data transmission */
    	    DataTransmissionRequest();
    	    HeaderReceived();
    	}
    	else
    	{
    		
    	}
    	
    	if(GetLINStateMachineState()&0x2)	/* if data transmitted */
    	{
    		
    		LINFLEX_0.LINSR.R = 0x2;
    	}
    	else
    	{
    		
    	}
        	break;
    default:
    	break;
    }
	

	
}

void ProcessCommand(T_UBYTE laub_Msg[1])
{
	 
					 
				
	switch (laub_Msg[0])
	{
	case CMD_NONE:
		break;
	case CMD_LED_ON:
		SetLedState(CMD_LED_ON);
		break;
	case CMD_LED_OFF:
		SetLedState(CMD_LED_OFF);
		break;
	case CMD_LED_TOGGLING:
		SetLedState(CMD_LED_TOGGLING);
		break;
	case CMD_DISABLE_SLV:
		SetNodeState(CMD_DISABLE_SLV);
			break;
	case CMD_ENABLE_SLV:
		SetNodeState(CMD_ENABLE_SLV);
		break;
	default :
		break;
	}
}
