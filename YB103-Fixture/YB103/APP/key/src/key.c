#include "adc_app.h"
#include "lcd.h"
#include "usart.h"
#include "lcd12864_enum.h"
//#include "can_transmit.h"
#include "key.h"
#include "key_if.h"

#include "key_class.h"
#include "key_def.h"

#include "key_class.h"
#include "key_def.h"

uint8_t key_menu_cnt = 0U;
uint8_t key_item_cnt = 0U;
uint16_t key_value_cnt = 0U;
uint8_t Can_Send_Sts = 0u; //0:Send 1:No Send

static uint8_t swc_key_value  = KEY_SNA;
static uint8_t button_key_value = KEY_SNA;
static uint8_t radio_key_value = KEY_SNA;

void Key_CheckProcess(void)
{
	uint8_t i;
  
	for(i=0; i<KEY_MAX; i++)
	{
		volencode_polling(i);
		switch(stKeyValue[i].KeySts)
		{
			case RELEASE:
				if(i == CONFIRM)
				{
					// Event_Farm_Release();
				}
				break;
			case PRESS:
				if(i == CONFIRM)
				{
					// Event_Farm_Press(key_menu_cnt);
				}
				break;
			case SHORT_PRESS:
				ShortPress(i);
				break;
			case LONG_PRESS:
				break;
		}
	}

}

void volencode_polling(uint8_t key_number)
{

	int VolADValueFliter;
	static uint8_t count[KEY_MAX] = {0};
	static uint8_t lastcount[KEY_MAX] = {0};

    VolADValueFliter = ADC_GetResValue(stKeyValue[key_number].channel);

    if((stKeyValue[key_number].AdcValue < VolADValueFliter + VOL_ADVALUE_ERROR) && (stKeyValue[key_number].AdcValue > VolADValueFliter - VOL_ADVALUE_ERROR))
    {
        stKeyValue[key_number].KeySts = PRESS;
		count[key_number] += 1;
    }
    else
    {
        stKeyValue[key_number].KeySts = RELEASE;
		lastcount[key_number] = count[key_number];
		count[key_number] = 0;
    }

	if((lastcount[key_number] >= 2) && (lastcount[key_number] < 100))
	{
		stKeyValue[key_number].KeySts = SHORT_PRESS;
		lastcount[key_number] = 0;
	}
	else if(count[key_number] >= 100)
	{
		stKeyValue[key_number].KeySts = LONG_PRESS;
		lastcount[key_number] = 0;
	}
	else
	{
		lastcount[key_number] = 0;
	}

}

void ShortPress(uint8_t key)
{
	uint8_t MENU_MAX;
	uint8_t max_item;
	uint16_t max_value;
	if(now_page == 0){
		key_menu_cnt = GetPage0MenuIndex();
		MENU_MAX = Page0_MENU_MAX;
		max_item = GetPage0ItemMAXItem(key_menu_cnt);
	    max_value = GetPage0ItemMAXValue(key_menu_cnt, key_item_cnt);
	    key_item_cnt  = GetPage0ItemIndex();
	}
	else{
		key_menu_cnt = GetPage1MenuIndex();
		MENU_MAX = Page1_MENU_MAX;
		max_item = GetPage1ItemMAXItem(key_menu_cnt);
	    max_value = GetPage1ItemMAXValue(key_menu_cnt, key_item_cnt);
	    key_item_cnt  = GetPage1ItemIndex();
	}

	static uint8_t last_key_value_cnt = 0;

	switch(key)
	{
		case PREVIOUS:
			if(key_menu_cnt == 0)
			{
				key_menu_cnt = MENU_MAX-1;
			}
			else
			{
				key_menu_cnt--;
			}
      		key_item_cnt = 0;
      		if(now_page == 0){
    			key_value_cnt  = GetPage0ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
      		else{
      			key_value_cnt  = GetPage1ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
			break;
		case NEXT_PAGE:
			key_menu_cnt++;
			if(key_menu_cnt >= MENU_MAX)
			{
				key_menu_cnt = 0;
			}
			key_item_cnt = 0;
      		if(now_page == 0){
    			key_value_cnt  = GetPage0ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
      		else{
      			key_value_cnt  = GetPage1ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
			break;
		case REVERSE:
			key_menu_cnt = 0;
			key_item_cnt = 0;
      		if(now_page == 0){
    			key_value_cnt  = GetPage0ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
      		else{
      			key_value_cnt  = GetPage1ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
			break;
		case CANCEL:
			Can_Send_Sts = !Can_Send_Sts;
			Can_SendSts_Control(Can_Send_Sts);
			break;
		case UP:
			if(key_item_cnt == 0U)
			{
				key_item_cnt = max_item - 1;
			}
			else
			{
				key_item_cnt--;
			}
      		if(now_page == 0){
    			key_value_cnt  = GetPage0ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
      		else{
      			key_value_cnt  = GetPage1ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
			break;
		case DOWN:
			key_item_cnt++;
			if(key_item_cnt >=max_item)
			{
				key_item_cnt = 0;
			}
      		if(now_page == 0){
    			key_value_cnt  = GetPage0ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
      		else{
      			key_value_cnt  = GetPage1ItemValue(key_menu_cnt, key_item_cnt, 0);
      		}
			break;
		case CONFIRM:
			now_page = (now_page == 1) ? 0 : 1;
			key_menu_cnt = 0;
			key_item_cnt = 0;
			switch_flag = 1;
			break;
		case LEFT:
			if(key_value_cnt <= 0U)
            {
                if (ItemValueLimit(key_menu_cnt, key_item_cnt))
				{
                    key_value_cnt = 0;
				}
                else
				{
                    key_value_cnt = max_value-1;
				}
            }
			else
			{
				key_value_cnt--;
			}
			break;
		case RIGHT:
			key_value_cnt++;
            if (key_value_cnt >= max_value)
			{
                if (ItemValueLimit(key_menu_cnt, key_item_cnt)) 
				{
                    key_value_cnt = max_value -1;
				}
                else
				{
                    key_value_cnt = 0;
				}
            }
			break;
		default:
			break;
	}
}

// void Event_Farm_Press(uint8_t menu)
// {
// 	if(menu == BTON)
// 	{
// 		button_key_value = PRESS;
// 		key_value_cnt = 1;
// 	}
// 	else if(menu == RADIO)
// 	{
// 		radio_key_value = PRESS;
// 		key_value_cnt = 1;
// 	}
// 	else if(menu == SWC)
// 	{
// 		swc_key_value = PRESS;
// 		key_value_cnt = 1;
// 	}
// 	else
// 	{
// 		key_value_cnt = 0;
// 	}
// }

// void Event_Farm_Release(void)
// {
// 	if((key_menu_cnt == BTON) && (button_key_value == PRESS))
// 	{
// 		button_key_value = RELEASE;
// 		key_value_cnt = 0;
// 	}
// 	else if((key_menu_cnt == RADIO) && (radio_key_value == PRESS))
// 	{
// 		radio_key_value = RELEASE;
// 		key_value_cnt = 0;
// 	}
// 	else if((key_menu_cnt == SWC) && (swc_key_value == PRESS))
// 	{
// 		swc_key_value = RELEASE;
// 		key_value_cnt = 0;
// 	}
// }

