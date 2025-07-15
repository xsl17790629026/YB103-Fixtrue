#ifndef _LCD12864_ENUM_H_
#define _LCD12864_ENUM_H_

#include "main.h"

typedef enum
{
	ACU_1,
	ESP_2,
	ABS_1,
	ABS_2,
	TPMS_1,
	BCM_1,
	BCM_3,
	BCM_4,
	BCM_5,
	PEPS_3,
	TBOX_1,
	TBOX_2,
	TBOX_4,
	FCM_3,
	FCM_4,
	FCM_5,
	FCM_6,
	FCM_7,
	FCM_8,
	GW_PC_1,
	GW_PC_6,
	GW_PC_2,
	GW_PC_7,
	GW_PC_4,
	GW_BD_9,
	GW_BD_14,
	GW_BD_24,
	GW_BD_29,
    Page0_MENU_MAX
} Pagedis_Page0;

typedef enum
{
    F1,
    F2,
    F3,
    F4,
    F5,
    F6,
    F7,
    F8,
    F9,
    F10,
    F11,
    F12,
    F13,
    F14,
    F15,
    F16,
    F17,
    F18,
    F19,
    F20,
    F21,
    F22,
    F23,
    F24,
    F25,
    F26,
    F27,
    F28,
    F29,
    F30,
    Page1_MENU_MAX
} Pagedis_Page1;

typedef enum
{
	ACU_CrashOutputSts,
	ACU_1_ITEM_MAX,
} ACU_1_ITEM;

typedef enum
{
    ESP_LongitAccel,
    ESP_LateralAccel,
    ESP_YawRate,
    ESP_YawRateSensorValid,
    ESP_LateralSensorValid,
    ESP_LongitSensorValid,
    ESP_2_ITEM_MAX,
} ESP_2_ITEM;

typedef enum
{
    ABS_FLWheelSpeed,
    ABS_FLWheelSpeedValid,
    ABS_FRWheelSpeed,
    ABS_FRWheelSpeedValid,
    ABS_1_ITEM_MAX,
} ABS_1_ITEM;

typedef enum
{
    ABS_RLWheelSpeed,
    ABS_RLWheelSpeedValid,
    ABS_RRWheelSpeed,
    ABS_RRWheelSpeedValid,
    ABS_2_ITEM_MAX,
} ABS_2_ITEM;

typedef enum
{
    BCM_ReverseLightSts,
    BCM_BrakeLightSts,
    BCM_BackMirrorFolderSts,
    BCM_1_ITEM_MAX,
} BCM_1_ITEM;

typedef enum
{
	BCM_ConsoleBtn1TriggerSts,
	BCM_3_ITEM_MAX,
} BCM_3_ITEM;

typedef enum
{
	BCM_SpeedLockSetSts,
	BCM_FlaoutUnlockSetSts,
	BCM_exRearMirrorAutoFoldSetSts,
	BCM_WindowAutoUPbyLockSetSts,
	BCM_ClsWinSpdSetSts,
	BCM_SearchCarWarnModSetSts,
	BCM_FollowMeHomeTimeSetSts,
	BCM_LeaveHomeTimeSetSts,
	BCM_InteriorLightTimeSetSts,
	BCM_AmbientLightSwtSts,
	BCM_AmbientLightLvl,
	BCM_AutoWshWipSetSts,
    BCM_AssistIlluminationSetSts,
    BCM_WindowRemoteAutoDownSetSts,
    BCM_HornAlertVolumeSetSts,
    BCM_SteeringwheelheatingSts,
    BCM_NozzleheatingSts,
    BCM_FrontwindshieldheatingSts,
    BCM_AAL_ONOFFSts,
    BCM_AAL_PitchAngle,
    BCM_AAL_YawAngle,
	BCM_4_ITEM_MAX,
} BCM_4_ITEM;

typedef enum
{
    BCM_SRF_PosStatus,
	BCM_5_ITEM_MAX,
} BCM_5_ITEM;

typedef enum
{
    TBOX_CommSignalVail,
    TBOX_EcallStatus,
	TBOX_2_ITEM_MAX,
} TBOX_2_ITEM;

typedef enum
{
	FCM_AEBONOFFSts,
	FCM_AEBMode,
	FCM_FCWONOFFSts,
	FCM_FCWMode,
	FCM_FCWSnvtySts,
    FCM_FCWpreWarning,
    FCM_DistanceWarning,
    FCM_ACCMode,
    FCM_DVMode,
    FCM_CameraTextInfo,
	FCM_3_ITEM_MAX,
} FCM_3_ITEM;

