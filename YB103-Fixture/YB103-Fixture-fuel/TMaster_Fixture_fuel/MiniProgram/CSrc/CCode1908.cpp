// GEN BLOCK BEGIN Include
#define TSMP_IMPL
#include "TSMaster.h"
#include "MPLibrary.h"
#include "Database.h"
#include "TSMasterBaseInclude.h"
#include "Configuration.h"
// GEN BLOCK END Include

// CODE BLOCK BEGIN Timer GW_PC_2_Timer MjA_
// 定时器文档 "GW_PC_2_Timer"
TMPTimerMS GW_PC_2_Timer;
// CODE BLOCK END Timer GW_PC_2_Timer

// CODE BLOCK BEGIN Timer GW_PC_1_Timer MTA_
// 定时器文档 "GW_PC_1_Timer"
TMPTimerMS GW_PC_1_Timer;
// CODE BLOCK END Timer GW_PC_1_Timer

// CODE BLOCK BEGIN Timer GW_PC_6_Timer MTA_
// 定时器文档 "GW_PC_6_Timer"
TMPTimerMS GW_PC_6_Timer;
// CODE BLOCK END Timer GW_PC_6_Timer

// CODE BLOCK BEGIN Timer BCM_1_Timer MTAw
// 定时器文档 "BCM_1_Timer"
TMPTimerMS BCM_1_Timer;
// CODE BLOCK END Timer BCM_1_Timer

// CODE BLOCK BEGIN Timer GW_BD_9_Timer MTAw
// 定时器文档 "GW_BD_9_Timer"
TMPTimerMS GW_BD_9_Timer;
// CODE BLOCK END Timer GW_BD_9_Timer

// CODE BLOCK BEGIN Timer ACU_1_Timer MTAw
// 定时器文档 "ACU_1_Timer"
TMPTimerMS ACU_1_Timer;
// CODE BLOCK END Timer ACU_1_Timer

// CODE BLOCK BEGIN Timer TPMS_1_Timer MTAw
// 定时器文档 "TPMS_1_Timer"
TMPTimerMS TPMS_1_Timer;
// CODE BLOCK END Timer TPMS_1_Timer

// CODE BLOCK BEGIN Timer GW_PC_7_Timer MjA_
// 定时器文档 "GW_PC_7_Timer"
TMPTimerMS GW_PC_7_Timer;
// CODE BLOCK END Timer GW_PC_7_Timer

// CODE BLOCK BEGIN Timer FCM_4_Timer NTA_
// 定时器文档 "FCM_4_Timer"
TMPTimerMS FCM_4_Timer;
// CODE BLOCK END Timer FCM_4_Timer

// CODE BLOCK BEGIN Timer FCM_3_Timer NTA_
// 定时器文档 "FCM_3_Timer"
TMPTimerMS FCM_3_Timer;
// CODE BLOCK END Timer FCM_3_Timer

// CODE BLOCK BEGIN Timer PEPS_1_Timer MjA_
// 定时器文档 "PEPS_1_Timer"
TMPTimerMS PEPS_1_Timer;
// CODE BLOCK END Timer PEPS_1_Timer

// CODE BLOCK BEGIN Timer GW_PC_4_Timer MTAw
// 定时器文档 "GW_PC_4_Timer"
TMPTimerMS GW_PC_4_Timer;
// CODE BLOCK END Timer GW_PC_4_Timer

// CODE BLOCK BEGIN Timer BCM_4_Timer MTAw
// 定时器文档 "BCM_4_Timer"
TMPTimerMS BCM_4_Timer;
// CODE BLOCK END Timer BCM_4_Timer

