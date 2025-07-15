#include "main.h"
#include "lcd12864.h"
#include "Service_CanComm_il.h"
extern uint8_t g_Page0menu_index;
extern uint8_t g_Page0item_index;

extern uint8_t g_Page1menu_index;
extern uint8_t g_Page1item_index;

static uint32_t crash_flag = 0;
static uint8_t first_crash_flag = 0;

uint32_t GetPage0ItemValue(uint8_t menu, uint8_t item, uint8_t really_value)
{
    uint32_t res = 0U;
    switch(menu)
    {
        case ACU_1:
            if(item < ACU_1_ITEM_MAX)
            {
                res = g_ACU_1[item];
            }
            break;
        case ESP_2:
            if(item < ESP_2_ITEM_MAX)
            {
                res = g_ESP_2[item];
            }
            break;
        case ABS_1:
            if(item < ABS_1_ITEM_MAX)
            {
                res = g_ABS_1[item];
            }
            break;
        case ABS_2:
            if(item < ABS_2_ITEM_MAX)
            {
                res = g_ABS_2[item];
            }
            break;
        case TPMS_1:
            if(item < TPMS_1_ITEM_MAX)
            {
                res = g_TPMS_1[item];
            }
            break;
        case BCM_1:
            if(item < BCM_1_ITEM_MAX)
            {
                res = g_BCM_1[item];
            }
            break;
        case BCM_3:
            if(item < BCM_3_ITEM_MAX)
            {
                res = g_BCM_3[item];
            }
            break;
        case BCM_4:
            if(item < BCM_4_ITEM_MAX)
            {
                res = g_BCM_4[item];
            }
            break;
        case BCM_5:
            if(item < BCM_5_ITEM_MAX)
            {
                res = g_BCM_5[item];
            }
            break;
        case PEPS_3:
            if(item < PEPS_3_ITEM_MAX)
            {
                res = g_PEPS_3[item];
            }
            break;
        case TBOX_1:
            if(item < TBOX_1_ITEM_MAX)
            {
                res = g_TBOX_1[item];
            }
            break;
        case TBOX_2:
            if(item < TBOX_2_ITEM_MAX)
            {
                res = g_TBOX_2[item];
            }
            break;
        case TBOX_4:
            if(item < TBOX_4_ITEM_MAX)
            {
                res = g_TBOX_4[item];
            }
            break;
        case FCM_3:
            if(item < FCM_3_ITEM_MAX)
            {
                res = g_FCM_3[item];
            }
            break;
        case FCM_4:
            if(item < FCM_4_ITEM_MAX)
            {
                res = g_FCM_4[item];
            }
            break;
        case FCM_5:
            if(item < FCM_5_ITEM_MAX)
            {
                res = g_FCM_5[item];
            }
            break;
        case FCM_6:
            if(item < FCM_6_ITEM_MAX)
            {
                res = g_FCM_6[item];
            }
            break;
        case FCM_7:
            if(item < FCM_7_ITEM_MAX)
            {
                res = g_FCM_7[item];
            }
            break;
        case FCM_8:
            if(item < FCM_8_ITEM_MAX)
            {
                res = g_FCM_8[item];
            }
            break;
        case GW_PC_1:
            if(item < GW_PC_1_ITEM_MAX)
            {
                res = g_GW_PC_1[item];
            }
            break;
        case GW_PC_6:
            if(item < GW_PC_6_ITEM_MAX)
            {
                res = g_GW_PC_6[item];
            }
            break;
        case GW_PC_2:
            if(item < GW_PC_2_ITEM_MAX)
            {
                res = g_GW_PC_2[item];
            }
            break;
        case GW_PC_7:
            if(item < GW_PC_7_ITEM_MAX)
            {
                res = g_GW_PC_7[item];
            }
            break;
        case GW_PC_4:
            if(item < GW_PC_4_ITEM_MAX)
            {
                res = g_GW_PC_4[item];
            }
            break;
        case GW_BD_9:
            if(item < GW_BD_9_ITEM_MAX)
            {
                res = g_GW_BD_9[item];
            }
            break;
        case GW_BD_14:
            if(item < GW_BD_14_ITEM_MAX)
            {
                res = g_GW_BD_14[item];
            }
            break;
        case GW_BD_24:
            if(item < GW_BD_24_ITEM_MAX)
            {
                res = g_GW_BD_24[item];
            }
            break;
        case GW_BD_29:
            if(item < GW_BD_29_ITEM_MAX)
            {
                res = g_GW_BD_29[item];
            }
            break;
        default:
            break;
    }
    return res;
}

uint32_t GetPage1ItemValue(uint8_t menu, uint8_t item, uint8_t really_value){
    uint32_t res = 0U;
    switch(menu)
    {
        case F1:
            if(item < F1_ITEM_MAX)
            {
                res = g_F1[item];
            }
            break;
        case F2:
            if(item < F2_ITEM_MAX)
            {
                res = g_F2[item];
            }
            break;
        case F3:
            if(item < F3_ITEM_MAX)
            {
                res = g_F3[item];
            }
            break;
        case F4:
            if(item < F4_ITEM_MAX)
            {
                res = g_F4[item];
            }
            break;
        case F5:
            if(item < F5_ITEM_MAX)
            {
                res = g_F5[item];
            }
            break;
        case F6:
            if(item < F6_ITEM_MAX)
            {
                res = g_F6[item];
            }
            break;
        case F7:
            if(item < F7_ITEM_MAX)
            {
                res = g_F7[item];
            }
            break;
        case F8:
            if(item < F8_ITEM_MAX)
            {
                res = g_F8[item];
            }
            break;
        case F9:
            if(item < F9_ITEM_MAX)
            {
                res = g_F9[item];
            }
            break;
        case F10:
            if(item < F10_ITEM_MAX)
            {
                res = g_F10[item];
            }
            break;
        case F11:
            if(item < F11_ITEM_MAX)
            {
                res = g_F11[item];
            }
            break;
        case F12:
            if(item < F12_ITEM_MAX)
            {
                res = g_F12[item];
            }
            break;
        case F13:
            if(item < F13_ITEM_MAX)
            {
                res = g_F13[item];
            }
            break;
        case F14:
            if(item < F14_ITEM_MAX)
            {
                res = g_F14[item];
            }
            break;
        case F15:
            if(item < F15_ITEM_MAX)
            {
                res = g_F15[item];
            }
            break;
        case F16:
            if(item < F16_ITEM_MAX)
            {
                res = g_F16[item];
            }
            break;
        case F17:
            if(item < F17_ITEM_MAX)
            {
                res = g_F17[item];
            }
            break;
        case F18:
            if(item < F18_ITEM_MAX)
            {
                res = g_F18[item];
            }
            break;
        case F19:
            if(item < F19_ITEM_MAX)
            {
                res = g_F19[item];
            }
            break;
        case F20:
            if(item < F20_ITEM_MAX)
            {
                res = g_F20[item];
            }
            break;
        case F21:
            if(item < F21_ITEM_MAX)
            {
                res = g_F21[item];
            }
            break;
        case F22:
            if(item < F22_ITEM_MAX)
            {
                res = g_F22[item];
            }
            break;
        case F23:
            if(item < F23_ITEM_MAX)
            {
                res = g_F23[item];
            }
            break;
        case F24:
            if(item < F24_ITEM_MAX)
            {
                res = g_F24[item];
            }
            break;
        case F25:
            if(item < F25_ITEM_MAX)
            {
                res = g_F25[item];
            }
            break;
        case F26:
            if(item < F26_ITEM_MAX)
            {
                res = g_F26[item];
            }
            break;
        case F27:
            if(item < F27_ITEM_MAX)
            {
                res = g_F27[item];
            }
            break;
        case F28:
            if(item < F28_ITEM_MAX)
            {
                res = g_F28[item];
            }
            break;
        case F29:
            if(item < F29_ITEM_MAX)
            {
                res = g_F29[item];
            }
            break;
        case F30:
            if(item < F30_ITEM_MAX)
            {
                res = g_F30[item];
            }
            break;
        default:
            break;
    	}
    return res;
}

uint8_t GetPage0ItemMAXItem(uint8_t menu)
{
    uint8_t temp = 0U;
    switch(menu)
    {
        case ACU_1:
            temp = ACU_1_ITEM_MAX;
            break;
        case ESP_2:
            temp = ESP_2_ITEM_MAX;
            break;
        case ABS_1:
            temp = ABS_1_ITEM_MAX;
            break;
        case ABS_2:
            temp = ABS_2_ITEM_MAX;
            break;
        case TPMS_1:
            temp = TPMS_1_ITEM_MAX;
            break;
        case BCM_1:
            temp = BCM_1_ITEM_MAX;
            break;
        case BCM_3:
            temp = BCM_3_ITEM_MAX;
            break;
        case BCM_4:
            temp = BCM_4_ITEM_MAX;
            break;
        case BCM_5:
            temp = BCM_5_ITEM_MAX;
            break;
        case PEPS_3:
            temp = PEPS_3_ITEM_MAX;
            break;
        case TBOX_1:
            temp = TBOX_1_ITEM_MAX;
            break;
        case TBOX_2:
            temp = TBOX_2_ITEM_MAX;
            break;
        case TBOX_4:
            temp = TBOX_4_ITEM_MAX;
            break;
        case FCM_3:
            temp = FCM_3_ITEM_MAX;
            break;
        case FCM_4:
            temp = FCM_4_ITEM_MAX;
            break;
        case FCM_5:
            temp = FCM_5_ITEM_MAX;
            break;
        case FCM_6:
            temp = FCM_6_ITEM_MAX;
            break;
        case FCM_7:
            temp = FCM_7_ITEM_MAX;
            break;
        case FCM_8:
            temp = FCM_8_ITEM_MAX;
            break;
        case GW_PC_1:
            temp = GW_PC_1_ITEM_MAX;
            break;
        case GW_PC_6:
            temp = GW_PC_6_ITEM_MAX;
            break;
        case GW_PC_2:
            temp = GW_PC_2_ITEM_MAX;
            break;
        case GW_PC_7:
            temp = GW_PC_7_ITEM_MAX;
            break;
        case GW_PC_4:
            temp = GW_PC_4_ITEM_MAX;
            break;
        case GW_BD_9:
            temp = GW_BD_9_ITEM_MAX;
            break;
        case GW_BD_14:
            temp = GW_BD_14_ITEM_MAX;
            break;
        case GW_BD_24:
            temp = GW_BD_24_ITEM_MAX;
            break;
        case GW_BD_29:
            temp = GW_BD_29_ITEM_MAX;
            break;
        default:
            break;
    }
    return temp;
}

uint8_t GetPage1ItemMAXItem(uint8_t menu)
{
    uint8_t temp = 0U;
    switch(menu){
        case F1:
            temp = F1_ITEM_MAX;
            break;
        case F2:
            temp = F2_ITEM_MAX;
            break;
        case F3:
            temp = F3_ITEM_MAX;
            break;
        case F4:
            temp = F4_ITEM_MAX;
            break;
        case F5:
            temp = F5_ITEM_MAX;
            break;
        case F6:
            temp = F6_ITEM_MAX;
            break;
        case F7:
            temp = F7_ITEM_MAX;
            break;
        case F8:
            temp = F8_ITEM_MAX;
            break;
        case F9:
            temp = F9_ITEM_MAX;
            break;
        case F10:
            temp = F10_ITEM_MAX;
            break;
        case F11:
            temp = F11_ITEM_MAX;
            break;
        case F12:
            temp = F12_ITEM_MAX;
            break;
        case F13:
            temp = F13_ITEM_MAX;
            break;
        case F14:
            temp = F14_ITEM_MAX;
            break;
        case F15:
            temp = F15_ITEM_MAX;
            break;
        case F16:
            temp = F16_ITEM_MAX;
            break;
        case F17:
            temp = F17_ITEM_MAX;
            break;
        case F18:
            temp = F18_ITEM_MAX;
            break;
        case F19:
            temp = F19_ITEM_MAX;
            break;
        case F20:
            temp = F20_ITEM_MAX;
            break;
        case F21:
            temp = F21_ITEM_MAX;
            break;
        case F22:
            temp = F22_ITEM_MAX;
            break;
        case F23:
            temp = F23_ITEM_MAX;
            break;
        case F24:
            temp = F24_ITEM_MAX;
            break;
        case F25:
            temp = F25_ITEM_MAX;
            break;
        case F26:
            temp = F26_ITEM_MAX;
            break;
        case F27:
            temp = F27_ITEM_MAX;
            break;
        case F28:
            temp = F28_ITEM_MAX;
            break;
        case F29:
            temp = F29_ITEM_MAX;
            break;
        case F30:
            temp = F30_ITEM_MAX;
            break;
        default:
            break;
    }
    return temp;
}

