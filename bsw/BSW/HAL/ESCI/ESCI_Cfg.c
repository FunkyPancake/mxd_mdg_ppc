/*
 * ESCI_Cfg.c
 *
 *  Created on: Nov 20, 2018
 *      Author: Mati
 */

#ifndef ESCI_CFG_C_
#define ESCI_CFG_C_

#include "Std_Types.h"

#include "ESCI_Cfg.h"
#include "esci.h" 
#include "xcp_if.h"
#include "ee_irq.h"

void InitESCI(void)
{
    esci_a_config();
}
void ESCI_EnableIsr(void)
{
  EE_e200z7_register_ISR(146+16,Xcp_RxStartIsr,2);
  EE_e200z7_register_ISR(29+16,Xcp_TxStopIsr,2);
  EE_e200z7_register_ISR(30+16,Xcp_RxStopIsr,2);
//    INTC_InstallINTCInterruptHandler(Xcp_RxStartIsr, 146, 1);
//    INTC_InstallINTCInterruptHandler(Xcp_TxStopIsr, 29, 1);
//    INTC_InstallINTCInterruptHandler(Xcp_RxStopIsr, 30, 1);
}

#undef ESCI_CFG_C_
#endif
