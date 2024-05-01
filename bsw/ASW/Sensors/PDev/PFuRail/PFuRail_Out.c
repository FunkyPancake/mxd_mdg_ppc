#include "PFuRail_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

volatile static sint16 PFuRail_Kpa;
volatile static sint16 PFuRail_Raw_U_mV;

#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"
static volatile uint8 PFuRail_Err;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void Set_PFuRail_Kpa(sint16 value)
{
    PFuRail_Kpa = value;
}

void Set_PFuRail_Raw_U_mV(sint16 value)
{
    PFuRail_Raw_U_mV = value;
}

void Set_PFuRail_Err(uint8 value)
{
    PFuRail_Err = value;
}

sint16 Get_PFuRail_Kpa(void)
{
    return PFuRail_Kpa;
}

sint16 Get_PFuRail_Raw_U_mV(void)
{
    return PFuRail_Raw_U_mV;
}

uint8 Get_PFuRail_Err(void)
{
    return PFuRail_Err;
}
#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