typedef enum
{
	FCM_LDWONOFFSts,
	FCM_LDWSysSts,
	FCM_LDWWarnModSts,
	FCM_TSRONOFFSts,
	FCM_TSRState,
	FCM_TSROverSpeedAcousticONOFFSts,
	FCM_IHBCONOFFSts,
	FCM_IHBCStatus,
    FCM_LDWLKATypefeedback,
	FCM_LDWLDPSnvtySts,
	FCM_4_ITEM_MAX,
} FCM_4_ITEM;

typedef enum
{
    FCM_EgoLeLineID,
    FCM_EgoLeLineColor,
    FCM_EgoLeLineTyp,
    FCM_EgoLeLineHozlDst,
    FCM_EgoLeLineCrvt,
    FCM_EgoRiLineID,
    FCM_EgoRiLineColor,
    FCM_EgoRiLineTyp,
    FCM_EgoRiLineHozlDst,
    FCM_EgoRiLineCrvt,
	FCM_5_ITEM_MAX,
} FCM_5_ITEM;

typedef enum
{
    FCM_NeborLeLineID,
    FCM_NeborLeLineColor,
    FCM_NeborLeLineTyp,
    FCM_NeborLeLineHozlDst,
    FCM_NeborLeLineCrvt,
    FCM_NeborRiLineID,
    FCM_NeborRiLineColor,
    FCM_NeborRiLineTyp,
    FCM_NeborRiLineHozlDst,
    FCM_NeborRiLineCrvt,
	FCM_6_ITEM_MAX,
} FCM_6_ITEM;

typedef enum
{
    FCM_ACCObjID,
    FCM_ACCObjTyp,
    FCM_ACC_TargetVehicleSubType,
    FCM_dxTarObjcolor,
    FCM_ACCObjLgtDstX,
    FCM_ACCObjHozDstY,
    FCM_FrntFarObjID,
    FCM_FrntFarObjTyp,
    FCM_FrntFarObjLgtDstX,
    FCM_FrntFarObjHozDstY,
	FCM_7_ITEM_MAX,
} FCM_7_ITEM;

typedef enum
{
    FCM_RiObjID,
    FCM_LeObjID,
    FCM_LeObjTyp,
    FCM_ACC_LeftTargetVehicleSubType,
    FCM_LeObjLgtDstX,
    FCM_LeObjHozDstY,
    FCM_RiObjTyp,
    FCM_ACC_RightTargetVehicleSubTyp,
    FCM_RiObjLgtDstX,
    FCM_RiObjHozDstY,
	FCM_8_ITEM_MAX,
} FCM_8_ITEM;

typedef enum
{
	AC_1_ButtonTriggerStatus,
	AC_1_ACSystemSts,
	AC_2_DriverSetTemperature,
	AC_2_PngSetTemperature,
	AC_1_BlowerSpeedLevel,
	AC_1_AirDistributeMode,
	AC_1_AirCirculationMode,
	AC_1_ACButtonSts,
	AC_1_FrontDefrostButtonSts,
	AC_2_DualButtonSts,
	AC_2_AUTOButtonSts,
	AC_2_OutsideTemperature,
	AC_1_ACSelfCleanModeSts,
    AC_1_TemperatureLevel,
    AC_1_RearDefrostButtonSts,
    AC_1_PTCButtonSts,
    AC_1_BlowerSpeedLevelRear,
    AC_1_RearModeSts,
    AC_2_OutsideTemperatureValid,
    AC_2_DualMode,
    AC_2_AUTOPassengerButtonSts,
    AC_1_Timeout_Flag,
    AC_2_Timeout_Flag,
	GW_BD_14_ITEM_MAX,
} GW_BD_14_ITEM;

typedef enum
{
	SCU_1_FLSeatHeatLvlSts,
	SCU_1_FRSeatHeatLvlSts,
	SCU_1_FLSeatMassgLvlSts,
	SCU_1_FLSeatMassgModSts,
	WCM_1_WirelessChargeSwtSts,
	WCM_1_ChargingSts,
	WCM_1_FailureSts,
	EPM_1_EPMModSts,
    SCU_1_FaultsStatus,
    SCU_1_FLSeatVentLvlSts,
    WCM_1_PhoneReminder,
    SCU_1_FRSeatVentLvlSts,
    EPM_1_Timeout_Flag,
    WCM_1_Timeout_Flag,
    SCU_1_Timeout_Flag,
	GW_BD_29_ITEM_MAX,
} GW_BD_29_ITEM;

