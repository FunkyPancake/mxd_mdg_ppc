#include "CDD_MC33926.h"

#include "GPIO_Cfg.h"
#include "gpio.h"
#include "EMIOS.h"
#include "EMIOS_Cfg.h"
#include "CDD_MC33926_Out.h"

#define BSW_START_SEC_CODE
#include "BSW_MemMap.h"
void CDD_MC33926_Init(void)
{
    gpio_config(PAD_HBRIDGE_IN1, GPIO_PRIMARY_FUNCTION | GPIO_OUTPUT_BUFFER_ENABLE);
    gpio_config(PAD_HBRIDGE_IN2, GPIO_IO_FUNCTION | GPIO_OUTPUT_BUFFER_ENABLE);
    gpio_config(PAD_HBRIDGE_INV, GPIO_IO_FUNCTION | GPIO_OUTPUT_BUFFER_ENABLE);
    gpio_config(PAD_HBRIDGE_SLEW, GPIO_IO_FUNCTION | GPIO_OUTPUT_BUFFER_ENABLE);
    gpio_config(PAD_HBRIDGE_SF, GPIO_IO_FUNCTION | GPIO_INPUT_BUFFER_ENABLE);
    gpio_config(PAD_HBRIDGE_D1, GPIO_IO_FUNCTION | GPIO_OUTPUT_BUFFER_ENABLE);

    gpio_write_data(PAD_HBRIDGE_D1, 0);
    gpio_write_data(PAD_HBRIDGE_INV, 0);
    gpio_write_data(PAD_HBRIDGE_IN2, 0);
    gpio_write_data(PAD_HBRIDGE_SLEW, 0);
    emios_ch_config_opwfmb(EMIOS_HBRIDGE_IN1_CHN, 0UL, CDD_MC33926_PWMPERIOD_TICKS, EMIOS_EDPOL_FALLING + EMIOS_BSL_INTERNAL + EMIOS_FCK_MAIN_CLK);
}

void CDD_MC33926_PwmCtrl(void)
{
    uint8 inv;
    sint16 pwm;
    sint32 pwm_ticks;
    pwm = Get_MC33926PwmDty();
    if (pwm == 0)
    {
        inv = 0;
        pwm_ticks = 0;
    }
    else
    {
        if (pwm > 0)
        {
            inv = 0;
        }
        else
        {
            pwm *= -1;
            inv = 1;
        }
        pwm_ticks = pwm * (CDD_MC33926_PWMPERIOD_TICKS / CDD_MC33926_PWM_MAX);
    }
    gpio_write_data(PAD_HBRIDGE_INV, inv);
    emios_ch_write_ab(EMIOS_HBRIDGE_IN1_CHN, pwm_ticks, CDD_MC33926_PWMPERIOD_TICKS);
}
#define BSW_STOP_SEC_CODE
#include "BSW_MemMap.h"
