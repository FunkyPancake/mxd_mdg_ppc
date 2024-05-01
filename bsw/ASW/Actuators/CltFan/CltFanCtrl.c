/*
 * CltFanCtrl.c
 *
 *  Created on: May 2, 2019
 *      Author: Mati
 */

#include "CltFanCtrl.h"
#include "CltFanCtrl_Out.h"
#include "EngOutCltTp.h"


#include "EngSns.h"
#define ACTR_START_SEC_CAL_8BIT
#include "ACTR_MemMap.h"
	const volatile boolean ClsFanRlyOvrEn_P = 0;
	const volatile boolean ClsFanRlyOvr_P = 0;
#define ACTR_STOP_SEC_CAL_8BIT
#include "ACTR_MemMap.h"
 
#define ACTR_START_SEC_CAL_16BIT
#include "ACTR_MemMap.h"
	const volatile sint16 ClsFanThTempDegC_P = 90;
	const volatile sint16 ClsFanHysTempDegC_P = 3;
#define ACTR_STOP_SEC_CAL_16BIT
#include "ACTR_MemMap.h"
 
	
#define ACTR_START_SEC_VAR_FAST_UNSPECIFIED
#include "ACTR_MemMap.h"
	volatile static CltFanCtrlStateEnum CltFanCtrlState;
#define ACTR_STOP_SEC_VAR_FAST_UNSPECIFIED
#include "ACTR_MemMap.h"	

void CltFanCtrl(void)
{
	sint16 clt_temp = (sint16)Get_Eng_TClt_DegC();
	boolean output;
	switch (CltFanCtrlState)
	{
		case Init:
			break;
		case Off:
			output = STD_IDLE;
			if(clt_temp >= ClsFanThTempDegC_P)
			{
				CltFanCtrlState = On;
			}            
			break;
		case On:
			output = STD_ACTIVE;
			if(clt_temp <= (ClsFanThTempDegC_P - ClsFanHysTempDegC_P))
			{
				CltFanCtrlState = Off;
			}            
			break;        
		default:
			output = STD_IDLE;
			Set_ClsFanState = Init;
			break;
	}
	if (ClsFanRlyOvrEn_P)
		output = ClsFanRlyOvr_P;
	Set_CltFanRlySt(output);
}
