/*
 * FuPmpCtrl.c
 *
 *  Created on: Apr 11, 2019
 *      Author: Mati
 */

#include "FuPmpCtrl.h"
#include "FuPmpCtrl_Out.h"
#include "EngMgmt.h"

#define ACTR_START_SEC_CAL_8BIT
#include "ACTR_MemMap.h"
const volatile boolean FuPmpRlyOvrEn_P = 0;
const volatile boolean FuPmpRlyOvr_P = 0;
#define ACTR_STOP_SEC_CAL_8BIT
#include "ACTR_MemMap.h"

#define ACTR_START_SEC_CAL_16BIT
#include "ACTR_MemMap.h"
const volatile uint16 FuPmpPrimeTime_P = 30;
#define ACTR_STOP_SEC_CAL_16BIT
#include "ACTR_MemMap.h"

#define ACTR_START_SEC_VAR_NOINIT_32BIT
#include "ACTR_MemMap.h"
volatile static FuPmpCtrlStateEnum FuPmpState;
#define ACTR_STOP_SEC_VAR_NOINIT_32BIT
#include "ACTR_MemMap.h"

#define ACTR_START_SEC_VAR_NOINIT_16BIT
#include "ACTR_MemMap.h"
volatile static uint16 FuPmpPrimTim;
#define ACTR_STOP_SEC_VAR_NOINIT_16BIT
#include "ACTR_MemMap.h"

void FuPmpCtrl(void)
{
    boolean output;
    boolean st = Get_Eng_bNMot();
    switch (FuPmpState)
    {
    case FuPmpCtrlStateEnum.Init:
        output_state = STD_OFF;
        if (st == STD_ACTIVE)
        {
            FuPmpState = FuPmpCtrlStateEnum.On;
        }
        else
        {
            FuPmpPrimTim = InjLPFPmpPrimeTime_P;
            FuPmpState = FuPmpCtrlStateEnum.Prime;
        }
        break;

    case FuPmpCtrlStateEnum.Prime:
        output_state = STD_ON;
        if (FuPmpPrimTim > 0)
        {
            FuPmpPrimTim--;
        }
        else
        {
            if (st == STD_ACTIVE)
            {
                FuPmpState = FuPmpCtrlStateEnum.On;
            }
            else
            {
                FuPmpState = FuPmpCtrlStateEnum.Off;
            }
        }
        break;

    case FuPmpCtrlStateEnum.On:
        output_state = STD_ON;
        if (st == STD_IDLE)
        {
            FuPmpState = FuPmpCtrlStateEnum.Off;
        }
        break;

    case FuPmpCtrlStateEnum.Off:
        output_state = STD_OFF;
        if (st == STD_ACTIVE)
        {
            FuPmpState = FuPmpCtrlStateEnum.On;
        }
        break;
    default:
        output = STD_OFF;
        FuPmpState = FuPmpCtrlStateEnum.Init;
        break;
    }
    if (FuPmpRlyOvrEn_P)
        output = FuPmpRlyOvr_P;
    Set_FuPmpRlySt(output);
}
