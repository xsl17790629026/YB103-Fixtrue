﻿#include "TSMaster.h"
#include "MPLibrary.h"
#include "Configuration.h"
#include "TSMasterBaseInclude.h"
#include <memory>
#include <string>
#include <vector>

// Variables definition
TTSApp app;
TTSCOM com;
TTSTest test;

// Templates Instantiation
template <>
void output<TCAN>(TCAN* canMsg) {
    com.transmit_can_async(canMsg);
}

template <>
void output<TLIN>(TLIN* linMsg) {
    com.transmit_lin_async(linMsg);
}

template <>
void output<TFlexRay>(TFlexRay* frMsg) {
    com.transmit_flexray_async(frMsg);
}

template <>
void output<TEthernetHeader>(TEthernetHeader* ethMsg) {
    com.transmit_ethernet_async(ethMsg);
}

// logger functions definition
#define TEMP_STR_LEN 1024
typedef char* va_list;
#ifndef __va_rounded_size
#define __va_rounded_size(TYPE) (((sizeof(TYPE)+sizeof(int)-1)/sizeof(int))*sizeof(int))
#endif
 
#ifndef va_start
#define va_start(AP, LASTARG)   (AP = ((char *)& (LASTARG) + __va_rounded_size(LASTARG)))
#endif
 
#ifndef va_arg
#define va_arg(AP, TYPE)        (AP += __va_rounded_size(TYPE), *((TYPE *)(AP - __va_rounded_size(TYPE))))
#endif
 
#ifndef va_end
#define va_end(AP)              (AP = (va_list)0 )
#endif

