#ifndef __ADC_APP_H_
#define __ADC_APP_H_

#include "main.h"

#define CHANNEL_NUM        0x03u

#define ADC_ERRORVALUE     0x40u
#define ADC_VALUE_INVALID  0X00u

typedef struct
{
	uint8_t debounCnt;
	uint32_t LastValue;
	uint32_t SumValue;
	uint32_t ResValue;
}Adc_DebouncingInfo_st;

extern void ADC_SamplingProcess(void);
extern uint32_t ADC_GetResValue(uint8_t Lu8Chl);


#endif




