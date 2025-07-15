/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    can.c
  * @brief   This file provides code for the configuration
  *          of the CAN instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "canbox_config.h"
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "can.h"

/* USER CODE BEGIN 0 */
/************************************************************************
 * caution: Due to hardware design, CAN1 and CAN2 cannot act as high speed
 *          CAN or low speed CAN at the same time, and only CAN1 or CAN2
 *          CAN act as high speed or low speed CAN at the same time!
 ***********************************************************************/

CAN_TxHeaderTypeDef   TxHeader;
CAN_RxHeaderTypeDef   RxHeader;
uint8_t               TxData[8] = {0};
uint8_t               RxData[8] = {0};
uint32_t              TxMailbox;

extern QueueHandle_t ReceiveQueue;

volatile uint8_t 	MsgAvailable = 0;

#define GET_PRESCALER(Baaudrate)  (4500/Baaudrate)
/* USER CODE END 0 */

CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;

/* CAN1 init function */
void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */
  CAN_FilterTypeDef Filter;
  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = GET_PRESCALER(CCAN1_BAUDRATE);
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_3TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_4TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = ENABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */
  Filter.FilterIdHigh = 0;
	Filter.FilterIdLow = 0;
	Filter.FilterMaskIdHigh = 0;
	Filter.FilterMaskIdLow = 0;
	Filter.SlaveStartFilterBank = 0;
	Filter.FilterScale = CAN_FILTERSCALE_32BIT;
	Filter.FilterMode = CAN_FILTERMODE_IDMASK;
	Filter.FilterBank = 0;
	Filter.FilterFIFOAssignment = CAN_FilterFIFO0;
	Filter.FilterActivation = CAN_FILTER_ENABLE;

  HAL_CAN_ConfigFilter(&hcan1, &Filter);

	HAL_CAN_Start(&hcan1);

	if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK) {
		/* Notification Error */
		Error_Handler();
	}
  /* USER CODE END CAN1_Init 2 */

}
/* CAN2 init function */
void MX_CAN2_Init(void)
{

  /* USER CODE BEGIN CAN2_Init 0 */
  CAN_FilterTypeDef Filter;
  /* USER CODE END CAN2_Init 0 */

  /* USER CODE BEGIN CAN2_Init 1 */

  /* USER CODE END CAN2_Init 1 */
  hcan2.Instance = CAN2;
  hcan2.Init.Prescaler = GET_PRESCALER(BCAN_BAUDRATE);
  hcan2.Init.Mode = CAN_MODE_NORMAL;
  hcan2.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan2.Init.TimeSeg1 = CAN_BS1_3TQ;
  hcan2.Init.TimeSeg2 = CAN_BS2_4TQ;
  hcan2.Init.TimeTriggeredMode = DISABLE;
  hcan2.Init.AutoBusOff = ENABLE;
  hcan2.Init.AutoWakeUp = DISABLE;
  hcan2.Init.AutoRetransmission = DISABLE;
  hcan2.Init.ReceiveFifoLocked = DISABLE;
  hcan2.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN2_Init 2 */
  Filter.FilterIdHigh = 0;
	Filter.FilterIdLow = 0;
	Filter.FilterMaskIdHigh = 0;
	Filter.FilterMaskIdLow = 0;
	Filter.SlaveStartFilterBank = 14;
	Filter.FilterScale = CAN_FILTERSCALE_32BIT;
	Filter.FilterMode = CAN_FILTERMODE_IDMASK;
	Filter.FilterBank = 14;
	Filter.FilterFIFOAssignment = CAN_FilterFIFO0;
	Filter.FilterActivation = CAN_FILTER_ENABLE;

	HAL_CAN_ConfigFilter(&hcan2, &Filter);

	HAL_CAN_Start(&hcan2);

	if (HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK) {
		/* Notification Error */
		Error_Handler();
	}
  /* USER CODE END CAN2_Init 2 */

}

