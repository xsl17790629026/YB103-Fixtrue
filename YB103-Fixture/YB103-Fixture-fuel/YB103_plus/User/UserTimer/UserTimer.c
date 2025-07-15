#include "UserTimer.h"
#include <stdio.h>
/* in order to get special marco */
#include "UserTimer_Class.h"
#include "UserTimer_Def.h"
#include "UserTimer_Class.h"
#include "UserTimer_Def.h"
#include "UserTimer_Class.h"
#include "UserTimer_Def.h"

#include "usart.h"

static UserTimer_Status_t UserTimer_Status[TIMER_MAX];
static uint32_t UserTimer_TickCounter;

/***********************************************************************
*  Name        : UserTimer_Initial
*  Description : this function init all the timers. default disable and Counter = 0
*  Parameter   : void
*  Returns     : void
***********************************************************************/
void UserTimer_Initial(void)
{
	uint8_t i;

	for(i = 0x00; i < (uint8_t)TIMER_MAX; i++) {
		UserTimer_Status[i].Counter = 0;
		UserTimer_Status[i].Counter_Backup = 0;
		UserTimer_Status[i].Type = E_UT_TYPE_ONE_SHOT;
		UserTimer_Status[i].IsActive = 0;

		if (UserTimer_Table[i].DefaultState == DEFAULT_START) {
			UserTimer_CreateDefault((UserTimer_ID_t)i);
		}
	}

	UserTimer_TickCounter = 0;
}

/***********************************************************************
*  Name        : UserTimer_CreateDefault
*  Description : this function create timer which is defined by the
                 parameters.
*  Parameter   : UserTimer_ID : the No. of the timer defined in enum TIMER_IDS
*  Returns     : void
***********************************************************************/
void UserTimer_CreateDefault(UserTimer_ID_t Timer_ID)
{
	if(Timer_ID < TIMER_MAX) {
		UserTimer_Status[Timer_ID].Counter = UserTimer_Table[Timer_ID].Period;
		UserTimer_Status[Timer_ID].Counter_Backup = UserTimer_Table[Timer_ID].Period;
		UserTimer_Status[Timer_ID].Type = UserTimer_Table[Timer_ID].Type;
		UserTimer_Status[Timer_ID].IsActive = 1;
	}
}

/***********************************************************************
*  Name        : tm_reset_timer
*  Description : this function create timer with slef-define parameter
*  Parameter   : UserTimer_ID : the No. of the timer defined in enum TIMER_IDS
                 period : time, the unit is 2 mseconds.
                 Type : Once or periodic timer.
*  Returns     : void
***********************************************************************/
void UserTimer_CreateSelf(UserTimer_ID_t Timer_ID, uint32_t period, UserTimer_Type_t Type)
{
    if(Timer_ID < TIMER_MAX) {
		UserTimer_Status[Timer_ID].Counter = period;
		UserTimer_Status[Timer_ID].Counter_Backup = period;
		UserTimer_Status[Timer_ID].Type = Type;
		UserTimer_Status[Timer_ID].IsActive = 1;
	}
}


/***********************************************************************
*  Name        : UserTimer_Kill
*  Description : this function kill timer which is defined by the
                 parameter UserTimer_ID.
*  Parameter   : UserTimer_ID : the No. of the timer defined in enum TIMER_IDS
*  Returns     : void
***********************************************************************/
void UserTimer_Kill(UserTimer_ID_t Timer_ID)
{
	if(Timer_ID < TIMER_MAX) {
		UserTimer_Status[Timer_ID].Counter = 0;
		UserTimer_Status[Timer_ID].Counter_Backup = 0;
		UserTimer_Status[Timer_ID].Type = E_UT_TYPE_ONE_SHOT;
		UserTimer_Status[Timer_ID].IsActive = 0;
	}
}

/***********************************************************************
*  Name        : UserTimer_Tick
*  Description : in order to Counter, need be call in tick_service
*  Parameter   : void
*  Returns     : void
***********************************************************************/
void UserTimer_Tick(void)
{
	uint8_t i;

	UserTimer_TickCounter++;
	if(UserTimer_TickCounter >= UT_TICK_BASE) {
		UserTimer_TickCounter = 0;

		for(i = 0x00; i < (uint8_t)TIMER_MAX; i++) {
			if(UserTimer_Status[i].IsActive) {
				if(UserTimer_Status[i].Counter > 0u) {
					UserTimer_Status[i].Counter--;
				}
			}
		}
	}
}

/***********************************************************************
*  Name        : UserTimer_Handler
*  Description : run in main(), it will call function if timeout
*  Parameter   : void
*  Returns     : void
***********************************************************************/
void UserTimer_Handler(void)
{
	uint8_t i;

	for(i = 0x00; i < (uint8_t)TIMER_MAX; i++) {
		if((UserTimer_Status[i].IsActive) && (UserTimer_Status[i].Counter == 0u)) {

            if(UserTimer_Status[i].Type == E_UT_TYPE_PERIODIC) {
                UserTimer_Status[i].Counter = UserTimer_Status[i].Counter_Backup;
            } else {
                UserTimer_Status[i].Counter = 0;
                UserTimer_Status[i].IsActive = 0;
            }

            UserTimer_Table[i].TimeoutFunc();
            
		}
	}
}

/***********************************************************************
*  Name        : UserTimer_IsActive
*  Description : check if specific timer is active or not
*  Parameter   : UserTimer_ID
*  Returns     : void
***********************************************************************/
uint8_t UserTimer_IsActive(UserTimer_ID_t Timer_ID)
{
	if (Timer_ID >= TIMER_MAX) return 0;

	return (uint8_t)(UserTimer_Status[Timer_ID].IsActive);
}

/***********************************************************************
*  Name        : UserTimer_GetRemainCounter
*  Description : get the timer remain Counter, such as Period == 1000£¬after 300£¬the  remain Counter == 700
*  Parameter   : UserTimer_ID
*  Returns     : void
***********************************************************************/
uint32_t UserTimer_GetRemainCounter(UserTimer_ID_t Timer_ID)
{
	if (Timer_ID >= TIMER_MAX) return 0;

	return (uint32_t)(UserTimer_Status[Timer_ID].Counter);
}

/***********************************************************************
*  Name        : UserTimer_GetType
*  Description : get the timer Type, once or period
*  Parameter   : UserTimer_ID
*  Returns     : void
***********************************************************************/
UserTimer_Type_t UserTimer_GetType(UserTimer_ID_t Timer_ID)
{
	if (Timer_ID >= TIMER_MAX) return E_UT_TYPE_PERIODIC;

	return (UserTimer_Status[Timer_ID].Type);
}

/***********************************************************************
*  Name        : UserTimer_GetPeriod
*  Description : get timer period
*  Parameter   : UserTimer_ID
*  Returns     : void
***********************************************************************/
uint32_t UserTimer_GetPeriod(UserTimer_ID_t Timer_ID)
{
	if (Timer_ID >= TIMER_MAX) return 0;

	return (uint32_t)(UserTimer_Status[Timer_ID].Counter_Backup);
}

int UserTimer_SetPeriod(UserTimer_ID_t Timer_ID, uint16_t Period)
{
    if (Timer_ID >= TIMER_MAX) return -1;

    UserTimer_Status[Timer_ID].Counter = Period;
    return 0;
}


/**************** END OF FILE *****************************************/
