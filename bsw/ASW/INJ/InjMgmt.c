/*
 * EngInjMgmt.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Mati
 */


#include "Std_Types.h"
#include "InjMgmt.h"
#include "UtilsLookup.h"
#include "ASW/EngMgmt.h"
#include "ASW/EngSns.h"
#include "InjOutputs.h"

#define INJ_START_SEC_CAL_16BIT
#include "ASW_MemMap.h"
const volatile uint16 InjCutOffRpmTh_Rpm_P = 1500;
const volatile sint16 InjCutOffThrTh_Per_P = 2;
#define INJ_STOP_SEC_CAL_16BIT
#include "ASW_MemMap.h"



#define INJ_START_SEC_CAL_UNSPECIFIED
#include "ASW_MemMap.h"
const volatile  real_t InjDurBase_ms_M[CAL_MAIN_ROW_SZ * CAL_MAIN_COL_SZ] = { 2.20,
		3.00, 3.00, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12,
		5.12, 2.20, 3.00, 3.00, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12, 5.12,
		5.12, 5.12, 5.12, 2.30, 3.00, 3.00, 6.20, 6.20, 6.20, 6.20, 6.20, 6.20,
		6.20, 6.20, 6.20, 6.20, 6.20, 2.50, 3.00, 3.00, 6.20, 6.20, 6.20, 6.20,
		6.20, 6.20, 6.20, 6.20, 6.20, 6.20, 6.20, 2.50, 3.00, 3.00, 6.00, 6.00,
		7.00, 6.50, 6.50, 6.50, 6.50, 6.50, 6.50, 6.50, 6.50, 3.00, 4.00, 6.00,
		6.00, 6.00, 7.00, 6.50, 6.50, 6.50, 6.50, 6.50, 6.50, 6.50, 6.50, 3.00,
		4.00, 6.00, 6.00, 6.00, 7.00, 7.00, 7.00, 7.00, 7.00, 7.00, 7.00, 7.00,
		7.00, 3.00, 4.00, 6.00, 6.00, 6.00, 7.00, 7.00, 7.00, 7.00, 7.00, 7.00,
		7.00, 7.00, 7.00, 3.00, 4.00, 6.00, 6.00, 6.00, 7.00, 7.00, 7.00, 9.00,
		9.00, 8.00, 8.00, 8.00, 8.00, 3.00, 5.00, 5.00, 6.00, 6.00, 7.00, 7.00,
		7.00, 9.00, 9.00, 8.00, 8.00, 8.00, 8.00, 3.00, 5.00, 5.00, 6.00, 6.00,
		7.00, 7.00, 7.00, 9.00, 9.00, 8.50, 8.50, 8.50, 8.50, 3.00, 5.00, 5.00,
		6.00, 6.00, 7.00, 7.00, 7.00, 9.00, 9.00, 8.50, 8.50, 8.50, 8.50, 0.00,
		3.00, 3.00, 6.00, 6.00, 7.00, 7.00, 7.00, 9.00, 9.00, 8.50, 8.50, 9.00,
		9.00, 0.00, 3.00, 3.00, 6.00, 6.00, 7.00, 7.00, 7.00, 9.00, 9.00, 8.50,
		8.50, 9.00, 9.00, 0.00, 3.00, 3.00, 5.00, 6.00, 7.00, 7.00, 7.00, 9.00,
		9.00, 8.50, 8.50, 8.50, 9.12, 0.00, 3.00, 3.00, 5.00, 6.00, 7.00, 7.00,
		7.00, 9.00, 9.00, 8.50, 8.50, 8.50, 9.12, 0.00, 3.00, 3.00, 4.00, 4.50,
		4.50, 7.00, 7.00, 9.00, 9.00, 8.50, 8.50, 8.50, 9.12, 0.00, 3.00, 3.00,
		4.00, 4.50, 4.50, 5.00, 7.00, 9.00, 9.00, 8.50, 8.50, 8.50, 9.12, 0.00,
		3.00, 3.00, 4.00, 4.50, 4.50, 5.00, 7.00, 9.00, 9.00, 8.50, 8.50, 8.50,
		9.12, 0.00, 3.00, 3.00, 4.00, 4.50, 4.50, 5.00, 7.00, 9.00, 9.00, 8.50,
		8.50, 8.50, 9.12 };

