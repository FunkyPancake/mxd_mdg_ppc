/*
 * eqadc.c
 *
 *  Created on: Dec 10, 2015
 *      Author: Mati
 */
#include "Std_Types.h"
#include "eqadc.h"
#include "MPC5644A.h"
#include <stdlib.h>

inline int ADC_u16Compare(const void *p0, const void *p1)
{
    uint32 a0 = (uint16) * (uint16 *)p0;
    uint32 a1 = (uint16) * (uint16 *)p1;

    if (a0 == a1)
        return 0;
    if (a0 < a1)
        return -1;
    else
        return 1;
}
void DmacConfig(uint8 DMA_chan, void *cmd_source, void *cmd_dest,
                uint8 cmd_count, void *rec_source, void *rec_dest, uint8 rec_count)
{
    EDMA.CERQR.R = (uint8)DMA_chan;     // disable this channel
    EDMA.CERQR.R = (uint8)DMA_chan + 1; // disable this channel

    /* Transfer Control Descriptor for CFIFO 00 - CH0-see RM 9.3.1.16, 9-23, pg 335          */
    EDMA.TCD[DMA_chan].SADDR = (uint32)cmd_source; //Start Address
    EDMA.TCD[DMA_chan].DADDR = (uint32)cmd_dest;   //Destination Address
    EDMA.TCD[DMA_chan].DSIZE = 0x02;               //Destination Transfer Size:32 bits
    EDMA.TCD[DMA_chan].SSIZE = 0x02;               //Source Transfer Size:32 bits
    EDMA.TCD[DMA_chan].SOFF = 0x4;                 //Signed Source Address Offset in bytes
    EDMA.TCD[DMA_chan].NBYTES = 0x4;               //Inner 'Minor' Byte Count
    EDMA.TCD[DMA_chan].SLAST = cmd_count * -4;     //Signed, # bytes to get Source Address Adjust Back to Start
    EDMA.TCD[DMA_chan].DOFF = 0x0;                 //Signed Destination Address Offset
    EDMA.TCD[DMA_chan].DLAST_SGA = 0x0;            //Signed Destination Address Adjust
    EDMA.TCD[DMA_chan].BITER = cmd_count;          //Beginning 'Major' Iteration Count
    EDMA.TCD[DMA_chan].CITER = cmd_count;          //Current 'Major' Iteration Count
    EDMA.TCD[DMA_chan].D_REQ = 0x0;                //Disables DMA Channel When Done
    EDMA.TCD[DMA_chan].SMOD = 0x00;                //Source Address Modulo
    EDMA.TCD[DMA_chan].DMOD = 0x00;                //Destination Address Modulo
    EDMA.TCD[DMA_chan].BWC = 0x0;                  //Bandwidth control:  No DMA Stalls
    EDMA.TCD[DMA_chan].MAJORLINKCH = 0x00;         //Major Channel Number
    EDMA.TCD[DMA_chan].MAJORE_LINK = 0x0;          //Major Channel Link:  Disabled
    EDMA.TCD[DMA_chan].DONE = 0x00;                //Channel Done
    EDMA.TCD[DMA_chan].ACTIVE = 0x00;              //Channel Active
    EDMA.TCD[DMA_chan].E_SG = 0x0;                 //Enable Scatter/Gather:  Disabled
    EDMA.TCD[DMA_chan].INT_HALF = 0x0;             //Interrupt on Minor Loop Count:  Disabled
    EDMA.TCD[DMA_chan].INT_MAJ = 0x0;              //Interrupt on Major Loop Count Completion
    EDMA.TCD[DMA_chan].START = 0x00;               //Explicit Channel Start Bit
    EDMA.TCD[DMA_chan].BITERE_LINK = 0;            // Linking Not Used
    EDMA.TCD[DMA_chan].CITERE_LINK = 0;            // Linking Not Used
    /* Transfer Control Descriptor for RFIFO 00 - CH1-see RM 9.3.1.16, 9-23, pg 335          */
    EDMA.TCD[DMA_chan + 1].SADDR = (uint32)rec_source; //Start Address
    EDMA.TCD[DMA_chan + 1].DADDR = (uint32)rec_dest;   //Destination Address
    EDMA.TCD[DMA_chan + 1].DSIZE = 0x01;               //Destination Transfer Size:16 bits
    EDMA.TCD[DMA_chan + 1].SSIZE = 0x01;               //Source Transfer Size:16 bits
    EDMA.TCD[DMA_chan + 1].SOFF = 0x0;                 //Signed Source Address Offset
    EDMA.TCD[DMA_chan + 1].NBYTES = 0x2;               //Inner 'Minor' Byte Count
    EDMA.TCD[DMA_chan + 1].SLAST = 0x0;                //Signed Source Address Adjust
    EDMA.TCD[DMA_chan + 1].DOFF = 0x2;                 //Signed Destination Address Offset in bytes
    EDMA.TCD[DMA_chan + 1].DLAST_SGA = rec_count * -2; //Signed Dest Address Adjust Back to Start - # bytes
    EDMA.TCD[DMA_chan + 1].BITER = rec_count;          //Beginning 'Major' Iteration Count
    EDMA.TCD[DMA_chan + 1].CITER = rec_count;          //Current 'Major' Iteration Count:  Disabled
    EDMA.TCD[DMA_chan + 1].D_REQ = 0x0;                //Disables DMA Channel When Done
    EDMA.TCD[DMA_chan + 1].SMOD = 0x00;                //Source Address Modulo
    EDMA.TCD[DMA_chan + 1].DMOD = 0x00;                //Destination Address Modulo
    EDMA.TCD[DMA_chan + 1].BWC = 0x0;                  //Bandwidth control:  No DMA Stalls
    EDMA.TCD[DMA_chan + 1].MAJORLINKCH = 0x00;         //Major Channel Number
    EDMA.TCD[DMA_chan + 1].MAJORE_LINK = 0x0;          //Major Channel Link:  Disabled
    EDMA.TCD[DMA_chan + 1].DONE = 0x00;                //Channel Done
    EDMA.TCD[DMA_chan + 1].ACTIVE = 0x00;              //Channel Active
    EDMA.TCD[DMA_chan + 1].E_SG = 0x0;                 //Enable Scatter/Gather:  Disabled
    EDMA.TCD[DMA_chan + 1].INT_HALF = 0x0;             //Interrupt on Minor Loop Count:  Disabled
    EDMA.TCD[DMA_chan + 1].INT_MAJ = 0x0;              //Interrupt on Major Loop Count Completion
    EDMA.TCD[DMA_chan + 1].START = 0x00;               //Explicit Channel Start Bit
    EDMA.TCD[DMA_chan + 1].BITERE_LINK = 0;            // Linking Not Used
    EDMA.TCD[DMA_chan + 1].CITERE_LINK = 0;            // Linking Not Used
    EDMA.SERQR.R = (uint8)DMA_chan;                    // enable this channel
    EDMA.SERQR.R = (uint8)DMA_chan + 1;                // enable this channel
}

