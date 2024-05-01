/*
 * IL_ETPU.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Mati
 */

#ifndef IL_ETPU_H_
#define IL_ETPU_H_

#include "Std_Types.h"

void SetIgnEvent(void);
void SetInjEvent(void);
void CalcNmot(uint8 error_flag);
void etpu_crank_isr(void);
void CrankOsc(void);
void ETPU_EnableCrankIsr(void);

#endif /* IL_ETPU_H_ */
