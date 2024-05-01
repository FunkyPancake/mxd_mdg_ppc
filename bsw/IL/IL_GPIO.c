/*
 * IL_GPIO.c
 *
 *  Created on: Dec 23, 2018
 *      Author: Mati
 */


#include "Std_Types.h"
#include "IL_GPIO.h"
#include "GPIO_Cfg.h"
#include "gpio.h"
#include "BrkVacPmpCtrl_Out.h"
#include "CltFanCtrl_Out.h"
#include "FuPmpCtrl_Out.h"

void IL_BrkPmpRlyGpio(void)
{
    boolean state = Get_BrkBostRlyEn();
    gpio_write_data(PAD_PWM78, state);
}

void IL_CltFanRlyGpio(void)
{
    boolean state = Get_CltFanRlySt();
    gpio_write_data(PAD_PWM56, state);
}

void IL_FuPmpRlyGpio(void)
{
    boolean state = Get_FuPmpRlySt();
    gpio_write_data(PAD_PWM34, state);

}

void PerEn_Set(void)
{
    boolean state = 1;
    gpio_write_byte(PAD_OUTEN, state);

}

void AuxEn_Set(void)
{
    boolean state = 1;
    gpio_write_data(PAD_VSNS_EN, state);
}
