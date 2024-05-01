/*
 * EQADC_Cfg.c
 *
 *  Created on: Nov 24, 2018
 *      Author: Mati
 */

#include "Std_Types.h"
#include "EQADC_Cfg.h"
#include "EQADC_Out.h"
#include "EQADC.h"
#include "MPC5644A.h"
#ifndef NULL
#define NULL 0
#endif

#define BSW_START_SEC_VAR_32BIT
#include "BSW_MemMap.h"

uint32 cfifo0[] =
    {
        (ADC(1) | LST(0) | RFIFO(0) | CAL(0) | CHANNEL(ADC_KNOCK_CH) | REG_EOQ | FFMT(1) | ALT_CFG(0x08))};

uint32 cfifo1[] =
    {
        (ADC(0) | LST(1) | RFIFO(1) | CAL(1) | CHANNEL(ADC_PIN1_CH)),
        (ADC(0) | LST(1) | RFIFO(1) | CAL(1) | CHANNEL(ADC_PIN2_CH)),
        (ADC(0) | LST(1) | RFIFO(1) | CAL(1) | CHANNEL(ADC_PIN3_CH)),
        (ADC(0) | LST(1) | RFIFO(1) | CAL(1) | CHANNEL(ADC_PIN8_CH) | REG_EOQ)};

uint32 cfifo2[] =
    {
        (ADC(0) | LST(1) | RFIFO(2) | CAL(1) | CHANNEL(ADC_PIN18_CH)),
        (ADC(0) | LST(1) | RFIFO(2) | CAL(1) | CHANNEL(ADC_PIN23_CH)),
        (ADC(0) | LST(1) | RFIFO(2) | CAL(1) | CHANNEL(ADC_PIN24_CH)),
        (ADC(0) | LST(1) | RFIFO(2) | CAL(1) | CHANNEL(ADC_EGT_CH) | REG_EOQ)};

uint32 cfifo3[] =
    {
        (ADC(0) | LST(1) | RFIFO(3) | CAL(1) | CHANNEL(ADC_PIN4_CH)),
        (ADC(0) | LST(1) | RFIFO(3) | CAL(1) | CHANNEL(ADC_PIN9_CH)),
        (ADC(0) | LST(1) | RFIFO(3) | CAL(1) | CHANNEL(ADC_PIN17_CH)),
        (ADC(0) | LST(1) | RFIFO(3) | CAL(1) | CHANNEL(ADC_VBAT_CH)),
        (ADC(0) | LST(1) | RFIFO(3) | CAL(1) | CHANNEL(ADC_ATEMP_CH) | REG_EOQ)};

#define BSW_STOP_SEC_VAR_32BIT
#include "BSW_MemMap.h"

#define BSW_START_SEC_VAR_NOINIT_16BIT
#include "BSW_MemMap.h"

uint16 rfifo1[sizeof(cfifo1) / 4];
uint16 rfifo2[sizeof(cfifo2) / 4];
uint16 rfifo3[sizeof(cfifo3) / 4];

#define BSW_STOP_SEC_VAR_NOINIT_16BIT
#include "BSW_MemMap.h"

#define BSW_START_SEC_CODE

