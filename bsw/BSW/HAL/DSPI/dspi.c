/*
 * fs_dspi.c
 *
 *  Created on: Apr 9, 2016
 *      Author: Mati
 */
#include "MPC5644A.h"
#include "dspi.h"

typedef struct
{
	uint8 *InputBuf;
	uint8 *OutputBuf;
	uint8 len;
	uint8 device_id;
} SpiJob;

typedef struct
{
	uint8 cs_id;
} SpiDevice;
void SpiBConfig(void)
{
	DSPI_B.MCR.R = 0x81f70d01;
	DSPI_B.CTAR[0].B.FMSZ = 15;
	DSPI_B.CTAR[0].B.CPOL = 0;
	DSPI_B.CTAR[0].B.CPHA = 0;
	DSPI_B.CTAR[0].B.BR = 10;
	DSPI_B.CTAR[3].R = 0;
	DSPI_B.CTAR[2].R = 0;
	DSPI_B.MCR.B.HALT = 0;
}
uint16 SpiTxPoll(uint16 data)
{
	DSPI_B.PUSHR.R = (uint32)(PUSHR_PCS(1) | PUSHR_CTAS(0) | PUSHR_EOQ | PUSHR_DATA(data));
	while (DSPI_B.SR.B.RFDF != 1)
		;
	DSPI_B.SR.B.RFDF = 1;
	return (uint16)DSPI_B.POPR.R;
}
