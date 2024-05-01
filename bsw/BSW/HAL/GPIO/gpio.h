/**************************************************************************
 * FILE NAME: $RCSfile: gpio.h,v $        COPYRIGHT (c) Freescale 2006 *
 * DESCRIPTION:                                     All Rights Reserved   *
 * This file contains the prototypes and defines for the MPC5500 GPIO low *
 * level driver.                                                          *
 *========================================================================*
 * ORIGINAL AUTHOR: Jeff Loeliger (r12110)                                *
 * $Log: gpio.h,v $
 * Revision 1.1  2006/01/11 11:28:53  r47354
 * remove "\"s
 *
 * Revision 1.0  2006/01/10 16:28:47  r47354
 * no message
 *
 *
 *........................................................................*
 *
 * File Name: gpio.h
 *
 * Description:  This file contains the prototypes and defines for the MPC5500
 *               GPIO low level driver. It includes function to configure
 *               the I/O pad and to perform I/O operations.
 *
 * Compilers: Metrowerks CodeWarrior for MPC5500 V1.5
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
 *****************************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_


extern struct SIU_struct *SIU_s;
/* Note, that mpc55xx register definitions must be included before
   inlude gpio.h, e.g. #include "mpc5554.h" */


/**************************************************************************/
/*                           Quick API Summary                            */
/**************************************************************************
uint8 gpio_read_data( uint16 pad );
void gpio_write_data( uint16 pad, uint8 value );
uint8 gpio_read_byte( uint16 pad_msb );
void gpio_write_byte( uint16 pad_msb, uint8 value );
void gpio_config_input(uint16 pad, uint16 hysteresis, uint16 weak_pull );
void gpio_config_output( uint16 pad, uint16 drive_strength, 
                            uint16 slew_rate, uint16 open_drain,
                            uint16 readback );
void gpio_config( uint16 pad, uint16 config );
void gpio_config_array( uint16 size, gpio_config_array_ts *config_array );
***************************************************************************/
/**************************************************************************/
/*                            Structure                                   */
/**************************************************************************/
typedef struct
{
	uint16 pad;    /* This is the pad number */
	uint16 config;  /* This is the configuration value for the pad */
}gpio_config_array_ts;



/**************************************************************************/
/*                  API Definition / Function Prototypes                  */
/**************************************************************************/

/*****************************************************************************
*
* Function : gpio_read_data
*
* Description:
*	 This function returns the current state of a pad.
*
* Arguments :
*    1) pad (in) - This is the pad number. The pad number should be
*                   between 0-511. It will typically be less for any
*                   given device. Remember that not all pad numbers within
*		the range are implemented on silicon
*
* Returns :
*    1) State of pad
*
* Range Issues:
*
* Special Issues:
*    This function assumes that the pad is already configured for input.
*
* Algorithm :
*
*****************************************************************************/
uint8 gpio_read_data( uint16 pad );


/*****************************************************************************
*
* Function : gpio_write_data
*
* Description:
*	 This function sets the state of a pad.
*
* Arguments :
*    1) pad (in) - This is the pad number. The pad number should be
*                   between 0-511. It will typically be less for any
*                   given device. Remember that not all pad numbers within
*		the range are implemented on silicon
*    2) value (in) - This is the value (0 or 1) to be written to the output
*                    pad.
*
* Returns :
*    None.
*
* Range Issues:
*
* Special Issues:
*    This function assumes that the pad is already configured for output.
*
* Algorithm :
*
*****************************************************************************/
void gpio_write_data( uint16 pad, uint8 value );


/*****************************************************************************
*
* Function : gpio_read_byte
*
* Description:
*	 This function returns the current states of the pads composing a byte.
*
* Arguments :
*    1) pad_msb (in) - This is the pad number of the MSB bit from a byte.
*                       The pad number should be between 0-504. It will
*                       typically be less for any given device. Remember that not
*		    all pad numbers within the range are implemented on silicon
*		
*
* Returns :
*    1) State of the 8 subsequent pads
*
* Range Issues:
*    pads composing a byte must be continuous.
*
* Special Issues:
*    This function assumes that the pads are already configured for input.
*
* Algorithm :
*
*****************************************************************************/
uint8 gpio_read_byte( uint16 pad_msb );


