/*
 * Service_CanComm_il.h
 *
 *  Created on: 2024��9��19��
 *      Author: user
 */

#ifndef APP_CAN_CAN_IL_CAN_IL_H_
#define APP_CAN_CAN_IL_CAN_IL_H_

#include "Public_CanDataTypes.h"
#include <stdint.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0


#define CanGetApplConfirmationPtr(i)    			ilTxTable[i].ApplConfirmationFct
#define CanGetTxId(i)                               ilTxTable[i].canId
//#define CanPackFunc(i)                              ilTxTable[i].pPackFunc
#define CanGetDstData(i)                            ilTxTable[i].dstData
#define CanGetMsgLen(i)                             ilTxTable[i].msglen
#define CanGetTxHwPort(i)                           ilTxTable[i].Instance

#define ilTxConfirmationFlags(Index)  (CanMsgTxStateBufferPtr[Index].TxConfirmationFlags)
#define ilTxUpdateCounter(Index)      (CanMsgTxStateBufferPtr[Index].TxUpdateCounter)
#define ilTxState(Index)              (CanMsgTxStateBufferPtr[Index].TxState)
#define ilTxCyclicCounter(Index)      (CanMsgTxStateBufferPtr[Index].TxCyclicCounter)
#define ilTxEventCounter(Index)       (CanMsgTxStateBufferPtr[Index].TxEventCounter)
#define iEventMsgInfo(Index)          (CanMsgTxStateBufferPtr[Index].EventMsgInfo)
#define ilTxStartDelay(Index)         (CanMsgTxStateBufferPtr[Index].TxStartDelay)

#define BCAN_CAN_INSTANCE      1
#define CCAN1_CAN_INSTANCE     2

enum
{
	NO_EVENT_MSG_SEND,
	EVENT_MSG_SEND,
};



enum
{
	CAN_MSG_TIMEOUT = 0u,
	CAN_MSG_NO_TIMEOUT,
};


typedef enum
{
	CAN_TRANSMIT_MSG_SUCCS = 0,
	CAN_TRANSMIT_MSG_FILED,
}CAN_TX_STS;



typedef struct
{
	uint16_t signalindex;
	void     (*Can_Read)(void* pdata);
}CanRxSiganl_t;

typedef struct
{
	uint16_t signalindex;
	void     (*Can_Write)(void* pdata);
}CanTxSiganl_t;

extern CanMsgTxStateBuffer_Struct * CanMsgTxStateBufferPtr;
extern const CanRxMessageConfig_t *ilRxTable[];
extern uint16_t iBytesOfRxHandles[];
extern const CanTransmitConfig_t *ilTxTable;
extern uint8_t iBytesOfTxHandles;
extern void (*FuncTimeoutDetectHandler)(void);
extern void (*FuncRxIrqHandler)(uint8_t instance, uint32_t canId, uint8_t msgLen, uint8_t *data);
extern CanRxSiganl_t *ilRxSignalTable;
extern uint16_t ilRxSignalTableLen;
extern CanTxSiganl_t *ilTxSignalTable;
extern uint16_t ilTxSignalTableLen;

extern void CanIl_SetCanBusSts(void);
extern uint8_t CanIl_GetCanBusLost(void);
extern void CanIl_StateInit(void);
extern uint8_t CanIl_GetRxEnabled(void);
extern bool CanIl_TxState(void);
extern bool CanIl_RxState(void);
extern void CanIl_TxTask(void);
extern void CanIl_RxTask(void);
extern void CanIl_RxStart(void);
extern void CanIl_TxStart(void);
extern void CanIl_SendEventMsg(uint8_t ilTxHnd);
extern void CanIl_RxIrqHandler(uint8_t instance, uint32_t canId, uint8_t msgLen, uint8_t *data);
extern void CanIl_ReleaseTx( void );
extern void CanIl_TxStop( void );
extern void CanIl_RxStop( void );
extern void CanIl_WaitTx( void );
extern void* CanIl_GetRxCanConfigTableMsgData(uint8_t instance,uint16_t absolutelyindex);
//extern uint8_t CanIl_ReadSignal(uint16_t signal,void* pdata);
// extern uint8_t CanIl_WriteSignal(uint16_t signal,void* pdata);
// extern void CanIl_RxSignalTable_Init(void);
// extern void CanIl_TxSignalTable_Init(void);
extern void CanIl_MessageTable_Init(void);
extern uint8_t CanIl_ClearSignal(uint8_t signal);
extern void CanIl_EventMsgSend(uint8_t ilTxHnd);
extern void CanIl_SetTxStartAPPMsg(void);
extern void CanIl_SetTxStopAPPMsg(void);
extern void CanIl_SetTxStartNWMMsg(void);
extern void CanIl_SetTxStopNWMMsg(void);




#endif /* APP_CAN_CAN_IL_CAN_IL_H_ */
