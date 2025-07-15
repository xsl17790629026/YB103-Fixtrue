#ifndef _APP_CAN_T2_CANMSGPAR_H_
#define _APP_CAN_T2_CANMSGPAR_H_

#include "APP_CAN_Include.h"
#include "Public_CanDataTypes.h"

extern const CanTransmitConfig_t CanTransmitConfig_Table[];
extern CanMsgTxStateBuffer_Struct CanMsgTxStateBuffer[CanTxMsgIndex_Max];

#endif