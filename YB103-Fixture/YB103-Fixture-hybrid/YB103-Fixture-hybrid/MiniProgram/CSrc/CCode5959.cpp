// GEN BLOCK BEGIN Include
#define TSMP_IMPL
#include "TSMaster.h"
#include "MPLibrary.h"
#include "Database.h"
#include "TSMasterBaseInclude.h"
#include "Configuration.h"
// GEN BLOCK END Include

// CODE BLOCK BEGIN Timer ABS_3_Timer MjA_
// 定时器文档 "ABS_3_Timer"
TMPTimerMS ABS_3_Timer;
// CODE BLOCK END Timer ABS_3_Timer

// CODE BLOCK BEGIN Timer GW_PC_26_Timer MTA_
// 定时器文档 "GW_PC_26_Timer"
TMPTimerMS GW_PC_26_Timer;
// CODE BLOCK END Timer GW_PC_26_Timer

// CODE BLOCK BEGIN Timer BMS_33_Timer MTAw
// 定时器文档 "BMS_33_Timer"
TMPTimerMS BMS_33_Timer;
// CODE BLOCK END Timer BMS_33_Timer

// CODE BLOCK BEGIN Timer VCU_43_Timer MTAw
// 定时器文档 "VCU_43_Timer"
TMPTimerMS VCU_43_Timer;
// CODE BLOCK END Timer VCU_43_Timer

// CODE BLOCK BEGIN Timer VCU_42_Timer MTAw
// 定时器文档 "VCU_42_Timer"
TMPTimerMS VCU_42_Timer;
// CODE BLOCK END Timer VCU_42_Timer

// CODE BLOCK BEGIN Timer VCU_41_Timer NTA_
// 定时器文档 "VCU_41_Timer"
TMPTimerMS VCU_41_Timer;
// CODE BLOCK END Timer VCU_41_Timer

// CODE BLOCK BEGIN Timer VCU_37_Timer NTA_
// 定时器文档 "VCU_37_Timer"
TMPTimerMS VCU_37_Timer;
// CODE BLOCK END Timer VCU_37_Timer

// CODE BLOCK BEGIN Timer TPMS_1_Timer MTAw
// 定时器文档 "TPMS_1_Timer"
TMPTimerMS TPMS_1_Timer;
// CODE BLOCK END Timer TPMS_1_Timer

// CODE BLOCK BEGIN Timer VCU_32_Timer MTA_
// 定时器文档 "VCU_32_Timer"
TMPTimerMS VCU_32_Timer;
// CODE BLOCK END Timer VCU_32_Timer

// CODE BLOCK BEGIN Timer GW_PC_7_Timer MjA_
// 定时器文档 "GW_PC_7_Timer"
TMPTimerMS GW_PC_7_Timer;
// CODE BLOCK END Timer GW_PC_7_Timer

// CODE BLOCK BEGIN Timer GW_BD_14_Timer MTAw
// 定时器文档 "GW_BD_14_Timer"
TMPTimerMS GW_BD_14_Timer;
// CODE BLOCK END Timer GW_BD_14_Timer

// CODE BLOCK BEGIN Timer BCM_1_Timer MTAw
// 定时器文档 "BCM_1_Timer"
TMPTimerMS BCM_1_Timer;
// CODE BLOCK END Timer BCM_1_Timer

// CODE BLOCK BEGIN Timer GW_PC_2_Timer MjA_
// 定时器文档 "GW_PC_2_Timer"
TMPTimerMS GW_PC_2_Timer;
// CODE BLOCK END Timer GW_PC_2_Timer

// CODE BLOCK BEGIN Timer EPB_1_Timer MjA_
// 定时器文档 "EPB_1_Timer"
TMPTimerMS EPB_1_Timer;
// CODE BLOCK END Timer EPB_1_Timer

// CODE BLOCK BEGIN Timer DCDC_1_Timer NTAw
// 定时器文档 "DCDC_1_Timer"
TMPTimerMS DCDC_1_Timer;
// CODE BLOCK END Timer DCDC_1_Timer

// CODE BLOCK BEGIN Timer VCU_31_Timer MTA_
// 定时器文档 "VCU_31_Timer"
TMPTimerMS VCU_31_Timer;
// CODE BLOCK END Timer VCU_31_Timer

// CODE BLOCK BEGIN Timer GW_PC_4_Timer MTAw
// 定时器文档 "GW_PC_4_Timer"
TMPTimerMS GW_PC_4_Timer;
// CODE BLOCK END Timer GW_PC_4_Timer

// CODE BLOCK BEGIN Timer GSM_1_Timer MTAw
// 定时器文档 "GSM_1_Timer"
TMPTimerMS GSM_1_Timer;
// CODE BLOCK END Timer GSM_1_Timer

// CODE BLOCK BEGIN Timer TCU_13_Timer MTA_
// 定时器文档 "TCU_13_Timer"
TMPTimerMS TCU_13_Timer;
// CODE BLOCK END Timer TCU_13_Timer

// CODE BLOCK BEGIN Timer BMS_23_Timer MTAwMA__
// 定时器文档 "BMS_23_Timer"
TMPTimerMS BMS_23_Timer;
// CODE BLOCK END Timer BMS_23_Timer

// CODE BLOCK BEGIN Timer GW_PC_31_Timer MTA_
// 定时器文档 "GW_PC_31_Timer"
TMPTimerMS GW_PC_31_Timer;
// CODE BLOCK END Timer GW_PC_31_Timer

// CODE BLOCK BEGIN Timer BMS_46_Timer MTAw
// 定时器文档 "BMS_46_Timer"
TMPTimerMS BMS_46_Timer;
// CODE BLOCK END Timer BMS_46_Timer

