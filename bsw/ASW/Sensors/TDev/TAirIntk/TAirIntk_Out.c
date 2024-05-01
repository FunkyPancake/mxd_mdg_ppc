/*
 * TAirIntk_Out.c
 *
 *  Created on: 31-12-2019
 *      Author: Mati
 */

#include "TAirIntk_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

volatile static sint16 TAirIntk_DegC;
volatile static uint16 TAirIntk_Ohm_Raw;

#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

sint16 Get_TAirIntk_DegC(void)
{
    return TAirIntk_DegC;
}

void Set_TAirIntk_DegC(sint16 value)
{
    TAirIntk_DegC = value;
}

uint16 Get_TAirIntk__Raw_Res_Ohm(void)
{
    return TAirIntk_Ohm_Raw;
}

void Set_TAirIntk__Raw_Res_Ohm(uint16 value)
{
    TAirIntk_Ohm_Raw = value;
}
#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
