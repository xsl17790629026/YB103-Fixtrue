#include <App_CAN_YB103_CanDbcSignal.h>
#include "FreeRTOS.h"
#include "task.h"
#include "dbc_can_core.h"
#include "can.h"
#include "lcd12864.h"
#include "Service_CanComm_il.h"
#include "lcd.h"

extern const CanTransmitConfig_t *ilTxTable;
extern uint8_t iBytesOfTxHandles;
extern CanMsgTxStateBuffer_Struct * CanMsgTxStateBufferPtr;
static uint8_t Svc_CanCommUpInf_TxConfigTableInit(CanTransmitConfig_t *p_TxTable)
{
   if(p_TxTable != NULL)
   {
      ilTxTable = p_TxTable;
      return TRUE;
   }
   else
   {
      return FALSE;
   }
}

static uint8_t Svc_CanCommUpInf_TxConfigTableLenInit(uint8_t TxTableLen)
{
   if(TxTableLen != 0)
   {
      iBytesOfTxHandles = TxTableLen;
      return TRUE;
   }
   else
   {
      return FALSE;
   }
}

static uint8_t Service_CanComm_CanMsgTxStateBufferInit(CanMsgTxStateBuffer_Struct * p_StateBuffer)
{
   if(p_StateBuffer != NULL)
   {
      CanMsgTxStateBufferPtr = p_StateBuffer;
      return TRUE;
   }
   else
   {
      return FALSE;
   }
}

void Can_SendSts_Control(uint8_t CanSendSts)
{
    if(E_CANSEND_OPEN == CanSendSts)
    {
        // Set_CanEventType_Cycle();
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
    }
    else
    {
        // Set_CanCycleType_Event();
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_RESET);
        delay_us(100);
        HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
    }
}

void App_Init(void)
{
    Svc_CanCommUpInf_TxConfigTableInit(CanTransmitConfig_Table);
    Svc_CanCommUpInf_TxConfigTableLenInit(CanTxMsgIndex_Max);
    Service_CanComm_CanMsgTxStateBufferInit(&CanMsgTxStateBuffer[0]);
}

