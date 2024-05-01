/*
 * InjOutputs.c
 *
 *  Created on: May 1, 2019
 *      Author: Mati
 */
#ifndef InjOutputs_C_
#define InjOutputs_C_
#endif

#include "Std_Types.h"
#include "InjOutputs.h"

#define INJ_START_SEC_VAR_FAST_8BIT
#include "ASW_MemMap.h"
	volatile static boolean Inj_bStModDis;
	volatile static boolean Inj_bOffCut;
#define INJ_STOP_SEC_VAR_FAST_8BIT
#include "ASW_MemMap.h"

#define INJ_START_SEC_VAR_FAST_32BIT
#include "ASW_MemMap.h"
	volatile real_t Inj_StUpMod_Pct;
	volatile real_t Inj_PulEnd_Deg;
	volatile real_t Inj_PulDur_ms;
	volatile real_t Inj_BseDur_ms;
	volatile real_t Inj_AfrMod;
#define INJ_STOP_SEC_VAR_FAST_32BIT
#include "ASW_MemMap.h"

boolean Get_Inj_bStModDis(void)
{
	return Inj_bStModDis;
}
void Set_Inj_bStModDis(boolean x)
{
	Inj_bStModDis = x;
}

boolean Get_Inj_bOffCut(void)
{
	return Inj_bOffCut;
}
void Set_Inj_bOffCut(boolean x)
{
	Inj_bOffCut = x;
}

real_t Get_Inj_StUpMod_Pct(void)
{
	return Inj_StUpMod_Pct;
}
void Set_Inj_StUpMod_Pct(real_t x)
{
	Inj_StUpMod_Pct = x;
}

real_t Get_Inj_PulEnd_Deg(void)
{
	return Inj_PulEnd_Deg;
}
void Set_Inj_PulEnd_Deg(real_t x)
{
	Inj_PulEnd_Deg = x;
}

real_t Get_Inj_PulDur_ms(void)
{
	return Inj_PulDur_ms;
}
void Set_Inj_PulDur_ms(real_t x)
{
	Inj_PulDur_ms = x;
}

real_t Get_Inj_BseDur_ms(void)
{
	return Inj_BseDur_ms;
}
void Set_Inj_BseDur_ms(real_t x)
{
	Inj_BseDur_ms = x;
}

real_t Get_Inj_AfrMod(void)
{
	return Inj_AfrMod;
}
void Set_Inj_AfrMod(real_t x)
{
	Inj_AfrMod = x;
}
#ifdef InjOutputs_C_
#undef InjOutputs_C_
#endif
