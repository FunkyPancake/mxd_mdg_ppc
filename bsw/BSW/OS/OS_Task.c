/*
 * OS_Tasks.c
 *
 *  Created on: 07-06-2019
 *      Author: Mati
 */
#include "ee.h"
#include "ee_irq.h"
#include "OS_Task.h"

#include "ASW_Tasks.h"
#include "BSW_Tasks.h"
#include "IL_Tasks.h"
#include "XcpBasic.h"
#include "xcp_if.h"
uint32 task_1ms_cnt, task_xcp_cnt, task_10ms_cnt, task_100ms_cnt, task_async_cnt;
asm volatile void send_OTM(TaskType value);
 asm volatile void send_OTM(TaskType value)
 {
   isync
   lwz r14, value
   mtspr PID0,r14
   isync
 }

void PreTaskHook(void)
{
  TaskType taskid;
  GetTaskID(&taskid);
  send_OTM(taskid);
}

TASK(Task_1ms)
{
  Task_BSW_Pre_1ms();
  Task_IL_Pre_1ms();
  task_1ms_cnt++;
  if (GetResource(AsyncAccess) == E_OK)
  {
    //IntkMafCalc_1ms();
    ReleaseResource(AsyncAccess);
  }

  //  SWT_KickTheDog();

  Task_IL_Post_1ms();
  Task_BSW_Post_1ms();
  SetEvent(Task_Xcp, Event_XCP_1ms);
  TerminateTask();
}

TASK(Task_20ms)
{
  task_10ms_cnt++;

  Task_BSW_Pre_20ms();
  Task_IL_Pre_20ms();

  Task_ASW_20ms();

  Task_IL_Post_20ms();
  Task_BSW_Post_20ms();
  TerminateTask();
}

TASK(Task_100ms)
{
  task_100ms_cnt++;

  Task_BSW_Pre_100ms();
  Task_IL_Pre_100ms();

  Task_ASW_100ms();

  Task_IL_Post_100ms();
  Task_BSW_Post_100ms();
  SetEvent(Task_Xcp, Event_XCP_100ms);
  TerminateTask();
}

TASK(Task_AngleSync)
{
  EventMaskType mask;
  SetRelAlarm(Alarm_Timeout, 32, 0);
  while (1)
  {
    WaitEvent(Event_AngleSync | Event_Timeout);
    GetEvent(Task_AngleSync, &mask);
    if (mask & Event_Timeout)
    {
      ClearEvent(Event_Timeout);
    }
    if (mask & Event_AngleSync)
    {
      ClearEvent(Event_AngleSync);
      CancelAlarm(Alarm_Timeout);
    }
    SetRelAlarm(Alarm_Timeout, 32, 0);
    //      Task_BSW_Pre_Async();

    if (GetResource(AsyncAccess) == E_OK)
    {
      //IntkMafCalc_Async();
      ReleaseResource(AsyncAccess);
    }
    task_async_cnt++;

    //      Task_BSW_Post_Async();
  }
  TerminateTask();
}
TASK(Task_Xcp)
{
  EventMaskType mask;
  XcpInit();

  while (1)
  {
    WaitEvent(Event_XCP_1ms | Event_XCP_10ms | Event_XCP_100ms | Event_XCP_ASync);
    GetEvent(Task_Xcp, &mask);
    if (mask & Event_XCP_1ms)
    {
      XcpEvent(0x01);
      XcpTxHandler();
      ClearEvent(Event_XCP_1ms);
    }
    if (mask & Event_XCP_10ms)
    {
      ClearEvent(Event_XCP_10ms);
      XcpEvent(0x02);
      XcpRxHandler();
      XcpBackground();
    }
    if (mask & Event_XCP_100ms)
    {
      XcpEvent(0x03);
      ClearEvent(Event_XCP_100ms);
    }
    if (mask & Event_XCP_ASync)
    {
      XcpEvent(0x04);
      ClearEvent(Event_XCP_ASync);
    }
    task_xcp_cnt++;
  }

  TerminateTask();
}

TASK(Task_CalFlash)
{
  //  Fls_Srvc();
  TerminateTask();
}

void StartupHook(void)
{
  //executed only once after os start before any task
  StartupHook_BSW();
  //  SetRelAlarm(Alarm_Timeout,32,0);
}