#include "BSW_MemMap.h"
void EQADC_Init(void)
{
    EQADC_StartConfig();
    EQADCStartupCalibration();
    DmacConfig(0, &cfifo0[0], (void *)CFIFO0_PUSH, sizeof(cfifo0) / 4, NULL,
               NULL, 0);
    DmacConfig(2, &cfifo1[0], (void *)CFIFO1_PUSH, sizeof(cfifo1) / 4,
               (void *)RFIFO1_POP, &rfifo1[0], sizeof(rfifo1) / 2);
    DmacConfig(4, &cfifo2[0], (void *)CFIFO2_PUSH, sizeof(cfifo2) / 4,
               (void *)RFIFO2_POP, &rfifo2[0], sizeof(rfifo2) / 2);
    DmacConfig(6, &cfifo3[0], (void *)CFIFO3_PUSH, sizeof(cfifo3) / 4,
               (void *)RFIFO3_POP, &rfifo3[0], sizeof(rfifo3) / 2);
    //    /*CH 0 special knock channel*/
    //    EQADC .IDCR[0].R = EQADC_IDCR_CFFE_MASK | EQADC_IDCR_CFFS_MASK;
    //    EQADC .CFCR[0].B.MODE = RISING_EXT_CS;
    //    SIU .ISEL3.B.ETSEL0 = 0b01110; // SIU_ISEL1 -> eTPU30

    /*Enable DMA Requests for CFIFO and RFIFO*/
    EQADC.IDCR[1].R = EQADC_IDCR_CFFE_MASK | EQADC_IDCR_CFFS_MASK | EQADC_IDCR_RFDE_MASK | EQADC_IDCR_RFDS_MASK;
    EQADC.CFCR[1].B.MODE = RISING_EXT_CS;
    SIU.ISEL3.B.ETSEL1 = 0b00010; // SIU_ISEL3 -> PIT1 trigger

    EQADC.IDCR[2].R = EQADC_IDCR_CFFE_MASK | EQADC_IDCR_CFFS_MASK | EQADC_IDCR_RFDE_MASK | EQADC_IDCR_RFDS_MASK;
    EQADC.CFCR[2].B.MODE = RISING_EXT_CS;
    SIU.ISEL3.B.ETSEL2 = 0b00011; // SIU_ISEL3 -> PIT2 trigger

    EQADC.IDCR[3].R = EQADC_IDCR_CFFE_MASK | EQADC_IDCR_CFFS_MASK | EQADC_IDCR_RFDE_MASK | EQADC_IDCR_RFDS_MASK;
    EQADC.CFCR[3].B.MODE = RISING_EXT_CS;
    SIU.ISEL3.B.ETSEL3 = 0b00100; // SIU_ISEL3 -> PIT3 trigger
}
inline uint16 EQADC_CalcU_mV(uint16 adc_result_raw)
{
    return (uint16)(((uint32)adc_result_raw * EQADC_MAX_MV) / EQADC_MAX_CODE);
}
inline uint16 EQADC_CalcR_Ohm(uint16 adc_result_raw)
{
    uint32 result = (((uint32)adc_result_raw * EQADC_R_PULLUP_OHM) / ((EQADC_MAX_CODE - 1) - (uint32)adc_result_raw));
    return result > 0xffff ? 0xffff : (uint16)result;
}

void EQADC_ReadResults_1ms()
{
    Set_An_Pin1_U_mV(EQADC_CalcU_mV(rfifo1[0]));
    Set_An_Pin2_U_mV(EQADC_CalcU_mV(rfifo1[1]));
    Set_An_Pin3_U_mV(EQADC_CalcU_mV(rfifo1[2]));
    Set_An_Pin8_U_mV(EQADC_CalcU_mV(rfifo1[3]));
}

void EQADC_ReadResults_20ms()
{
    Set_An_Pin18_U_mV(EQADC_CalcU_mV(rfifo2[0]));
    Set_An_Pin23_U_mV(EQADC_CalcU_mV(rfifo2[1]));
    Set_An_Pin24_U_mV(EQADC_CalcU_mV(rfifo2[2]));
    Set_An_Pin25_U_mV(EQADC_CalcU_mV(rfifo2[3]));
}

void EQADC_ReadResults_100ms()
{
    Set_An_Pin4_Res_Ohm(EQADC_CalcR_Ohm(rfifo3[0]));
    Set_An_Pin9_Res_Ohm(EQADC_CalcR_Ohm(rfifo3[1]));
    Set_An_Pin17_Res_Ohm(EQADC_CalcR_Ohm(rfifo3[2]));
    Set_An_KL30_U_mV(EQADC_CalcU_mV(rfifo3[3]));
    Set_An_TempSns_U_mV(EQADC_CalcU_mV(rfifo3[4]));
}
#define BSW_STOP_SEC_CODE
#include "BSW_MemMap.h"
