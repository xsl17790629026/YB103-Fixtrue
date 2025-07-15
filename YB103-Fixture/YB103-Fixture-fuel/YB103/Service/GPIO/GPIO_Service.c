#include "GPIO_Service.h"
#include "usart.h"

void GPIO_Service_ExtendPower_Set(uint8_t Powerstatus)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (GPIO_PinState)Powerstatus);
}

uint8_t GPIO_Service_ACC_Get(void)
{
	return (!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13));
}

uint8_t GPIO_Service_ILL_Get(void)
{
	return (!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5));
}

uint8_t GPIO_Service_Reverse_Get(void)
{
	return (!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8));
}

uint8_t GPIO_Service_Parking_Get(void)
{
	return (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6));
}

uint8_t GPIO_Service_Mute_Get(void)
{
	return (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_7));
}

uint8_t GPIO_Service_Body_Get(void)
{
	return (!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9));
}

uint8_t GPIO_Service_Door_Get(void)
{
	return (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15));
}







