#include "main.h"
#include "lcd12864_def.h"

#ifndef ITEM_MAX_2
#define ITEM_MAX_2 2
#endif

#ifndef ITEM_MAX_3
#define ITEM_MAX_3 3
#endif

#ifndef ITEM_MAX_4
#define ITEM_MAX_4 4
#endif

#ifndef ITEM_MAX_5
#define ITEM_MAX_5 5
#endif

#ifndef ITEM_MAX_DEFAULT
#define ITEM_MAX_DEFAULT 16
#endif

char* Page0[Page0_MENU_MAX] = {
		"ACU1",
		"ESP2",
		"ABS1",
		"ABS2",
		"TPS1",
		"BCM1",
		"BCM3",
		"BCM4",
		"BCM5",
		"PPS3",
		"TBX1",
		"TBX2",
		"TBX4",
		"FCM3",
		"FCM4",
		"FCM5",
		"FCM6",
		"FCM7",
		"FCM8",
		"GPC1",
		"GPC6",
		"GPC2",
		"GPC7",
		"GPC4",
		"GBD9",
		"GB14",
		"GB24",
		"GB29",
};

char* Page1[Page1_MENU_MAX] = {
	"F1",
	"F2",
	"F3",
	"F4",
	"F5",
	"F6",
	"F7",
	"F8",
	"F9",
	"F10",
	"F11",
	"F12",
	"F13",
	"F14",
	"F15",
	"F16",
	"F17",
	"F18",
	"F19",
	"F20",
	"F21",
	"F22",
	"F23",
	"F24",
	"F25",
	"F26",
	"F27",
	"F28",
	"F29",
	"F30"
};

char* ACU_1Item[ACU_1_ITEM_MAX] = {
    "ACUCrshOut"
};

char* ACU_1Value[ACU_1_ITEM_MAX][16] = {
    {"NoCrsh", "BTCrsh", "FRCrsh", "RRCrsh", "DRCrsh", "PSCrsh"},
};

uint16_t ACU_1Max[ACU_1_ITEM_MAX] = {256};
uint16_t g_ACU_1[ACU_1_ITEM_MAX] = {0};

char* ESP_2Item[ESP_2_ITEM_MAX] = {
    "LongAcc",
    "LatAcc",
    "YawRate",
    "YawValid",
    "LatValid",
    "LongValid",
};

char* ESP_2Value[ESP_2_ITEM_MAX][16] = {
    {""},
    {""},
    {""},
	{"Valid","Invalid"},
	{"Valid","Invalid"},
    {"Valid","Invalid"},
};

uint16_t ESP_2Max[ESP_2_ITEM_MAX] = {
	17,
	17,
	144,
    2,
    2,
    2,
};

uint16_t g_ESP_2[ESP_2_ITEM_MAX] = {0};

char* ABS_1Item[ABS_1_ITEM_MAX] = {
    "ABS_FLSpd",
    "ABS_FLVali",
    "ABS_FRSpd",
    "ABS_FRVali",
};

char* ABS_1Value[ABS_1_ITEM_MAX][16] = {
    {""},
	{"Valid", "Invalid"},
    {""},
    {"Valid", "Invalid"},
};

uint16_t ABS_1Max[ABS_1_ITEM_MAX] = {
    46,
    2,
	46,
    2,
};

uint16_t g_ABS_1[ABS_1_ITEM_MAX] = {0};

char* ABS_2Item[ABS_2_ITEM_MAX] = {
    "ABS_RLSpd",
    "ABS_RLVali",
    "ABS_RRSpd",
    "ABS_RRVali",
};

char* ABS_2Value[ABS_2_ITEM_MAX][16] = {
	{""},
	{"Valid", "Invalid"},
	{""},
	{"Valid", "Invalid"},
};

uint16_t ABS_2Max[ABS_2_ITEM_MAX] = {
	46,
	2,
	46,
	2,
};

uint16_t g_ABS_2[ABS_2_ITEM_MAX] = {0};

char* TPMS_1Item[TPMS_1_ITEM_MAX] = {
    "TPMSTireID",
    "TPMSPrsr",
    "TPMSPrSts",
    "SnsrLStss",
    "TPMSLrnSt",
    "TTempSts",
    "TPMS_Temp"
};

char* TPMS_1Value[TPMS_1_ITEM_MAX][16] = {
    {"LFrnt", "RFrnt", "RRear", "LRear"},
    {"InValid"},
    {"Normal", "OvrPrsr", "UndPrsr", "Reserved"},
    {"NotLost", "Lost"},
    {"UnLearn", "Learning", "Learned", "LearnFail"},
    {"Normal", "HighTemp"},
	{"InValid"}
};

uint16_t TPMS_1Max[TPMS_1_ITEM_MAX] = {4, (0xFF / 15), 4, 2, 4, 2, (0xFF / 15),};
uint16_t g_TPMS_1[TPMS_1_ITEM_MAX] = {0};

char* BCM_1Item[BCM_1_ITEM_MAX] = {
    "BCM_RevSts",
    "BCM_BrkSts",
    "BkMrrFld",
};

char* BCM_1Value[BCM_1_ITEM_MAX][16] = {
    {"Off", "On", "Reserved", "Invalid"},
	{"Off", "On", "Reserved", "Invalid"},
    {"Off", "On"},
};

uint16_t BCM_1Max[BCM_1_ITEM_MAX] = {
    4,
    4,
    2,
};

uint16_t g_BCM_1[BCM_1_ITEM_MAX] = {0};

char* BCM_3Item[BCM_3_ITEM_MAX] = {
    "CB1TrgSts"
};

char* BCM_3Value[BCM_3_ITEM_MAX][16] = {
    {"NotPress", "Pressed"}
};

