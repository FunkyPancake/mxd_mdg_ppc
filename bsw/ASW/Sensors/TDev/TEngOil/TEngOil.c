/*
 * TEngOil.c
 *
 *  Created on: 31-12-2019
 *      Author: Mati
 */

#include "TEngOil.h"
#include "TEngOil_Out.h"
#include "NTC12_Cal.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void TEngOilCalc(void)
{
    float32 temp;
    float32 res;
    res = (float32)Get_TEngOil__Raw_Res_Ohm();
    temp = NtcM12_Ohm_DegC_Get(res);
    Set_TEngOil_DegC((sint16)temp);
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
