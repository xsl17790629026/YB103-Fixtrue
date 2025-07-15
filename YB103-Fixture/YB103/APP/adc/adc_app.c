#include "adc_app.h"
#include "adc.h"

static uint8_t GcChlNumIdx = 0u;
static Adc_DebouncingInfo_st Adc_DebouncingInfo[CHANNEL_NUM];

/*****************************************************
* Function Name  : Adc_SetCoverChl
* Description	 : None
* Input 		 : None
* Output		 : None
* Return		 : None
******************************************************/
static void Adc_SetCoverChl(uint8_t LcChl)
{
	
	ADC_ChannelConfTypeDef AdcChlConfig;
	AdcChlConfig.Channel = LcChl;
	AdcChlConfig.Rank = ADC_REGULAR_RANK_1;
	AdcChlConfig.SamplingTime = ADC_SAMPLETIME_13CYCLES_5;
	HAL_ADC_ConfigChannel(&hadc1,&AdcChlConfig);
	HAL_ADC_Start(&hadc1);
}

/*****************************************************
* Function Name  : ADC_SamplingProcess
* Description	 : None
* Input 		 : None
* Output		 : None
* Return		 : None
******************************************************/

void ADC_SamplingProcess(void)
{
	uint8_t LcChlNum[CHANNEL_NUM] = {ADC_CHANNEL_15,ADC_CHANNEL_14,ADC_CHANNEL_8};

	uint32_t LcAdcData[CHANNEL_NUM] = {0u};
	
	if(GcChlNumIdx >= (CHANNEL_NUM - 1u))
	{
		GcChlNumIdx = 0x00u;
	}
	else
	{
	    GcChlNumIdx++;
	}
	Adc_SetCoverChl(LcChlNum[GcChlNumIdx]);
	LcAdcData[GcChlNumIdx] = HAL_ADC_GetValue(&hadc1);
	Adc_DebouncingInfo[GcChlNumIdx].ResValue = LcAdcData[GcChlNumIdx];
}

/*****************************************************
* Function Name  : ADC_GetResValue
* Description	 : None
* Input 		 : None
* Output		 : None
* Return		 : None
******************************************************/
uint32_t ADC_GetResValue(uint8_t Lu8Chl)
{
	return Adc_DebouncingInfo[Lu8Chl].ResValue;
}