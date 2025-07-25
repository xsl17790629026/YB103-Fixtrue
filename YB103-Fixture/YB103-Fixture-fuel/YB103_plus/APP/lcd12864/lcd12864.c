#include "main.h"
#include "lcd12864.h"

extern uint8_t g_menu_index;
extern uint8_t g_item_index;

static uint8_t crash_flag = 0;
static uint8_t first_crash_flag = 0;

uint8_t ItemValueLimit(uint8_t menu, uint8_t item)
{
    uint8_t res = 0;
    menu = GET_MENU(menu, MENU_MAX);
    switch(menu) {
        case F1:
            res = 0;
            break;
        case F2:
            res = 0;
            break;
        case F3:
            res = 0;
            break;
        case F4:
            res = 0;
            break;
        case F5:
            res = 0;
            break;
        case F6:
            res = 0;
            break;
        case F7:
            res = 0;
            break;
        case F8:
            res = 0;
            break;
        case F9:
            res = 0;
            break;
        case F10:
            res = 0;
            break;
        case F11:
            res = 0;
            break;
        case F12:
            res = 0;
            break;
        case F13:
            res = 0;
            break;
        case F14:
            res = 0;
            break;
        case F15:
            res = 0;
            break;
        case F16:
            res = 0;
            break;
        case F17:
            res = 0;
            break;
        case F18:
            res = 0;
            break;
        case F19:
            res = 0;
            break;
        case F20:
            res = 0;
            break;
        case F21:
            res = 0;
            break;
        case F22:
            res = 0;
            break;
        case F23:
            res = 0;
            break;
        case F24:
            res = 0;
            break;
        case F25:
            res = 0;
            break;
        case F26:
            res = 0;
            break;
        case F27:
            res = 0;
            break;
        case F28:
            res = 0;
            break;
        case F29:
            res = 0;
            break;
        case F30:
            res = 0;
            break;
        case F31:
            res = 0;
            break;
        case F32:
            res = 0;
            break;
        case F33:
            res = 0;
            break;
        case F34:
            res = 0;
            break;
        case F35:
            res = 0;
            break;
        case F36:
            res = 0;
            break;
        case F37:
            res = 0;
            break;
        case F38:
            res = 0;
            break;
        case F39:
            res = 0;
            break;
        case F40:
            res = 0;
            break;
        case F41:
            res = 0;
            break;
        case F42:
            res = 0;
            break;
        case F43:
            res = 0;
            break;
        case F44:
            res = 0;
            break;
        case F45:
            res = 0;
            break;
        case F46:
            res = 0;
            break;
        case F47:
            res = 0;
            break;
        case F48:
            res = 0;
            break;
        case F49:
            res = 0;
            break;
        case F50:
            res = 0;
            break;
        case F51:
            res = 0;
            break;
        case F52:
            res = 0;
            break;
        case F53:
            res = 0;
            break;
        case F54:
            res = 0;
            break;
        case F55:
            res = 0;
            break;
        case F56:
            res = 0;
            break;
        case F57:
            res = 0;
            break;
        case F58:
            res = 0;
            break;
        case F59:
            res = 0;
            break;
        case F60:
            res = 0;
            break;
        case F61:
            res = 0;
            break;
        case F62:
            res = 0;
            break;
        case F63:
            res = 0;
            break;
        case F64:
            res = 0;
            break;
        case F65:
            res = 0;
            break;
        case F66:
            res = 0;
            break;
        case F67:
            res = 0;
            break;
        case F68:
            res = 0;
            break;
        case F69:
            res = 0;
            break;
        case F70:
            res = 0;
            break;
        case F71:
            res = 0;
            break;
        case F72:
            res = 0;
            break;
        case F73:
            res = 0;
            break;
        case F74:
            res = 0;
            break;
        case F75:
            res = 0;
            break;
        case F76:
            res = 0;
            break;
        case F77:
            res = 0;
            break;
        case F78:
            res = 0;
            break;
        default:
            break;
    }
    return res;
}

uint32_t GetItemValue(uint8_t menu, uint8_t item, uint8_t really_value)
{
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
        case F31:
            if(item < F31_ITEM_MAX)
            {
                res = g_F31[item];
            }
            break;
        case F32:
            if(item < F32_ITEM_MAX)
            {
                res = g_F32[item];
            }
            break;
        case F33:
            if(item < F33_ITEM_MAX)
            {
                res = g_F33[item];
            }
            break;
        case F34:
            if(item < F34_ITEM_MAX)
            {
                res = g_F34[item];
            }
            break;
        case F35:
            if(item < F35_ITEM_MAX)
            {
                res = g_F35[item];
            }
            break;
        case F36:
            if(item < F36_ITEM_MAX)
            {
                res = g_F36[item];
            }
            break;
        case F37:
            if(item < F37_ITEM_MAX)
            {
                res = g_F37[item];
            }
            break;
        case F38:
            if(item < F38_ITEM_MAX)
            {
                res = g_F38[item];
            }
            break;
        case F39:
            if(item < F39_ITEM_MAX)
            {
                res = g_F39[item];
            }
            break;
        case F40:
            if(item < F40_ITEM_MAX)
            {
                res = g_F40[item];
            }
            break;
        case F41:
            if(item < F41_ITEM_MAX)
            {
                res = g_F41[item];
            }
            break;
        case F42:
            if(item < F42_ITEM_MAX)
            {
                res = g_F42[item];
            }
            break;
        case F43:
            if(item < F43_ITEM_MAX)
            {
                res = g_F43[item];
            }
            break;
        case F44:
            if(item < F44_ITEM_MAX)
            {
                res = g_F44[item];
            }
            break;
        case F45:
            if(item < F45_ITEM_MAX)
            {
                res = g_F45[item];
            }
            break;
        case F46:
            if(item < F46_ITEM_MAX)
            {
                res = g_F46[item];
            }
            break;
        case F47:
            if(item < F47_ITEM_MAX)
            {
                res = g_F47[item];
            }
            break;
        case F48:
            if(item < F48_ITEM_MAX)
            {
                res = g_F48[item];
            }
            break;
        case F49:
            if(item < F49_ITEM_MAX)
            {
                res = g_F49[item];
            }
            break;
        case F50:
            if(item < F50_ITEM_MAX)
            {
                res = g_F50[item];
            }
            break;
        case F51:
            if(item < F51_ITEM_MAX)
            {
                res = g_F51[item];
            }
            break;
        case F52:
            if(item < F52_ITEM_MAX)
            {
                res = g_F52[item];
            }
            break;
        case F53:
            if(item < F53_ITEM_MAX)
            {
                res = g_F53[item];
            }
            break;
        case F54:
            if(item < F54_ITEM_MAX)
            {
                res = g_F54[item];
            }
            break;
        case F55:
            if(item < F55_ITEM_MAX)
            {
                res = g_F55[item];
            }
            break;
        case F56:
            if(item < F56_ITEM_MAX)
            {
                res = g_F56[item];
            }
            break;
        case F57:
            if(item < F57_ITEM_MAX)
            {
                res = g_F57[item];
            }
            break;
        case F58:
            if(item < F58_ITEM_MAX)
            {
                res = g_F58[item];
            }
            break;
        case F59:
            if(item < F59_ITEM_MAX)
            {
                res = g_F59[item];
            }
            break;
        case F60:
            if(item < F60_ITEM_MAX)
            {
                res = g_F60[item];
            }
            break;
        case F61:
            if(item < F61_ITEM_MAX)
            {
                res = g_F61[item];
            }
            break;
        case F62:
            if(item < F62_ITEM_MAX)
            {
                res = g_F62[item];
            }
            break;
        case F63:
            if(item < F63_ITEM_MAX)
            {
                res = g_F63[item];
            }
            break;
        case F64:
            if(item < F64_ITEM_MAX)
            {
                res = g_F64[item];
            }
            break;
        case F65:
            if(item < F65_ITEM_MAX)
            {
                res = g_F65[item];
            }
            break;
        case F66:
            if(item < F66_ITEM_MAX)
            {
                res = g_F66[item];
            }
            break;
        case F67:
            if(item < F67_ITEM_MAX)
            {
                res = g_F67[item];
            }
            break;
        case F68:
            if(item < F68_ITEM_MAX)
            {
                res = g_F68[item];
            }
            break;
        case F69:
            if(item < F69_ITEM_MAX)
            {
                res = g_F69[item];
            }
            break;
        case F70:
            if(item < F70_ITEM_MAX)
            {
                res = g_F70[item];
            }
            break;
        case F71:
            if(item < F71_ITEM_MAX)
            {
                res = g_F71[item];
            }
            break;
        case F72:
            if(item < F72_ITEM_MAX)
            {
                res = g_F72[item];
            }
            break;
        case F73:
            if(item < F73_ITEM_MAX)
            {
                res = g_F73[item];
            }
            break;
        case F74:
            if(item < F74_ITEM_MAX)
            {
                res = g_F74[item];
            }
            break;
        case F75:
            if(item < F75_ITEM_MAX)
            {
                res = g_F75[item];
            }
            break;
        case F76:
            if(item < F76_ITEM_MAX)
            {
                res = g_F76[item];
            }
            break;
        case F77:
            if(item < F77_ITEM_MAX)
            {
                res = g_F77[item];
            }
            break;
        case F78:
            if(item < F78_ITEM_MAX)
            {
                res = g_F78[item];
            }
            break;
        default:
            break;
    }
    return res;
}

