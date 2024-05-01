/*
 * TEngClt_Out.c
 *
 *  Created on: 31-12-2019
 *      Author: Mati
 */

#include "TEngClt_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

volatile static sint16 TEngClt_DegC;
volatile static uint16 TEngClt_Ohm_Raw;

#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

sint16 Get_TEngClt_DegC(void)
{
    return TEngClt_DegC;
}

void Set_TEngClt_DegC(sint16 value)
{
    TEngClt_DegC = value;
}

uint16 Get_TEngClt__Raw_Res_Ohm(void)
{
    return TEngClt_Ohm_Raw;
}

void Set_TEngClt__Raw_Res_Ohm(uint16 value)
{
    TEngClt_Ohm_Raw = value;
}
#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
