#ifndef _USER_TIMER_H_
#define _USER_TIMER_H_

#include "stdint.h"
#include "string.h"
#include "gpio.h"

#include "UserTimer_Class.h"
#include "UserTimer_Def.h"

typedef void (*p_UserTimer_TimeoutFunc)(void);

typedef enum {
	E_UT_TYPE_PERIODIC,
	E_UT_TYPE_ONE_SHOT
} UserTimer_Type_t;

typedef struct {
	uint32_t Counter;
	uint32_t Counter_Backup;
	UserTimer_Type_t Type;
	uint8_t IsActive;
} UserTimer_Status_t;

typedef struct {
	p_UserTimer_TimeoutFunc TimeoutFunc;
	uint32_t Period;
	UserTimer_Type_t Type;
	uint8_t DefaultState;
} UserTimer_Table_t;

extern void UserTimer_Initial(void);
extern void UserTimer_Handler(void);
extern void UserTimer_Tick(void); //cycle call time need to check UT_TICK_BASE

extern void UserTimer_CreateDefault(UserTimer_ID_t Timer_ID);
extern void UserTimer_CreateSelf(UserTimer_ID_t Timer_ID, uint32_t period, UserTimer_Type_t Type);
extern void UserTimer_Kill(UserTimer_ID_t Timer_ID);

extern uint8_t UserTimer_IsActive(UserTimer_ID_t Timer_ID);
extern uint32_t UserTimer_GetRemainCounter(UserTimer_ID_t Timer_ID);
extern uint32_t UserTimer_GetPeriod(UserTimer_ID_t Timer_ID);
extern UserTimer_Type_t UserTimer_GetType(UserTimer_ID_t Timer_ID);

extern int UserTimer_SetPeriod(UserTimer_ID_t Timer_ID, uint16_t Period);

extern void UserTimer_uds_timeouthandler(void);


#endif /*_TIMER_FUN_H_*/

/****************************** END OF FILE ***************************/