typedef enum
{
    BCM_2_WindowRunningStatusRR,
    BCM_2_WindowRunningStatusRL,
    BCM_2_WindowRunningStatusFR,
    BCM_2_WindowRunningStatusFL,
    BCM_2_WindowPosFL,
    BCM_2_WindowPosFR,
    BCM_2_WindowPosRL,
    BCM_2_WindowPosRR,
    BCM_2_Timeout_Flag,
	GW_BD_24_ITEM_MAX,
} GW_BD_24_ITEM;

typedef enum
{
	BCM_1_FrontLeftDoorSts,
	BCM_1_FrontRightDoorSts,
	BCM_1_RearLeftDoorSts,
	BCM_1_RearRightDoorSts,
	BCM_1_TailGateOpenSts,
	BCM_1_HoodSts,
	TCM_1_LeftTurnLightSWSts,
	TCM_1_RightTurnLightSWSts,
	BCM_1_PositionLightSts,
	BCM_1_ACRearFrostSts,
	BCM_1_PowerMode,
	BCM_1_LowBeamSts,
	BCM_1_HighBeamSts,
	BCM_1_LeftTurnLightSts,
	BCM_1_RightTurnLightSts,
	BCM_1_EmergencyLightSts,
	BCM_1_RearFogLightSts,
	BCM_1_FrontFogLightSts,
	BCM_1_DaytimeRunningLightSts,
	BCM_1_ReverseGearInfo,
	BCM_1_BackMirrorFolderSts,
	TCM_1_LeftTurnLightSWStsValid,
	TCM_1_RightTurnLightSWStsValid,
	BCM_1_Timeout_Flag,
	TCM_1_Timeout_Flag,
	GW_BD_9_ITEM_MAX,
} GW_BD_9_ITEM;

typedef enum
{
	TCU_1_GearShiftPosition,
	EMS_3_SS_SetSts,
	TCU_3_Drivemode,
	EMS_2_EngineSpeed,
	EMS_2_EngineSpeedValid,
	TCU_1_GearShiftPositionValid,
	EMS_3_EngineStatus,
	EMS_3_Timeout_Flag,
	TCU_1_Timeout_Flag,
	TCU_3_Timeout_Flag,
	GW_PC_1_ITEM_MAX,
} GW_PC_1_ITEM;

typedef enum
{
    TCU_3_DrivemodeOprationNotice,
    TCU_3_Timeout_Flag1,
	GW_PC_6_ITEM_MAX,
} GW_PC_6_ITEM;

typedef enum
{
	ABS_3_VehicleSpeed,
	SAS_1_SteeringAngle,
	ESP_1_ESPActive,
	ABS_3_AbsActive,
	ABS_3_VehicleSpeedValid,
	SAS_1_SteeringAngleValid,
	ESP_1_Timeout_Flag,
	ABS_3_Timeout_Flag,
	SAS_1_Timeout_Flag,
	GW_PC_2_ITEM_MAX,
} GW_PC_2_ITEM;

typedef enum
{
    AWD_1_Lamp4WDLock,
	AWD_1_Lamp4WDLow,
	AWD_1_Lamp2WD,
	EDL_1_FrontDiffLockGreenLamp,
	EDL_1_FrontDiffLockYellowLamp,
	EDL_1_RearDiffLockGreenLamp,
	EDL_1_RearDiffLockYellowLamp,
	AWD_1_Timeout_Flag,
	EDL_1_Timeout_Flag,
	GW_PC_7_ITEM_MAX,
} GW_PC_7_ITEM;

typedef enum
{
    Swaybar_1_FrontSwaybarYellowLamp,
    Swaybar_1_FrontSwaybarGreenLamp,
    Swaybar_1_Timeout_Flag,
	GW_PC_4_ITEM_MAX,
} GW_PC_4_ITEM;

typedef enum
{
    PEPS_RemoteControlSt,
    PEPS_3_RollingCounter,
    PEPS_3_Checksum,
	PEPS_3_ITEM_MAX,
} PEPS_3_ITEM;