static uint32_t HAL_RCC_CAN1_CLK_ENABLED=0;

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspInit 0 */

  /* USER CODE END CAN1_MspInit 0 */
    /* CAN1 clock enable */
    HAL_RCC_CAN1_CLK_ENABLED++;
    if(HAL_RCC_CAN1_CLK_ENABLED==1){
      __HAL_RCC_CAN1_CLK_ENABLE();
    }

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**CAN1 GPIO Configuration
    PA11     ------> CAN1_RX
    PA12     ------> CAN1_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* CAN1 interrupt Init */
    HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspInit 1 */

  /* USER CODE END CAN1_MspInit 1 */
  }
  else if(canHandle->Instance==CAN2)
  {
  /* USER CODE BEGIN CAN2_MspInit 0 */

  /* USER CODE END CAN2_MspInit 0 */
    /* CAN2 clock enable */
    __HAL_RCC_CAN2_CLK_ENABLE();
    HAL_RCC_CAN1_CLK_ENABLED++;
    if(HAL_RCC_CAN1_CLK_ENABLED==1){
      __HAL_RCC_CAN1_CLK_ENABLE();
    }

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**CAN2 GPIO Configuration
    PB12     ------> CAN2_RX
    PB13     ------> CAN2_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* CAN2 interrupt Init */
    HAL_NVIC_SetPriority(CAN2_RX0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(CAN2_RX0_IRQn);
  /* USER CODE BEGIN CAN2_MspInit 1 */

  /* USER CODE END CAN2_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspDeInit 0 */

  /* USER CODE END CAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    HAL_RCC_CAN1_CLK_ENABLED--;
    if(HAL_RCC_CAN1_CLK_ENABLED==0){
      __HAL_RCC_CAN1_CLK_DISABLE();
    }

    /**CAN1 GPIO Configuration
    PA11     ------> CAN1_RX
    PA12     ------> CAN1_TX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);

    /* CAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspDeInit 1 */

  /* USER CODE END CAN1_MspDeInit 1 */
  }
  else if(canHandle->Instance==CAN2)
  {
  /* USER CODE BEGIN CAN2_MspDeInit 0 */

  /* USER CODE END CAN2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN2_CLK_DISABLE();
    HAL_RCC_CAN1_CLK_ENABLED--;
    if(HAL_RCC_CAN1_CLK_ENABLED==0){
      __HAL_RCC_CAN1_CLK_DISABLE();
    }

    /**CAN2 GPIO Configuration
    PB12     ------> CAN2_RX
    PB13     ------> CAN2_TX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12|GPIO_PIN_13);

    /* CAN2 interrupt Deinit */
    HAL_NVIC_DisableIRQ(CAN2_RX0_IRQn);
  /* USER CODE BEGIN CAN2_MspDeInit 1 */

  /* USER CODE END CAN2_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *CanHandle)
{
    CanMsg_t RxMessageObject;
    BaseType_t xHigherPriorityTaskWoken = 0;
	/* Get RX message */
	if (HAL_CAN_GetRxMessage(CanHandle, CAN_RX_FIFO0, &RxHeader, RxData) != HAL_OK) {
		/* Reception Error */
		Error_Handler();
	}
    
    RxMessageObject.MsgID = RxHeader.StdId;
    RxMessageObject.MsgLen = RxHeader.DLC;
    
    for(uint8_t i = 0;i<RxMessageObject.MsgLen;++i)
    {
        RxMessageObject.Msg[i] = RxData[i];
    }
    
    if(ReceiveQueue != NULL)
    {
        if(errQUEUE_FULL == xQueueSendFromISR(ReceiveQueue, &RxMessageObject, &xHigherPriorityTaskWoken))
        {
            //printf("ERR: CAN queue is full for buffer\r\n");
        }
    }
    portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}

uint8_t CAN2_SendMsg(uint8_t *msgdata, uint32_t msgID, uint8_t msglen)
{
	static uint32_t Gu32CurTxMailBox;
	uint8_t tmpdata[8] = {0u};
	uint8_t i = 0, res = 0u;
	uint32_t freelevel = 0u;
	CAN_TxHeaderTypeDef TxHeader;
    if(msgID > 0x7ffu)
	{
		TxHeader.IDE = CAN_ID_EXT;
		
		TxHeader.ExtId = msgID;
	}
	else
	{
		TxHeader.IDE = CAN_ID_STD;
		TxHeader.StdId = msgID;
	}
	TxHeader.DLC = msglen;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.TransmitGlobalTime = DISABLE;

	for(i = 0u; i < msglen; i++) {
		tmpdata[i] = msgdata[i];
	}
	freelevel = HAL_CAN_GetTxMailboxesFreeLevel(&hcan2);
	if(freelevel != 0u) {
		res = 1u;
		if(HAL_CAN_AddTxMessage(&hcan2, &TxHeader, tmpdata, &Gu32CurTxMailBox)!=HAL_OK){
            res = 0u;
        }
	}
	return res;
}

uint8_t CAN_SendMsg(uint8_t *msgdata, uint32_t msgID, uint8_t msglen)
{
	static uint32_t Gu32CurTxMailBox;
	uint8_t tmpdata[8] = {0u};
	uint8_t i = 0, res = 0u;
	uint32_t freelevel = 0u;
	CAN_TxHeaderTypeDef TxHeader;
	TxHeader.IDE = CAN_ID_STD;
	TxHeader.StdId = msgID;
	TxHeader.DLC = msglen;
	TxHeader.RTR = CAN_RTR_DATA;
	TxHeader.TransmitGlobalTime = DISABLE;

	for(i = 0u; i < msglen; i++) {
		tmpdata[i] = msgdata[i];
	}
	freelevel = HAL_CAN_GetTxMailboxesFreeLevel(&hcan1);
	if(freelevel != 0u) {
		res = 1u;
		HAL_CAN_AddTxMessage(&hcan1, &TxHeader, tmpdata, &Gu32CurTxMailBox);
	}
	return res;
}

uint8_t CAN_ReceiveMsg(uint8_t *msgdata, uint32_t *msgID, uint8_t *msglen)
{
	uint8_t i = 0;
	if(MsgAvailable == 1) {
		for(i = 0; i < RxHeader.DLC; ++i) {
			msgdata[i] = RxData[i];
			RxData[i] = 0;
		}
		*msglen = RxHeader.DLC;
		*msgID = RxHeader.StdId;
		MsgAvailable = 0;
	}
	return 0;
}

// static void Error_Handler(void)
// {
// 	while (1) {
// 	}
// }
/* USER CODE END 1 */
