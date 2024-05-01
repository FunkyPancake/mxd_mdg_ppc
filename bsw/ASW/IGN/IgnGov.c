/*
 * IgnGov.c
 *
 *  Created on: Dec 20, 2018
 *      Author: Mati
 */

#include "Std_Types.h"
#include "IgnGov.h"
#include "Ifx.h"
#include "IgnGov_Out.h"
#include "IdleCtrl_Out.h"
#include "EngEpm_Out.h"
/*
 * Default calibration values
 */
#define IGN_START_SEC_CAL_16BIT
#include "IGN_MemMap.h"
const volatile sint16 Ign_AdvCrank_Deg_P = 100;
#define IGN_STOP_SEC_CAL_16BIT
#include "IGN_MemMap.h"


#define IGN_START_SEC_CAL_UNSPECIFIED
#include "IGN_MemMap.h"

const volatile sint16 Ign_Ubat_V_DwlTme_us_C[] = {5,600,700,800,1200,1300,3000,3000,2700,2500,2500};
Ifx_IntIpoCur_i16_i16(vbat,Ign_Ubat_V_DwlTme_us_C[0],&Ign_Ubat_V_DwlTme_us_C[1],&Ign_Ubat_V_DwlTme_us_C[6]);


const volatile sint16 Ign_AdvBase_Deg_M[CAL_MAIN_ROW_SZ * CAL_MAIN_COL_SZ] ={ 
80, 95, 114, 138, 162, 165, 175, 188, 202, 215, 228, 255, 283, 289, 310, 310, 310, 310, 310, 310, 
85, 95, 114, 138, 162,165, 175, 188, 202, 215, 228, 230, 282, 310, 310, 310, 310,310, 310, 310,
77, 94, 114, 138, 162, 166, 185, 201, 210,	218, 229, 224, 276, 310, 310, 310, 310, 310, 310, 310,
100, 108, 114, 138, 162, 167, 194, 213, 217, 220, 229, 241, 262, 288, 288, 288, 288, 288, 288, 288, 
100, 100, 114, 138, 162,167, 189, 210, 230, 238, 241, 250, 256, 301, 288, 288, 288, 288, 288, 288, 
100, 100, 114, 138, 162, 167, 189, 211, 221, 217, 238, 253, 252, 280, 281, 288, 288, 288, 288, 288, 
100, 100, 114, 138, 162, 167, 189, 207, 210, 224, 229, 233, 247, 257, 253, 269, 269, 269, 277, 277, 
100, 100, 114, 150, 169, 193, 205, 215, 206, 235, 245, 257, 241, 266, 250, 257, 261,259, 263, 273, 
100, 100, 114, 138, 195, 218, 254, 259, 266, 271, 294, 287, 289, 280, 280, 280, 280, 280, 284, 284, 
100, 100, 114, 131, 228, 250, 297, 301, 303, 308, 316, 330, 334, 330, 330, 330, 330, 330, 330, 330,
100, 100, 100, 133, 223, 248, 288, 304, 316, 308, 307, 335, 332, 330, 330, 330, 330, 330, 330, 330,
100, 100, 100, 138, 214, 241, 264, 287, 318, 308, 310, 334, 334, 330, 330, 330, 330, 330, 330, 330, 
100, 100, 100, 138, 190, 223, 255, 283, 318, 307, 314, 334, 332, 330, 330, 330, 330, 330, 330, 330,
100, 100, 100, 139, 186, 221, 253, 270, 314, 307, 316, 332, 334, 330, 330, 330, 330,330, 330, 330 
};
#define IGN_STOP_SEC_CAL_UNSPECIFIED
#include "IGN_MemMap.h"


void IgnAdvGov(void)
{
	boolean end_of_start = Get_EngEpmStEnd();
	boolean idle_en = Get_IdleSpdGovEn();
	sint16 load = Get_EngLoad();
	sint16 rpm = Get_EpmRpm();
	sint16 adv_base;
	sint16 ign_adv;
	switch(IgnAdvGovState)
	{
		case Init:
			if(end_of_start == STD_TRUE)
			{
				IgnAdvGovState = Normal;
			}
			else
			{
				IgnAdvGovState = Startup;
			}
			break;
		case Startup:
			ign_adv = (sint16) (Ign_AdvCrank_Deg_P);
			if(end_of_start == STD_TRUE)
			{
				IgnAdvGovState = Normal;
			}
			break;
		case Normal:
			if (idle_en == STD_ACTIVE)
			{
				adv_base = Get_IdleIgnAdv();
			}
			else
			{
				adv_base = IgnAdvBse_Get(load,rpm);
			}
			ign_adv = (sint16) (adv_base);
			break;
		case Overrrun:
			break;
		default:
			break;
	}
	Set_IgnAdv_Deg(ign_adv);
}


void IgnDwlTmeCalc(void)
{
	sint16 dwell;
	sint16 vbat = Get_USup_Ubat_V();
	dwell = Ign_Ubat_V_DwlTme_us_Get(vbat);
	Set_IgnDwl_uSec(dwell);
}
