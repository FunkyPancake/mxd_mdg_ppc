#include "PEngOil.h"
#include "PEngOil_Out.h"
#include "Ifx.h"
/*Calibration parameters*/
#define SENSOR_START_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"
const volatile sint16 PEngOil_DefVal_Kpa_P = 500;
const volatile sint16 PEngOil_mV2Kpa_C[] = {
	2, 500, 4500, 0, 1000};
#define SENSOR_STOP_SEC_VAR_CAL_16BIT
#include "SENSOR_MemMap.h"

#define PEngOil_mV_Kpa_Get(x) (Ifx_IntIpoCur_i16_i16(x, 2, (const sint16 *)&(PEngOil_mV2Kpa_C[1]), (const sint16 *)&(PEngOil_mV2Kpa_C[3])))

#define SENSOR_START_SEC_CODE
#include "SENSOR_MemMap.h"

inline boolean PEngOilDiag(sint16 raw_value)
{
	PARAM_UNUSED(raw_value);
	return TRUE;
}
void PEngOilCalc(void)
{
	sint16 oil_raw = Get_PEngOil_Raw_U_mV();
	boolean is_valid = PEngOilDiag(oil_raw);
	sint16 oil_phy = PEngOil_mV_Kpa_Get(oil_raw);
	if (!is_valid)
	{
		oil_phy = PEngOil_DefVal_Kpa_P;
	}
	Set_PEngOil_Kpa(oil_phy);
}
#define SENSOR_STOP_SEC_CODE
#include "SENSOR_MemMap.h"