uint16_t BCM_3Max[BCM_3_ITEM_MAX] = {2};
uint16_t g_BCM_3[BCM_3_ITEM_MAX] = {0};

char* BCM_4Item[BCM_4_ITEM_MAX] = {
    "SpdLckSts",
    "FlaUnlkSts",
    "RrMAutoFld",
    "WndAutoUP",
    "ClsWndSpd",
    "SrchCarWrn",
    "FolHomeTm",
    "LevHomeTm",
    "IntrLghtTm",
    "AmbLghtSwch",
    "AmbLghtLvl",
    "AutoWshWpr",
    "AIsSts",
    "WRAutoDn",
    "HAlVolSts",
    "SWhHtgSts",
    "NzlHtgSts",
    "FWshHtgSts",
    "AALOSts",
    "AALPitAng",
    "AALYawAng"
};

char* BCM_4Value[BCM_4_ITEM_MAX][16] = {
    {"OFF", "15KLOCK", "40KLOCK", "RSRV", "INVL"},
    {"OFF", "ON"},
    {"OFF", "ON"},
    {"OFF", "ON"},
    {"OFF", "60KCLS", "80KCLS", "100KCLS"},
    {"LGHT", "SND", "LGHTSND", "RSRV"},
    {"OFF", "30S", "60S", "90S", "120S", "RSRV", "INVL"},
    {"OFF", "30S", "60S", "90S", "120S", "RSRV", "INVL"},
    {"OFF", "2MIN", "5MIN", "10MIN", "RSRV", "INVL"},
    {"OFF", "ON"},
    {"RSRV", "LV1", "LV2", "LV3", "LV4", "LV5", "LV6", "LV7", "LV8", "LV9", "LV10", "RSRV"},
    {"300MS", "500MS", "800MS", "INVL"},
    {"OFF", "ON"},
	{"OFF", "ON"},
    {"Off", "Low", "Normal", "High", "Reserved", "Invalid"},
    {"NotHeating", "Heating"},
    {"Off", "On"},
    {"Off", "On"},
	{"Off", "On"},
    {""},
	{""},
};

uint16_t BCM_4Max[BCM_4_ITEM_MAX] = {
    7, 2, 2, 2, 4, 4, 7, 7, 7, 2, 16, 4, 2, 2, 8, 2, 2, 2, 2, 0xB5, 0xF1,
};

uint16_t g_BCM_4[BCM_4_ITEM_MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x5A, 0x3C,};

char* BCM_5Item[BCM_5_ITEM_MAX] = {
    "SRFPosSts",
};

char* BCM_5Value[BCM_5_ITEM_MAX][16] = {
    {"FullClsd", "SlideOpn", "TiltUp", "Opening", "Closing", "Reversing", "PosNoTrust", "NotUsed"},
};

uint16_t BCM_5Max[BCM_5_ITEM_MAX] = {
    16,
};

uint16_t g_BCM_5[BCM_5_ITEM_MAX] = {0};

char* PEPS_3Item[PEPS_3_ITEM_MAX] = {
    "RmteCtlSts",
	"RollCountr",
	"Checksum"
};

char* PEPS_3Value[PEPS_3_ITEM_MAX][16] = {
    {"NotRmCtl", "RemoveCtl"},
    {""},
    {""},
};

uint16_t PEPS_3Max[PEPS_3_ITEM_MAX] = {2, 16, 256,};
uint16_t g_PEPS_3[PEPS_3_ITEM_MAX] = {0};

char* TBOX_1Item[TBOX_1_ITEM_MAX] = {
    "TBOXSec", "TBOXMin", "TBOXHour", "TBOXDay", "TBOXMonth", "TBOXYear"
};

char* TBOX_1Value[TBOX_1_ITEM_MAX][16] = {{""}, {""}, {""}, {""}, {""}, {""}};

uint16_t TBOX_1Max[TBOX_1_ITEM_MAX] = {0x3C, 0x3C, 0x18, 0x1F, 0xC, 0x64};

uint16_t g_TBOX_1[TBOX_1_ITEM_MAX] = {0};

char* TBOX_2Item[TBOX_2_ITEM_MAX] = {
    "CommSgnVa",
    "EcallSts"
};

char* TBOX_2Value[TBOX_2_ITEM_MAX][16] = {
    {""},
    {"Not Ecall", "Ecalling"},
};

uint16_t TBOX_2Max[TBOX_2_ITEM_MAX] = {
    256,
    2,
};

uint16_t g_TBOX_2[TBOX_2_ITEM_MAX] = {0};

char* TBOX_4Item[TBOX_4_ITEM_MAX] = {
    "AuMuReqst"
};

char* TBOX_4Value[TBOX_4_ITEM_MAX][16] = {
    {"NoReqst", "ReqstMu"},
};

uint16_t TBOX_4Max[TBOX_4_ITEM_MAX] = {2,};
uint16_t g_TBOX_4[TBOX_4_ITEM_MAX] = {0};

char* FCM_3Item[FCM_3_ITEM_MAX] = {
    "AEBOFSts",
    "FCMAEBMod",
    "FCMOFSts",
    "FCWMode",
    "FCWSnvtySt",
    "FCWpreWrn",
    "DistancWrn",
    "ACCMode",
    "DVMode",
    "CameraText"
};