uint8_t GetItemMAXItem(uint8_t menu) 
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
        case F31:
            temp = F31_ITEM_MAX;
            break;
        case F32:
            temp = F32_ITEM_MAX;
            break;
        case F33:
            temp = F33_ITEM_MAX;
            break;
        case F34:
            temp = F34_ITEM_MAX;
            break;
        case F35:
            temp = F35_ITEM_MAX;
            break;
        case F36:
            temp = F36_ITEM_MAX;
            break;
        case F37:
            temp = F37_ITEM_MAX;
            break;
        case F38:
            temp = F38_ITEM_MAX;
            break;
        case F39:
            temp = F39_ITEM_MAX;
            break;
        case F40:
            temp = F40_ITEM_MAX;
            break;
        case F41:
            temp = F41_ITEM_MAX;
            break;
        case F42:
            temp = F42_ITEM_MAX;
            break;
        case F43:
            temp = F43_ITEM_MAX;
            break;
        case F44:
            temp = F44_ITEM_MAX;
            break;
        case F45:
            temp = F45_ITEM_MAX;
            break;
        case F46:
            temp = F46_ITEM_MAX;
            break;
        case F47:
            temp = F47_ITEM_MAX;
            break;
        case F48:
            temp = F48_ITEM_MAX;
            break;
        case F49:
            temp = F49_ITEM_MAX;
            break;
        case F50:
            temp = F50_ITEM_MAX;
            break;
        case F51:
            temp = F51_ITEM_MAX;
            break;
        case F52:
            temp = F52_ITEM_MAX;
            break;
        case F53:
            temp = F53_ITEM_MAX;
            break;
        case F54:
            temp = F54_ITEM_MAX;
            break;
        case F55:
            temp = F55_ITEM_MAX;
            break;
        case F56:
            temp = F56_ITEM_MAX;
            break;
        case F57:
            temp = F57_ITEM_MAX;
            break;
        case F58:
            temp = F58_ITEM_MAX;
            break;
        case F59:
            temp = F59_ITEM_MAX;
            break;
        case F60:
            temp = F60_ITEM_MAX;
            break;
        case F61:
            temp = F61_ITEM_MAX;
            break;
        case F62:
            temp = F62_ITEM_MAX;
            break;
        case F63:
            temp = F63_ITEM_MAX;
            break;
        case F64:
            temp = F64_ITEM_MAX;
            break;
        case F65:
            temp = F65_ITEM_MAX;
            break;
        case F66:
            temp = F66_ITEM_MAX;
            break;
        case F67:
            temp = F67_ITEM_MAX;
            break;
        case F68:
            temp = F68_ITEM_MAX;
            break;
        case F69:
            temp = F69_ITEM_MAX;
            break;
        case F70:
            temp = F70_ITEM_MAX;
            break;
        case F71:
            temp = F71_ITEM_MAX;
            break;
        case F72:
            temp = F72_ITEM_MAX;
            break;
        case F73:
            temp = F73_ITEM_MAX;
            break;
        case F74:
            temp = F74_ITEM_MAX;
            break;
        case F75:
            temp = F75_ITEM_MAX;
            break;
        case F76:
            temp = F76_ITEM_MAX;
            break;
        case F77:
            temp = F77_ITEM_MAX;
            break;
        case F78:
            temp = F78_ITEM_MAX;
            break;
        default:
            break;
    }
    return temp;
}

uint32_t GetItemMAXValue(uint8_t menu, uint8_t item)
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
		case F31:
			res = F31Max[item];
			break;
		case F32:
			res = F32Max[item];
			break;
		case F33:
			res = F33Max[item];
			break;
		case F34:
			res = F34Max[item];
			break;
		case F35:
			res = F35Max[item];
			break;
		case F36:
			res = F36Max[item];
			break;
		case F37:
			res = F37Max[item];
			break;
		case F38:
			res = F38Max[item];
			break;
		case F39:
			res = F39Max[item];
			break;
		case F40:
			res = F40Max[item];
			break;
		case F41:
			res = F41Max[item];
			break;
		case F42:
			res = F42Max[item];
			break;
		case F43:
			res = F43Max[item];
			break;
		case F44:
			res = F44Max[item];
			break;
		case F45:
			res = F45Max[item];
			break;
		case F46:
			res = F46Max[item];
			break;
		case F47:
			res = F47Max[item];
			break;
		case F48:
			res = F48Max[item];
			break;
		case F49:
			res = F49Max[item];
			break;
		case F50:
			res = F50Max[item];
			break;
		case F51:
			res = F51Max[item];
			break;
		case F52:
			res = F52Max[item];
			break;
		case F53:
			res = F53Max[item];
			break;
		case F54:
			res = F54Max[item];
			break;
		case F55:
			res = F55Max[item];
			break;
		case F56:
			res = F56Max[item];
			break;
		case F57:
			res = F57Max[item];
			break;
		case F58:
			res = F58Max[item];
			break;
		case F59:
			res = F59Max[item];
			break;
		case F60:
			res = F60Max[item];
			break;
		case F61:
			res = F61Max[item];
			break;
		case F62:
			res = F62Max[item];
			break;
		case F63:
			res = F63Max[item];
			break;
		case F64:
			res = F64Max[item];
			break;
		case F65:
			res = F65Max[item];
			break;
		case F66:
			res = F66Max[item];
			break;
		case F67:
			res = F67Max[item];
			break;
		case F68:
			res = F68Max[item];
			break;
		case F69:
			res = F69Max[item];
			break;
		case F70:
			res = F70Max[item];
			break;
		case F71:
			res = F71Max[item];
			break;
		case F72:
			res = F72Max[item];
			break;
		case F73:
			res = F73Max[item];
			break;
		case F74:
			res = F74Max[item];
			break;
		case F75:
			res = F75Max[item];
			break;
		case F76:
			res = F76Max[item];
			break;
		case F77:
			res = F77Max[item];
			break;
		case F78:
			res = F78Max[item];
			break;
        default:
            break;
    }
    return res;
}