uint32_t GetPage0ItemMAXValue(uint8_t menu, uint8_t item)
{
    uint32_t res = 0U;
    switch(menu)
    {
        case ACU_1:
            res = ACU_1Max[item];
            break;
        case ESP_2:
            res = ESP_2Max[item];
            break;
        case ABS_1:
            res = ABS_1Max[item];
            break;
        case ABS_2:
            res = ABS_2Max[item];
            break;
        case TPMS_1:
            res = TPMS_1Max[item];
            break;
        case BCM_1:
            res = BCM_1Max[item];
            break;
        case BCM_3:
            res = BCM_3Max[item];
            break;
        case BCM_4:
            res = BCM_4Max[item];
            break;
        case BCM_5:
            res = BCM_5Max[item];
            break;
            break;
        case PEPS_3:
            res = PEPS_3Max[item];
            break;
        case TBOX_1:
            res = TBOX_1Max[item];
            break;
        case TBOX_2:
            res = TBOX_2Max[item];
            break;
        case TBOX_4:
            res = TBOX_4Max[item];
            break;
        case FCM_3:
            res = FCM_3Max[item];
            break;
        case FCM_4:
            res = FCM_4Max[item];
            break;
        case FCM_5:
            res = FCM_5Max[item];
            break;
        case FCM_6:
            res = FCM_6Max[item];
            break;
        case FCM_7:
            res = FCM_7Max[item];
            break;
        case FCM_8:
            res = FCM_8Max[item];
            break;
        case GW_PC_1:
            res = GW_PC_1Max[item];
            break;
        case GW_PC_6:
            res = GW_PC_6Max[item];
            break;
        case GW_PC_2:
            res = GW_PC_2Max[item];
            break;
        case GW_PC_7:
            res = GW_PC_7Max[item];
            break;
        case GW_PC_4:
            res = GW_PC_4Max[item];
            break;
        case GW_BD_9:
            res = GW_BD_9Max[item];
            break;
        case GW_BD_14:
            res = GW_BD_14Max[item];
            break;
        case GW_BD_24:
            res = GW_BD_24Max[item];
            break;
        case GW_BD_29:
            res = GW_BD_29Max[item];
            break;
        default:
            break;
    }
    return res;
}

uint32_t GetPage1ItemMAXValue(uint8_t menu, uint8_t item)
{
    uint32_t res = 0U;
    switch(menu)
    {
		case F1:
			res = F1Max[item];
			break;
		case F2:
			res = F2Max[item];
			break;
		case F3:
			res = F3Max[item];
			break;
		case F4:
			res = F4Max[item];
			break;
		case F5:
			res = F5Max[item];
			break;
		case F6:
			res = F6Max[item];
			break;
		case F7:
			res = F7Max[item];
			break;
		case F8:
			res = F8Max[item];
			break;
		case F9:
			res = F9Max[item];
			break;
		case F10:
			res = F10Max[item];
			break;
		case F11:
			res = F11Max[item];
			break;
		case F12:
			res = F12Max[item];
			break;
		case F13:
			res = F13Max[item];
			break;
		case F14:
			res = F14Max[item];
			break;
		case F15:
			res = F15Max[item];
			break;
		case F16:
			res = F16Max[item];
			break;
		case F17:
			res = F17Max[item];
			break;
		case F18:
			res = F18Max[item];
			break;
		case F19:
			res = F19Max[item];
			break;
		case F20:
			res = F20Max[item];
			break;
		case F21:
			res = F21Max[item];
			break;
		case F22:
			res = F22Max[item];
			break;
		case F23:
			res = F23Max[item];
			break;
		case F24:
			res = F24Max[item];
			break;
		case F25:
			res = F25Max[item];
			break;
		case F26:
			res = F26Max[item];
			break;
		case F27:
			res = F27Max[item];
			break;
		case F28:
			res = F28Max[item];
			break;
		case F29:
			res = F29Max[item];
			break;
		case F30:
			res = F30Max[item];
			break;
		default:
			break;
    }
    return res;
}

void SavePage0ItemValue(Pagedis_Page0 menu, uint8_t item, int16_t value)
{
	g_Page0menu_index = GET_MENU(menu, Page0_MENU_MAX);
    switch (g_Page0menu_index)
    {
        case ACU_1:
            value = CHECK_VALUE(value, ACU_1Max[item]);
            g_ACU_1[item] = value;
            break;
        case ESP_2:
            value = CHECK_VALUE(value, ESP_2Max[item]);
            g_ESP_2[item] = value;
            break;
        case ABS_1:
            value = CHECK_VALUE(value, ABS_1Max[item]);
            g_ABS_1[item] = value;
            break;
        case ABS_2:
            value = CHECK_VALUE(value, ABS_2Max[item]);
            g_ABS_2[item] = value;
            break;
        case TPMS_1:
            value = CHECK_VALUE(value, TPMS_1Max[item]);
            g_TPMS_1[item] = value;
            break;
        case BCM_1:
            value = CHECK_VALUE(value, BCM_1Max[item]);
            g_BCM_1[item] = value;
            break;
        case BCM_3:
            value = CHECK_VALUE(value, BCM_3Max[item]);
            g_BCM_3[item] = value;
            break;
        case BCM_4:
            value = CHECK_VALUE(value, BCM_4Max[item]);
            g_BCM_4[item] = value;
            break;
        case BCM_5:
            value = CHECK_VALUE(value, BCM_5Max[item]);
            g_BCM_5[item] = value;
            break;
        case PEPS_3:
            value = CHECK_VALUE(value, PEPS_3Max[item]);
            g_PEPS_3[item] = value;
            break;
        case TBOX_1:
            value = CHECK_VALUE(value, TBOX_1Max[item]);
            g_TBOX_1[item] = value;
            break;
        case TBOX_2:
            value = CHECK_VALUE(value, TBOX_2Max[item]);
            g_TBOX_2[item] = value;
            break;
        case TBOX_4:
            value = CHECK_VALUE(value, TBOX_4Max[item]);
            g_TBOX_4[item] = value;
            break;
        case FCM_3:
            value = CHECK_VALUE(value, FCM_3Max[item]);
            g_FCM_3[item] = value;
            break;
        case FCM_4:
            value = CHECK_VALUE(value, FCM_4Max[item]);
            g_FCM_4[item] = value;
            break;
        case FCM_5:
            value = CHECK_VALUE(value, FCM_5Max[item]);
            g_FCM_5[item] = value;
            break;
        case FCM_6:
            value = CHECK_VALUE(value, FCM_6Max[item]);
            g_FCM_6[item] = value;
            break;
        case FCM_7:
            value = CHECK_VALUE(value, FCM_7Max[item]);
            g_FCM_7[item] = value;
            break;
        case FCM_8:
            value = CHECK_VALUE(value, FCM_8Max[item]);
            g_FCM_8[item] = value;
            break;
        case GW_PC_1:
            value = CHECK_VALUE(value, GW_PC_1Max[item]);
            g_GW_PC_1[item] = value;
            break;
        case GW_PC_6:
            value = CHECK_VALUE(value, GW_PC_6Max[item]);
            g_GW_PC_6[item] = value;
            break;
        case GW_PC_2:
			value = CHECK_VALUE(value, GW_PC_2Max[item]);
			g_GW_PC_2[item] = value;
            break;
        case GW_PC_7:
            value = CHECK_VALUE(value, GW_PC_7Max[item]);
            g_GW_PC_7[item] = value;
            break;
        case GW_PC_4:
            value = CHECK_VALUE(value, GW_PC_4Max[item]);
            g_GW_PC_4[item] = value;
            break;
        case GW_BD_9:
            value = CHECK_VALUE(value, GW_BD_9Max[item]);
            g_GW_BD_9[item] = value;
            break;
        case GW_BD_14:
            value = CHECK_VALUE(value, GW_BD_14Max[item]);
            g_GW_BD_14[item] = value;
            break;
        case GW_BD_24:
            value = CHECK_VALUE(value, GW_BD_24Max[item]);
            g_GW_BD_24[item] = value;
            break;
        case GW_BD_29:
            value = CHECK_VALUE(value, GW_BD_29Max[item]);
            g_GW_BD_29[item] = value;
            break;
        default:
            break;
    }
    g_Page0item_index = item;
}

void SavePage1ItemValue(Pagedis_Page1 menu, uint8_t item, int16_t value)
{
	g_Page1menu_index = GET_MENU(menu, Page1_MENU_MAX);
	switch (g_Page1menu_index)
	    {
	    case F1:
	        value = CHECK_VALUE(value, F1Max[item]);
	        g_F1[item] = value;
	        break;
	    case F2:
	        value = CHECK_VALUE(value, F2Max[item]);
	        g_F2[item] = value;
	        break;
	    case F3:
	        value = CHECK_VALUE(value, F3Max[item]);
	        g_F3[item] = value;
			if(item == F3_ABS_3_VehicleSpeed || item == F3_ABS_3_VehicleSpeedValid || item == F3_ABS_3_Timeout_Flag){
				g_F1[item] = g_F3[item];
			}
			else if(item == F3_EMS_2_EngineSpeed || item == F3_EMS_2_EngineSpeedValid || item == F3_EMS_2_Timeout_Flag){
				g_F2[item - 3] = g_F3[item];
			}
	        break;
	    case F4:
	        value = CHECK_VALUE(value, F4Max[item]);
	        g_F4[item] = value;
	        break;
	    case F5:
	        value = CHECK_VALUE(value, F5Max[item]);
	        g_F5[item] = value;
			if(item == F5_ABS_3_VehicleSpeed || item == F5_ABS_3_VehicleSpeedValid || item == F5_ABS_3_Timeout_Flag){
				g_F1[item] = g_F5[item];
			}
	        break;
	    case F6:
	        value = CHECK_VALUE(value, F6Max[item]);
	        g_F6[item] = value;
			if(item == F6_ABS_3_VehicleSpeed || item == F6_ABS_3_VehicleSpeedValid || item == F6_ABS_3_Timeout_Flag){
				g_F1[item] = g_F6[item];
			}
			else if(item == F6_EMS_2_EngineSpeed || item == F6_EMS_2_EngineSpeedValid || item == F6_EMS_2_Timeout_Flag){
				g_F2[item - 3] = g_F6[item];
			}
			else if(item == F6_EMS_4_Timeout_Flag){
				g_F4[EMS_4_Timeout_Flag] = g_F6[F6_EMS_4_Timeout_Flag];
			}
	        break;
	    case F7:
	        value = CHECK_VALUE(value, F7Max[item]);
	        g_F7[item] = value;
			if(item == F7_ABS_3_VehicleSpeed || item == F7_ABS_3_VehicleSpeedValid || item == F7_ABS_3_Timeout_Flag){
				g_F1[item] = g_F7[item];
			}
			else if(item == F7_EMS_2_EngineSpeed || item == F7_EMS_2_EngineSpeedValid || item == F7_EMS_2_Timeout_Flag){
				g_F2[item - 3] = g_F7[item];
			}
			else if(item == F7_EMS_4_Timeout_Flag){
				g_F4[EMS_4_Timeout_Flag] = g_F7[F7_EMS_4_Timeout_Flag];
			}
			else if(item == F7_EMS_4_FuelConsumption){
				g_F6[EMS_4_FuelConsumption] = g_F7[F7_EMS_4_FuelConsumption];
			}
	        break;
	    case F8:
	        value = CHECK_VALUE(value, F8Max[item]);
	        g_F8[item] = value;
	        break;
	    case F9:
	        value = CHECK_VALUE(value, F9Max[item]);
	        g_F9[item] = value;
	        break;
	    case F10:
	        value = CHECK_VALUE(value, F10Max[item]);
	        g_F10[item] = value;
	        break;
	    case F11:
	        value = CHECK_VALUE(value, F11Max[item]);
	        g_F11[item] = value;
	        break;
	    case F12:
	        value = CHECK_VALUE(value, F12Max[item]);
	        g_F12[item] = value;
	        break;
	    case F13:
	        value = CHECK_VALUE(value, F13Max[item]);
	        g_F13[item] = value;
	        break;
	    case F14:
	        value = CHECK_VALUE(value, F14Max[item]);
	        g_F14[item] = value;
	        break;
	    case F15:
	        value = CHECK_VALUE(value, F15Max[item]);
	        g_F15[item] = value;
	        break;
	    case F16:
	        value = CHECK_VALUE(value, F16Max[item]);
	        g_F16[item] = value;
	        break;
	    case F17:
	        value = CHECK_VALUE(value, F17Max[item]);
	        g_F17[item] = value;
	        break;
	    case F18:
	        value = CHECK_VALUE(value, F18Max[item]);
	        g_F18[item] = value;
	        break;
	    case F19:
	        value = CHECK_VALUE(value, F19Max[item]);
	        g_F19[item] = value;
	        break;
	    case F20:
	        value = CHECK_VALUE(value, F20Max[item]);
	        g_F20[item] = value;
	        break;
	    case F21:
	        value = CHECK_VALUE(value, F21Max[item]);
	        g_F21[item] = value;
	        break;
	    case F22:
	        value = CHECK_VALUE(value, F22Max[item]);
	        g_F22[item] = value;
	        break;
	    case F23:
	        value = CHECK_VALUE(value, F23Max[item]);
	        g_F23[item] = value;
	        break;
	    case F24:
	        value = CHECK_VALUE(value, F24Max[item]);
	        g_F24[item] = value;
	        break;
	    case F25:
	        value = CHECK_VALUE(value, F25Max[item]);
	        g_F25[item] = value;
	        break;
	    case F26:
	        value = CHECK_VALUE(value, F26Max[item]);
	        g_F26[item] = value;
	        break;
	    case F27:
	        value = CHECK_VALUE(value, F27Max[item]);
	        g_F27[item] = value;
	        break;
	    case F28:
	        value = CHECK_VALUE(value, F28Max[item]);
	        g_F28[item] = value;
	        break;
	    case F29:
	        value = CHECK_VALUE(value, F29Max[item]);
	        g_F29[item] = value;
	        break;
	    case F30:
	        value = CHECK_VALUE(value, F30Max[item]);
	        g_F30[item] = value;
	        break;
	    }
    g_Page1item_index = item;
}

