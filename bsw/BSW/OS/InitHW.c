/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2010  Evidence Srl
 *
 * This file is part of ERIKA Enterprise.
 *
 * ERIKA Enterprise is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation, 
 * (with a special exception described below).
 *
 * Linking this code statically or dynamically with other modules is
 * making a combined work based on this code.  Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * As a special exception, the copyright holders of this library give you
 * permission to link this code with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module.  An independent module is a module which is not derived from
 * or based on this library.  If you modify this code, you may extend
 * this exception to your version of the code, but you are not
 * obligated to do so.  If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * ERIKA Enterprise is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with ERIKA Enterprise; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 * ###*E*### */

/*
 * Author: 2014,  Francesco Esposito
 * Company: Evidence SRL
 */
#include "Std_Types.h"
#include "InitHW.h"
#include "GPIO_Cfg.h"
#include "EMIOS_Cfg.h"
#include "PIT_Cfg.h"
#include "fmpll.h"
#include "ESCI_Cfg.h"
#include "EQADC_Cfg.h"
//#include "IntcInterrupts.h"
#include "ETPU_Cfg.h"
#include "IL_ETPU.h"
//#include "IL_PIT.h"
#include "ee_irq.h"

#define MODULE_ID (15)

void InitHW(void)
{

  fmpll_config();
  //InitCRC(); - currently not needed
  //  InitSPI();
  //  InitCAN();
  InitESCI();
  EQADC_Init();
  // InitETPU();
  //  my_system_etpu_init();
  EMIOS_Init();
  PIT_Init();
  // InitWatchdog();
  InitGPIO();
  //  InitCDDs();
}
void EnableIsr(void)
{
  ESCI_EnableIsr();
  //    ETPU_EnableCrankIsr();
  //    EE_e200z7_register_ISR(PIT_ISR_1ms,PIT_IRQ_TEST,2);

  EE_e200z7_enableIRQ();

  //  my_system_etpu_start();
}