void SaveItemValue(Pagedis_Func menu, uint8_t item, int16_t value) 
{
    g_menu_index = GET_MENU(menu, MENU_MAX);
    switch (g_menu_index)
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
    case F31:
        value = CHECK_VALUE(value, F31Max[item]);
        g_F31[item] = value;
        break;
    case F32:
        value = CHECK_VALUE(value, F32Max[item]);
        g_F32[item] = value;
        break;
    case F33:
        value = CHECK_VALUE(value, F33Max[item]);
        g_F33[item] = value;
        break;
    case F34:
        value = CHECK_VALUE(value, F34Max[item]);
        g_F34[item] = value;
        break;
    case F35:
        value = CHECK_VALUE(value, F35Max[item]);
        g_F35[item] = value;
        break;
    case F36:
        value = CHECK_VALUE(value, F36Max[item]);
        g_F36[item] = value;
        break;
    case F37:
        value = CHECK_VALUE(value, F37Max[item]);
        g_F37[item] = value;
        break;
    case F38:
        value = CHECK_VALUE(value, F38Max[item]);
        g_F38[item] = value;
        break;
    case F39:
        value = CHECK_VALUE(value, F39Max[item]);
        g_F39[item] = value;
        break;
    case F40:
        value = CHECK_VALUE(value, F40Max[item]);
        g_F40[item] = value;
        break;
    case F41:
        value = CHECK_VALUE(value, F41Max[item]);
        g_F41[item] = value;
        break;
    case F42:
        value = CHECK_VALUE(value, F42Max[item]);
        g_F42[item] = value;
        break;
    case F43:
        value = CHECK_VALUE(value, F43Max[item]);
        g_F43[item] = value;
        break;
    case F44:
        value = CHECK_VALUE(value, F44Max[item]);
        g_F44[item] = value;
        break;
    case F45:
        value = CHECK_VALUE(value, F45Max[item]);
        g_F45[item] = value;
        break;
    case F46:
        value = CHECK_VALUE(value, F46Max[item]);
        g_F46[item] = value;
        break;
    case F47:
        value = CHECK_VALUE(value, F47Max[item]);
        g_F47[item] = value;
        break;
    case F48:
        value = CHECK_VALUE(value, F48Max[item]);
        g_F48[item] = value;
        break;
    case F49:
        value = CHECK_VALUE(value, F49Max[item]);
        g_F49[item] = value;
        break;
    case F50:
        value = CHECK_VALUE(value, F50Max[item]);
        g_F50[item] = value;
        break;
    case F51:
        value = CHECK_VALUE(value, F51Max[item]);
        g_F51[item] = value;
        break;
    case F52:
        value = CHECK_VALUE(value, F52Max[item]);
        g_F52[item] = value;
        break;
    case F53:
        value = CHECK_VALUE(value, F53Max[item]);
        g_F53[item] = value;
        break;
    case F54:
        value = CHECK_VALUE(value, F54Max[item]);
        g_F54[item] = value;
        break;
    case F55:
        value = CHECK_VALUE(value, F55Max[item]);
        g_F55[item] = value;
        break;
    case F56:
        value = CHECK_VALUE(value, F56Max[item]);
        g_F56[item] = value;
        break;
    case F57:
        value = CHECK_VALUE(value, F57Max[item]);
        g_F57[item] = value;
        break;
    case F58:
        value = CHECK_VALUE(value, F58Max[item]);
        g_F58[item] = value;
        break;
    case F59:
        value = CHECK_VALUE(value, F59Max[item]);
        g_F59[item] = value;
        break;
    case F60:
        value = CHECK_VALUE(value, F60Max[item]);
        g_F60[item] = value;
        break;
    case F61:
        value = CHECK_VALUE(value, F61Max[item]);
        g_F61[item] = value;
        break;
    case F62:
        value = CHECK_VALUE(value, F62Max[item]);
        g_F62[item] = value;
        break;
    case F63:
        value = CHECK_VALUE(value, F63Max[item]);
        g_F63[item] = value;
        break;
    case F64:
        value = CHECK_VALUE(value, F64Max[item]);
        g_F64[item] = value;
        break;
    case F65:
        value = CHECK_VALUE(value, F65Max[item]);
        g_F65[item] = value;
        break;
    case F66:
        value = CHECK_VALUE(value, F66Max[item]);
        g_F66[item] = value;
        break;
    case F67:
        value = CHECK_VALUE(value, F67Max[item]);
        g_F67[item] = value;
        break;
    case F68:
        value = CHECK_VALUE(value, F68Max[item]);
        g_F68[item] = value;
        break;
    case F69:
        value = CHECK_VALUE(value, F69Max[item]);
        g_F69[item] = value;
        break;
    case F70:
        value = CHECK_VALUE(value, F70Max[item]);
        g_F70[item] = value;
        break;
    case F71:
        value = CHECK_VALUE(value, F71Max[item]);
        g_F71[item] = value;
        break;
    case F72:
        value = CHECK_VALUE(value, F72Max[item]);
        g_F72[item] = value;
        break;
    case F73:
        value = CHECK_VALUE(value, F73Max[item]);
        g_F73[item] = value;
        break;
    case F74:
        value = CHECK_VALUE(value, F74Max[item]);
        g_F74[item] = value;
        break;
    case F75:
        value = CHECK_VALUE(value, F75Max[item]);
        g_F75[item] = value;
        break;
    case F76:
        value = CHECK_VALUE(value, F76Max[item]);
        g_F76[item] = value;
        break;
    case F77:
        value = CHECK_VALUE(value, F77Max[item]);
        g_F77[item] = value;
        break;
    case F78:
        value = CHECK_VALUE(value, F78Max[item]);
        g_F78[item] = value;
        break;
        default:
            break;
    }
    g_item_index = item;
}

uint32_t GetF1Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F1_ITEM_MAX);
    if(item == ABS_3_VehicleSpeed){
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
    item = GET_MENU(item, F1_ITEM_MAX);
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
    if(item == IC_OdoMeter){
        res = g_F5[item] * 10000;
    }
    else{
        res = g_F5[item];
    }
    return res;
}

uint32_t GetF6Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F6_ITEM_MAX);
    if(item == EMS_4_FuelConsumption){
        res = g_F6[item] * 5;
    }
    else if(item == IC_SurplusMileage){
    	res = g_F6[item] * 100;
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
    if(item == IC_LifeTimeAvgFuelConsRate || item == IC_TripAvgFuelConsRate){
        res = g_F7[item] * 10;
    }
    else{
    	res = g_F7[item];
    }
    return res;
}

uint32_t GetF8Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F8_ITEM_MAX);
    if(item == TPMS_TirePressure){
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

uint32_t GetF31Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F31_ITEM_MAX);
    res = g_F31[item];
    return res;
}

uint32_t GetF32Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F32_ITEM_MAX);
    res = g_F32[item];
    return res;
}

uint32_t GetF33Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F33_ITEM_MAX);
    res = g_F33[item];
    return res;
}

uint32_t GetF34Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F34_ITEM_MAX);
    res = g_F34[item];
    return res;
}

uint32_t GetF35Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F35_ITEM_MAX);
    res = g_F35[item];
    return res;
}

