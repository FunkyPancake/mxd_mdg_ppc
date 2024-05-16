#ifndef swt_C_
#define swt_C_
#endif

/*
 * swt.c
 *
 *  Created on: Dec 30, 2018
 *      Author: Mati
 */
#include "Std_Types.h"
#include "swt.h"
#include "MPC5644A.h"
#include "SWT_Cfg.h"

void SWT_Setup(uint32 timeout)
{
	SWT.MCR.B.RIA = 1;
	SWT.MCR.B.FRZ = 1;
	SWT.MCR.B.STP = 1;
	SWT.MCR.B.RIA =1;
	
	SWT.TO.R = timeout;
#ifdef SWT_ENABLE_KEY
	SWT.MCR.B.KEY =1;
#endif
	
#ifdef SWT_ENABLE_WINDOW
	SWT.MCR.B.WND = 1;
#endif
	
#ifdef SWT_OSC_CLK
	SWT.MCR.B.CSL = 1;
#endif	
//	SWT.MCR.B.WEN = 1;
}
void SWT_SetWindow(uint32 window)
{
	SWT.WN.R = window;
}
void SWT_Enable(void)
{
	SWT.MCR.B.WEN = 1;
}
void SWT_Disable(void)
{
	SWT.MCR.B.WEN = 0;
}
void SWT_KickTheDog(void)
{
#ifdef SWT_ENABLE_KEY
	uint16 key;
	key = (uint16)(SWT.SK.R*17)+3;
	SWT.SR.R = key;
	SWT.SR.R = (uint16)(key*17)+3;
#else	
	SWT.SR.R = 0xA602;
	SWT.SR.R = 0xB480;
#endif	
}
#ifdef swt_C_
#undef swt_C_
#endif
