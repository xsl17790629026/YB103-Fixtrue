#ifndef __GPIO_Service_H_
#define __GPIO_Service_H_

#include "main.h"
#include "gpio.h"

extern void GPIO_Service_ExtendPower_Set(uint8_t Powerstatus);

extern uint8_t GPIO_Service_Door_Get(void);
extern uint8_t GPIO_Service_Body_Get(void);
extern uint8_t GPIO_Service_Mute_Get(void);
extern uint8_t GPIO_Service_Parking_Get(void);
extern uint8_t GPIO_Service_Reverse_Get(void);
extern uint8_t GPIO_Service_ILL_Get(void);
extern uint8_t GPIO_Service_ACC_Get(void);
#endif

