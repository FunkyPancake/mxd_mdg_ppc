/*
 * EMIOS_Cfg.c
 *
 *  Created on: Nov 20, 2018
 *      Author: Mati
 */
#include "EMIOS_Cfg.h"
#include "EMIOS.h"

#define BSW_START_SEC_CODE
#include "BSW_MemMap.h"

void EMIOS_Init(void)
{
    emios_gclk_config(EMIOS_CNTR_A_CHANNEL);                                                  //Counter A -> TCR 2
    emios_ch_config_opwfmb(EMIOS_TACHO_CHANNEL, 300, 1800, EMIOS_EDPOL_RISING + EMIOS_BSL_A); //tacho out
}

#define BSW_STOP_SEC_CODE
#include "BSW_MemMap.h"
