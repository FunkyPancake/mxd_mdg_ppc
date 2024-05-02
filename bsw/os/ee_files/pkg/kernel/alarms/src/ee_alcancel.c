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
 * CVS: $Id: ee_alcancel.c,v 1.3 2006/12/03 22:03:53 pj Exp $
 */

#include "../../frsh/inc/ee_internal.h"

#ifndef __PRIVATE_ALARM_CANCEL__
void EE_alarm_CancelAlarm(AlarmType AlarmID)
{
  register AlarmType current, previous;
  register EE_FREG flag;

  flag = EE_hal_begin_nested_primitive();

  /* to compute the relative value in ticks, we have to follow the counter
     delay chain */
  current = EE_counter_RAM[EE_alarm_ROM[AlarmID].c].first;

  /* check if there are alarms pending*/
  if (current == (AlarmType)-1) {
    /* alarm not present */
    EE_hal_end_nested_primitive(flag);
    return;
  }

  if (current == AlarmID) {
    /* the alarm is the first one in the delta queue */
    EE_counter_RAM[EE_alarm_ROM[AlarmID].c].first = 
      EE_alarm_RAM[AlarmID].next;
  } else {
    /* the alarm is not the first one in the delta queue */
    do {
      previous = current;
      current = EE_alarm_RAM[current].next;
      if (current == (AlarmType)-1) {
	/* alarm not present */
	EE_hal_end_nested_primitive(flag);
	return;
      }
    } while (current != AlarmID);
    EE_alarm_RAM[previous].next = EE_alarm_RAM[AlarmID].next;
  }

  if (EE_alarm_RAM[AlarmID].next != (EE_TYPEALARM)-1) {
    EE_alarm_RAM[EE_alarm_RAM[AlarmID].next].delta +=
      EE_alarm_RAM[AlarmID].delta;
  }

  EE_hal_end_nested_primitive(flag);
}
#endif