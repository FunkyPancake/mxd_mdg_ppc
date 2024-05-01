#ifndef FAIRINTK_OUT_H
#define FAIRINTK_OUT_H
#include "Std_Types.h"

void Set_FAirIntk_Raw_U_mV(sint16 value);
void Set_FAirIntk_Kgh(float32 value);
void Set_FAirIntk_Err(uint8 value);
sint16 Get_FAirIntk_Kgh(void);
sint16 Get_FAirIntk_Raw_U_mV(void);
uint8 Get_FAirIntk_Err(void);

#endif /* FAIRINTK_OUT_H */