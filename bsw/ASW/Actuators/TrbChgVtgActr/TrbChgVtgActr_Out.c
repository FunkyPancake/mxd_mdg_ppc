#include "TrbChgVtgActr_Out.h"

#define ACTR_START_SEC_VAR_FAST_NOINIT_16BIT
#include "ACTR_MemMap.h"

volatile static sint16 RTrbVtgPosTrg_Pct;
volatile static sint16 RTrbVtgActrPwm_Pct;

#define ACTR_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "ACTR_MemMap.h"

#define ACTR_START_SEC_VAR_FAST_NOINIT_8BIT
#include "ACTR_MemMap.h"
static volatile uint8 RTrbVtgActr_Err;
#define ACTR_STOP_SEC_VAR_FAST_NOINIT_8BIT
#include "ACTR_MemMap.h"

#define ACTR_START_SEC_CODE
#include "ACTR_MemMap.h"

void Set_RTrbVtgPosTrg_Pct(sint16 value)
{
    RTrbVtgPosTrg_Pct = value;
}

void Set_RTrbVtgActrPwm_Pct(sint16 value)
{
    RTrbVtgActrPwm_Pct = value;
}

void Set_RTrbVtgActr_Err(uint8 value)
{
    RTrbVtgActr_Err = value;
}

sint16 Get_RTrbVtgPosTrg_Pct(void)
{
    return RTrbVtgPosTrg_Pct;
}

sint16 Get_RTrbVtgActrPwm_Pct(void)
{
    return RTrbVtgActrPwm_Pct;
}

uint8 Get_RTrbVtgActr_Err(void)
{
    return RTrbVtgActr_Err;
}

#define ACTR_STOP_SEC_CODE
#include "ACTR_MemMap.h"