/*
 * ProcessCommand.c
 *
 *  Created on: Dec 13, 2015
 *      Author: x
 */

#include "Application\ProcessCommand.h"

void ProcessCommand(void)
{
	/* --------------------------------------------------------------------------
	*  Name                 :  ProcessCommand
	*  Description          :  Reads the response of the master and determines which command
	*  							the slave will execute: whether to do nothing, request the Led_StateMachine
	*  							 to turn on/off or toggle, or request the Node_StateMachine to disable or enable 
	*  							 the node.
	*  							
	*  Parameters           :  void
	*  								
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
					 
		if(COMMANDINQUEUE == rub_CommandFlag )	
		{	
			switch (raub_RxData[0])
			{
			case CMD_NONE:
				break;
			case CMD_LED_ON:
				SendLedCommand(ON);
				rub_CommandFlag = COMMANDDISPATCHED;
				break;
			case CMD_LED_OFF:
				SendLedCommand(OFF);
				rub_CommandFlag = COMMANDDISPATCHED;
				break;
			case CMD_LED_TOGGLING:
				SendLedCommand(TOGGLING);
				rub_CommandFlag = COMMANDDISPATCHED;
				break;
			case CMD_DISABLE_SLV:
				SendNodeCommand(DISABLED);
				rub_CommandFlag = COMMANDDISPATCHED;
					break;
			case CMD_ENABLE_SLV:
				SendNodeCommand(ENABLED);
				rub_CommandFlag = COMMANDDISPATCHED;
				break;
			default :
				break;
			}
		} else{/*do nothing*/}
}

void SendLedCommand(T_UBYTE lub_LedFlg)
{
	/* --------------------------------------------------------------------------
	*  Name                 :  SendLedCommand
	*  Description          :  Change the value of the global variable led flag 
	*  							that will be used by the Led_StateMachine to change its
	*  							state variable. 
	*  Parameters           :  T_UBYTE lub_LedFlg
	*  								Possible values: CMD_LED_ON, CMD_LED_OFF or CMD_LED_TOGGLING.
	*  								
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
	rub_LedFlag = lub_LedFlg;
	
}

void SendNodeCommand(T_UBYTE lub_NodeFlg)
{
	/* --------------------------------------------------------------------------
	*  Name                 :  SendNodeCommand
	*  Description          :  Change the value of the global variable node flag 
	*  							that will be used by the Node_StateMachine to change its
	*  							state variable. 
	*  Parameters           :  T_UBYTE lub_NodeFlg
	*  								Possible values: CMD_DISABLE_SLV, CMD_ENABLE_SLV.
	*  Return               :  void
	*  -------------------------------------------------------------------------
	*/
	rub_NodeFlag = lub_NodeFlg;
	
}