/*****************************************************************************
*
* Function : gpio_write_byte
*
* Description:
*	 This function sets the states of the pads composing a byte.
*
* Arguments :
*    1) pad_msb (in) - This is the pad number of the MSB bit from a byte.
*                       The pad number should be between 0-504. It will
*                       typically be less for any given device.  Remember that not
*		    all pad numbers within the range are implemented on silicon
*    2) value (in) - This is the 8bit=byte value to be written to the outputs.
*
* Returns :
*    None.
*
* Range Issues:
*    pads composing a byte must be continuous.
*
* Special Issues:
*    This function assumes that the pads are already configured for output.
*
* Algorithm :
*
*****************************************************************************/
void gpio_write_byte( uint16 pad_msb, uint8 value );


/*****************************************************************************
*
* Function : gpio_config_input
*
* Description:
*	 This function configures a pad for use as general purpose input.
*
* Arguments :
*    1) pad (in) - This is the pad number. The pad number should be
*                   between 0-511. It will typically be less for any
*                   given device.  Remember that not all pad numbers
*	    	within the range are implemented on silicon
*    2) hysteresis (in) - This defines if hysteresis should be enabled
*                         for the pad.
*                         Use GPIO_HYSTERESIS_ENABLE to enable it,
*                         or  GPIO_HYSTERESIS_DISABLE (or 0) to disable it.
*    3) weak_pull (in) - This defines the weak pull device for the pad.
*                        It should be set to: GPIO_WEAK_PULL_UP,
*                        GPIO_WEAK_PULL_DOWN, or GPIO_WEAK_PULL_DISABLE (or 0).
*
* Returns :
*    None.
*
* Range Issues:
*
* Special Issues:
*
* Algorithm :
*
*****************************************************************************/
void gpio_config_input(uint16 pad, uint16 hysteresis, uint16 weak_pull );


/*****************************************************************************
*
* Function : gpio_config_output
*
* Description:
*	 This function configures a pad for use as general purpose output.
*
* Arguments :
*    1) pad (in) - This is the pad number. The pad number should be
*                   between 0-511. It will typically be less for any
*                   given device. Remember that not all pad numbers
*	    	within the range are implemented on silicon
*    2) drive_strength (in) - This defines the drive strength.
*                             It should be set to GPIO_DRIVE_STRENGTH_10PF,
*                             GPIO_DRIVE_STRENGTH_20PF, GPIO_DRIVE_STRENGTH_30PF
*                             or GPIO_DRIVE_STRENGTH_50PF.
*    3) slew_rate (in) - This defines the slew rate.
*                        It should be set to GPIO_MINIMUM_SLEW_RATE,
*                        GPIO_MEDIUM_SLEW_RATE or GPIO_MAXIMUM_SLEW_RATE.
*    4) open_drain (in) - This enables open drain mode.
*                         It should be set to GPIO_OUTPUT_DRAIN_ENABLE to enable
*                         open drain mode or to GPIO_OUTPUT_DRAIN_DISABLE (or 0)
*                         to disable it.
*    5) readback (in) - This enables to read the actual value of the pad
*                       by gpio_read_data() function.
*                       Use GPIO_READBACK_ENABLE to enable such functionality,
*                       or GPIO_READBACK_DISABLE (or 0) to disable it and thus
*                       to reduce noise and power consumption.
*
* Returns :
*    None.
*
* Range Issues:
*
* Special Issues:
*
* Algorithm :
*
*****************************************************************************/
void gpio_config_output( uint16 pad, uint16 drive_strength, 
                            uint16 slew_rate, uint16 open_drain,
                            uint16 readback );


