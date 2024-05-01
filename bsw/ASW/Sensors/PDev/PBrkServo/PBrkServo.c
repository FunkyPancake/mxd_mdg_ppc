
#include "PBrkServo.h"
#include "PBrkServo_Out.h"
#include "Ifx.h"
/*Calibration parameters*/
#define SENSOR_START_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"
const volatile sint16 PBrkServo_DefVal_Kpa = 115;
const volatile sint16 PBrkServo_mV2Kpa_C[] = {
	2, 400, 4650, 15, 115};
#define SENSOR_STOP_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"

#define PBrkServo_mV2Kpa_Get(x) (Ifx_IntIpoCur_i16_i16(x, 2, (const sint16 *)&(PBrkServo_mV2Kpa_C[1]), (const sint16 *)&(PBrkServo_mV2Kpa_C[3])))

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

#if 0

#define SNS_START_SEC_CAL_8BIT
#include "ASW_MemMap.h"
const volatile uint8_t Sns_PVacBrkDiagDbnc_P = 10;
#define SNS_STOP_SEC_CAL_8BIT
#include "ASW_MemMap.h"

#define SNS_START_SEC_VAR_FAST_32BIT
#include "ASW_MemMap.h"
volatile float32 Sns_PVacBrk_Bar;
#define SNS_STOP_SEC_VAR_FAST_32BIT
#include "ASW_MemMap.h"

#define SNS_START_SEC_VAR_FAST_16BIT
#include "ASW_MemMap.h"
volatile int16 Sns_PVacBrkRaw_mV;
#define SNS_STOP_SEC_VAR_FAST_16BIT
#include "ASW_MemMap.h"

#define SNS_START_SEC_VAR_STBY_8BIT
#include "ASW_MemMap.h"
volatile uint8_t Sns_PVacBrk_ErrState;
#define SNS_STOP_SEC_VAR_STBY_8BIT
#include "ASW_MemMap.h"

#define SNS_START_SEC_VAR_NOINIT_8BIT
#include "ASW_MemMap.h"
volatile static uint8_t Sns_PVacBrkDiagCurDbnc;
#define SNS_STOP_SEC_VAR_NOINIT_8BIT
#include "ASW_MemMap.h"

__inline__ void Dec_Sns_PVacBrkDiagCurDbnc(void)
{
	if (Sns_PVacBrkDiagCurDbnc > 0)
	{
		Sns_PVacBrkDiagCurDbnc -= 1;
	}
}
__inline__ void Inc_Sns_PVacBrkDiagCurDbnc(void)
{
	if (Sns_PVacBrkDiagCurDbnc <= Sns_PVacBrkDiagDbnc_P)
	{
		Sns_PVacBrkDiagCurDbnc += 1;
	}
}
/*
 * Setters/Getters
 * */
/*RAW value*/
void Set_Sns_PVacBrkRaw_mV(int16 data)
{
	Sns_PVacBrkRaw_mV = data;
}
__inline__ int16 Get_Sns_PVacBrkRaw_mV()
{
	return Sns_PVacBrkRaw_mV;
}

/*Phys Value*/
__inline__ void Set_Sns_PVacBrk_mBar(float32 data)
{
	Sns_PVacBrk_Bar = data;
}

float32 Get_Sns_PVacBrk_mBar(void)
{
	return Sns_PVacBrk_Bar;
}

/*Diag*/
uint8_t Get_Sns_PVacBrk_ErrState(void)
{
	return Sns_PVacBrk_ErrState;
}
__inline__ void Set_Sns_PVacBrk_ErrState(uint8_t data)
{
	Sns_PVacBrk_ErrState = data;
}

/*Basic diagnotics with debounce*/
uint8_t Sns_PVacBrk_Diag(float32 PVacBrk_raw)
{
	uint8_t flt_sts;

	if ((PVacBrk_raw < Sns_PVacBrkDiagLow_mV_P) || (PVacBrk_raw > Sns_PVacBrkDiagHigh_mV_P))
	{
		Inc_Sns_PVacBrkDiagCurDbnc();
		flt_sts = STD_TRUE;
	}
	else
	{
		Dec_Sns_PVacBrkDiagCurDbnc();
		flt_sts = STD_FALSE;
	}
	if (Sns_PVacBrkDiagCurDbnc >= Sns_PVacBrkDiagDbnc_P)
	{
		Set_Sns_PVacBrk_ErrState(DIAG_ERR_OVRRNG);
	}
	return flt_sts;
}

void Sns_PVacBrk_Process(void)
{
	float32 PVacBrk;
	float32 PVacBrk_old = Get_Sns_PVacBrk_mBar();
	uint8_t PVacBrkerr_tmp;
	uint8_t PVacBrkerr;
	float32 vac_raw = (float32)Get_Sns_PVacBrkRaw_mV();
	PVacBrk = (vac_raw - Sns_PVacBrkOff_mV_P) * Sns_PVacBrkGrd_mBar_mV_P - 1000;
	PVacBrk = SimpleLPFilter(PVacBrk, PVacBrk_old, Sns_PVacBrkFilt_P);
	PVacBrkerr_tmp = Sns_PVacBrk_Diag(vac_raw);
	PVacBrkerr = Get_Sns_PVacBrk_ErrState();
	if (PVacBrkerr_tmp == STD_TRUE)
	{
		PVacBrk = PVacBrk_old;
	}
	if (PVacBrkerr == STD_TRUE)
	{
		PVacBrk = Sns_PVacBrkDef_mBar_P;
	}
	Set_Sns_PVacBrk_mBar(PVacBrk);
}

#ifdef Sns_PVacBrk_C_
#undef Sns_PVacBrk_C_
#endif
#endif
boolean PBrkServoDiag(sint16 raw_value);
boolean PBrkServoDiag(sint16 raw_value)
{
	PARAM_UNUSED(raw_value);
	return STD_TRUE;
}
void PBrkServoCalc(void)
{
	sint16 raw = Get_PBrkServo_Raw_U_mV();
	boolean is_valid = PBrkServoDiag(raw);
	sint16 phy = PBrkServo_mV2Kpa_Get(raw);
	if (!is_valid)
	{
		phy = PBrkServo_DefVal_Kpa;
	}
	Set_PBrkServo_Vac_Kpa(phy);
}