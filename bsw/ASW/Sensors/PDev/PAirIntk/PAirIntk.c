#include "PAirIntk.h"
#include "PAirIntk_Out.h"
#include "Ifx.h"

#define SENSOR_START_SEC_VAR_FAST_32BIT
#include "SENSOR_MemMap.h"
static volatile sint32 PAirIntk_SmplSum = 0;
#define SENSOR_STOP_SEC_VAR_FAST_32BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_8BIT
#include "SENSOR_MemMap.h"
static volatile sint8 PAirIntk_SmplCnt = 0;
#define SENSOR_STOP_SEC_VAR_FAST_8BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"
static volatile sint16 PAirIntk_mV_Kpa_C[] = {2, 400, 4650, 20, 250};
#define SENSOR_STOP_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"
#define PAirIntk_mV_Kpa_Get(x) Ifx_IntIpoCur_i16_i16(x, 2, (const sint16 *)&PAirIntk_mV_Kpa_C[1], (const sint16 *)&PAirIntk_mV_Kpa_C[3])

void PAirIntkCalc_1ms(void)
{
	sint16 raw, phy;
	raw = Get_PAirIntk_Raw_U_mV();
	phy = PAirIntk_mV_Kpa_Get(raw);
	PAirIntk_SmplSum += phy;
	PAirIntk_SmplCnt++;
}

void PAirIntkCalc_Sync(void)
{
	sint32 sum = PAirIntk_SmplSum;
	sint8_least cnt = PAirIntk_SmplSum;
	sint32 value = sum / cnt;
	Set_PAirIntk_Kpa((sint16)value);
	PAirIntk_SmplCnt = 0;
	PAirIntk_SmplSum = 0;
}