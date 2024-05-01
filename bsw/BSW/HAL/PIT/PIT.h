/*
 * PIT.h
 *
 *  Created on: Nov 23, 2015
 *      Author: Mati
 */

#ifndef PIT_H_
#define PIT_H_

#include "Std_Types.h"

void PIT_ModuleConfig(sint8 clkctrl);

void PIT_ChConfig(sint8 channel, uint32 period, sint8 irq_en);

void RTC_Config(uint32 period, sint8 irq_en);

void PIT_Enable(uint8 channel);

void PIT_Disable(uint8 channel);

void RTC_Enable(void);

void RTC_Disable(void);
void PIT_ClearIsr(uint8 channel);

#endif /* PIT_H_ */
