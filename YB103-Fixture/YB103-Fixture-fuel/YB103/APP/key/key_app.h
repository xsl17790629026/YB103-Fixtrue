#ifndef __KEY_APP_H_
#define __KEY_APP_H_

#if 0

#include "main.h"

#define  VOL_ADVALUE_A        1660
#define  VOL_ADVALUE_C        4020

#define  VOL_ADVALUE_B   			1986
#define  VOL_ADVALUE_D 				2730

#define  VOL_ADVALUE_ERROR    100
#define  VOL_ADVALUE_NONE     0

typedef enum
{
    SNA = 0,
    Press = 1,
    Left = 2,
    Right = 3,
}Key_sts;

typedef enum
{
    SITE_NONE = 0,
    SITE_A = 1,
    SITE_C = 2,
    SITE_ABC_UP = 3,
    SITE_CBA_DOWN = 4,
}E_VolSite;

typedef struct
{
	uint8_t key_menu;
    uint8_t key_item;
	uint8_t key_value;
}key_chanel;

typedef union
{
  uint8_t key_sts[3];
	key_chanel key;
}key_chanel_struct;

extern uint8_t CAN_Send_sts;
extern uint8_t key_menu_cnt;
extern uint8_t key_item_cnt;
extern uint16_t key_value_cnt;

extern void Key_Rotary_CheckProcess(void);
void volencode_polling(uint8_t key_ch);

#endif

#endif


