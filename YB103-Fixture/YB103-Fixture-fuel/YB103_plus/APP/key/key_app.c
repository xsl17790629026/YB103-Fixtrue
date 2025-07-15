#if 0

#include "key_app.h"
#include "adc_app.h"
#include "lcd12864.h"
#include "usart.h"

uint8_t SWC_Send = 0U;
key_chanel_struct KEY_Status = {0};
uint8_t key_menu_cnt = 0U;
uint8_t key_item_cnt = 0U;
uint16_t key_value_cnt = 0U;
uint8_t Can_Send_Sts = 0u; //0:Send 1:No Send
uint8_t CandSts_press_Sts = 0u;

typedef enum
{
    E_NO_PRESS,
    E_PRESS
}CANSTS_PRESS_STS;

void Key_Rotary_CheckProcess(void)
{
	uint8_t i;
	KEY_Status.key.key_menu = SNA;
	KEY_Status.key.key_item = SNA;
	KEY_Status.key.key_value = SNA;
    
	key_menu_cnt = GetMenuIndex();
    key_item_cnt  = GetItemIndex();

	for(i=0; i<CHANNEL_NUM; i++)
	{
		volencode_polling(i);
	}
    //printf("%d %d %d\r\n",KEY_Status.key.key_menu,KEY_Status.key.key_item,KEY_Status.key.key_value);
	switch(KEY_Status.key.key_menu)
	{
		case Right:
			key_menu_cnt++;
			if(key_menu_cnt >= MENU_MAX)
				key_menu_cnt = 0;
			key_item_cnt = 0;
		break;
		case Left:
			if(key_menu_cnt > 0U)
				key_menu_cnt = key_menu_cnt-1;
			else
				key_menu_cnt = MENU_MAX-1;
      key_item_cnt = 0;
		break;
		case Press:
		key_menu_cnt = 0;
		key_item_cnt = 0;
		break;
		default:
			break;/****do nothing*****/
	}	

    uint8_t max_item = GetItemMAXItem(key_menu_cnt);
	
	switch(KEY_Status.key.key_item)
	{
		case Left:
			key_item_cnt++;
			if(key_item_cnt >=max_item)
				key_item_cnt = 0;
            break;
		case Right:
			if(key_item_cnt >0U)
				key_item_cnt = key_item_cnt-1;
			else
					key_item_cnt = max_item - 1;
            break;
		case Press:
            if(CandSts_press_Sts == E_NO_PRESS)
            {
                CandSts_press_Sts = E_PRESS;
                Can_Send_Sts = !Can_Send_Sts;
               // Can_SendSts_Control(Can_Send_Sts);
            }
            break;
		default:
            CandSts_press_Sts = E_NO_PRESS;
			break;/****do nothing*****/
	}	
    key_value_cnt  = GetItemValue(key_menu_cnt, key_item_cnt, 0);
	// static uint8_t swc_key_value  = SWC_SNA;
    uint16_t max_value = GetItemMAXValue(key_menu_cnt, key_item_cnt);
	switch(KEY_Status.key.key_value)
	{
		case Left:
			key_value_cnt++;
            if (key_value_cnt >= max_value){
                if (ItemValueLimit(key_menu_cnt, key_item_cnt)) 
                    key_value_cnt = max_value -1;
                else
                    key_value_cnt = 0;
            }
            break;
		case Right:
            if(key_value_cnt > 0U)
                key_value_cnt = key_value_cnt-1;
            else {
                if (ItemValueLimit(key_menu_cnt, key_item_cnt)) 
                    key_value_cnt = 0;
                else
                    key_value_cnt = max_value-1;
            }
		break;
		case Press:
//            if (key_menu_cnt == SWC){
//				if(swc_key_value != SWC_PRESS)	
//                {
//                    SWC_Send = 0x01U;
//                }                    
//				swc_key_value = SWC_PRESS;
//				key_value_cnt = 1;
//			}
//            else
//                key_value_cnt = 0;
            break;
		default:
//			if((key_menu_cnt == SWC) && (swc_key_value == SWC_PRESS)){
//				swc_key_value = SWC_RELEASE;
//				SWC_Send = 0x02U;
//				key_value_cnt = 0;
//                //sendflag[TX_SWCOMMAND_PLUS_FRAME] = 1;
//			}
			break;/****do nothing*****/
	}	

}

