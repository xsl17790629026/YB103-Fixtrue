#ifndef _LCD128_H_
#define _LCD128_H_

#include "main.h"
#include "canbox_config.h"
#include "lcd12864_enum.h"

#define ITEM_MAX_1      1
#define ITEM_MAX_2      2
#define ITEM_MAX_3      3
#define ITEM_MAX_4      4
#define ITEM_MAX_5      5
#define ITEM_MAX_6      6
#define ITEM_MAX_7      7
#define ITEM_MAX_8      8
#define ITEM_MAX_9      9
#define ITEM_MAX_10     10
#define ITEM_MAX_16     16

#define DISPLAY_SUCCESS 0
#define DESPLAY_FAILD   1

#define SWITCH_ON       1
#define SWITCH_OFF      0

#define IGN_MAX_STS     6
#define FAIL_MAX_STS     3
#define MAX_SWITCH      2
#define MAX_MODE_STS    4
#define MAX_BGS_STS     5

#define MAX_LIGHT_LEVEL 8
#define MAX_POWER_VALUE 20  //13960
#define MAX_POWER_LIMIT 20460
#define MIN_POWER_VALUE -6500
#define MAX_ENGINESPEED 17    //16383
#define MAX_ENGINESPEED_LIMIT 16383
#define MAX_VIN_LIMIT   256


#define MENU_UNDEFINE 0xFF
#define ITEM_DEFAULT 0x0
#define VALUE_DEFAULT 0x0


#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum)) 
//IO�ڵ�ַӳ��
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C 
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C 
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C 
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C 
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C 
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C    
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C    

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808 
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08 
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008 
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408 
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808 
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08 
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08 

#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)  //输出 
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)  //输入 

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)  //输出 
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)  //输入 

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)  //输出 
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)  //输入 

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出 
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入 

#define PEout(n)   BIT_ADDR(GPIOE_ODR_Addr,n)  //输出 
#define PEin(n)    BIT_ADDR(GPIOE_IDR_Addr,n)  //输入

#define PFout(n)   BIT_ADDR(GPIOF_ODR_Addr,n)  //输出 
#define PFin(n)    BIT_ADDR(GPIOF_IDR_Addr,n)  //输入

#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //输出 
#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //输入

//#define RST      PCout(14)
#define CS       PAout(7)
#define SCLK     PAout(5)
#define SID     PAout(6)

extern uint8_t SWC_Send_Flag;

void lcd_hw_Init(void);
void lcd128_Init(void);
void write_com(uint8_t cmdcode);
void write_data(uint8_t Dispdata);
void sendbyte(uint8_t zdata);
void hzkdis(char *s);
void LCD_ShowNum(int16_t num);
void LCD_Show32Num(uint32_t num);
void LCD_ShowNumdecimal(int16_t num, uint8_t is_half);
#ifdef MCA312_HWSPEED
void Handle_HWVehspeed(void);
#endif
typedef union
{
	uint16_t speed;
	struct{
	uint8_t Vehspeed_msb;
	uint8_t Vehspeed_lsb;	
	}TCOVehs_struct;
}TCOVehs;
uint8_t GET_Vehspeed(uint8_t msb);
    

void Cls_screen(void);
void Page_0(void);
/***/
void Page_Ign(uint8_t indexraw0, uint8_t indexraw1, uint16_t indexraw2);
uint8_t LCD_Menu_Display(uint8_t menu, uint8_t item, int16_t value);
void LCD_menu(Pagedis_Func menu);
void LCD_menu_item(Pagedis_Func menu, uint8_t item, int16_t value);
uint32_t GetItem32BitValue(uint8_t menu, uint8_t item, uint8_t really_value);
Pagedis_Func GetMenuIndex();
uint8_t GetItemIndex();

void LCD_Show_CANSendClose(void);

#endif
