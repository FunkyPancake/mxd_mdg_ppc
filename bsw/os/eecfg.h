#ifndef EECFG_H
#define EECFG_H


#define RTDRUID_CONFIGURATOR_NUMBER 1278



/***************************************************************************
 *
 * Common defines ( CPU 0 )
 *
 **************************************************************************/

    /* TASK definition */
    #define EE_MAX_TASK 6
    #define Task_1ms 0
    #define Task_20ms 1
    #define Task_100ms 2
    #define Task_AngleSync 3
    #define Task_Xcp 4
    #define Task_CalFlash 5

    /* MUTEX definition */
    #define EE_MAX_RESOURCE 1U
    #define AsyncAccess 0U

    /* EVENT definition */
    #define Event_AngleSync 0x1U
    #define Event_Timeout 0x2U
    #define Event_XCP_100ms 0x4U
    #define Event_XCP_10ms 0x8U
    #define Event_XCP_1ms 0x10U
    #define Event_XCP_ASync 0x20U

    /* ALARM definition */
    #define EE_MAX_ALARM 5U
    #define Alarm_1ms 0U
    #define Alarm_20ms 1U
    #define Alarm_100ms 2U
    #define Alarm_Timeout 3U
    #define Alarm_10ms 4U

    /* SCHEDULING TABLE definition */
    #define EE_MAX_SCHEDULETABLE 0U

    /* COUNTER OBJECTS definition */
    #define EE_MAX_COUNTER_OBJECTS (EE_MAX_ALARM + EE_MAX_SCHEDULETABLE)

    /* CPU CLOCK definition */
    #define EE_CPU_CLOCK      120000000U

    /* COUNTER definition */
    #define EE_MAX_COUNTER 1U
    #define system_timer 0U

    /* APPMODE definition */
    #define EE_MAX_APPMODE 1U

    /* CPUs */
    #define EE_MAX_CPU 1
    #define EE_CURRENTCPU 0

    /* Number of isr 2 */
    #define EE_MAX_ISR2   4
    #define EE_MAX_ISR_ID 4

#ifndef __DISABLE_EEOPT_DEFINES__


/***************************************************************************
 *
 * User options
 *
 **************************************************************************/
#define __CODEWARRIOR__
#define EE_ISR_DYNAMIC_TABLE
#define EE_SYSTEM_TIMER_DEVICE_DECREMENTER
#define __USE_CUSTOM_LINKER_SCRIPT__
#define __USE_CUSTOM_CRT0__


/***************************************************************************
 *
 * Automatic options
 *
 **************************************************************************/
#define __RTD_CYGWIN__
#define __PPCE200ZX__
#define EE_PPCE200Z4
#define ENABLE_SYSTEM_TIMER
#define __VLE__
#define __DIAB__
#define __OO_ORTI_LASTERROR__
#define __OO_ORTI_SERVICETRACE__
#define __OO_ORTI_PRIORITY__
#define __OO_ORTI_RES_LOCKER_TASK__
#define __OO_ORTI_RES_ISLOCKED__
#define __OO_ORTI_STACK__
#define __OO_ORTI_ALARMTIME__
#define __OO_ORTI_RUNNINGISR2__
#define __OO_ECC2__
#define __OO_EXTENDED_STATUS__
#define __OO_HAS_STARTUPHOOK__
#define __OO_HAS_PRETASKHOOK__
#define __IRQ_STACK_NEEDED__
#define __MULTI__
#define __OO_AUTOSTART_TASK__
#define __OO_AUTOSTART_ALARM__
#define __ALLOW_NESTED_IRQ__

#endif

    /* System stack size */
    #define EE_SYS_STACK_SIZE     4096



/***************************************************************************
 *
 * HW counter definition
 *
 **************************************************************************/
#define EE_MAX_COUNTER_HW 1
#define EE_SYSTEM_TIMER   system_timer
#define EE_SYSTEM_TIMER_DEVICE   EE_PPCE200ZX_DECREMENTER

#define EE_PPCE200ZX_DECREMENTER_ISR EE_e200zx_system_timer_handler


/***************************************************************************
 *
 * Counter defines
 *
 **************************************************************************/
#define OSMAXALLOWEDVALUE_system_timer 2147483647U
#define OSTICKSPERBASE_system_timer    1U
#define OSMINCYCLE_system_timer        1U

#define OSMAXALLOWEDVALUE 2147483647U
#define OSTICKSPERBASE    1U
#define OSMINCYCLE        1U
#define OSTICKDURATION    1000000U



/***************************************************************************
 *
 * Vector size defines
 *
 **************************************************************************/
    #define EE_ACTION_ROM_SIZE 5
    #define EE_ALARM_ROM_SIZE 5
    #define EE_COUNTER_HW_ROM_SIZE 1
    #define EE_COUNTER_OBJECTS_ROM_SIZE 5
    #define EE_COUNTER_ROM_SIZE 1
    #define EE_E200Z7_SYSTEM_TOS_SIZE 4
    #define EE_OO_AUTOSTART_ALARM_MODE_OSDEFAULTAPPMODE_SIZE 4
    #define EE_OO_AUTOSTART_TASK_MODE_OSDEFAULTAPPMODE_SIZE 2
    #define EE_RQ_PAIRS_NEXT_SIZE 6
    #define EE_RQ_PAIRS_TID_SIZE 6
    #define EE_RQ_QUEUES_HEAD_SIZE 16
    #define EE_RQ_QUEUES_TAIL_SIZE 16


#endif

