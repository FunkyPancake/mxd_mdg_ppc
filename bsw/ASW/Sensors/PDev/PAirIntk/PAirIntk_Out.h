#ifndef PAIRINTK_OUT_H_
#define PAIRINTK_OUT_H_

#include "Std_Types.h"

void Set_PAirIntk_Kpa(sint16 value);
void Set_PAirIntk_Raw_U_mV(sint16 value);
void Set_PAirIntk_Err(uint8 value);

sint16 Get_PAirIntk_Kpa(void);
sint16 Get_PAirIntk_Raw_U_mV(void);
uint8 Get_PAirIntk_Err(void);

#endif /* PAIRINTK_OUT_H_ */