void EQADCStartupCalibration(void)
{
    uint32 timeout;
    uint16 tmprfifo0[24];
    uint16 tmprfifo1[24];
    uint16 tmprfifo2[24];
    uint16 tmprfifo3[24];
    uint32 sum[4];
    uint16 occ1, occ2;
    uint16 gcc1, gcc2;
    uint8 i;

    for (i = 0; i < 6; i++)
    {
        EQADC.IDCR[i].R = EQADC_CFCR_CFINV_MASK;
    }

    for (i = 0; i < 4; i++)
    {
        sum[i] = 0;
    }

    for (timeout = 0; timeout < 10000; ++timeout)
    {
        ;
    }

    for (i = 0; i < (sizeof(tmprfifo0) / 2); i++)
    {
        PUSH_TO_CFIFO(
            REG_EOQ | ADC(1) | LST(3) | RFIFO(0) | CAL(0) | CHANNEL(VREF_075_CH));
        EQADC.CFCR[0].R = 0x0410;
        while ((EQADC.FISR[0].B.RFDF != 1))
        {
            ;
        }
        tmprfifo2[i] = POP_RFIFO0;
        EQADC.FISR[0].R = 0x10020000;
    }
    for (i = 0; i < (sizeof(tmprfifo1) / 2); i++)
    {
        PUSH_TO_CFIFO(
            REG_EOQ | ADC(0) | LST(3) | RFIFO(0) | CAL(0) | CHANNEL(VREF_025_CH));
        EQADC.CFCR[0].R = 0x0410;
        while ((EQADC.FISR[0].B.RFDF != 1))
        {
            ;
        }
        tmprfifo1[i] = POP_RFIFO0;
        EQADC.FISR[0].R = 0x10020000;
    }
    for (i = 0; i < (sizeof(tmprfifo2) / 2); i++)
    {
        PUSH_TO_CFIFO(
            REG_EOQ | ADC(0) | LST(3) | RFIFO(0) | CAL(0) | CHANNEL(VREF_075_CH));
        EQADC.CFCR[0].R = 0x0410;
        while ((EQADC.FISR[0].B.RFDF != 1))
        {
            ;
        }

        tmprfifo0[i] = POP_RFIFO0;
        EQADC.FISR[0].R = 0x10020000;
    }
    for (i = 0; i < 24; i++)
    {
        PUSH_TO_CFIFO(
            REG_EOQ | ADC(1) | LST(3) | RFIFO(0) | CAL(0) | CHANNEL(VREF_025_CH));
        EQADC.CFCR[0].R = 0x0410;
        while ((EQADC.FISR[0].B.RFDF != 1))
        {
            ;
        }

        tmprfifo3[i] = POP_RFIFO0;
        EQADC.FISR[0].R = 0x10020000;
    }
#ifdef MEDIAN_CALIBRATION
    qsort((void *)tmprfifo0, (sizeof(tmprfifo0) / 2), sizeof(tmprfifo0[0]),
          ADC_u16Compare);
    qsort((void *)tmprfifo1, (sizeof(tmprfifo1) / 2), sizeof(tmprfifo1[0]),
          ADC_u16Compare);
    qsort((void *)tmprfifo2, (sizeof(tmprfifo2) / 2), sizeof(tmprfifo2[0]),
          ADC_u16Compare);
    qsort((void *)tmprfifo3, (sizeof(tmprfifo3) / 2), sizeof(tmprfifo3[0]),
          ADC_u16Compare);
    sum[0] = tmprfifo0[12];
    sum[1] = tmprfifo1[12];
    sum[2] = tmprfifo2[12];
    sum[3] = tmprfifo3[12];
#else
    /*mean value of samples*/
    for (i = 0; i < 24; i++)
    {
        if (tmprfifo0[i] != 0)
            sum[0] += tmprfifo0[i];
        if (tmprfifo1[i] != 0)
            sum[1] += tmprfifo1[i];
        if (tmprfifo2[i] != 0)
            sum[2] += tmprfifo2[i];
        if (tmprfifo3[i] != 0)
            sum[3] += tmprfifo3[i];
    }
    sum[0] = sum[0] / 23;
    sum[1] = sum[1] / 23;
    sum[2] = sum[2] / 23;
    sum[3] = sum[3] / 23;
#endif
    /*calc new coef*/
    gcc1 = ((IDEAL_RES75 - IDEAL_RES25) << 14) / (sum[0] - sum[1]);
    gcc2 = ((IDEAL_RES75 - IDEAL_RES25) << 14) / (sum[2] - sum[3]);
    occ1 = (uint16)(IDEAL_RES75 - ((uint32)(gcc1 * sum[0]) >> 14) - 2);
    occ2 = (uint16)(IDEAL_RES75 - ((uint32)(gcc2 * sum[2]) >> 14) - 2);
    /*write new calibration coefitients to registers*/
    for (i = 0; i < 6; i++)
    {
        EQADC.IDCR[i].R = EQADC_CFCR_CFINV_MASK;
    }
    PUSH_TO_CFIFO(BN(0) | ADC_REG_ADDR(ADC0_GCCR) | ADC_REG_VALUE(gcc1));
    PUSH_TO_CFIFO(BN(0) | ADC_REG_ADDR(ADC0_OCCR) | ADC_REG_VALUE(occ1));
    PUSH_TO_CFIFO(BN(1) | ADC_REG_ADDR(ADC1_GCCR) | ADC_REG_VALUE(gcc2));
    PUSH_TO_CFIFO(
        REG_EOQ | BN(1) | ADC_REG_ADDR(ADC1_OCCR) | ADC_REG_VALUE((uint16)occ2));
    //buffer 1
    /* enable ADC0 & ADC1 & sets prescaler= divide by 10*/

    EQADC.CFCR[0].R = 0x0410; /* Trigger CFIFO 0 using Single Scan SW mode */
    while (EQADC.FISR[0].B.EOQF != 1)
    {
    } /* Wait for End Of Queue flag */

    EQADC.FISR[0].B.EOQF = 1; /* Clear End Of Queue flag */

    for (i = 0; i < 6; i++)
    {
        EQADC.IDCR[i].R = EQADC_CFCR_CFINV_MASK;
    }
}

