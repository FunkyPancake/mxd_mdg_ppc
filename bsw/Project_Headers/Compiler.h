/*
 * Compiler.h
 *
 *  Created on: Oct 23, 2018
 *      Author: Mati
 */

#ifndef COMPILER_H_
#define COMPILER_H_

//#define DEBUG
#define __MWERKS__
//#define ASW_ENABLE

#define LOCAL_INLINE <ret type> <functionname> (<parameter-list>) static inline functionname() __atribute__ ((always_inline))
#define SYSCLK 120000000

#define PARAM_UNUSED(param)  ((void)(param))
#define E200_ISR_OFFSET 16
//#define EE_CPU_CLOCK (SYSCLK/1e6)
#define USE_XCP
#define XCP_INTERRUPT_CONTROL
#define XCP_ON_UART
#endif /* COMPILER_H_ */