uint8_t ItemValueLimit(uint8_t menu, uint8_t item)
{
    uint8_t res = 0;
    menu = GET_MENU(menu, Page0_MENU_MAX);
    switch(menu)
    {
        case ACU_1:
            res = 0;
            break;
        case BCM_3:
            res = 0;
            break;
        case BCM_4:
            res = 0;
            break;
        case FCM_3:
            res = 0;
            break;
        case FCM_4:
            res = 0;
            break;
        case GW_BD_14:
            res = 0;
            break;
        case GW_BD_29:
            res = 0;
            break;
        case GW_BD_9:
            res = 0;
            break;
        case GW_PC_1:
            res = 0;
            break;
        case GW_PC_2:
            res = 0;
            break;
        case GW_PC_7:
            res = 0;
            break;
        case PEPS_3:
            res = 0;
            break;
        case TBOX_1:
            res = 0;
            break;
        case TBOX_4:
            res = 0;
            break;
        case TPMS_1:
            res = 0;
            break;
        default:
            break;
    }
    return res;
}

uint32_t GetACU_1Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, ACU_1_ITEM_MAX);
    res = g_ACU_1[item];
    if(crash_flag != 0 && res == 0){
    	res = crash_flag;
    }
    return res;
}

uint32_t GetESP_2Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, ESP_2_ITEM_MAX);
    res = g_ESP_2[item];
    if(item == 0 || item == 1){
    	res = g_ESP_2[item] * 100;
    }
    else if(item == 2){
    	res = g_ESP_2[item] * 30;
    }
    return res;
}

uint32_t GetABS_1Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, ABS_1_ITEM_MAX);
    if(item == 0 || item == 2){
        res = g_ABS_1[item] / 0.005625;
    }
    else{
        res = g_ABS_1[item];
    }
    return res;
}

uint32_t GetABS_2Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, ABS_2_ITEM_MAX);
    if(item == 0 || item == 2){
        res = g_ABS_2[item] / 0.005625;
    }
    else{
        res = g_ABS_2[item];
    }
    return res;
}

uint32_t GetBCM_1Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, BCM_1_ITEM_MAX);
    res = g_BCM_1[item];
    return res;
}

uint32_t GetBCM_3Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, BCM_3_ITEM_MAX);
    res = g_BCM_3[item];
	if(item == BCM_ConsoleBtn1TriggerSts){
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)==GPIO_PIN_RESET)
		{
			res = 1;
		}
		else
		{
			res = 0;
		}
	}
    return res;
}

uint32_t GetBCM_4Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, BCM_4_ITEM_MAX);
    res = g_BCM_4[item];
    if(item == BCM_AssistIlluminationSetSts){
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)==GPIO_PIN_RESET)
		{
			res = 1;
		}
		else
		{
			res = 0;
		}

	}
    return res;
}

uint32_t GetBCM_5Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, BCM_5_ITEM_MAX);
    res = g_BCM_5[item];
    return res;
}

uint32_t GetFCM_3Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, FCM_3_ITEM_MAX);
    res = g_FCM_3[item];
    return res;
}

uint32_t GetFCM_4Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, FCM_4_ITEM_MAX);
    res = g_FCM_4[item];
    return res;
}

uint32_t GetFCM_5Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, FCM_5_ITEM_MAX);
    res = g_FCM_5[item];
    if(item == FCM_EgoRiLineHozlDst || item == FCM_EgoLeLineHozlDst){
    	res = g_FCM_5[item] * 10;
    }
    else if((item == FCM_EgoLeLineCrvt || item == FCM_EgoRiLineCrvt)){
    	res = g_FCM_5[item] * 20;
    }
    return res;
}

uint32_t GetFCM_6Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, FCM_6_ITEM_MAX);
    res = g_FCM_6[item];
    if(item == FCM_NeborRiLineHozlDst || item == FCM_NeborLeLineHozlDst){
    	res = g_FCM_6[item] * 10;
    }
    else if((item == FCM_NeborLeLineCrvt || item == FCM_NeborRiLineCrvt)){
    	res = g_FCM_6[item] * 20;
    }
    return res;
}

uint32_t GetFCM_7Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, FCM_7_ITEM_MAX);
    res = g_FCM_7[item];
    if(item == FCM_ACCObjHozDstY || item == FCM_FrntFarObjHozDstY){
    	res = g_FCM_7[item] * 100;
    }
    return res;
}

uint32_t GetFCM_8Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, FCM_8_ITEM_MAX);
    res = g_FCM_8[item];
    if((item == FCM_LeObjHozDstY || item == FCM_RiObjHozDstY)){
    	 res = g_FCM_8[item] * 100;
    }
    return res;
}

uint32_t GetGW_BD_14Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, GW_BD_14_ITEM_MAX);
    res = g_GW_BD_14[item];
    if((item == AC_2_OutsideTemperature)){
        res = g_GW_BD_14[item] * 2;
    }
    return res;
}

uint32_t GetGW_BD_24Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, GW_BD_24_ITEM_MAX);
    res = g_GW_BD_24[item];
    if((item >= 4 && item <= 7)){
        res = g_GW_BD_24[item] * 4;
    }
    return res;
}

uint32_t GetGW_BD_29Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, GW_BD_29_ITEM_MAX);
    res = g_GW_BD_29[item];
    return res;
}

uint32_t GetGW_BD_9Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, GW_BD_9_ITEM_MAX);
    res = g_GW_BD_9[item];
	if(item == BCM_1_FrontLeftDoorSts){
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15)==GPIO_PIN_RESET)
		{
			res = 1;
		}
		else
		{
			res = 0;
		}
	}
    return res;
}

uint32_t GetGW_PC_1Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, GW_PC_1_ITEM_MAX);
    if(item == EMS_2_EngineSpeed){
        res = g_GW_PC_1[item] * 400;
    }
    else{
        res = g_GW_PC_1[item];
    }
    if(item == TCU_1_GearShiftPosition){
//		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)==GPIO_PIN_SET)
//		{
//			res = 0;
//		}
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8)==GPIO_PIN_RESET)
		{
			res = 1;
		}
	}
    return res;
}

uint32_t GetGW_PC_6Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, GW_PC_6_ITEM_MAX);
    res = g_GW_PC_6[item];
    return res;
}

uint32_t GetGW_PC_2Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, GW_PC_2_ITEM_MAX);
    res = g_GW_PC_2[item];
    if(item == ABS_3_VehicleSpeed){
        res = g_GW_PC_2[item] / 0.005625;
    }
    else if(item == SAS_1_SteeringAngle){
    	res = g_GW_PC_2[item] * 85;
    }
    return res;
}

uint32_t GetGW_PC_7Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, GW_PC_7_ITEM_MAX);
    res = g_GW_PC_7[item];
    return res;
}

uint32_t GetGW_PC_4Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, GW_PC_4_ITEM_MAX);
    res = g_GW_PC_4[item];
    return res;
}

uint32_t GetPEPS_3Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, PEPS_3_ITEM_MAX);
    res = g_PEPS_3[item];
    return res;
}

uint32_t GetTBOX_1Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, TBOX_1_ITEM_MAX);
    res = g_TBOX_1[item];
    return res;
}

uint32_t GetTBOX_2Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, TBOX_2_ITEM_MAX);
    res = g_TBOX_2[item];
    return res;
}

uint32_t GetTBOX_4Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, TBOX_4_ITEM_MAX);
    res = g_TBOX_4[item];
    return res;
}

uint32_t GetTPMS_1Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, TPMS_1_ITEM_MAX);
    if(item == TPMS_TirePressure || item == TPMS_TireTemperature){
        res = g_TPMS_1[item] * 15;
    }
    else{
    	res = g_TPMS_1[item];
    }
    return res;
}


uint32_t GetF1Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F1_ITEM_MAX);
    if(item == F1_ABS_3_VehicleSpeed){
        res = g_F1[item] / 0.05625;
    }
    else{
        res = g_F1[item];
    }

    return res;
}

uint32_t GetF2Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F2_ITEM_MAX);
    if(item == EMS_2_EngineSpeed){
        res = g_F2[item] * 400;
    }
    else{
        res = g_F2[item];
    }
    return res;
}

uint32_t GetF3Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F3_ITEM_MAX);
    res = g_F3[item];
    return res;
}

uint32_t GetF4Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F4_ITEM_MAX);
    if(item == EMS_4_EngineCoolantTemp){
        res = g_F4[item] * 2;
    }
    else{
        res = g_F4[item];
    }
    return res;
}

uint32_t GetF5Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F5_ITEM_MAX);
    res = g_F5[item];
    return res;
}

uint32_t GetF6Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F6_ITEM_MAX);
    if(item == EMS_4_FuelConsumption){
        res = g_F6[item] * 5;
    }
    else{
        res = g_F6[item];
    }
    return res;
}

uint32_t GetF7Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F7_ITEM_MAX);
    res = g_F7[item];
    return res;
}

uint32_t GetF8Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F8_ITEM_MAX);
    if(item == F8_TPMS_TirePressure){
        res = g_F8[item] * 15;
    }
    else{
    	res = g_F8[item];
    }
    return res;
}

uint32_t GetF9Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F9_ITEM_MAX);
    res = g_F9[item];
    return res;
}

uint32_t GetF10Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F10_ITEM_MAX);
    res = g_F10[item];
    return res;
}

uint32_t GetF11Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F11_ITEM_MAX);
    res = g_F11[item];
    return res;
}

uint32_t GetF12Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F12_ITEM_MAX);
    res = g_F12[item];
    return res;
}

uint32_t GetF13Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F13_ITEM_MAX);
    res = g_F13[item];
    return res;
}

uint32_t GetF14Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F14_ITEM_MAX);
    res = g_F14[item];
    return res;
}

uint32_t GetF15Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F15_ITEM_MAX);
    res = g_F15[item];
    return res;
}

uint32_t GetF16Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F16_ITEM_MAX);
    res = g_F16[item];
    return res;
}

uint32_t GetF17Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F17_ITEM_MAX);
    res = g_F17[item];
    return res;
}

uint32_t GetF18Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F18_ITEM_MAX);
    res = g_F18[item];
    return res;
}

uint32_t GetF19Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F19_ITEM_MAX);
    res = g_F19[item];
    return res;
}

uint32_t GetF20Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F20_ITEM_MAX);
    res = g_F20[item];
    return res;
}

uint32_t GetF21Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F21_ITEM_MAX);
    res = g_F21[item];
    return res;
}

uint32_t GetF22Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F22_ITEM_MAX);
    res = g_F22[item];
    return res;
}

