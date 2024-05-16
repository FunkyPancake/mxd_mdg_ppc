/*
 * PIT.c
 *
 *  Created on: Nov 23, 2015
 *      Author: Mati
 */
#include "PIT.h"
#include "MPC5644A.h"
#include "Compiler.h"

#define PIT_MDIS_ENABLE 0x00
#define PIT_MDIS_DISABLE 0x04
#define PIT_RTC_ENABLE 0x00
#define PIT_RTC_DISABLE 0x02
#define PIT_FREEZE_ENABLE 0x01
#define PIT_FREEZE_DISABLE 0x00

#define BSW_START_SEC_CODE
#include "BSW_MemMap.h"

void PIT_ModuleConfig(sint8 clkctrl)
{
	PIT.PITMCR.R = clkctrl;
#ifdef DEBUG
	PIT.PITMCR.B.FRZ = PIT_FREEZE_ENABLE;
#endif
}

void PIT_ChConfig(sint8 channel, uint32 period, sint8 irq_en)
{
	PIT.TIMER[channel].LDVAL.R = period;
	PIT.TIMER[channel].TCTRL.B.TIE = irq_en;
	PIT.TIMER[channel].TCTRL.B.TEN = STD_ON;
}
void RTC_Config(uint32 period, sint8 irq_en)
{
	PIT.RTI.LDVAL.R = period;
	PIT.RTI.TCTRL.B.TIE = irq_en;
	PIT.RTI.TCTRL.B.TEN = STD_ON;
}
void PIT_Enable(uint8 channel)
{
	PIT.TIMER[channel].TCTRL.B.TEN = STD_ON;
}
void PIT_Disable(uint8 channel)
{
	PIT.TIMER[channel].TCTRL.B.TEN = STD_OFF;
}
void RTC_Enable(void)
{
	PIT.RTI.TCTRL.B.TEN = STD_ON;
}
void RTC_Disable(void)
{
	PIT.RTI.TCTRL.B.TEN = STD_OFF;
}
void PIT_ClearIsr(uint8 channel)
{
	PIT.TIMER[channel].TFLG.R = 1;
}
#define BSW_STOP_SEC_CODE
#include "BSW_MemMap.h"
