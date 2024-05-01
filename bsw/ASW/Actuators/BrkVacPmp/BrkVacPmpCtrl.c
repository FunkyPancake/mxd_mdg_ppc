/*
 * BrkVacPmpCtrl.c
 *
 *  Created on: May 2, 2019
 *      Author: Mati
 */

#include "BrkVacPmpCtrl.h"
#include "BrkPmpP.h"

#define ACTR_START_SEC_CAL_16BIT
#include "ACTR_MemMap.h"
const volatile sint16 BrkVacThLowMbar_P = -600;
const volatile sint16 BrkVacThHighMbar_P = -250;
#define ACTR_STOP_SEC_CAL_16BIT
#include "ACTR_MemMap.h"
 
 
#define ACTR_START_SEC_CAL_8BIT
#include "ACTR_MemMap.h"
const volatile boolean BrkCtrlOvrEn_P = 0;
const volatile boolean BrkCtrlOvr_P = 0;
#define ACTR_STOP_SEC_CAL_8BIT
#include "ACTR_MemMap.h"

#define ACTR_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "ACTR_MemMap.h"
volatile static BrkBstStateEnum BrkBostTaskState;
#define ACTR_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "ACTR_MemMap.h"

void BrkVacPmpCtrl(void)
{
    boolean output;
    sint16 brk_vac = (sint16)Get_BrkPmpPVac_mBar();
    switch(BrkBostTaskState)
    {
        case BrkBostSt_Init:
            output = STD_ACTIVE;
            BrkBostTaskState = BrkBostSt_Off;
            break;
        case BrkBostSt_On:
            output = STD_ACTIVE;
            if(brk_vac <= BrkVacThLowMbar_P)
            {
                BrkBostTaskState = BrkBostSt_Off;
            }
            break;
        case BrkBostSt_Off:
            output = STD_IDLE;
            if(brk_vac >= BrkVacThHighMbar_P)
            {
                BrkBostTaskState = BrkBostSt_On;
            }
            break;
        default:
            BrkBostTaskState = BrkBostSt_Init;
            break;
    }
    if (BrkCtrlOvrEn_P == STD_ACTIVE)
        output = BrkCtrlOvr_P;
    Set_BrkBostRlyEn(output);
}