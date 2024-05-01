#include "TrbChgDivVlv.h"

/*
    Normally diverter valve should operate based on flowmase and intake pressure,
    since there is no such characteristic avalible for this particular turbo - max pressure and throttle closed is used
    Main function should run in 20ms raster
*/
#include "TrbChgDivVlv_Out.h"
#include "IntkPreThrP_Out.h"
#include "IntkThrPos_Out.h"
#define TRBCHGDIVVLV_OFF 0u
#define TRBCHGDIVVLV_ON 100u

#define ACTR_START_SEC_CAL_8BIT
#include "ACTR_MemMap.h"
const volatile uint8 TrbChgDivVlv_HldDty_Pct_P = 30u;
const volatile uint8 TrbChgDivVlv_OpnTout_P = 5u;
const volatile boolean TrbChgDivVlv_Ovr_En_P = 0u;
const volatile uint8 TrbChgDivVlv_OvrDty_Pct_P = 0u;
#define ACTR_STOP_SEC_CAL_8BIT
#include "ACTR_MemMap.h"

#define INJ_START_SEC_VAR_FAST_UNSPECIFIED
#include "ACTR_MemMap.h"
const volatile float32 TrbChgDivVlv_MaxP_Kpa_P = 2.0f;
const volatile float32 TrbChgDivVlv_MaxThr_Pct_P = 5.0f;
#define INJ_START_SEC_VAR_FAST_UNSPECIFIED
#include "ACTR_MemMap.h"

#define ACTR_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "ACTR_MemMap.h"
static TrbChgDivVlvStateEnum TrbChgDivVlvCtrlState;
static uint8 openTimer;
#define ACTR_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "ACTR_MemMap.h"


void TrbChgDivVlvCtrl(void)
{
    uint8 duty;
    float32 tps,intp;
    tps = Get_IntkThrPos_Pct();
    intp = Get_IntkPreThrP_Kpa();
    boolean openValve = (intp > TrbChgDivVlv_MaxP_Kpa_P) && (tps < TrbChgDivVlv_MaxThr_Pct_P);
    switch (TrbChgDivVlvCtrlState)
    {
    case Init:
        duty = TRBCHGDIVVLV_OFF;
        break;
    case Off:
        duty = TRBCHGDIVVLV_OFF;
        if(openValve)
        {
            openTimer = TrbChgDivVlv_OpnTout_P;
            TrbChgDivVlvCtrlState = Open;
        }
        break;
    case Open:
        duty = TRBCHGDIVVLV_ON;
        if(openValve)
        {
            if(openTimer >0)
            {
            openTimer--;
            }
            else
            {
                TrbChgDivVlvCtrlState = Hold;
            }
        }
        else
        {
            TrbChgDivVlvCtrlState = Off;
        }
        break;
    case Hold:
        duty = TrbChgDivVlv_HldDty_P;
        if(!openValve)
        {
            TrbChgDivVlvCtrlState = Off;
        }
        break;
    default:
        duty = TRBCHGDIVVLV_OFF;
        TrbChgDivVlvCtrlState = Init;
        break;
    }  
    if(TrbChgDivVlv_Ovr_En_P){
        duty = TrbChgDivVlv_OvrDty_Pct_P;
    }
    Set_TrbChgDivVlvDty_Pct(duty);
}