/*****************************************************************************
*
* Function : gpio_config
*
* Description:
*	 This function configures a pad (a general configuration).
*
* Arguments :
*    1) pad (in) - This is the pad number. The pad number should be
*                   between 0-511. It will typically be less for any
*                   given device. Remember that not all pad numbers
*	    	within the range are implemented on silicon
*    2) config (in) - This is the configuration value for the pad. The best
*                     way to determine this is to add the appropriate
*                     configuration values together from the gpio.h file.
* E.g: gpio_config(4,GPIO_IO_FUNCTION + GPIO_OUTPUT_MODE + GPIO_DRIVE_STRENGTH_50PF);
*
* Returns :
*    None.
*
* Range Issues:
*
* Special Issues: User must be fully familiar with GPIO configuration.
*
* Algorithm :
*
*****************************************************************************/
void gpio_config( uint16 pad, uint16 config );


/*****************************************************************************
*
* Function : gpio_config_array
*
* Description:
*	 This function configures an array of pads (a general configuration).
*
* Arguments :
*    1) size (in) - This the number of elements in the config array,
*                   i.e. the number of pads to be configured.
*    2) config_array (in) - This is an array of pad and config data.
*
* Returns :
*    None.
*
* Range Issues:
*
* Special Issues: User must be fully familiar with GPIO configuration.
*
* Algorithm :
*
*****************************************************************************/
void gpio_config_array( uint16 size, gpio_config_array_ts *config_array );



/**************************************************************************/
/*                            Definitions                                 */
/**************************************************************************/

/* Fields used for all pads  */
/* -------------------------  */
/* PA field - pad assignment */
#define GPIO_IO_FUNCTION          0x0000
#define GPIO_PRIMARY_FUNCTION     0x0400
#define GPIO_ALTERNATE_FUNCTION   0x0800
#define GPIO_ALTERNATE_FUNCTION1  0x0400 /* == GPIO_ALTERNATE_FUNCTION */
#define GPIO_ALTERNATE_FUNCTION2  0x0800
#define GPIO_ALTERNATE_FUNCTION3  0x0c00

/* OBE, IBE fields - output/input buffer enable */
#define GPIO_OUTPUT_BUFFER_ENABLE 0x0200
#define GPIO_INPUT_BUFFER_ENABLE  0x0100
#define GPIO_OUTPUT_MODE          0x0200
#define GPIO_INPUT_MODE           0x0100
#define GPIO_READBACK_ENABLE      0x0100
#define GPIO_READBACK_DISABLE     0x0000
#define GPIO_ANALOG_MODE		  0x2000

/* Fields used for Input       */
/* -------------------------   */
/* HYS field - hysteresis      */
#define GPIO_HYSTERESIS_ENABLE  0x0010
#define GPIO_HYSTERESIS_DISABLE 0x0000

/* WPE and WPS fields - treated as 1 field for weak pull configuration */
#define GPIO_WEAK_PULL_UP      0x0003
#define GPIO_WEAK_PULL_DOWN    0x0002
#define GPIO_WEAK_PULL_DISABLE 0x0000


/* Fields used for Output      */
/* -------------------------   */
/* DSC field - drive strength control */
#define GPIO_DRIVE_STRENGTH_10PF 0x0000
#define GPIO_DRIVE_STRENGTH_20PF 0x0040
#define GPIO_DRIVE_STRENGTH_30PF 0x0080
#define GPIO_DRIVE_STRENGTH_50PF 0x00C0

/* ODE field - output drain control */
#define GPIO_OUTPUT_DRAIN_ENABLE  0x0020
#define GPIO_OUTPUT_DRAIN_DISABLE 0x0000
#define GPIO_OPEN_DRAIN_ENABLE  0x0020
#define GPIO_OPEN_DRAIN_DISABLE 0x0000

/* SRC field - slew rate control */
#define GPIO_MINIMUM_SLEW_RATE 0x0000
#define GPIO_MEDIUM_SLEW_RATE  0x0004
#define GPIO_MAXIMUM_SLEW_RATE 0x000C


