#ifndef PENGOIL_OUT_H_
#define PENGOIL_OUT_H_

#include "Std_Types.h"

void Set_PEngOil_Kpa(sint16 value);
void Set_PEngOil_Raw_U_mV(sint16 value);
void Set_PEngOil_Err(uint8 value);

sint16 Get_PEngOil_Kpa(void);
sint16 Get_PEngOil_Raw_U_mV(void);
uint8 Get_PEngOil_Err(void);

#endif /*PENGOIL_OUT_H_*/