char* FCM_3Value[FCM_3_ITEM_MAX][16] = {
    {"NotActive", "On", "Off", "Reserved"},    // 6/2/3/4字符
    {"Off", "Passive", "Standby", "Active", "Error", "FatrPattn", "Reserved"},
    {"NotActive", "On", "Off", "Reserved"},
    {"Off", "Passive", "Standby", "LWActive", "FCWActive", "AWBActive", "Error", "Reserved"},
    {"NotActive", "Standard", "Near", "Far"},
	{"Notwarning", "Warning"},
	{"Notwarning", "Warning"},
	{"Off", "Passive", "Standby", "ActiveCtrl", "Brakectrl", "Override", "Reserved", "Failure"},
	{"Off", "Active", "Error", "Reserved"},
	{"Normal", "Failure", "Blocked", "Reserved"},
};

uint16_t FCM_3Max[FCM_3_ITEM_MAX] = {4, 8, 4, 8, 4, 2, 2, 8, 4, 4};
uint16_t g_FCM_3[FCM_3_ITEM_MAX] = {1, 0, 1, 0, 1, 0, 0, 0, 0, 0};

char* FCM_4Item[FCM_4_ITEM_MAX] = {
    "LDWOFSts",
    "LDWSysSts",
    "LDWWrnModS",
    "TSROFSts",
    "FCMTSRSts",
    "TSROvrSpd",
    "IHBCOFSts",
    "TSROvrSpdA",
	"LKATypfebc",
	"LDPSntySts"
};

char* FCM_4Value[FCM_4_ITEM_MAX][16] = {
    {"NotActive", "On", "Off", "Reserved"},
    {"Off", "Passive", "Standby", "Active", "Error", "Reserved"},
    {"Off", "VOICON", "SHCKON", "VNS"},
	{"Off", "On"},
    {"Off", "Passive", "Standby", "Active", "CamBlock", "Fault", "Reserved"},
    {"Off", "On"},
    {"NotActive", "On", "Off", "Reserved"},
	{"Off", "On"},
    {"Default", "LDW", "LKA", "Off"},
    {"NotActive", "LowSensty", "HighSensty", "Reserved"}
};

uint16_t FCM_4Max[FCM_4_ITEM_MAX] = {4, 8, 4, 2, 8, 2, 4, 2, 4, 4};
uint16_t g_FCM_4[FCM_4_ITEM_MAX] = {1, 0, 3, 1, 0, 1, 0, 1, 0, 1};

char* FCM_5Item[FCM_5_ITEM_MAX] = {
    "ELLID",
    "ELLColr",
    "ELLType",
    "ELLHozlDst",
    "ELLCrvt",
    "ERLID",
    "ERLColor",
    "ERLTyp",
    "ERLHozlDst",
    "ERLCrvt"
};

char* FCM_5Value[FCM_5_ITEM_MAX][16] = {
    {"Invalid", "Valid"},
    {"NotDisplay", "Colr_unKnw", "Colr_White", "Colr_Yello"},
	{"NotDisplay", "Type_unKnw", "Type_SoLin", "Colr_DaLin"},
    {""},
    {""},
	{"Invalid", "Valid"},
    {"NotDisplay", "Colr_unKnw", "Colr_White", "Colr_Yello"},
	{"NotDisplay", "Type_unKnw", "Type_SoLin", "Colr_DaLin"},
    {""},
    {""},
};

uint16_t FCM_5Max[FCM_5_ITEM_MAX] = {
    2,
    4,
    4,
	0x1F4/10 + 1,
	0x208/20 + 1,
    2,
    4,
    4,
	0x1F4/10 + 1,
    0x208/20 + 1,
};

uint16_t g_FCM_5[FCM_5_ITEM_MAX] = {0};

char* FCM_6Item[FCM_6_ITEM_MAX] = {
	"NLLID",
	"NLLColr",
	"NLLType",
	"NLLHozlDst",
	"NLLCrvt",
	"NRLID",
	"NRLColor",
	"NRLTyp",
	"NRLHozlDst",
	"NRLCrvt"
};

char* FCM_6Value[FCM_6_ITEM_MAX][16] = {
	{"Invalid", "Valid"},
	{"NotDisplay", "Colr_unKnw", "Colr_White", "Colr_Yello"},
	{"NotDisplay", "Type_unKnw", "Type_SoLin", "Colr_DaLin"},
	{""},
	{""},
	{"Invalid", "Valid"},
	{"NotDisplay", "Colr_unKnw", "Colr_White", "Colr_Yello"},
	{"NotDisplay", "Type_unKnw", "Type_SoLin", "Colr_DaLin"},
	{""},
	{""},
};

uint16_t FCM_6Max[FCM_6_ITEM_MAX] = {
    2,
    4,
    4,
	0x1F4/10 + 1,
    0x208/20 + 1,
    2,
    4,
    4,
	0x1F4/10 + 1,
    0x208/20 + 1,
};

uint16_t g_FCM_6[FCM_6_ITEM_MAX] = {0};

char* FCM_7Item[FCM_7_ITEM_MAX] = {
    "ACCObjID",
    "ACCObjTyp",
    "ACCTVhSTyp",
    "dxTObjclrr",
    "ACCObjLDX",
    "ACCObjHDY",
    "FtFObjID",
    "FtFObjTyp",
    "FtFObjLDX",
    "FtFObjHDY"
};

char* FCM_7Value[FCM_7_ITEM_MAX][16] = {
    {"Invalid", "Valid"},
	{"Invalid", "Vehicle", "Pedestrian", "Cyclist", "GenralObj", "Reserved"},
    {"Unknown", "Bus", "SmllMedCar", "Trucks", "Motors", "SpecialVe", "TinyCar", "Lorry"},
    {"Green", "Yellow", "red", "gray", "no display", "reserved"},
    {""},
    {""},
    {"Invalid", "Valid"},
    {"No type", "Car", "Truck", "Motorcycle", "Pedestrian", "Cyclist", "Bus", "Reserved"},
    {""},
    {""},
};

