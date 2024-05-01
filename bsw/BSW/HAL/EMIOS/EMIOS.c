/*
 * emios.c
 *
 *  Created on: Nov 8, 2015
 *      Author: Mati
 */
#include "EMIOS.h"
#include "MPC5644A.h"

#define BSW_START_SEC_CODE
#include "BSW_MemMap.h"

inline boolean emios_channel_check_range(uint8 channel)
{
	if (channel > EMIOS_CHANNEL_MAX)
	{
		return STD_FALSE;
	}
	else
	{
		return STD_TRUE;
	}
}
Std_ReturnType emios_ch_write_status(uint8 channel, boolean status)
{
	if (emios_channel_check_range(channel) == STD_FALSE)
	{
		return E_NOT_OK;
	}
	status &= 1;
	EMIOS.UCDIS.R &= ~(status << channel);
	return E_OK;
}
Std_ReturnType emios_ch_read_status(uint8 channel, boolean *status)
{
	uint32 reg;
	if (emios_channel_check_range(channel) == STD_FALSE)
	{
		return E_NOT_OK;
	}
	reg = (EMIOS.UCDIS.R & (1 << channel)) >> channel;
	*status = (uint8)reg;
	return E_OK;
}

Std_ReturnType emios_ch_read_period(uint8 channel, uint32 *period)
{
	uint32 a_val, b_val;
	if ((period == 0) || (emios_channel_check_range(channel) == STD_FALSE))
	{
		return E_NOT_OK;
	}
	else
	{
		if ((EMIOS.CH[channel].CCR.R & EMIOS_MODE_IPM == EMIOS_MODE_IPM))
		{
			a_val = EMIOS.CH[channel].CADR.R;
			b_val = EMIOS.CH[channel].CBDR.R;
			if (a_val < b_val)
				a_val += 0x00ffffff;
			*period = b_val - a_val;
			return E_OK;
		}
		return E_NOT_OK;
	}
}

Std_ReturnType emios_ch_read_pulse_width(uint8 channel, uint32 *width)
{
	uint32 a_val, b_val;
	if ((width == 0) || (emios_channel_check_range(channel) == STD_FALSE))
	{
		return E_NOT_OK;
	}
	else
	{
		if ((EMIOS.CH[channel].CCR.R & EMIOS_MODE_IPWM == EMIOS_MODE_IPWM))
		{
			a_val = EMIOS.CH[channel].CADR.R;
			b_val = EMIOS.CH[channel].CBDR.R;
			if (a_val < b_val)
				a_val += 0x00ffffff;
			*width = b_val - a_val;
			return E_OK;
		}
		return E_NOT_OK;
	}
}

Std_ReturnType emios_ch_read_ab(uint8 channel, sint32 *a_val, sint32 *b_val)
{
	if ((a_val == 0) || (b_val == 0))
	{
		return E_NOT_OK;
	}
	else
	{
		EMIOS.CH[channel].CADR.R = (uint32)a_val;
		EMIOS.CH[channel].CBDR.R = (uint32)b_val;
		return E_OK;
	}
}

/*ENd of uzupelnic*/

Std_ReturnType emios_ch_config_daoc(uint8 channel, uint32 a_val, uint32 b_val, uint32 ccr_val)
{
	if (emios_channel_check_range(channel) == STD_FALSE)
	{
		return E_NOT_OK;
	}
	EMIOS.UCDIS.R &= ~(1 << channel);
	EMIOS.CH[channel].CADR.R = a_val;
	EMIOS.CH[channel].CBDR.R = b_val;
	EMIOS.CH[channel].CCR.R = EMIOS_UPREN_EN + EMIOS_MODE_DAOC_B + ccr_val;
	return E_OK;
}

void emios_ch_config_ipwm(uint8 channel, uint32 ccr_val)
{
	EMIOS.UCDIS.R &= ~(1 << channel);
	EMIOS.CH[channel].CCR.R = EMIOS_UPREN_EN + EMIOS_MODE_IPWM + ccr_val;
}

void emios_ch_config_ipm(uint8 channel, uint32 ccr_val)
{
	EMIOS.UCDIS.R &= ~(1 << channel);
	EMIOS.CH[channel].CCR.R = EMIOS_UPREN_EN + EMIOS_MODE_IPM + ccr_val;
}

void emios_ch_config_opwmb(uint8 channel, uint32 a_val, uint32 b_val, uint32 ccr_val)
{
	EMIOS.UCDIS.R &= ~(1 << channel);
	EMIOS.CH[channel].CADR.R = a_val;
	EMIOS.CH[channel].CBDR.R = b_val;
	EMIOS.CH[channel].CCR.R = EMIOS_UPREN_EN + EMIOS_MODE_OPMB + ccr_val;
}

void emios_ch_config_opwfmb(uint8 channel, uint32 a_val, uint32 b_val, uint32 ccr_val)
{
	EMIOS.UCDIS.R &= ~(1 << channel);
	EMIOS.CH[channel].CADR.R = a_val;
	EMIOS.CH[channel].CBDR.R = b_val;
	EMIOS.CH[channel].CCR.R = EMIOS_UPREN_EN + EMIOS_MODE_OPFMB + ccr_val;
}

void emios_ch_write_ab(uint8 channel, sint32 a_val, sint32 b_val)
{
	if (a_val >= 0)
		EMIOS.CH[channel].CADR.R = (uint32)a_val;
	if (b_val >= 0)
		EMIOS.CH[channel].CBDR.R = (uint32)b_val;
}

void emios_gclk_config(uint8 gclk_pre)
{
	EMIOS.MCR.B.GPRE = gclk_pre;
	EMIOS.MCR.B.GPREN = 1;
	EMIOS.MCR.B.GTBE = 1;
	EMIOS.MCR.B.ETB = 1;
	EMIOS.MCR.B.SRV = 2;
	EMIOS.UCDIS.R = 0xffffff;
}

void emios_ch_config_mcb(uint8 channel, uint32 a_val)
{
	EMIOS.UCDIS.R &= ~(1 << channel);
	EMIOS.CH[channel].CADR.R = a_val;
	EMIOS.CH[channel].CCR.B.MODE = 0x50;
	EMIOS.CH[channel].CCR.B.BSL = 0x3;
	EMIOS.CH[channel].CCR.B.UCPRE = 0;
	EMIOS.CH[channel].CCR.B.UCPREN = 1;
}

#define BSW_STOP_SEC_CODE
#include "BSW_MemMap.h"
