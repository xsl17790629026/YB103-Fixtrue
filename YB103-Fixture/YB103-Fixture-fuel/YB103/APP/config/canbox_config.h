#ifndef __CANBOX_CONFIG_H__
#define __CANBOX_CONFIG_H__

#ifdef USE_BOOT
#define USER_VECT_TAB_ADDRESS
#endif

#define CanBaudrate50k       50
#define CanBaudrate125k      125
#define CanBaudrate500k      500

#define CANBOX_PROJECT   PROJECT_SPS250
#define BCAN_BAUDRATE    CanBaudrate500k
#define CCAN1_BAUDRATE   CanBaudrate500k

#define JMC            1 

#endif