uint32_t GetF23Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F23_ITEM_MAX);
    res = g_F23[item];
    return res;
}

uint32_t GetF24Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F24_ITEM_MAX);
    res = g_F24[item];
    return res;
}

uint32_t GetF25Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F25_ITEM_MAX);
    res = g_F25[item];
    return res;
}

uint32_t GetF26Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F26_ITEM_MAX);
    res = g_F26[item];
    return res;
}

uint32_t GetF27Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F27_ITEM_MAX);
    res = g_F27[item];
    return res;
}

uint32_t GetF28Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F28_ITEM_MAX);
    res = g_F28[item];
    return res;
}

uint32_t GetF29Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F29_ITEM_MAX);
    res = g_F29[item];
    return res;
}

uint32_t GetF30Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F30_ITEM_MAX);
    res = g_F30[item];
    return res;
}

void LCD_ACU_1_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(*m_value == 1 || *m_value == 2 || *m_value == 4 || *m_value == 8 || *m_value == 16){
		crash_flag = *m_value;
	}
	if(*m_value >= 0 && *m_value <= 2){
		if(crash_flag != 0){
			*m_value = crash_flag;
		}
	}
	else if(*m_value == 4){
		*m_value = 3;
	}
	else if(*m_value == 8){
		*m_value = 4;
	}
	else if(*m_value == 16){
		*m_value = 5;
	}
	else{
		*flag = 1;
	}
}

void LCD_ACU_1_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, ACU_1_ITEM_MAX);
    write_com(0x83);
    hzkdis(ACU_1Item[item]);
    write_com(0x93);
    uint32_t m_value = g_ACU_1[item];
    uint8_t flag = 0;
    LCD_ACU_1_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(ACU_1Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }

    item = GET_MENU(item+1, ACU_1_ITEM_MAX);
    write_com(0x8b);
    hzkdis(ACU_1Item[item]);
    write_com(0x9b);
    m_value = g_ACU_1[item];
    flag = 0;
    LCD_ACU_1_item_Judge(item, &m_value, &flag);
	if (flag == 0) {
		hzkdis(ACU_1Value[item][m_value]);
	} else {
		LCD_ShowNum(m_value);
	}

    write_com(0x93);
    if(crash_flag != 0 && first_crash_flag == 0){
    	CanIl_SendEventMsg(ACU_1);
    	first_crash_flag = 1;
    }
}

void LCD_ESP_2_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, ESP_2_ITEM_MAX);
    write_com(0x83);
    hzkdis(ESP_2Item[item]);
    write_com(0x93);
    if (strcmp(ESP_2Value[item][0], "") != 0) {
        hzkdis(ESP_2Value[item][g_ESP_2[item]]);
    } else {
    	if(item == 0 || item == 1){
            int32_t tmp = (g_ESP_2[item] * 100 * 0.027127 - 21.593092) * 100;
			LCD_ShowNumWithTwoDecimals(tmp);
    	}
    	else if(item == 2){
    		int32_t tmp = (g_ESP_2[item] * 30 * 0.0009765625 - 2.0947265625) * 100;
    		LCD_ShowNumWithTwoDecimals(tmp);
    	}
    	else{
    		LCD_ShowNum(g_ESP_2[item]);
    	}
    }

    item = GET_MENU(item+1, ESP_2_ITEM_MAX);
    write_com(0x8b);
    hzkdis(ESP_2Item[item]);
    write_com(0x9b);
    if (strcmp(ESP_2Value[item][0], "") != 0) {
        hzkdis(ESP_2Value[item][g_ESP_2[item]]);
    } else {
    	if(item == 0 || item == 1){
            int32_t tmp = (g_ESP_2[item] * 100 * 0.027127 - 21.593092) * 100;
			LCD_ShowNumWithTwoDecimals(tmp);
    	}
    	else if(item == 2){
    		int32_t tmp = (g_ESP_2[item] * 30 * 0.0009765625 - 2.0947265625) * 100;
    		LCD_ShowNumWithTwoDecimals(tmp);
    	}
    	else{
    		LCD_ShowNum(g_ESP_2[item]);
    	}
    }
    write_com(0x93);
}

void LCD_ABS_1_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, ABS_1_ITEM_MAX);
    write_com(0x83);
    hzkdis(ABS_1Item[item]);
    write_com(0x93);
    if (strcmp(ABS_1Value[item][0], "") != 0) {
        hzkdis(ABS_1Value[item][g_ABS_1[item]]);
    } else {
    	if(item == ABS_FLWheelSpeed || item == ABS_FRWheelSpeed){
    		LCD_ShowNum(g_ABS_1[item] * 10);
    	}
    	else{
    		LCD_ShowNum(g_ABS_1[item]);
    	}
    }

    item = GET_MENU(item+1, ABS_1_ITEM_MAX);
    write_com(0x8b);
    hzkdis(ABS_1Item[item]);
    write_com(0x9b);
    if (strcmp(ABS_1Value[item][0], "") != 0) {
        hzkdis(ABS_1Value[item][g_ABS_1[item]]);
    } else {
    	if(item == ABS_FLWheelSpeed || item == ABS_FRWheelSpeed){
    		LCD_ShowNum(g_ABS_1[item] * 10);
    	}
    	else{
    		LCD_ShowNum(g_ABS_1[item]);
    	}
    }
    write_com(0x93);
}

void LCD_ABS_2_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, ABS_2_ITEM_MAX);
    write_com(0x83);
    hzkdis(ABS_2Item[item]);
    write_com(0x93);
    if (strcmp(ABS_2Value[item][0], "") != 0) {
        hzkdis(ABS_2Value[item][g_ABS_2[item]]);
    } else {
    	if(item == ABS_RLWheelSpeed || item == ABS_RRWheelSpeed){
    		LCD_ShowNum(g_ABS_2[item] * 10);
    	}
    	else{
    		LCD_ShowNum(g_ABS_2[item]);
    	}
    }

    item = GET_MENU(item+1, ABS_2_ITEM_MAX);
    write_com(0x8b);
    hzkdis(ABS_2Item[item]);
    write_com(0x9b);
    if (strcmp(ABS_2Value[item][0], "") != 0) {
        hzkdis(ABS_2Value[item][g_ABS_2[item]]);
    } else {
    	if(item == ABS_RLWheelSpeed || item == ABS_RRWheelSpeed){
    		LCD_ShowNum(g_ABS_2[item] * 10);
    	}
    	else{
    		LCD_ShowNum(g_ABS_2[item]);
    	}
    }
    write_com(0x93);
}

void LCD_TPMS_1_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 1 || item == 6){
		if(*m_value == 0xFF){
			*m_value = 0;
		}
	}
}

void LCD_TPMS_1_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, TPMS_1_ITEM_MAX);
    write_com(0x83);
    hzkdis(TPMS_1Item[item]);
    write_com(0x93);
    uint32_t m_value = g_TPMS_1[item];
    uint8_t flag = 0;
    LCD_TPMS_1_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        if(item == TPMS_TirePressure){
        	int32_t tmp = (m_value * 15  * 2.745) * 100;
        	LCD_ShowNumWithTwoDecimals(tmp);
        }
        else if(item == TPMS_TireTemperature){
        	uint32_t tmp = (m_value * 15  - 60);
        	LCD_ShowNum(tmp);
        }
        else{
        	hzkdis(TPMS_1Value[item][g_TPMS_1[item]]);
        }
    } else {
        LCD_ShowNum(g_TPMS_1[item]);
    }

    item = GET_MENU(item+1, TPMS_1_ITEM_MAX);
    write_com(0x8b);
    hzkdis(TPMS_1Item[item]);
    write_com(0x9b);
    m_value = g_TPMS_1[item];
    flag = 0;
    LCD_TPMS_1_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        if(item == TPMS_TirePressure){
        	uint32_t tmp = (m_value * 15  * 2.745) * 100;
        	LCD_ShowNumWithTwoDecimals(tmp);
        }
        else if(item == TPMS_TireTemperature){
        	uint32_t tmp = (m_value * 15  - 60);
        	LCD_ShowNum(tmp);
        }
        else{
        	hzkdis(TPMS_1Value[item][g_TPMS_1[item]]);
        }
    } else {
        LCD_ShowNum(g_TPMS_1[item]);
    }
    write_com(0x93);
}

void LCD_BCM_1_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, BCM_1_ITEM_MAX);
    write_com(0x83);
    hzkdis(BCM_1Item[item]);
    write_com(0x93);
    if (strcmp(BCM_1Value[item][0], "") != 0) {
        hzkdis(BCM_1Value[item][g_BCM_1[item]]);
    } else {
        LCD_ShowNum(g_BCM_1[item]);
    }

    item = GET_MENU(item+1, BCM_1_ITEM_MAX);
    write_com(0x8b);
    hzkdis(BCM_1Item[item]);
    write_com(0x9b);
    if (strcmp(BCM_1Value[item][0], "") != 0) {
        hzkdis(BCM_1Value[item][g_BCM_1[item]]);
    } else {
        LCD_ShowNum(g_BCM_1[item]);
    }
    write_com(0x93);
}

void LCD_BCM_3_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, BCM_3_ITEM_MAX);
    write_com(0x83);
    hzkdis(BCM_3Item[item]);
    write_com(0x93);
    if (strcmp(BCM_3Value[item][0], "") != 0) {
        hzkdis(BCM_3Value[item][g_BCM_3[item]]);
    } else {
        LCD_ShowNum(g_BCM_3[item]);
    }

    item = GET_MENU(item+1, BCM_3_ITEM_MAX);
    write_com(0x8b);
    hzkdis(BCM_3Item[item]);
    write_com(0x9b);
    if (strcmp(BCM_3Value[item][0], "") != 0) {
        hzkdis(BCM_3Value[item][g_BCM_3[item]]);
    } else {
        LCD_ShowNum(g_BCM_3[item]);
    }
    write_com(0x93);
}

void LCD_BCM_4_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
    if (item == 0){
    	if(*m_value >= 3 && *m_value <= 6){
    		*m_value = 3;
    	}
    	else if(*m_value == 7){
    		*m_value = 4;
    	}
    }
    else if(item == 6){
    	if(*m_value >= 5 && *m_value <= 6){
    		*m_value = 5;
    	}
    	else if(*m_value == 7){
    		*m_value = 6;
    	}
    }
    else if(item == 7){
    	if(*m_value >= 5 && *m_value <= 6){
    		*m_value = 5;
    	}
    	else if(*m_value == 7){
    		*m_value = 6;
    	}
    }
    else if(item == 8){
    	if(*m_value >= 4 && *m_value <= 6){
    		*m_value = 4;
    	}
    	else if(*m_value == 7){
    		*m_value = 5;
    	}
    }
    else if(item == 10){
    	if(*m_value >= 11){
    		*m_value = 11;
    	}
    }
    else if(item == 14){
    	if(*m_value >= 4 && *m_value <= 6){
    	    *m_value = 4;
    	}
    	else if(*m_value == 7){
    		*m_value = 5;
    	}
    }
    else{
    	flag = 1;
    }
}

void LCD_BCM_4_item(uint8_t item, int16_t value)
{


    item = GET_MENU(item, BCM_4_ITEM_MAX);
    write_com(0x83);
    hzkdis(BCM_4Item[item]);
    write_com(0x93);
    uint32_t m_value = g_BCM_4[item];
    uint8_t flag = 0;
    LCD_BCM_4_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(BCM_4Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }

    item = GET_MENU(item+1, BCM_4_ITEM_MAX);
    write_com(0x8b);
    hzkdis(BCM_4Item[item]);
    write_com(0x9b);
    m_value = g_BCM_4[item];
    flag = 0;
    LCD_BCM_4_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(BCM_4Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }
    write_com(0x93);
}

void LCD_BCM_5_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 0){
		if(*m_value >= 7 && *m_value <= 0x15){
			*m_value = 7;
		}
	}
}

void LCD_BCM_5_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, BCM_5_ITEM_MAX);
    write_com(0x83);
    hzkdis(BCM_5Item[item]);
    write_com(0x93);
    uint32_t m_value = g_BCM_5[item];
    uint8_t flag = 0;
    LCD_BCM_5_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(BCM_5Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }

    item = GET_MENU(item+1, BCM_5_ITEM_MAX);
    write_com(0x8b);
    hzkdis(BCM_5Item[item]);
    write_com(0x9b);
    m_value = g_BCM_5[item];
    flag = 0;
    LCD_BCM_5_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(BCM_5Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }
    write_com(0x93);
}



