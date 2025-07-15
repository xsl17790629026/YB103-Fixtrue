#ifndef _DBC_CAN_CORE_H_
#define _DBC_CAN_CORE_H_ 

#include "Service_CanComm_Include.h"
#include "APP_CAN_Include.h"

typedef enum
{
    E_CANSEND_OPEN,
    E_CANSEND_CLOSE
}CAN_SEND_STS;

extern void App_Init(void);
extern void CanTransmitFunction(void const *pvParameters);

#endif /* _DBC_CAN_CORE_H_ */