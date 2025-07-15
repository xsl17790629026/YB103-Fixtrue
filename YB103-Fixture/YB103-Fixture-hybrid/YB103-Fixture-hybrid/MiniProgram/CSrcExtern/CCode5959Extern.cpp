#include "TSMaster.h"
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
extern TMPTimerMS ABS_3_Timer;
extern TMPTimerMS GW_PC_26_Timer;
extern TMPTimerMS BMS_33_Timer;
extern TMPTimerMS VCU_43_Timer;
extern TMPTimerMS VCU_42_Timer;
extern TMPTimerMS VCU_41_Timer;
extern TMPTimerMS VCU_37_Timer;
extern TMPTimerMS TPMS_1_Timer;
extern TMPTimerMS VCU_32_Timer;
extern TMPTimerMS GW_PC_7_Timer;
extern TMPTimerMS GW_BD_14_Timer;
extern TMPTimerMS BCM_1_Timer;
extern TMPTimerMS GW_PC_2_Timer;
extern TMPTimerMS EPB_1_Timer;
extern TMPTimerMS DCDC_1_Timer;
extern TMPTimerMS VCU_31_Timer;
extern TMPTimerMS GW_PC_4_Timer;
extern TMPTimerMS GSM_1_Timer;
extern TMPTimerMS TCU_13_Timer;
extern TMPTimerMS BMS_23_Timer;
extern TMPTimerMS GW_PC_31_Timer;
extern TMPTimerMS BMS_46_Timer;
extern TMPTimerMS BMS_3_Timer;
extern TMPTimerMS ESP_5_Timer;
extern TMPTimerMS AVAS_Timer;

