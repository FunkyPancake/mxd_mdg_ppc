#include "RIntkThr.h"
#include "RIntkThr_Out.h"

static boolean RIntkThrDiag(sint16 raw_value);

#define SENSOR_START_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"
const volatile sint16 RIntkThr_ThHigh_mV_P = 4470;
const volatile sint16 RIntkThr_ThLow_mV_P = 490;
#define SENSOR_STOP_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

static boolean RIntkThrDiag(sint16 raw_value)
{
    PARAM_UNUSED(raw_value);
    return TRUE;
}
void RIntkThrCalc(void)
{
    sint16 raw = Get_RIntkThr_Raw_U_mV();
    sint16 phy = 0;
    boolean is_valid = RIntkThrDiag(raw);
    if (!is_valid)
    {
        if (raw < RIntkThr_ThLow_mV_P)
        {
            phy = RIntkThr_ThLow_mV_P;
        }
        else if (raw > RIntkThr_ThHigh_mV_P)
        {
            phy = RIntkThr_ThHigh_mV_P;
        }
        else
        {
            phy = (sint16)((sint32)((raw - RIntkThr_ThLow_mV_P) * 100) / (RIntkThr_ThHigh_mV_P - RIntkThr_ThLow_mV_P));
        }
    }
    Set_RIntkThr_Pct(phy);
}
#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
