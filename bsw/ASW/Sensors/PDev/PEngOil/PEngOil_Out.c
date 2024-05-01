#include "PEngOil_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

volatile static sint16 PEngOil_Kpa;
volatile static sint16 PEngOil_Raw_U_mV;

#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"
static volatile uint8 PEngOil_Err;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void Set_PEngOil_Kpa(sint16 value)
{
    PEngOil_Kpa = value;
}

void Set_PEngOil_Raw_U_mV(sint16 value)
{
    PEngOil_Raw_U_mV = value;
}

void Set_PEngOil_Err(uint8 value)
{
    PEngOil_Err = value;
}

sint16 Get_PEngOil_Kpa(void)
{
    return PEngOil_Kpa;
}

sint16 Get_PEngOil_Raw_U_mV(void)
{
    return PEngOil_Raw_U_mV;
}

uint8 Get_PEngOil_Err(void)
{
    return PEngOil_Err;
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
