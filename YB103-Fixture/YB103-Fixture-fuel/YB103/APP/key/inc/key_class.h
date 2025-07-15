#ifndef __KEY_CLASS_H__
#define __KEY_CLASS_H__

#define key_PASS1

#endif /*__KEY_CLASS_H__*/

#ifdef key_PASS2
#undef key_PASS2

#define BEGIN_KEY   static KEY_VAL stKeyValue[KEY_MAX] = {
#define KEY_DEF(id, channel, AdcValue, KeySts)     {channel, AdcValue, KeySts},
#define END_KEY     };

#endif

#ifdef key_PASS1
#undef key_PASS1
#define key_PASS2

#define BEGIN_KEY   enum eKEY_DEF{
#define KEY_DEF(id, channel, AdcValue, KeySts)     id,
#define END_KEY     KEY_MAX};

#endif

