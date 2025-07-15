/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
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
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "stdio.h"
/* USER CODE END Includes */

extern UART_HandleTypeDef huart4;

extern UART_HandleTypeDef huart5;

extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
#define LIN2RXMSGMAXLEN         8
#define LIN1RXMSGMAXLEN         8

extern uint8_t Lin2RXBuffer;
extern uint8_t Lin2RXBuf[12];
extern volatile uint8_t Lin2RXBuflen;
extern uint8_t Lin2RXFlag;
extern volatile uint8_t Lin2RXBufMaxlen;
extern uint8_t Lin1RXBuffer;
extern uint8_t Lin1RXBuf[12];
extern volatile uint8_t Lin1RXBuflen;
extern uint8_t Lin1RXFlag;
extern volatile uint8_t Lin1RXBufMaxlen;
/* USER CODE END Private defines */

void MX_UART4_Init(void);
void MX_UART5_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

