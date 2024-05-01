/*
 * TAirIntk.c
 *
 *  Created on: 31-12-2019
 *      Author: Mati
 */

#include "TAirIntk.h"
#include "TAirIntk_Out.h"
#include "NTC12_Cal.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void TAirIntkCalc(void)
{
    float32 temp;
    float32 res;
    res = (float32)Get_TAirIntk__Raw_Res_Ohm();
    temp = NtcM12_Ohm_DegC_Get(res);
    Set_TAirIntk_DegC((sint16)temp);
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
