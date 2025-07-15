/*****************************************
*Company:
*
*File:LIN.c
*
*Description：
*
*Author:
*
*Data: 
******************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "lin.h"
#include "key.h"
#include "GPIO_Service.h"
#include "key_app.h"
//#include "can_transmit.h"
#include "lcd12864.h"
#include <string.h>
#include "config.h"
#include "usart.h"

#if 0

extern UART_HandleTypeDef huart2;

uint8_t LINCalID(uint8_t id)
{
  uint8_t parity, p0, p1;
 
  parity = id;
  p0 = (BIT(parity, 0) ^ BIT(parity, 1) ^ BIT(parity, 2) ^ BIT(parity, 4)) << 6;
  p1 = (!(BIT(parity, 1) ^ BIT(parity, 3) ^ BIT(parity, 4) ^ BIT(parity, 5))) << 7;
 
  parity |= (p0 | p1);
 
  return parity;
}
 
uint8_t LINCalChecksum(uint8_t id, uint8_t *data)
{
  uint32_t sum = id;
  uint8_t i;
 
  for(i = 1; i < 9; i++)
  {
    sum += data[i];
    if(sum & 0xFF00)
    {
      sum = (sum & 0x00FF) + 1;
    }
  }
 
  sum ^= 0x00FF;
 
  return (uint8_t)sum;
}

//uint8_t UART_Rx_data[5];
uint8_t QM_LinBuff[11]={0};

LIN_SWC_Msg Lin_RxMsg = {0};
uint8_t	QM_Lin_Rxdata[11] = {0};
uint8_t QM_Lin_Call_Flag = 0;
uint8_t QM_Lin_Receive_Flag = 0;
uint8_t send_value = 0;
extern uint8_t Can_TxReq_Status[kCanNumberOfTxObjects];


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
		uint8_t i = 0U;
		uint8_t temp = 0U;		
		if(huart->Instance == USART2) //  LIN2 接收
		{
			if((QM_Lin_Rxdata[0] == 0x55)&&(QM_Lin_Rxdata[1] == 0x42))     //如果从机ID是0x02
			{
        
					for(i=1;i<6;i++)
					{
							temp += QM_Lin_Rxdata[i];
						    if(temp & 0xFF00)
								{
									temp = (temp & 0x00FF) + 1;
								}
					}
					temp ^= 0x00FF;
					if(temp == QM_Lin_Rxdata[6])
					{

							QM_Lin_Call_Flag = TURE;    //数据接收回调成功，置位标志 
							if(memcmp(Lin_RxMsg.Lin_data,QM_Lin_Rxdata,sizeof(QM_Lin_Rxdata)))
							{
										Lin_RxMsg.Lin_data[0] = QM_Lin_Rxdata[0];
										Lin_RxMsg.Lin_data[1] = QM_Lin_Rxdata[1];
										Lin_RxMsg.Lin_data[2] = QM_Lin_Rxdata[2];
										Lin_RxMsg.Lin_data[3] = QM_Lin_Rxdata[3];
										Lin_RxMsg.Lin_data[4] = QM_Lin_Rxdata[4];
										Lin_RxMsg.Lin_data[5] = QM_Lin_Rxdata[5];
										Lin_RxMsg.Lin_data[6] = QM_Lin_Rxdata[6];
										//Lin_RxMsg.Lin_data[7] = QM_Lin_Rxdata[7];
										// SWC_Send = 0x03U;
                    Can_TxReq_Status[CanTxMsgIndex_SWC] = CAN_TRANSMIT_LIN;
							}
					}
	//	(void)memset(&QM_Lin_Rxdata,0x00,sizeof(QM_Lin_Rxdata));
		 }
	 }			
}



uint8_t Task_Lin_State = 0;
void Lin_Flow_task(void const *pvParameters)
{
  static uint8_t bt_button = KEY_RELLEASE;
  static uint8_t last_bt_button = KEY_RELLEASE;
  static uint8_t ex_12v = 0;
  while(1)
  {
		switch(Task_Lin_State)
		{
			case 0:
/*********************			
					if((TURE == QM_Lin_Receive_Flag) && (TURE == QM_Lin_Call_Flag))
					{							
							QM_Lin_Call_Flag = FALSE;
					}
					else
					{
							if(TURE == QM_Lin_Receive_Flag)
							{
							HAL_UART_AbortReceive_IT(&huart2);//如果没有接收到从机信号，则关闭接收中断
							}
					}

					QM_Lin_Receive_Flag = FALSE;
					QM_LinBuff[0] = 0x55;
					QM_LinBuff[1] = LINCalID(0x20);
					QM_LinBuff[2] = 0x00;
					QM_LinBuff[3] = 0x00;
					QM_LinBuff[4] = 0x00;
					QM_LinBuff[5] = 0x7f;
					QM_LinBuff[6] = 0x7f;
					QM_LinBuff[7] = 0x7f;
					QM_LinBuff[8] = 0x7f;
					QM_LinBuff[9] = 0x7f;
					QM_LinBuff[10] = LINCalChecksum(0x00,QM_LinBuff);
					HAL_LIN_SendBreak(&huart2);
					HAL_UART_Transmit_IT(&huart2,QM_LinBuff,11);
								*************/
					Task_Lin_State++;

					break;
			case 1: 	
					Task_Lin_State++;
					break;
			case 2:
					Task_Lin_State++;
					break;
			case 3:
					Task_Lin_State++;
					break;
			case 4:
					Task_Lin_State++;
					break;
			case 5:
					Task_Lin_State++;
					break;
			case 6:
					Task_Lin_State++;
					break;
			case 7:  //Send 0x02
					QM_LinBuff[0] = 0x55;
					QM_LinBuff[1] = LINCalID(0x42);
					HAL_LIN_SendBreak(&huart2);
					HAL_UART_Transmit_IT(&huart2,QM_LinBuff,2);
					HAL_UART_Receive_IT(&huart2,QM_Lin_Rxdata,11);
			//HAL_UART_Receive_IT(&huart2,Lin_RxMsg.Lin_data,11);
					QM_Lin_Receive_Flag = TURE;
					Task_Lin_State = 0;
					break;
			default:
					break;
		}

		bt_button = GPIO_Service_Body_Get();
		if(last_bt_button != bt_button)
		{
			last_bt_button = bt_button;
			send_value = !send_value;
			// printf("KEY_PRESS\r\n");
			Can_TxReq_Status[CanTxMsgIndex_BUTTON] = CAN_TRANSMIT_BUTTON;

			if(bt_button == KEY_RELLEASE)
			{
				ex_12v = !ex_12v;
				GPIO_Service_ExtendPower_Set(ex_12v);
				// printf("ex_12v = %d\r\n", ex_12v);
			}
		}

		
    vTaskDelay(pdMS_TO_TICKS(10));
  }
  
  
}

