/*
 * emios.h
 *
 *  Created on: Nov 5, 2015
 *      Author: Mati
 */

#ifndef EMIOS_H_
#define EMIOS_H_

#include "Std_Types.h"

#define EMIOS_CHANNEL_MAX 23

#define EMIOS_MODE_GPIO_IN 0
#define EMIOS_MODE_GPIO_OUT 1
#define EMIOS_MODE_SAIC 2
#define EMIOS_MODE_SAOC 3
#define EMIOS_MODE_IPWM 4
#define EMIOS_MODE_IPM 5
#define EMIOS_MODE_DAOC_BM 6
#define EMIOS_MODE_DAOC_B 7
#define EMIOS_MODE_MCB_U 0x50
#define EMIOS_MODE_MCB_UD 0x58
#define EMIOS_MODE_OPFMB 0x58
#define EMIOS_MODE_OPMB 0x60

#define EMIOS_EDPOL_RISING 0x80
#define EMIOS_EDPOL_FALLING 0x00

#define EMIOS_EDSEL_EN 0x100
#define EMIOS_EDSEL_DIS 0x000

#define EMIOS_BSL_A 0x000
#define EMIOS_BSL_BCD 0x200
#define EMIOS_BSL_INTERNAL 0x600

#define EMIOS_FORCMB_FB 0x800

#define EMIOS_ODISSL_DI0 0
#define EMIOS_ODISSL_DI1 0x10000000
#define EMIOS_ODISSL_DI2 0x20000000
#define EMIOS_ODISSL_DI3 0x30000000

#define EMIOS_ODIS_NORM 0
#define EMIOS_ODIS_EDPOL 0x40000000

#define EMIOS_FREN_EN 0x80000000
#define EMIOS_FREN_DIS 0

#define EMIOS_UPREN_EN 0x02000000
#define EMIOS_UPRE_DIV1 0
#define EMIOS_UPRE_DIV2 0x04000000
#define EMIOS_UPRE_DIV3 0x08000000
#define EMIOS_UPRE_DIV4 0x0C000000

#define EMIOS_FCK_MAIN_CLK 0x00040000
#define EMIOS_FCK_PRESCAL_CLK 0

inline boolean emios_channel_check_range(uint8 channel);

Std_ReturnType emios_ch_write_status(uint8 channel, boolean status);

Std_ReturnType emios_ch_read_status(uint8 channel, boolean *status);

Std_ReturnType emios_ch_read_period(uint8 channel, uint32 *period);

Std_ReturnType emios_ch_read_pulse_width(uint8 channel, uint32 *width);

Std_ReturnType emios_ch_read_ab(uint8 channel, sint32 *a_val, sint32 *b_val);

Std_ReturnType emios_ch_config_daoc(uint8 channel, uint32 a_val, uint32 b_val, uint32 ccr_val);

void emios_ch_config_ipwm(uint8 channel, uint32 ccr_val);

void emios_ch_config_ipm(uint8 channel, uint32 ccr_val);

void emios_ch_config_opwmb(uint8 channel, uint32 a_val, uint32 b_val, uint32 ccr_val);

void emios_ch_config_opwfmb(uint8 channel, uint32 a_val, uint32 b_val, uint32 ccr_val);

void emios_ch_write_ab(uint8 channel, sint32 a_val, sint32 b_val);

void emios_gclk_config(uint8 gclk_pre);

void emios_ch_config_mcb(uint8 channel, uint32 a_val);

#endif /* EMIOS_H_ */
