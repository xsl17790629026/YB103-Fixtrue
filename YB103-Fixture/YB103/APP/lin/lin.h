#ifndef _LIN_H_
#define _LIN_H_

#include "stm32f1xx_hal.h"
#include "lcd12864.h"

#define  TURE        (0x01)
#define  FALSE       (0x00) 
#define BIT(A,B)       ((A >> B) & 0x01)

#define RXBUFFERSIZE   1 					//缓存大小

#define LIN_CHANNEL         UART5

#define RCC_LIN_APB         RCC_APB1PeriphClockCmd

#define RCC_LIN_CLK         RCC_APB1Periph_UART5

#define LIN_BOAURATE        19200

#define LIN_IRQ             UART5_IRQn

#define LIN_INT_FUNC        UART5_IRQHandler
typedef union
{
 uint8_t	Lin_data[11];
	struct
	{
		uint8_t Sync;
		uint8_t Protected_ID;
		uint8_t Data0;
		uint8_t Data1;		
		uint8_t Data2;
		uint8_t Data3;
		uint8_t Checksum;
		uint8_t Reserve[4];
	}LIN_struct;
	
	struct
	{
		uint8_t Sync;
		uint8_t Protected_ID;
		uint8_t D_VolUp:1;
		uint8_t F_VolDown:1;
		uint8_t E_Mute:1;
		uint8_t A_ScanUp:1;
		
		uint8_t C_ScanDown:1;
		uint8_t T:1;
		uint8_t P_PickUp:1;
		uint8_t R_HangUp:1;
		
		uint8_t B_source:1;
		uint8_t Q_Voice:1;
		uint8_t N_OK:1;
		uint8_t G_Up:1;
		
		uint8_t L_Down:1;
		uint8_t H_Right:1;
		uint8_t M_Left:1;
		uint8_t S:1;
				
		uint8_t Data2;
		uint8_t Data3;
		uint8_t Checksum;
		uint8_t Reserve[4];
	}LIN_SWC_struct;
	
	struct
	{
		uint8_t Sync;
		uint8_t Protected_ID;
		uint8_t D_VolUp:1;
		uint8_t F_VolDown:1;
		uint8_t E_Mute:1;
		uint8_t A_ScanUp:1;
		
		uint8_t C_ScanDown:1;
		uint8_t T:1;
		uint8_t P_Phone:1;
		uint8_t R_Qmenu:1;
		
		uint8_t B_source:1;
		uint8_t Q_VR:1;
		uint8_t N_OK:1;
		uint8_t G_Up:1;
		
		uint8_t L_Down:1;
		uint8_t H_Right:1;
		uint8_t M_Left:1;
		uint8_t S:1;
				
		uint8_t Data2;
		uint8_t Data3;
		uint8_t Checksum;
		uint8_t Reserve[4];
	}SWCL_struct;
	struct
	{
		uint8_t Sync;
		uint8_t Protected_ID;
		uint8_t D_VolUp:1;
		uint8_t F_VolDown:1;
		uint8_t E_Mute:1;
		uint8_t A_ScanUp:1;
		
		uint8_t C_ScanDown:1;
		uint8_t T:1;
		uint8_t P_Phone:1;
		uint8_t R_Qmenu:1;
		
		uint8_t B_source:1;
		uint8_t Q_VR:1;
		uint8_t N_OK:1;
		uint8_t G_Up:1;
		
		uint8_t L_Down:1;
		uint8_t H_Right:1;
		uint8_t M_Left:1;
		uint8_t S:1;
				
		uint8_t Data2;
		uint8_t Data3;
		uint8_t Checksum;
		uint8_t Reserve[4];
	}SWCR_struct;
}LIN_SWC_Msg;

uint8_t Get_Lin_RxMsg(uint8_t SWC_ch);
void MX_USART2_UART_Init(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

void QM_Lin_Flow_Task(void);
uint8_t LINCalID(uint8_t id);
uint8_t LINCalChecksum(uint8_t id, uint8_t *data);

static void lin_gpio_init(void);
static void lin_uart_init(void);
void LINInit(void);

void LINSendChar(uint8_t ch);
void LINSendBreak(void);

void LIN_INT_FUNC(void);
#endif