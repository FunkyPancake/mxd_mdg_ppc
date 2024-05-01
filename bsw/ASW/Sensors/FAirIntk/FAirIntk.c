/*
 * FAIRINTK.c
 * 
 *
 *  Created on: Apr 4, 2019
 *      Author: Mati
 */
#include "FAirIntk.h"
#include "FAirIntk_Out.h"
#include "Ifl.h"

#define SENSOR_START_SEC_VAR_CAL_32BIT
#include "SENSOR_MemMap.h"
const volatile float32 FAirIntk_mV_Kgh_C[] = {8, 1.4837, 1.5819, 1.7898, 2.2739, 2.8868, 3.6255, 4.4727, 4.9406, 8, 10, 15, 30, 60, 120, 250, 370};
#define FAirIntk_mV_Kgh_Get(x) Ifl_IntIpoCur_f32_f32(x, (uint32)FAirIntk_mV_Kgh_C[0], (float *)&FAirIntk_mV_Kgh_C[1], (float *)&FAirIntk_mV_Kgh_C[9])

#define SENSOR_STOP_SEC_VAR_CAL_32BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_32BIT
#include "SENSOR_MemMap.h"
static volatile float32 FAirIntk_SmplSum = 0.0f;
#define SENSOR_STOP_SEC_VAR_FAST_32BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_8BIT
#include "SENSOR_MemMap.h"
static volatile uint8 FAirIntk_SmplCnt = 0;
#define SENSOR_STOP_SEC_VAR_FAST_8BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

static void Rst_FAirIntk_SmplSum(void)
{
	FAirIntk_SmplSum = 0;
	FAirIntk_SmplCnt = 0;
}

static void Add_FAirIntk_SmplSum(float32 value)
{
	FAirIntk_SmplSum += value;
	FAirIntk_SmplCnt++;
}
static float32 Get_FAirIntk_SmplSum(void)
{
	return FAirIntk_SmplSum;
}
static uint8 Get_FAirIntk_SmplCnt(void)
{
	return FAirIntk_SmplCnt;
}

void FAirIntkCalc_1ms(void)
{
	float32 maf_cur, maf_raw;
	maf_raw = (float32)Get_FAirIntk_Raw_U_mV() / 1000;
	maf_cur = FAirIntk_mV_Kgh_Get(maf_raw);
	Add_FAirIntk_SmplSum(maf_cur);
}

void FAirIntkCalc_Sync(void)
{
	float32 sum = Get_FAirIntk_SmplSum();
	sint8_least cnt = Get_FAirIntk_SmplCnt();
	float32 value = sum / cnt;
	Set_FAirIntk_Kgh(value);
	Rst_FAirIntk_SmplSum();
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"