// CODE BLOCK BEGIN Timer BMS_3_Timer MTAwMA__
// 定时器文档 "BMS_3_Timer"
TMPTimerMS BMS_3_Timer;
// CODE BLOCK END Timer BMS_3_Timer

// CODE BLOCK BEGIN Timer ESP_5_Timer MjA_
// 定时器文档 "ESP_5_Timer"
TMPTimerMS ESP_5_Timer;
// CODE BLOCK END Timer ESP_5_Timer

// CODE BLOCK BEGIN Timer AVAS_Timer MTAwMA__
// 定时器文档 "AVAS_Timer"
TMPTimerMS AVAS_Timer;
// CODE BLOCK END Timer AVAS_Timer

// CODE BLOCK BEGIN Global_Definitions 
double ABS_VehicleSpeed_signal;
u32 ABS_VehicleSpeedValid_signal;

double EMS_11_EngSpd_signal;
u32 EMS_11_EngSpdValid_signal;
u32 EMS_11_Timeout_Flag_signal;

u32 EMS_14_engCoolantTempValid_signal;
double EMS_14_engCoolantTemp_signal;
u32 EMS_14_Timeout_Flag_signal;

double BMS_BatPackSOCDisply_signal;

u32 VCU_OdoMeter_signal;

u32 VCU_OdoMeterHEV_signal;

u32 VCU_OdoMeterEV_signal;

u32 VCU_DrvRangeFuel_signal;

u32 VCU_DrvRangeTotal_signal;

double EMS_14_FuelConsumption_signal;
double VCU_InsAvgFuelCons_signal;

double VCU_AvgPwrConslast100km_signal;

double VCU_AvgFuelConslast100km_signal;

double VCU_AvgEgyConslast100km_signal;

double VCU_AvgPwrConsLifetime_signal;

double VCU_AvgFuelConsLifetime_signal;

u32 VCU_DrvOutputSurplusPower_signal;

u32 TPMS_SystemStatus_signal;
u32 TPMS_TireID_signal;
u32 TPMS_SensorLost_signal;
u32 TPMS_TireLeakage_signal;
u32 TPMS_LearningStatus_signal;
u32 TPMS_TirePressureStatus_signal;
double TPMS_TirePressure_signal;

u32 VCU_TargetGear_signal;
u32 VCU_TargetGearValid_signal;
u32 VCU_GearShiftPosition_signal;
u32 VCU_GearShiftPositionValid_signal;

u32 EDL_1_RearDiffLockGreenLamp_signal;
u32 EDL_1_RearDiffLockYellowLamp_signal;
u32 EDL_1_FrontDiffLockGreenLamp_signal;
u32 EDL_1_FrontDiffLockYellowLamp_signal;
u32 EDL_1_Timeout_Flag_signal;

u32 AC_2_OutsideTemperatureValid_signal;
double AC_2_OutsideTemperature_signal;
u32 AC_2_Timeout_Flag_signal;

u32 BCM_HighBeamSts_signal;

u32 BCM_LowBeamSts_signal;

u32 BCM_PositionLightSts_signal;

u32 BCM_FrontFogLightSts_signal;

u32 BCM_RearFogLightSts_signal;

u32 BCM_DaytimeRunningLightSts_signal;

u32 ABS_EbdFault_signal;
u32 ESP_1_DVTSessionFlag_signal;
u32 ESP_1_Timeout_Flag_signal;

u32 EPB_ActiveLamp_signal;
u32 EPB_WarningLamp_signal;

u32 DCDC_WorkStatus_signal;
u32 VCU_LvBat_ERR_MIL_signal;

u32 ABS_AbsFault_signal;

u32 AWD_1_Lamp4WDAuto_signal;
u32 AWD_1_Timeout_Flag_signal;

u32 EHPS_1_FaultStatus_signal;
u32 EHPS_1_Timeout_Flag_signal;
u32 SAS_1_CalibratedSt_signal;
u32 SAS_1_Timeout_Flag_signal;

u32 VCU_MILLamp_signal;

u32 EMS_14_OilPressureLamp_signal;

u32 GSM_GearShiftAuthRelease_signal;
u32 VCU_ReleaseSig_signal;

u32 TCU_TrsmFailLampReq_signal;

u32 EMS_14_GPFState_signal;

u32 VCU_VehFauLamp_signal;

u32 BMS_6C0_BATT_FAULT_IND_signal;

u32 BMS_6C0_OBC_REMIND_LAMP_signal;

u32 GCU_12_StaFaultOut_signal;
u32 GCU_12_Timeout_Flag_signal;
u32 MCU_11_StaFaultOut_signal;
u32 MCU_11_Timeout_Flag_signal;
u32 MCU_11_Motor_TempFault_signal;
u32 MCU_11_Motor_ContrlTempFault_signal;

u32 BMS_6C0_VEH_INSULATION_FAULT_IND_signal;

u32 BMS_ChrgConctSta_signal;
u32 BMS_ChrgSta_signal;

u32 VCU_VehRunSta_signal;

u32 BMS_6C0_BATT_TEMP_LAMP_signal;

u32 B2V_FaultInfo_32960_ThermalRunaw_signal;

u32 VCU_TurtleLamp_signal;
u32 VCU_VehModDisply_signal;

u32 EMS_11_SVS_signal;

u32 VCU_Drivemode_signal;

u32 ESP_CCO_Active_signal;
u32 ESP_CCO_Faied_signal;

u32 EPB_TAB_Sts_signal;

u32 VCU_HVILFauSta_signal;

u32 TCU_OilTempOverHi_signal;

