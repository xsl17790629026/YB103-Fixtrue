#ifndef     __KEY_H__
#define     __KEY_H__

#include "main.h"

#define CHANNEL_NUM        0x03u

#define VOL_ADVALUE_L       100
#define VOL_ADVALUE_M       2730
#define VOL_ADVALUE_H       1986

#define  VOL_ADVALUE_ERROR    100

#define KEY_PRESS       1
#define KEY_RELLEASE    0 
#define KEY_SNA         2   

extern uint8_t CAN_Send_sts;
extern uint8_t key_menu_cnt;
extern uint8_t key_item_cnt;
extern uint16_t key_value_cnt;

void ShortPress(uint8_t key);
void volencode_polling(uint8_t key_number);
void Event_Farm_Press(uint8_t menu);
void Event_Farm_Release(void);
extern void Key_CheckProcess(void);

#endif
