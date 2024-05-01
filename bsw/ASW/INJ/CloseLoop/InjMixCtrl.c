/*
 * Inj_MixCtrl.c
 *
 *  Created on: Feb 16, 2019
 *      Author: Mati
 */
#ifndef Inj_MixCtrl_C_
#define Inj_MixCtrl_C_
#endif

#include "Std_Types.h"
#include "InjMixCtrl.h"
#include "InjOutputs.h"
#include "EngMgmt.h"
#include "EngSns.h"

#define INJ_START_SEC_CAL_32BIT
#include "ASW_MemMap.h"
const volatile real_t InjAfrModMin_P =-25.0f;
const volatile real_t InjAfrModMax_P =25.0f;
const volatile real_t InjAfrModInc_P = 0.5f;
const volatile real_t InjAfrFiltCoef_P = 0.3f;
#define INJ_STOP_SEC_CAL_32BIT
#include "ASW_MemMap.h"

#define INJ_START_SEC_CAL_UNSPECIFIED
#include "ASW_MemMap.h"
const volatile sint16 InjTrgLam_M[CAL_MAIN_ROW_SZ * CAL_MAIN_COL_SZ] ={ 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 
100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100 };
#define INJ_STOP_SEC_CAL_UNSPECIFIED
#include "ASW_MemMap.h"


#define INJ_START_SEC_CAL_16BIT
#include "ASW_MemMap.h"
const volatile Inj_CLEnCltTh_DegC_P = 60;
const volatile Inj_CLEnDly_P = 5;
#define INJ_STOP_SEC_CAL_16BIT
#include "ASW_MemMap.h"

volatile static sint16 InjCLDelayTimer;
volatile static boolean InjCLEnOld;

boolean InjEnAfr(void)
{
	uint16 row_idx = Get_MainRowAxisIdx();
	uint16 col_idx = Get_MainColAxisIdx();
	sint16 clt = (sint16)Get_Eng_TClt_DegC();
    boolean lsu_en = Get_Eng_Afr_bEn();
	boolean cutoff = Get_Inj_bOffCut();
	register boolean stend = Get_Eng_bStEnd();
    boolean enable = ((clt > Inj_CLEnCltTh_DegC_P) &(cutoff == STD_FALSE)& (lsu_en == STD_TRUE) & (stend== STD_TRUE));
    if ((enable == STD_TRUE) & (InjCLEnOld == STD_FALSE))
    {
        InjCLDelayTimer = Inj_CLEnDly_P;
    }
    else if (InjCLDelayTimer >0)
    {
        InjCLDelayTimer--;
    }
    InjCLEnOld = enable;
	return ((InjCLDelayTimer == 0) && enable);
}
void InjCalcAfrMod(void)
{
	static real_t afr_old;
	real_t afr_filt;
	real_t mod = Get_Inj_AfrMod();
	real_t afr = Get_Eng_Afr_Meas();
	boolean en = InjEnAfr();
	if(en == STD_TRUE)
	{
		afr_filt = afr*InjAfrFiltCoef_P + (1-InjAfrFiltCoef_P)*afr_old;
		if (afr_filt > 1.02f)
		{
			mod+=InjAfrModInc_P;
		}
		else if( afr_filt < 0.98f)
		{
			mod-=InjAfrModInc_P;
		}
		
		if (mod < InjAfrModMin_P)
		{
			mod = InjAfrModMin_P;
		}
		
		if (mod > InjAfrModMax_P)
		{
			mod = InjAfrModMax_P;
		}
		
		Set_Inj_AfrMod(mod);
	}
	else
	{
		Set_Inj_AfrMod(0);
	}
	afr_old = afr;
}

#ifdef Inj_MixCtrl_C_
#undef Inj_MixCtrl_C_
#endif
