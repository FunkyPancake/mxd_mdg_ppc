#include "RIntkThr_Out.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

volatile static sint16 RIntkThr_Raw_U_mV;
volatile static sint16 RIntkThr_Pct;

#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"
static volatile uint8 RIntkThr_Err;
#define SENSOR_STOP_SEC_VAR_FAST_NOINIT_8BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void Set_RIntkThr_Pct(sint16 value)
{
    RIntkThr_Pct = value;
}

void Set_RIntkThr_Raw_U_mV(sint16 value)
{
    RIntkThr_Raw_U_mV = value;
}
void Set_RIntkThr_Err(uint8 value)
{
    RIntkThr_Err = value;
}

sint16 Get_RIntkThr_Pct(void)
{
    return RIntkThr_Pct;
}

sint16 Get_RIntkThr_Raw_U_mV(void)
{
    return RIntkThr_Raw_U_mV;
}
uint8 Get_RIntkThr_Err(void)
{
    return RIntkThr_Err;
}

#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