uint32_t GetF36Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F36_ITEM_MAX);
    res = g_F36[item];
    return res;
}

uint32_t GetF37Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F37_ITEM_MAX);
    res = g_F37[item];
    return res;
}

uint32_t GetF38Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F38_ITEM_MAX);
    res = g_F38[item];
    return res;
}

uint32_t GetF39Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F39_ITEM_MAX);
    res = g_F39[item];
    return res;
}

uint32_t GetF40Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F40_ITEM_MAX);
    res = g_F40[item];
    return res;
}

uint32_t GetF41Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F41_ITEM_MAX);
    res = g_F41[item];
    return res;
}

uint32_t GetF42Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F42_ITEM_MAX);
    res = g_F42[item];
    return res;
}

uint32_t GetF43Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F43_ITEM_MAX);
    res = g_F43[item];
    return res;
}

uint32_t GetF44Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F44_ITEM_MAX);
    res = g_F44[item];
    return res;
}

uint32_t GetF45Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F45_ITEM_MAX);
    res = g_F45[item];
    return res;
}

uint32_t GetF46Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F46_ITEM_MAX);
    res = g_F46[item];
    return res;
}

uint32_t GetF47Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F47_ITEM_MAX);
    res = g_F47[item];
    return res;
}

uint32_t GetF48Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F48_ITEM_MAX);
    res = g_F48[item];
    return res;
}

uint32_t GetF49Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F49_ITEM_MAX);
    res = g_F49[item];
    return res;
}

uint32_t GetF50Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F50_ITEM_MAX);
    res = g_F50[item];
    return res;
}

uint32_t GetF51Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F51_ITEM_MAX);
    res = g_F51[item];
    return res;
}

uint32_t GetF52Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F52_ITEM_MAX);
    res = g_F52[item];
    return res;
}

uint32_t GetF53Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F53_ITEM_MAX);
    res = g_F53[item];
    return res;
}

uint32_t GetF54Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F54_ITEM_MAX);
    res = g_F54[item];
    return res;
}

uint32_t GetF55Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F55_ITEM_MAX);
    res = g_F55[item];
    return res;
}

uint32_t GetF56Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F56_ITEM_MAX);
    res = g_F56[item];
    return res;
}

uint32_t GetF57Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F57_ITEM_MAX);
    res = g_F57[item];
    return res;
}

uint32_t GetF58Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F58_ITEM_MAX);
    res = g_F58[item];
    return res;
}

uint32_t GetF59Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F59_ITEM_MAX);
    res = g_F59[item];
    return res;
}

uint32_t GetF60Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F60_ITEM_MAX);
    res = g_F60[item];
    return res;
}

uint32_t GetF61Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F61_ITEM_MAX);
    res = g_F61[item];
    return res;
}

uint32_t GetF62Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F62_ITEM_MAX);
    res = g_F62[item];
    return res;
}

uint32_t GetF63Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F63_ITEM_MAX);
    res = g_F63[item];
    return res;
}

uint32_t GetF64Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F64_ITEM_MAX);
    res = g_F64[item];
    return res;
}

uint32_t GetF65Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F65_ITEM_MAX);
    res = g_F65[item];
    return res;
}

uint32_t GetF66Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F66_ITEM_MAX);
    res = g_F66[item];
    return res;
}

uint32_t GetF67Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F67_ITEM_MAX);
    res = g_F67[item];
    return res;
}

uint32_t GetF68Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F68_ITEM_MAX);
    res = g_F68[item];
    return res;
}

uint32_t GetF69Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F69_ITEM_MAX);
    res = g_F69[item];
    return res;
}

uint32_t GetF70Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F70_ITEM_MAX);
    res = g_F70[item];
    return res;
}

uint32_t GetF71Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F71_ITEM_MAX);
    res = g_F71[item];
    return res;
}

uint32_t GetF72Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F72_ITEM_MAX);
    res = g_F72[item];
    return res;
}

uint32_t GetF73Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F73_ITEM_MAX);
    res = g_F73[item];
    return res;
}

uint32_t GetF74Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F74_ITEM_MAX);
    res = g_F74[item];
    return res;
}

uint32_t GetF75Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F75_ITEM_MAX);
    res = g_F75[item];
    return res;
}

uint32_t GetF76Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F76_ITEM_MAX);
    res = g_F76[item];
    return res;
}

uint32_t GetF77Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F77_ITEM_MAX);
    res = g_F77[item];
    return res;
}

uint32_t GetF78Value(uint8_t item)
{
    uint32_t res = 0u;
    item = GET_MENU(item, F78_ITEM_MAX);
    res = g_F78[item];
    return res;
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
        else if(item == IC_SurplusMileage){
        	LCD_ShowNum(g_F6[item] * 100);
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
        else if(item == IC_SurplusMileage){
        	LCD_ShowNum(g_F6[item] * 100);
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
        if(item == TPMS_TirePressure){
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

void LCD_F31_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F31_ITEM_MAX);
    write_com(0x83);
    hzkdis(F31Item[item]);
    write_com(0x93);
    if (strcmp(F31Value[item][0], "") != 0) {
        hzkdis(F31Value[item][g_F31[item]]);
    } else {
        LCD_ShowNum(g_F31[item]);
    }

    item = GET_MENU(item + 1, F31_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F31Item[item]);
    write_com(0x9b);
    if (strcmp(F31Value[item][0], "") != 0) {
        hzkdis(F31Value[item][g_F31[item]]);
    } else {
        LCD_ShowNum(g_F31[item]);
    }
    write_com(0x93);
}

void LCD_F32_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F32_ITEM_MAX);
    write_com(0x83);
    hzkdis(F32Item[item]);
    write_com(0x93);
    if (strcmp(F32Value[item][0], "") != 0) {
        hzkdis(F32Value[item][g_F32[item]]);
    } else {
        LCD_ShowNum(g_F32[item]);
    }

    item = GET_MENU(item + 1, F32_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F32Item[item]);
    write_com(0x9b);
    if (strcmp(F32Value[item][0], "") != 0) {
        hzkdis(F32Value[item][g_F32[item]]);
    } else {
        LCD_ShowNum(g_F32[item]);
    }
    write_com(0x93);
}

void LCD_F33_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F33_ITEM_MAX);
    write_com(0x83);
    hzkdis(F33Item[item]);
    write_com(0x93);
    if (strcmp(F33Value[item][0], "") != 0) {
        hzkdis(F33Value[item][g_F33[item]]);
    } else {
        LCD_ShowNum(g_F33[item]);
    }

    item = GET_MENU(item + 1, F33_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F33Item[item]);
    write_com(0x9b);
    if (strcmp(F33Value[item][0], "") != 0) {
        hzkdis(F33Value[item][g_F33[item]]);
    } else {
        LCD_ShowNum(g_F33[item]);
    }
    write_com(0x93);
}

void LCD_F34_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F34_ITEM_MAX);
    write_com(0x83);
    hzkdis(F34Item[item]);
    write_com(0x93);
    if (strcmp(F34Value[item][0], "") != 0) {
        hzkdis(F34Value[item][g_F34[item]]);
    } else {
        LCD_ShowNum(g_F34[item]);
    }

    item = GET_MENU(item + 1, F34_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F34Item[item]);
    write_com(0x9b);
    if (strcmp(F34Value[item][0], "") != 0) {
        hzkdis(F34Value[item][g_F34[item]]);
    } else {
        LCD_ShowNum(g_F34[item]);
    }
    write_com(0x93);
}

