#ifndef PBRKSERVO_OUT_H_
#define PBRKSERVO_OUT_H_

#include "Std_Types.h"

void Set_PBrkServo_Vac_Kpa(sint16 value);
void Set_PBrkServo_Raw_U_mV(sint16 value);
void Set_PBrkServo_Err(uint8 value);

sint16 Get_PBrkServo_Vac_Kpa(void);
sint16 Get_PBrkServo_Raw_U_mV(void);
uint8 Get_PBrkServo_Err(void);

#endif /*PBRKSERVO_OUT_H_*/