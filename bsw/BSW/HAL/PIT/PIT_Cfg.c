/*
 * PIT_Cfg.c
 *
 *  Created on: Nov 20, 2018
 *      Author: Mati
 */

#include "Std_Types.h"
#include "PIT_Cfg.h"
#include "PIT.h"

#define BSW_START_SEC_CODE
#include "BSW_MemMap.h"

void PIT_Init(void)
{
    PIT_ModuleConfig(0);
    PIT_ChConfig(PIT_CHN_1ms, PIT_CNT_1ms, STD_OFF);
    PIT_ChConfig(PIT_CHN_10ms, PIT_CNT_10ms, STD_OFF);
    PIT_ChConfig(PIT_CHN_50ms, PIT_CNT_50ms, STD_OFF);
}

#define BSW_STOP_SEC_CODE
#include "BSW_MemMap.h"