void LCD_PEPS_3_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, PEPS_3_ITEM_MAX);
    write_com(0x83);
    hzkdis(PEPS_3Item[item]);
    write_com(0x93);
    if (strcmp(PEPS_3Value[item][0], "") != 0) {
        hzkdis(PEPS_3Value[item][g_PEPS_3[item]]);
    } else {
        LCD_ShowNum(g_PEPS_3[item]);
    }

    item = GET_MENU(item+1, PEPS_3_ITEM_MAX);
    write_com(0x8b);
    hzkdis(PEPS_3Item[item]);
    write_com(0x9b);
    if (strcmp(PEPS_3Value[item][0], "") != 0) {
        hzkdis(PEPS_3Value[item][g_PEPS_3[item]]);
    } else {
        LCD_ShowNum(g_PEPS_3[item]);
    }
    write_com(0x93);
}

void LCD_TBOX_1_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 3 || item == 4){
		*m_value += 1;
	}
	else if(item == 5){
		*m_value += 2000;
	}
}

void LCD_TBOX_1_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, TBOX_1_ITEM_MAX);
    write_com(0x83);
    hzkdis(TBOX_1Item[item]);
    write_com(0x93);
    uint32_t m_value = g_TBOX_1[item];
    uint8_t flag = 0;
    LCD_TBOX_1_item_Judge(item, &m_value, &flag);
    if (strcmp(TBOX_1Value[item][0], "") != 0) {
        hzkdis(TBOX_1Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }

    item = GET_MENU(item+1, TBOX_1_ITEM_MAX);
    write_com(0x8b);
    hzkdis(TBOX_1Item[item]);
    write_com(0x9b);
    m_value = g_TBOX_1[item];
    flag = 0;
    LCD_TBOX_1_item_Judge(item, &m_value, &flag);
    if (strcmp(TBOX_1Value[item][0], "") != 0) {
        hzkdis(TBOX_1Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }
    write_com(0x93);
}

void LCD_TBOX_2_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, TBOX_2_ITEM_MAX);
    write_com(0x83);
    hzkdis(TBOX_2Item[item]);
    write_com(0x93);
    if (strcmp(TBOX_2Value[item][0], "") != 0) {
        hzkdis(TBOX_2Value[item][g_TBOX_2[item]]);
    } else {
        LCD_ShowNum(g_TBOX_2[item]);
    }

    item = GET_MENU(item+1, TBOX_2_ITEM_MAX);
    write_com(0x8b);
    hzkdis(TBOX_2Item[item]);
    write_com(0x9b);
    if (strcmp(TBOX_2Value[item][0], "") != 0) {
        hzkdis(TBOX_2Value[item][g_TBOX_2[item]]);
    } else {
        LCD_ShowNum(g_TBOX_2[item]);
    }
    write_com(0x93);
}

void LCD_TBOX_4_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, TBOX_4_ITEM_MAX);
    write_com(0x83);
    hzkdis(TBOX_4Item[item]);
    write_com(0x93);
    if (strcmp(TBOX_4Value[item][0], "") != 0) {
        hzkdis(TBOX_4Value[item][g_TBOX_4[item]]);
    } else {
        LCD_ShowNum(g_TBOX_4[item]);
    }

    item = GET_MENU(item+1, TBOX_4_ITEM_MAX);
    write_com(0x8b);
    hzkdis(TBOX_4Item[item]);
    write_com(0x9b);
    if (strcmp(TBOX_4Value[item][0], "") != 0) {
        hzkdis(TBOX_4Value[item][g_TBOX_4[item]]);
    } else {
        LCD_ShowNum(g_TBOX_4[item]);
    }
    write_com(0x93);
}

void LCD_FCM_3_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 1){
		if(*m_value >= 0x6 && *m_value <= 0x7){
			*m_value = 6;
		}
	}
}

void LCD_FCM_3_item(uint8_t item, int16_t value)
{


    item = GET_MENU(item, FCM_3_ITEM_MAX);
    write_com(0x83);
    hzkdis(FCM_3Item[item]);
    write_com(0x93);
    uint32_t m_value = g_FCM_3[item];
    uint8_t flag = 0;
    LCD_FCM_3_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(FCM_3Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }

    item = GET_MENU(item+1, FCM_3_ITEM_MAX);
    write_com(0x8b);
    hzkdis(FCM_3Item[item]);
    write_com(0x9b);
    m_value = g_FCM_3[item];
    flag = 0;
    LCD_FCM_3_item_Judge(item, &m_value, &flag);
    if (strcmp(FCM_3Value[item][0], "") != 0) {
        hzkdis(FCM_3Value[item][g_FCM_3[item]]);
    } else {
        LCD_ShowNum(g_FCM_3[item]);
    }
    write_com(0x93);
}

void LCD_FCM_4_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 1){
		if(*m_value >= 5 && *m_value <= 7){
			*m_value = 5;
		}
	}
	else if(item == 4){
		if(*m_value >= 6 && *m_value <= 7){
			*m_value = 6;
		}
	}
	else if(item == 7){
		if(*m_value >= 6 && *m_value <= 7){
			*m_value = 6;
		}
	}
}

void LCD_FCM_4_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, FCM_4_ITEM_MAX);
    write_com(0x83);
    hzkdis(FCM_4Item[item]);
    write_com(0x93);
    uint32_t m_value = g_FCM_4[item];
    uint8_t flag = 0;
    LCD_FCM_4_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(FCM_4Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }

    item = GET_MENU(item+1, FCM_4_ITEM_MAX);
    write_com(0x8b);
    hzkdis(FCM_4Item[item]);
    write_com(0x9b);
    m_value = g_FCM_4[item];
    flag = 0;
    LCD_FCM_4_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(FCM_4Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }
    write_com(0x93);
}

void LCD_FCM_5_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, FCM_5_ITEM_MAX);
    write_com(0x83);
    hzkdis(FCM_5Item[item]);
    write_com(0x93);
    if (strcmp(FCM_5Value[item][0], "") != 0) {
        hzkdis(FCM_5Value[item][g_FCM_5[item]]);
    } else {
    	if(item == FCM_EgoRiLineHozlDst || item == FCM_EgoLeLineHozlDst){
    		LCD_ShowNum(g_FCM_5[item] - 25);
    	}
    	else if((item == FCM_EgoLeLineCrvt || item == FCM_EgoRiLineCrvt)){
    		int32_t tmp = (g_FCM_5[item] * 20 * 0.00006 - 0.0156) * 100;
    		LCD_ShowNumWithTwoDecimals(tmp);
    	}
    	else{
    		LCD_ShowNum(g_FCM_5[item]);
    	}
    }

    item = GET_MENU(item+1, FCM_5_ITEM_MAX);
    write_com(0x8b);
    hzkdis(FCM_5Item[item]);
    write_com(0x9b);
    if (strcmp(FCM_5Value[item][0], "") != 0) {
        hzkdis(FCM_5Value[item][g_FCM_5[item]]);
    } else {
    	if(item == FCM_EgoRiLineHozlDst || item == FCM_EgoLeLineHozlDst){
    		LCD_ShowNum(g_FCM_5[item] - 25);
    	}
    	else if((item == FCM_EgoLeLineCrvt || item == FCM_EgoRiLineCrvt)){
    		int32_t tmp = (g_FCM_5[item] * 20 * 0.00006 - 0.0156) * 100;
    		LCD_ShowNumWithTwoDecimals(tmp);
    	}
    	else{
    		LCD_ShowNum(g_FCM_5[item]);
    	}
    }
    write_com(0x93);
}

void LCD_FCM_6_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, FCM_6_ITEM_MAX);
    write_com(0x83);
    hzkdis(FCM_6Item[item]);
    write_com(0x93);
    if (strcmp(FCM_6Value[item][0], "") != 0) {
        hzkdis(FCM_6Value[item][g_FCM_6[item]]);
    } else {
    	if(item == FCM_EgoRiLineHozlDst || item == FCM_EgoLeLineHozlDst){
    		LCD_ShowNum(g_FCM_6[item] * 10 - 25);
    	}
    	else if(item == FCM_NeborLeLineCrvt || item == FCM_NeborRiLineCrvt){
    		int32_t tmp = (g_FCM_6[item] * 20 * 0.00006 - 0.0156) * 100;
    		LCD_ShowNumWithTwoDecimals(tmp);
    	}
    	else{
    		LCD_ShowNum(g_FCM_6[item]);
    	}
    }

    item = GET_MENU(item+1, FCM_6_ITEM_MAX);
    write_com(0x8b);
    hzkdis(FCM_6Item[item]);
    write_com(0x9b);
    if (strcmp(FCM_6Value[item][0], "") != 0) {
        hzkdis(FCM_6Value[item][g_FCM_6[item]]);
    } else {
    	if(item == FCM_NeborLeLineHozlDst || item == FCM_NeborRiLineHozlDst){
    		LCD_ShowNum(g_FCM_6[item] * 10 - 25);
    	}
    	else if(item == FCM_NeborLeLineCrvt || item == FCM_NeborRiLineCrvt){
    		int32_t tmp = (g_FCM_6[item] * 20 * 0.00006 - 0.0156) * 100;
    		LCD_ShowNumWithTwoDecimals(tmp);
    	}
    	else{
    		LCD_ShowNum(g_FCM_6[item]);
    	}
    }
    write_com(0x93);
}

void LCD_FCM_7_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 1 || item == 3){
		if(*m_value >= 5 && *m_value <= 7){
			*m_value = 5;
		}
	}
	else if(item == 7){
		if(*m_value >= 7){
			*m_value = 7;
		}
	}
	else if(item == 4 || item == 5 || item == 8 || item == 9){
		*flag = 1;
	}
}

void LCD_FCM_7_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, FCM_7_ITEM_MAX);
    write_com(0x83);
    hzkdis(FCM_7Item[item]);
    write_com(0x93);
    uint32_t m_value = g_FCM_7[item];
    uint8_t flag = 0;
    LCD_FCM_7_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(FCM_7Value[item][m_value]);
    } else {
    	if(item == FCM_ACCObjHozDstY || item == FCM_FrntFarObjHozDstY){
            LCD_ShowNum(m_value * 10 - 50);
    	}
    	else{
    		LCD_ShowNum(m_value);
    	}
    }

    item = GET_MENU(item+1, FCM_7_ITEM_MAX);
    write_com(0x8b);
    hzkdis(FCM_7Item[item]);
    write_com(0x9b);
    m_value = g_FCM_7[item];
    flag = 0;
    LCD_FCM_7_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(FCM_7Value[item][m_value]);
    } else {
    	if(item == FCM_ACCObjHozDstY || item == FCM_FrntFarObjHozDstY){
            LCD_ShowNum(m_value * 100 - 50);
    	}
    	else{
    		LCD_ShowNum(m_value);
    	}
    }
    write_com(0x93);
}

void LCD_FCM_8_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 2 || item == 6){
		if(*m_value >= 5 && *m_value <= 7){
			*m_value = 5;
		}
	}
	else if(item == 4 || item == 5 || item == 8 || item == 9){
		*flag = 1;
	}
}

void LCD_FCM_8_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, FCM_8_ITEM_MAX);
    write_com(0x83);
    hzkdis(FCM_8Item[item]);
    write_com(0x93);
    uint32_t m_value = g_FCM_8[item];
    uint8_t flag = 0;
    LCD_FCM_8_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(FCM_8Value[item][m_value]);
    } else {
    	if(item == FCM_LeObjHozDstY || item == FCM_RiObjHozDstY){
            LCD_ShowNum(m_value * 10 - 50);
    	}
    	else{
    		LCD_ShowNum(m_value);
    	}
    }

    item = GET_MENU(item+1, FCM_8_ITEM_MAX);
    write_com(0x8b);
    hzkdis(FCM_8Item[item]);
    write_com(0x9b);
    m_value = g_FCM_8[item];
    flag = 0;
    LCD_FCM_8_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(FCM_8Value[item][m_value]);
    } else {
    	if(item == FCM_LeObjHozDstY || item == FCM_RiObjHozDstY){
            LCD_ShowNum(m_value * 10 - 50);
    	}
    	else{
    		LCD_ShowNum(m_value);
    	}
    }
    write_com(0x93);
}

