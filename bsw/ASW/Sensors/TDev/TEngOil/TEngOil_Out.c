/*
 * TEngOil_Out.c
 *
 *  Created on: 31-12-2019
 *      Author: Mati
 */

#include "TEngOil_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

volatile static sint16 TEngOil_DegC;
volatile static uint16 TEngOil_Ohm_Raw;

#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

sint16 Get_TEngOil_DegC(void)
{
    return TEngOil_DegC;
}

void Set_TEngOil_DegC(sint16 value)
{
    TEngOil_DegC = value;
}

uint16 Get_TEngOil__Raw_Res_Ohm(void)
{
    return TEngOil_Ohm_Raw;
}

void Set_TEngOil__Raw_Res_Ohm(uint16 value)
{
    TEngOil_Ohm_Raw = value;
}
#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
