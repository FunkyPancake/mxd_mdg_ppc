#ifndef RINTKTHR_OUT_H_
#define RINTKTHR_OUT_H_

#include "Std_Types.h"

void Set_RIntkThr_Pct(sint16 value);
void Set_RIntkThr_Raw_U_mV(sint16 value);
void Set_RIntkThr_Err(uint8 value);
sint16 Get_RIntkThr_Pct(void);
sint16 Get_RIntkThr_Raw_U_mV(void);
uint8 Get_RIntkThr_Err(void);
#endif /*RINTKTHR_OUT_H_*/