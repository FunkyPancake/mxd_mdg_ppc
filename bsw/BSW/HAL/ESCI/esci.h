/*
 * esci.h
 *
 *  Created on: Jan 23, 2016
 *      Author: Mati
 */

#ifndef ESCI_H_
#define ESCI_H_



#ifdef ESCI_C_
    #define EXTERNAL_ 
#else
    #define EXTERNAL_ extern   
#endif

#define ESCI_A_DMA_TX_CHN 18
#define ESCI_A_DMA_RX_CHN 19


void esci_a_config(void);
void ESCI_A_DmaInit(void);
sint8 ESCI_A_WriteDma(const void* address,const uint16 size);
sint8 ESCI_A_ReadDma(const void* address,const uint16 size);
void ESCI_A_TdmaIsr(void);
void ESCI_A_RdmaIsr(void);
uint8 ESCI_A_RxIsr(void);
void ESCI_A_WritePoll(uint8 data);

  
  
#ifdef EXTERNAL_
#undef EXTERNAL_
#endif

#endif /* ESCI_H_ */
