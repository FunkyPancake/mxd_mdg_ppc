#include "RTrbVtgPos.h"
#include "RTrbVtgPos_Out.h"
#include "Ifx.h"
/*Calibration parameters*/
#define SENSOR_START_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"
const volatile sint16 RTrbVtgPos_mV_Pct_C[] = {
    2, 500, 4500, 0, 1000};
#define SENSOR_STOP_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"

#define RTrbVtgPos_mV_Pct_Get(x) (Ifx_IntIpoCur_i16_i16(x, 2, (const sint16 *)&(RTrbVtgPos_mV_Pct_C[1]), (const sint16 *)&(RTrbVtgPos_mV_Pct_C[3])))

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

void RTrbVtgPosCalc(void)
{
    sint16 raw = Get_RTrbVtgPos_Raw_U_mV();
    sint16 phy = RTrbVtgPos_mV_Pct_Get(raw);
    Set_RTrbVtgPos_Pct(phy);
}
#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