void LCD_GW_PC_1_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 0){
		if((*m_value >= 0 && *m_value <= 5) || (*m_value == 7)){
			if(*m_value == 7){
				*m_value = 6;
			}
		}
		else if(*m_value >= 0x8 && *m_value <= 0xC){
			*m_value = 7;
		}
		else if(*m_value == 0xF){
			*m_value = 8;
		}
		else{
			*flag = 1;
		}
	}
	else if(item == 2){
		if(*m_value >= 0 && *m_value <= 0x0A){

		}
		else if(*m_value >= 0x0B && *m_value <= 0x0F){
			*m_value = 11;
		}
		else if(*m_value >= 0x10 && *m_value <= 0x13){
			*m_value -= 4;
		}
		else if(*m_value >= 0x14 && *m_value <= 0x3E){
			*m_value = 16;
		}
		else if(*m_value == 0x3F){
			*m_value = 17;
		}
		else{
			*flag = 1;
		}
	}
	else if(item == EMS_2_EngineSpeed){
		*flag = 1;
	}
}

void LCD_GW_PC_1_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, GW_PC_1_ITEM_MAX);
    write_com(0x83);
    hzkdis(GW_PC_1Item[item]);
    write_com(0x93);
    uint32_t m_value = g_GW_PC_1[item];
    uint8_t flag = 0;
    LCD_GW_PC_1_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(GW_PC_1Value[item][m_value]);
    }
    else {
    	if(item == EMS_2_EngineSpeed){
			LCD_ShowNum(g_GW_PC_1[item] * 100);
		}
		else{
			LCD_ShowNum(g_GW_PC_1[item]);
		}
    }
    item = GET_MENU(item+1, GW_PC_1_ITEM_MAX);
    write_com(0x8b);
    hzkdis(GW_PC_1Item[item]);
    write_com(0x9b);
    m_value = g_GW_PC_1[item];
    flag = 0;
    LCD_GW_PC_1_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(GW_PC_1Value[item][m_value]);
    } else {
    	if(item == EMS_2_EngineSpeed){
			LCD_ShowNum(g_GW_PC_1[item] * 100);
		}
		else{
			LCD_ShowNum(g_GW_PC_1[item]);
		}
    }
    write_com(0x93);
}

void LCD_GW_PC_6_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 0){
		if(*m_value >= 4){
			*m_value = 4;
		}
	}
}

void LCD_GW_PC_6_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, GW_PC_6_ITEM_MAX);
    write_com(0x83);
    hzkdis(GW_PC_6Item[item]);
    write_com(0x93);
    uint32_t m_value = g_GW_PC_6[item];
    uint8_t flag = 0;
    LCD_GW_PC_6_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(GW_PC_6Value[item][m_value]);
    }
    else {
		LCD_ShowNum(m_value);
    }

    item = GET_MENU(item+1, GW_PC_6_ITEM_MAX);
    write_com(0x8b);
    hzkdis(GW_PC_6Item[item]);
    write_com(0x9b);
    m_value = g_GW_PC_6[item];
	flag = 0;
	LCD_GW_PC_6_item_Judge(item, &m_value, &flag);
	if (flag == 0) {
		hzkdis(GW_PC_6Value[item][m_value]);
	}
	else {
		LCD_ShowNum(m_value);
	}
    write_com(0x93);
}

void LCD_GW_PC_2_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 1){
		if(*m_value <= (0x3CF1/85) && *m_value > (0x1E78/85)){
			*m_value = 0;
		}
		else if(*m_value >= 0 && *m_value < (0x1E78/85)){
			*m_value = 1;
		}
		else if(*m_value > (0x3CF1/85) && *m_value <= (0xFFFE/85)){
			*m_value = 2;
		}
		else if(*m_value == (0x1E78/85)){
			*m_value = 3;
		}
		else{
			*m_value = 4;
		}
	}
	else if(item == 0){
		*m_value *= 10;
		*flag = 1;
	}
}

void LCD_GW_PC_2_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, GW_PC_2_ITEM_MAX);
    write_com(0x83);
    hzkdis(GW_PC_2Item[item]);
    write_com(0x93);
    uint32_t m_value = g_GW_PC_2[item];
    uint8_t flag = 0;
    LCD_GW_PC_2_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(GW_PC_2Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }

    item = GET_MENU(item+1, GW_PC_2_ITEM_MAX);
    write_com(0x8b);
    hzkdis(GW_PC_2Item[item]);
    write_com(0x9b);
    m_value = g_GW_PC_2[item];
    flag = 0;
    LCD_GW_PC_2_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(GW_PC_2Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }
    write_com(0x93);
}

void LCD_GW_PC_7_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, GW_PC_7_ITEM_MAX);
    write_com(0x83);
    hzkdis(GW_PC_7Item[item]);
    write_com(0x93);
    if (strcmp(GW_PC_7Value[item][0], "") != 0) {
        hzkdis(GW_PC_7Value[item][g_GW_PC_7[item]]);
    } else {
        LCD_ShowNum(g_GW_PC_7[item]);
    }

    item = GET_MENU(item+1, GW_PC_7_ITEM_MAX);
    write_com(0x8b);
    hzkdis(GW_PC_7Item[item]);
    write_com(0x9b);
    if (strcmp(GW_PC_7Value[item][0], "") != 0) {
        hzkdis(GW_PC_7Value[item][g_GW_PC_7[item]]);
    } else {
        LCD_ShowNum(g_GW_PC_7[item]);
    }
    write_com(0x93);
}

void LCD_GW_PC_4_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, GW_PC_4_ITEM_MAX);
    write_com(0x83);
    hzkdis(GW_PC_4Item[item]);
    write_com(0x93);
    if (strcmp(GW_PC_4Value[item][0], "") != 0) {
        hzkdis(GW_PC_4Value[item][g_GW_PC_4[item]]);
    } else {
        LCD_ShowNum(g_GW_PC_4[item]);
    }

    item = GET_MENU(item+1, GW_PC_4_ITEM_MAX);
    write_com(0x8b);
    hzkdis(GW_PC_4Item[item]);
    write_com(0x9b);
    if (strcmp(GW_PC_4Value[item][0], "") != 0) {
        hzkdis(GW_PC_4Value[item][g_GW_PC_4[item]]);
    } else {
        LCD_ShowNum(g_GW_PC_4[item]);
    }
    write_com(0x93);
}

void LCD_GW_BD_9_item(uint8_t item, int16_t value)
{


    item = GET_MENU(item, GW_BD_9_ITEM_MAX);
    write_com(0x83);
    hzkdis(GW_BD_9Item[item]);
    write_com(0x93);
    if (strcmp(GW_BD_9Value[item][0], "") != 0) {
        hzkdis(GW_BD_9Value[item][g_GW_BD_9[item]]);
    } else {
        LCD_ShowNum(g_GW_BD_9[item]);
    }

    item = GET_MENU(item+1, GW_BD_9_ITEM_MAX);
    write_com(0x8b);
    hzkdis(GW_BD_9Item[item]);
    write_com(0x9b);
    if (strcmp(GW_BD_9Value[item][0], "") != 0) {
        hzkdis(GW_BD_9Value[item][g_GW_BD_9[item]]);
    } else {
        LCD_ShowNum(g_GW_BD_9[item]);
    }
    write_com(0x93);
}

void LCD_GW_BD_14_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 2){
		if(*m_value == 0){
			*m_value = 0;
		}
		else if(*m_value == 1){
			*m_value = 1;
		}
		else if(*m_value >= 2 && *m_value <= 32){
			if((*m_value - 2) % 2 == 0){
				*m_value = 16.5 + 0.5 * (*m_value - 2);
				*flag = 3;
			}
			else{
				*m_value = 16.5 + 0.5 * (*m_value - 2);
				*flag = 2;
			}
		}
		else if(*m_value == 0x3E){
			*m_value = 2;
		}
		else if(*m_value == 0x3F){
			*m_value = 3;
		}
		else{
			*flag = 1;
		}
	}
	else if(item == 3){
		if(*m_value == 0){
			*m_value = 0;
		}
		else if(*m_value == 1){
			*m_value = 1;
		}
		else if(*m_value >= 2 && *m_value <= 32){
			if((*m_value - 2) % 2 == 0){
				*m_value = 16.5 + 0.5 * (*m_value - 2);
				*flag = 3;
			}
			else{
				*m_value = 16.5 + 0.5 * (*m_value - 2);
				*flag = 2;
			}
		}
		else if(*m_value == 0x3E){
			*m_value = 2;
		}
		else if(*m_value == 0x3F){
			*m_value = 3;
		}
		else{
			*flag = 1;
		}
	}
	else if(item == 5){
		if(*m_value >= 6 && *m_value <= 7){
			*m_value = 6;
		}
	}
	else if(item == 11){
		if(*m_value == 0xFF){
			*m_value = 0;
		}
		else{
			*flag = 1;
		}
	}
}

void LCD_GW_BD_14_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, GW_BD_14_ITEM_MAX);
    write_com(0x83);
    hzkdis(GW_BD_14Item[item]);
    write_com(0x93);
    uint32_t m_value = g_GW_BD_14[item];
    uint8_t flag = 0;
    LCD_GW_BD_14_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(GW_BD_14Value[item][m_value]);
    } else if(flag == 1) {
    	if(item == 11){
    		int32_t tmp = m_value - 40;
    		LCD_ShowNum(tmp);
    	}
    	else{
    		LCD_ShowNum(m_value);
    	}
    }
    else if(flag ==2){
    	LCD_ShowNumdecimal(m_value, 0);
    }
    else{
    	LCD_ShowNumdecimal(m_value, 1);
    }

    item = GET_MENU(item+1, GW_BD_14_ITEM_MAX);
    write_com(0x8b);
    hzkdis(GW_BD_14Item[item]);
    write_com(0x9b);
    m_value = g_GW_BD_14[item];
    flag = 0;
    LCD_GW_BD_14_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(GW_BD_14Value[item][m_value]);
    } else if(flag == 1) {
    	if(item == 11){
    		int32_t tmp = m_value - 40;
    		LCD_ShowNum(tmp);
    	}
    	else{
    		LCD_ShowNum(m_value);
    	}
    }
    else if(flag ==2){
    	LCD_ShowNumdecimal(m_value, 0);
    }
    else{
    	LCD_ShowNumdecimal(m_value, 1);
    }
    write_com(0x93);
}

void LCD_GW_BD_24_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, GW_BD_24_ITEM_MAX);
    write_com(0x83);
    hzkdis(GW_BD_24Item[item]);
    write_com(0x93);
    if (strcmp(GW_BD_24Value[item][0], "") != 0) {
        hzkdis(GW_BD_24Value[item][g_GW_BD_24[item]]);
    } else {
    	if(item >= 4 && item <= 7){
    		LCD_ShowNum(g_GW_BD_24[item] * 4);
    	}
    	else{
    		LCD_ShowNum(g_GW_BD_24[item]);
    	}
    }

    item = GET_MENU(item+1, GW_BD_24_ITEM_MAX);
    write_com(0x8b);
    hzkdis(GW_BD_24Item[item]);
    write_com(0x9b);
    if (strcmp(GW_BD_24Value[item][0], "") != 0) {
        hzkdis(GW_BD_24Value[item][g_GW_BD_24[item]]);
    } else {
    	if(item >= 4 && item <= 7){
    		LCD_ShowNum(g_GW_BD_24[item] * 4);
    	}
    	else{
    		LCD_ShowNum(g_GW_BD_24[item]);
    	}
    }
    write_com(0x93);
}

void LCD_GW_BD_29_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag){
	if(item == 0 || item == 1 || item == 9 || item == 11){
		if(*m_value >= 4 && *m_value <= 0x0E){
			*m_value = 4;
		}
		else if(*m_value == 0x0F){
			*m_value = 5;
		}
	}
	else if(item == 2){
		if(*m_value >= 4 && *m_value <= 6){
			*m_value = 4;
		}
		else if(*m_value == 7){
			*m_value = 5;
		}
	}
	else if(item == 3){
		if(*m_value >= 4 && *m_value <= 0x0E){
			*m_value = 3;
		}
		else if(*m_value == 0x0F){
			*m_value = 4;
		}
	}
	else if(item == 6){
		if(*m_value >= 6 && *m_value <= 7){
			*m_value = 6;
		}
	}
}

