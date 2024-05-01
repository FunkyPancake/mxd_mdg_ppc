#ifndef PFURAIL_OUT_H_
#define PFURAIL_OUT_H_

#include "Std_Types.h"

void Set_PFuRail_Kpa(sint16 value);
void Set_PFuRail_Raw_U_mV(sint16 value);
void Set_PFuRail_Err(uint8 value);

sint16 Get_PFuRail_Kpa(void);
sint16 Get_PFuRail_Raw_U_mV(void);
uint8 Get_PFuRail_Err(void);

#endif /*PFURAIL_OUT_H_*/