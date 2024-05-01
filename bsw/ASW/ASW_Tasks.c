/*
 * AswTasks.c
 *
 *  Created on: Feb 17, 2019
 *      Author: Mati
 */

#include "ASW_Tasks.h"

/*Sensors*/
#include "TAirIntk.h"
#include "TEngOil.h"
#include "TEngClt.h"
#include "RIntkThr.h"
#include "PEngOil.h"
#include "RTrbVtgPos.h"
#include "PFuRail.h"

/*Actuators*/
#include "TrbChgVtgActr.h"

//#include "InjMgmt.h"
//#include "IdleMgmt.h"
//#include "IgnMgmt.h"
// #include "CltFanCtrl.h"
// #include "BrkVacPmpCtrl.h"
// #include "FuPmpCtrl.h"
//#include "InjMixCtrl.h"
void Task_ASW_1ms(void)
{
	RIntkThrCalc();
}
void Task_ASW_Sync(void)
{
}
void Task_ASW_20ms(void)
{
	RTrbVtgPosCalc();
	PEngOilCalc();
	PFuRailCalc();

	TrbChgVtgActrCtrl();
	// TrbChgDivVlvCtrl();
}

void Task_ASW_100ms(void)
{
	TAirIntkCalc();
	TEngCltCalc();
	TEngOilCalc();
	// FuPmpCtrl();
	// ClsFanCtrl();
	// BrkVacPmpCtrl();

	//	IgnCalcDwellTime();
	//	InjCalcDeadTime();
	//	IdleMgmt();
	//	InjCalcAfrMod();
}

void StartupHook_ASW(void)
{
	;
}
