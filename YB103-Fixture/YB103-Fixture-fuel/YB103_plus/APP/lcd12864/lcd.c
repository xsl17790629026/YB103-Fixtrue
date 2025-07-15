/*****************************************
*Company:
*
*File:lcd28.c
*
*Description：
*
*Author:
*
*Data: 
******************************************/
#include "lcd.h"
#include "math.h"
#include "key.h"
//#include "can_transmit.h"
#include "config.h"
#include "lcd12864.h"
#include "lcd12864_enum.h"

void delay_us(uint16_t nus)
{
	uint16_t i,j = 0u;

	for(i = 0u; i< nus; i++)
	{
		for(j = 0u; j < 20u; j++)
		{
			__NOP();
		}
	}
}

void delay(uint16_t nms)
{
	uint16_t i = 0u;
	for(i =0u; i < nms; i++)
	{
	delay_us(100);
	}
}

static uint8_t Asci2[36] = {
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, // '0' to '9'
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, // 'A' to 'J'
    75, 76, 77, 78, 79, 80, 81, 82, 83, 84, // 'K' to 'T'
    85, 86, 87, 88, 89, 90                 // 'U' to 'Z'
};

extern uint8_t Can_TxReq_Status[];
				
uint8_t g_menu_index = 0;//MENU_UNDEFINE;
uint8_t g_item_index = 0;//ITEM_DEFAULT;
uint8_t vin_number = 0;

#if MCA312_HWSPEED
void Handle_HWVehspeed(void)
{
	static uint8_t per = 0U;
	if(per == 0U)
	{
        Set_RISING_cnt(0);
	}
	per++;
    if(per == 11U)
	{
        g_speed[VehSpeed] = (uint16_t)Get_RISING_cnt()*3/2;
        per = 0U;
	}
}
#endif
        
void lcd_hw_Init(void)
{
    GPIO_InitTypeDef  GPIO_Initure;

    __HAL_RCC_GPIOA_CLK_ENABLE();   
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
    GPIO_Initure.Pin=GPIO_PIN_7;	
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;	
    GPIO_Initure.Pull=GPIO_PULLUP;        	
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);   	
	 
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
	
/*************************************************
    GPIO_Initure.Pin=GPIO_PIN_14;	
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;	
    GPIO_Initure.Pull=GPIO_PULLUP;        	
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);   	
	 
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,GPIO_PIN_SET);	
*******************************************************/	

    GPIO_Initure.Pin=GPIO_PIN_5|GPIO_PIN_6;
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;	
    GPIO_Initure.Pull=GPIO_PULLUP;        	
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;   	
    HAL_GPIO_Init(GPIOA,&GPIO_Initure); 
  
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET); 
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET); 	
	
}

void lcd128_Init(void)
{  
	lcd_hw_Init();
	//RST = 0;
	delay(2000);
	//RST = 1;
	//delay(20000);
	write_com(0x30);
	delay(50);
	write_com(0x0c);
	delay(50);
	write_com(0x0F);
	
    Page_0();
	delay(10000);
}

void write_com(uint8_t cmdcode)
{
	CS = 1;
	sendbyte(0xf8);
	sendbyte(cmdcode & 0xf0);
	sendbyte((cmdcode << 4) & 0xf0);
	delay(2);
}
/********************************************************************

***********************************************************************/
void write_data(uint8_t Dispdata)
{
	CS = 1;
	sendbyte(0xfa);
	sendbyte(Dispdata & 0xf0);
	sendbyte((Dispdata << 4) & 0xf0);
	delay(2);
}

/********************************************************************

***********************************************************************/
void sendbyte(uint8_t zdata)
{
	unsigned int i;
	for(i=0; i<8; i++)
	{
		if((zdata << i) & 0x80)
		{
			SID = 1;
		}
		else 
		{
			SID = 0;
		}
		SCLK = 0;
		SCLK = 1;
	}
}
	
/********************************************************************

***********************************************************************/

void hzkdis(char *s)
{
	while(*s > 0)
    { 
		write_data(*s);
		s++;
		delay_us(50);
    }
}

void LCD_ShowNumWithTwoDecimals(int32_t num)
{
    uint8_t integerPart[5] = {0}; // 存储整数部分各位，最多 5 位（考虑符号等情况，可根据实际调整）
    uint8_t decimalPart[2] = {0}; // 存储小数点后两位
    int32_t absNum = abs(num);
    int i = 0, j = 0;
    int isNegative = num < 0 ? 1 : 0;

    // 拆分出小数点后两位
    decimalPart[0] = (absNum / 10) % 10;
    decimalPart[1] = absNum % 10;
    // 得到去掉小数部分后的整数（即原数放大 100 倍后的整数部分再除以 100）
    int32_t integerNum = absNum / 100;

    // 处理整数部分，拆分成各个数字位存到数组
    if (integerNum == 0) {
        integerPart[i++] = 0;
    } else {
        while (integerNum > 0) {
            integerPart[i++] = integerNum % 10;
            integerNum /= 10;
        }
    }

    // 显示负号
    if (isNegative) {
        write_data('-');
    }

    // 倒序显示整数部分数字
    for (j = i - 1; j >= 0; j--) {
        write_data(integerPart[j] + 0x30);
    }

    // 显示小数点
    write_data('.');

    // 显示小数点后两位
    write_data(decimalPart[0] + 0x30);
    write_data(decimalPart[1] + 0x30);
}

