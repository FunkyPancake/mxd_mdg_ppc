#ifndef Il_an_H_
#define Il_an_H_

#include "Std_Types.h"

/*Mapping Functions*/
inline void IL_An_Pin1_U_mV_FAirHfm_Raw_U_mV(void);
inline void IL_An_Pin2_U_mV_PAirIntk_Raw_U_mV(void);
inline void IL_An_Pin3_U_mV_RIntkThr_Raw_U_mV(void);
inline void IL_An_Pin4_Res_Ohm_TEngOil__Raw_Res_Ohm(void);
inline void IL_An_Pin8_U_mV_RInjAfr_Raw_U_mV(void);
inline void IL_An_Pin9_Res_Ohm_TAirIntk__Raw_Res_Ohm(void);
inline void IL_An_Pin17_Res_Ohm_TEngClt__Raw_Res_Ohm(void);
inline void IL_An_Pin18_U_mV_PBrkServo_Raw_U_mV(void);
inline void IL_An_Pin23_U_mV_PFuRail_Raw_U_mV(void);
inline void IL_An_Pin24_U_mV_PEngOil_Raw_U_mV(void);
inline void IL_An_Pin25_U_mV_TExhGas_Raw_U_mV(void);
inline void IL_An_KL30_U_mV_UKl30_Raw_U_mV(void);
inline void IL_An_TempSns_U_mV_TPcb_Raw_U_mV(void);

/*Grouped Mapping By Time Raster*/
void IL_An_100ms(void);
void IL_An_1ms(void);
void IL_An_20ms(void);

#endif /*Il_an_H_*/