void EQADC_StartConfig(void)
{
    EQADC.MCR.R = 0;
    EQADC.ETDFR.R = 0;
    PUSH_TO_CFIFO(
        BN(0) | ADC_REG_ADDR(ADC0_CR) | ADC_REG_VALUE(AD_ENABLE | AD_CLOCK(0x08)));
    PUSH_TO_CFIFO(
        BN(1) | ADC_REG_ADDR(ADC_ACR1) | ADC_REG_VALUE(AD_DEST(0x01) | AD_GAIN(0x01) | AD_FMTA(1)));
    PUSH_TO_CFIFO(
        REG_EOQ | BN(1) | ADC_REG_ADDR(ADC1_CR) | ADC_REG_VALUE(AD_ENABLE | AD_CLOCK(0x04)));
    //buffer 1
    /* enable ADC0 & ADC1 & sets prescaler= divide by 10*/ EQADC.CFCR[0].R =
        0x0410; /* Trigger CFIFO 0 using Single Scan SW mode */
    while (EQADC.FISR[0].B.EOQF != 1)
    {
    }                         /* Wait for End Of Queue flag */
    EQADC.FISR[0].B.EOQF = 1; /* Clear End Of Queue flag */
}
Std_ReturnType EQADC_ConfigureADC()
{
}
Std_ReturnType EQADC_ConfigureFIFO()
{
}

Std_ReturnType EQADC_BuildCFIFIOEntry()
{
}