/*
 * EQADC_Cfg.h
 *
 *  Created on: Nov 24, 2018
 *      Author: Mati
 */

#ifndef EQADC_CFG_H_
#define EQADC_CFG_H_

#define ADC0_PRESCALER 9
#define ADC1_PRESCALER 19
#define MEDIAN_CALIBRATION

#define EQADC_R_PULLUP_OHM 1000U
#define EQADC_MAX_MV 5000U
#define EQADC_MAX_CODE 0x3FFC
#define ADC_PIN1_CH 8
#define ADC_PIN2_CH 39
#define ADC_PIN3_CH 11
#define ADC_PIN4_CH 17
#define ADC_PIN8_CH 9
#define ADC_PIN9_CH 16
#define ADC_PIN17_CH 37
#define ADC_PIN18_CH 21
#define ADC_PIN23_CH 18
#define ADC_PIN24_CH 36
#define ADC_EGT_CH 3
#define ADC_ATEMP_CH 2
#define ADC_KNOCK_CH 96
#define ADC_VBAT_CH 25

void EQADC_Init(void);

void EQADC_ReadResults_1ms();
void EQADC_ReadResults_20ms();
void EQADC_ReadResults_100ms();

#endif /* EQADC_CFG_H_ */