// CODE BLOCK BEGIN Global_Definitions 
//车速
u32 ABS_3_VehicleSpeed_signal;
u32 ABS_3_VehicleSpeedValid_signal;
u32 ABS_3_Timeout_Flag_signal;
//转速
double EMS_2_EngineSpeed_signal;
u32 EMS_2_EngineSpeedValid_signal;
u32 EMS_2_Timeout_Flag_signal;
//水温
double EMS_4_EngineCoolantTemp_signal;
u32 EMS_4_EngineCoolantTempValid_signal;
u32 EMS_4_Timeout_Flag_signal;
//转向灯、危险警示灯
u32 BCM_LeftTurnLightSts_signal;
u32 BCM_RightTurnLightSts_signal;
u32 BCM_EmergencyLightSts_signal;
//远光灯、近光灯、位置灯、雾灯
u32 BCM_1_HighBeamSts_signal;
u32 BCM_1_LowBeamSts_signal;
u32 BCM_1_PositionLightSts_signal;
u32 BCM_1_FrontFogLightSts_signal;
u32 BCM_1_RearFogLightSts_signal;
u32 BCM_1_Timeout_Flag_signal;
//安全气囊指示灯
u32 ACU_AirbagWarningStatus_signal;
u32 ACU_AirbagInhibitWarning_signal;
//驻车指示灯
u32 EPB_1_ActiveLamp_signal;
//EPB故障指示灯
u32 EPB_1_WarningLamp_signal;
u32 EPB_1_Timeout_Flag_signal;
//蓄电池放电故障指示灯
u32 EMS_6_GeneratorFaultLamp_signal;
u32 EMS_6_Timeout_Flag_signal;
//ABS指示灯
u32 ABS_3_AbsFault_signal;
u32 ABS_3_EbdFault_signal;
//ESP指示灯
u32 ESP_1_ESPFault_signal;
u32 ESP_1_TCSFault_signal;
u32 ESP_1_DVTSessionFlag_signal;
u32 ESP_1_ESPActive_signal;
u32 ESP_1_TCSActive_signal;
u32 ESP_1_ESPOff_signal;
u32 ESP_1_Timeout_Flag_signal;
//EHPS故障指示灯
u32 SAS_1_CalibratedSt_signal;
u32 SAS_1_Timeout_Flag_signal;
//发动机MIL指示灯
u32 EMS_4_MIL_signal;
//机油压力低指示灯
u32 EMS_6_OilPressureLamp_signal;
//发动机防盗指示灯
u32 EMS_3_EngineReleaseSig_signal;
u32 EMS_3_Timeout_Flag_signal;
//变速箱故障指示灯
u32 TCU_1_TcuFaultLamp_signal;
u32 TCU_1_TransOilWrnLmpReq_signal;
u32 TCU_1_Timeout_Flag_signal;
//GPF指示灯
u32 EMS_6_GPFState_signal;
//胎压监测系统障碍指示灯
u32 TPMS_SystemStatus_signal;
u32 TPMS_LearningStatus_signal;
//轮胎漏气提示
u32 TPMS_TireLeakage_signal;
//AUTOHOLD工作指示灯
u32 EPB_1_AutoholdValid_signal;
u32 EPB_1_AutoHold_Standby_signal;
u32 EPB_1_AutoholdActive_signal;
//四驱故障/2H/4H/4L指示灯
u32 AWD_1_DiagnosticLampRequest_signal;
u32 AWD_1_Lamp2WD_signal;
u32 AWD_1_Lamp4WDLock_signal;
u32 AWD_1_Lamp4WDLow_signal;
u32 AWD_1_Timeout_Flag_signal;
//LDW指示灯         
u32 FCM_LDWSysSts_signal;
u32 FCM_LDWVoiceWarning_signal;
//FCM模式
u32 FCM_FCWMode_signal;
//AEB模式
u32 FCM_AEBMode_signal;
//定速巡航指示灯
u32 EMS_4_CruiseControlStatus_signal;
double EMS_4_CruiseTargetSpeed_signal;
//ACC指示灯
u32 FCM_ACCMode_signal;
double FCM_ACCVSetDis_signal;
//陡坡缓降指示灯
u32 ESP_1_HDCControl_signal;
u32 ESP_1_HDCFault_signal;
//前、后电控差速锁指示灯
u32 EDL_1_RearDiffLockGreenLamp_signal;
u32 EDL_1_RearDiffLockYellowLamp_signal;
u32 EDL_1_FrontDiffLockGreenLamp_signal;
u32 EDL_1_FrontDiffLockYellowLamp_signal;
u32 EDL_1_Timeout_Flag_signal;
//PEPS指示灯
u32 PEPS_FailStatus_signal;
//启停系统工作指示灯
u32 EMS_3_SS_Active_Lamp_signal;
u32 EMS_3_SS_Fault_Lamp_signal;
u32 EMS_3_SS_SetSts_signal;
//稳定杆断开指示灯
u32 Swaybar_1_FrontSwaybarGreenLamp_signal;
u32 Swaybar_1_FrontSwaybarYellowLamp_signal;
u32 Swaybar_1_Timeout_Flag_signal;
//道路限速标识指示灯
u32 FCM_TSRDisplay_signal;
u32 FCM_TSROverSpdWarning_signal;
u32 FCM_TSROverSpeedAcousticONOFFSts_signal;
u32 FCM_TSRState_signal;
//时距显示指示灯
u32 FCM_TimeGapSetICM_signal;
//自动远近光指示灯
u32 FCM_IHBCStatus_signal;
//驾驶模式指示灯
u32 TCU_3_Drivemode_signal;
u32 TCU_3_Timeout_Flag_signal;
//SVS指示灯
u32 EMS_4_SVS_signal;
//防控灯状态指示灯
u32 BCM_AAL_ONOFFSts_signal;
//日间行车指示灯（预留）
u32 BCM_1_DaytimeRunningLightSts_signal;
//方向盘加热指示灯
u32 BCM_SteeringwheelheatingSts_signal;
//电源状态
u32 BCM_1_PowerMode_signal;
// CODE BLOCK END Global_Definitions 

