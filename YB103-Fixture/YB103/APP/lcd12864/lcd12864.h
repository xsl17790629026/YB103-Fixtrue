#ifndef _LCD12864_H_
#define _LCD12864_H_

#include "lcd12864_def.h"
#include "lcd12864_enum.h"

#define GET_MENU(x, max_value) ((x) >= max_value ? x-max_value : x)
#define CHECK_VALUE(x, max_value) ((x) >= max_value ? max_value-1 : x)

void LCD_ACU_1_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag);
void LCD_BCM_4_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag);
void LCD_FCM_3_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag);
void LCD_FCM_4_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag);
void LCD_GW_BD_14_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag);
void LCD_GW_BD_29_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag);
void LCD_GW_PC_1_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag);
void LCD_GW_PC_2_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag);
void LCD_TPMS_1_item_Judge(uint8_t item, uint32_t *m_value, uint8_t *flag);

void LCD_ACU_1_item(uint8_t item, int16_t value);
void LCD_BCM_3_item(uint8_t item, int16_t value);
void LCD_BCM_4_item(uint8_t item, int16_t value);
void LCD_FCM_3_item(uint8_t item, int16_t value);
void LCD_FCM_4_item(uint8_t item, int16_t value);
void LCD_GW_BD_14_item(uint8_t item, int16_t value);
void LCD_GW_BD_29_item(uint8_t item, int16_t value);
void LCD_GW_BD_9_item(uint8_t item, int16_t value);
void LCD_GW_PC_1_item(uint8_t item, int16_t value);
void LCD_GW_PC_2_item(uint8_t item, int16_t value);
void LCD_GW_PC_7_item(uint8_t item, int16_t value);
void LCD_PEPS_3_item(uint8_t item, int16_t value);
void LCD_TBOX_1_item(uint8_t item, int16_t value);
void LCD_TBOX_4_item(uint8_t item, int16_t value);
void LCD_TPMS_1_item(uint8_t item, int16_t value);
void LCD_VCU_32_item(uint8_t item, int16_t value);

uint32_t GetItemValue(uint8_t menu, uint8_t item, uint8_t really_value);
uint8_t GetItemMAXItem(uint8_t menu);
uint32_t GetItemMAXValue(uint8_t menu, uint8_t item);
void SavePage0ItemValue(Pagedis_Page0 menu, uint8_t item, int16_t value);
void SavePage1ItemValue(Pagedis_Page1 menu, uint8_t item, int16_t value);
uint8_t ItemValueLimit(uint8_t menu, uint8_t item);
uint32_t GetACU_1Value(uint8_t item);
uint32_t GetBCM_3Value(uint8_t item);
uint32_t GetBCM_4Value(uint8_t item);
uint32_t GetFCM_3Value(uint8_t item);
uint32_t GetFCM_4Value(uint8_t item);
uint32_t GetGW_BD_14Value(uint8_t item);
uint32_t GetGW_BD_29Value(uint8_t item);
uint32_t GetGW_BD_9Value(uint8_t item);
uint32_t GetGW_PC_1Value(uint8_t item);
uint32_t GetGW_PC_2Value(uint8_t item);
uint32_t GetGW_PC_7Value(uint8_t item);
uint32_t GetPEPS_3Value(uint8_t item);
uint32_t GetTBOX_1Value(uint8_t item);
uint32_t GetTBOX_4Value(uint8_t item);
uint32_t GetTPMS_1Value(uint8_t item);
uint32_t GetVCU_32Value(uint8_t item);

extern void (*LCD_Display_Page0[Page0_MENU_MAX])(uint8_t, int16_t);
extern void (*LCD_Display_Page1[Page1_MENU_MAX])(uint8_t, int16_t);

#endif // _LCD12864_H_