typedef enum
{
	TBOX_DateTimeSecond,
	TBOX_DateTimeMinute,
	TBOX_DateTimeHour,
	TBOX_DateTimeDay,
	TBOX_DateTimeMonth,
	TBOX_DateTimeYear,
	TBOX_1_ITEM_MAX,
} TBOX_1_ITEM;

typedef enum
{
	TBOX_AudioMuteRequest,
	TBOX_4_ITEM_MAX,
} TBOX_4_ITEM;

typedef enum
{
	TPMS_TireID,
	TPMS_TirePressure,
	TPMS_TirePressureStatus,
	TPMS_SensorLost,
	TPMS_LearningStatus,
	TPMS_TireTemperatureSts,
	TPMS_TireTemperature,
	TPMS_1_ITEM_MAX,
} TPMS_1_ITEM;

typedef enum
{
	F1_ABS_3_VehicleSpeed,
	F1_ABS_3_VehicleSpeedValid,
	F1_ABS_3_Timeout_Flag,
	F1_ITEM_MAX,
} F1_ITEM;

typedef enum
{
	F2_EMS_2_EngineSpeed,
	F2_EMS_2_EngineSpeedValid,
	EMS_2_Timeout_Flag,
	F2_ITEM_MAX,
} F2_ITEM;

typedef enum
{
	F3_ABS_3_VehicleSpeed,
	F3_ABS_3_VehicleSpeedValid,
	F3_ABS_3_Timeout_Flag,
	F3_EMS_2_EngineSpeed,
	F3_EMS_2_EngineSpeedValid,
	F3_EMS_2_Timeout_Flag,
    F3_ITEM_MAX,
} F3_ITEM;

typedef enum
{
	EMS_4_EngineCoolantTemp,
	EMS_4_EngineCoolantTempValid,
	EMS_4_Timeout_Flag,
    F4_ITEM_MAX,
} F4_ITEM;

typedef enum
{
	F5_ABS_3_VehicleSpeed,
	F5_ABS_3_VehicleSpeedValid,
	F5_ABS_3_Timeout_Flag,
    F5_ITEM_MAX,
} F5_ITEM;

typedef enum
{
	F6_ABS_3_VehicleSpeed,
	F6_ABS_3_VehicleSpeedValid,
	F6_ABS_3_Timeout_Flag,
	F6_EMS_2_EngineSpeed,
	F6_EMS_2_EngineSpeedValid,
	F6_EMS_2_Timeout_Flag,
	EMS_4_FuelConsumption,
	F6_EMS_4_Timeout_Flag,
    F6_ITEM_MAX,
} F6_ITEM;

typedef enum
{
	F7_ABS_3_VehicleSpeed,
	F7_ABS_3_VehicleSpeedValid,
	F7_ABS_3_Timeout_Flag,
	F7_EMS_2_EngineSpeed,
	F7_EMS_2_EngineSpeedValid,
	F7_EMS_2_Timeout_Flag,
	F7_EMS_4_FuelConsumption,
	F7_EMS_4_Timeout_Flag,
    F7_ITEM_MAX,
} F7_ITEM;

typedef enum
{
	TPMS_SystemStatus,
	F8_TPMS_TireID,
	F8_TPMS_SensorLost,
	F8_TPMS_TireLeakage,
	F8_TPMS_LearningStatus,
	F8_TPMS_TirePressureStatus,
	F8_TPMS_TirePressure,
    F8_ITEM_MAX,
} F8_ITEM;

typedef enum
{
	F9_BCM_1_FrontLeftDoorSts,
	F9_BCM_1_FrontRightDoorSts,
	F9_BCM_1_RearLeftDoorSts,
	F9_BCM_1_RearRightDoorSts,
	F9_BCM_1_TailGateOpenSts,
	F9_BCM_1_HoodSts,
	F9_BCM_1_Timeout_Flag,
    F9_ITEM_MAX,
} F9_ITEM;

typedef enum
{
	TCU_3_TargetGear,
	TCU_3_TargetGearValid,
	F10_TCU_1_GearShiftPosition,
	F10_TCU_1_GearShiftPositionValid,
	F10_TCU_1_Timeout_Flag,
	F10_TCU_3_Timeout_Flag1,
    F10_ITEM_MAX,
} F10_ITEM;

