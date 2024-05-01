/*
 * esci.c
 *
 *  Created on: Jan 23, 2016
 *      Author: Mati
 */
#ifndef ESCI_C_
#define ESCI_C_ 
#include "MPC5644A.h"
#include "esci.h"

void esci_a_config(void)
{
    /*UART Mode*/

    ESCI_A .LCR.B.LIN = 0;
    ESCI_A .CR2.R = 0x200;
    ESCI_A .CR1.B.TE = 1;
    ESCI_A .CR1.B.RE = 1;
    ESCI_A .CR1.B.PT = 0;
    ESCI_A .CR1.B.PE = 0;
    ESCI_A .CR1.B.RIE = 1;
    ESCI_A .CR1.B.SBR = 16;	// baud rate 460800 @ 120MHz
    ESCI_A_DmaInit();
}


void ESCI_A_WritePoll(uint8 data)
{
    ESCI_A .DR.B.D = data;
    while(ESCI_A .SR.B.TC != 1)
        ;
    ESCI_A .SR.B.TC = 1;
}
void ESCI_A_DmaInit(void)
{
    /*Transmit channel*/
    EDMA .CERQR.R = ESCI_A_DMA_TX_CHN;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].SMOD = 0x00;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].SSIZE = 0;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].DMOD = 0x00;    //Destination Address Modulo
    EDMA .TCD[ESCI_A_DMA_TX_CHN].DSIZE = 0;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].SOFF = 1;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].NBYTES = 1;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].SLAST = 0;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].DADDR = (uint32) &ESCI_A .DR.B.D;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].CITERE_LINK = 0;        // Linking Not Used
    EDMA .TCD[ESCI_A_DMA_TX_CHN].CITER = 1;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].DOFF = 0;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].DLAST_SGA = 0;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].BITERE_LINK = 0;        // Linking Not Used
    EDMA .TCD[ESCI_A_DMA_TX_CHN].BITER = 1;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].BWC = 0x0;  //Bandwidth control:  No DMA Stalls
    EDMA .TCD[ESCI_A_DMA_TX_CHN].MAJORLINKCH = 0x00;     //Major Channel Number
    EDMA .TCD[ESCI_A_DMA_TX_CHN].DONE = 0x00;    //Channel Done
    EDMA .TCD[ESCI_A_DMA_TX_CHN].ACTIVE = 0x00;  //Channel Active
    EDMA .TCD[ESCI_A_DMA_TX_CHN].MAJORE_LINK = 0x0; //Major Channel Link:  Disabled
    EDMA .TCD[ESCI_A_DMA_TX_CHN].E_SG = 0x0;  //Enable Scatter/Gather:  Disabled
    EDMA .TCD[ESCI_A_DMA_TX_CHN].D_REQ = 1;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].INT_HALF = 0x0; //Interrupt on Minor Loop Count:  Disabled
    EDMA .TCD[ESCI_A_DMA_TX_CHN].INT_MAJ = 1; //Interrupt on Major Loop Count Completion
    EDMA .TCD[ESCI_A_DMA_TX_CHN].START = 0x00;   //Explicit Channel Start Bit
    EDMA .CDSBR.R = ESCI_A_DMA_TX_CHN;
    EDMA .CER.R = ESCI_A_DMA_TX_CHN;

    /*recieve channel*/EDMA .CERQR.R = ESCI_A_DMA_RX_CHN;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].SMOD = 0x00;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].SSIZE = 0;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].DMOD = 0x00;    //Destination Address Modulo
    EDMA .TCD[ESCI_A_DMA_RX_CHN].DSIZE = 0;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].SOFF = 0;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].NBYTES = 1;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].SLAST = 0;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].SADDR = (uint32) &ESCI_A .DR.B.D;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].CITERE_LINK = 0;        // Linking Not Used
    EDMA .TCD[ESCI_A_DMA_RX_CHN].CITER = 1;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].DOFF = 1;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].DLAST_SGA = 0;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].BITERE_LINK = 0;        // Linking Not Used
    EDMA .TCD[ESCI_A_DMA_RX_CHN].BITER = 1;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].BWC = 0x0;  //Bandwidth control:  No DMA Stalls
    EDMA .TCD[ESCI_A_DMA_RX_CHN].MAJORLINKCH = 0x00;     //Major Channel Number
    EDMA .TCD[ESCI_A_DMA_RX_CHN].DONE = 0x00;    //Channel Done
    EDMA .TCD[ESCI_A_DMA_RX_CHN].ACTIVE = 0x00;  //Channel Active
    EDMA .TCD[ESCI_A_DMA_RX_CHN].MAJORE_LINK = 0x0; //Major Channel Link:  Disabled
    EDMA .TCD[ESCI_A_DMA_RX_CHN].E_SG = 0x0;  //Enable Scatter/Gather:  Disabled
    EDMA .TCD[ESCI_A_DMA_RX_CHN].D_REQ = 1;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].INT_HALF = 0x0; //Interrupt on Minor Loop Count:  Disabled
    EDMA .TCD[ESCI_A_DMA_RX_CHN].INT_MAJ = 1; //Interrupt on Major Loop Count Completion
    EDMA .TCD[ESCI_A_DMA_RX_CHN].START = 0x00;   //Explicit Channel Start Bit
    EDMA .CDSBR.R = ESCI_A_DMA_RX_CHN;
    EDMA .CER.R = ESCI_A_DMA_RX_CHN;
}

sint8 ESCI_A_WriteDma(const void* address, const uint16 size)
{
    if(size == 0)
        return -1;
    ESCI_A .CR2.B.TXDMA = 1;
    EDMA .CERQR.R = ESCI_A_DMA_TX_CHN;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].SADDR = (uint32) address;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].CITER = size;
    EDMA .TCD[ESCI_A_DMA_TX_CHN].BITER = size;
    EDMA .CDSBR.R = ESCI_A_DMA_TX_CHN;
    ESCI_A .SR.B.TDRE = 1;
    EDMA .SERQR.R = ESCI_A_DMA_TX_CHN;
    return 0;
}
sint8 ESCI_A_ReadDma(const void* address, const uint16 size)
{
    if(size == 0)
        return -1;
    ESCI_A .CR2.B.RXDMA = 1;
    ESCI_A .CR1.B.RIE = 0;
    EDMA .CERQR.R = ESCI_A_DMA_RX_CHN;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].DADDR = (uint32) address;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].CITER = size;
    EDMA .TCD[ESCI_A_DMA_RX_CHN].BITER = size;
    EDMA .CDSBR.R = ESCI_A_DMA_RX_CHN;
    EDMA .SERQR.R = ESCI_A_DMA_RX_CHN;
    return 0;
}
void ESCI_A_TdmaIsr(void)
{
    EDMA .CIRQR.R = ESCI_A_DMA_TX_CHN;
    EDMA .CER.R = ESCI_A_DMA_TX_CHN;
    ESCI_A .CR2.B.TXDMA = 0;
    ESCI_A .SR.B.TC = 1;
}
void ESCI_A_RdmaIsr(void)
{
    EDMA .CIRQR.R = ESCI_A_DMA_RX_CHN;
    EDMA .CER.R = ESCI_A_DMA_RX_CHN;
    ESCI_A .CR1.B.RIE = 1;
    ESCI_A .CR2.B.RXDMA = 0;
}

uint8 ESCI_A_RxIsr(void)
{
    uint8 reg_tmp;
    reg_tmp = ESCI_A .DR.B.D;
    ESCI_A .SR.B.RXRDY = 1;
    return reg_tmp;
}

#undef ESCI_C_
#endif