uint8_t Get_Lin_RxMsg(uint8_t SWC_ch)
{
	uint8_t res = 0xFF;
	switch(SWC_ch)
	{
		case Vol_Up:
		res = Lin_RxMsg.LIN_SWC_struct.D_VolUp;
		break;
		case Vol_Down:
		res = Lin_RxMsg.LIN_SWC_struct.F_VolDown;
		break;
		case Seek_Up:
		res = Lin_RxMsg.LIN_SWC_struct.A_ScanUp;
		break;
		case Seek_Down:
		res = Lin_RxMsg.LIN_SWC_struct.C_ScanDown;
		break;
		case Mute:
		res = Lin_RxMsg.LIN_SWC_struct.E_Mute;
		break;
	    case Pick_Up:
		res = Lin_RxMsg.LIN_SWC_struct.P_PickUp;
		break;
	    case Hang_Up:
		res = Lin_RxMsg.LIN_SWC_struct.R_HangUp;
		break;
		case Source:
		res = Lin_RxMsg.LIN_SWC_struct.B_source;
		break;
	    case Voice:
		res = Lin_RxMsg.LIN_SWC_struct.Q_Voice;
		break;
		default:
			break;
	}
	
	return res;
}

static void lin_gpio_init(void)
{
	GPIO_InitTypeDef  GPIO_Initure;
	
	__HAL_RCC_AFIO_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_UART5_CLK_ENABLE();
	
	
    GPIO_Initure.Pin=GPIO_PIN_12;	
    GPIO_Initure.Mode=GPIO_MODE_AF_PP;	
    GPIO_Initure.Pull=GPIO_PULLUP;        	
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);  
 	
	GPIO_Initure.Pin=GPIO_PIN_2;	
    GPIO_Initure.Mode=GPIO_MODE_AF_INPUT ;	
    HAL_GPIO_Init(GPIOD,&GPIO_Initure); 
	
    HAL_NVIC_SetPriority(LIN_IRQ,2,1);
    HAL_NVIC_EnableIRQ(LIN_IRQ);
}

uint8_t aRxBuffer[RXBUFFERSIZE]; 
UART_HandleTypeDef UART5_Handler; 

static void lin_uart_init(void)
{

	UART5_Handler.Instance=UART5;					    
	UART5_Handler.Init.BaudRate=LIN_BOAURATE;				    
	UART5_Handler.Init.WordLength=UART_WORDLENGTH_8B;   
	UART5_Handler.Init.StopBits=UART_STOPBITS_1;	    
	UART5_Handler.Init.Parity=UART_PARITY_NONE;		    
	UART5_Handler.Init.HwFlowCtl=UART_HWCONTROL_NONE;   
	UART5_Handler.Init.Mode=UART_MODE_TX_RX;		    
	HAL_UART_Init(&UART5_Handler);

    HAL_LIN_Init(&UART5_Handler,UART_LINBREAKDETECTLENGTH_11B);	
	
	HAL_UART_Receive_IT(&UART5_Handler, (uint8_t *)aRxBuffer, RXBUFFERSIZE);
	
}

 
void LINInit(void)
{
  lin_gpio_init();
  lin_uart_init();
}

void LINSendBreak(void)
{
  HAL_LIN_SendBreak(&UART5_Handler);
}

#endif