// CODE BLOCK BEGIN On_Timer On_GW_PC_2_Timer R1dfUENfMl9UaW1lcg__
// 定时器触发事件 "On_GW_PC_2_Timer" for Timer GW_PC_2_Timer
void on_timer_On_GW_PC_2_Timer(void) { try { // 定时器 = GW_PC_2_Timer
TGW_PC_2_1 GW_PC_2_1;

// 原有信号获取
app.get_system_var_uint32("ABS_3_VehicleSpeed", &ABS_3_VehicleSpeed_signal);
app.get_system_var_uint32("ABS_3_VehicleSpeedValid", &ABS_3_VehicleSpeedValid_signal);
app.get_system_var_uint32("ABS_3_Timeout_Flag", &ABS_3_Timeout_Flag_signal);
app.get_system_var_uint32("EPB_1_ActiveLamp", &EPB_1_ActiveLamp_signal);
app.get_system_var_uint32("EPB_1_Timeout_Flag", &EPB_1_Timeout_Flag_signal);
app.get_system_var_uint32("EPB_1_WarningLamp", &EPB_1_WarningLamp_signal);

// ABS指示灯相关信号获取
app.get_system_var_uint32("ABS_3_AbsFault", &ABS_3_AbsFault_signal);
app.get_system_var_uint32("ABS_3_EbdFault", &ABS_3_EbdFault_signal);
app.get_system_var_uint32("ABS_3_Timeout_Flag", &ABS_3_Timeout_Flag_signal);

// ESP指示灯相关信号获取
app.get_system_var_uint32("ESP_1_ESPFault", &ESP_1_ESPFault_signal);
app.get_system_var_uint32("ESP_1_TCSFault", &ESP_1_TCSFault_signal);
app.get_system_var_uint32("ESP_1_DVTSessionFlag", &ESP_1_DVTSessionFlag_signal);
app.get_system_var_uint32("ESP_1_ESPActive", &ESP_1_ESPActive_signal);
app.get_system_var_uint32("ESP_1_TCSActive", &ESP_1_TCSActive_signal);
app.get_system_var_uint32("ESP_1_ESPOff", &ESP_1_ESPOff_signal);
app.get_system_var_uint32("ESP_1_Timeout_Flag", &ESP_1_Timeout_Flag_signal);

app.get_system_var_uint32("SAS_1_CalibratedSt", &SAS_1_CalibratedSt_signal);
app.get_system_var_uint32("SAS_1_Timeout_Flag", &SAS_1_Timeout_Flag_signal);

app.get_system_var_uint32("EPB_1_AutoholdValid", &EPB_1_AutoholdValid_signal);
app.get_system_var_uint32("EPB_1_AutoHold_Standby", &EPB_1_AutoHold_Standby_signal);
app.get_system_var_uint32("EPB_1_AutoholdActive", &EPB_1_AutoholdActive_signal);

app.get_system_var_uint32("ESP_1_HDCControl", &ESP_1_HDCControl_signal);
app.get_system_var_uint32("ESP_1_HDCFault", &ESP_1_HDCFault_signal);

GW_PC_2_1.init();

// 原有信号设置
GW_PC_2_1.set_ABS_3_VehicleSpeed(ABS_3_VehicleSpeed_signal);
GW_PC_2_1.set_ABS_3_VehicleSpeedValid(ABS_3_VehicleSpeedValid_signal);
GW_PC_2_1.set_ABS_3_Timeout_Flag(ABS_3_Timeout_Flag_signal);
GW_PC_2_1.set_EPB_1_ActiveLamp(EPB_1_ActiveLamp_signal);
GW_PC_2_1.set_EPB_1_Timeout_Flag(EPB_1_Timeout_Flag_signal);
GW_PC_2_1.set_EPB_1_WarningLamp(EPB_1_WarningLamp_signal);   

// ABS指示灯相关信号设置
GW_PC_2_1.set_ABS_3_AbsFault(ABS_3_AbsFault_signal);
GW_PC_2_1.set_ABS_3_EbdFault(ABS_3_EbdFault_signal);

// ESP指示灯相关信号设置
GW_PC_2_1.set_ESP_1_ESPFault(ESP_1_ESPFault_signal);
GW_PC_2_1.set_ESP_1_TCSFault(ESP_1_TCSFault_signal);
GW_PC_2_1.set_ESP_1_DVTSessionFlag(ESP_1_DVTSessionFlag_signal);
GW_PC_2_1.set_ESP_1_ESPActive(ESP_1_ESPActive_signal);
GW_PC_2_1.set_ESP_1_TCSActive(ESP_1_TCSActive_signal);
GW_PC_2_1.set_ESP_1_ESPOff(ESP_1_ESPOff_signal);
GW_PC_2_1.set_ESP_1_Timeout_Flag(ESP_1_Timeout_Flag_signal);

GW_PC_2_1.set_SAS_1_CalibratedSt(SAS_1_CalibratedSt_signal);
GW_PC_2_1.set_SAS_1_Timeout_Flag(SAS_1_Timeout_Flag_signal);

GW_PC_2_1.set_EPB_1_AutoholdValid(EPB_1_AutoholdValid_signal);
GW_PC_2_1.set_EPB_1_AutoHold_Standby(EPB_1_AutoHold_Standby_signal);
GW_PC_2_1.set_EPB_1_AutoholdActive(EPB_1_AutoholdActive_signal);

GW_PC_2_1.set_ESP_1_HDCControl(ESP_1_HDCControl_signal);
GW_PC_2_1.set_ESP_1_HDCFault(ESP_1_HDCFault_signal);

com.transmit_can_async(&GW_PC_2_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_2_Timer

// CODE BLOCK BEGIN On_Start On_Start
// 启动事件 "On_Start"
void on_start_On_Start(void) { try { // 程序启动事件
app.connect();
GW_PC_2_Timer.start(); 
GW_PC_1_Timer.start();
GW_PC_6_Timer.start();
BCM_1_Timer.start();
GW_BD_9_Timer.start();
ACU_1_Timer.start();
TPMS_1_Timer.start();
GW_PC_7_Timer.start();
FCM_4_Timer.start();
FCM_3_Timer.start();
PEPS_1_Timer.start();
GW_PC_4_Timer.start();
BCM_4_Timer.start();

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Start On_Start

// CODE BLOCK BEGIN On_Timer On_GW_PC_1_Timer R1dfUENfMV9UaW1lcg__
// 定时器触发事件 "On_GW_PC_1_Timer" for Timer GW_PC_1_Timer
void on_timer_On_GW_PC_1_Timer(void) { try { // 定时器 = GW_PC_1_Timer
TGW_PC_1_1 GW_PC_1_1;
                        
app.get_system_var_double("EMS_2_EngineSpeed", &EMS_2_EngineSpeed_signal);
app.get_system_var_uint32("EMS_2_EngineSpeedValid", &EMS_2_EngineSpeedValid_signal);
app.get_system_var_uint32("EMS_2_Timeout_Flag", &EMS_2_Timeout_Flag_signal);
app.get_system_var_uint32("EMS_3_Timeout_Flag", &EMS_3_Timeout_Flag_signal);
app.get_system_var_uint32("EMS_3_EngineReleaseSig", &EMS_3_EngineReleaseSig_signal);
app.get_system_var_uint32("TCU_1_TcuFaultLamp", &TCU_1_TcuFaultLamp_signal);
app.get_system_var_uint32("TCU_1_TransOilWrnLmpReq", &TCU_1_TransOilWrnLmpReq_signal);
app.get_system_var_uint32("TCU_1_Timeout_Flag", &TCU_1_Timeout_Flag_signal);
app.get_system_var_uint32("EMS_3_SS_Active_Lamp", &EMS_3_SS_Active_Lamp_signal);
app.get_system_var_uint32("EMS_3_SS_Fault_Lamp", &EMS_3_SS_Fault_Lamp_signal);
app.get_system_var_uint32("EMS_3_SS_SetSts", &EMS_3_SS_SetSts_signal);
app.get_system_var_uint32("TCU_3_Drivemode", &TCU_3_Drivemode_signal);
app.get_system_var_uint32("TCU_3_Timeout_Flag", &TCU_3_Timeout_Flag_signal);

GW_PC_1_1.init();
 
GW_PC_1_1.set_EMS_2_EngineSpeed(EMS_2_EngineSpeed_signal);
GW_PC_1_1.set_EMS_2_EngineSpeedValid(EMS_2_EngineSpeedValid_signal);
GW_PC_1_1.set_EMS_2_Timeout_Flag(EMS_2_Timeout_Flag_signal);
GW_PC_1_1.set_EMS_3_Timeout_Flag(EMS_3_Timeout_Flag_signal);
GW_PC_1_1.set_EMS_3_EngineReleaseSig(EMS_3_EngineReleaseSig_signal);
GW_PC_1_1.set_TCU_1_TcuFaultLamp(TCU_1_TcuFaultLamp_signal);
GW_PC_1_1.set_TCU_1_TransOilWrnLmpReq(TCU_1_TransOilWrnLmpReq_signal);
GW_PC_1_1.set_TCU_1_Timeout_Flag(TCU_1_Timeout_Flag_signal);
GW_PC_1_1.set_EMS_3_SS_Active_Lamp(EMS_3_SS_Active_Lamp_signal);
GW_PC_1_1.set_EMS_3_SS_Fault_Lamp(EMS_3_SS_Fault_Lamp_signal);
GW_PC_1_1.set_EMS_3_SS_SetSts(EMS_3_SS_SetSts_signal);
GW_PC_1_1.set_TCU_3_Drivemode(TCU_3_Drivemode_signal);
GW_PC_1_1.set_TCU_3_Timeout_Flag(TCU_3_Timeout_Flag_signal);

com.transmit_can_async(&GW_PC_1_1.FCAN); 

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_1_Timer

// CODE BLOCK BEGIN On_Timer On_GW_PC_6_Timer R1dfUENfNl9UaW1lcg__
// 定时器触发事件 "On_GW_PC_6_Timer" for Timer GW_PC_6_Timer
void on_timer_On_GW_PC_6_Timer(void) { try { // 定时器 = GW_PC_6_Timer
TGW_PC_6_1 GW_PC_6_1;
                        
app.get_system_var_double("EMS_4_EngineCoolantTemp", &EMS_4_EngineCoolantTemp_signal);
app.get_system_var_uint32("EMS_4_EngineCoolantTempValid", &EMS_4_EngineCoolantTempValid_signal);
app.get_system_var_uint32("EMS_4_Timeout_Flag", &EMS_4_Timeout_Flag_signal);
app.get_system_var_uint32("EMS_6_GeneratorFaultLamp", &EMS_6_GeneratorFaultLamp_signal);
app.get_system_var_uint32("EMS_6_Timeout_Flag", &EMS_6_Timeout_Flag_signal);
app.get_system_var_uint32("EMS_4_MIL", &EMS_4_MIL_signal);
app.get_system_var_uint32("EMS_6_OilPressureLamp", &EMS_6_OilPressureLamp_signal);
app.get_system_var_uint32("EMS_6_GPFState", &EMS_6_GPFState_signal);
app.get_system_var_uint32("EMS_4_CruiseControlStatus", &EMS_4_CruiseControlStatus_signal);
app.get_system_var_double("EMS_4_CruiseTargetSpeed", &EMS_4_CruiseTargetSpeed_signal);
app.get_system_var_uint32("EMS_4_SVS", &EMS_4_SVS_signal);
GW_PC_6_1.init();
 
GW_PC_6_1.set_EMS_4_EngineCoolantTemp(EMS_4_EngineCoolantTemp_signal);
GW_PC_6_1.set_EMS_4_EngineCoolantTempValid(EMS_4_EngineCoolantTempValid_signal);
GW_PC_6_1.set_EMS_4_Timeout_Flag(EMS_4_Timeout_Flag_signal);
GW_PC_6_1.set_EMS_6_GeneratorFaultLamp(EMS_6_GeneratorFaultLamp_signal);
GW_PC_6_1.set_EMS_6_Timeout_Flag(EMS_6_Timeout_Flag_signal);
GW_PC_6_1.set_EMS_4_MIL(EMS_4_MIL_signal);
GW_PC_6_1.set_EMS_6_OilPressureLamp(EMS_6_OilPressureLamp_signal);
GW_PC_6_1.set_EMS_6_GPFState(EMS_6_GPFState_signal);
GW_PC_6_1.set_EMS_4_CruiseControlStatus(EMS_4_CruiseControlStatus_signal);
GW_PC_6_1.set_EMS_4_CruiseTargetSpeed(EMS_4_CruiseTargetSpeed_signal);
GW_PC_6_1.set_EMS_4_SVS(EMS_4_SVS_signal);

com.transmit_can_async(&GW_PC_6_1.FCAN); 

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_6_Timer

// CODE BLOCK BEGIN On_Timer On_BCM_1_Timer QkNNXzFfVGltZXI_
// 定时器触发事件 "On_BCM_1_Timer" for Timer BCM_1_Timer
void on_timer_On_BCM_1_Timer(void) { try { // 定时器 = BCM_1_Timer
TBCM_1_1 BCM_1_1;

static uint32_t toggle_counter = 0;
static bool toggle_flag = false;
static bool send125Hz_mode = false;
static uint32_t BCM_LeftTurnLightSts_signal_last;
static uint32_t BCM_LeftTurnLightSts_signal_now;
static uint32_t BCM_RightTurnLightSts_signal_last;
static uint32_t BCM_RightTurnLightSts_signal_now;
static uint32_t BCM_EmergencyLightSts_signal_last;
static uint32_t BCM_EmergencyLightSts_signal_now;

toggle_counter++;
if (toggle_counter >= 8) {
    toggle_counter = 0;
    toggle_flag = true;
}

app.get_system_var_uint32("BCM_LeftTurnLightSts", &BCM_LeftTurnLightSts_signal);
app.get_system_var_uint32("BCM_RightTurnLightSts", &BCM_RightTurnLightSts_signal);
app.get_system_var_uint32("BCM_EmergencyLightSts", &BCM_EmergencyLightSts_signal);

BCM_1_1.init();

if(BCM_LeftTurnLightSts_signal == 1){
    send125Hz_mode = true;
    if(BCM_LeftTurnLightSts_signal_last == 0){
         BCM_LeftTurnLightSts_signal_now = toggle_flag ? 1 : 0;  
    }
    else{
         BCM_LeftTurnLightSts_signal_now = toggle_flag ? 0 : 1; 
    }                            
    BCM_1_1.set_BCM_LeftTurnLightSts(BCM_LeftTurnLightSts_signal_now); 
    BCM_LeftTurnLightSts_signal_last = BCM_LeftTurnLightSts_signal_now;  
}
else{
    BCM_1_1.set_BCM_LeftTurnLightSts(BCM_LeftTurnLightSts_signal);  
}
if(BCM_RightTurnLightSts_signal == 1){
    send125Hz_mode = true;
    if(BCM_RightTurnLightSts_signal_last == 0){
         BCM_RightTurnLightSts_signal_now = toggle_flag ? 1 : 0;  
    }
    else{
         BCM_RightTurnLightSts_signal_now = toggle_flag ? 0 : 1; 
    }                            
    BCM_1_1.set_BCM_RightTurnLightSts(BCM_RightTurnLightSts_signal_now); 
    BCM_RightTurnLightSts_signal_last = BCM_RightTurnLightSts_signal_now; 
}
else{
     BCM_1_1.set_BCM_RightTurnLightSts(BCM_RightTurnLightSts_signal);
}
if(BCM_EmergencyLightSts_signal == 1){
    send125Hz_mode = true;
    if(BCM_EmergencyLightSts_signal_last == 0){
         BCM_EmergencyLightSts_signal_now = toggle_flag ? 1 : 0;  
    }
    else{
         BCM_EmergencyLightSts_signal_now = toggle_flag ? 0 : 1; 
    }                            
    BCM_1_1.set_BCM_EmergencyLightSts(BCM_EmergencyLightSts_signal_now); 
    BCM_EmergencyLightSts_signal_last = BCM_EmergencyLightSts_signal_now;         
}
else{
    BCM_1_1.set_BCM_EmergencyLightSts(BCM_EmergencyLightSts_signal);
}

if(send125Hz_mode == true && toggle_flag == true){
    com.transmit_can_async(&BCM_1_1.FCAN);
    send125Hz_mode = false;
    toggle_flag = false;
}
else if(send125Hz_mode == false){
    com.transmit_can_async(&BCM_1_1.FCAN);
    send125Hz_mode = false;
    toggle_flag = false;
}

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_BCM_1_Timer

// CODE BLOCK BEGIN On_Timer On_GW_BD_9_Timer R1dfQkRfOV9UaW1lcg__
// 定时器触发事件 "On_GW_BD_9_Timer" for Timer GW_BD_9_Timer
void on_timer_On_GW_BD_9_Timer(void) { try { // 定时器 = GW_BD_9_Timer
TGW_BD_9_1 GW_BD_9_1;
                        
app.get_system_var_uint32("BCM_1_HighBeamSts", &BCM_1_HighBeamSts_signal);
app.get_system_var_uint32("BCM_1_Timeout_Flag", &BCM_1_Timeout_Flag_signal);
app.get_system_var_uint32("BCM_1_LowBeamSts", &BCM_1_LowBeamSts_signal);
app.get_system_var_uint32("BCM_1_PositionLightSts", &BCM_1_PositionLightSts_signal);
app.get_system_var_uint32("BCM_1_FrontFogLightSts", &BCM_1_FrontFogLightSts_signal);
app.get_system_var_uint32("BCM_1_RearFogLightSts", &BCM_1_RearFogLightSts_signal);
app.get_system_var_uint32("BCM_1_DaytimeRunningLightSts", &BCM_1_DaytimeRunningLightSts_signal);
app.get_system_var_uint32("BCM_1_PowerMode", &BCM_1_PowerMode_signal);

GW_BD_9_1.init();
 
GW_BD_9_1.set_BCM_1_HighBeamSts(BCM_1_HighBeamSts_signal);
GW_BD_9_1.set_BCM_1_LowBeamSts(BCM_1_LowBeamSts_signal);
GW_BD_9_1.set_BCM_1_PositionLightSts(BCM_1_PositionLightSts_signal);
GW_BD_9_1.set_BCM_1_FrontFogLightSts(BCM_1_FrontFogLightSts_signal);
GW_BD_9_1.set_BCM_1_RearFogLightSts(BCM_1_RearFogLightSts_signal);
GW_BD_9_1.set_BCM_1_Timeout_Flag(BCM_1_Timeout_Flag_signal);
GW_BD_9_1.set_BCM_1_DaytimeRunningLightSts(BCM_1_DaytimeRunningLightSts_signal);
GW_BD_9_1.set_BCM_1_PowerMode(BCM_1_PowerMode_signal);

com.transmit_can_async(&GW_BD_9_1.FCAN); 

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_BD_9_Timer

// CODE BLOCK BEGIN On_Timer On_ACU_1_Timer QUNVXzFfVGltZXI_
// 定时器触发事件 "On_ACU_1_Timer" for Timer ACU_1_Timer
void on_timer_On_ACU_1_Timer(void) { try { // 定时器 = ACU_1_Timer
TACU_1_1 ACU_1_1;

app.get_system_var_uint32("ACU_AirbagWarningStatus", &ACU_AirbagWarningStatus_signal);
app.get_system_var_uint32("ACU_AirbagInhibitWarning", &ACU_AirbagInhibitWarning_signal);

ACU_1_1.init();

ACU_1_1.set_ACU_AirbagWarningStatus(ACU_AirbagWarningStatus_signal);
ACU_1_1.set_ACU_AirbagInhibitWarning(ACU_AirbagInhibitWarning_signal);

com.transmit_can_async(&ACU_1_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_ACU_1_Timer

// CODE BLOCK BEGIN On_Timer On_TPMS_1_Timer VFBNU18xX1RpbWVy
// 定时器触发事件 "On_TPMS_1_Timer" for Timer TPMS_1_Timer
void on_timer_On_TPMS_1_Timer(void) { try { // 定时器 = TPMS_1_Timer
TTPMS_1_1 TPMS_1_1;

app.get_system_var_uint32("TPMS_SystemStatus", &TPMS_SystemStatus_signal);
app.get_system_var_uint32("TPMS_LearningStatus", &TPMS_LearningStatus_signal);
app.get_system_var_uint32("TPMS_TireLeakage", &TPMS_TireLeakage_signal);

TPMS_1_1.init();

TPMS_1_1.set_TPMS_SystemStatus(TPMS_SystemStatus_signal);
TPMS_1_1.set_TPMS_LearningStatus(TPMS_LearningStatus_signal);
TPMS_1_1.set_TPMS_TireLeakage(TPMS_TireLeakage_signal);

com.transmit_can_async(&TPMS_1_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_TPMS_1_Timer

// CODE BLOCK BEGIN On_Timer On_GW_PC_7_Timer R1dfUENfN19UaW1lcg__
// 定时器触发事件 "On_GW_PC_7_Timer" for Timer GW_PC_7_Timer
void on_timer_On_GW_PC_7_Timer(void) { try { // 定时器 = GW_PC_7_Timer
TGW_PC_7_1 GW_PC_7_1;

app.get_system_var_uint32("AWD_1_DiagnosticLampRequest", &AWD_1_DiagnosticLampRequest_signal);
app.get_system_var_uint32("AWD_1_Lamp2WD", &AWD_1_Lamp2WD_signal);
app.get_system_var_uint32("AWD_1_Lamp4WDLock", &AWD_1_Lamp4WDLock_signal);
app.get_system_var_uint32("AWD_1_Lamp4WDLow", &AWD_1_Lamp4WDLow_signal);
app.get_system_var_uint32("AWD_1_Timeout_Flag", &AWD_1_Timeout_Flag_signal);
app.get_system_var_uint32("EDL_1_RearDiffLockGreenLamp", &EDL_1_RearDiffLockGreenLamp_signal);
app.get_system_var_uint32("EDL_1_RearDiffLockYellowLamp", &EDL_1_RearDiffLockYellowLamp_signal);
app.get_system_var_uint32("EDL_1_FrontDiffLockGreenLamp", &EDL_1_FrontDiffLockGreenLamp_signal);
app.get_system_var_uint32("EDL_1_FrontDiffLockYellowLamp", &EDL_1_FrontDiffLockYellowLamp_signal);
app.get_system_var_uint32("EDL_1_Timeout_Flag", &EDL_1_Timeout_Flag_signal);

GW_PC_7_1.init();

GW_PC_7_1.set_AWD_1_DiagnosticLampRequest(AWD_1_DiagnosticLampRequest_signal);
GW_PC_7_1.set_AWD_1_Lamp2WD(AWD_1_Lamp2WD_signal);
GW_PC_7_1.set_AWD_1_Lamp4WDLock(AWD_1_Lamp4WDLock_signal);
GW_PC_7_1.set_AWD_1_Lamp4WDLow(AWD_1_Lamp4WDLow_signal);
GW_PC_7_1.set_AWD_1_Timeout_Flag(AWD_1_Timeout_Flag_signal);
GW_PC_7_1.set_EDL_1_RearDiffLockGreenLamp(EDL_1_RearDiffLockGreenLamp_signal);
GW_PC_7_1.set_EDL_1_RearDiffLockYellowLamp(EDL_1_RearDiffLockYellowLamp_signal);
GW_PC_7_1.set_EDL_1_FrontDiffLockGreenLamp(EDL_1_FrontDiffLockGreenLamp_signal);
GW_PC_7_1.set_EDL_1_FrontDiffLockYellowLamp(EDL_1_FrontDiffLockYellowLamp_signal);
GW_PC_7_1.set_EDL_1_Timeout_Flag(EDL_1_Timeout_Flag_signal);

com.transmit_can_async(&GW_PC_7_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_7_Timer

// CODE BLOCK BEGIN On_Timer On_FCM_4_Timer RkNNXzRfVGltZXI_
// 定时器触发事件 "On_FCM_4_Timer" for Timer FCM_4_Timer
void on_timer_On_FCM_4_Timer(void) { try { // 定时器 = FCM_4_Timer
TFCM_4_1 FCM_4_1;

app.get_system_var_uint32("FCM_LDWSysSts", &FCM_LDWSysSts_signal);
app.get_system_var_uint32("FCM_LDWVoiceWarning", &FCM_LDWVoiceWarning_signal);
app.get_system_var_uint32("FCM_TSRDisplay", &FCM_TSRDisplay_signal);
app.get_system_var_uint32("FCM_TSROverSpdWarning", &FCM_TSROverSpdWarning_signal);
app.get_system_var_uint32("FCM_TSROverSpeedAcousticONOFFSts", &FCM_TSROverSpeedAcousticONOFFSts_signal);
app.get_system_var_uint32("FCM_TSRState", &FCM_TSRState_signal);
app.get_system_var_uint32("FCM_IHBCStatus", &FCM_IHBCStatus_signal);

FCM_4_1.init();

FCM_4_1.set_FCM_LDWSysSts(FCM_LDWSysSts_signal);
FCM_4_1.set_FCM_LDWVoiceWarning(FCM_LDWVoiceWarning_signal);
FCM_4_1.set_FCM_TSRDisplay(FCM_TSRDisplay_signal);
FCM_4_1.set_FCM_TSROverSpdWarning(FCM_TSROverSpdWarning_signal);
FCM_4_1.set_FCM_TSROverSpeedAcousticONOFFSts(FCM_TSROverSpeedAcousticONOFFSts_signal);
FCM_4_1.set_FCM_TSRState(FCM_TSRState_signal);
FCM_4_1.set_FCM_IHBCStatus(FCM_IHBCStatus_signal);

com.transmit_can_async(&FCM_4_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_FCM_4_Timer

// CODE BLOCK BEGIN On_Timer On_FCM_3_Timer RkNNXzNfVGltZXI_
// 定时器触发事件 "On_FCM_3_Timer" for Timer FCM_3_Timer
void on_timer_On_FCM_3_Timer(void) { try { // 定时器 = FCM_3_Timer
TFCM_3_1 FCM_3_1; 

app.get_system_var_uint32("FCM_FCWMode", &FCM_FCWMode_signal);
app.get_system_var_uint32("FCM_AEBMode", &FCM_AEBMode_signal);
app.get_system_var_uint32("FCM_ACCMode", &FCM_ACCMode_signal);
app.get_system_var_double("FCM_ACCVSetDis", &FCM_ACCVSetDis_signal);
app.get_system_var_uint32("FCM_TimeGapSetICM", &FCM_TimeGapSetICM_signal);

FCM_3_1.init();

FCM_3_1.set_FCM_FCWMode(FCM_FCWMode_signal);
FCM_3_1.set_FCM_AEBMode(FCM_AEBMode_signal);
FCM_3_1.set_FCM_ACCMode(FCM_ACCMode_signal);
FCM_3_1.set_FCM_ACCVSetDis(FCM_ACCVSetDis_signal);
FCM_3_1.set_FCM_TimeGapSetICM(FCM_TimeGapSetICM_signal);

com.transmit_can_async(&FCM_3_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_FCM_3_Timer

// CODE BLOCK BEGIN On_Timer On_PEPS_1_Timer UEVQU18xX1RpbWVy
// 定时器触发事件 "On_PEPS_1_Timer" for Timer PEPS_1_Timer
void on_timer_On_PEPS_1_Timer(void) { try { // 定时器 = PEPS_1_Timer
TPEPS_1_1 PEPS_1_1;

app.get_system_var_uint32("PEPS_FailStatus", &PEPS_FailStatus_signal);

PEPS_1_1.init();

PEPS_1_1.set_PEPS_FailStatus(PEPS_FailStatus_signal);

com.transmit_can_async(&PEPS_1_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_PEPS_1_Timer

// CODE BLOCK BEGIN On_Timer On_GW_PC_4_Timer R1dfUENfNF9UaW1lcg__
// 定时器触发事件 "On_GW_PC_4_Timer" for Timer GW_PC_4_Timer
void on_timer_On_GW_PC_4_Timer(void) { try { // 定时器 = GW_PC_4_Timer
TGW_PC_4_1 GW_PC_4_1;

app.get_system_var_uint32("Swaybar_1_FrontSwaybarGreenLamp", &Swaybar_1_FrontSwaybarGreenLamp_signal);
app.get_system_var_uint32("Swaybar_1_FrontSwaybarYellowLamp", &Swaybar_1_FrontSwaybarYellowLamp_signal);
app.get_system_var_uint32("Swaybar_1_Timeout_Flag", &Swaybar_1_Timeout_Flag_signal);

GW_PC_4_1.init();

GW_PC_4_1.set_Swaybar_1_FrontSwaybarGreenLamp(Swaybar_1_FrontSwaybarGreenLamp_signal);
GW_PC_4_1.set_Swaybar_1_FrontSwaybarYellowLamp(Swaybar_1_FrontSwaybarYellowLamp_signal);
GW_PC_4_1.set_Swaybar_1_Timeout_Flag(Swaybar_1_Timeout_Flag_signal);

com.transmit_can_async(&GW_PC_4_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_4_Timer

// CODE BLOCK BEGIN On_Timer On_BCM_4_Timer QkNNXzRfVGltZXI_
// 定时器触发事件 "On_BCM_4_Timer" for Timer BCM_4_Timer
void on_timer_On_BCM_4_Timer(void) { try { // 定时器 = BCM_4_Timer
TBCM_4_1 BCM_4_1;

app.get_system_var_uint32("BCM_AAL_ONOFFSts", &BCM_AAL_ONOFFSts_signal);
app.get_system_var_uint32("BCM_SteeringwheelheatingSts", &BCM_SteeringwheelheatingSts_signal);

BCM_4_1.init();

BCM_4_1.set_BCM_AAL_ONOFFSts(BCM_AAL_ONOFFSts_signal);
BCM_4_1.set_BCM_SteeringwheelheatingSts(BCM_SteeringwheelheatingSts_signal);

com.transmit_can_async(&BCM_4_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_BCM_4_Timer

// CODE BLOCK BEGIN Step_Function  MjA_
// 主step函数，执行周期 20 ms
void step(void) { try { // 周期 = 20 ms
 


} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END Step_Function 