// Retrieve TSMP abilities
typedef s32 (__stdcall* TRegTSMasterFunction)(const void* AObj, const char* AFuncType, const char* AFuncName, const char* AData, const void* AFuncPointer, const char* ADescription);
extern void step(void);
extern void on_timer_On_ABS_3_Timer(void);
extern void on_timer_On_GW_PC_26_Timer(void);
extern void on_timer_On_BMS_33_Timer(void);
extern void on_timer_On_VCU_43_Timer(void);
extern void on_timer_On_VCU_42_Timer(void);
extern void on_timer_On_VCU_41_Timer(void);
extern void on_timer_On_VCU_37_Timer(void);
extern void on_timer_On_TPMS_1_Timer(void);
extern void on_timer_On_VCU_32_Timer(void);
extern void on_timer_On_GW_BD_14_Timer(void);
extern void on_timer_On_BCM_1_Timer(void);
extern void on_timer_On_GW_PC_2_Timer(void);
extern void on_timer_On_EPB_1_Timer(void);
extern void on_timer_On_DCDC_1_Timer(void);
extern void on_timer_On_VCU_31_Timer(void);
extern void on_timer_On_GSM_1_Timer(void);
extern void on_timer_On_TCU_13_Timer(void);
extern void on_timer_On_BMS_23_Timer(void);
extern void on_timer_On_GW_PC_31_Timer(void);
extern void on_timer_On_BMS_46_Timer(void);
extern void on_timer_On_ESP_5_Timer(void);
extern void on_timer_On_GW_PC_7_Timer(void);
extern void on_timer_On_GW_PC_4_Timer(void);
extern void on_timer_On_BMS_3_Timer(void);
extern void on_timer_On_AVAS_Timer(void);
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
  if (!AReg(AObj, "step_function", "step", "5", reinterpret_cast<const void*>(&step), "")) return -1;
  if (!AReg(AObj, "timer", "ABS_3_Timer", "20", reinterpret_cast<const void*>(&ABS_3_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_26_Timer", "10", reinterpret_cast<const void*>(&GW_PC_26_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "BMS_33_Timer", "100", reinterpret_cast<const void*>(&BMS_33_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "VCU_43_Timer", "100", reinterpret_cast<const void*>(&VCU_43_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "VCU_42_Timer", "100", reinterpret_cast<const void*>(&VCU_42_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "VCU_41_Timer", "50", reinterpret_cast<const void*>(&VCU_41_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "VCU_37_Timer", "50", reinterpret_cast<const void*>(&VCU_37_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "TPMS_1_Timer", "100", reinterpret_cast<const void*>(&TPMS_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "VCU_32_Timer", "10", reinterpret_cast<const void*>(&VCU_32_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_7_Timer", "20", reinterpret_cast<const void*>(&GW_PC_7_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_BD_14_Timer", "100", reinterpret_cast<const void*>(&GW_BD_14_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "BCM_1_Timer", "100", reinterpret_cast<const void*>(&BCM_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_2_Timer", "20", reinterpret_cast<const void*>(&GW_PC_2_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "EPB_1_Timer", "20", reinterpret_cast<const void*>(&EPB_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "DCDC_1_Timer", "500", reinterpret_cast<const void*>(&DCDC_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "VCU_31_Timer", "10", reinterpret_cast<const void*>(&VCU_31_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_4_Timer", "100", reinterpret_cast<const void*>(&GW_PC_4_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GSM_1_Timer", "100", reinterpret_cast<const void*>(&GSM_1_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "TCU_13_Timer", "10", reinterpret_cast<const void*>(&TCU_13_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "BMS_23_Timer", "1000", reinterpret_cast<const void*>(&BMS_23_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "GW_PC_31_Timer", "10", reinterpret_cast<const void*>(&GW_PC_31_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "BMS_46_Timer", "100", reinterpret_cast<const void*>(&BMS_46_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "BMS_3_Timer", "1000", reinterpret_cast<const void*>(&BMS_3_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "ESP_5_Timer", "20", reinterpret_cast<const void*>(&ESP_5_Timer), "")) return -1;
  if (!AReg(AObj, "timer", "AVAS_Timer", "1000", reinterpret_cast<const void*>(&AVAS_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_ABS_3_Timer", "ABS_3_Timer", reinterpret_cast<const void*>(&on_timer_On_ABS_3_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_26_Timer", "GW_PC_26_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_26_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_BMS_33_Timer", "BMS_33_Timer", reinterpret_cast<const void*>(&on_timer_On_BMS_33_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_VCU_43_Timer", "VCU_43_Timer", reinterpret_cast<const void*>(&on_timer_On_VCU_43_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_VCU_42_Timer", "VCU_42_Timer", reinterpret_cast<const void*>(&on_timer_On_VCU_42_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_VCU_41_Timer", "VCU_41_Timer", reinterpret_cast<const void*>(&on_timer_On_VCU_41_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_VCU_37_Timer", "VCU_37_Timer", reinterpret_cast<const void*>(&on_timer_On_VCU_37_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_TPMS_1_Timer", "TPMS_1_Timer", reinterpret_cast<const void*>(&on_timer_On_TPMS_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_VCU_32_Timer", "VCU_32_Timer", reinterpret_cast<const void*>(&on_timer_On_VCU_32_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_BD_14_Timer", "GW_BD_14_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_BD_14_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_BCM_1_Timer", "BCM_1_Timer", reinterpret_cast<const void*>(&on_timer_On_BCM_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_2_Timer", "GW_PC_2_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_2_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_EPB_1_Timer", "EPB_1_Timer", reinterpret_cast<const void*>(&on_timer_On_EPB_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_DCDC_1_Timer", "DCDC_1_Timer", reinterpret_cast<const void*>(&on_timer_On_DCDC_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_VCU_31_Timer", "VCU_31_Timer", reinterpret_cast<const void*>(&on_timer_On_VCU_31_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GSM_1_Timer", "GSM_1_Timer", reinterpret_cast<const void*>(&on_timer_On_GSM_1_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_TCU_13_Timer", "TCU_13_Timer", reinterpret_cast<const void*>(&on_timer_On_TCU_13_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_BMS_23_Timer", "BMS_23_Timer", reinterpret_cast<const void*>(&on_timer_On_BMS_23_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_31_Timer", "GW_PC_31_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_31_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_BMS_46_Timer", "BMS_46_Timer", reinterpret_cast<const void*>(&on_timer_On_BMS_46_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_ESP_5_Timer", "ESP_5_Timer", reinterpret_cast<const void*>(&on_timer_On_ESP_5_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_7_Timer", "GW_PC_7_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_7_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_GW_PC_4_Timer", "GW_PC_4_Timer", reinterpret_cast<const void*>(&on_timer_On_GW_PC_4_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_BMS_3_Timer", "BMS_3_Timer", reinterpret_cast<const void*>(&on_timer_On_BMS_3_Timer), "")) return -1;
  if (!AReg(AObj, "on_timer_callback", "on_timer_On_AVAS_Timer", "AVAS_Timer", reinterpret_cast<const void*>(&on_timer_On_AVAS_Timer), "")) return -1;
  if (!AReg(AObj, "on_start_callback", "on_start_On_Start", "", reinterpret_cast<const void*>(&on_start_On_Start), "")) return -1;
  // MP library functions

  return 52;
}
