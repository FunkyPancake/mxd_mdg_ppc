#include "TrbChgVtgActr.h"
#include "TrbChgVtgActr_Out.h"
#include "RTrbVtgPos_Out.h"

#define ACTR_START_SEC_VAR_CAL_16BIT
#include "ACTR_MemMap.h"
const volatile sint16 TrbChgVtgActrPidP_P = 2;
const volatile sint16 TrbChgVtgActrPidScale_P = 5;
#define ACTR_STOP_SEC_VAR_CAL_16BIT
#include "ACTR_MemMap.h"

#define ACTR_START_SEC_CODE
#include "ACTR_MemMap.h"

void TrbChgVtgActrCtrl(void)
{
    sint16 trg, act, err;
    volatile sint32 out;
    trg = Get_RTrbVtgPosTrg_Pct();
    act = Get_RTrbVtgPos_Pct();
    err = trg - act;
    out = err * TrbChgVtgActrPidP_P;
    out /= TrbChgVtgActrPidScale_P;
    Set_RTrbVtgActrPwm_Pct(out);
}
#define ACTR_STOP_SEC_CODE
#include "ACTR_MemMap.h"