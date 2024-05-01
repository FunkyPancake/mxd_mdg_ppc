#include "FAirIntk_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"
static volatile sint16 FAirIntk_Kgh;
static volatile sint16 FAirIntk_Raw_U_mV;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"
static volatile uint8 FAirIntk_Err;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"
void Set_FAirIntk_Kgh(float32 value)
{
	FAirIntk_Kgh = (sint16)(value * 10);
}
void Set_FAirIntk_Raw_U_mV(sint16 value)
{
	FAirIntk_Raw_U_mV = value;
}
void Set_FAirIntk_Err(uint8 value)
{
	FAirIntk_Err = value;
}

sint16 Get_FAirIntk_Kgh(void)
{
	return FAirIntk_Kgh;
}

sint16 Get_FAirIntk_Raw_U_mV(void)
{
	return FAirIntk_Raw_U_mV;
}

uint8 Get_FAirIntk_Err(void)
{
	return FAirIntk_Err;
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"