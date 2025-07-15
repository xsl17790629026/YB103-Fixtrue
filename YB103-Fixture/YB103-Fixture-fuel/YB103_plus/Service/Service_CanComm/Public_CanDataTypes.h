/*************************************************************************************************
 *  Copyright (c) 2025,cviauto.co
 *  All rights reserved.
 *
 * @file name:    .h
 *
 * @description:
 *
 * @revision:
 *
 *     Rev.000    Bob     2025-01-12   1. New Create.
 *
 *************************************************************************************************/
#ifndef _PUBLIC_CANDATATYPES_H_
#define _PUBLIC_CANDATATYPES_H_

/*************************************************************************************************
 * Include Files
 *************************************************************************************************/
#include <stdint.h>
#include <stdbool.h>
/*************************************************************************************************
 * Macro definition
 ************************************************************************************************/
#define CANTIMEBASE              (5)
#define CAN_TIME_MS(CanTime)        (CanTime/CANTIMEBASE)

#define iTxCycSend          (uint8_t)0x01
#define iTxCycEveSend       (uint8_t)0x02
#define iTxEveSend          (uint8_t)0x04

#define SEND_APP_MSG								(1)
#define SEND_NWM_MSG								(1<<4)
#define SEND_ALL_MSG								(SEND_NWM_MSG|SEND_APP_MSG)

enum
{
	NO_MSG_ATTRIBUTE = 0u,
	APP_MSG_ATTRIBUTE = SEND_APP_MSG,
	NWM_MSG_ATTRIBUTE = SEND_NWM_MSG,
};


/*************************************************************************************************
 * Variable declaration
 ************************************************************************************************/


//-----------------------------------------------------------------------------------------------
//EcuAL Can install struct
typedef struct
{
	uint8_t (*pfn_Can0ReciveIsrHandle)(uint32_t CanId, uint8_t Dlc, uint8_t* pCanData);
	uint8_t (*pfn_Can1ReciveIsrHandle)(uint32_t CanId, uint8_t Dlc, uint8_t* pCanData);
}STRUCT_CAN_RECIVE_INIT_PARAM,*PTR_STRUCT_CAN_RECIVE_INIT_PARAM;

typedef struct
{
	uint8_t   MsgIndex;
	uint32_t  canId;
	uint8_t   msglen;
	uint8_t      *dstData;
	//int       (*pPackFunc) (uint8_t* dst_p, void* src_p, size_t size);
	//uint8_t   indirection;

	uint8_t   msgattribute;
	uint8_t   msgtype;
	uint8_t   startcycles;   //After CAN is enabled, the time when periodic packet timing is allowed to start
	uint8_t   updatecycles;  //CAN Indicates the interval at which the next frame is allowed to be sent
	uint8_t   cycliccycles;
	uint8_t   eventcycles;
	uint8_t   Instance;
	void      (*ApplConfirmationFct)(uint16_t txObject);
}CanTransmitConfig_t;


typedef struct
{
	uint8_t idx;
}CanSignalsConfig_t;

typedef struct CanMessageConfig CanRxMessageConfig_t;

typedef struct
{
	

	uint8_t u8MessageReceiveflag;/*报文接收标志位 - FALSE：报文未接收；TRUE：报文已接收*/
	uint16_t u8MessageTimeoutcount;/*计时器*/
	uint16_t u8MessageTimeoutMaxPeriod;/*最大超时周期ms*/
	uint8_t u8MessageTimeoutflag;/*报文超时标志位 - FALSE：报文未丢失；TRUE：报文丢失*/
	uint8_t u8MessageFirstReceivedFlag;/*报文首帧接收标志位 - FALSE：首帧未接收；TRUE：首帧已接收*/
	int     (*pMessageTimeFunc)   (const CanRxMessageConfig_t *pMessageConfig, uint8_t flag);/*设置报文接收标志位接口*/

	int                  (*pMessageTimeoutFunc)   (void);/*报文超时处理函数*/
	int                  (*pMessageRecoverFunc)   (void);/*报文超时恢复处理函数*/
}TimeoutConfig_t;

struct CanMessageConfig
{
    uint32_t             canId;
    uint8_t              msgLen;
	uint8_t              msgindex;
    uint8_t                 *dstData;
	//int                  (*pUnPackFunc)           (void *dst_p, const uint8_t *src_p, size_t size);
    int                  (*pApplCallbackFunc)     (const uint8_t *src_p, uint32_t size);
    //int                  (*pSignalTimeoutFunc)    (const CanSignalsConfig_t *pSignalConfig, uint32_t u32SignalsConfigNum, uint8_t onOff);
	
	
    TimeoutConfig_t      *pMessageTimeoutConfig;
    // CanSignalsConfig_t   *pSignalsConfigTable;
    // uint32_t             u32SignalsConfigNum;
};

typedef struct
{
    uint8_t Flag;
    uint8_t Time;
    uint8_t Counter;
}TxConfigInfoCyc;

typedef struct
{
	uint8_t eventtx_interval_time;
	uint8_t eventtx_cnt;
	uint8_t cyceventtx_interval_time;
}EventTxConfig_t;

typedef struct
{
	uint8_t TxConfirmationFlags;
	uint8_t TxUpdateCounter;
	volatile uint8_t TxState;
	uint8_t TxCyclicCounter;
	uint8_t TxEventCounter;
	TxConfigInfoCyc EventMsgInfo;
	uint8_t TxStartDelay;
}CanMsgTxStateBuffer_Struct;



typedef struct
{
    uint8_t (*GetAccState)(void);
    uint8_t (*GetAccLevel)(void);
    uint8_t (*GetIgnState)(void);
}STRUCT_ASRNM_INIT_FUNCS,*PTR_STRUCT_ASRNM_INIT_FUNCS;

/*************************************************************************************************
 * Variable declaration External
 ************************************************************************************************/




/*************************************************************************************************
 * Function declaration
 ************************************************************************************************/






/*************************************************************************************************
 * Function Definition
 ************************************************************************************************/


#endif//_PUBLIC_CANDATATYPES_H_
/*************************************************************************************************
 * End of File
*************************************************************************************************/
