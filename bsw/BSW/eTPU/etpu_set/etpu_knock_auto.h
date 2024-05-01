
/**************************************************************** 
* WARNING: This file is automatically generated. DO NOT EDIT IT!
*
* COPYRIGHT (c) Freescale 2004-2014, All Rights Reserved
*
* FILE NAME: etpu_knock_auto.h
* ARCHITECTURE: eTPU2
*
* This file was generated by: etpuc_knock.c on Apr  9 2014 , 09:29:37
*
* This file provides an interface between eTPU code and CPU
* code. All references to the eTPU function should be made with
* information in this file. This allows only symbolic
* information to be referenced which allows the eTPU code to be
* optimized without effecting the CPU code.
*****************************************************************/
#ifndef _ETPU_KNOCK_AUTO_H_
#define _ETPU_KNOCK_AUTO_H_

/* Function Configuration Information */
#define FS_ETPU_KNOCK_FUNCTION_NUMBER 5
#define FS_ETPU_KNOCK_TABLE_SELECT 1
#define FS_ETPU_KNOCK_NUM_PARMS 0x20


/* Host Service Request Definitions */
#define FS_ETPU_KNOCK_HSR_INIT 7
#define FS_ETPU_KNOCK_HSR_STOP 5

/* Function Mode Bit Definitions */
#define FS_ETPU_KNOCK_FM0_ACTIVE_HIGH 0
#define FS_ETPU_KNOCK_FM0_ACTIVE_LOW 1
#define FS_ETPU_KNOCK_FM1_MODE_GATE (0 <<1)
#define FS_ETPU_KNOCK_FM1_MODE_TRIGGER (1 <<1)

/* Parameter Definitions */
#define FS_ETPU_KNOCK_OFFSET_P_WINDOW_FIRST 0x1
#define FS_ETPU_KNOCK_OFFSET_P_WINDOW 0x5
#define FS_ETPU_KNOCK_OFFSET_TDC_ANGLE 0x9
#define FS_ETPU_KNOCK_OFFSET_TDC_ANGLE_ACTUAL 0xd
#define FS_ETPU_KNOCK_OFFSET_TCR2_WINDOW_START 0x11
#define FS_ETPU_KNOCK_OFFSET_TCR2_WINDOW_END 0x15
#define FS_ETPU_KNOCK_OFFSET_TRIGGER_PERIOD 0x19
#define FS_ETPU_KNOCK_OFFSET_WINDOW_COUNT 0x0
#define FS_ETPU_KNOCK_OFFSET_WINDOW_COUNTER 0x4
#define FS_ETPU_KNOCK_OFFSET_IRQ_DMA_OPTIONS 0x8

/* Window Structure Definitions */
#define FS_ETPU_KNOCK_WINDOW_OFFSET_START 0x01
#define FS_ETPU_KNOCK_WINDOW_OFFSET_WIDTH 0x05
#define FS_ETPU_KNOCK_WINDOW_STRUCT_SIZE 0x08

/* IRQ & DMA Options */
#define FS_ETPU_KNOCK_IRQ_AT_WINDOW_START 0x01
#define FS_ETPU_KNOCK_IRQ_AT_WINDOW_END 0x02
#define FS_ETPU_KNOCK_IRQ_AT_EVERY_TRIGGER 0x04
#define FS_ETPU_KNOCK_DMA_AT_WINDOW_START 0x10
#define FS_ETPU_KNOCK_DMA_AT_WINDOW_END 0x20
#define FS_ETPU_KNOCK_DMA_AT_EVERY_TRIGGER 0x40

#endif