u32 AVAS_SwtSts_signal;

u32 BCM_PowerMode_signal;
// CODE BLOCK END Global_Definitions 

// CODE BLOCK BEGIN On_Timer On_ABS_3_Timer QUJTXzNfVGltZXI_
// 定时器触发事件 "On_ABS_3_Timer" for Timer ABS_3_Timer
void on_timer_On_ABS_3_Timer(void) { try { // 定时器 = ABS_3_Timer
TABS_3_1 ABS_3_1;  

app.get_system_var_double("ABS_VehicleSpeed", &ABS_VehicleSpeed_signal);
app.get_system_var_uint32("ABS_VehicleSpeedValid", &ABS_VehicleSpeedValid_signal);
app.get_system_var_uint32("ABS_EbdFault", &ABS_EbdFault_signal);
app.get_system_var_uint32("ABS_AbsFault", &ABS_AbsFault_signal);

ABS_3_1.init();

ABS_3_1.set_ABS_VehicleSpeed(ABS_VehicleSpeed_signal);
ABS_3_1.set_ABS_VehicleSpeedValid(ABS_VehicleSpeedValid_signal);
ABS_3_1.set_ABS_EbdFault(ABS_EbdFault_signal);
ABS_3_1.set_ABS_AbsFault(ABS_AbsFault_signal);

com.transmit_can_async(&ABS_3_1.FCAN); 

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_ABS_3_Timer

// CODE BLOCK BEGIN On_Start On_Start
// 启动事件 "On_Start"
void on_start_On_Start(void) { try { // 程序启动事件
app.connect();

ABS_3_Timer.start();
GW_PC_26_Timer.start();
BMS_33_Timer.start();
VCU_43_Timer.start();
VCU_42_Timer.start();
VCU_41_Timer.start();
VCU_37_Timer.start();
TPMS_1_Timer.start();
VCU_32_Timer.start();
GW_PC_7_Timer.start();
GW_BD_14_Timer.start();
BCM_1_Timer.start();
GW_PC_2_Timer.start();
EPB_1_Timer.start();
DCDC_1_Timer.start();
VCU_31_Timer.start();
GW_PC_4_Timer.start();    
GSM_1_Timer.start();
TCU_13_Timer.start();
BMS_23_Timer.start();
GW_PC_31_Timer.start();
BMS_46_Timer.start();
BMS_3_Timer.start();
ESP_5_Timer.start();

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Start On_Start

// CODE BLOCK BEGIN On_Timer On_GW_PC_26_Timer R1dfUENfMjZfVGltZXI_
// 定时器触发事件 "On_GW_PC_26_Timer" for Timer GW_PC_26_Timer
void on_timer_On_GW_PC_26_Timer(void) { try { // 定时器 = GW_PC_26_Timer
TGW_PC_26_1 GW_PC_26_1;

app.get_system_var_double("EMS_11_EngSpd", &EMS_11_EngSpd_signal);
app.get_system_var_uint32("EMS_11_EngSpdValid", &EMS_11_EngSpdValid_signal);
app.get_system_var_uint32("EMS_11_Timeout_Flag", &EMS_11_Timeout_Flag_signal);
app.get_system_var_uint32("EMS_14_engCoolantTempValid", &EMS_14_engCoolantTempValid_signal);
app.get_system_var_double("EMS_14_engCoolantTemp", &EMS_14_engCoolantTemp_signal);
app.get_system_var_uint32("EMS_14_Timeout_Flag", &EMS_14_Timeout_Flag_signal);
app.get_system_var_double("EMS_14_FuelConsumption", &EMS_14_FuelConsumption_signal);
app.get_system_var_uint32("EMS_14_OilPressureLamp", &EMS_14_OilPressureLamp_signal);
app.get_system_var_uint32("EMS_14_GPFState", &EMS_14_GPFState_signal);
app.get_system_var_uint32("EMS_11_SVS", &EMS_11_SVS_signal);

GW_PC_26_1.init();

GW_PC_26_1.set_EMS_11_EngSpd(EMS_11_EngSpd_signal);
GW_PC_26_1.set_EMS_11_EngSpdValid(EMS_11_EngSpdValid_signal);
GW_PC_26_1.set_EMS_11_Timeout_Flag(EMS_11_Timeout_Flag_signal);
GW_PC_26_1.set_EMS_14_engCoolantTempValid(EMS_14_engCoolantTempValid_signal);
GW_PC_26_1.set_EMS_14_engCoolantTemp(EMS_14_engCoolantTemp_signal);
GW_PC_26_1.set_EMS_14_Timeout_Flag(EMS_14_Timeout_Flag_signal); 
GW_PC_26_1.set_EMS_14_FuelConsumption(EMS_14_FuelConsumption_signal);
GW_PC_26_1.set_EMS_14_OilPressureLamp(EMS_14_OilPressureLamp_signal);
GW_PC_26_1.set_EMS_14_GPFState(EMS_14_GPFState_signal);
GW_PC_26_1.set_EMS_11_SVS(EMS_11_SVS_signal);

com.transmit_can_async(&GW_PC_26_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_26_Timer

// CODE BLOCK BEGIN On_Timer On_BMS_33_Timer Qk1TXzMzX1RpbWVy
// 定时器触发事件 "On_BMS_33_Timer" for Timer BMS_33_Timer
void on_timer_On_BMS_33_Timer(void) { try { // 定时器 = BMS_33_Timer
TBMS_33_1 BMS_33_1;

app.get_system_var_double("BMS_BatPackSOCDisply", &BMS_BatPackSOCDisply_signal);

BMS_33_1.init();

BMS_33_1.set_BMS_BatPackSOCDisply(BMS_BatPackSOCDisply_signal);

com.transmit_can_async(&BMS_33_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_BMS_33_Timer

// CODE BLOCK BEGIN On_Timer On_VCU_43_Timer VkNVXzQzX1RpbWVy
// 定时器触发事件 "On_VCU_43_Timer" for Timer VCU_43_Timer
void on_timer_On_VCU_43_Timer(void) { try { // 定时器 = VCU_43_Timer
TVCU_43_1 VCU_43_1;

app.get_system_var_uint32("VCU_OdoMeter", &VCU_OdoMeter_signal);
app.get_system_var_uint32("VCU_OdoMeterHEV", &VCU_OdoMeterHEV_signal);
app.get_system_var_uint32("VCU_OdoMeterEV", &VCU_OdoMeterEV_signal);

VCU_43_1.init();

VCU_43_1.set_VCU_OdoMeter(VCU_OdoMeter_signal);
VCU_43_1.set_VCU_OdoMeterHEV(VCU_OdoMeterHEV_signal);
VCU_43_1.set_VCU_OdoMeterEV(VCU_OdoMeterEV_signal);

com.transmit_can_async(&VCU_43_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_VCU_43_Timer

// CODE BLOCK BEGIN On_Timer On_VCU_42_Timer VkNVXzQyX1RpbWVy
// 定时器触发事件 "On_VCU_42_Timer" for Timer VCU_42_Timer
void on_timer_On_VCU_42_Timer(void) { try { // 定时器 = VCU_42_Timer
TVCU_42_1 VCU_42_1;

app.get_system_var_uint32("VCU_DrvRangeFuel", &VCU_DrvRangeFuel_signal);
app.get_system_var_uint32("VCU_DrvRangeTotal", &VCU_DrvRangeTotal_signal);
app.get_system_var_double("VCU_AvgPwrConsLifetime", &VCU_AvgPwrConsLifetime_signal);
app.get_system_var_double("VCU_AvgFuelConsLifetime", &VCU_AvgFuelConsLifetime_signal);

VCU_42_1.init();

VCU_42_1.set_VCU_DrvRangeFuel(VCU_DrvRangeFuel_signal);
VCU_42_1.set_VCU_DrvRangeTotal(VCU_DrvRangeTotal_signal);
VCU_42_1.set_VCU_AvgPwrConsLifetime(VCU_AvgPwrConsLifetime_signal);
VCU_42_1.set_VCU_AvgFuelConsLifetime(VCU_AvgFuelConsLifetime_signal);

com.transmit_can_async(&VCU_42_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_VCU_42_Timer

// CODE BLOCK BEGIN On_Timer On_VCU_41_Timer VkNVXzQxX1RpbWVy
// 定时器触发事件 "On_VCU_41_Timer" for Timer VCU_41_Timer
void on_timer_On_VCU_41_Timer(void) { try { // 定时器 = VCU_41_Timer
TVCU_41_1 VCU_41_1;

app.get_system_var_double("VCU_InsAvgFuelCons", &VCU_InsAvgFuelCons_signal);
app.get_system_var_double("VCU_AvgPwrConslast100km", &VCU_AvgPwrConslast100km_signal);
app.get_system_var_double("VCU_AvgFuelConslast100km", &VCU_AvgFuelConslast100km_signal);
app.get_system_var_double("VCU_AvgEgyConslast100km", &VCU_AvgEgyConslast100km_signal);

VCU_41_1.init();

VCU_41_1.set_VCU_InsAvgFuelCons(VCU_InsAvgFuelCons_signal);
VCU_41_1.set_VCU_AvgPwrConslast100km(VCU_AvgPwrConslast100km_signal);
VCU_41_1.set_VCU_AvgFuelConslast100km(VCU_AvgFuelConslast100km_signal);
VCU_41_1.set_VCU_AvgEgyConslast100km(VCU_AvgEgyConslast100km_signal);

com.transmit_can_async(&VCU_41_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_VCU_41_Timer

// CODE BLOCK BEGIN On_Timer On_VCU_37_Timer VkNVXzM3X1RpbWVy
// 定时器触发事件 "On_VCU_37_Timer" for Timer VCU_37_Timer
void on_timer_On_VCU_37_Timer(void) { try { // 定时器 = VCU_37_Timer
TVCU_37_1 VCU_37_1;

app.get_system_var_uint32("VCU_DrvOutputSurplusPower", &VCU_DrvOutputSurplusPower_signal);

VCU_37_1.init();

VCU_37_1.set_VCU_DrvOutputSurplusPower(VCU_DrvOutputSurplusPower_signal);

com.transmit_can_async(&VCU_37_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_VCU_37_Timer

// CODE BLOCK BEGIN On_Timer On_TPMS_1_Timer VFBNU18xX1RpbWVy
// 定时器触发事件 "On_TPMS_1_Timer" for Timer TPMS_1_Timer
void on_timer_On_TPMS_1_Timer(void) { try { // 定时器 = TPMS_1_Timer
TTPMS_1_1 TPMS_1_1;

app.get_system_var_uint32("TPMS_SystemStatus", &TPMS_SystemStatus_signal);
app.get_system_var_uint32("TPMS_TireID", &TPMS_TireID_signal);
app.get_system_var_uint32("TPMS_SensorLost", &TPMS_SensorLost_signal);
app.get_system_var_uint32("TPMS_TireLeakage", &TPMS_TireLeakage_signal);
app.get_system_var_uint32("TPMS_LearningStatus", &TPMS_LearningStatus_signal);
app.get_system_var_uint32("TPMS_TirePressureStatus", &TPMS_TirePressureStatus_signal);
app.get_system_var_double("TPMS_TirePressure", &TPMS_TirePressure_signal);

TPMS_1_1.init();

TPMS_1_1.set_TPMS_SystemStatus(TPMS_SystemStatus_signal);
TPMS_1_1.set_TPMS_TireID(TPMS_TireID_signal);
TPMS_1_1.set_TPMS_SensorLost(TPMS_SensorLost_signal);
TPMS_1_1.set_TPMS_TireLeakage(TPMS_TireLeakage_signal);
TPMS_1_1.set_TPMS_LearningStatus(TPMS_LearningStatus_signal);
TPMS_1_1.set_TPMS_TirePressureStatus(TPMS_TirePressureStatus_signal);
TPMS_1_1.set_TPMS_TirePressure(TPMS_TirePressure_signal);

com.transmit_can_async(&TPMS_1_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_TPMS_1_Timer

// CODE BLOCK BEGIN On_Timer On_VCU_32_Timer VkNVXzMyX1RpbWVy
// 定时器触发事件 "On_VCU_32_Timer" for Timer VCU_32_Timer
void on_timer_On_VCU_32_Timer(void) { try { // 定时器 = VCU_32_Timer
TVCU_32_1 VCU_32_1;

app.get_system_var_uint32("VCU_TargetGear", &VCU_TargetGear_signal);
app.get_system_var_uint32("VCU_TargetGearValid", &VCU_TargetGearValid_signal);
app.get_system_var_uint32("VCU_GearShiftPosition", &VCU_GearShiftPosition_signal);
app.get_system_var_uint32("VCU_GearShiftPositionValid", &VCU_GearShiftPositionValid_signal);
app.get_system_var_uint32("VCU_ReleaseSig", &VCU_ReleaseSig_signal);
app.get_system_var_uint32("VCU_Drivemode", &VCU_Drivemode_signal);

VCU_32_1.init();

VCU_32_1.set_VCU_TargetGear(VCU_TargetGear_signal);
VCU_32_1.set_VCU_TargetGearValid(VCU_TargetGearValid_signal);
VCU_32_1.set_VCU_GearShiftPosition(VCU_GearShiftPosition_signal);
VCU_32_1.set_VCU_GearShiftPositionValid(VCU_GearShiftPositionValid_signal);
VCU_32_1.set_VCU_ReleaseSig(VCU_ReleaseSig_signal);
VCU_32_1.set_VCU_Drivemode(VCU_Drivemode_signal);

com.transmit_can_async(&VCU_32_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_VCU_32_Timer

// CODE BLOCK BEGIN On_Timer On_GW_BD_14_Timer R1dfQkRfMTRfVGltZXI_
// 定时器触发事件 "On_GW_BD_14_Timer" for Timer GW_BD_14_Timer
void on_timer_On_GW_BD_14_Timer(void) { try { // 定时器 = GW_BD_14_Timer
TGW_BD_14_1 GW_BD_14_1;
  
app.get_system_var_uint32("AC_2_OutsideTemperatureValid", &AC_2_OutsideTemperatureValid_signal);
app.get_system_var_double("AC_2_OutsideTemperature", &AC_2_OutsideTemperature_signal);
app.get_system_var_uint32("AC_2_Timeout_Flag", &AC_2_Timeout_Flag_signal);

GW_BD_14_1.init();

GW_BD_14_1.set_AC_2_OutsideTemperatureValid(AC_2_OutsideTemperatureValid_signal);
GW_BD_14_1.set_AC_2_OutsideTemperature(AC_2_OutsideTemperature_signal);
GW_BD_14_1.set_AC_2_Timeout_Flag(AC_2_Timeout_Flag_signal);

com.transmit_can_async(&GW_BD_14_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_BD_14_Timer

// CODE BLOCK BEGIN On_Timer On_BCM_1_Timer QkNNXzFfVGltZXI_
// 定时器触发事件 "On_BCM_1_Timer" for Timer BCM_1_Timer
void on_timer_On_BCM_1_Timer(void) { try { // 定时器 = BCM_1_Timer
TBCM_1_1 BCM_1_1;

app.get_system_var_uint32("BCM_HighBeamSts", &BCM_HighBeamSts_signal);
app.get_system_var_uint32("BCM_LowBeamSts", &BCM_LowBeamSts_signal);
app.get_system_var_uint32("BCM_PositionLightSts", &BCM_PositionLightSts_signal);
app.get_system_var_uint32("BCM_FrontFogLightSts", &BCM_FrontFogLightSts_signal);
app.get_system_var_uint32("BCM_RearFogLightSts", &BCM_RearFogLightSts_signal);
app.get_system_var_uint32("BCM_DaytimeRunningLightSts", &BCM_DaytimeRunningLightSts_signal);
app.get_system_var_uint32("BCM_PowerMode", &BCM_PowerMode_signal);

BCM_1_1.init();

BCM_1_1.set_BCM_HighBeamSts(BCM_HighBeamSts_signal);
BCM_1_1.set_BCM_LowBeamSts(BCM_LowBeamSts_signal);
BCM_1_1.set_BCM_PositionLightSts(BCM_PositionLightSts_signal);
BCM_1_1.set_BCM_FrontFogLightSts(BCM_FrontFogLightSts_signal);
BCM_1_1.set_BCM_RearFogLightSts(BCM_RearFogLightSts_signal);
BCM_1_1.set_BCM_DaytimeRunningLightSts(BCM_DaytimeRunningLightSts_signal);
BCM_1_1.set_BCM_PowerMode(BCM_PowerMode_signal);

com.transmit_can_async(&BCM_1_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_BCM_1_Timer

// CODE BLOCK BEGIN On_Timer On_GW_PC_2_Timer R1dfUENfMl9UaW1lcg__
// 定时器触发事件 "On_GW_PC_2_Timer" for Timer GW_PC_2_Timer
void on_timer_On_GW_PC_2_Timer(void) { try { // 定时器 = GW_PC_2_Timer
TGW_PC_2_1 GW_PC_2_1;

app.get_system_var_uint32("ESP_1_DVTSessionFlag", &ESP_1_DVTSessionFlag_signal);
app.get_system_var_uint32("ESP_1_Timeout_Flag", &ESP_1_Timeout_Flag_signal);
app.get_system_var_uint32("SAS_1_CalibratedSt", &SAS_1_CalibratedSt_signal);
app.get_system_var_uint32("SAS_1_Timeout_Flag", &SAS_1_Timeout_Flag_signal);
GW_PC_2_1.init();

GW_PC_2_1.set_ESP_1_DVTSessionFlag(ESP_1_DVTSessionFlag_signal);
GW_PC_2_1.set_ESP_1_Timeout_Flag(ESP_1_Timeout_Flag_signal);
GW_PC_2_1.set_SAS_1_CalibratedSt(SAS_1_CalibratedSt_signal);
GW_PC_2_1.set_SAS_1_Timeout_Flag(SAS_1_Timeout_Flag_signal);

com.transmit_can_async(&GW_PC_2_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_2_Timer

// CODE BLOCK BEGIN On_Timer On_EPB_1_Timer RVBCXzFfVGltZXI_
// 定时器触发事件 "On_EPB_1_Timer" for Timer EPB_1_Timer
void on_timer_On_EPB_1_Timer(void) { try { // 定时器 = EPB_1_Timer
TEPB_1_1 EPB_1_1;

app.get_system_var_uint32("EPB_ActiveLamp", &EPB_ActiveLamp_signal);
app.get_system_var_uint32("EPB_WarningLamp", &EPB_WarningLamp_signal);
app.get_system_var_uint32("EPB_TAB_Sts", &EPB_TAB_Sts_signal);

EPB_1_1.init();

EPB_1_1.set_EPB_ActiveLamp(EPB_ActiveLamp_signal);
EPB_1_1.set_EPB_WarningLamp(EPB_WarningLamp_signal);
EPB_1_1.set_EPB_TAB_Sts(EPB_TAB_Sts_signal);

com.transmit_can_async(&EPB_1_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_EPB_1_Timer

// CODE BLOCK BEGIN On_Timer On_DCDC_1_Timer RENEQ18xX1RpbWVy
// 定时器触发事件 "On_DCDC_1_Timer" for Timer DCDC_1_Timer
void on_timer_On_DCDC_1_Timer(void) { try { // 定时器 = DCDC_1_Timer
TDCDC_1_1 DCDC_1_1;

app.get_system_var_uint32("DCDC_WorkStatus", &DCDC_WorkStatus_signal);

DCDC_1_1.init();

DCDC_1_1.set_DCDC_WorkStatus(DCDC_WorkStatus_signal);

com.transmit_can_async(&DCDC_1_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_DCDC_1_Timer

// CODE BLOCK BEGIN On_Timer On_VCU_31_Timer VkNVXzMxX1RpbWVy
// 定时器触发事件 "On_VCU_31_Timer" for Timer VCU_31_Timer
void on_timer_On_VCU_31_Timer(void) { try { // 定时器 = VCU_31_Timer
TVCU_31_1 VCU_31_1;

app.get_system_var_uint32("VCU_LvBat_ERR_MIL", &VCU_LvBat_ERR_MIL_signal);
app.get_system_var_uint32("VCU_MILLamp", &VCU_MILLamp_signal);
app.get_system_var_uint32("VCU_VehFauLamp", &VCU_VehFauLamp_signal);
app.get_system_var_uint32("VCU_VehRunSta", &VCU_VehRunSta_signal);
app.get_system_var_uint32("VCU_TurtleLamp", &VCU_TurtleLamp_signal);
app.get_system_var_uint32("VCU_VehModDisply", &VCU_VehModDisply_signal);
app.get_system_var_uint32("VCU_HVILFauSta", &VCU_HVILFauSta_signal);

VCU_31_1.init();

VCU_31_1.set_VCU_LvBat_ERR_MIL(VCU_LvBat_ERR_MIL_signal);
VCU_31_1.set_VCU_MILLamp(VCU_MILLamp_signal);
VCU_31_1.set_VCU_VehFauLamp(VCU_VehFauLamp_signal);
VCU_31_1.set_VCU_VehRunSta(VCU_VehRunSta_signal);
VCU_31_1.set_VCU_TurtleLamp(VCU_TurtleLamp_signal);
VCU_31_1.set_VCU_VehModDisply(VCU_VehModDisply_signal);
VCU_31_1.set_VCU_HVILFauSta(VCU_HVILFauSta_signal);

com.transmit_can_async(&VCU_31_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_VCU_31_Timer

// CODE BLOCK BEGIN On_Timer On_GSM_1_Timer R1NNXzFfVGltZXI_
// 定时器触发事件 "On_GSM_1_Timer" for Timer GSM_1_Timer
void on_timer_On_GSM_1_Timer(void) { try { // 定时器 = GSM_1_Timer
TGSM_1_1 GSM_1_1;

app.get_system_var_uint32("GSM_GearShiftAuthRelease", &GSM_GearShiftAuthRelease_signal);

GSM_1_1.init();

GSM_1_1.set_GSM_GearShiftAuthRelease(GSM_GearShiftAuthRelease_signal);

com.transmit_can_async(&GSM_1_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GSM_1_Timer

// CODE BLOCK BEGIN On_Timer On_TCU_13_Timer VENVXzEzX1RpbWVy
// 定时器触发事件 "On_TCU_13_Timer" for Timer TCU_13_Timer
void on_timer_On_TCU_13_Timer(void) { try { // 定时器 = TCU_13_Timer
TTCU_13_1 TCU_13_1;

app.get_system_var_uint32("TCU_TrsmFailLampReq", &TCU_TrsmFailLampReq_signal);
app.get_system_var_uint32("TCU_OilTempOverHi", &TCU_OilTempOverHi_signal);
 
TCU_13_1.init();

TCU_13_1.set_TCU_TrsmFailLampReq(TCU_TrsmFailLampReq_signal);
TCU_13_1.set_TCU_OilTempOverHi(TCU_OilTempOverHi_signal);

com.transmit_can_async(&TCU_13_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_TCU_13_Timer

// CODE BLOCK BEGIN On_Timer On_BMS_23_Timer Qk1TXzIzX1RpbWVy
// 定时器触发事件 "On_BMS_23_Timer" for Timer BMS_23_Timer
void on_timer_On_BMS_23_Timer(void) { try { // 定时器 = BMS_23_Timer
TBMS_23_1 BMS_23_1;

app.get_system_var_uint32("BMS_6C0_BATT_FAULT_IND", &BMS_6C0_BATT_FAULT_IND_signal);
app.get_system_var_uint32("BMS_6C0_OBC_REMIND_LAMP", &BMS_6C0_OBC_REMIND_LAMP_signal);
app.get_system_var_uint32("BMS_6C0_VEH_INSULATION_FAULT_IND", &BMS_6C0_VEH_INSULATION_FAULT_IND_signal);
app.get_system_var_uint32("BMS_6C0_BATT_TEMP_LAMP", &BMS_6C0_BATT_TEMP_LAMP_signal);

BMS_23_1.init();

BMS_23_1.set_BMS_6C0_BATT_FAULT_IND(BMS_6C0_BATT_FAULT_IND_signal);
BMS_23_1.set_BMS_6C0_OBC_REMIND_LAMP(BMS_6C0_OBC_REMIND_LAMP_signal);
BMS_23_1.set_BMS_6C0_VEH_INSULATION_FAULT_IND(BMS_6C0_VEH_INSULATION_FAULT_IND_signal);
BMS_23_1.set_BMS_6C0_BATT_TEMP_LAMP(BMS_6C0_BATT_TEMP_LAMP_signal);

com.transmit_can_async(&BMS_23_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_BMS_23_Timer

// CODE BLOCK BEGIN On_Timer On_GW_PC_31_Timer R1dfUENfMzFfVGltZXI_
// 定时器触发事件 "On_GW_PC_31_Timer" for Timer GW_PC_31_Timer
void on_timer_On_GW_PC_31_Timer(void) { try { // 定时器 = GW_PC_31_Timer
TGW_PC_31_1 GW_PC_31_1;

app.get_system_var_uint32("GCU_12_StaFaultOut", &GCU_12_StaFaultOut_signal);
app.get_system_var_uint32("GCU_12_Timeout_Flag", &GCU_12_Timeout_Flag_signal);
app.get_system_var_uint32("MCU_11_StaFaultOut", &MCU_11_StaFaultOut_signal);
app.get_system_var_uint32("MCU_11_Timeout_Flag", &MCU_11_Timeout_Flag_signal);
app.get_system_var_uint32("MCU_11_Motor_TempFault", &MCU_11_Motor_TempFault_signal);
app.get_system_var_uint32("MCU_11_Motor_ContrlTempFault", &MCU_11_Motor_ContrlTempFault_signal);

GW_PC_31_1.init();

GW_PC_31_1.set_GCU_12_StaFaultOut(GCU_12_StaFaultOut_signal);
GW_PC_31_1.set_GCU_12_Timeout_Flag(GCU_12_Timeout_Flag_signal);
GW_PC_31_1.set_MCU_11_StaFaultOut(MCU_11_StaFaultOut_signal);
GW_PC_31_1.set_MCU_11_Timeout_Flag(MCU_11_Timeout_Flag_signal);
GW_PC_31_1.set_MCU_11_Motor_TempFault(MCU_11_Motor_TempFault_signal);
GW_PC_31_1.set_MCU_11_Motor_ContrlTempFault(MCU_11_Motor_ContrlTempFault_signal);

com.transmit_can_async(&GW_PC_31_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_31_Timer

// CODE BLOCK BEGIN On_Timer On_BMS_46_Timer Qk1TXzQ2X1RpbWVy
// 定时器触发事件 "On_BMS_46_Timer" for Timer BMS_46_Timer
void on_timer_On_BMS_46_Timer(void) { try { // 定时器 = BMS_46_Timer
TBMS_46_1 BMS_46_1;

app.get_system_var_uint32("BMS_ChrgConctSta", &BMS_ChrgConctSta_signal);
app.get_system_var_uint32("BMS_ChrgSta", &BMS_ChrgSta_signal);

BMS_46_1.init();

BMS_46_1.set_BMS_ChrgConctSta(BMS_ChrgConctSta_signal);
BMS_46_1.set_BMS_ChrgSta(BMS_ChrgSta_signal);

com.transmit_can_async(&BMS_46_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_BMS_46_Timer

// CODE BLOCK BEGIN On_Timer On_ESP_5_Timer RVNQXzVfVGltZXI_
// 定时器触发事件 "On_ESP_5_Timer" for Timer ESP_5_Timer
void on_timer_On_ESP_5_Timer(void) { try { // 定时器 = ESP_5_Timer
TESP_5_1 ESP_5_1;

app.get_system_var_uint32("ESP_CCO_Active", &ESP_CCO_Active_signal);
app.get_system_var_uint32("ESP_CCO_Faied", &ESP_CCO_Faied_signal);

ESP_5_1.init();

ESP_5_1.set_ESP_CCO_Active(ESP_CCO_Active_signal);
ESP_5_1.set_ESP_CCO_Faied(ESP_CCO_Faied_signal);

com.transmit_can_async(&ESP_5_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_ESP_5_Timer

// CODE BLOCK BEGIN On_Timer On_GW_PC_7_Timer R1dfUENfN19UaW1lcg__
// 定时器触发事件 "On_GW_PC_7_Timer" for Timer GW_PC_7_Timer
void on_timer_On_GW_PC_7_Timer(void) { try { // 定时器 = GW_PC_7_Timer
TGW_PC_7_1 GW_PC_7_1;

app.get_system_var_uint32("EDL_1_RearDiffLockGreenLamp", &EDL_1_RearDiffLockGreenLamp_signal);
app.get_system_var_uint32("EDL_1_RearDiffLockYellowLamp", &EDL_1_RearDiffLockYellowLamp_signal);
app.get_system_var_uint32("EDL_1_FrontDiffLockGreenLamp", &EDL_1_FrontDiffLockGreenLamp_signal);
app.get_system_var_uint32("EDL_1_FrontDiffLockYellowLamp", &EDL_1_FrontDiffLockYellowLamp_signal);
app.get_system_var_uint32("EDL_1_Timeout_Flag", &EDL_1_Timeout_Flag_signal);
app.get_system_var_uint32("AWD_1_Lamp4WDAuto", &AWD_1_Lamp4WDAuto_signal);
app.get_system_var_uint32("AWD_1_Timeout_Flag", &AWD_1_Timeout_Flag_signal);

GW_PC_7_1.init();

GW_PC_7_1.set_EDL_1_RearDiffLockGreenLamp(EDL_1_RearDiffLockGreenLamp_signal);
GW_PC_7_1.set_EDL_1_RearDiffLockYellowLamp(EDL_1_RearDiffLockYellowLamp_signal);
GW_PC_7_1.set_EDL_1_FrontDiffLockGreenLamp(EDL_1_FrontDiffLockGreenLamp_signal);
GW_PC_7_1.set_EDL_1_FrontDiffLockYellowLamp(EDL_1_FrontDiffLockYellowLamp_signal);
GW_PC_7_1.set_EDL_1_Timeout_Flag(EDL_1_Timeout_Flag_signal);
GW_PC_7_1.set_AWD_1_Lamp4WDAuto(AWD_1_Lamp4WDAuto_signal);
GW_PC_7_1.set_AWD_1_Timeout_Flag(AWD_1_Timeout_Flag_signal);

com.transmit_can_async(&GW_PC_7_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_7_Timer

// CODE BLOCK BEGIN On_Timer On_GW_PC_4_Timer R1dfUENfNF9UaW1lcg__
// 定时器触发事件 "On_GW_PC_4_Timer" for Timer GW_PC_4_Timer
void on_timer_On_GW_PC_4_Timer(void) { try { // 定时器 = GW_PC_4_Timer
TGW_PC_4_1 GW_PC_4_1;

app.get_system_var_uint32("EHPS_1_FaultStatus", &EHPS_1_FaultStatus_signal);
app.get_system_var_uint32("EHPS_1_Timeout_Flag", &EHPS_1_Timeout_Flag_signal);

GW_PC_4_1.init();

GW_PC_4_1.set_EHPS_1_FaultStatus(EHPS_1_FaultStatus_signal);
GW_PC_4_1.set_EHPS_1_Timeout_Flag(EHPS_1_Timeout_Flag_signal);

com.transmit_can_async(&GW_PC_4_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_GW_PC_4_Timer

// CODE BLOCK BEGIN On_Timer On_BMS_3_Timer Qk1TXzNfVGltZXI_
// 定时器触发事件 "On_BMS_3_Timer" for Timer BMS_3_Timer
void on_timer_On_BMS_3_Timer(void) { try { // 定时器 = BMS_3_Timer
TBMS_3_1 BMS_3_1;

app.get_system_var_uint32("B2V_FaultInfo_32960_ThermalRunaw", &B2V_FaultInfo_32960_ThermalRunaw_signal);

BMS_3_1.init();

BMS_3_1.set_B2V_FaultInfo_32960_ThermalRunaw(B2V_FaultInfo_32960_ThermalRunaw_signal);

com.transmit_can_async(&BMS_3_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_BMS_3_Timer

// CODE BLOCK BEGIN On_Timer On_AVAS_Timer QVZBU19UaW1lcg__
// 定时器触发事件 "On_AVAS_Timer" for Timer AVAS_Timer
void on_timer_On_AVAS_Timer(void) { try { // 定时器 = AVAS_Timer
TAVAS_1_1 AVAS_1_1;

app.get_system_var_uint32("AVAS_SwtSts", &AVAS_SwtSts_signal);

AVAS_1_1.init();

AVAS_1_1.set_AVAS_SwtSts(AVAS_SwtSts_signal);

com.transmit_can_async(&AVAS_1_1.FCAN);

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END On_Timer On_AVAS_Timer

// CODE BLOCK BEGIN Step_Function  NQ__
// 主step函数，执行周期 5 ms
void step(void) { try { // 周期 = 5 ms

} catch (...) { log_nok("CRASH detected"); app.terminate_application(); }}
// CODE BLOCK END Step_Function 

