#include "PAirIntk_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"
static volatile sint16 PAirIntk_Kpa;
static volatile sint16 PAirIntk_Raw_U_mV;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"
static volatile uint8 PAirIntk_Err;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void Set_PAirIntk_Kpa(sint16 value)
{
	PAirIntk_Kpa = (value);
}

void Set_PAirIntk_Raw_U_mV(sint16 value)
{
	PAirIntk_Raw_U_mV = value;
}

void Set_PAirIntk_Err(uint8 value)
{
	PAirIntk_Err = value;
}

sint16 Get_PAirIntk_Kpa(void)
{
	return PAirIntk_Kpa;
}

sint16 Get_PAirIntk_Raw_U_mV(void)
{
	return PAirIntk_Raw_U_mV;
}

uint8 Get_PAirIntk_Err(void)
{
	return PAirIntk_Err;
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"