/* Pin's functional name vs. GPIO pad number */
#define GPIO_CS0       0
#define GPIO_CS1       1
#define GPIO_CS2       2
#define GPIO_CS3       3
#define GPIO_ADDR8     4
#define GPIO_ADDR9     5
#define GPIO_ADDR10    6
#define GPIO_ADDR11    7
#define GPIO_ADDR12    8
#define GPIO_ADDR13    9
#define GPIO_ADDR14    10
#define GPIO_ADDR15    11
#define GPIO_ADDR16    12
#define GPIO_ADDR17    13
#define GPIO_ADDR18    14
#define GPIO_ADDR19    15
#define GPIO_ADDR20    16
#define GPIO_ADDR21    17
#define GPIO_ADDR22    18
#define GPIO_ADDR23    19
#define GPIO_ADDR24    20
#define GPIO_ADDR25    21
#define GPIO_ADDR26    22
#define GPIO_ADDR27    23
#define GPIO_ADDR28    24
#define GPIO_ADDR29    25
#define GPIO_ADDR30    26
#define GPIO_ADDR31    27
#define GPIO_DATA0     28
#define GPIO_DATA1     29
#define GPIO_DATA2     30
#define GPIO_DATA3     31
#define GPIO_DATA4     32
#define GPIO_DATA5     33
#define GPIO_DATA6     34
#define GPIO_DATA7     35
#define GPIO_DATA8     36
#define GPIO_DATA9     37
#define GPIO_DATA10    38
#define GPIO_DATA11    39
#define GPIO_DATA12    40
#define GPIO_DATA13    41
#define GPIO_DATA14    42
#define GPIO_DATA15    43
#define GPIO_DATA16    44
#define GPIO_DATA17    45
#define GPIO_DATA18    46
#define GPIO_DATA19    47
#define GPIO_DATA20    48
#define GPIO_DATA21    49
#define GPIO_DATA22    50
#define GPIO_DATA23    51
#define GPIO_DATA24    52
#define GPIO_DATA25    53
#define GPIO_DATA26    54
#define GPIO_DATA27    55
#define GPIO_DATA28    56
#define GPIO_DATA29    57
#define GPIO_DATA30    58
#define GPIO_DATA31    59
#define GPIO_TSIZ0     60
#define GPIO_TSIZ1     61
#define GPIO_RD_WR     62
#define GPIO_BDIP      63
#define GPIO_WE0       64
#define GPIO_WE1       65
#define GPIO_WE2       66
#define GPIO_WE3       67
#define GPIO_OE        68
#define GPIO_TS        69
#define GPIO_TA        70
#define GPIO_TEA       71
#define GPIO_BR        72
#define GPIO_BG        73
#define GPIO_BB        74
#define GPIO_MDO4      75
#define GPIO_MDO5      76
#define GPIO_MDO6      77
#define GPIO_MDO7      78
#define GPIO_MDO8      79
#define GPIO_MDO9      80
#define GPIO_MDO10     81
#define GPIO_MDO11     82
#define GPIO_CNTXA     83
#define GPIO_CNRXA     84
#define GPIO_CNTXB     85
#define GPIO_CNRXB     86
#define GPIO_CNTXC     87
#define GPIO_CNRXC     88
#define GPIO_TXDA      89
#define GPIO_RXDA      90
#define GPIO_TXDB      91
#define GPIO_RXDB      92
#define GPIO_SCKA      93
#define GPIO_SINA      94
#define GPIO_SOUTA     95
#define GPIO_PCSA0     96
#define GPIO_PCSA1     97
#define GPIO_PCSA2     98
#define GPIO_PCSA3     99
#define GPIO_PCSA4     100
#define GPIO_PCSA5     101
#define GPIO_SCKB      102
#define GPIO_SINB      103
#define GPIO_SOUTB     104
#define GPIO_PCSB0     105
#define GPIO_PCSB1     106
#define GPIO_PCSB2     107
#define GPIO_PCSB3     108
#define GPIO_PCSB4     109
#define GPIO_PCSB5     110
#define GPIO_ETRIG0    111
#define GPIO_ETRIG1    112
#define GPIO_TCRCLKA   113
#define GPIO_ETPUA0    114
#define GPIO_ETPUA1    115
#define GPIO_ETPUA2    116
#define GPIO_ETPUA3    117
#define GPIO_ETPUA4    118
#define GPIO_ETPUA5    119
#define GPIO_ETPUA6    120
#define GPIO_ETPUA7    121
#define GPIO_ETPUA8    122
#define GPIO_ETPUA9    123
#define GPIO_ETPUA10   124
#define GPIO_ETPUA11   125
#define GPIO_ETPUA12   126
#define GPIO_ETPUA13   127
#define GPIO_ETPUA14   128
#define GPIO_ETPUA15   129
#define GPIO_ETPUA16   130
#define GPIO_ETPUA17   131
#define GPIO_ETPUA18   132
#define GPIO_ETPUA19   133
#define GPIO_ETPUA20   134
#define GPIO_ETPUA21   135
#define GPIO_ETPUA22   136
#define GPIO_ETPUA23   137
#define GPIO_ETPUA24   138
#define GPIO_ETPUA25   139
#define GPIO_ETPUA26   140
#define GPIO_ETPUA27   141
#define GPIO_ETPUA28   142
#define GPIO_ETPUA29   143
#define GPIO_ETPUA30   144
#define GPIO_ETPUA31   145
#define GPIO_TCRCLKB   146
#define GPIO_ETPUB0    147
#define GPIO_ETPUB1    148
#define GPIO_ETPUB2    149
#define GPIO_ETPUB3    150
#define GPIO_ETPUB4    151
#define GPIO_ETPUB5    152
#define GPIO_ETPUB6    153
#define GPIO_ETPUB7    154
#define GPIO_ETPUB8    155
#define GPIO_ETPUB9    156
#define GPIO_ETPUB10   157
#define GPIO_ETPUB11   158
#define GPIO_ETPUB12   159
#define GPIO_ETPUB13   160
#define GPIO_ETPUB14   161
#define GPIO_ETPUB15   162
#define GPIO_ETPUB16   163
#define GPIO_ETPUB17   164
#define GPIO_ETPUB18   165
#define GPIO_ETPUB19   166
#define GPIO_ETPUB20   167
#define GPIO_ETPUB21   168
#define GPIO_ETPUB22   169
#define GPIO_ETPUB23   170
#define GPIO_ETPUB24   171
#define GPIO_ETPUB25   172
#define GPIO_ETPUB26   173
#define GPIO_ETPUB27   174
#define GPIO_ETPUB28   175
#define GPIO_ETPUB29   176
#define GPIO_ETPUB30   177
#define GPIO_ETPUB31   178
#define GPIO_EMIOS0    179
#define GPIO_EMIOS1    180
#define GPIO_EMIOS2    181
#define GPIO_EMIOS3    182
#define GPIO_EMIOS4    183
#define GPIO_EMIOS5    184
#define GPIO_EMIOS6    185
#define GPIO_EMIOS7    186
#define GPIO_EMIOS8    187
#define GPIO_EMIOS9    188
#define GPIO_EMIOS10   189
#define GPIO_EMIOS11   190
#define GPIO_EMIOS12   191
#define GPIO_EMIOS13   192
#define GPIO_EMIOS14   193
#define GPIO_EMIOS15   194
#define GPIO_EMIOS16   195
#define GPIO_EMIOS17   196
#define GPIO_EMIOS18   197
#define GPIO_EMIOS19   198
#define GPIO_EMIOS20   199
#define GPIO_EMIOS21   200
#define GPIO_EMIOS22   201
#define GPIO_EMIOS23   202
#define GPIO_GPIO203   203
#define GPIO_GPIO204   204
#define GPIO_GPIO205   205
#define GPIO_GPIO206   206
#define GPIO_GPIO207   207
#define GPIO_PLLCFG0   208
#define GPIO_PLLCFG1   209
#define GPIO_RSTCFG    210
#define GPIO_BOOTCFG0  211
#define GPIO_BOOTCFG1  212
#define GPIO_WKPCFG    213

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

#ifdef EXTERNAL_
#undef EXTERNAL_
#endif

#endif /* #ifndef _GPIO_H_ */