uint16_t FCM_7Max[FCM_7_ITEM_MAX] = {
    2,
    8,
    8,
    8,
    254/2 + 1,
    11,
    2,
    16,
    254/2 + 1,
    11,
};

uint16_t g_FCM_7[FCM_7_ITEM_MAX] = {0};

char* FCM_8Item[FCM_8_ITEM_MAX] = {
    "FCMRObjID",
    "FCMLObjID",
    "FCMLObjTyp",
    "ACCLTVSTyp",
    "FCM_LeOLDX",
    "FCM_LeOHDY",
    "FCMRObjTyp",
    "ACCRTVSTyp",
    "FCM_RiOLDX",
    "FCM_RiOHDY"
};

char* FCM_8Value[FCM_8_ITEM_MAX][16] = {
	{"Invalid", "Valid"},
	{"Invalid", "Valid"},
	{"Invalid", "Vehicle", "Pedestrian", "Cyclist", "GenralObj", "Reserved"},
	{"Unknown", "Bus", "SmllMedCar", "Trucks", "Motors", "SpecialVe", "TinyCar", "Lorry"},
	{""},
	{""},
	{"Invalid", "Vehicle", "Pedestrian", "Cyclist", "GenralObj", "Reserved"},
	{"Unknown", "Bus", "SmllMedCar", "Trucks", "Motors", "SpecialVe", "TinyCar", "Lorry"},
	{""},
	{""},
};

uint16_t FCM_8Max[FCM_8_ITEM_MAX] = {
	2,
	2,
	8,
	8,
	254/2 + 1,
	11,
	8,
	8,
	254/2 + 1,
	11,
};

uint16_t g_FCM_8[FCM_8_ITEM_MAX] = {0};

char* GW_PC_1Item[GW_PC_1_ITEM_MAX] = {
    "GearSftPos",
    "SSSetSts",
    "DriveMode",
	"EngineSpd",
	"EngineSpdV",
	"GearSfPosV",
	"EngineSts",
	"EMS3TOFlg",
	"TCU1TOFlg",
	"TCU3TOFlg",
};

char* GW_PC_1Value[GW_PC_1_ITEM_MAX][18] = {
    {"P", "R", "N", "D", "+PS", "-PS", "M", "Reserved", "Invalid"},
    {"Off", "On"},
    {"Standard", "Economic", "Sport", "Snow", "Comfort", "Deep Snow", "Cross", "Slip Mud", "Intellegnt", "Mountain", "Uneven", "Reserved", "Sand", "Rock", "Mud", "Wade", "Reserved", "Invalid"},
    {""},
	{"Valid", "Invalid"},
	{"Valid", "Invalid"},
	{"PowerOff", "PowerOn", "Cranking", "Running"},
	{"Normal", "Timeout"},
	{"Normal", "Timeout"},
	{"Normal", "Timeout"},
};

uint16_t GW_PC_1Max[GW_PC_1_ITEM_MAX] = {
	16,
	2,
	0x3F,
	(0xFFFF/400),
	2,
	2,
	4,
	2,
	2,
	2
};
uint16_t g_GW_PC_1[GW_PC_1_ITEM_MAX] = {0};

char* GW_PC_6Item[GW_PC_6_ITEM_MAX] = {
    "DrimodONot",
    "TCU3TOF1"
};

char* GW_PC_6Value[GW_PC_6_ITEM_MAX][16] = {
    {"NoRequest", "To 4H/4L", "To 2H/4H", "To 4L", "Reserved"},
    {"Normal", "Timeout"},
};

uint16_t GW_PC_6Max[GW_PC_6_ITEM_MAX] = {
    16,
    2,
};

uint16_t g_GW_PC_6[GW_PC_6_ITEM_MAX] = {0};

char* GW_PC_2Item[GW_PC_2_ITEM_MAX] = {
    "VehiSpd",
    "SteerAng",
	"ESP1Active",
	"ABS3Active",
	"VehiSpdV",
	"SteerAngV",
	"ESP1TOFlg",
	"ABS3TOFlg",
	"SAS1TOFlg"
};

char* GW_PC_2Value[GW_PC_2_ITEM_MAX][16] = {
    {""},
    {"CLKW", "CCLKW", "Reversed", "0", "invalid"},
    {"Inactive", "Active"},
	{"Inactive", "Active"},
	{"Valid", "Invalid"},
	{"Valid", "Invalid"},
	{"Normal", "Timeout"},
	{"Normal", "Timeout"},
	{"Normal", "Timeout"},
};

uint16_t GW_PC_2Max[GW_PC_2_ITEM_MAX] = {46, (0xFFFF/85 + 1), 2, 2, 2, 2, 2, 2, 2};
uint16_t g_GW_PC_2[GW_PC_2_ITEM_MAX] = {0,(0xFFFF/85), 0, 0, 0, 0, 0, 0, 0};

char* GW_PC_7Item[GW_PC_7_ITEM_MAX] = {
    "4WDLockLmp",
    "4WDLowLamp",
	"Lamp2WD",
	"FDLGreenLp",
	"FDLYelloLp",
	"RDLGreenLp",
	"RDLYelloLp",
	"AWD1TOFlg",
	"EDL1TOFlg"
};

char* GW_PC_7Value[GW_PC_7_ITEM_MAX][16] = {
    {"LampOff", "BlinkLamp", "LampOn", "Unused"},  // LMP=Light（3字符）
    {"LampOff", "BlinkLamp", "LampOn", "Unused"},
	{"LampOff", "BlinkLamp", "LampOn", "Unused"},
	{"Off", "On", "Flashing", "Not used"},
	{"Off", "On", "Flashing", "Not used"},
	{"Off", "On", "Flashing", "Not used"},
	{"Off", "On", "Flashing", "Not used"},
	{"Normal", "Timeout"},
	{"Normal", "Timeout"},
};