void volencode_polling(uint8_t key_ch)
{

	uint32_t VolADValueFliter;
	uint32_t VolADvalueFinal;
	static uint8_t VolSiteBak1[3] = {0};
	static uint8_t VolSiteBak2[3] = {0};
    uint8_t key_channel = key_ch;
	
    VolADValueFliter = ADC_GetResValue(key_ch);

    // printf("ch%d:%d\r\n",key_ch,VolADValueFliter);
    if((VolADValueFliter  <= VOL_ADVALUE_A + VOL_ADVALUE_ERROR) &&(VolADValueFliter  >= VOL_ADVALUE_A - VOL_ADVALUE_ERROR))
        VolADvalueFinal  = VOL_ADVALUE_A;
    else if((VolADValueFliter  <= VOL_ADVALUE_C + VOL_ADVALUE_ERROR) &&(VolADValueFliter  >= VOL_ADVALUE_C - VOL_ADVALUE_ERROR))
        VolADvalueFinal  = VOL_ADVALUE_C;
    else if((VolADValueFliter  <= VOL_ADVALUE_B + VOL_ADVALUE_ERROR) &&(VolADValueFliter  >= VOL_ADVALUE_B - VOL_ADVALUE_ERROR))
        VolADvalueFinal  = VOL_ADVALUE_B;
    else if((VolADValueFliter  <= VOL_ADVALUE_D + VOL_ADVALUE_ERROR) &&(VolADValueFliter  >= VOL_ADVALUE_D - VOL_ADVALUE_ERROR))
        VolADvalueFinal  = VOL_ADVALUE_D;
	else if((VolADValueFliter  <= 0x20) && (VolADValueFliter  >= 0x0A))
		KEY_Status.key_sts[key_channel] = Press;
    else
        VolADvalueFinal  = VOL_ADVALUE_NONE;

    //----------------------------------------------------------------------------------------------------------------
	if(VolADvalueFinal  == VOL_ADVALUE_B || VolADvalueFinal  == VOL_ADVALUE_D)
	{
	    if(VolADvalueFinal  == VOL_ADVALUE_B)
	        VolSiteBak2[key_channel]  = SITE_ABC_UP;
	    else
	        VolSiteBak2[key_channel]  = SITE_CBA_DOWN;
			
		if((VolSiteBak1[key_channel] == SITE_A && VolSiteBak2[key_channel] == SITE_ABC_UP ) ||(VolSiteBak1[key_channel] == SITE_C && VolSiteBak2[key_channel] == SITE_CBA_DOWN ))
			KEY_Status.key_sts[key_channel]  = Right;
	    else if((VolSiteBak1[key_channel]  == SITE_C && VolSiteBak2[key_channel] == SITE_ABC_UP ) ||(VolSiteBak1[key_channel] == SITE_A && VolSiteBak2[key_channel]  == SITE_CBA_DOWN ))
            KEY_Status.key_sts[key_channel]  = Left;

		VolSiteBak1[key_channel]  = SITE_NONE;
		VolSiteBak2[key_channel]  = SITE_NONE;
        VolADvalueFinal  = VOL_ADVALUE_NONE;
	}
	else if(VolADvalueFinal  == VOL_ADVALUE_A || VolADvalueFinal  == VOL_ADVALUE_C)
	{
	    if(VolADvalueFinal  == VOL_ADVALUE_A)
	        VolSiteBak1[key_channel]  = SITE_A;
	    else
	        VolSiteBak1[key_channel] = SITE_C;
	    VolADvalueFinal  = VOL_ADVALUE_NONE;
	}

}

#endif
