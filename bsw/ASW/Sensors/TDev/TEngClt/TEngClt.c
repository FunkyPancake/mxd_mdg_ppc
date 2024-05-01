/*
 * TEngClt.c
 *
 *  Created on: 31-12-2019
 *      Author: Mati
 */

#include "TEngClt.h"
#include "TEngClt_Out.h"
#include "NTC12_Cal.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void TEngCltCalc(void)
{
    float32 temp;
    float32 res;
    res = (float32)Get_TEngClt__Raw_Res_Ohm();
    temp = NtcM12_Ohm_DegC_Get(res);
    Set_TEngClt_DegC((sint16)temp);
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