void LCD_F35_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F35_ITEM_MAX);
    write_com(0x83);
    hzkdis(F35Item[item]);
    write_com(0x93);
    if (strcmp(F35Value[item][0], "") != 0) {
        hzkdis(F35Value[item][g_F35[item]]);
    } else {
        LCD_ShowNum(g_F35[item]);
    }

    item = GET_MENU(item + 1, F35_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F35Item[item]);
    write_com(0x9b);
    if (strcmp(F35Value[item][0], "") != 0) {
        hzkdis(F35Value[item][g_F35[item]]);
    } else {
        LCD_ShowNum(g_F35[item]);
    }
    write_com(0x93);
}

void LCD_F36_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F36_ITEM_MAX);
    write_com(0x83);
    hzkdis(F36Item[item]);
    write_com(0x93);
    if (strcmp(F36Value[item][0], "") != 0) {
        hzkdis(F36Value[item][g_F36[item]]);
    } else {
        LCD_ShowNum(g_F36[item]);
    }

    item = GET_MENU(item + 1, F36_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F36Item[item]);
    write_com(0x9b);
    if (strcmp(F36Value[item][0], "") != 0) {
        hzkdis(F36Value[item][g_F36[item]]);
    } else {
        LCD_ShowNum(g_F36[item]);
    }
    write_com(0x93);
}

void LCD_F37_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F37_ITEM_MAX);
    write_com(0x83);
    hzkdis(F37Item[item]);
    write_com(0x93);
    if (strcmp(F37Value[item][0], "") != 0) {
        hzkdis(F37Value[item][g_F37[item]]);
    } else {
        LCD_ShowNum(g_F37[item]);
    }

    item = GET_MENU(item + 1, F37_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F37Item[item]);
    write_com(0x9b);
    if (strcmp(F37Value[item][0], "") != 0) {
        hzkdis(F37Value[item][g_F37[item]]);
    } else {
        LCD_ShowNum(g_F37[item]);
    }
    write_com(0x93);
}

void LCD_F38_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F38_ITEM_MAX);
    write_com(0x83);
    hzkdis(F38Item[item]);
    write_com(0x93);
    if (strcmp(F38Value[item][0], "") != 0) {
        hzkdis(F38Value[item][g_F38[item]]);
    } else {
        LCD_ShowNum(g_F38[item]);
    }

    item = GET_MENU(item + 1, F38_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F38Item[item]);
    write_com(0x9b);
    if (strcmp(F38Value[item][0], "") != 0) {
        hzkdis(F38Value[item][g_F38[item]]);
    } else {
        LCD_ShowNum(g_F38[item]);
    }
    write_com(0x93);
}

void LCD_F39_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F39_ITEM_MAX);
    write_com(0x83);
    hzkdis(F39Item[item]);
    write_com(0x93);
    if (strcmp(F39Value[item][0], "") != 0) {
        hzkdis(F39Value[item][g_F39[item]]);
    } else {
        LCD_ShowNum(g_F39[item]);
    }

    item = GET_MENU(item + 1, F39_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F39Item[item]);
    write_com(0x9b);
    if (strcmp(F39Value[item][0], "") != 0) {
        hzkdis(F39Value[item][g_F39[item]]);
    } else {
        LCD_ShowNum(g_F39[item]);
    }
    write_com(0x93);
}

void LCD_F40_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F40_ITEM_MAX);
    write_com(0x83);
    hzkdis(F40Item[item]);
    write_com(0x93);
    if (strcmp(F40Value[item][0], "") != 0) {
        hzkdis(F40Value[item][g_F40[item]]);
    } else {
        LCD_ShowNum(g_F40[item]);
    }

    item = GET_MENU(item + 1, F40_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F40Item[item]);
    write_com(0x9b);
    if (strcmp(F40Value[item][0], "") != 0) {
        hzkdis(F40Value[item][g_F40[item]]);
    } else {
        LCD_ShowNum(g_F40[item]);
    }
    write_com(0x93);
}

void LCD_F41_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F41_ITEM_MAX);
    write_com(0x83);
    hzkdis(F41Item[item]);
    write_com(0x93);
    if (strcmp(F41Value[item][0], "") != 0) {
        hzkdis(F41Value[item][g_F41[item]]);
    } else {
        LCD_ShowNum(g_F41[item]);
    }

    item = GET_MENU(item + 1, F41_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F41Item[item]);
    write_com(0x9b);
    if (strcmp(F41Value[item][0], "") != 0) {
        hzkdis(F41Value[item][g_F41[item]]);
    } else {
        LCD_ShowNum(g_F41[item]);
    }
    write_com(0x93);
}

void LCD_F42_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F42_ITEM_MAX);
    write_com(0x83);
    hzkdis(F42Item[item]);
    write_com(0x93);
    if (strcmp(F42Value[item][0], "") != 0) {
        hzkdis(F42Value[item][g_F42[item]]);
    } else {
        LCD_ShowNum(g_F42[item]);
    }

    item = GET_MENU(item + 1, F42_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F42Item[item]);
    write_com(0x9b);
    if (strcmp(F42Value[item][0], "") != 0) {
        hzkdis(F42Value[item][g_F42[item]]);
    } else {
        LCD_ShowNum(g_F42[item]);
    }
    write_com(0x93);
}

void LCD_F43_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F43_ITEM_MAX);
    write_com(0x83);
    hzkdis(F43Item[item]);
    write_com(0x93);
    if (strcmp(F43Value[item][0], "") != 0) {
        hzkdis(F43Value[item][g_F43[item]]);
    } else {
        LCD_ShowNum(g_F43[item]);
    }

    item = GET_MENU(item + 1, F43_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F43Item[item]);
    write_com(0x9b);
    if (strcmp(F43Value[item][0], "") != 0) {
        hzkdis(F43Value[item][g_F43[item]]);
    } else {
        LCD_ShowNum(g_F43[item]);
    }
    write_com(0x93);
}

void LCD_F44_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F44_ITEM_MAX);
    write_com(0x83);
    hzkdis(F44Item[item]);
    write_com(0x93);
    if (strcmp(F44Value[item][0], "") != 0) {
        hzkdis(F44Value[item][g_F44[item]]);
    } else {
        LCD_ShowNum(g_F44[item]);
    }

    item = GET_MENU(item + 1, F44_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F44Item[item]);
    write_com(0x9b);
    if (strcmp(F44Value[item][0], "") != 0) {
        hzkdis(F44Value[item][g_F44[item]]);
    } else {
        LCD_ShowNum(g_F44[item]);
    }
    write_com(0x93);
}

void LCD_F45_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F45_ITEM_MAX);
    write_com(0x83);
    hzkdis(F45Item[item]);
    write_com(0x93);
    if (strcmp(F45Value[item][0], "") != 0) {
        hzkdis(F45Value[item][g_F45[item]]);
    } else {
        LCD_ShowNum(g_F45[item]);
    }

    item = GET_MENU(item + 1, F45_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F45Item[item]);
    write_com(0x9b);
    if (strcmp(F45Value[item][0], "") != 0) {
        hzkdis(F45Value[item][g_F45[item]]);
    } else {
        LCD_ShowNum(g_F45[item]);
    }
    write_com(0x93);
}

void LCD_F46_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F46_ITEM_MAX);
    write_com(0x83);
    hzkdis(F46Item[item]);
    write_com(0x93);
    if (strcmp(F46Value[item][0], "") != 0) {
        hzkdis(F46Value[item][g_F46[item]]);
    } else {
        LCD_ShowNum(g_F46[item]);
    }

    item = GET_MENU(item + 1, F46_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F46Item[item]);
    write_com(0x9b);
    if (strcmp(F46Value[item][0], "") != 0) {
        hzkdis(F46Value[item][g_F46[item]]);
    } else {
        LCD_ShowNum(g_F46[item]);
    }
    write_com(0x93);
}

