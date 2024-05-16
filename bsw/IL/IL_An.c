#include "IL_An.h"

/*Module includes*/
#include "RIntkThr_Out.h"
#include "EQADC_Out.h"
//#include "FAirHfm_Out.h"
//#include "Hego_Out.h"
#include "PAirIntk_Out.h"
#include "PBrkServo_Out.h"
#include "PEngOil_Out.h"
#include "PFuRail_Out.h"
#include "TAirIntk_Out.h"
#include "TEngClt_Out.h"
#include "TEngOil_Out.h"
#include "RTrbVtgPos_Out.h"
//#include "TExhGas_Out.h"
//#include "USup_Out.h"

#define IL_START_SEC_CODE
#include "IL_MemMap.h"

/*Mapping Functions*/

inline void IL_An_Pin1_U_mV_FAirHfm_Raw_U_mV(void)
{
    uint16 value = Get_An_Pin1_U_mV();
    Set_RTrbVtgPos_Raw_U_mV((sint16)value);

    //    Set_FAirHfm_Raw_U_mV((sint16)value);
}
inline void IL_An_Pin2_U_mV_PAirIntk_Raw_U_mV(void)
{
    uint16 value = Get_An_Pin2_U_mV();
    Set_PAirIntk_Raw_U_mV((sint16)value);
}
inline void IL_An_Pin3_U_mV_RIntkThr_Raw_U_mV(void)
{
    uint16 value = Get_An_Pin3_U_mV();
    Set_RIntkThr_Raw_U_mV((sint16)value);
}
inline void IL_An_Pin4_Res_Ohm_TEngOil__Raw_Res_Ohm(void)
{
    uint16 value = Get_An_Pin4_Res_Ohm();
    Set_TEngOil__Raw_Res_Ohm((uint16)value);
}
inline void IL_An_Pin8_U_mV_RInjAfr_Raw_U_mV(void)
{
    uint16 value = Get_An_Pin8_U_mV();
    //    Set_RInjAfr_Raw_U_mV((sint16)value);
}
inline void IL_An_Pin9_Res_Ohm_TAirIntk__Raw_Res_Ohm(void)
{
    uint16 value = Get_An_Pin9_Res_Ohm();
    Set_TAirIntk__Raw_Res_Ohm((uint16)value);
}
inline void IL_An_Pin17_Res_Ohm_TEngClt__Raw_Res_Ohm(void)
{
    uint16 value = Get_An_Pin17_Res_Ohm();
    Set_TEngClt__Raw_Res_Ohm((uint16)value);
}
inline void IL_An_Pin18_U_mV_PBrkServo_Raw_U_mV(void)
{
    uint16 value = Get_An_Pin18_U_mV();
    Set_PBrkServo_Raw_U_mV((sint16)value);
}
inline void IL_An_Pin23_U_mV_PFuRail_Raw_U_mV(void)
{
    uint16 value = Get_An_Pin23_U_mV();
    // Set_PFuRail_Raw_U_mV((sint16)value);
    // Set_RTrbVtgPos_Raw_U_mV((sint16)value);
}
inline void IL_An_Pin24_U_mV_PEngOil_Raw_U_mV(void)
{
    uint16 value = Get_An_Pin24_U_mV();
    Set_PEngOil_Raw_U_mV((sint16)value);
}
inline void IL_An_Pin25_U_mV_TExhGas_Raw_U_mV(void)
{
    uint16 value = Get_An_Pin25_U_mV();
    //    Set_TExhGas_Raw_U_mV((sint16)value);
}
inline void IL_An_KL30_U_mV_UKl30_Raw_U_mV(void)
{
    uint16 value = Get_An_KL30_U_mV();
    //    Set_UKl30_Raw_U_mV((sint16)value);
}
inline void IL_An_TempSns_U_mV_TPcb_Raw_U_mV(void)
{
    uint16 value = Get_An_TempSns_U_mV();
    //    Set_TPcb_Raw_U_mV((sint16)value);
}

/*Grouped Mapping By Time Raster*/

void IL_An_100ms(void)
{
    IL_An_Pin4_Res_Ohm_TEngOil__Raw_Res_Ohm();
    IL_An_Pin9_Res_Ohm_TAirIntk__Raw_Res_Ohm();
    IL_An_Pin17_Res_Ohm_TEngClt__Raw_Res_Ohm();
    IL_An_KL30_U_mV_UKl30_Raw_U_mV();
    IL_An_TempSns_U_mV_TPcb_Raw_U_mV();
}
void IL_An_1ms(void)
{
    IL_An_Pin1_U_mV_FAirHfm_Raw_U_mV();
    IL_An_Pin2_U_mV_PAirIntk_Raw_U_mV();
    IL_An_Pin3_U_mV_RIntkThr_Raw_U_mV();
    IL_An_Pin8_U_mV_RInjAfr_Raw_U_mV();
}
void IL_An_20ms(void)
{
    IL_An_Pin18_U_mV_PBrkServo_Raw_U_mV();
    IL_An_Pin23_U_mV_PFuRail_Raw_U_mV();
    IL_An_Pin24_U_mV_PEngOil_Raw_U_mV();
    IL_An_Pin25_U_mV_TExhGas_Raw_U_mV();
}

#define IL_STOP_SEC_CODE
#include "IL_MemMap.h"
