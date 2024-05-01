/*
 * NTC12_Cal.c
 *
 *  Created on: 31-12-2019
 *      Author: Mati
 */

#include "NTC12_Cal.h"
#include "Ifl.h"
#define CAL_NTC_LEN 18

#define SENSOR_START_SEC_VAR_CAL_32BIT
#include "SENSOR_MemMap.h"

const volatile float32 NtcM12_Ohm_DegC_C[2 * CAL_NTC_LEN + 1] = {
    CAL_NTC_LEN, 45313, 26114, 15462, 9397, 5896, 3792, 2500, 1707, 1175, 834, 596, 436, 323,
    243, 187, 144, 113, 89, -40, -30, -20, -10, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110,
    120, 130};

#define SENSOR_STOP_SEC_VAR_CAL_32BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

float32 NtcM12_Ohm_DegC_Get(float32 res)
{
    return Ifl_IntIpoCur_f32_f32(res, (uint32)NtcM12_Ohm_DegC_C[0], (const float32 *)&NtcM12_Ohm_DegC_C[1], (const float32 *)&NtcM12_Ohm_DegC_C[CAL_NTC_LEN + 1]);
}
#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"