void LCD_F47_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F47_ITEM_MAX);
    write_com(0x83);
    hzkdis(F47Item[item]);
    write_com(0x93);
    if (strcmp(F47Value[item][0], "") != 0) {
        hzkdis(F47Value[item][g_F47[item]]);
    } else {
        LCD_ShowNum(g_F47[item]);
    }

    item = GET_MENU(item + 1, F47_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F47Item[item]);
    write_com(0x9b);
    if (strcmp(F47Value[item][0], "") != 0) {
        hzkdis(F47Value[item][g_F47[item]]);
    } else {
        LCD_ShowNum(g_F47[item]);
    }
    write_com(0x93);
}

void LCD_F48_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F48_ITEM_MAX);
    write_com(0x83);
    hzkdis(F48Item[item]);
    write_com(0x93);
    if (strcmp(F48Value[item][0], "") != 0) {
        hzkdis(F48Value[item][g_F48[item]]);
    } else {
        LCD_ShowNum(g_F48[item]);
    }

    item = GET_MENU(item + 1, F48_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F48Item[item]);
    write_com(0x9b);
    if (strcmp(F48Value[item][0], "") != 0) {
        hzkdis(F48Value[item][g_F48[item]]);
    } else {
        LCD_ShowNum(g_F48[item]);
    }
    write_com(0x93);
}

void LCD_F49_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F49_ITEM_MAX);
    write_com(0x83);
    hzkdis(F49Item[item]);
    write_com(0x93);
    if (strcmp(F49Value[item][0], "") != 0) {
        hzkdis(F49Value[item][g_F49[item]]);
    } else {
        LCD_ShowNum(g_F49[item]);
    }

    item = GET_MENU(item + 1, F49_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F49Item[item]);
    write_com(0x9b);
    if (strcmp(F49Value[item][0], "") != 0) {
        hzkdis(F49Value[item][g_F49[item]]);
    } else {
        LCD_ShowNum(g_F49[item]);
    }
    write_com(0x93);
}

void LCD_F50_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F50_ITEM_MAX);
    write_com(0x83);
    hzkdis(F50Item[item]);
    write_com(0x93);
    if (strcmp(F50Value[item][0], "") != 0) {
        hzkdis(F50Value[item][g_F50[item]]);
    } else {
        LCD_ShowNum(g_F50[item]);
    }

    item = GET_MENU(item + 1, F50_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F50Item[item]);
    write_com(0x9b);
    if (strcmp(F50Value[item][0], "") != 0) {
        hzkdis(F50Value[item][g_F50[item]]);
    } else {
        LCD_ShowNum(g_F50[item]);
    }
    write_com(0x93);
}

void LCD_F51_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F51_ITEM_MAX);
    write_com(0x83);
    hzkdis(F51Item[item]);
    write_com(0x93);
    if (strcmp(F51Value[item][0], "") != 0) {
        hzkdis(F51Value[item][g_F51[item]]);
    } else {
        LCD_ShowNum(g_F51[item]);
    }

    item = GET_MENU(item + 1, F51_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F51Item[item]);
    write_com(0x9b);
    if (strcmp(F51Value[item][0], "") != 0) {
        hzkdis(F51Value[item][g_F51[item]]);
    } else {
        LCD_ShowNum(g_F51[item]);
    }
    write_com(0x93);
}

void LCD_F52_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F52_ITEM_MAX);
    write_com(0x83);
    hzkdis(F52Item[item]);
    write_com(0x93);
    if (strcmp(F52Value[item][0], "") != 0) {
        hzkdis(F52Value[item][g_F52[item]]);
    } else {
        LCD_ShowNum(g_F52[item]);
    }

    item = GET_MENU(item + 1, F52_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F52Item[item]);
    write_com(0x9b);
    if (strcmp(F52Value[item][0], "") != 0) {
        hzkdis(F52Value[item][g_F52[item]]);
    } else {
        LCD_ShowNum(g_F52[item]);
    }
    write_com(0x93);
}

void LCD_F53_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F53_ITEM_MAX);
    write_com(0x83);
    hzkdis(F53Item[item]);
    write_com(0x93);
    if (strcmp(F53Value[item][0], "") != 0) {
        hzkdis(F53Value[item][g_F53[item]]);
    } else {
        LCD_ShowNum(g_F53[item]);
    }

    item = GET_MENU(item + 1, F53_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F53Item[item]);
    write_com(0x9b);
    if (strcmp(F53Value[item][0], "") != 0) {
        hzkdis(F53Value[item][g_F53[item]]);
    } else {
        LCD_ShowNum(g_F53[item]);
    }
    write_com(0x93);
}

void LCD_F54_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F54_ITEM_MAX);
    write_com(0x83);
    hzkdis(F54Item[item]);
    write_com(0x93);
    if (strcmp(F54Value[item][0], "") != 0) {
        hzkdis(F54Value[item][g_F54[item]]);
    } else {
        LCD_ShowNum(g_F54[item]);
    }

    item = GET_MENU(item + 1, F54_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F54Item[item]);
    write_com(0x9b);
    if (strcmp(F54Value[item][0], "") != 0) {
        hzkdis(F54Value[item][g_F54[item]]);
    } else {
        LCD_ShowNum(g_F54[item]);
    }
    write_com(0x93);
}

void LCD_F55_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F55_ITEM_MAX);
    write_com(0x83);
    hzkdis(F55Item[item]);
    write_com(0x93);
    if (strcmp(F55Value[item][0], "") != 0) {
        hzkdis(F55Value[item][g_F55[item]]);
    } else {
        LCD_ShowNum(g_F55[item]);
    }

    item = GET_MENU(item + 1, F55_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F55Item[item]);
    write_com(0x9b);
    if (strcmp(F55Value[item][0], "") != 0) {
        hzkdis(F55Value[item][g_F55[item]]);
    } else {
        LCD_ShowNum(g_F55[item]);
    }
    write_com(0x93);
}

void LCD_F56_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F56_ITEM_MAX);
    write_com(0x83);
    hzkdis(F56Item[item]);
    write_com(0x93);
    if (strcmp(F56Value[item][0], "") != 0) {
        hzkdis(F56Value[item][g_F56[item]]);
    } else {
        LCD_ShowNum(g_F56[item]);
    }

    item = GET_MENU(item + 1, F56_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F56Item[item]);
    write_com(0x9b);
    if (strcmp(F56Value[item][0], "") != 0) {
        hzkdis(F56Value[item][g_F56[item]]);
    } else {
        LCD_ShowNum(g_F56[item]);
    }
    write_com(0x93);
}

void LCD_F57_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F57_ITEM_MAX);
    write_com(0x83);
    hzkdis(F57Item[item]);
    write_com(0x93);
    if (strcmp(F57Value[item][0], "") != 0) {
        hzkdis(F57Value[item][g_F57[item]]);
    } else {
        LCD_ShowNum(g_F57[item]);
    }

    item = GET_MENU(item + 1, F57_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F57Item[item]);
    write_com(0x9b);
    if (strcmp(F57Value[item][0], "") != 0) {
        hzkdis(F57Value[item][g_F57[item]]);
    } else {
        LCD_ShowNum(g_F57[item]);
    }
    write_com(0x93);
}