uint16_t GW_PC_7Max[GW_PC_7_ITEM_MAX] = {4, 4, 4, 4, 4, 4, 4, 2, 2};
uint16_t g_GW_PC_7[GW_PC_7_ITEM_MAX] = {0};

char* GW_PC_4Item[GW_PC_4_ITEM_MAX] = {
    "SFSYelloLp",
    "SFSGreenLp",
    "S1_TO_Flg",
};

char* GW_PC_4Value[GW_PC_4_ITEM_MAX][16] = {
	{"Off", "On", "Flashing", "Not used"},
	{"Off", "On", "Flashing", "Not used"},
	{"Normal", "Timeout"},
};

uint16_t GW_PC_4Max[GW_PC_4_ITEM_MAX] = {
    4,
    4,
    2,
};

uint16_t g_GW_PC_4[GW_PC_4_ITEM_MAX] = {0};

char* GW_BD_9Item[GW_BD_9_ITEM_MAX] = {
    "FLDoorSts",
    "FRDoorSts",
    "RLDoorSts",
    "RRDoorSts",
    "TGateOpSts",
    "HoodSts",
    "T1LTLgtSWS",
    "T1RTLgtSWS",
    "PosLgtSts",
    "ACRFrostSt",
    "PowerMod",
    "LowBSts",
    "HighBSts",
    "B1LTLgtSts",
    "B1RTLgtSts",
    "EmyLgtSts",
    "RFogLgtSts",
    "FFogLgtSts",
    "DRLgtSts",
    "RGearInfo",
    "BMirorFSts",
    "T1LTLgtSWV",
    "T1RTLgtSWV",
    "BCM1TOFlg",
    "TCM1TOFlg"
};

char* GW_BD_9Value[GW_BD_9_ITEM_MAX][16] = {
    {"Close", "Open"},
    {"Close", "Open"},
    {"Close", "Open"},
    {"Close", "Open"},
    {"Close", "Open"},
    {"Close", "Open"},
    {"Off", "On"},
    {"Off", "On"},
    {"Off", "On", "Reserved", "Invalid"},
    {"Off", "On"},
    {"Off", "ACC", "On", "Start"},
	{"Off", "On", "Reserved", "Invalid"},
	{"Off", "On", "Reserved", "Invalid"},
	{"Off", "On", "Reserved", "Invalid"},
	{"Off", "On", "Reserved", "Invalid"},
	{"Off", "On", "Reserved", "Invalid"},
	{"Off", "On", "Reserved", "Invalid"},
	{"Off", "On", "Reserved", "Invalid"},
	{"Off", "On", "Reserved", "Invalid"},
    {"NotEngaged", "Engaged"},
    {"Fold", "Unfold"},
    {"Valid", "Invalid"},
	{"Valid", "Invalid"},
	{"Normal", "Timeout"},
	{"Normal", "Timeout"},
};

uint16_t GW_BD_9Max[GW_BD_9_ITEM_MAX] = {
    2, 2, 2, 2, 2, 2, 2, 2, 4, 2,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 2,
    2, 2, 2, 2, 2
};

uint16_t g_GW_BD_9[GW_BD_9_ITEM_MAX] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 0, 0
};

char* GW_BD_14Item[GW_BD_14_ITEM_MAX] = {
    "BtnTrgSts",
    "ACSysSts",
    "DriverTemp",
    "PsgrTemp",
    "BlowerSpd",
    "AirDst",
    "AirCir",
    "ACBtnSts",
    "FDefrost",
    "DualBtn",
    "AUTOBtn",
    "OutsdTemp",
    "SCleanMod",
	"TempLvl",
	"RDefrost",
	"PTCBtnSts",
	"BlrSpdLvlR",
	"RearModSts",
	"OutsdTempV",
	"DualMod",
	"APsgBtnSts",
	"AC1TOFlg",
	"AC2TOFlg"
};

char* GW_BD_14Value[GW_BD_14_ITEM_MAX][16] = {
    {"NotPressed", "Pressed"},
    {"Off", "On"},
    {"NoDisplay", "LO", "HI", "Invalid"},
    {"NoDisplay", "LO", "HI", "Invalid"},
    {"Off", "BS1", "BS2", "BS3", "BS4", "BS5", "BS6", "BS7"},
    {"Face", "FeAFt", "FeAFtADt", "Foot", "FootADe", "FaceADe", "Reserved", "Reserved"},
    {"EXTCIR", "INTCIR"},
	{"Off", "On"},
	{"Off", "On"},
	{"Off", "On"},
	{"Off", "On"},
    {"Invalid"},
	{"Off", "On"},
    {"Level 1", "Level 2", "Level 3", "Level 4", "Level 5", "Level 6", "Level 7", "Level 8", "Level 9", "Level 10", "Level 11", "Level 12", "Level 13", "Level 14", "Level 15", "Reserved"},
	{"NotPressed", "Pressed"},
	{"Off", "On"},
    {"Off", "BlrLvl1", "BlrLvl2", "BlrLvl3"},
    {"Off", "On"},
    {"Valid", "Invalid"},
    {"SignalMod", "DualMod"},
	{"Off", "On"},
	{"Normal", "Timeout"},
	{"Normal", "Timeout"},
};

uint16_t GW_BD_14Max[GW_BD_14_ITEM_MAX] = {
    2, 2, 0x3F, 0x3F, 8, 8, 2, 2, 2, 2, 2, 128, 2,
    16, 2, 2, 4, 2, 2, 2, 2, 2, 2
};

