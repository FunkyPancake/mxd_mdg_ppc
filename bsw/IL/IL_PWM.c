#include "IL_PWM.h"
#include "CDD_MC33926_Out.h"
#include "TrbChgVtgActr_Out.h"

void IL_PWM_20ms(void)
{
    sint16 pwm = Get_RTrbVtgActrPwm_Pct();
    Set_MC33926PwmDty(pwm);
}