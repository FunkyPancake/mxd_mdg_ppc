/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2008  Evidence Srl
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
 * Author: 2002 Paolo Gai
 * CVS: $Id: ee_spost.c,v 1.7 2007/06/14 10:27:12 pj Exp $
 */

#include "../../frsh/inc/ee_internal.h"

#ifndef __PRIVATE_SEM_POST__
void EE_sem_PostSem(SemRefType s)
{
  register EE_FREG flag;
  EE_TID newthread;

  flag = EE_hal_begin_nested_primitive();

  if (s->first != EE_NIL) {
    newthread = s->first;

      /* wake up blocked thread */
      if ((s->first = EE_th_next[newthread]) == EE_NIL)
        s->last = EE_NIL;
      
      /* check for preemption */ 
#if defined(__FP__)
      if (!EE_hal_get_IRQ_nesting_level() &&
	  EE_sys_ceiling < EE_th_ready_prio[newthread]) {
#else
      if (!EE_hal_get_IRQ_nesting_level() &&
	  (EE_stk_queryfirst() == EE_NIL || 	/* main task! */
	   ((EE_STIME)(EE_th_absdline[EE_stk_queryfirst()] - EE_th_absdline[newthread]) > 0
	    && EE_sys_ceiling < EE_th_ready_prio[newthread])
	  )
	 ) {
#endif
	/* we have to schedule th blocked thread */
#if defined(__MULTI__) || defined(__WITH_STATUS__)
	EE_th_status[newthread] = EE_STACKED;
#endif
	EE_sys_ceiling |= EE_th_dispatch_prio[newthread];
	
	/* insert the extracted task on the topo of the stack */
	EE_th_next[newthread] = EE_stk_queryfirst();
	EE_stkfirst = newthread;
	
	EE_hal_stkchange(newthread);
      }
      else {      
#if defined(__MULTI__) || defined(__WITH_STATUS__)
	EE_th_status[newthread] = EE_READY | EE_WASSTACKED;
#endif
	EE_rq_insert(newthread);
      }
  }
  else
    s->count++;

  EE_hal_end_nested_primitive(flag);
}
#endif