typedef enum
{
	F11_EDL_1_RearDiffLockGreenLamp,
	F11_EDL_1_RearDiffLockYellowLamp,
	F11_EDL_1_FrontDiffLockGreenLamp,
	F11_EDL_1_FrontDiffLockYellowLamp,
	F11_EDL_1_Timeout_Flag,
    F11_ITEM_MAX,
} F11_ITEM;

typedef enum
{
	F12_AC_2_OutsideTemperatureValid,
	F12_AC_2_OutsideTemperature,
	F12_AC_2_Timeout_Flag,
    F12_ITEM_MAX,
} F12_ITEM;

typedef enum
{
    F13_FCM_EgoLeLineID,
	F13_FCM_EgoLeLineColor,
	F13_FCM_EgoLeLineTyp,
	F13_FCM_EgoLeLineHozlDst,
	F13_FCM_EgoLeLineCrvt,
	F13_FCM_EgoRiLineID,
	F13_FCM_EgoRiLineColor,
	F13_FCM_EgoRiLineTyp,
	F13_FCM_EgoRiLineHozlDst,
	F13_FCM_EgoRiLineCrvt,
    FCM_5_RollingCounter,
    FCM_5_Checksum,
	F13_FCM_NeborLeLineID,
	F13_FCM_NeborLeLineColor,
	F13_FCM_NeborLeLineTyp,
	F13_FCM_NeborLeLineHozlDst,
	F13_FCM_NeborLeLineCrvt,
	F13_FCM_NeborRiLineID,
	F13_FCM_NeborRiLineColor,
	F13_FCM_NeborRiLineTyp,
	F13_FCM_NeborRiLineHozlDst,
	F13_FCM_NeborRiLineCrvt,
    FCM_6_RollingCounter,
    FCM_6_Checksum,
	F13_FCM_ACCObjID,
	F13_FCM_ACCObjTyp,
	F13_FCM_ACC_TargetVehicleSubType,
	F13_FCM_dxTarObjcolor,
	F13_FCM_ACCObjLgtDstX,
	F13_FCM_ACCObjHozDstY,
	F13_FCM_FrntFarObjID,
	F13_FCM_FrntFarObjTyp,
	F13_FCM_FrntFarObjLgtDstX,
	F13_FCM_FrntFarObjHozDstY,
    FCM_7_RollingCounter,
    FCM_7_Checksum,
	F13_FCM_RiObjID,
	F13_FCM_LeObjID,
	F13_FCM_LeObjTyp,
	F13_FCM_ACC_LeftTargetVehicleSubType,
	F13_FCM_LeObjLgtDstX,
	F13_FCM_LeObjHozDstY,
	F13_FCM_RiObjTyp,
	F13_FCM_ACC_RightTargetVehicleSubTyp,
	F13_FCM_RiObjLgtDstX,
	F13_FCM_RiObjHozDstY,
    FCM_8_RollingCounter,
    FCM_8_Checksum,
    F13_ITEM_MAX,
} F13_ITEM;

typedef enum
{
	BCM_LeftTurnLightSts,
    F14_ITEM_MAX,
} F14_ITEM;

typedef enum
{
    F15_ITEM_MAX,
} F15_ITEM;

typedef enum
{
    F16_ITEM_MAX,
} F16_ITEM;

typedef enum
{
    F17_ITEM_MAX,
} F17_ITEM;

typedef enum
{
    F18_ITEM_MAX,
} F18_ITEM;

typedef enum
{
    F19_ITEM_MAX,
} F19_ITEM;

typedef enum
{
    F20_ITEM_MAX,
} F20_ITEM;

typedef enum
{
    F21_ITEM_MAX,
} F21_ITEM;

typedef enum
{
    F22_ITEM_MAX,
} F22_ITEM;

typedef enum
{
    F23_ITEM_MAX,
} F23_ITEM;

typedef enum
{
    F24_ITEM_MAX,
} F24_ITEM;

typedef enum
{
    F25_ITEM_MAX,
} F25_ITEM;

typedef enum
{
    F26_ITEM_MAX,
} F26_ITEM;

typedef enum
{
    F27_ITEM_MAX,
} F27_ITEM;

typedef enum
{
    F28_ITEM_MAX,
} F28_ITEM;

typedef enum
{
    F29_ITEM_MAX,
} F29_ITEM;

typedef enum
{
    F30_ITEM_MAX,
} F30_ITEM;

#endif // _LCD12864_ENUM_H_
