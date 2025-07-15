#ifndef __KEY_IF__
#define __KEY_IF__

typedef enum
{
    RELEASE,
    PRESS,
    SHORT_PRESS,
    LONG_PRESS,
}Key_sts;

typedef struct
{
    uint8_t channel;
    uint16_t AdcValue;
    Key_sts KeySts;
}KEY_VAL;


#endif
