/*******************************************************************************************/
/*====================== COPYRIGHT (C) CVTE automotive Technology 2020 =====================*/
/*******************************************************************************************
* C Source	   : can_ccl.c
*
* Description  : Source file for CAN  Communication Control Layer module .
*
* Environment  : autosar 4.x SC1, Renesas RH850, Greenhills Multi 6.1.4
*
* Created_by   : MCU Platform team
*
*	 Rev 1.0.0		Dsl 24-11-2020
*	 Initial revision.
*
********************************************************************************************/
#include "Service_CanComm_ccl.h"
#include "Service_CanComm_il.h"


/*****************************************************************************
* Function   : CanCcl_InitPowerOn
* Description:
* Call       : Local
* Returns   : Nothing
******************************************************************************/
static void CanCcl_InitPowerOn( void )
{
	//CanIl_RxSignalTable_Init();
	//CanIl_TxSignalTable_Init();
	CanIl_MessageTable_Init();
    CanIl_StateInit();
	CanIl_RxStart();
	CanIl_TxStart();
}

/*****************************************************************************
* Function   : void CANNMAPP_vPoweronInit (void)
* Description:
* Call       : Local
* Returns   : Nothing
******************************************************************************/
void CanCcl_vPoweronInit(void)
{
    CanCcl_InitPowerOn();
}

/*****************************************************************************
* Function   : void CanCcl_vReset (void)
* Description: Called OS Reset container.
* Call       : Global
* Returns   : Nothing
******************************************************************************/
void CanCcl_vReset(void)
{
	CanCcl_vPoweronInit();
}

/*****************************************************************************
* Function   : CanCcl_vTickCntCallBack
* Description:
* Call       : Global
* Returns   : Nothing
******************************************************************************/
void CanCcl_TickCntHnadler(void)
{
	CanIl_TxTask();
    // CanIl_RxTask();
}





