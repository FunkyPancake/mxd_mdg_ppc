/*
 * IdleOutputs.c
 *
 *  Created on: May 2, 2019
 *      Author: Mati
 */
#ifndef IdleOutputs_C_
#define IdleOutputs_C_
#endif

#include "Std_Types.h"
#include "IdleOutputs.h"


#define IDLE_START_SEC_VAR_FAST_16BIT
#include "ASW_MemMap.h"
volatile static sint16 Idle_AdvTotal_Deg;
#define IDLE_STOP_SEC_VAR_FAST_16BIT
#include "ASW_MemMap.h"


#define IDLE_START_SEC_VAR_FAST_8BIT
#include "ASW_MemMap.h"
volatile static boolean Idle_bEn;
#define IDLE_STOP_SEC_VAR_FAST_8BIT
#include "ASW_MemMap.h"



sint16 Get_Idle_AdvTotal_Deg(void)
{
	return Idle_AdvTotal_Deg;
}

void Set_Idle_AdvTotal_Deg(sint16 x)
{
	Idle_AdvTotal_Deg = x;
}

boolean Get_Idle_bEn(void)
{
	return Idle_bEn;
}

void Set_Idle_bEn(boolean x)
{
	Idle_bEn = x;
}
