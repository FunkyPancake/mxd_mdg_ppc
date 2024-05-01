/*
 * EngSns.c
 *
 *  Created on: Feb 17, 2019
 *      Author: Mati
 */
#ifndef EngSns_C_
#define EngSns_C_
#endif

#include "Std_Types.h"
#include "EngSns.h"
#include "UtilsLookup.h"
#include "Sns_POil.h"
#include "Sns_PVacBrk.h"
#define CAL_AFR_SZ 20

#define CAL_MAF_SZ 8
//#pragma push
//#pragma section all_types ".cal_32bit" ".cal_32bit"
const volatile real_t EngUbatFac_VmV_P;
const volatile real_t EngPMapFac_KpaMv_P = 0.0247058;
const volatile real_t EngPMapOff_Kpa_P = 0.117647;
//#pragma pop
//#pragma push
//#pragma section all_types ".cal_unspecified" ".cal_unspecified"

const volatile real_t CalLambda_mV_A[CAL_AFR_SZ] =
	{500, 890, 1086, 1478, 1673, 1867, 2260, 2456, 2848, 3043, 3238, 3434, 3630,
	 3825, 4021, 4216, 4413, 4608, 4803, 5000};
const volatile real_t CalLambda_Afr_A[CAL_AFR_SZ] =
	{0.650, 0.690, 0.730, 0.810, 0.840, 0.870, 0.890, 0.920, 0.970, 1.000, 1.030,
	 1.050, 1.070, 1.100, 1.150, 1.200, 1.250, 1.300, 1.400, 1.500};
const volatile real_t CalMaf_kgh_A[CAL_MAF_SZ] =
	{8, 10, 15, 30, 60, 120, 250, 370};
const volatile real_t CalMaf_V_A[CAL_MAF_SZ] =
	{1.4837, 1.5819, 1.7898, 2.2739, 2.8868, 3.6255, 4.4727, 4.9406};
//#pragma pop
//
//#pragma push
//#pragma section all_types ".cal_16bit" ".cal_16bit"
const volatile sint16 EngAThrHigh_Mv_P = 4470;
const volatile sint16 EngAThrLow_Mv_P = 490;
//#pragma pop

//#pragma push
//#pragma section all_types ".meas_ram" ".meas_ram"

//static volatile real_t Eng_POil_Bar;
static volatile real_t Eng_Ubat_V;
static volatile real_t Eng_FMaf_Kgh;
static volatile real_t Eng_PMap_Kpa;
static volatile real_t Eng_AThr_Pct;
static volatile real_t Eng_TClt_DegC;
static volatile real_t Eng_TIat_DegC;
static volatile real_t Eng_TOil_DegC;
static volatile real_t Eng_Afr_Meas;

//static volatile uint16 Eng_POil_Raw;
static volatile uint16 Eng_Ubat_Raw;
static volatile uint16 Eng_FMaf_Raw;
static volatile uint16 Eng_PMap_Raw;
static volatile uint16 Eng_AThr_Raw;
static volatile uint16 Eng_TClt_Raw;
static volatile uint16 Eng_TIat_Raw;
static volatile uint16 Eng_TOil_Raw;
static volatile uint16 Eng_Afr_Raw;

static volatile boolean Eng_Afr_bEn;
//#pragma pop

real_t Get_Eng_AThr_Pct()
{
	return Eng_AThr_Pct;
}

real_t Get_Eng_Ubat_V()
{
	return Eng_Ubat_V;
}
real_t Get_Eng_FMaf_Kgh()
{
	return Eng_FMaf_Kgh;
}
real_t Get_Eng_PMap_Kpa()
{
	return Eng_PMap_Kpa;
}

real_t Get_Eng_Afr_Meas()
{
	return Eng_Afr_Meas;
}
boolean Get_Eng_Afr_bEn()
{
	return Eng_Afr_bEn;
}
real_t Get_Eng_TClt_DegC()
{
	return Eng_TClt_DegC;
}
real_t Get_Eng_TOil_DegC()
{
	return Eng_TOil_DegC;
}
real_t Get_Eng_TIat_DegC()
{
	return Eng_TIat_DegC;
}

__inline__ uint16 Get_Eng_AThr_Raw()
{
	return Eng_AThr_Raw;
}

__inline__ uint16 Get_Eng_Ubat_Raw()
{
	return Eng_Ubat_Raw;
}
__inline__ uint16 Get_Eng_FMaf_Raw()
{
	return Eng_FMaf_Raw;
}
__inline__ uint16 Get_Eng_PMap_Raw()
{
	return Eng_PMap_Raw;
}

__inline__ uint16 Get_Eng_Afr_Raw()
{
	return Eng_Afr_Raw;
}

__inline__ uint16 Get_Eng_TClt_Raw()
{
	return Eng_TClt_Raw;
}
__inline__ uint16 Get_Eng_TOil_Raw()
{
	return Eng_TOil_Raw;
}
__inline__ uint16 Get_Eng_TIat_Raw()
{
	return Eng_TIat_Raw;
}

__inline__ void Set_Eng_TOil_DegC(real_t x)
{
	Eng_TOil_DegC = x;
}

__inline__ void Set_Eng_Ubat_V(real_t x)
{
	Eng_Ubat_V = x;
}

