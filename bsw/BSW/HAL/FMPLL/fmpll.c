/*
 * fmpll.c
 *
 *  Created on: Nov 8, 2015
 *      Author: Mati
 */
#include "fmpll.h"
#include "MPC5644A.h"

void fmpll_config(void)
{
	volatile uint32 timeout = 0;
	
	/* 
	 * PLL Configuration Fosc = 16MHz
	 * SYSCLK = 120MHz
	 * */
	
	/*
	 * Set Flash wait states, according to datasheet
	 * FLASH_X.BIUCR.B.WWSC = 3;	
	 * FLASH_X.BIUCR.B.RWSC = 3;
	 * FLASH_X.BIUCR.B.APC = 3;
	 * */
	FLASH_A.BIUCR.R = 0x00037b53;
	FLASH_B.BIUCR.R = 0x00037b53;

	FLASH_A.BIUCR.B.IPFEN = 1;
	FLASH_B.BIUCR.B.IPFEN = 0;
	FLASH_B.BIUCR.B.DPFEN = 0;
	FLASH_A.BIUCR.B.PFLIM = 1;
	FLASH_A.BIUCR.B.BFEN = 1;
	
	SIU.SYSDIV.B.BYPASS = 1;
	FMPLL.ESYNCR1.B.EMODE =1;
	FMPLL.ESYNCR1.B.EPREDIV = 1;
	FMPLL.ESYNCR1.B.EMFD = 60;
	FMPLL.ESYNCR1.B.CLKCFG = 7;
	while(FMPLL.SYNSR.B.LOCK == 0 && (timeout < 10000))
	{
		++timeout;
	}
	if(timeout < 10000)
	{
		FMPLL.ESYNCR2.B.ERFD = 1;
	}
	//Frequency modulation	
	/*timeout = 0;
	FMPLL.SYNFMMR.B.MODSEL = 0;
	FMPLL.SYNFMMR.B.MODPERIOD = 50;
	FMPLL.SYNFMMR.B.INCSTEP = 105;
	while((FMPLL.SYNFMMR.B.BSY == 0) && (timeout < 10000))
	{
		++timeout;
	}
	FMPLL.SYNFMMR.B.MODEN = 1;*/
	FMPLL.ESYNCR2.B.LOCEN = 1;
	FMPLL.ESYNCR2.B.LOCRE =1;
}
