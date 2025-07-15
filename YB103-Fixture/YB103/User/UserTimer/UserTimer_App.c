#include "UserTimer_App.h"
#include "GPIO_Service.h"
#include "adc.h"
#include "usart.h"


/* create timer 2 if timer 1 timeout */
uint8_t cnt = 0,i = 0;
uint16_t heartled_delaytime[] = {1000, 200, 200, 200, 200, 2000 };
void LedHeart_Tick_1000ms_TimeoutFunc(void)
{
    UserTimer_SetPeriod(E_TIMER_LED_HEART,heartled_delaytime[i++]);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, (GPIO_PinState)!cnt);
    cnt = !cnt;
    if(i> sizeof(heartled_delaytime)/sizeof(uint16_t))
    {
        i = 0;
        cnt = 0;
    }
}