void LCD_F58_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F58_ITEM_MAX);
    write_com(0x83);
    hzkdis(F58Item[item]);
    write_com(0x93);
    if (strcmp(F58Value[item][0], "") != 0) {
        hzkdis(F58Value[item][g_F58[item]]);
    } else {
        LCD_ShowNum(g_F58[item]);
    }

    item = GET_MENU(item + 1, F58_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F58Item[item]);
    write_com(0x9b);
    if (strcmp(F58Value[item][0], "") != 0) {
        hzkdis(F58Value[item][g_F58[item]]);
    } else {
        LCD_ShowNum(g_F58[item]);
    }
    write_com(0x93);
}

void LCD_F59_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F59_ITEM_MAX);
    write_com(0x83);
    hzkdis(F59Item[item]);
    write_com(0x93);
    if (strcmp(F59Value[item][0], "") != 0) {
        hzkdis(F59Value[item][g_F59[item]]);
    } else {
        LCD_ShowNum(g_F59[item]);
    }

    item = GET_MENU(item + 1, F59_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F59Item[item]);
    write_com(0x9b);
    if (strcmp(F59Value[item][0], "") != 0) {
        hzkdis(F59Value[item][g_F59[item]]);
    } else {
        LCD_ShowNum(g_F59[item]);
    }
    write_com(0x93);
}

void LCD_F60_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F60_ITEM_MAX);
    write_com(0x83);
    hzkdis(F60Item[item]);
    write_com(0x93);
    if (strcmp(F60Value[item][0], "") != 0) {
        hzkdis(F60Value[item][g_F60[item]]);
    } else {
        LCD_ShowNum(g_F60[item]);
    }

    item = GET_MENU(item + 1, F60_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F60Item[item]);
    write_com(0x9b);
    if (strcmp(F60Value[item][0], "") != 0) {
        hzkdis(F60Value[item][g_F60[item]]);
    } else {
        LCD_ShowNum(g_F60[item]);
    }
    write_com(0x93);
}

void LCD_F61_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F61_ITEM_MAX);
    write_com(0x83);
    hzkdis(F61Item[item]);
    write_com(0x93);
    if (strcmp(F61Value[item][0], "") != 0) {
        hzkdis(F61Value[item][g_F61[item]]);
    } else {
        LCD_ShowNum(g_F61[item]);
    }

    item = GET_MENU(item + 1, F61_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F61Item[item]);
    write_com(0x9b);
    if (strcmp(F61Value[item][0], "") != 0) {
        hzkdis(F61Value[item][g_F61[item]]);
    } else {
        LCD_ShowNum(g_F61[item]);
    }
    write_com(0x93);
}

void LCD_F62_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F62_ITEM_MAX);
    write_com(0x83);
    hzkdis(F62Item[item]);
    write_com(0x93);
    if (strcmp(F62Value[item][0], "") != 0) {
        hzkdis(F62Value[item][g_F62[item]]);
    } else {
        LCD_ShowNum(g_F62[item]);
    }

    item = GET_MENU(item + 1, F62_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F62Item[item]);
    write_com(0x9b);
    if (strcmp(F62Value[item][0], "") != 0) {
        hzkdis(F62Value[item][g_F62[item]]);
    } else {
        LCD_ShowNum(g_F62[item]);
    }
    write_com(0x93);
}

void LCD_F63_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F63_ITEM_MAX);
    write_com(0x83);
    hzkdis(F63Item[item]);
    write_com(0x93);
    if (strcmp(F63Value[item][0], "") != 0) {
        hzkdis(F63Value[item][g_F63[item]]);
    } else {
        LCD_ShowNum(g_F63[item]);
    }

    item = GET_MENU(item + 1, F63_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F63Item[item]);
    write_com(0x9b);
    if (strcmp(F63Value[item][0], "") != 0) {
        hzkdis(F63Value[item][g_F63[item]]);
    } else {
        LCD_ShowNum(g_F63[item]);
    }
    write_com(0x93);
}

void LCD_F64_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F64_ITEM_MAX);
    write_com(0x83);
    hzkdis(F64Item[item]);
    write_com(0x93);
    if (strcmp(F64Value[item][0], "") != 0) {
        hzkdis(F64Value[item][g_F64[item]]);
    } else {
        LCD_ShowNum(g_F64[item]);
    }

    item = GET_MENU(item + 1, F64_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F64Item[item]);
    write_com(0x9b);
    if (strcmp(F64Value[item][0], "") != 0) {
        hzkdis(F64Value[item][g_F64[item]]);
    } else {
        LCD_ShowNum(g_F64[item]);
    }
    write_com(0x93);
}

void LCD_F65_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F65_ITEM_MAX);
    write_com(0x83);
    hzkdis(F65Item[item]);
    write_com(0x93);
    if (strcmp(F65Value[item][0], "") != 0) {
        hzkdis(F65Value[item][g_F65[item]]);
    } else {
        LCD_ShowNum(g_F65[item]);
    }

    item = GET_MENU(item + 1, F65_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F65Item[item]);
    write_com(0x9b);
    if (strcmp(F65Value[item][0], "") != 0) {
        hzkdis(F65Value[item][g_F65[item]]);
    } else {
        LCD_ShowNum(g_F65[item]);
    }
    write_com(0x93);
}

void LCD_F66_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F66_ITEM_MAX);
    write_com(0x83);
    hzkdis(F66Item[item]);
    write_com(0x93);
    if (strcmp(F66Value[item][0], "") != 0) {
        hzkdis(F66Value[item][g_F66[item]]);
    } else {
        LCD_ShowNum(g_F66[item]);
    }

    item = GET_MENU(item + 1, F66_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F66Item[item]);
    write_com(0x9b);
    if (strcmp(F66Value[item][0], "") != 0) {
        hzkdis(F66Value[item][g_F66[item]]);
    } else {
        LCD_ShowNum(g_F66[item]);
    }
    write_com(0x93);
}

void LCD_F67_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F67_ITEM_MAX);
    write_com(0x83);
    hzkdis(F67Item[item]);
    write_com(0x93);
    if (strcmp(F67Value[item][0], "") != 0) {
        hzkdis(F67Value[item][g_F67[item]]);
    } else {
        LCD_ShowNum(g_F67[item]);
    }

    item = GET_MENU(item + 1, F67_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F67Item[item]);
    write_com(0x9b);
    if (strcmp(F67Value[item][0], "") != 0) {
        hzkdis(F67Value[item][g_F67[item]]);
    } else {
        LCD_ShowNum(g_F67[item]);
    }
    write_com(0x93);
}

void LCD_F68_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F68_ITEM_MAX);
    write_com(0x83);
    hzkdis(F68Item[item]);
    write_com(0x93);
    if (strcmp(F68Value[item][0], "") != 0) {
        hzkdis(F68Value[item][g_F68[item]]);
    } else {
        LCD_ShowNum(g_F68[item]);
    }

    item = GET_MENU(item + 1, F68_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F68Item[item]);
    write_com(0x9b);
    if (strcmp(F68Value[item][0], "") != 0) {
        hzkdis(F68Value[item][g_F68[item]]);
    } else {
        LCD_ShowNum(g_F68[item]);
    }
    write_com(0x93);
}

void LCD_F69_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F69_ITEM_MAX);
    write_com(0x83);
    hzkdis(F69Item[item]);
    write_com(0x93);
    if (strcmp(F69Value[item][0], "") != 0) {
        hzkdis(F69Value[item][g_F69[item]]);
    } else {
        LCD_ShowNum(g_F69[item]);
    }

    item = GET_MENU(item + 1, F69_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F69Item[item]);
    write_com(0x9b);
    if (strcmp(F69Value[item][0], "") != 0) {
        hzkdis(F69Value[item][g_F69[item]]);
    } else {
        LCD_ShowNum(g_F69[item]);
    }
    write_com(0x93);
}