uint16_t g_GW_BD_14[GW_BD_14_ITEM_MAX] = {
    0, 0, 0x13, 0x13, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

char* GW_BD_24Item[GW_BD_24_ITEM_MAX] = {
    "WinRStsRR",
    "WinRStsRL",
    "WinRStsFR",
    "WinRStsFL",
    "WinPosFL",
    "WinPosFR",
    "WinPosRL",
    "WinPosRR",
    "BCM2TOFlg",
};

char* GW_BD_24Value[GW_BD_24_ITEM_MAX][16] = {
    {"StandStill", "Opening", "Closing", "Reserved"},
	{"StandStill", "Opening", "Closing", "Reserved"},
	{"StandStill", "Opening", "Closing", "Reserved"},
	{"StandStill", "Opening", "Closing", "Reserved"},
    {""},
    {""},
    {""},
    {""},
	{"Normal", "Timeout"},
};

uint16_t GW_BD_24Max[GW_BD_24_ITEM_MAX] = {
    4,
    4,
    4,
    4,
    26,
    26,
    26,
    26,
    2,
};

uint16_t g_GW_BD_24[GW_BD_24_ITEM_MAX] = {0};

char* GW_BD_29Item[GW_BD_29_ITEM_MAX] = {
    "FLStHtLvl",
    "FRStHtLvl",
    "FLStMsgLvl",
    "FLStMsgMod",
    "WlsCrgSw",
    "CrgingSts",
    "FailSts",
    "EPMMode",
    "FaultsSts",
    "FLStVLvlSts",
    "PhoneRmder",
    "FRStVLvlSts",
    "EPM1TOFlg",
    "WCM1TOFlg",
    "SCU1TOFlg"
};

char* GW_BD_29Value[GW_BD_29_ITEM_MAX][16] = {
    {"Off", "Low", "Mid", "High", "Reserved", "Invalid"},
    {"Off", "Low", "Mid", "High", "Reserved", "Invalid"},
    {"Off", "Low", "Mid", "High", "Reserved", "Invalid"},
    {"Wave", "Cross", "Jump", "Reserved", "Invalid"},
    {"Off", "On", "Reserved", "Invalid"},
    {"NoCharge", "Charging", "ChargCmplt", "Fault"},
    {"Normal", "UnderV", "OverV", "OverTemp", "FornMtrDe", "OverPower", "Reserved", "Reserved"},
    {"Invalid", "AUTO", "ALWEXT", "ALWRTR"},
    {"NoFault", "DrvrHeatPF", "PsgrHeatWF", "NTCShort", "NTCOpen", "SCUHighV", "SCULowV", "MAMComF", "MAMHighV", "MAMLowV", "RemoteLoss", "Reserved", "Invalid"},
	{"Off", "Low", "Mid", "High", "Reserved", "Invalid"},
    {"NoWarning", "Forgotten"},
	{"Off", "Low", "Mid", "High", "Reserved", "Invalid"},
	{"Normal", "Timeout"},
	{"Normal", "Timeout"},
	{"Normal", "Timeout"},
};

uint16_t GW_BD_29Max[GW_BD_29_ITEM_MAX] = {16, 16, 8, 16, 4, 4, 8, 4, 256, 16, 2, 16, 2, 2, 2,};
uint16_t g_GW_BD_29[GW_BD_29_ITEM_MAX] = {0};


//----------------------------------F1------------------------------//
char* F1Item[F1_ITEM_MAX] = {
		"ABS_VhSd",
		"ABS_SpdV",
		"ABS_TmOt",
};
char* F1Value[F1_ITEM_MAX][16] = {};
uint16_t F1Max[F1_ITEM_MAX] = {
		460,
		2,
		2,
};
uint16_t g_F1[F1_ITEM_MAX] = {0};

//----------------------------------F2------------------------------//
char* F2Item[F2_ITEM_MAX] = {
		"EMS2_ES",
		"EMS2_ESV",
		"EMS2_TO"
};
char* F2Value[F2_ITEM_MAX][16] = {};
uint16_t F2Max[F2_ITEM_MAX] = {
		(0xFFFF/400),
		2,
		2,
};
uint16_t g_F2[F2_ITEM_MAX] = {0};

//----------------------------------F3------------------------------//
char* F3Item[F3_ITEM_MAX] = {
		"ABS_VhSd",
		"ABS_SpdV",
		"ABS_TmOt",
		"EMS2_ES",
		"EMS2_ESV",
		"EMS2_TO"
};
char* F3Value[F3_ITEM_MAX][16] = {};
uint16_t F3Max[F3_ITEM_MAX] = {
		460,
		2,
		2,
		(0xFFFF/400),
		2,
		2,
};
uint16_t g_F3[F3_ITEM_MAX] = {0};

//----------------------------------F4------------------------------//
char* F4Item[F4_ITEM_MAX] = {
		"EMS4_ECTmp",
		"EMS4_ECTpV",
		"EMS4_TO"
};
char* F4Value[F4_ITEM_MAX][16] = {};
uint16_t F4Max[F4_ITEM_MAX] = {
		0xFF,
		2,
		2,
};
uint16_t g_F4[F4_ITEM_MAX] = {90/2, 0, 0};

//----------------------------------F5------------------------------//
char* F5Item[F5_ITEM_MAX] = {
		"ABS_VhSd",
		"ABS_SpdV",
		"ABS_TmOt",
};
char* F5Value[F5_ITEM_MAX][16] = {};
uint16_t F5Max[F5_ITEM_MAX] = {
		460,
		2,
		2,
};
uint16_t g_F5[F5_ITEM_MAX] = {0};

//----------------------------------F6------------------------------//
char* F6Item[F6_ITEM_MAX] = {
		"ABS_VhSd",
		"ABS_SpdV",
		"ABS_TmOt",
		"EMS2_ES",
		"EMS2_ESV",
		"EMS2_TO",
		"EMS4_FC",
		"EMS4_TO",
};
char* F6Value[F6_ITEM_MAX][16] = {
};
uint16_t F6Max[F6_ITEM_MAX] = {
		460,
		2,
		2,
		(0xFFFF/400),
		2,
		2,
		0xFF/5,
		2,
};
uint16_t g_F6[F6_ITEM_MAX] = {0};

//----------------------------------F7------------------------------//
char* F7Item[F7_ITEM_MAX] = {
		"ABS_VhSd",
		"ABS_SpdV",
		"ABS_TmOt",
		"EMS2_ES",
		"EMS2_ESV",
		"EMS2_TO",
		"EMS4_FC",
		"EMS4_TO",
};
char* F7Value[F7_ITEM_MAX][16] = {};
uint16_t F7Max[F7_ITEM_MAX] = {
		460,
		2,
		2,
		(0xFFFF/400),
		2,
		2,
		0xFF/5,
		2,
};
uint16_t g_F7[F7_ITEM_MAX] = {0};

//----------------------------------F8------------------------------//
char* F8Item[F8_ITEM_MAX] = {
		"TPMS_SSt",
		"TPMS_TID",
		"TPMS_SLost",
		"TPMS_TLeak",
		"TPMS_LSt",
		"TPMS_TPS",
		"TPMS_TP"
};
char* F8Value[F8_ITEM_MAX][16] = {};
uint16_t F8Max[F8_ITEM_MAX] = {
		4,
		4,
		2,
		2,
		4,
		4,
		0xFF / 15,
};
uint16_t g_F8[F8_ITEM_MAX] = {0};

//----------------------------------F9------------------------------//
char* F9Item[F9_ITEM_MAX] = {
		"BCM1_FLDor",
		"BCM1_FRDor",
		"BCM1_RLDor",
		"BCM1_RRDor",
		"BCM1_TailG",
		"BCM1_HoodS",
		"BCM1_TO"
};
char* F9Value[F9_ITEM_MAX][16] = {};
uint16_t F9Max[F9_ITEM_MAX] = {
		2,
		2,
		2,
		2,
		2,
		2,
		2,
};
uint16_t g_F9[F9_ITEM_MAX] = {0};

//----------------------------------F10------------------------------//
char* F10Item[F10_ITEM_MAX] = {
		"TCU3_TgtG",
		"TCU3_TgtGV",
		"TCU1_GSPos",
		"TCU1_GSPoV",
		"TCU1_TO",
		"TCU3_TO"
};
char* F10Value[F10_ITEM_MAX][16] = {};
uint16_t F10Max[F10_ITEM_MAX] = {
		0x10,
		2,
		0x10,
		2,
		2,
		2,
};
uint16_t g_F10[F10_ITEM_MAX] = {0};

//----------------------------------F11------------------------------//
char* F11Item[F11_ITEM_MAX] = {
		"E1_RGreen",
		"E1_RYellow",
		"E1_FGreen",
		"E1_FYellow",
		"EDL1_TO"
};
char* F11Value[F11_ITEM_MAX][16] = {};
uint16_t F11Max[F11_ITEM_MAX] = {
		4,
		4,
		4,
		4,
		2,
};
uint16_t g_F11[F11_ITEM_MAX] = {0};

//----------------------------------F12------------------------------//
char* F12Item[F12_ITEM_MAX] = {
		"AC2_OTempV",
		"AC2_OTemp",
		"AC2_TO"
};
char* F12Value[F12_ITEM_MAX][16] = {};
uint16_t F12Max[F12_ITEM_MAX] = {
		2,
		0xFF,
		2
};
uint16_t g_F12[F12_ITEM_MAX] = {0};

//----------------------------------F13------------------------------//
char* F13Item[F13_ITEM_MAX] = {
	    "FCM_ELnID", "FCM_ELnCl", "FCM_ELnTp", "FCM_ELnHD", "FCM_ELnCv",
	    "FCM_ERnID", "FCM_ERnCl", "FCM_ERnTp", "FCM_ERnHD", "FCM_ERnCv",
	    "FCM5_RC", "FCM5_CS",
		"FCM_NLnID", "FCM_NLnCl", "FCM_NLnTp", "FCM_NLnHD", "FCM_NLnCv",
	    "FCM_NRnID", "FCM_NRnCl", "FCM_NRnTp", "FCM_NRnHD", "FCM_NRnCv",
	    "FCM6_RC", "FCM6_CS",
	    "FCM_ACCOI", "FCM_ACCO", "FCM_ACCTV", "FCM_dxTOC", "FCM_ACOLX",
	    "FCM_ACOHY", "FCM_FFOI", "FCM_FFOT", "FCM_FFOLX", "FCM_FFOHY",
	    "FCM7_RC", "FCM7_CS",
	    "FCM_RiOI", "FCM_LeOI", "FCM_LeOT", "FCM_ACCLV", "FCM_LeOLX",
	    "FCM_LeOHY", "FCM_RiOT", "FCM_ACCRV", "FCM_RiOLX", "FCM_RiOHY",
	    "FCM8_RC", "FCM8_CS"
};
char* F13Value[F13_ITEM_MAX][16] = {};
uint16_t F13Max[F13_ITEM_MAX] = {
	    2,
	    4,
	    4,
		0x1F5,
		0x209,
	    2,
	    4,
	    4,
		0x1F5,
		0x209,
		0x10,
		0x100,
	    2,
	    4,
	    4,
		0x1F5,
		0x209,
	    2,
	    4,
	    4,
		0x1F5,
		0x209,
		0x10,
		0x100,
	    2,
	    8,
	    8,
	    8,
	    0xFF,
	    0x3E9,
	    2,
	    0x20,
	    0xFF,
	    0x3E9,
	    0x10,
	    0x100,
	    2,
	    2,
	    8,
	    8,
	    0xFF,
	    0x3E9,
	    8,
	    8,
	    0xFF,
	    0x3E9,
	    0x10,
	    0x100,
};
uint16_t g_F13[F13_ITEM_MAX] = {0};



//----------------------------------F14------------------------------//
char* F14Item[F14_ITEM_MAX] = {
		"LeftTLgtSt"
};
char* F14Value[F14_ITEM_MAX][16] = {
};
uint16_t F14Max[F14_ITEM_MAX] = {
		4,
};
uint16_t g_F14[F14_ITEM_MAX] = {0};

//----------------------------------F15------------------------------//
char* F15Item[F15_ITEM_MAX] = {
};
char* F15Value[F15_ITEM_MAX][16] = {};
uint16_t F15Max[F15_ITEM_MAX] = {
};
uint16_t g_F15[F15_ITEM_MAX] = {0};

//----------------------------------F16------------------------------//
char* F16Item[F16_ITEM_MAX] = {
};
char* F16Value[F16_ITEM_MAX][16] = {};
uint16_t F16Max[F16_ITEM_MAX] = {
};
uint16_t g_F16[F16_ITEM_MAX] = {0};

//----------------------------------F17------------------------------//
char* F17Item[F17_ITEM_MAX] = {
};
char* F17Value[F17_ITEM_MAX][16] = {};
uint16_t F17Max[F17_ITEM_MAX] = {
};
uint16_t g_F17[F17_ITEM_MAX] = {0};

//----------------------------------F18------------------------------//
char* F18Item[F18_ITEM_MAX] = {
};
char* F18Value[F18_ITEM_MAX][16] = {};
uint16_t F18Max[F18_ITEM_MAX] = {
};
uint16_t g_F18[F18_ITEM_MAX] = {0};

//----------------------------------F19------------------------------//
char* F19Item[F19_ITEM_MAX] = {
};
char* F19Value[F19_ITEM_MAX][16] = {};
uint16_t F19Max[F19_ITEM_MAX] = {
};
uint16_t g_F19[F19_ITEM_MAX] = {0};

//----------------------------------F20------------------------------//
char* F20Item[F20_ITEM_MAX] = {
};
char* F20Value[F20_ITEM_MAX][16] = {};
uint16_t F20Max[F20_ITEM_MAX] = {
};
uint16_t g_F20[F20_ITEM_MAX] = {0};

//----------------------------------F21------------------------------//
char* F21Item[F21_ITEM_MAX] = {
};
char* F21Value[F21_ITEM_MAX][16] = {};
uint16_t F21Max[F21_ITEM_MAX] = {
};
uint16_t g_F21[F21_ITEM_MAX] = {0};

//----------------------------------F22------------------------------//
char* F22Item[F22_ITEM_MAX] = {
};
char* F22Value[F22_ITEM_MAX][16] = {};
uint16_t F22Max[F22_ITEM_MAX] = {
};
uint16_t g_F22[F22_ITEM_MAX] = {0};

//----------------------------------F23------------------------------//
char* F23Item[F23_ITEM_MAX] = {
};
char* F23Value[F23_ITEM_MAX][16] = {};
uint16_t F23Max[F23_ITEM_MAX] = {
};
uint16_t g_F23[F23_ITEM_MAX] = {0};

//----------------------------------F24------------------------------//
char* F24Item[F24_ITEM_MAX] = {
};
char* F24Value[F24_ITEM_MAX][16] = {};
uint16_t F24Max[F24_ITEM_MAX] = {
};
uint16_t g_F24[F24_ITEM_MAX] = {0};

//----------------------------------F25------------------------------//
char* F25Item[F25_ITEM_MAX] = {
};
char* F25Value[F25_ITEM_MAX][16] = {};
uint16_t F25Max[F25_ITEM_MAX] = {
};
uint16_t g_F25[F25_ITEM_MAX] = {0};

//----------------------------------F26------------------------------//
char* F26Item[F26_ITEM_MAX] = {
};
char* F26Value[F26_ITEM_MAX][16] = {};
uint16_t F26Max[F26_ITEM_MAX] = {
};
uint16_t g_F26[F26_ITEM_MAX] = {0};

//----------------------------------F27------------------------------//
char* F27Item[F27_ITEM_MAX] = {
};
char* F27Value[F27_ITEM_MAX][16] = {};
uint16_t F27Max[F27_ITEM_MAX] = {
};
uint16_t g_F27[F27_ITEM_MAX] = {0};

//----------------------------------F28------------------------------//
char* F28Item[F28_ITEM_MAX] = {
};
char* F28Value[F28_ITEM_MAX][16] = {};
uint16_t F28Max[F28_ITEM_MAX] = {
};
uint16_t g_F28[F28_ITEM_MAX] = {0};

//----------------------------------F29------------------------------//
char* F29Item[F29_ITEM_MAX] = {
};
char* F29Value[F29_ITEM_MAX][16] = {};
uint16_t F29Max[F29_ITEM_MAX] = {
};
uint16_t g_F29[F29_ITEM_MAX] = {0};

//----------------------------------F30------------------------------//
char* F30Item[F30_ITEM_MAX] = {
};
char* F30Value[F30_ITEM_MAX][16] = {};
uint16_t F30Max[F30_ITEM_MAX] = {
};
uint16_t g_F30[F30_ITEM_MAX] = {0};