void LCD_GW_BD_29_item(uint8_t item, int16_t value)
{


    item = GET_MENU(item, GW_BD_29_ITEM_MAX);
    write_com(0x83);
    hzkdis(GW_BD_29Item[item]);
    write_com(0x93);
    uint32_t m_value = g_GW_BD_29[item];
    uint8_t flag = 0;
    LCD_GW_BD_29_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(GW_BD_29Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }

    item = GET_MENU(item+1, GW_BD_29_ITEM_MAX);
    write_com(0x8b);
    hzkdis(GW_BD_29Item[item]);
    write_com(0x9b);
    m_value = g_GW_BD_29[item];
    flag = 0;
    LCD_GW_BD_29_item_Judge(item, &m_value, &flag);
    if (flag == 0) {
        hzkdis(GW_BD_29Value[item][m_value]);
    } else {
        LCD_ShowNum(m_value);
    }
    write_com(0x93);
}



void LCD_F1_item(uint8_t item, int16_t value)
{
	item = GET_MENU(item, F1_ITEM_MAX);
    write_com(0x83);
    hzkdis(F1Item[item]);
    write_com(0x93);
    if (strcmp(F1Value[item][0], "") != 0) {
        hzkdis(F1Value[item][g_F1[item]]);
    } else {
        LCD_ShowNum(g_F1[item]);
    }
	item = GET_MENU(item + 1, F1_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F1Item[item]);
    write_com(0x9b);
    if (strcmp(F1Value[item][0], "") != 0) {
        hzkdis(F1Value[item][g_F1[item]]);
    } else {
        LCD_ShowNum(g_F1[item]);
    }
    write_com(0x93);
}

void LCD_F2_item(uint8_t item, int16_t value)
{
	item = GET_MENU(item, F2_ITEM_MAX);
    write_com(0x83);
    hzkdis(F2Item[item]);
    write_com(0x93);
    if (strcmp(F2Value[item][0], "") != 0) {
        hzkdis(F2Value[item][g_F2[item]]);
    } else {
        if(item == EMS_2_EngineSpeed){
            LCD_ShowNum(g_F2[item] * 100);
        }
        else{
        	LCD_ShowNum(g_F2[item]);
        }
    }
	item = GET_MENU(item + 1, F2_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F2Item[item]);
    write_com(0x9b);
    if (strcmp(F2Value[item][0], "") != 0) {
        hzkdis(F2Value[item][g_F2[item]]);
    } else {
        LCD_ShowNum(g_F2[item]);
    }
    write_com(0x93);
}

void LCD_F3_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F3_ITEM_MAX);
    write_com(0x83);
    hzkdis(F3Item[item]);
    write_com(0x93);
    if (strcmp(F3Value[item][0], "") != 0) {
        hzkdis(F3Value[item][g_F3[item]]);
    } else {
        LCD_ShowNum(g_F3[item]);
    }

    item = GET_MENU(item + 1, F3_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F3Item[item]);
    write_com(0x9b);
    if (strcmp(F3Value[item][0], "") != 0) {
        hzkdis(F3Value[item][g_F3[item]]);
    } else {
        LCD_ShowNum(g_F3[item]);
    }
    write_com(0x93);
}

void LCD_F4_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F4_ITEM_MAX);
    write_com(0x83);
    hzkdis(F4Item[item]);
    write_com(0x93);
    if (strcmp(F4Value[item][0], "") != 0) {
        hzkdis(F4Value[item][g_F4[item]]);
    } else {
        if(item == EMS_4_EngineCoolantTemp){
        	int32_t tmp = g_F4[item] * 2 * 0.75 - 48;
            LCD_ShowNum(tmp);
        }
        else{
        	LCD_ShowNum(g_F4[item]);
        }
    }

    item = GET_MENU(item + 1, F4_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F4Item[item]);
    write_com(0x9b);
    if (strcmp(F4Value[item][0], "") != 0) {
        hzkdis(F4Value[item][g_F4[item]]);
    } else {
        if(item == EMS_4_EngineCoolantTemp){
        	int32_t tmp = g_F4[item] * 2 * 0.75 - 48;
            LCD_ShowNum(tmp);
        }
        else{
        	LCD_ShowNum(g_F4[item]);
        }
    }
    write_com(0x93);
}

void LCD_F5_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F5_ITEM_MAX);
    write_com(0x83);
    hzkdis(F5Item[item]);
    write_com(0x93);
    if (strcmp(F5Value[item][0], "") != 0) {
        hzkdis(F5Value[item][g_F5[item]]);
    } else {
        LCD_ShowNum(g_F5[item]);
    }

    item = GET_MENU(item + 1, F5_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F5Item[item]);
    write_com(0x9b);
    if (strcmp(F5Value[item][0], "") != 0) {
        hzkdis(F5Value[item][g_F5[item]]);
    } else {
        LCD_ShowNum(g_F5[item]);
    }
    write_com(0x93);
}

void LCD_F6_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F6_ITEM_MAX);
    write_com(0x83);
    hzkdis(F6Item[item]);
    write_com(0x93);
    if (strcmp(F6Value[item][0], "") != 0) {
        hzkdis(F6Value[item][g_F6[item]]);
    } else {
        if(item == EMS_4_FuelConsumption){
        	uint32_t tmp = g_F6[item] * 100 * 5 * 0.004;
        	LCD_ShowNumWithTwoDecimals(tmp);
        }
        else if(item == F6_EMS_2_EngineSpeed){
            LCD_ShowNum(g_F6[item] * 100);
        }
        else{
        	LCD_ShowNum(g_F6[item]);
        }
    }

    item = GET_MENU(item + 1, F6_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F6Item[item]);
    write_com(0x9b);
    if (strcmp(F6Value[item][0], "") != 0) {
        hzkdis(F6Value[item][g_F6[item]]);
    } else {
        if(item == EMS_4_FuelConsumption){
        	uint32_t tmp = g_F6[item] * 100 * 5  * 0.004;
        	LCD_ShowNumWithTwoDecimals(tmp);
        }
        else if(item == F6_EMS_2_EngineSpeed){
            LCD_ShowNum(g_F6[item] * 100);
        }
        else{
        	LCD_ShowNum(g_F6[item]);
        }
    }
    write_com(0x93);
}

void LCD_F7_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F7_ITEM_MAX);
    write_com(0x83);
    hzkdis(F7Item[item]);
    write_com(0x93);
    if (strcmp(F7Value[item][0], "") != 0) {
        hzkdis(F7Value[item][g_F7[item]]);
    } else {
        if(item == F7_EMS_4_FuelConsumption){
        	uint32_t tmp = g_F7[item] * 100 * 5  * 0.004;
        	LCD_ShowNumWithTwoDecimals(tmp);
        }
        else if(item == F7_EMS_2_EngineSpeed){
        	LCD_ShowNum(g_F7[item] * 100);
        }
        else{
        	LCD_ShowNum(g_F7[item]);
        }
    }

    item = GET_MENU(item + 1, F7_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F7Item[item]);
    write_com(0x9b);
    if (strcmp(F7Value[item][0], "") != 0) {
        hzkdis(F7Value[item][g_F7[item]]);
    } else {
        if(item == F7_EMS_4_FuelConsumption){
        	uint32_t tmp = g_F7[item] * 100 * 5  * 0.004;
        	LCD_ShowNumWithTwoDecimals(tmp);
        }
        else if(item == F7_EMS_2_EngineSpeed){
        	LCD_ShowNum(g_F7[item] * 100);
        }
        else{
        	LCD_ShowNum(g_F7[item]);
        }
    }
    write_com(0x93);
}

void LCD_F8_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F8_ITEM_MAX);
    write_com(0x83);
    hzkdis(F8Item[item]);
    write_com(0x93);
    if (strcmp(F8Value[item][0], "") != 0) {
        hzkdis(F8Value[item][g_F8[item]]);
    } else {
        if(item == F8_TPMS_TirePressure){
        	uint32_t tmp = (g_F8[item] * 15  * 2.75 + 100) * 100;
        	LCD_ShowNumWithTwoDecimals(tmp);
        }
        else{
        	LCD_ShowNum(g_F8[item]);
        }
    }

    item = GET_MENU(item + 1, F8_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F8Item[item]);
    write_com(0x9b);
    if (strcmp(F8Value[item][0], "") != 0) {
        hzkdis(F8Value[item][g_F8[item]]);
    } else {
        LCD_ShowNum(g_F8[item]);
    }
    write_com(0x93);
}

void LCD_F9_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F9_ITEM_MAX);
    write_com(0x83);
    hzkdis(F9Item[item]);
    write_com(0x93);
    if (strcmp(F9Value[item][0], "") != 0) {
        hzkdis(F9Value[item][g_F9[item]]);
    } else {
        LCD_ShowNum(g_F9[item]);
    }

    item = GET_MENU(item + 1, F9_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F9Item[item]);
    write_com(0x9b);
    if (strcmp(F9Value[item][0], "") != 0) {
        hzkdis(F9Value[item][g_F9[item]]);
    } else {
        LCD_ShowNum(g_F9[item]);
    }
    write_com(0x93);
}

void LCD_F10_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F10_ITEM_MAX);
    write_com(0x83);
    hzkdis(F10Item[item]);
    write_com(0x93);
    if (strcmp(F10Value[item][0], "") != 0) {
        hzkdis(F10Value[item][g_F10[item]]);
    } else {
        LCD_ShowNum(g_F10[item]);
    }

    item = GET_MENU(item + 1, F10_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F10Item[item]);
    write_com(0x9b);
    if (strcmp(F10Value[item][0], "") != 0) {
        hzkdis(F10Value[item][g_F10[item]]);
    } else {
        LCD_ShowNum(g_F10[item]);
    }
    write_com(0x93);
}

void LCD_F11_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F11_ITEM_MAX);
    write_com(0x83);
    hzkdis(F11Item[item]);
    write_com(0x93);
    if (strcmp(F11Value[item][0], "") != 0) {
        hzkdis(F11Value[item][g_F11[item]]);
    } else {
        LCD_ShowNum(g_F11[item]);
    }

    item = GET_MENU(item + 1, F11_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F11Item[item]);
    write_com(0x9b);
    if (strcmp(F11Value[item][0], "") != 0) {
        hzkdis(F11Value[item][g_F11[item]]);
    } else {
        LCD_ShowNum(g_F11[item]);
    }
    write_com(0x93);
}

void LCD_F12_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F12_ITEM_MAX);
    write_com(0x83);
    hzkdis(F12Item[item]);
    write_com(0x93);
    if (strcmp(F12Value[item][0], "") != 0) {
        hzkdis(F12Value[item][g_F12[item]]);
    } else {
        if(item == AC_2_OutsideTemperature){
        	int32_t tmp = (g_F12[item] * 0.5) * 100 - 4000;
        	LCD_ShowNumWithTwoDecimals(tmp);
        }
        else{
        	LCD_ShowNum(g_F12[item]);
        }
    }

    item = GET_MENU(item + 1, F12_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F12Item[item]);
    write_com(0x9b);
    if (strcmp(F12Value[item][0], "") != 0) {
        hzkdis(F12Value[item][g_F12[item]]);
    } else {
        if(item == AC_2_OutsideTemperature){
        	int32_t tmp = (g_F12[item] * 0.5) * 100 - 4000;
        	LCD_ShowNumWithTwoDecimals(tmp);
        }
        else{
        	LCD_ShowNum(g_F12[item]);
        }
    }
    write_com(0x93);
}

void LCD_F13_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F13_ITEM_MAX);
    write_com(0x83);
    hzkdis(F13Item[item]);
    write_com(0x93);
    if (strcmp(F13Value[item][0], "") != 0) {
        hzkdis(F13Value[item][g_F13[item]]);
    } else {
        LCD_ShowNum(g_F13[item]);
    }

    item = GET_MENU(item + 1, F13_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F13Item[item]);
    write_com(0x9b);
    if (strcmp(F13Value[item][0], "") != 0) {
        hzkdis(F13Value[item][g_F13[item]]);
    } else {
        LCD_ShowNum(g_F13[item]);
    }
    write_com(0x93);
}

void LCD_F14_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F14_ITEM_MAX);
    write_com(0x83);
    hzkdis(F14Item[item]);
    write_com(0x93);
    if (strcmp(F14Value[item][0], "") != 0) {
        hzkdis(F14Value[item][g_F14[item]]);
    } else {
        LCD_ShowNum(g_F14[item]);
    }

    item = GET_MENU(item + 1, F14_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F14Item[item]);
    write_com(0x9b);
    if (strcmp(F14Value[item][0], "") != 0) {
        hzkdis(F14Value[item][g_F14[item]]);
    } else {
        LCD_ShowNum(g_F14[item]);
    }
    write_com(0x93);
}