void LCD_F70_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F70_ITEM_MAX);
    write_com(0x83);
    hzkdis(F70Item[item]);
    write_com(0x93);
    if (strcmp(F70Value[item][0], "") != 0) {
        hzkdis(F70Value[item][g_F70[item]]);
    } else {
        LCD_ShowNum(g_F70[item]);
    }

    item = GET_MENU(item + 1, F70_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F70Item[item]);
    write_com(0x9b);
    if (strcmp(F70Value[item][0], "") != 0) {
        hzkdis(F70Value[item][g_F70[item]]);
    } else {
        LCD_ShowNum(g_F70[item]);
    }
    write_com(0x93);
}

void LCD_F71_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F71_ITEM_MAX);
    write_com(0x83);
    hzkdis(F71Item[item]);
    write_com(0x93);
    if (strcmp(F71Value[item][0], "") != 0) {
        hzkdis(F71Value[item][g_F71[item]]);
    } else {
        LCD_ShowNum(g_F71[item]);
    }

    item = GET_MENU(item + 1, F71_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F71Item[item]);
    write_com(0x9b);
    if (strcmp(F71Value[item][0], "") != 0) {
        hzkdis(F71Value[item][g_F71[item]]);
    } else {
        LCD_ShowNum(g_F71[item]);
    }
    write_com(0x93);
}

void LCD_F72_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F72_ITEM_MAX);
    write_com(0x83);
    hzkdis(F72Item[item]);
    write_com(0x93);
    if (strcmp(F72Value[item][0], "") != 0) {
        hzkdis(F72Value[item][g_F72[item]]);
    } else {
        LCD_ShowNum(g_F72[item]);
    }

    item = GET_MENU(item + 1, F72_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F72Item[item]);
    write_com(0x9b);
    if (strcmp(F72Value[item][0], "") != 0) {
        hzkdis(F72Value[item][g_F72[item]]);
    } else {
        LCD_ShowNum(g_F72[item]);
    }
    write_com(0x93);
}

void LCD_F73_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F73_ITEM_MAX);
    write_com(0x83);
    hzkdis(F73Item[item]);
    write_com(0x93);
    if (strcmp(F73Value[item][0], "") != 0) {
        hzkdis(F73Value[item][g_F73[item]]);
    } else {
        LCD_ShowNum(g_F73[item]);
    }

    item = GET_MENU(item + 1, F73_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F73Item[item]);
    write_com(0x9b);
    if (strcmp(F73Value[item][0], "") != 0) {
        hzkdis(F73Value[item][g_F73[item]]);
    } else {
        LCD_ShowNum(g_F73[item]);
    }
    write_com(0x93);
}

void LCD_F74_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F74_ITEM_MAX);
    write_com(0x83);
    hzkdis(F74Item[item]);
    write_com(0x93);
    if (strcmp(F74Value[item][0], "") != 0) {
        hzkdis(F74Value[item][g_F74[item]]);
    } else {
        LCD_ShowNum(g_F74[item]);
    }

    item = GET_MENU(item + 1, F74_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F74Item[item]);
    write_com(0x9b);
    if (strcmp(F74Value[item][0], "") != 0) {
        hzkdis(F74Value[item][g_F74[item]]);
    } else {
        LCD_ShowNum(g_F74[item]);
    }
    write_com(0x93);
}

void LCD_F75_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F75_ITEM_MAX);
    write_com(0x83);
    hzkdis(F75Item[item]);
    write_com(0x93);
    if (strcmp(F75Value[item][0], "") != 0) {
        hzkdis(F75Value[item][g_F75[item]]);
    } else {
        LCD_ShowNum(g_F75[item]);
    }

    item = GET_MENU(item + 1, F75_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F75Item[item]);
    write_com(0x9b);
    if (strcmp(F75Value[item][0], "") != 0) {
        hzkdis(F75Value[item][g_F75[item]]);
    } else {
        LCD_ShowNum(g_F75[item]);
    }
    write_com(0x93);
}

void LCD_F76_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F76_ITEM_MAX);
    write_com(0x83);
    hzkdis(F76Item[item]);
    write_com(0x93);
    if (strcmp(F76Value[item][0], "") != 0) {
        hzkdis(F76Value[item][g_F76[item]]);
    } else {
        LCD_ShowNum(g_F76[item]);
    }

    item = GET_MENU(item + 1, F76_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F76Item[item]);
    write_com(0x9b);
    if (strcmp(F76Value[item][0], "") != 0) {
        hzkdis(F76Value[item][g_F76[item]]);
    } else {
        LCD_ShowNum(g_F76[item]);
    }
    write_com(0x93);
}

void LCD_F77_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F77_ITEM_MAX);
    write_com(0x83);
    hzkdis(F77Item[item]);
    write_com(0x93);
    if (strcmp(F77Value[item][0], "") != 0) {
        hzkdis(F77Value[item][g_F77[item]]);
    } else {
        LCD_ShowNum(g_F77[item]);
    }

    item = GET_MENU(item + 1, F77_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F77Item[item]);
    write_com(0x9b);
    if (strcmp(F77Value[item][0], "") != 0) {
        hzkdis(F77Value[item][g_F77[item]]);
    } else {
        LCD_ShowNum(g_F77[item]);
    }
    write_com(0x93);
}

void LCD_F78_item(uint8_t item, int16_t value)
{
    item = GET_MENU(item, F78_ITEM_MAX);
    write_com(0x83);
    hzkdis(F78Item[item]);
    write_com(0x93);
    if (strcmp(F78Value[item][0], "") != 0) {
        hzkdis(F78Value[item][g_F78[item]]);
    } else {
        LCD_ShowNum(g_F78[item]);
    }

    item = GET_MENU(item + 1, F78_ITEM_MAX);
    write_com(0x8b);
    hzkdis(F78Item[item]);
    write_com(0x9b);
    if (strcmp(F78Value[item][0], "") != 0) {
        hzkdis(F78Value[item][g_F78[item]]);
    } else {
        LCD_ShowNum(g_F78[item]);
    }
    write_com(0x93);
}

// LCD显示函数指针数组
void (*LCD_Display_Func[MENU_MAX])(uint8_t, int16_t) = {
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
    LCD_F31_item,
    LCD_F32_item,
    LCD_F33_item,
    LCD_F34_item,
    LCD_F35_item,
    LCD_F36_item,
    LCD_F37_item,
    LCD_F38_item,
    LCD_F39_item,
    LCD_F40_item,
    LCD_F41_item,
    LCD_F42_item,
    LCD_F43_item,
    LCD_F44_item,
    LCD_F45_item,
    LCD_F46_item,
    LCD_F47_item,
    LCD_F48_item,
    LCD_F49_item,
    LCD_F50_item,
    LCD_F51_item,
    LCD_F52_item,
    LCD_F53_item,
    LCD_F54_item,
    LCD_F55_item,
    LCD_F56_item,
    LCD_F57_item,
    LCD_F58_item,
    LCD_F59_item,
    LCD_F60_item,
    LCD_F61_item,
    LCD_F62_item,
    LCD_F63_item,
    LCD_F64_item,
    LCD_F65_item,
    LCD_F66_item,
    LCD_F67_item,
    LCD_F68_item,
    LCD_F69_item,
    LCD_F70_item,
    LCD_F71_item,
    LCD_F72_item,
    LCD_F73_item,
    LCD_F74_item,
    LCD_F75_item,
    LCD_F76_item,
    LCD_F77_item,
    LCD_F78_item,
};

