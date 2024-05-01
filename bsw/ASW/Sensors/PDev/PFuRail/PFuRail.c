#include "PFuRail.h"
#include "PFuRail_Out.h"
#include "Ifx.h"
/*Calibration parameters*/
#define SENSOR_START_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"
const volatile sint16 PFuRail_DefVal_Kpa = 500;
const volatile sint16 PFuRail_mV2Kpa_C[] = {
	2, 500, 4500, 0, 1000};
#define SENSOR_STOP_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"

#define PFuRail_mV2Kpa_Get(x) (Ifx_IntIpoCur_i16_i16(x, 2, (const sint16 *)&(PFuRail_mV2Kpa_C[1]), (const sint16 *)&(PFuRail_mV2Kpa_C[3])))

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

inline boolean PFuRailDiag(sint16 raw_value)
{
	PARAM_UNUSED(raw_value);
	return TRUE;
}
void PFuRailCalc(void)
{
	sint16 oil_raw = Get_PFuRail_Raw_U_mV();
	boolean is_valid = PFuRailDiag(oil_raw);
	sint16 oil_phy = PFuRail_mV2Kpa_Get(oil_raw);
	if (!is_valid)
	{
		oil_phy = PFuRail_DefVal_Kpa;
	}
	Set_PFuRail_Kpa(oil_phy);
}
#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
