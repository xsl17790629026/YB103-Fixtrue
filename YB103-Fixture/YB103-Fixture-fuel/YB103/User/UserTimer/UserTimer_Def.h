#ifndef _USER_MENU_DEF_H_
#define _USER_MENU_DEF_H_

#define UT_TICK_BASE                    1   /* 1 ms */

#define MSECOND     					*1u
#define SECOND     						*(1000u MSECOND)
#define MINUTE      					*(60000u MSECOND)

#define DEFAULT_START                   1
#define DEFAULT_STOP                    0

#endif /*_USER_MENU_DEF_H_*/

/*
 * check timer_class.h
 * #define USER_TIMER_ADD(UserTimer_ID, callback, period, Type, DefaultState)
*/

BEGIN_USER_TIMER

USER_TIMER_ADD(E_TIMER_LED_HEART,       LedHeart_Tick_1000ms_TimeoutFunc,           1 SECOND,       E_UT_TYPE_PERIODIC, DEFAULT_START)

END_USER_TIMER

/****************************** END OF FILE ***************************/
