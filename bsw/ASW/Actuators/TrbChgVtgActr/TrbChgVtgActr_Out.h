#ifndef TRBCHGVTGACCT_OUT_H_
#define TRBCHGVTGACCT_OUT_H_

#include "Std_Types.h"

void Set_RTrbVtgPosTrg_Pct(sint16 value);
void Set_RTrbVtgActrPwm_Pct(sint16 value);
void Set_RTrbVtgActr_Err(uint8 value);

sint16 Get_RTrbVtgPosTrg_Pct(void);
sint16 Get_RTrbVtgActrPwm_Pct(void);
uint8 Get_RTrbVtgActr_Err(void);

#endif /*TRBCHGVTGACCT_OUT_H_*/