const volatile  sint16 InjStClt_DegC_A[CAL_MAIN_ROW_SZ] = { -20, -10, 0, 10, 20, 30,
		40, 50, 60, 70, 80, 90, 100, 110 };
const volatile  sint16 InjStTurns_A[CAL_MAIN_COL_SZ] = { 10, 20, 30, 50, 60, 70, 80,
		90, 100, 150, 200, 250, 300, 400, 1000, 2000, 3000, 4000, 5000, 6000 };

const volatile  sint16 InjStUpDur_ms_M[CAL_MAIN_ROW_SZ * CAL_MAIN_COL_SZ] = { 
		300, 200, 175, 150, 125, 100, 120,120, 100, 90, 70, 50, 20, 10, 0, 0, 0, 0,0, 0,
		300, 200, 175, 150, 125, 100, 120,120, 100, 90, 70, 50, 20, 10, 0, 0, 0, 0,0, 0,
		300, 200, 150, 125, 100, 90, 90,75, 60, 50, 40, 30, 20, 10, 0, 0, 0, 0,0, 0,
		175, 150, 125, 80, 80, 69, 57, 46, 34, 23, 11, 0, 0, 0, 0, 0,0, 0, 0, 0,
		150, 100, 115, 70, 80, 67, 53, 40, 27, 13, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,
		100, 100, 90, 70, 80, 67, 53, 40, 27, 13, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,
		100, 100, 70, 70, 67, 53, 40, 27, 13, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0,
		85, 80, 73, 50, 50, 50, 38, 25, 13, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0,
		85, 80, 70, 40, 47, 35, 23, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0,
		75, 63, 50, 38, 25, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		75, 56, 38, 19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 25,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 25, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#define INJ_STOP_SEC_CAL_UNSPECIFIED
#include "ASW_MemMap.h"




void InjMgmt(void) {
	uint16 row_idx = Get_MainRowAxisIdx();
	uint16 col_idx = Get_MainColAxisIdx();
	real_t lambda_cor;
	real_t fuel_base_dur;
	real_t st_up_mod;
	real_t fuel_dur;
	fuel_base_dur = TableLookup2D_f(row_idx, col_idx,
			(real_t *) InjDurBase_ms_M, CAL_MAIN_ROW_SZ, CAL_MAIN_COL_SZ);
	Set_Inj_BseDur_ms(fuel_base_dur);
	InjStartUpMod();
	InjCalcPulseEnd();
	InjFuelCutOff();
	lambda_cor = Get_Inj_AfrMod();
	st_up_mod = Get_Inj_StUpMod_Pct();
	fuel_dur = (100 + st_up_mod + lambda_cor) / 100 * fuel_base_dur;
	Set_Inj_PulDur_ms(fuel_dur);
}


void InjStartUpMod() {
	register uint32 turns = Get_Eng_Nturns();
	register sint16 clt = (sint16)Get_Eng_TClt_DegC();
	sint16 mod;
	uint16 row_idx;
	uint16 col_idx;
	if( turns < InjStTurns_A[CAL_MAIN_COL_SZ-1])
	{
		row_idx = AxisLookup_i16(clt, (const volatile sint16*) InjStClt_DegC_A,CAL_MAIN_ROW_SZ);
		col_idx = AxisLookup_i16((sint16)turns,(const volatile sint16*) InjStTurns_A,CAL_MAIN_COL_SZ);
		mod = TableLookup2D_i16(row_idx, col_idx, (sint16 *) InjStUpDur_ms_M,
				CAL_MAIN_ROW_SZ, CAL_MAIN_COL_SZ);
	}
	else
	{
		mod = 0;
	}
	Set_Inj_StUpMod_Pct((real_t)mod);

}
void InjFuelCutOff(void) {
	boolean cutoff_en = 0;
	uint16 rpm = Get_Eng_Nmot_Rpm();
	sint16 throtle = (sint16)Get_Eng_AThr_Pct();
	if ((rpm > InjCutOffRpmTh_Rpm_P) && (throtle < InjCutOffThrTh_Per_P))
		cutoff_en = STD_ACTIVE;
	else
		cutoff_en = STD_IDLE;
	Set_Inj_bOffCut(cutoff_en);
}
void InjCalcDeadTime(void) {
	real_t vbat = Get_Eng_Ubat_V();
}
void InjCalcPulseEnd(void) {
	Set_Inj_PulEnd_Deg(220);
}
