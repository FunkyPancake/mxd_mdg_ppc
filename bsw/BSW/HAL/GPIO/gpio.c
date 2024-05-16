/**************************************************************************
 * FILE NAME: $RCSfile: gpio.c,v $        COPYRIGHT (c) Freescale 2006 *
 * DESCRIPTION:                                     All Rights Reserved   *
 * This file contains the GPIO API for the MPC5500 family.                *
 *========================================================================*
 * ORIGINAL AUTHOR: Jeff Loeliger (r12110)                                *
 * $Log: gpio.c,v $
 * Revision 1.1  2006/01/11 11:26:59  r47354
 * remove "\"s
 *
 * Revision 1.0  2006/01/10 16:28:32  r47354
 * no message
 **
 *
 *........................................................................*
 *
 * File Name: gpio.h
 *
 * Description:  This file contains the GPIO API for the MPC5500 family.
 *               This API works with all devices in the MPC5500 family.
 *
 * Compilers: Metrowerks CodeWarrior for MPC5500 V1.5
 *			       GreenHills
 *			       WindRiver Diab 5.1.1
 *
 * Original author: Jeff Loeliger  (jeff.loeliger@motorola.com)
 * REV      AUTHOR      DATE        DESCRIPTION OF CHANGE
 * ---   -----------  ----------    ---------------------
 * 0.1   J. Loeliger  16/Sep/03     Initial version.
 * 0.2   M. Kaspar    24/Nov/03     Updated naming convention
 * 0.3   M. Kaspar    18/Dec/03     Updated after the first review
 * 0.4   M. Kaspar    26/Jul/04     Updated for RM1.1 and Freescale
 * 0.5	  D. Mckenna 7/Jan/08       Updated variable names to match corresponding App Note
 *
 ****************************************************************************/
 
#include "Std_Types.h"
#include "MPC5644A.h"
#include "gpio.h"



/****************************************************************************/
uint8 gpio_read_data( uint16 pad )
{

	return( SIU.GPDI[pad].R );
}

/****************************************************************************/
void gpio_write_data( uint16 pad, uint8 value )
{

	SIU.GPDO[pad].R = value;
}

/****************************************************************************/
uint8 gpio_read_byte( uint16 pad_msb )
{

	return(uint8)(((SIU.GPDI[pad_msb].R<<7)+(SIU.GPDI[pad_msb+1].R<<6)+(SIU.GPDI[pad_msb+2].R<<5)+(SIU.GPDI[pad_msb+3].R<<4) +
		(SIU.GPDI[pad_msb+4].R<<3)+(SIU.GPDI[pad_msb+5].R<<2)+(SIU.GPDI[pad_msb+6].R<<1)+(SIU.GPDI[pad_msb+7].R) ));
}

/****************************************************************************/
void gpio_write_byte( uint16 pad_msb, uint8 value )
{

	SIU.GPDO[pad_msb].R = (uint8)(value >> 7);
	SIU.GPDO[pad_msb+1].R = (uint8)(value >> 6);
	SIU.GPDO[pad_msb+2].R = (uint8)(value >> 5);
	SIU.GPDO[pad_msb+3].R = (uint8)(value >> 4);
	SIU.GPDO[pad_msb+4].R = (uint8)(value >> 3);
	SIU.GPDO[pad_msb+5].R = (uint8)(value >> 2);
	SIU.GPDO[pad_msb+6].R = (uint8)(value >> 1);
	SIU.GPDO[pad_msb+7].R = (uint8)(value);

}

/****************************************************************************/
void gpio_config_input(uint16 pad, uint16 hysteresis, uint16 weak_pull )
{

	SIU.PCR[pad].R = (vuint16)(GPIO_IO_FUNCTION + GPIO_INPUT_BUFFER_ENABLE +
		              hysteresis + weak_pull);
}

/****************************************************************************/
void gpio_config_output( uint16 pad, uint16 drive_strength, 
                         uint16 slew_rate, uint16 open_drain,
                         uint16 readback )
{

	SIU.PCR[pad].R = (vuint16)(GPIO_IO_FUNCTION + GPIO_OUTPUT_BUFFER_ENABLE +
		              drive_strength + slew_rate + open_drain + readback);
}

/****************************************************************************/
void gpio_config( uint16 pad, uint16 config )
{

	SIU.PCR[pad].R = config;
}

/****************************************************************************/
void gpio_config_array( uint16 size, gpio_config_array_ts *config_array )
{

	int i;   /* local loop counter */

	for ( i=0; i < size; i++)

		SIU.PCR[config_array[i].pad].R = config_array[i].config;
}

/*********************************************************************
 *
 * Copyright:
 *	Freescale Semiconductor, Inc. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Freescale Semiconductor, Inc. This
 *  software is provided on an "AS IS" basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, FREESCALE SEMICONDUCTOR
 *  DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED, INCLUDING
 *  IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR
 *  PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH REGARD TO THE
 *  SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF) AND ANY
 *  ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL FREESCALE SEMICONDUCTOR BE LIABLE FOR ANY DAMAGES WHATSOEVER (INCLUDING
 *  WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS
 *  INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY
 *  LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Freescale Semiconductor assumes no responsibility for the maintenance and support
 *  of this software
 ********************************************************************/