void LCD_ShowNum(int16_t num)
{
    uint8_t i,j,k,l,n;
    if(num >= 65535)
    {
        num = 65535;
    }
    if (num < 0)
    {
        write_data('-');
        num =abs(num);
    }

    i= num/10000;
    j= (num-10000*i)/1000;
    k= (num-10000*i-1000*j)/100;
    l= (num-10000*i-1000*j-100*k)/10;
    n= num%10;

    if(i!=0)
    {
        write_data(i+0x30);
    }
    if((i!=0)||(j!=0))
    {
        write_data(j+0x30);
    }
    if((i!=0)||(j!=0)||(k!=0))
    {
        write_data(k+0x30);
    }
    if((i!=0)||(j!=0)||(k!=0)||(l!=0))
    {
        write_data(l+0x30);
    }
    write_data(n+0x30);
}
 
void LCD_Show32Num(uint32_t num)
{
    uint8_t i,j,k,l,n,m,o,p,q,r;
    if(num >= 4294967295)
    {
        num = 4294967295;
    }

    i=num/1000000000;
    j=(num-1000000000*i)/100000000;
    k=(num-1000000000*i-100000000*j)/10000000;
    l=(num-1000000000*i-100000000*j-10000000*k)/1000000;
    n=(num-1000000000*i-100000000*j-10000000*k-1000000*l)/100000;
    m=(num-1000000000*i-100000000*j-10000000*k-1000000*l-100000*n)/10000;
    o=(num-1000000000*i-100000000*j-10000000*k-1000000*l-100000*n-10000*m)/1000;
    p=(num-1000000000*i-100000000*j-10000000*k-1000000*l-100000*n-10000*m-1000*o)/100;
    q=(num-1000000000*i-100000000*j-10000000*k-1000000*l-100000*n-10000*m-1000*o-100*p)/10;
    r=num%10;


    if(i!=0)
    {
        write_data(i+0x30);
    }
    if((i!=0)||(j!=0))
    {
        write_data(j+0x30);
    }
    if((i!=0)||(j!=0)||(k!=0))
    {
        write_data(k+0x30);
    }
    if((i!=0)||(j!=0)||(k!=0)||(l!=0))
    {
        write_data(l+0x30);
    }
    if((i!=0)||(j!=0)||(k!=0)||(l!=0)||(n!=0))
    {
        write_data(n+0x30);
    }
    if((i!=0)||(j!=0)||(k!=0)||(l!=0)||(n!=0)||(m!=0))
    {
        write_data(m+0x30);
    }
    if((i!=0)||(j!=0)||(k!=0)||(l!=0)||(n!=0)||(m!=0)||(o!=0))
    {
        write_data(o+0x30);
    }
    if((i!=0)||(j!=0)||(k!=0)||(l!=0)||(n!=0)||(m!=0)||(o!=0)||(p!=0))
    {
        write_data(p+0x30);
    }
    if((i!=0)||(j!=0)||(k!=0)||(l!=0)||(n!=0)||(m!=0)||(o!=0)||(p!=0)||(q!=0))
    {
        write_data(q+0x30);
    }
    write_data(r+0x30);
}
 
void LCD_ShowHex(uint8_t num)
{
     uint8_t i,j;
     i = num / 16;
     j = num % 16;
     if (i < 10)
     {
         write_data(i+0x30);
     }
     else
     {
         write_data('A'+i-10);
     }
     if (j < 10)
     {
         write_data(j+0x30);
     }
     else
     {
         write_data('A'+j-10);
     }
 }

void LCD_ShowAscii(uint8_t num)
{
    write_data(Asci2[num]);
}

void Cls_screen(void)
{
	write_com(0x01);
	delay(10);
}

/**************************/
Pagedis_Func GetMenuIndex()
{
    return g_menu_index;
}

uint8_t GetItemIndex()
{
    return g_item_index;
}
				 
void LCD_menu(Pagedis_Func menu) 
{
    Pagedis_Func Fi = menu;
    Cls_screen();
	write_com(0x03);
	delay(50);    
  
	write_com(0x80);
    Fi = GET_MENU(Fi, MENU_MAX);
	hzkdis(Func[Fi++]);

	write_com(0x90);
    Fi = GET_MENU(Fi, MENU_MAX);
	hzkdis(Func[Fi++]);
    
	write_com(0x88);
    Fi = GET_MENU(Fi, MENU_MAX);
	hzkdis(Func[Fi++]);
    
	write_com(0x98);
    Fi = GET_MENU(Fi, MENU_MAX);
	hzkdis(Func[Fi]);
    
    write_com(0x82);
    hzkdis("*");
}				 
				 
uint8_t LCD_Menu_Display(uint8_t menu, uint8_t item, int16_t value) {
    menu = GET_MENU(menu, MENU_MAX);
    LCD_menu(menu);
    LCD_Display_Func[menu](item, value);
    return DISPLAY_SUCCESS;
}

void LCD_Show_CANSendClose(void)
{
    Cls_screen();
    write_com(0x80);
    hzkdis("CAN Send OFF!");
}

void Page_0(void)
{
	Cls_screen();
	write_com(0x03);
	delay(50);
	write_com(0x80);
	hzkdis("YB103_Fix_fuel");
    #if SPS250_LIN
    write_com(0x90);
	hzkdis("SW_V1.0.5"); //1.0.1   SPS250_CAN,SPS250
	write_com(0x98);
	hzkdis("*:SWC-LIN ");
    #else
    write_com(0x90);
	hzkdis("SW_V1.0.0"); //1.0.1   SPS250_CAN,SPS250
	write_com(0x98);
	hzkdis("*:Normal ");
    #endif
}