void CanGetMsgSignal(void)
{
	if(now_page == 0){
		//ACU_1
		CanTx_SigSet_0x350_ACU_CrashOutputSts(GetACU_1Value(ACU_CrashOutputSts));

		//ESP_2
	    CanTx_SigSet_0x211_ESP_LongitAccel(GetESP_2Value(ESP_LongitAccel));
	    CanTx_SigSet_0x211_ESP_LateralAccel(GetESP_2Value(ESP_LateralAccel));
	    CanTx_SigSet_0x211_ESP_YawRate(GetESP_2Value(ESP_YawRate));
	    CanTx_SigSet_0x211_ESP_YawRateSensorValid(GetESP_2Value(ESP_YawRateSensorValid));
	    CanTx_SigSet_0x211_ESP_LateralSensorValid(GetESP_2Value(ESP_LateralSensorValid));
	    CanTx_SigSet_0x211_ESP_LongitSensorValid(GetESP_2Value(ESP_LongitSensorValid));

	    //ABS_1
	    CanTx_SigSet_0x200_ABS_FLWheelSpeed(GetABS_1Value(ABS_FLWheelSpeed));
	    CanTx_SigSet_0x200_ABS_FLWheelSpeedValid(GetABS_1Value(ABS_FLWheelSpeedValid));
	    CanTx_SigSet_0x200_ABS_FRWheelSpeed(GetABS_1Value(ABS_FRWheelSpeed));
	    CanTx_SigSet_0x200_ABS_FRWheelSpeedValid(GetABS_1Value(ABS_FRWheelSpeedValid));

	    //ABS_2
	    CanTx_SigSet_0x201_ABS_RLWheelSpeed(GetABS_2Value(ABS_RLWheelSpeed));
	    CanTx_SigSet_0x201_ABS_RLWheelSpeedValid(GetABS_2Value(ABS_RLWheelSpeedValid));
	    CanTx_SigSet_0x201_ABS_RRWheelSpeed(GetABS_2Value(ABS_RRWheelSpeed));
	    CanTx_SigSet_0x201_ABS_RRWheelSpeedValid(GetABS_2Value(ABS_RRWheelSpeedValid));

		//TPMS_1
		CanTx_SigSet_0x365_TPMS_TireID(GetTPMS_1Value(TPMS_TireID));
		CanTx_SigSet_0x365_TPMS_TirePressure(GetTPMS_1Value(TPMS_TirePressure));
		CanTx_SigSet_0x365_TPMS_TirePressureStatus(GetTPMS_1Value(TPMS_TirePressureStatus));
		CanTx_SigSet_0x365_TPMS_SensorLost(GetTPMS_1Value(TPMS_SensorLost));
		CanTx_SigSet_0x365_TPMS_LearningStatus(GetTPMS_1Value(TPMS_LearningStatus));
		CanTx_SigSet_0x365_TPMS_TireTemperatureSts(GetTPMS_1Value(TPMS_TireTemperatureSts));
		CanTx_SigSet_0x365_TPMS_TireTemperature(GetTPMS_1Value(TPMS_TireTemperature));

		//BCM_1
		CanTx_SigSet_0x360_BCM_1_ReverseLightSts(GetBCM_1Value(BCM_ReverseLightSts));
		CanTx_SigSet_0x360_BCM_1_BrakeLightSts(GetBCM_1Value(BCM_BrakeLightSts));
		CanTx_SigSet_0x360_BCM_1_BackMirrorFolderSts(GetBCM_1Value(BCM_BackMirrorFolderSts));

		//BCM_3
		CanTx_SigSet_0x311_BCM_ConsoleBtn1TriggerSts(GetBCM_3Value(BCM_ConsoleBtn1TriggerSts));

		//BCM_4
	    CanTx_SigSet_0x362_BCM_AssistIlluminationSetSts(GetBCM_4Value(BCM_AssistIlluminationSetSts));
	    CanTx_SigSet_0x362_BCM_WindowRemoteAutoDownSetSts(GetBCM_4Value(BCM_WindowRemoteAutoDownSetSts));
	    CanTx_SigSet_0x362_BCM_LeaveHomeTimeSetSts(GetBCM_4Value(BCM_LeaveHomeTimeSetSts));
	    CanTx_SigSet_0x362_BCM_FollowMeHomeTimeSetSts(GetBCM_4Value(BCM_FollowMeHomeTimeSetSts));
	    CanTx_SigSet_0x362_BCM_exRearMirrorAutoFoldSetSts(GetBCM_4Value(BCM_exRearMirrorAutoFoldSetSts));
	    CanTx_SigSet_0x362_BCM_SpeedLockSetSts(GetBCM_4Value(BCM_SpeedLockSetSts));
	    CanTx_SigSet_0x362_BCM_InteriorLightTimeSetSts(GetBCM_4Value(BCM_InteriorLightTimeSetSts));
	    CanTx_SigSet_0x362_BCM_AutoWshWipSetSts(GetBCM_4Value(BCM_AutoWshWipSetSts));
	    CanTx_SigSet_0x362_BCM_SearchCarWarnModSetSts(GetBCM_4Value(BCM_SearchCarWarnModSetSts));
	    CanTx_SigSet_0x362_BCM_WindowAutoUPbyLockSetSts(GetBCM_4Value(BCM_WindowAutoUPbyLockSetSts));
	    CanTx_SigSet_0x362_BCM_HornAlertVolumeSetSts(GetBCM_4Value(BCM_HornAlertVolumeSetSts));
	    CanTx_SigSet_0x362_BCM_AmbientLightLvl(GetBCM_4Value(BCM_AmbientLightLvl));
	    CanTx_SigSet_0x362_BCM_AmbientLightSwtSts(GetBCM_4Value(BCM_AmbientLightSwtSts));
	    CanTx_SigSet_0x362_BCM_ClsWinSpdSetSts(GetBCM_4Value(BCM_ClsWinSpdSetSts));
	    CanTx_SigSet_0x362_BCM_FlaoutUnlockSetSts(GetBCM_4Value(BCM_FlaoutUnlockSetSts));
	    CanTx_SigSet_0x362_BCM_SteeringwheelheatingSts(GetBCM_4Value(BCM_SteeringwheelheatingSts));
	    CanTx_SigSet_0x362_BCM_NozzleheatingSts(GetBCM_4Value(BCM_NozzleheatingSts));
	    CanTx_SigSet_0x362_BCM_FrontwindshieldheatingSts(GetBCM_4Value(BCM_FrontwindshieldheatingSts));
	    CanTx_SigSet_0x362_BCM_AAL_ONOFFSts(GetBCM_4Value(BCM_AAL_ONOFFSts));
	    CanTx_SigSet_0x362_BCM_AAL_PitchAngle(GetBCM_4Value(BCM_AAL_PitchAngle));
	    CanTx_SigSet_0x362_BCM_AAL_YawAngle(GetBCM_4Value(BCM_AAL_YawAngle));

	    //BCM5
	    CanTx_SigSet_0x312_BCM_SRF_PosStatus(GetBCM_5Value(BCM_SRF_PosStatus));

	    //PEPS_3
	    CanTx_SigSet_0x269_PEPS_3_RemoteControlSt(GetPEPS_3Value(PEPS_RemoteControlSt));
	    CanTx_SigSet_0x269_PEPS_3_RollingCounter(GetPEPS_3Value(PEPS_3_RollingCounter));
	    CanTx_SigSet_0x269_PEPS_3_Checksum(GetPEPS_3Value(PEPS_3_Checksum));

		//TBOX_1
		CanTx_SigSet_0x598_TBOX_DateTimeSecond(GetTBOX_1Value(TBOX_DateTimeSecond));
		CanTx_SigSet_0x598_TBOX_DateTimeMinute(GetTBOX_1Value(TBOX_DateTimeMinute));
		CanTx_SigSet_0x598_TBOX_DateTimeHour(GetTBOX_1Value(TBOX_DateTimeHour));
		CanTx_SigSet_0x598_TBOX_DateTimeDay(GetTBOX_1Value(TBOX_DateTimeDay));
		CanTx_SigSet_0x598_TBOX_DateTimeMonth(GetTBOX_1Value(TBOX_DateTimeMonth));
		CanTx_SigSet_0x598_TBOX_DateTimeYear(GetTBOX_1Value(TBOX_DateTimeYear));

		//TBOX_2
		CanTx_SigSet_0x599_TBOX_CommSignalVail(GetTBOX_2Value(TBOX_CommSignalVail));
		CanTx_SigSet_0x599_TBOX_EcallStatus(GetTBOX_2Value(TBOX_EcallStatus));

		//TBOX_4
		CanTx_SigSet_0x317_TBOX_AudioMuteRequest(GetTBOX_4Value(TBOX_AudioMuteRequest));

	    //FCM_3
		CanTx_SigSet_0x302_FCM_AEBONOFFSts(GetFCM_3Value(FCM_AEBONOFFSts));
		CanTx_SigSet_0x302_FCM_AEBMode(GetFCM_3Value(FCM_AEBMode));
		CanTx_SigSet_0x302_FCM_FCWONOFFSts(GetFCM_3Value(FCM_FCWONOFFSts));
		CanTx_SigSet_0x302_FCM_FCWMode(GetFCM_3Value(FCM_FCWMode));
		CanTx_SigSet_0x302_FCM_FCWSnvtySts(GetFCM_3Value(FCM_FCWSnvtySts));
		CanTx_SigSet_0x302_FCM_FCWpreWarning(GetFCM_3Value(FCM_FCWpreWarning));
		CanTx_SigSet_0x302_FCM_DistanceWarning(GetFCM_3Value(FCM_DistanceWarning));
		CanTx_SigSet_0x302_FCM_ACCMode(GetFCM_3Value(FCM_ACCMode));
		CanTx_SigSet_0x302_FCM_DVMode(GetFCM_3Value(FCM_DVMode));
		CanTx_SigSet_0x302_FCM_CameraTextInfo(GetFCM_3Value(FCM_CameraTextInfo));

		//FCM_4
		CanTx_SigSet_0x303_FCM_LDWONOFFSts(GetFCM_4Value(FCM_LDWONOFFSts));
		CanTx_SigSet_0x303_FCM_LDWSysSts(GetFCM_4Value(FCM_LDWSysSts));
		CanTx_SigSet_0x303_FCM_LDWWarnModSts(GetFCM_4Value(FCM_LDWWarnModSts));
		CanTx_SigSet_0x303_FCM_TSRONOFFSts(GetFCM_4Value(FCM_TSRONOFFSts));
		CanTx_SigSet_0x303_FCM_TSRState(GetFCM_4Value(FCM_TSRState));
		CanTx_SigSet_0x303_FCM_TSROverSpeedAcousticONOFFSts(GetFCM_4Value(FCM_TSROverSpeedAcousticONOFFSts));
		CanTx_SigSet_0x303_FCM_IHBCONOFFSts(GetFCM_4Value(FCM_IHBCONOFFSts));
		CanTx_SigSet_0x303_FCM_IHBCStatus(GetFCM_4Value(FCM_IHBCStatus));

		//FCM_5
		CanTx_SigSet_0x304_FCM_EgoLeLineID(GetFCM_5Value(FCM_EgoLeLineID));
		CanTx_SigSet_0x304_FCM_EgoLeLineColor(GetFCM_5Value(FCM_EgoLeLineColor));
		CanTx_SigSet_0x304_FCM_EgoLeLineTyp(GetFCM_5Value(FCM_EgoLeLineTyp));
		CanTx_SigSet_0x304_FCM_EgoLeLineHozlDst(GetFCM_5Value(FCM_EgoLeLineHozlDst));
		CanTx_SigSet_0x304_FCM_EgoLeLineCrvt(GetFCM_5Value(FCM_EgoLeLineCrvt));
		CanTx_SigSet_0x304_FCM_EgoRiLineID(GetFCM_5Value(FCM_EgoRiLineID));
		CanTx_SigSet_0x304_FCM_EgoRiLineColor(GetFCM_5Value(FCM_EgoRiLineColor));
		CanTx_SigSet_0x304_FCM_EgoRiLineTyp(GetFCM_5Value(FCM_EgoRiLineTyp));
		CanTx_SigSet_0x304_FCM_EgoRiLineHozlDst(GetFCM_5Value(FCM_EgoRiLineHozlDst));
		CanTx_SigSet_0x304_FCM_EgoRiLineCrvt(GetFCM_5Value(FCM_EgoRiLineCrvt));

		//FCM_6
		CanTx_SigSet_0x305_FCM_NeborLeLineID(GetFCM_6Value(FCM_NeborLeLineID));
		CanTx_SigSet_0x305_FCM_NeborLeLineColor(GetFCM_6Value(FCM_NeborLeLineColor));
		CanTx_SigSet_0x305_FCM_NeborLeLineTyp(GetFCM_6Value(FCM_NeborLeLineTyp));
		CanTx_SigSet_0x305_FCM_NeborLeLineHozlDst(GetFCM_6Value(FCM_NeborLeLineHozlDst));
		CanTx_SigSet_0x305_FCM_NeborLeLineCrvt(GetFCM_6Value(FCM_NeborLeLineCrvt));
		CanTx_SigSet_0x305_FCM_NeborRiLineID(GetFCM_6Value(FCM_NeborRiLineID));
		CanTx_SigSet_0x305_FCM_NeborRiLineColor(GetFCM_6Value(FCM_NeborRiLineColor));
		CanTx_SigSet_0x305_FCM_NeborRiLineTyp(GetFCM_6Value(FCM_NeborRiLineTyp));
		CanTx_SigSet_0x305_FCM_NeborRiLineHozlDst(GetFCM_6Value(FCM_NeborRiLineHozlDst));
		CanTx_SigSet_0x305_FCM_NeborRiLineCrvt(GetFCM_6Value(FCM_NeborRiLineCrvt));

		//FCM_7
	    CanTx_SigSet_0x306_FCM_ACCObjID(GetFCM_7Value(FCM_ACCObjID));
	    CanTx_SigSet_0x306_FCM_ACCObjTyp(GetFCM_7Value(FCM_ACCObjTyp));
	    CanTx_SigSet_0x306_FCM_ACC_TargetVehicleSubType(GetFCM_7Value(FCM_ACC_TargetVehicleSubType));
	    CanTx_SigSet_0x306_FCM_dxTarObjcolor(GetFCM_7Value(FCM_dxTarObjcolor));
	    CanTx_SigSet_0x306_FCM_ACCObjLgtDstX(GetFCM_7Value(FCM_ACCObjLgtDstX));
	    CanTx_SigSet_0x306_FCM_ACCObjHozDstY(GetFCM_7Value(FCM_ACCObjHozDstY));
	    CanTx_SigSet_0x306_FCM_FrntFarObjID(GetFCM_7Value(FCM_FrntFarObjID));
	    CanTx_SigSet_0x306_FCM_FrntFarObjTyp(GetFCM_7Value(FCM_FrntFarObjTyp));
	    CanTx_SigSet_0x306_FCM_FrntFarObjLgtDstX(GetFCM_7Value(FCM_FrntFarObjLgtDstX));
	    CanTx_SigSet_0x306_FCM_FrntFarObjHozDstY(GetFCM_7Value(FCM_FrntFarObjHozDstY));

	    //FCM_8
	    CanTx_SigSet_0x307_FCM_RiObjID(GetFCM_8Value(FCM_RiObjID));
	    CanTx_SigSet_0x307_FCM_LeObjID(GetFCM_8Value(FCM_LeObjID));
	    CanTx_SigSet_0x307_FCM_LeObjTyp(GetFCM_8Value(FCM_LeObjTyp));
	    CanTx_SigSet_0x307_FCM_ACC_LeftTargetVehicleSubType(GetFCM_8Value(FCM_ACC_LeftTargetVehicleSubType));
	    CanTx_SigSet_0x307_FCM_LeObjLgtDstX(GetFCM_8Value(FCM_LeObjLgtDstX));
	    CanTx_SigSet_0x307_FCM_LeObjHozDstY(GetFCM_8Value(FCM_LeObjHozDstY));
	    CanTx_SigSet_0x307_FCM_RiObjTyp(GetFCM_8Value(FCM_RiObjTyp));
	    CanTx_SigSet_0x307_FCM_ACC_RightTargetVehicleSubTyp(GetFCM_8Value(FCM_ACC_RightTargetVehicleSubTyp));
	    CanTx_SigSet_0x307_FCM_RiObjLgtDstX(GetFCM_8Value(FCM_RiObjLgtDstX));
	    CanTx_SigSet_0x307_FCM_RiObjHozDstY(GetFCM_8Value(FCM_RiObjHozDstY));

		//GW_PC_1
		CanTx_SigSet_0x150_TCU_1_GearShiftPosition(GetGW_PC_1Value(TCU_1_GearShiftPosition));
		CanTx_SigSet_0x150_EMS_3_SS_SetSts(GetGW_PC_1Value(EMS_3_SS_SetSts));
		CanTx_SigSet_0x150_TCU_3_Drivemode(GetGW_PC_1Value(TCU_3_Drivemode));
	    CanTx_SigSet_0x150_TCU_1_GearShiftPositionValid(GetGW_PC_1Value(TCU_1_GearShiftPositionValid));
	    CanTx_SigSet_0x150_EMS_2_EngineSpeedValid(GetGW_PC_1Value(EMS_2_EngineSpeedValid));
	    CanTx_SigSet_0x150_EMS_2_EngineSpeed(GetGW_PC_1Value(EMS_2_EngineSpeed));
	    CanTx_SigSet_0x150_TCU_3_Timeout_Flag(GetGW_PC_1Value(TCU_3_Timeout_Flag));
	    CanTx_SigSet_0x150_TCU_1_Timeout_Flag(GetGW_PC_1Value(TCU_1_Timeout_Flag));
	    CanTx_SigSet_0x150_EMS_3_EngineStatus(GetGW_PC_1Value(EMS_3_EngineStatus));
	    CanTx_SigSet_0x150_EMS_3_Timeout_Flag(GetGW_PC_1Value(EMS_3_Timeout_Flag));

		//GW_PC_6
		CanTx_SigSet_0x155_TCU_3_Timeout_Flag1(GetGW_PC_6Value(TCU_3_Timeout_Flag1));
		CanTx_SigSet_0x155_TCU_3_DrivemodeOprationNotice(GetGW_PC_6Value(TCU_3_DrivemodeOprationNotice));

		//GW_PC_2
		CanTx_SigSet_0x250_SAS_1_SteeringAngle(GetGW_PC_2Value(SAS_1_SteeringAngle));
		CanTx_SigSet_0x250_ABS_3_VehicleSpeed(GetGW_PC_2Value(ABS_3_VehicleSpeed));
		CanTx_SigSet_0x250_SAS_1_SteeringAngleValid(GetGW_PC_2Value(SAS_1_SteeringAngleValid));
		CanTx_SigSet_0x250_ABS_3_AbsActive(GetGW_PC_2Value(ABS_3_AbsActive));
		CanTx_SigSet_0x250_ESP_1_ESPActive(GetGW_PC_2Value(ESP_1_ESPActive));
		CanTx_SigSet_0x250_ABS_3_VehicleSpeedValid(GetGW_PC_2Value(ABS_3_VehicleSpeedValid));
		CanTx_SigSet_0x250_SAS_1_Timeout_Flag(GetGW_PC_2Value(SAS_1_Timeout_Flag));
		CanTx_SigSet_0x250_ABS_3_Timeout_Flag(GetGW_PC_2Value(ABS_3_Timeout_Flag));
		CanTx_SigSet_0x250_ESP_1_Timeout_Flag(GetGW_PC_2Value(ESP_1_Timeout_Flag));

		//GW_PC_7
		CanTx_SigSet_0x255_AWD_1_Lamp4WDLock(GetGW_PC_7Value(AWD_1_Lamp4WDLock));
		CanTx_SigSet_0x255_AWD_1_Lamp4WDLow(GetGW_PC_7Value(AWD_1_Lamp4WDLow));
		CanTx_SigSet_0x255_AWD_1_Lamp2WD(GetGW_PC_7Value(AWD_1_Lamp2WD));
		CanTx_SigSet_0x255_EDL_1_FrontDiffLockYellowLamp(GetGW_PC_7Value(EDL_1_FrontDiffLockYellowLamp));
		CanTx_SigSet_0x255_EDL_1_FrontDiffLockGreenLamp(GetGW_PC_7Value(EDL_1_FrontDiffLockGreenLamp));
		CanTx_SigSet_0x255_EDL_1_RearDiffLockYellowLamp(GetGW_PC_7Value(EDL_1_RearDiffLockYellowLamp));
		CanTx_SigSet_0x255_EDL_1_RearDiffLockGreenLamp(GetGW_PC_7Value(EDL_1_RearDiffLockGreenLamp));
		CanTx_SigSet_0x255_EDL_1_Timeout_Flag(GetGW_PC_7Value(EDL_1_Timeout_Flag));
		CanTx_SigSet_0x255_AWD_1_Timeout_Flag(GetGW_PC_7Value(AWD_1_Timeout_Flag));

		//GW_PC_4
		CanTx_SigSet_0x3A0_Swaybar_1_FrontSwaybarYellowLamp(GetGW_PC_4Value(Swaybar_1_FrontSwaybarYellowLamp));
		CanTx_SigSet_0x3A0_Swaybar_1_FrontSwaybarGreenLamp(GetGW_PC_4Value(Swaybar_1_FrontSwaybarGreenLamp));
		CanTx_SigSet_0x3A0_Swaybar_1_Timeout_Flag(GetGW_PC_4Value(Swaybar_1_Timeout_Flag));

		//GW_BD_9
		CanTx_SigSet_0x3A7_BCM_1_FrontLeftDoorSts(GetGW_BD_9Value(BCM_1_FrontLeftDoorSts));
		CanTx_SigSet_0x3A7_BCM_1_FrontRightDoorSts(GetGW_BD_9Value(BCM_1_FrontRightDoorSts));
		CanTx_SigSet_0x3A7_BCM_1_RearLeftDoorSts(GetGW_BD_9Value(BCM_1_RearLeftDoorSts));
		CanTx_SigSet_0x3A7_BCM_1_RearRightDoorSts(GetGW_BD_9Value(BCM_1_RearRightDoorSts));
		CanTx_SigSet_0x3A7_BCM_1_TailGateOpenSts(GetGW_BD_9Value(BCM_1_TailGateOpenSts));
		CanTx_SigSet_0x3A7_BCM_1_HoodSts(GetGW_BD_9Value(BCM_1_HoodSts));
		CanTx_SigSet_0x3A7_TCM_1_LeftTurnLightSWSts(GetGW_BD_9Value(TCM_1_LeftTurnLightSWSts));
		CanTx_SigSet_0x3A7_TCM_1_RightTurnLightSWSts(GetGW_BD_9Value(TCM_1_RightTurnLightSWSts));
		CanTx_SigSet_0x3A7_BCM_1_PositionLightSts(GetGW_BD_9Value(BCM_1_PositionLightSts));
		CanTx_SigSet_0x3A7_BCM_1_ACRearFrostSts(GetGW_BD_9Value(BCM_1_ACRearFrostSts));
		CanTx_SigSet_0x3A7_BCM_1_LeftTurnLightSts(GetGW_BD_9Value(BCM_1_LeftTurnLightSts));
		CanTx_SigSet_0x3A7_BCM_1_HighBeamSts(GetGW_BD_9Value(BCM_1_HighBeamSts));
		CanTx_SigSet_0x3A7_BCM_1_LowBeamSts(GetGW_BD_9Value(BCM_1_LowBeamSts));
		CanTx_SigSet_0x3A7_BCM_1_PowerMode(GetGW_BD_9Value(BCM_1_PowerMode));
		CanTx_SigSet_0x3A7_BCM_1_RearFogLightSts(GetGW_BD_9Value(BCM_1_RearFogLightSts));
		CanTx_SigSet_0x3A7_BCM_1_EmergencyLightSts(GetGW_BD_9Value(BCM_1_EmergencyLightSts));
		CanTx_SigSet_0x3A7_BCM_1_RightTurnLightSts(GetGW_BD_9Value(BCM_1_RightTurnLightSts));
		CanTx_SigSet_0x3A7_BCM_1_DaytimeRunningLightSts(GetGW_BD_9Value(BCM_1_DaytimeRunningLightSts));
		CanTx_SigSet_0x3A7_BCM_1_FrontFogLightSts(GetGW_BD_9Value(BCM_1_FrontFogLightSts));
		CanTx_SigSet_0x3A7_BCM_1_ReverseGearInfo(GetGW_BD_9Value(BCM_1_ReverseGearInfo));
		CanTx_SigSet_0x3A7_BCM_1_BackMirrorFolderSts(GetGW_BD_9Value(BCM_1_BackMirrorFolderSts));
		CanTx_SigSet_0x3A7_TCM_1_LeftTurnLightSWStsValid(GetGW_BD_9Value(TCM_1_LeftTurnLightSWStsValid));
		CanTx_SigSet_0x3A7_TCM_1_RightTurnLightSWStsValid(GetGW_BD_9Value(TCM_1_RightTurnLightSWStsValid));
		CanTx_SigSet_0x3A7_TCM_1_Timeout_Flag(GetGW_BD_9Value(TCM_1_Timeout_Flag));
	    CanTx_SigSet_0x3A7_BCM_1_Timeout_Flag(GetGW_BD_9Value(BCM_1_Timeout_Flag));

		//GW_BD_14
		CanTx_SigSet_0x3AC_AC_1_ButtonTriggerStatus(GetGW_BD_14Value(AC_1_ButtonTriggerStatus));
		CanTx_SigSet_0x3AC_AC_1_ACSystemSts(GetGW_BD_14Value(AC_1_ACSystemSts));
		CanTx_SigSet_0x3AC_AC_2_DriverSetTemperature(GetGW_BD_14Value(AC_2_DriverSetTemperature));
		CanTx_SigSet_0x3AC_AC_2_PngSetTemperature(GetGW_BD_14Value(AC_2_PngSetTemperature));
		CanTx_SigSet_0x3AC_AC_1_BlowerSpeedLevel(GetGW_BD_14Value(AC_1_BlowerSpeedLevel));
		CanTx_SigSet_0x3AC_AC_1_AirDistributeMode(GetGW_BD_14Value(AC_1_AirDistributeMode));
		CanTx_SigSet_0x3AC_AC_1_AirCirculationMode(GetGW_BD_14Value(AC_1_AirCirculationMode));
		CanTx_SigSet_0x3AC_AC_1_ACButtonSts(GetGW_BD_14Value(AC_1_ACButtonSts));
		CanTx_SigSet_0x3AC_AC_1_FrontDefrostButtonSts(GetGW_BD_14Value(AC_1_FrontDefrostButtonSts));
		CanTx_SigSet_0x3AC_AC_2_DualButtonSts(GetGW_BD_14Value(AC_2_DualButtonSts));
		CanTx_SigSet_0x3AC_AC_2_AUTOButtonSts(GetGW_BD_14Value(AC_2_AUTOButtonSts));
		CanTx_SigSet_0x3AC_AC_2_OutsideTemperature(GetGW_BD_14Value(AC_2_OutsideTemperature));
		CanTx_SigSet_0x3AC_AC_1_ACSelfCleanModeSts(GetGW_BD_14Value(AC_1_ACSelfCleanModeSts));
		CanTx_SigSet_0x3AC_AC_1_TemperatureLevel(GetGW_BD_14Value(AC_1_TemperatureLevel));
		CanTx_SigSet_0x3AC_AC_1_RearDefrostButtonSts(GetGW_BD_14Value(AC_1_RearDefrostButtonSts));
		CanTx_SigSet_0x3AC_AC_1_PTCButtonSts(GetGW_BD_14Value(AC_1_PTCButtonSts));
		CanTx_SigSet_0x3AC_AC_1_BlowerSpeedLevelRear(GetGW_BD_14Value(AC_1_BlowerSpeedLevelRear));
		CanTx_SigSet_0x3AC_AC_1_RearModeSts(GetGW_BD_14Value(AC_1_RearModeSts));
		CanTx_SigSet_0x3AC_AC_2_OutsideTemperatureValid(GetGW_BD_14Value(AC_2_OutsideTemperatureValid));
		CanTx_SigSet_0x3AC_AC_2_DualMode(GetGW_BD_14Value(AC_2_DualMode));
		CanTx_SigSet_0x3AC_AC_2_AUTOPassengerButtonSts(GetGW_BD_14Value(AC_2_AUTOPassengerButtonSts));
		CanTx_SigSet_0x3AC_AC_2_Timeout_Flag(GetGW_BD_14Value(AC_2_Timeout_Flag));
		CanTx_SigSet_0x3AC_AC_1_Timeout_Flag(GetGW_BD_14Value(AC_1_Timeout_Flag));

		//GW_BD_24
		CanTx_SigSet_0x3C7_BCM_2_WindowRunningStatusRR(GetGW_BD_24Value(BCM_2_WindowRunningStatusRR));
		CanTx_SigSet_0x3C7_BCM_2_WindowRunningStatusRL(GetGW_BD_24Value(BCM_2_WindowRunningStatusRL));
		CanTx_SigSet_0x3C7_BCM_2_WindowRunningStatusFR(GetGW_BD_24Value(BCM_2_WindowRunningStatusFR));
		CanTx_SigSet_0x3C7_BCM_2_WindowRunningStatusFL(GetGW_BD_24Value(BCM_2_WindowRunningStatusFL));
		CanTx_SigSet_0x3C7_BCM_2_WindowPosFL(GetGW_BD_24Value(BCM_2_WindowPosFL));
		CanTx_SigSet_0x3C7_BCM_2_WindowPosFR(GetGW_BD_24Value(BCM_2_WindowPosFR));
		CanTx_SigSet_0x3C7_BCM_2_WindowPosRL(GetGW_BD_24Value(BCM_2_WindowPosRL));
		CanTx_SigSet_0x3C7_BCM_2_WindowPosRR(GetGW_BD_24Value(BCM_2_WindowPosRR));
		CanTx_SigSet_0x3C7_BCM_2_Timeout_Flag(GetGW_BD_24Value(BCM_2_Timeout_Flag));

		//GW_BD_29
		CanTx_SigSet_0x3CC_SCU_1_FLSeatHeatLvlSts(GetGW_BD_29Value(SCU_1_FLSeatHeatLvlSts));
		CanTx_SigSet_0x3CC_SCU_1_FRSeatHeatLvlSts(GetGW_BD_29Value(SCU_1_FRSeatHeatLvlSts));
		CanTx_SigSet_0x3CC_SCU_1_FLSeatMassgLvlSts(GetGW_BD_29Value(SCU_1_FLSeatMassgLvlSts));
		CanTx_SigSet_0x3CC_SCU_1_FLSeatMassgModSts(GetGW_BD_29Value(SCU_1_FLSeatMassgModSts));
		CanTx_SigSet_0x3CC_WCM_1_WirelessChargeSwtSts(GetGW_BD_29Value(WCM_1_WirelessChargeSwtSts));
		CanTx_SigSet_0x3CC_WCM_1_ChargingSts(GetGW_BD_29Value(WCM_1_ChargingSts));
		CanTx_SigSet_0x3CC_WCM_1_FailureSts(GetGW_BD_29Value(WCM_1_FailureSts));
		CanTx_SigSet_0x3CC_EPM_1_EPMModSts(GetGW_BD_29Value(EPM_1_EPMModSts));
		CanTx_SigSet_0x3CC_SCU_1_FaultsStatus(GetGW_BD_29Value(SCU_1_FaultsStatus));
		CanTx_SigSet_0x3CC_SCU_1_FLSeatVentLvlSts(GetGW_BD_29Value(SCU_1_FLSeatVentLvlSts));
		CanTx_SigSet_0x3CC_WCM_1_PhoneReminder(GetGW_BD_29Value(WCM_1_PhoneReminder));
		CanTx_SigSet_0x3CC_SCU_1_FRSeatVentLvlSts(GetGW_BD_29Value(SCU_1_FRSeatVentLvlSts));
		CanTx_SigSet_0x3CC_EPM_1_Timeout_Flag(GetGW_BD_29Value(EPM_1_Timeout_Flag));
		CanTx_SigSet_0x3CC_WCM_1_Timeout_Flag(GetGW_BD_29Value(WCM_1_Timeout_Flag));
		CanTx_SigSet_0x3CC_SCU_1_Timeout_Flag(GetGW_BD_29Value(SCU_1_Timeout_Flag));

	}
	else{
		//F1
		CanTx_SigSet_0x250_ABS_3_VehicleSpeed(GetF1Value(F1_ABS_3_VehicleSpeed));
		CanTx_SigSet_0x250_ABS_3_VehicleSpeedValid(GetF1Value(F1_ABS_3_VehicleSpeedValid));
		CanTx_SigSet_0x250_ABS_3_Timeout_Flag(GetF1Value(F1_ABS_3_Timeout_Flag));
		//F2
		CanTx_SigSet_0x150_EMS_2_EngineSpeed(GetF2Value(F2_EMS_2_EngineSpeed));
		CanTx_SigSet_0x150_EMS_2_EngineSpeedValid(GetF2Value(F2_EMS_2_EngineSpeedValid));
		CanTx_SigSet_0x150_EMS_2_Timeout_Flag(GetF2Value(EMS_2_Timeout_Flag));
		//F3
		//F4
		CanTx_SigSet_0x155_EMS_4_EngineCoolantTemp(GetF4Value(EMS_4_EngineCoolantTemp));
		CanTx_SigSet_0x155_EMS_4_EngineCoolantTempValid(GetF4Value(EMS_4_EngineCoolantTempValid));
		CanTx_SigSet_0x155_EMS_4_Timeout_Flag(GetF4Value(EMS_4_Timeout_Flag));
		//F5
		//F6
		CanTx_SigSet_0x155_EMS_4_FuelConsumption(GetF6Value(EMS_4_FuelConsumption));
		//F7
		//F8
		CanTx_SigSet_0x365_TPMS_SystemStatus(GetF8Value(TPMS_SystemStatus));
		CanTx_SigSet_0x365_TPMS_TireID(GetF8Value(F8_TPMS_TireID));
	    CanTx_SigSet_0x365_TPMS_SensorLost(GetF8Value(F8_TPMS_SensorLost));
	    CanTx_SigSet_0x365_TPMS_TireLeakage(GetF8Value(F8_TPMS_TireLeakage));
		CanTx_SigSet_0x365_TPMS_LearningStatus(GetF8Value(F8_TPMS_LearningStatus));
		CanTx_SigSet_0x365_TPMS_TirePressureStatus(GetF8Value(F8_TPMS_TirePressureStatus));
		CanTx_SigSet_0x365_TPMS_TirePressure(GetF8Value(F8_TPMS_TirePressure));
		//F9
		CanTx_SigSet_0x3A7_BCM_1_FrontLeftDoorSts(GetF9Value(F9_BCM_1_FrontLeftDoorSts));
		CanTx_SigSet_0x3A7_BCM_1_FrontRightDoorSts(GetF9Value(F9_BCM_1_FrontRightDoorSts));
	    CanTx_SigSet_0x3A7_BCM_1_RearLeftDoorSts(GetF9Value(F9_BCM_1_RearLeftDoorSts));
		CanTx_SigSet_0x3A7_BCM_1_RearRightDoorSts(GetF9Value(F9_BCM_1_RearRightDoorSts));
		CanTx_SigSet_0x3A7_BCM_1_TailGateOpenSts(GetF9Value(F9_BCM_1_TailGateOpenSts));
	    CanTx_SigSet_0x3A7_BCM_1_HoodSts(GetF9Value(F9_BCM_1_HoodSts));
	    CanTx_SigSet_0x3A7_BCM_1_Timeout_Flag(GetF9Value(F9_BCM_1_Timeout_Flag));
	    //F10
	    CanTx_SigSet_0x155_TCU_3_TargetGearValid(GetF10Value(TCU_3_TargetGearValid));
		CanTx_SigSet_0x155_TCU_3_TargetGear(GetF10Value(TCU_3_TargetGear));
		CanTx_SigSet_0x150_TCU_1_GearShiftPositionValid(GetF10Value(F10_TCU_1_GearShiftPositionValid));
		CanTx_SigSet_0x150_TCU_1_GearShiftPosition(GetF10Value(F10_TCU_1_GearShiftPosition));
		CanTx_SigSet_0x155_TCU_3_Timeout_Flag1(GetF10Value(F10_TCU_3_Timeout_Flag1));
		CanTx_SigSet_0x150_TCU_1_Timeout_Flag(GetF10Value(F10_TCU_1_Timeout_Flag));
		//F11
		CanTx_SigSet_0x255_EDL_1_RearDiffLockGreenLamp(GetF11Value(F11_EDL_1_RearDiffLockGreenLamp));
		CanTx_SigSet_0x255_EDL_1_RearDiffLockYellowLamp(GetF11Value(F11_EDL_1_RearDiffLockYellowLamp));
		CanTx_SigSet_0x255_EDL_1_FrontDiffLockGreenLamp(GetF11Value(F11_EDL_1_FrontDiffLockGreenLamp));
		CanTx_SigSet_0x255_EDL_1_FrontDiffLockYellowLamp(GetF11Value(F11_EDL_1_FrontDiffLockYellowLamp));
		CanTx_SigSet_0x255_EDL_1_Timeout_Flag(GetF11Value(F11_EDL_1_Timeout_Flag));
		//F12
		CanTx_SigSet_0x3AC_AC_2_OutsideTemperatureValid(GetF12Value(F12_AC_2_OutsideTemperatureValid));
		CanTx_SigSet_0x3AC_AC_2_OutsideTemperature(GetF12Value(F12_AC_2_OutsideTemperature));
		CanTx_SigSet_0x3AC_AC_2_Timeout_Flag(GetF12Value(F12_AC_2_Timeout_Flag));
		//F13
	    CanTx_SigSet_0x304_FCM_EgoLeLineID(GetF13Value(F13_FCM_EgoLeLineID));
	    CanTx_SigSet_0x304_FCM_EgoLeLineColor(GetF13Value(F13_FCM_EgoLeLineColor));
	    CanTx_SigSet_0x304_FCM_EgoLeLineTyp(GetF13Value(F13_FCM_EgoLeLineTyp));
	    CanTx_SigSet_0x304_FCM_EgoLeLineHozlDst(GetF13Value(F13_FCM_EgoLeLineHozlDst));
	    CanTx_SigSet_0x304_FCM_EgoLeLineCrvt(GetF13Value(F13_FCM_EgoLeLineCrvt));
	    CanTx_SigSet_0x304_FCM_EgoRiLineID(GetF13Value(F13_FCM_EgoRiLineID));
	    CanTx_SigSet_0x304_FCM_EgoRiLineColor(GetF13Value(F13_FCM_EgoRiLineColor));
	    CanTx_SigSet_0x304_FCM_EgoRiLineTyp(GetF13Value(F13_FCM_EgoRiLineTyp));
	    CanTx_SigSet_0x304_FCM_EgoRiLineHozlDst(GetF13Value(F13_FCM_EgoRiLineHozlDst));
	    CanTx_SigSet_0x304_FCM_EgoRiLineCrvt(GetF13Value(F13_FCM_EgoRiLineCrvt));
	    CanTx_SigSet_0x304_FCM_5_RollingCounter(GetF13Value(FCM_5_RollingCounter));
	    CanTx_SigSet_0x304_FCM_5_Checksum(GetF13Value(FCM_5_Checksum));

	    CanTx_SigSet_0x305_FCM_NeborLeLineID(GetF13Value(F13_FCM_NeborLeLineID));
	    CanTx_SigSet_0x305_FCM_NeborLeLineColor(GetF13Value(F13_FCM_NeborLeLineColor));
	    CanTx_SigSet_0x305_FCM_NeborLeLineTyp(GetF13Value(F13_FCM_NeborLeLineTyp));
	    CanTx_SigSet_0x305_FCM_NeborLeLineHozlDst(GetF13Value(F13_FCM_NeborLeLineHozlDst));
	    CanTx_SigSet_0x305_FCM_NeborLeLineCrvt(GetF13Value(F13_FCM_NeborLeLineCrvt));
	    CanTx_SigSet_0x305_FCM_NeborRiLineID(GetF13Value(F13_FCM_NeborRiLineID));
	    CanTx_SigSet_0x305_FCM_NeborRiLineColor(GetF13Value(F13_FCM_NeborRiLineColor));
	    CanTx_SigSet_0x305_FCM_NeborRiLineTyp(GetF13Value(F13_FCM_NeborRiLineTyp));
	    CanTx_SigSet_0x305_FCM_NeborRiLineHozlDst(GetF13Value(F13_FCM_NeborRiLineHozlDst));
	    CanTx_SigSet_0x305_FCM_NeborRiLineCrvt(GetF13Value(F13_FCM_NeborRiLineCrvt));
	    CanTx_SigSet_0x305_FCM_6_RollingCounter(GetF13Value(FCM_6_RollingCounter));
	    CanTx_SigSet_0x305_FCM_6_Checksum(GetF13Value(FCM_6_Checksum));

	    CanTx_SigSet_0x306_FCM_ACCObjID(GetF13Value(F13_FCM_ACCObjID));
	    CanTx_SigSet_0x306_FCM_ACCObjTyp(GetF13Value(F13_FCM_ACCObjTyp));
	    CanTx_SigSet_0x306_FCM_ACC_TargetVehicleSubType(GetF13Value(F13_FCM_ACC_TargetVehicleSubType));
	    CanTx_SigSet_0x306_FCM_dxTarObjcolor(GetF13Value(F13_FCM_dxTarObjcolor));
	    CanTx_SigSet_0x306_FCM_ACCObjLgtDstX(GetF13Value(F13_FCM_ACCObjLgtDstX));
	    CanTx_SigSet_0x306_FCM_ACCObjHozDstY(GetF13Value(F13_FCM_ACCObjHozDstY));
	    CanTx_SigSet_0x306_FCM_FrntFarObjID(GetF13Value(F13_FCM_FrntFarObjID));
	    CanTx_SigSet_0x306_FCM_FrntFarObjTyp(GetF13Value(F13_FCM_FrntFarObjTyp));
	    CanTx_SigSet_0x306_FCM_FrntFarObjLgtDstX(GetF13Value(F13_FCM_FrntFarObjLgtDstX));
	    CanTx_SigSet_0x306_FCM_FrntFarObjHozDstY(GetF13Value(F13_FCM_FrntFarObjHozDstY));
	    CanTx_SigSet_0x306_FCM_7_RollingCounter(GetF13Value(FCM_7_RollingCounter));
	    CanTx_SigSet_0x306_FCM_7_Checksum(GetF13Value(FCM_7_Checksum));

	    CanTx_SigSet_0x307_FCM_RiObjID(GetF13Value(F13_FCM_RiObjID));
	    CanTx_SigSet_0x307_FCM_LeObjID(GetF13Value(F13_FCM_LeObjID));
	    CanTx_SigSet_0x307_FCM_LeObjTyp(GetF13Value(F13_FCM_LeObjTyp));
	    CanTx_SigSet_0x307_FCM_ACC_LeftTargetVehicleSubType(GetF13Value(F13_FCM_ACC_LeftTargetVehicleSubType));
	    CanTx_SigSet_0x307_FCM_LeObjLgtDstX(GetF13Value(F13_FCM_LeObjLgtDstX));
	    CanTx_SigSet_0x307_FCM_LeObjHozDstY(GetF13Value(F13_FCM_LeObjHozDstY));
	    CanTx_SigSet_0x307_FCM_RiObjTyp(GetF13Value(F13_FCM_RiObjTyp));
	    CanTx_SigSet_0x307_FCM_ACC_RightTargetVehicleSubTyp(GetF13Value(F13_FCM_ACC_RightTargetVehicleSubTyp));
	    CanTx_SigSet_0x307_FCM_RiObjLgtDstX(GetF13Value(F13_FCM_RiObjLgtDstX));
	    CanTx_SigSet_0x307_FCM_RiObjHozDstY(GetF13Value(F13_FCM_RiObjHozDstY));
	    CanTx_SigSet_0x307_FCM_8_RollingCounter(GetF13Value(FCM_8_RollingCounter));
	    CanTx_SigSet_0x307_FCM_8_Checksum(GetF13Value(FCM_8_Checksum));



	    //F14



	}
}

void CanTransmitFunction(void const *pvParameters)
{
	(void)pvParameters;
    printf("CanTransmitFunction\r\n");
	for(;;)
	{
      CanGetMsgSignal();
      CanCcl_TickCntHnadler();
		// CanDbc_TxHandler();
		vTaskDelay(pdMS_TO_TICKS(5));
	}
}