// Utility functions definition
void internal_log(const char* AFile, const char* AFunc, const s32 ALine, const TLogLevel ALevel, const char* fmt, ...)
{ 
  va_list ap;    
  va_start(ap, fmt);
  std::vector<char> buf(1024);
  int ret;  
#if __cplusplus == 201103L
  while((ret = vsnprintf_s(&buf[0], buf.size(), fmt, ap)) == -1){
#else
  // in VC++ version is 199711L, log("__cplusplus: %d\n", __cplusplus);
  while ((ret = vsnprintf_s(&buf[0], buf.size(), buf.size(), fmt, ap)) == -1) {
#endif
    buf.resize(buf.size() * 2);    
  }
  va_end(ap);
  if (ret == static_cast<int>(buf.size())){
    buf[buf.size() - 1] = '\0';    
  }         
  app.debug_log(AFile, AFunc, ALine, &buf[0], ALevel);
}

void internal_test_log(const char* AFile, const char* AFunc, const s32 ALine, const TLogLevel ALevel, const char* fmt, ...)
{ 
  va_list ap;    
  va_start(ap, fmt);
  std::vector<char> buf(1024);
  int ret;  
#if __cplusplus == 201103L
  while ((ret = vsnprintf_s(&buf[0], buf.size(), fmt, ap)) == -1) {
#else
  while ((ret = vsnprintf_s(&buf[0], buf.size(), buf.size(), fmt, ap)) == -1) {
#endif
    buf.resize(buf.size() * 2);    
  }
  va_end(ap);
  if (ret == static_cast<int>(buf.size())){
    buf[buf.size() - 1] = '\0';    
  }         
  test.debug_log_info(AFile, AFunc, ALine, &buf[0], ALevel);
}

void test_logCAN(const char* ADesc, PCAN ACAN, const TLogLevel ALevel)
{
    char s[TEMP_STR_LEN];
    // channel, id, dlc, [data]
    if (ACAN->is_tx){
        if (ACAN->is_data){
            sprintf(s, "%s %d %03X Tx d %d [%02X %02X %02X %02X %02X %02X %02X %02X]", ADesc, ACAN->FIdxChn, ACAN->FIdentifier, ACAN->FDLC, ACAN->FData[0], ACAN->FData[1], ACAN->FData[2], ACAN->FData[3], ACAN->FData[4], ACAN->FData[5], ACAN->FData[6], ACAN->FData[7]);
        } else {
            sprintf(s, "%s %d %03X Tx r %d", ADesc, ACAN->FIdxChn, ACAN->FIdentifier, ACAN->FDLC);
        }
    } else {
        if (ACAN->is_data){
            sprintf(s, "%s %d %03X Rx d %d [%02X %02X %02X %02X %02X %02X %02X %02X]", ADesc, ACAN->FIdxChn, ACAN->FIdentifier, ACAN->FDLC, ACAN->FData[0], ACAN->FData[1], ACAN->FData[2], ACAN->FData[3], ACAN->FData[4], ACAN->FData[5], ACAN->FData[6], ACAN->FData[7]);
        } else {
            sprintf(s, "%s %d %03X Rx r %d", ADesc, ACAN->FIdxChn, ACAN->FIdentifier, ACAN->FDLC);
        }
    }
    test.log_info(s, ALevel);
}

DLLEXPORT s32 __stdcall initialize_miniprogram(const PTSMasterConfiguration AConf)
{
    app = AConf->FTSApp;
    com = AConf->FTSCOM;
    test = AConf->FTSTest;
    return 0;
    
}

DLLEXPORT s32 __stdcall finalize_miniprogram(void)
{
    return 0;
    
}

// MP library functions definition

// Timers defintions
extern TMPTimerMS GW_PC_2_Timer;
extern TMPTimerMS GW_PC_1_Timer;
extern TMPTimerMS GW_PC_6_Timer;
extern TMPTimerMS BCM_1_Timer;
extern TMPTimerMS GW_BD_9_Timer;
extern TMPTimerMS ACU_1_Timer;
extern TMPTimerMS TPMS_1_Timer;
extern TMPTimerMS GW_PC_7_Timer;
extern TMPTimerMS FCM_4_Timer;
extern TMPTimerMS FCM_3_Timer;
extern TMPTimerMS PEPS_1_Timer;
extern TMPTimerMS GW_PC_4_Timer;
extern TMPTimerMS BCM_4_Timer;
extern TMPTimerMS TBOX_2_Timer;

// Retrieve TSMP abilities
typedef s32 (__stdcall* TRegTSMasterFunction)(const void* AObj, const char* AFuncType, const char* AFuncName, const char* AData, const void* AFuncPointer, const char* ADescription);
extern void step(void);
extern void on_timer_On_GW_PC_2_Timer(void);
extern void on_timer_On_GW_PC_1_Timer(void);
extern void on_timer_On_GW_PC_6_Timer(void);
extern void on_timer_On_BCM_1_Timer(void);
extern void on_timer_On_GW_BD_9_Timer(void);
extern void on_timer_On_ACU_1_Timer(void);
extern void on_timer_On_TPMS_1_Timer(void);
extern void on_timer_On_GW_PC_7_Timer(void);
extern void on_timer_On_FCM_4_Timer(void);
extern void on_timer_On_FCM_3_Timer(void);
extern void on_timer_On_PEPS_1_Timer(void);
extern void on_timer_On_GW_PC_4_Timer(void);
extern void on_timer_On_BCM_4_Timer(void);
extern void on_timer_On_TBOX_2_Timer(void);
extern void on_start_On_Start(void);
DLLEXPORT s32 __stdcall retrieve_mp_abilities(const void* AObj, const TRegTSMasterFunction AReg) {
  #define TSMASTER_VERSION "2025.6.4.1464"
  if (!AReg(AObj, "check_mp_internal", "version", TSMASTER_VERSION, 0, "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_app", (void *)sizeof(TTSMasterConfiguration), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_tcan", (void *)sizeof(TCAN), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_tcanfd", (void *)sizeof(TCANFD), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_tlin", (void *)sizeof(TLIN), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_tflexray", (void *)sizeof(TFlexRay), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_tethernetheader", (void *)sizeof(TEthernetHeader), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_TMPVarInt", (void *)sizeof(TMPVarInt), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_TMPVarDouble", (void *)sizeof(TMPVarDouble), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_TMPVarString", (void *)sizeof(TMPVarString), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_TMPVarCAN", (void *)sizeof(TMPVarCAN), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_TMPVarCANFD", (void *)sizeof(TMPVarCANFD), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_TMPVarLIN", (void *)sizeof(TMPVarLIN), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_TLIBTSMapping", (void *)sizeof(TLIBTSMapping), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "struct_size", "struct_size_TLIBSystemVarDef", (void *)sizeof(TLIBSystemVarDef), "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "auto_start", "0", 0, "")) return -1;
  if (!AReg(AObj, "check_mp_internal", "addr_conf", "app", &app, "")) return -1;
  if (!AReg(AObj, "step_function", "step", "20", reinterpret_cast<const void*>(&step), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_2_Timer", "20", reinterpret_cast<const void*>(&GW_PC_2_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_1_Timer", "10", reinterpret_cast<const void*>(&GW_PC_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_6_Timer", "10", reinterpret_cast<const void*>(&GW_PC_6_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "BCM_1_Timer", "100", reinterpret_cast<const void*>(&BCM_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_BD_9_Timer", "100", reinterpret_cast<const void*>(&GW_BD_9_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "ACU_1_Timer", "100", reinterpret_cast<const void*>(&ACU_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "TPMS_1_Timer", "100", reinterpret_cast<const void*>(&TPMS_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_7_Timer", "20", reinterpret_cast<const void*>(&GW_PC_7_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "FCM_4_Timer", "50", reinterpret_cast<const void*>(&FCM_4_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "FCM_3_Timer", "50", reinterpret_cast<const void*>(&FCM_3_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "PEPS_1_Timer", "20", reinterpret_cast<const void*>(&PEPS_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_4_Timer", "100", reinterpret_cast<const void*>(&GW_PC_4_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "BCM_4_Timer", "100", reinterpret_cast<const void*>(&BCM_4_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "TBOX_2_Timer", "1000", reinterpret_cast<const void*>(&TBOX_2_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_2_Timer", "GW_PC_2_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_2_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_1_Timer", "GW_PC_1_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_6_Timer", "GW_PC_6_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_6_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_BCM_1_Timer", "BCM_1_Timer", reinterpret_cast<const void*>(&on_timer_On_BCM_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_BD_9_Timer", "GW_BD_9_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_BD_9_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_ACU_1_Timer", "ACU_1_Timer", reinterpret_cast<const void*>(&on_timer_On_ACU_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_TPMS_1_Timer", "TPMS_1_Timer", reinterpret_cast<const void*>(&on_timer_On_TPMS_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_7_Timer", "GW_PC_7_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_7_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_FCM_4_Timer", "FCM_4_Timer", reinterpret_cast<const void*>(&on_timer_On_FCM_4_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_FCM_3_Timer", "FCM_3_Timer", reinterpret_cast<const void*>(&on_timer_On_FCM_3_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_PEPS_1_Timer", "PEPS_1_Timer", reinterpret_cast<const void*>(&on_timer_On_PEPS_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_4_Timer", "GW_PC_4_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_4_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_BCM_4_Timer", "BCM_4_Timer", reinterpret_cast<const void*>(&on_timer_On_BCM_4_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_TBOX_2_Timer", "TBOX_2_Timer", reinterpret_cast<const void*>(&on_timer_On_TBOX_2_Timer), "")) return -1;
  if (!AReg(AObj, "on_start_callback", "on_start_On_Start", "", reinterpret_cast<const void*>(&on_start_On_Start), "")) return -1;
  // MP library functions

  return 30;
}