__inline__ void Set_Eng_FMaf_Kgh(real_t x)
{
	Eng_FMaf_Kgh = x;
}

__inline__ void Set_Eng_AThr_Pct(real_t x)
{
	Eng_AThr_Pct = x;
}

__inline__ void Set_Eng_PMap_Kpa(real_t x)
{
	Eng_PMap_Kpa = x;
}

__inline__ void Set_Eng_TClt_DegC(real_t x)
{
	Eng_TClt_DegC = x;
}

__inline__ void Set_Eng_TIat_DegC(real_t x)
{
	Eng_TIat_DegC = x;
}

__inline__ void Set_Eng_Afr_Meas(real_t x)
{
	Eng_Afr_Meas = x;
}

__inline__ void Set_Eng_Afr_bEn(boolean x)
{
	Eng_Afr_bEn = x;
}

void Set_Eng_Ubat_Raw(uint16 x)
{
	Eng_Ubat_Raw = x;
}
void Set_Eng_FMaf_Raw(uint16 x)
{
	Eng_FMaf_Raw = x;
}
void Set_Eng_AThr_Raw(uint16 x)
{
	Eng_AThr_Raw = x;
}
void Set_Eng_PMap_Raw(uint16 x)
{
	Eng_PMap_Raw = x;
}
void Set_Eng_TClt_Raw(uint16 x)
{
	Eng_TClt_Raw = x;
}
void Set_Eng_TIat_Raw(uint16 x)
{
	Eng_TIat_Raw = x;
}
void Set_Eng_TOil_Raw(uint16 x)
{
	Eng_TOil_Raw = x;
}

void Set_Eng_Afr_Raw(uint16 x)
{
	Eng_Afr_Raw = x;
}

void DevDrvrSnsrOilT(void)
{
	real_t input = (real_t)Get_Eng_TOil_Raw();
	real_t output = TableLookup1D_f(input, CalRNtc12_Ohm_A, CalTNtc12_DegC_A,
									CAL_NTC_LEN);
	Set_Eng_TOil_DegC(output);
}

void DevDrvrSnsrVbat(void)
{
	real_t input = (real_t)Get_Eng_Ubat_Raw();
	real_t output = input * ((8.2 + 24.9) / 8.2) * 0.001;
	Set_Eng_Ubat_V(output);
}

void DevDrvrSnsrMaf(void)
{
	real_t volt_mv = ((real_t)Get_Eng_FMaf_Raw()) / 1000;
	real_t output = TableLookup1D_f(volt_mv, CalMaf_V_A, CalMaf_kgh_A,
									CAL_MAF_SZ);
	Set_Eng_FMaf_Kgh(output);
}
void DevDrvrSnsrMap(void)
{
	real_t volt_mv = (real_t)Get_Eng_PMap_Raw();
	real_t output = (volt_mv * EngPMapFac_KpaMv_P) + EngPMapOff_Kpa_P;
	Set_Eng_PMap_Kpa(output);
}
void DevDrvrSnsrTps(void)
{
	real_t volt_mv = (real_t)Get_Eng_AThr_Raw();
	real_t output;
	if (volt_mv >= EngAThrHigh_Mv_P)
	{
		output = 100;
	}
	else if (volt_mv <= EngAThrLow_Mv_P)
	{
		output = 0;
	}
	else
	{
		output = 100 * (volt_mv - EngAThrLow_Mv_P) / (EngAThrHigh_Mv_P - EngAThrLow_Mv_P);
	}
	Set_Eng_AThr_Pct(output);
}
void DevDrvrSnsrIat(void)
{
	real_t volt_mv = (real_t)Get_Eng_TIat_Raw();
	real_t output = TableLookup1D_f(volt_mv, CalRNtc12_Ohm_A, CalTNtc12_DegC_A,
									CAL_NTC_LEN);
	Set_Eng_TIat_DegC(output);
}

void DevDrvrSnsrLambda(void)
{
	real_t volt_mv = (real_t)Get_Eng_Afr_Raw();
	boolean lam_en;
	if (volt_mv > CalLambda_mV_A[0])
		lam_en = STD_TRUE;
	else
		lam_en = STD_FALSE;
	real_t output = TableLookup1D_f(volt_mv, CalLambda_mV_A, CalLambda_Afr_A,
									CAL_AFR_SZ);
	Set_Eng_Afr_bEn(lam_en);
	Set_Eng_Afr_Meas(output);
}

void DevDrvrSnsrClt(void)
{
	real_t volt_mv = (real_t)Get_Eng_TClt_Raw();
	real_t output = TableLookup1D_f(volt_mv, CalRNtc12_Ohm_A, CalTNtc12_DegC_A,
									CAL_NTC_LEN);
	Set_Eng_TClt_DegC(output);
}
void DevDrvrSnsr_10ms(void)
{
	DevDrvrSnsrLambda();
	DevDrvrSnsrMaf();
	DevDrvrSnsrTps();
	DevDrvrSnsrMap();
	Sns_POil_Process();
}

void DevDrvrSnsr_100ms(void)
{
	DevDrvrSnsrClt();
	Sns_PVacBrk_Process();
	DevDrvrSnsrVbat();
	DevDrvrSnsrOilT();
	DevDrvrSnsrIat();
}

#ifdef EngSns_C_
#undef EngSns_C_
#endif
