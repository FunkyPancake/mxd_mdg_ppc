/*
 * EngIdleMngmt.c
 *
 *  Created on: Dec 22, 2018
 *      Author: Mati
 */
#ifndef IDLE_MGMT_C_
#define IDLE_MGMT_C_
#endif

#include "Std_Types.h"
#include "IdleMgmt.h"
#include "EngSns.h"
#include "EngMgmt.h"
#include "CltFanCtrl_Out.h"
#include "UtilsLookup.h"
#include "IdleOutputs.h"

IdleSpdGovStateEnum IdleSpdGovState;
#define IDLE_START_SEC_CODE
#include "Idle_MemMap.h"

__inline__ boolean IdleChckEnCond(sint16 tps, sint16 rpm)
{
	boolean stend = Get_Eng_bStEnd();
	return (boolean)((tps < Idle_EnThThr_P) & (rpm < Idle_EnThRpm_P) & (stend == TRUE));
}

void IdleSpdGov(void)
{
	register sint16 rpm = (sint16)Get_Eng_Nmot_Rpm();
	register sint16 tps = (sint16)Get_Eng_AThr_Pct();
	register sint16 clt = (sint16)Get_Eng_TClt_DegC();
	register boolean idle_en = IdleChckEnCond(tps, rpm);
	sint16 fan_uplift = (sint16)Get_ClsFanRlySt();
	*Idle_FanUL_Deg_P;
	sint16 trg_rpm;
	sint16 adv_total = 0;
	switch (IdleSpdGovState)
	{
	case Intit:
		IdleSpdGovState = Off;
		break;
	case Off:
		Idle_AdvPid_Deg = 0;
		Idle_AdvBase_Deg = 0;
		if (idle_en)
		{
			IdleSpdGovState = Lock;
		}
		break;
	case Lock:
		if (idle_en)
		{
			if (IdleSpdLockTimo > 0)
			{
				IdleSpdLockTimo--;
			}
			else
			{
				IdleSpdGovState = On;
			}
		}
		else
		{
			IdleSpdGovState = Off;
		}
		break;
	case On:
		if (idle_en)
		{
			Idle_AdvBase_Deg = Ifx_IntIpoMap_i16i16_i16(rpm, clt, CAL_IDLE_COL_SZ, CAL_IDLE_ROW_SZ, Idle_MapRpm_A, Idle_MapClt_A, Idle_MapAdv_M);
			if (Idle_bPidEn_P)
			{
				trg_rpm = Ifx_IntIpoCur_i16_i16((sint16)clt, Idle_TrgRpm_C[0], &Idle_TrgRpm_C[1], &Idle_TrgRpm_C[6]);
				if (trg_rpm - Idle_PidDbRpm_P > rpm)
				{
					Idle_AdvPid_Deg -= 5;
				}
				else if (trg_rpm + Idle_PidDbRpm_P < rpm)
				{
					Idle_AdvPid_Deg += 5;
				}
				if (Idle_AdvPid_Deg > Idle_PidSat_Deg_P)
				{
					Idle_AdvPid_Deg = Idle_PidSat_Deg_P;
				}
				if (Idle_AdvPid_Deg < -Idle_PidSat_Deg_P)
				{
					Idle_AdvPid_Deg = -Idle_PidSat_Deg_P;
				}
			}
			else
			{
				Idle_AdvPid_Deg = 0;
			}
			Idle_LoopTim = Idle_TskPrd_P;
			adv_total = Idle_AdvPid_Deg + fan_uplift + Idle_AdvBase_Deg + Idle_AdvPid_Deg;
		}
		else
		{
			IdleSpdGovState = Off;
		}
		break;
	default:
		break;
	}
	Set_Idle_AdvTotal_Deg(adv_total);
	Set_Idle_bEn(idle_en);
}

#define IDLE_STOP_SEC_CODE
#include "Idle_MemMap.h"