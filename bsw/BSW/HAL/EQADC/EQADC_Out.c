#include "EQADC_Out.h"

#define BSW_START_SEC_VAR_FAST_NOINIT_16BIT
#include "BSW_MemMap.h"
//variable declaration
uint16 An_Pin1_U_mV;
uint16 An_Pin2_U_mV;
uint16 An_Pin3_U_mV;
uint16 An_Pin4_Res_Ohm;
uint16 An_Pin8_U_mV;
uint16 An_Pin9_Res_Ohm;
uint16 An_Pin17_Res_Ohm;
uint16 An_Pin18_U_mV;
uint16 An_Pin23_U_mV;
uint16 An_Pin24_U_mV;
uint16 An_Pin25_U_mV;
uint16 An_KL30_U_mV;
uint16 An_TempSns_U_mV;

#define BSW_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "BSW_MemMap.h"

#define BSW_START_SEC_CODE
#include "BSW_MemMap.h"
//setters
void Set_An_Pin1_U_mV(uint16 value)
{
    An_Pin1_U_mV = value;
}
void Set_An_Pin2_U_mV(uint16 value)
{
    An_Pin2_U_mV = value;
}
void Set_An_Pin3_U_mV(uint16 value)
{
    An_Pin3_U_mV = value;
}
void Set_An_Pin4_Res_Ohm(uint16 value)
{
    An_Pin4_Res_Ohm = value;
}
void Set_An_Pin8_U_mV(uint16 value)
{
    An_Pin8_U_mV = value;
}
void Set_An_Pin9_Res_Ohm(uint16 value)
{
    An_Pin9_Res_Ohm = value;
}
void Set_An_Pin17_Res_Ohm(uint16 value)
{
    An_Pin17_Res_Ohm = value;
}
void Set_An_Pin18_U_mV(uint16 value)
{
    An_Pin18_U_mV = value;
}
void Set_An_Pin23_U_mV(uint16 value)
{
    An_Pin23_U_mV = value;
}
void Set_An_Pin24_U_mV(uint16 value)
{
    An_Pin24_U_mV = value;
}
void Set_An_Pin25_U_mV(uint16 value)
{
    An_Pin25_U_mV = value;
}
void Set_An_KL30_U_mV(uint16 value)
{
    An_KL30_U_mV = value;
}
void Set_An_TempSns_U_mV(uint16 value)
{
    An_TempSns_U_mV = value;
}
//getters
uint16 Get_An_Pin1_U_mV(void)
{
    return An_Pin1_U_mV;
}
uint16 Get_An_Pin2_U_mV(void)
{
    return An_Pin2_U_mV;
}
uint16 Get_An_Pin3_U_mV(void)
{
    return An_Pin3_U_mV;
}
uint16 Get_An_Pin4_Res_Ohm(void)
{
    return An_Pin4_Res_Ohm;
}
uint16 Get_An_Pin8_U_mV(void)
{
    return An_Pin8_U_mV;
}
uint16 Get_An_Pin9_Res_Ohm(void)
{
    return An_Pin9_Res_Ohm;
}
uint16 Get_An_Pin17_Res_Ohm(void)
{
    return An_Pin17_Res_Ohm;
}
uint16 Get_An_Pin18_U_mV(void)
{
    return An_Pin18_U_mV;
}
uint16 Get_An_Pin23_U_mV(void)
{
    return An_Pin23_U_mV;
}
uint16 Get_An_Pin24_U_mV(void)
{
    return An_Pin24_U_mV;
}
uint16 Get_An_Pin25_U_mV(void)
{
    return An_Pin25_U_mV;
}
uint16 Get_An_KL30_U_mV(void)
{
    return An_KL30_U_mV;
}
uint16 Get_An_TempSns_U_mV(void)
{
    return An_TempSns_U_mV;
}

#define BSW_STOP_SEC_CODE
#include "BSW_MemMap.h"