void LCD_F15_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F15_ITEM_MAX);
    write_com(0x83);
    hzkdis(F15Item[item]);
    write_com(0x93);
    if (strcmp(F15Value[item][0], "") != 0) {
        hzkdis(F15Value[item][g_F15[item]]);
    } else {
        LCD_ShowNum(g_F15[item]);
    }

    item = GET_MENU(item + 1, F15_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F15Item[item]);
    write_com(0x9b);
    if (strcmp(F15Value[item][0], "") != 0) {
        hzkdis(F15Value[item][g_F15[item]]);
    } else {
        LCD_ShowNum(g_F15[item]);
    }
    write_com(0x93);
}

void LCD_F16_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F16_ITEM_MAX);
    write_com(0x83);
    hzkdis(F16Item[item]);
    write_com(0x93);
    if (strcmp(F16Value[item][0], "") != 0) {
        hzkdis(F16Value[item][g_F16[item]]);
    } else {
        LCD_ShowNum(g_F16[item]);
    }

    item = GET_MENU(item + 1, F16_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F16Item[item]);
    write_com(0x9b);
    if (strcmp(F16Value[item][0], "") != 0) {
        hzkdis(F16Value[item][g_F16[item]]);
    } else {
        LCD_ShowNum(g_F16[item]);
    }
    write_com(0x93);
}

void LCD_F17_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F17_ITEM_MAX);
    write_com(0x83);
    hzkdis(F17Item[item]);
    write_com(0x93);
    if (strcmp(F17Value[item][0], "") != 0) {
        hzkdis(F17Value[item][g_F17[item]]);
    } else {
        LCD_ShowNum(g_F17[item]);
    }

    item = GET_MENU(item + 1, F17_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F17Item[item]);
    write_com(0x9b);
    if (strcmp(F17Value[item][0], "") != 0) {
        hzkdis(F17Value[item][g_F17[item]]);
    } else {
        LCD_ShowNum(g_F17[item]);
    }
    write_com(0x93);
}

void LCD_F18_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F18_ITEM_MAX);
    write_com(0x83);
    hzkdis(F18Item[item]);
    write_com(0x93);
    if (strcmp(F18Value[item][0], "") != 0) {
        hzkdis(F18Value[item][g_F18[item]]);
    } else {
        LCD_ShowNum(g_F18[item]);
    }

    item = GET_MENU(item + 1, F18_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F18Item[item]);
    write_com(0x9b);
    if (strcmp(F18Value[item][0], "") != 0) {
        hzkdis(F18Value[item][g_F18[item]]);
    } else {
        LCD_ShowNum(g_F18[item]);
    }
    write_com(0x93);
}

void LCD_F19_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F19_ITEM_MAX);
    write_com(0x83);
    hzkdis(F19Item[item]);
    write_com(0x93);
    if (strcmp(F19Value[item][0], "") != 0) {
        hzkdis(F19Value[item][g_F19[item]]);
    } else {
        LCD_ShowNum(g_F19[item]);
    }

    item = GET_MENU(item + 1, F19_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F19Item[item]);
    write_com(0x9b);
    if (strcmp(F19Value[item][0], "") != 0) {
        hzkdis(F19Value[item][g_F19[item]]);
    } else {
        LCD_ShowNum(g_F19[item]);
    }
    write_com(0x93);
}

void LCD_F20_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F20_ITEM_MAX);
    write_com(0x83);
    hzkdis(F20Item[item]);
    write_com(0x93);
    if (strcmp(F20Value[item][0], "") != 0) {
        hzkdis(F20Value[item][g_F20[item]]);
    } else {
        LCD_ShowNum(g_F20[item]);
    }

    item = GET_MENU(item + 1, F20_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F20Item[item]);
    write_com(0x9b);
    if (strcmp(F20Value[item][0], "") != 0) {
        hzkdis(F20Value[item][g_F20[item]]);
    } else {
        LCD_ShowNum(g_F20[item]);
    }
    write_com(0x93);
}

void LCD_F21_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F21_ITEM_MAX);
    write_com(0x83);
    hzkdis(F21Item[item]);
    write_com(0x93);
    if (strcmp(F21Value[item][0], "") != 0) {
        hzkdis(F21Value[item][g_F21[item]]);
    } else {
        LCD_ShowNum(g_F21[item]);
    }

    item = GET_MENU(item + 1, F21_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F21Item[item]);
    write_com(0x9b);
    if (strcmp(F21Value[item][0], "") != 0) {
        hzkdis(F21Value[item][g_F21[item]]);
    } else {
        LCD_ShowNum(g_F21[item]);
    }
    write_com(0x93);
}

void LCD_F22_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F22_ITEM_MAX);
    write_com(0x83);
    hzkdis(F22Item[item]);
    write_com(0x93);
    if (strcmp(F22Value[item][0], "") != 0) {
        hzkdis(F22Value[item][g_F22[item]]);
    } else {
        LCD_ShowNum(g_F22[item]);
    }

    item = GET_MENU(item + 1, F22_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F22Item[item]);
    write_com(0x9b);
    if (strcmp(F22Value[item][0], "") != 0) {
        hzkdis(F22Value[item][g_F22[item]]);
    } else {
        LCD_ShowNum(g_F22[item]);
    }
    write_com(0x93);
}

void LCD_F23_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F23_ITEM_MAX);
    write_com(0x83);
    hzkdis(F23Item[item]);
    write_com(0x93);
    if (strcmp(F23Value[item][0], "") != 0) {
        hzkdis(F23Value[item][g_F23[item]]);
    } else {
        LCD_ShowNum(g_F23[item]);
    }

    item = GET_MENU(item + 1, F23_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F23Item[item]);
    write_com(0x9b);
    if (strcmp(F23Value[item][0], "") != 0) {
        hzkdis(F23Value[item][g_F23[item]]);
    } else {
        LCD_ShowNum(g_F23[item]);
    }
    write_com(0x93);
}

void LCD_F24_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F24_ITEM_MAX);
    write_com(0x83);
    hzkdis(F24Item[item]);
    write_com(0x93);
    if (strcmp(F24Value[item][0], "") != 0) {
        hzkdis(F24Value[item][g_F24[item]]);
    } else {
        LCD_ShowNum(g_F24[item]);
    }

    item = GET_MENU(item + 1, F24_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F24Item[item]);
    write_com(0x9b);
    if (strcmp(F24Value[item][0], "") != 0) {
        hzkdis(F24Value[item][g_F24[item]]);
    } else {
        LCD_ShowNum(g_F24[item]);
    }
    write_com(0x93);
}

void LCD_F25_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F25_ITEM_MAX);
    write_com(0x83);
    hzkdis(F25Item[item]);
    write_com(0x93);
    if (strcmp(F25Value[item][0], "") != 0) {
        hzkdis(F25Value[item][g_F25[item]]);
    } else {
        LCD_ShowNum(g_F25[item]);
    }

    item = GET_MENU(item + 1, F25_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F25Item[item]);
    write_com(0x9b);
    if (strcmp(F25Value[item][0], "") != 0) {
        hzkdis(F25Value[item][g_F25[item]]);
    } else {
        LCD_ShowNum(g_F25[item]);
    }
    write_com(0x93);
}

void LCD_F26_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F26_ITEM_MAX);
    write_com(0x83);
    hzkdis(F26Item[item]);
    write_com(0x93);
    if (strcmp(F26Value[item][0], "") != 0) {
        hzkdis(F26Value[item][g_F26[item]]);
    } else {
        LCD_ShowNum(g_F26[item]);
    }

    item = GET_MENU(item + 1, F26_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F26Item[item]);
    write_com(0x9b);
    if (strcmp(F26Value[item][0], "") != 0) {
        hzkdis(F26Value[item][g_F26[item]]);
    } else {
        LCD_ShowNum(g_F26[item]);
    }
    write_com(0x93);
}

void LCD_F27_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F27_ITEM_MAX);
    write_com(0x83);
    hzkdis(F27Item[item]);
    write_com(0x93);
    if (strcmp(F27Value[item][0], "") != 0) {
        hzkdis(F27Value[item][g_F27[item]]);
    } else {
        LCD_ShowNum(g_F27[item]);
    }

    item = GET_MENU(item + 1, F27_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F27Item[item]);
    write_com(0x9b);
    if (strcmp(F27Value[item][0], "") != 0) {
        hzkdis(F27Value[item][g_F27[item]]);
    } else {
        LCD_ShowNum(g_F27[item]);
    }
    write_com(0x93);
}

void LCD_F28_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F28_ITEM_MAX);
    write_com(0x83);
    hzkdis(F28Item[item]);
    write_com(0x93);
    if (strcmp(F28Value[item][0], "") != 0) {
        hzkdis(F28Value[item][g_F28[item]]);
    } else {
        LCD_ShowNum(g_F28[item]);
    }

    item = GET_MENU(item + 1, F28_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F28Item[item]);
    write_com(0x9b);
    if (strcmp(F28Value[item][0], "") != 0) {
        hzkdis(F28Value[item][g_F28[item]]);
    } else {
        LCD_ShowNum(g_F28[item]);
    }
    write_com(0x93);
}

void LCD_F29_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F29_ITEM_MAX);
    write_com(0x83);
    hzkdis(F29Item[item]);
    write_com(0x93);
    if (strcmp(F29Value[item][0], "") != 0) {
        hzkdis(F29Value[item][g_F29[item]]);
    } else {
        LCD_ShowNum(g_F29[item]);
    }

    item = GET_MENU(item + 1, F29_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F29Item[item]);
    write_com(0x9b);
    if (strcmp(F29Value[item][0], "") != 0) {
        hzkdis(F29Value[item][g_F29[item]]);
    } else {
        LCD_ShowNum(g_F29[item]);
    }
    write_com(0x93);
}

void LCD_F30_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F30_ITEM_MAX);
    write_com(0x83);
    hzkdis(F30Item[item]);
    write_com(0x93);
    if (strcmp(F30Value[item][0], "") != 0) {
        hzkdis(F30Value[item][g_F30[item]]);
    } else {
        LCD_ShowNum(g_F30[item]);
    }

    item = GET_MENU(item + 1, F30_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F30Item[item]);
    write_com(0x9b);
    if (strcmp(F30Value[item][0], "") != 0) {
        hzkdis(F30Value[item][g_F30[item]]);
    } else {
        LCD_ShowNum(g_F30[item]);
    }
    write_com(0x93);
}

// LCD显示函数指针数组
void (*LCD_Display_Page0[Page0_MENU_MAX])(uint8_t, int16_t) = {
    LCD_ACU_1_item,
	LCD_ESP_2_item,
	LCD_ABS_1_item,
	LCD_ABS_2_item,
	LCD_TPMS_1_item,
	LCD_BCM_1_item,
    LCD_BCM_3_item,
    LCD_BCM_4_item,
	LCD_BCM_5_item,
	LCD_PEPS_3_item,
    LCD_TBOX_1_item,
	LCD_TBOX_2_item,
    LCD_TBOX_4_item,
    LCD_FCM_3_item,
    LCD_FCM_4_item,
    LCD_FCM_5_item,
    LCD_FCM_6_item,
    LCD_FCM_7_item,
    LCD_FCM_8_item,
    LCD_GW_PC_1_item,
	LCD_GW_PC_6_item,
    LCD_GW_PC_2_item,
    LCD_GW_PC_7_item,
	LCD_GW_PC_4_item,
    LCD_GW_BD_9_item,
    LCD_GW_BD_14_item,
	LCD_GW_BD_24_item,
    LCD_GW_BD_29_item,
};

void (*LCD_Display_Page1[Page1_MENU_MAX])(uint8_t, int16_t) = {
	LCD_F1_item,
	LCD_F2_item,
	LCD_F3_item,
	LCD_F4_item,
	LCD_F5_item,
	LCD_F6_item,
	LCD_F7_item,
	LCD_F8_item,
	LCD_F9_item,
	LCD_F10_item,
	LCD_F11_item,
	LCD_F12_item,
	LCD_F13_item,
	LCD_F14_item,
	LCD_F15_item,
	LCD_F16_item,
	LCD_F17_item,
	LCD_F18_item,
	LCD_F19_item,
	LCD_F20_item,
	LCD_F21_item,
	LCD_F22_item,
	LCD_F23_item,
	LCD_F24_item,
	LCD_F25_item,
	LCD_F26_item,
	LCD_F27_item,
	LCD_F28_item,
	LCD_F29_item,
	LCD_F30_item,
};
