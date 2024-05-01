#include "PBrkServo_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"
volatile static sint16 PBrkServo_Vac_Kpa;
volatile static sint16 PBrkServo_Raw_U_mV;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"
static volatile uint8 PBrkServo_Err;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void Set_PBrkServo_Vac_Kpa(sint16 value)
{
    PBrkServo_Vac_Kpa = value;
}

void Set_PBrkServo_Raw_U_mV(sint16 value)
{
    PBrkServo_Raw_U_mV = value;
}

void Set_PBrkServo_Err(uint8 value)
{
    PBrkServo_Err = value;
}

sint16 Get_PBrkServo_Vac_Kpa(void)
{
    return PBrkServo_Vac_Kpa;
}

sint16 Get_PBrkServo_Raw_U_mV(void)
{
    return PBrkServo_Raw_U_mV;
}

uint8 Get_PBrkServo_Err(void)
{
    return PBrkServo_Err;
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
