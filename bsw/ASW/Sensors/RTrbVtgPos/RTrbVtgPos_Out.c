#include "RTrbVtgPos_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"
static volatile sint16 RTrbVtgPos_Pct;
static volatile sint16 RTrbVtgPos_Raw_U_mV;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"
static volatile uint8 RTrbVtgPos_Err;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void Set_RTrbVtgPos_Pct(sint16 value)
{
    RTrbVtgPos_Pct = value;
}

void Set_RTrbVtgPos_Raw_U_mV(sint16 value)
{
    RTrbVtgPos_Raw_U_mV = value;
}

void Set_RTrbVtgPos_Err(uint8 value)
{
    RTrbVtgPos_Err = value;
}

sint16 Get_RTrbVtgPos_Pct(void)
{
    return RTrbVtgPos_Pct;
}

sint16 Get_RTrbVtgPos_Raw_U_mV(void)
{
    return RTrbVtgPos_Raw_U_mV;
}

uint8 Get_RTrbVtgPos_Err(void)
{
    return RTrbVtgPos_Err;
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"