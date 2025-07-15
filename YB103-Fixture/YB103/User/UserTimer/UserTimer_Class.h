#ifndef _USER_TIMER_CLASS_H_
#define _USER_TIMER_CLASS_H_

#define USER_TIMER_CLASS_1

#endif //_USER_TIMER_CLASS_H_

#ifdef USER_TIMER_CLASS_4
#undef  USER_TIMER_CLASS_4

#undef  BEGIN_USER_TIMER
#undef  END_USER_TIMER
#undef  USER_TIMER_ADD
#define BEGIN_USER_TIMER
#define END_USER_TIMER
#define USER_TIMER_ADD(UserTimer_ID, callback, period, Type, DefaultState)
#endif

#ifdef USER_TIMER_CLASS_3
#undef  USER_TIMER_CLASS_3
#define USER_TIMER_CLASS_4
#undef  BEGIN_USER_TIMER
#undef  END_USER_TIMER
#undef  USER_TIMER_ADD
#define BEGIN_USER_TIMER        const UserTimer_Table_t UserTimer_Table[TIMER_MAX] = {
#define END_USER_TIMER          };
#define USER_TIMER_ADD(UserTimer_ID, callback, period, Type, DefaultState)          {callback,period,Type,DefaultState},
#endif

#ifdef USER_TIMER_CLASS_2
#undef  USER_TIMER_CLASS_2
#define USER_TIMER_CLASS_3
#undef  BEGIN_USER_TIMER
#undef  END_USER_TIMER
#undef  USER_TIMER_ADD
#define BEGIN_USER_TIMER
#define END_USER_TIMER
#define USER_TIMER_ADD(UserTimer_ID, callback, period, Type, DefaultState)         extern void callback(void);
#endif

#ifdef USER_TIMER_CLASS_1
#undef USER_TIMER_CLASS_1
#define USER_TIMER_CLASS_2
#define BEGIN_USER_TIMER        typedef enum TIMERS_ENUM {
#define END_USER_TIMER          TIMER_MAX } UserTimer_ID_t;
#define USER_TIMER_ADD(UserTimer_ID, callback, period, Type, DefaultState)          UserTimer_ID,
#endif



/****************************** END OF FILE ***************************/
