#ifndef RTRBVTGPOS_OUT_H_
#define RTRBVTGPOS_OUT_H_
#include "Std_Types.h"

void Set_RTrbVtgPos_Pct(sint16 value);
void Set_RTrbVtgPos_Raw_U_mV(sint16 value);
void Set_RTrbVtgPos_Err(uint8 value);

sint16 Get_RTrbVtgPos_Pct(void);
sint16 Get_RTrbVtgPos_Raw_U_mV(void);
uint8 Get_RTrbVtgPos_Err(void);

#endif /* RTRBVTGPOS_OUT_H_ */