#ifndef EQADC_OUT_H_
#define EQADC_OUT_H_

#include "Std_Types.h"

//Setters
void Set_An_Pin1_U_mV(uint16 value);
void Set_An_Pin2_U_mV(uint16 value);
void Set_An_Pin3_U_mV(uint16 value);
void Set_An_Pin4_Res_Ohm(uint16 value);
void Set_An_Pin8_U_mV(uint16 value);
void Set_An_Pin9_Res_Ohm(uint16 value);
void Set_An_Pin17_Res_Ohm(uint16 value);
void Set_An_Pin18_U_mV(uint16 value);
void Set_An_Pin23_U_mV(uint16 value);
void Set_An_Pin24_U_mV(uint16 value);
void Set_An_Pin25_U_mV(uint16 value);
void Set_An_KL30_U_mV(uint16 value);
void Set_An_TempSns_U_mV(uint16 value);

//Getters
uint16 Get_An_Pin1_U_mV(void);
uint16 Get_An_Pin2_U_mV(void);
uint16 Get_An_Pin3_U_mV(void);
uint16 Get_An_Pin4_Res_Ohm(void);
uint16 Get_An_Pin8_U_mV(void);
uint16 Get_An_Pin9_Res_Ohm(void);
uint16 Get_An_Pin17_Res_Ohm(void);
uint16 Get_An_Pin18_U_mV(void);
uint16 Get_An_Pin23_U_mV(void);
uint16 Get_An_Pin24_U_mV(void);
uint16 Get_An_Pin25_U_mV(void);
uint16 Get_An_KL30_U_mV(void);
uint16 Get_An_TempSns_U_mV(void);

#endif /*EQADC_OUT_H_*/
