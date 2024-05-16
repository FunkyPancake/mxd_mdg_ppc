/**************************************************************************/
/* FILE NAME: etpu_struct.h             COPYRIGHT (c) Freescale 2010      */
/* VERSION:  1.3                                  All Rights Reserved     */
/*                                                                        */
/* DESCRIPTION:                                                           */
/* This file contain all of the register and bit field definitions for    */
/* the eTPU module.                                                       */
/*========================================================================*/
/* UPDATE HISTORY                                                         */
/* REV      AUTHOR      DATE       DESCRIPTION OF CHANGE                  */
/* ---   -----------  ---------    ---------------------                  */
/* 1.0   J. Loeliger  26/Nov/04    Initial version of file.               */
/* 1.1   R. Moran     18/Jan/10    Updated with eTPU2 registers           */
/* 1.2   G. Emerson   19/Jan/10    name structure as ETPU_struct          */
/* 1.2   G. Emerson   20/Jan/10    fix typo                               */
/* 1.3   M. Brejl     10/Aug/11    Correction in IDLE register            */
/**************************************************************************/
/*>>>>NOTE! this file is auto-generated please do not edit it!<<<<*/

#ifndef _ETPU_STRUCT_H_
#define _ETPU_STRUCT_H_

#include "Std_Types.h"

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef __MWERKS__
#pragma push
#pragma ANSI_strict off
#endif

/****************************************************************************/
/*                              MODULE :ETPU                                */
/****************************************************************************/

/***************************Configuration Registers**************************/

    struct eTPU_struct {
        union {                 /* MODULE CONFIGURATION REGISTER */
            vuint32 R;
            struct {
                vuint32 GEC:1;        /* Global Exception Clear */
                vuint32 SDMERR:1;     /* SDM Read Error */
                vuint32 WDTOA:1;      /* Watchdog Timeout-eTPU_A */
                vuint32 WDTOB:1;      /* Watchdog Timeout-eTPU_B */
                vuint32 MGE1:1;       /* Microcode Global Exception-ETPU_A */
                vuint32 MGE2:1;       /* Microcode Global Exception-ETPU_B */
                vuint32 ILF1:1;       /* Illegal Instruction Flag-ETPU_A */
                vuint32 ILF2:1;       /* Illegal Instruction Flag-ETPU_B */
                vuint32:3;
                vuint32 SCMSIZE:5;    /* Shared Code Memory size */
                vuint32:4;
                vuint32 SCMMISC:1;    /* SCM MISC Complete/Clear */
                vuint32 SCMMISF:1;    /* SCM MISC Flag */
                vuint32 SCMMISEN:1;   /* SCM MISC Enable */
                vuint32 SCMERR:1;     /* SCM Read Error */
                vuint32:1;
                vuint32 VIS:1;        /* SCM Visability */
                vuint32:5;
                vuint32 GTBE:1;       /* Global Time Base Enable */
            } B;
        } MCR;
        
        union {                 /* COHERENT DUAL-PARAMETER CONTROL */
            vuint32 R;
            struct {
                vuint32 STS:1;        /* Start Status bit */
                vuint32 CTBASE:5;     /* Channel Transfer Base */
                vuint32 PBASE:10;     /* Parameter Buffer Base Address */
                vuint32 PWIDTH:1;     /* Parameter Width */
                vuint32 PARAM0:7;     /* Channel Parameter 0 */
                vuint32 WR:1;         /* Read/Write selection */
                vuint32 PARAM1:7;     /* Channel Parameter 1 */
            } B;
        } CDCR;
        
        uint32 eTPU_reserved0008;  /* 0x0008-0x000B */
        
        union {                 /* MISC Compare Register */
            uint32 R;
            struct {
                vuint32 ETPUMISCCMP:32;   
            } B;
        } MISCCMPR;
        
        union {                 /* SCM off-range Date Register */
            uint32 R;
            struct {
                vuint32 ETPUSCMOFFDATA:32;   
            } B;
        } SCMOFFDATAR;
        
        union {                 /* ETPU_A Configuration Register */
            vuint32 R;
            struct {
                vuint32 FEND:1;       /* Force END */
                vuint32 MDIS:1;       /* Low power Stop */
                vuint32:1;
                vuint32 STF:1;        /* Stop Flag */
                vuint32:4;
                vuint32 HLTF:1;       /* Halt Mode Flag */
                vuint32:3;
                vuint32 FCSS:1;       /* Filter Clock Source Select */
                vuint32 FPSCK:3;      /* Filter Prescaler Clock Control */
                vuint32 CDFC:2;
                vuint32:1;
                vuint32 ERBA:5;       /* Engine Relative Base Address */
                vuint32 SPPDIS:1;     /* Schedule Priority Passing Disable */
                vuint32:2;
                vuint32 ETB:5;        /* Entry Table Base */
            } B;
        } ECR_A;
        
        union {                 /* ETPU_B Configuration Register */
            vuint32 R;
            struct {
                vuint32 FEND:1;       /* Force END */
                vuint32 MDIS:1;       /* Low power Stop */
                vuint32:1;
                vuint32 STF:1;        /* Stop Flag */
                vuint32:4;
                vuint32 HLTF:1;       /* Halt Mode Flag */
                vuint32:3;
                vuint32 FCSS:1;       /* Filter Clock Source Select */
                vuint32 FPSCK:3;      /* Filter Prescaler Clock Control */
                vuint32 CDFC:2;
                vuint32:1;
                vuint32 ERBA:5;       /* Engine Relative Base Address */
                vuint32 SPPDIS:1;     /* Schedule Priority Passing Disable */
                vuint32:2;
                vuint32 ETB:5;        /* Entry Table Base */
            } B;
        } ECR_B;
        
        uint32 eTPU_reserved001C;  /* 0x001C-0x001F */
        
        union {                 /* ETPU_A Timebase Configuration Register */
            uint32 R;
            struct {
                vuint32 TCR2CTL:3;     /* TCR2 Clock/Gate Control */
                vuint32 TCRCF:2;       /* TCRCLK Signal Filter Control */
                vuint32 AM:2;          /* Angle Mode */
                vuint32:3;
                vuint32 TCR2P:6;       /* TCR2 Prescaler Control */
                vuint32 TCR1CTL:2;     /* TCR1 Clock/Gate Control */
                vuint32 TCR1CS:1;      /* TCR1 Clock Source */ 
                vuint32:5;
                vuint32 TCR1P:8;       /* TCR1 Prescaler Control */
            } B;
        } TBCR_A;
        
        union {                 /* ETPU_A TCR1 Visibility Register */
            vuint32 R;
            struct {
                vuint32:8;
                vuint32 TCR1:24;
            } B;
        } TB1R_A;
        
        union {                 /* ETPU_A TCR2 Visibility Register */
            vuint32 R;
            struct {
                vuint32:8;
                vuint32 TCR2:24;
            } B;
        } TB2R_A;
        
        union {                 /* ETPU_A STAC Configuration Register */
            vuint32 R;
            struct {
                vuint32 REN1:1;       /* Resource Enable TCR1 */
                vuint32 RSC1:1;       /* Resource Control TCR1 */
                vuint32:2;
                vuint32 SERVER_ID1:4;   /* TCR1 Server ID */
                vuint32:4;
                vuint32 SRV1:4;       /* Resource Server Slot */
                vuint32 REN2:1;       /* Resource Enable TCR2 */
                vuint32 RSC2:1;       /* Resource Control TCR2 */
                vuint32:2;
                vuint32 SERVER_ID2:4;   /* TCR2 Server ID */
                vuint32:4;
                vuint32 SRV2:4;       /* Resource Server Slot */
            } B;
        } REDCR_A;
        
        uint32 eTPU_reserved0030[4];  /* 0x0030-0x003F */
        
        union {                 /* ETPU_B Timebase Configuration Register */
            uint32 R;
            struct {
                vuint32 TCR2CTL:3;     /* TCR2 Clock/Gate Control */
                vuint32 TCRCF:2;       /* TCRCLK Signal Filter Control */
                vuint32 AM:2;          /* Angle Mode */
                vuint32:3;
                vuint32 TCR2P:6;       /* TCR2 Prescaler Control */
                vuint32 TCR1CTL:2;     /* TCR1 Clock/Gate Control */
                vuint32 TCR1CS:1;      /* TCR1 Clock Source */ 
                vuint32:5;
                vuint32 TCR1P:8;       /* TCR1 Prescaler Control */
            } B;
        } TBCR_B;
        
        union {                 /* ETPU_B TCR1 Visibility Register */
            vuint32 R;
            struct {
                vuint32:8;
                vuint32 TCR1:24;
            } B;
        } TB1R_B;
        
        union {                 /* ETPU_B TCR2 Visibility Register */
            vuint32 R;
            struct {
                vuint32:8;
                vuint32 TCR2:24;
            } B;
        } TB2R_B;
        
        union {                 /* ETPU_B STAC Configuration Register */
            vuint32 R;
            struct {
                vuint32 REN1:1;       /* Resource Enable TCR1 */
                vuint32 RSC1:1;       /* Resource Control TCR1 */
                vuint32:2;
                vuint32 SERVER_ID1:4;   /* TCR1 Server ID */
                vuint32:4;
                vuint32 SRV1:4;       /* Resource Server Slot */
                vuint32 REN2:1;       /* Resource Enable TCR2 */
                vuint32 RSC2:1;       /* Resource Control TCR2 */
                vuint32:2;
                vuint32 SERVER_ID2:4;   /* TCR2 Server ID */
                vuint32:4;
                vuint32 SRV2:4;       /* Resource Server Slot */
            } B;
        } REDCR_B;
        
        uint32 eTPU_reserved0050[4];  /* 0x0050-0x005F */
        
        union {                 /* Watchdog Timer Register A */
            vuint32 R;
            struct {
                vuint32 WDM:2;          /* Watchdog Mode */
                vuint32:14;
                vuint32 WDCNT:16;       /* Watchdog Count */
            } B;
        } WDTR_A;
        
        uint32 eTPU_reserved0064;  /* 0x0064-0x0067 */
        
        union {                 /* Idle Counter Register A*/
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 ICLR:1;       /* Idle Clear */
            } B;
            
        } IDLE_A;
        
        uint32 eTPU_reserved006C;  /* 0x006C-0x006F */
        
        union {                 /* Watchdog Timer Register B */
            vuint32 R;
            struct {
                vuint32 WDM:2;          /* Watchdog Mode */
                vuint32:14;
                vuint32 WDCNT:16;       /* Watchdog Count */
            } B;
        } WDTR_B;
        
        uint32 eTPU_reserved0074;  /* 0x0074-0x0077 */
        
        union {                 /* Idle Counter Register B*/
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 ICLR:1;       /* Idle Clear */
            } B;
        } IDLE_B;
        
        uint32 eTPU_reserved007C;  /* 0x007C-0x007F */
        
        uint32 eTPU_reserved0080[96];  /* 0x0080-0x01FF */

/*****************************Status and Control Registers**************************/

        union {                 /* ETPU_A Channel Interrut Status */
            vuint32 R;
            struct {
                vuint32 CIS31:1;      /* Channel 31 Interrut Status */
                vuint32 CIS30:1;      /* Channel 30 Interrut Status */
                vuint32 CIS29:1;      /* Channel 29 Interrut Status */
                vuint32 CIS28:1;      /* Channel 28 Interrut Status */
                vuint32 CIS27:1;      /* Channel 27 Interrut Status */
                vuint32 CIS26:1;      /* Channel 26 Interrut Status */
                vuint32 CIS25:1;      /* Channel 25 Interrut Status */
                vuint32 CIS24:1;      /* Channel 24 Interrut Status */
                vuint32 CIS23:1;      /* Channel 23 Interrut Status */
                vuint32 CIS22:1;      /* Channel 22 Interrut Status */
                vuint32 CIS21:1;      /* Channel 21 Interrut Status */
                vuint32 CIS20:1;      /* Channel 20 Interrut Status */
                vuint32 CIS19:1;      /* Channel 19 Interrut Status */
                vuint32 CIS18:1;      /* Channel 18 Interrut Status */
                vuint32 CIS17:1;      /* Channel 17 Interrut Status */
                vuint32 CIS16:1;      /* Channel 16 Interrut Status */
                vuint32 CIS15:1;      /* Channel 15 Interrut Status */
                vuint32 CIS14:1;      /* Channel 14 Interrut Status */
                vuint32 CIS13:1;      /* Channel 13 Interrut Status */
                vuint32 CIS12:1;      /* Channel 12 Interrut Status */
                vuint32 CIS11:1;      /* Channel 11 Interrut Status */
                vuint32 CIS10:1;      /* Channel 10 Interrut Status */
                vuint32 CIS9:1;       /* Channel 9 Interrut Status */
                vuint32 CIS8:1;       /* Channel 8 Interrut Status */
                vuint32 CIS7:1;       /* Channel 7 Interrut Status */
                vuint32 CIS6:1;       /* Channel 6 Interrut Status */
                vuint32 CIS5:1;       /* Channel 5 Interrut Status */
                vuint32 CIS4:1;       /* Channel 4 Interrut Status */
                vuint32 CIS3:1;       /* Channel 3 Interrut Status */
                vuint32 CIS2:1;       /* Channel 2 Interrut Status */
                vuint32 CIS1:1;       /* Channel 1 Interrut Status */
                vuint32 CIS0:1;       /* Channel 0 Interrut Status */
            } B;
        } CISR_A;
        
        union {                 /* ETPU_B Channel Interruput Status */
            vuint32 R;
            struct {
                vuint32 CIS31:1;      /* Channel 31 Interrut Status */
                vuint32 CIS30:1;      /* Channel 30 Interrut Status */
                vuint32 CIS29:1;      /* Channel 29 Interrut Status */
                vuint32 CIS28:1;      /* Channel 28 Interrut Status */
                vuint32 CIS27:1;      /* Channel 27 Interrut Status */
                vuint32 CIS26:1;      /* Channel 26 Interrut Status */
                vuint32 CIS25:1;      /* Channel 25 Interrut Status */
                vuint32 CIS24:1;      /* Channel 24 Interrut Status */
                vuint32 CIS23:1;      /* Channel 23 Interrut Status */
                vuint32 CIS22:1;      /* Channel 22 Interrut Status */
                vuint32 CIS21:1;      /* Channel 21 Interrut Status */
                vuint32 CIS20:1;      /* Channel 20 Interrut Status */
                vuint32 CIS19:1;      /* Channel 19 Interrut Status */
                vuint32 CIS18:1;      /* Channel 18 Interrut Status */
                vuint32 CIS17:1;      /* Channel 17 Interrut Status */
                vuint32 CIS16:1;      /* Channel 16 Interrut Status */
                vuint32 CIS15:1;      /* Channel 15 Interrut Status */
                vuint32 CIS14:1;      /* Channel 14 Interrut Status */
                vuint32 CIS13:1;      /* Channel 13 Interrut Status */
                vuint32 CIS12:1;      /* Channel 12 Interrut Status */
                vuint32 CIS11:1;      /* Channel 11 Interrut Status */
                vuint32 CIS10:1;      /* Channel 10 Interrut Status */
                vuint32 CIS9:1;       /* Channel 9 Interrut Status */
                vuint32 CIS8:1;       /* Channel 8 Interrut Status */
                vuint32 CIS7:1;       /* Channel 7 Interrut Status */
                vuint32 CIS6:1;       /* Channel 6 Interrut Status */
                vuint32 CIS5:1;       /* Channel 5 Interrut Status */
                vuint32 CIS4:1;       /* Channel 4 Interrut Status */
                vuint32 CIS3:1;       /* Channel 3 Interrut Status */
                vuint32 CIS2:1;       /* Channel 2 Interrut Status */
                vuint32 CIS1:1;       /* Channel 1 Interrupt Status */
                vuint32 CIS0:1;       /* Channel 0 Interrupt Status */
            } B;
        } CISR_B;
        
        uint32 eTPU_reserved0208[2];  /* 0x0208-0x020F */
        
        union {                 /* ETPU_A Data Transfer Request Status */
            vuint32 R;
            struct {
                vuint32 DTRS31:1;     /* Channel 31 Data Transfer Request Status */
                vuint32 DTRS30:1;     /* Channel 30 Data Transfer Request Status */
                vuint32 DTRS29:1;     /* Channel 29 Data Transfer Request Status */
                vuint32 DTRS28:1;     /* Channel 28 Data Transfer Request Status */
                vuint32 DTRS27:1;     /* Channel 27 Data Transfer Request Status */
                vuint32 DTRS26:1;     /* Channel 26 Data Transfer Request Status */
                vuint32 DTRS25:1;     /* Channel 25 Data Transfer Request Status */
                vuint32 DTRS24:1;     /* Channel 24 Data Transfer Request Status */
                vuint32 DTRS23:1;     /* Channel 23 Data Transfer Request Status */
                vuint32 DTRS22:1;     /* Channel 22 Data Transfer Request Status */
                vuint32 DTRS21:1;     /* Channel 21 Data Transfer Request Status */
                vuint32 DTRS20:1;     /* Channel 20 Data Transfer Request Status */
                vuint32 DTRS19:1;     /* Channel 19 Data Transfer Request Status */
                vuint32 DTRS18:1;     /* Channel 18 Data Transfer Request Status */
                vuint32 DTRS17:1;     /* Channel 17 Data Transfer Request Status */
                vuint32 DTRS16:1;     /* Channel 16 Data Transfer Request Status */
                vuint32 DTRS15:1;     /* Channel 15 Data Transfer Request Status */
                vuint32 DTRS14:1;     /* Channel 14 Data Transfer Request Status */
                vuint32 DTRS13:1;     /* Channel 13 Data Transfer Request Status */
                vuint32 DTRS12:1;     /* Channel 12 Data Transfer Request Status */
                vuint32 DTRS11:1;     /* Channel 11 Data Transfer Request Status */
                vuint32 DTRS10:1;     /* Channel 10 Data Transfer Request Status */
                vuint32 DTRS9:1;      /* Channel 9 Data Transfer Request Status */
                vuint32 DTRS8:1;      /* Channel 8 Data Transfer Request Status */
                vuint32 DTRS7:1;      /* Channel 7 Data Transfer Request Status */
                vuint32 DTRS6:1;      /* Channel 6 Data Transfer Request Status */
                vuint32 DTRS5:1;      /* Channel 5 Data Transfer Request Status */
                vuint32 DTRS4:1;      /* Channel 4 Data Transfer Request Status */
                vuint32 DTRS3:1;      /* Channel 3 Data Transfer Request Status */
                vuint32 DTRS2:1;      /* Channel 2 Data Transfer Request Status */
                vuint32 DTRS1:1;      /* Channel 1 Data Transfer Request Status */
                vuint32 DTRS0:1;      /* Channel 0 Data Transfer Request Status */
            } B;
        } CDTRSR_A;
        
        union {                 /* ETPU_B Data Transfer Request Status */
            vuint32 R;
            struct {
                vuint32 DTRS31:1;     /* Channel 31 Data Transfer Request Status */
                vuint32 DTRS30:1;     /* Channel 30 Data Transfer Request Status */
                vuint32 DTRS29:1;     /* Channel 29 Data Transfer Request Status */
                vuint32 DTRS28:1;     /* Channel 28 Data Transfer Request Status */
                vuint32 DTRS27:1;     /* Channel 27 Data Transfer Request Status */
                vuint32 DTRS26:1;     /* Channel 26 Data Transfer Request Status */
                vuint32 DTRS25:1;     /* Channel 25 Data Transfer Request Status */
                vuint32 DTRS24:1;     /* Channel 24 Data Transfer Request Status */
                vuint32 DTRS23:1;     /* Channel 23 Data Transfer Request Status */
                vuint32 DTRS22:1;     /* Channel 22 Data Transfer Request Status */
                vuint32 DTRS21:1;     /* Channel 21 Data Transfer Request Status */
                vuint32 DTRS20:1;     /* Channel 20 Data Transfer Request Status */
                vuint32 DTRS19:1;     /* Channel 19 Data Transfer Request Status */
                vuint32 DTRS18:1;     /* Channel 18 Data Transfer Request Status */
                vuint32 DTRS17:1;     /* Channel 17 Data Transfer Request Status */
                vuint32 DTRS16:1;     /* Channel 16 Data Transfer Request Status */
                vuint32 DTRS15:1;     /* Channel 15 Data Transfer Request Status */
                vuint32 DTRS14:1;     /* Channel 14 Data Transfer Request Status */
                vuint32 DTRS13:1;     /* Channel 13 Data Transfer Request Status */
                vuint32 DTRS12:1;     /* Channel 12 Data Transfer Request Status */
                vuint32 DTRS11:1;     /* Channel 11 Data Transfer Request Status */
                vuint32 DTRS10:1;     /* Channel 10 Data Transfer Request Status */
                vuint32 DTRS9:1;      /* Channel 9 Data Transfer Request Status */
                vuint32 DTRS8:1;      /* Channel 8 Data Transfer Request Status */
                vuint32 DTRS7:1;      /* Channel 7 Data Transfer Request Status */
                vuint32 DTRS6:1;      /* Channel 6 Data Transfer Request Status */
                vuint32 DTRS5:1;      /* Channel 5 Data Transfer Request Status */
                vuint32 DTRS4:1;      /* Channel 4 Data Transfer Request Status */
                vuint32 DTRS3:1;      /* Channel 3 Data Transfer Request Status */
                vuint32 DTRS2:1;      /* Channel 2 Data Transfer Request Status */
                vuint32 DTRS1:1;      /* Channel 1 Data Transfer Request Status */
                vuint32 DTRS0:1;      /* Channel 0 Data Transfer Request Status */
            } B;
        } CDTRSR_B;
        
        uint32 eTPU_reserved0218[2];  /* 0x0218-0x021F */
        
        union {                 /* ETPU_A Interruput Overflow Status */
            vuint32 R;
            struct {
                vuint32 CIOS31:1;     /* Channel 31 Interruput Overflow Status */
                vuint32 CIOS30:1;     /* Channel 30 Interruput Overflow Status */
                vuint32 CIOS29:1;     /* Channel 29 Interruput Overflow Status */
                vuint32 CIOS28:1;     /* Channel 28 Interruput Overflow Status */
                vuint32 CIOS27:1;     /* Channel 27 Interruput Overflow Status */
                vuint32 CIOS26:1;     /* Channel 26 Interruput Overflow Status */
                vuint32 CIOS25:1;     /* Channel 25 Interruput Overflow Status */
                vuint32 CIOS24:1;     /* Channel 24 Interruput Overflow Status */
                vuint32 CIOS23:1;     /* Channel 23 Interruput Overflow Status */
                vuint32 CIOS22:1;     /* Channel 22 Interruput Overflow Status */
                vuint32 CIOS21:1;     /* Channel 21 Interruput Overflow Status */
                vuint32 CIOS20:1;     /* Channel 20 Interruput Overflow Status */
                vuint32 CIOS19:1;     /* Channel 19 Interruput Overflow Status */
                vuint32 CIOS18:1;     /* Channel 18 Interruput Overflow Status */
                vuint32 CIOS17:1;     /* Channel 17 Interruput Overflow Status */
                vuint32 CIOS16:1;     /* Channel 16 Interruput Overflow Status */
                vuint32 CIOS15:1;     /* Channel 15 Interruput Overflow Status */
                vuint32 CIOS14:1;     /* Channel 14 Interruput Overflow Status */
                vuint32 CIOS13:1;     /* Channel 13 Interruput Overflow Status */
                vuint32 CIOS12:1;     /* Channel 12 Interruput Overflow Status */
                vuint32 CIOS11:1;     /* Channel 11 Interruput Overflow Status */
                vuint32 CIOS10:1;     /* Channel 10 Interruput Overflow Status */
                vuint32 CIOS9:1;      /* Channel 9 Interruput Overflow Status */
                vuint32 CIOS8:1;      /* Channel 8 Interruput Overflow Status */
                vuint32 CIOS7:1;      /* Channel 7 Interruput Overflow Status */
                vuint32 CIOS6:1;      /* Channel 6 Interruput Overflow Status */
                vuint32 CIOS5:1;      /* Channel 5 Interruput Overflow Status */
                vuint32 CIOS4:1;      /* Channel 4 Interruput Overflow Status */
                vuint32 CIOS3:1;      /* Channel 3 Interruput Overflow Status */
                vuint32 CIOS2:1;      /* Channel 2 Interruput Overflow Status */
                vuint32 CIOS1:1;      /* Channel 1 Interruput Overflow Status */
                vuint32 CIOS0:1;      /* Channel 0 Interruput Overflow Status */
            } B;
        } CIOSR_A;
        
        union {                 /* ETPU_B Interruput Overflow Status */
            vuint32 R;
            struct {
                vuint32 CIOS31:1;     /* Channel 31 Interruput Overflow Status */
                vuint32 CIOS30:1;     /* Channel 30 Interruput Overflow Status */
                vuint32 CIOS29:1;     /* Channel 29 Interruput Overflow Status */
                vuint32 CIOS28:1;     /* Channel 28 Interruput Overflow Status */
                vuint32 CIOS27:1;     /* Channel 27 Interruput Overflow Status */
                vuint32 CIOS26:1;     /* Channel 26 Interruput Overflow Status */
                vuint32 CIOS25:1;     /* Channel 25 Interruput Overflow Status */
                vuint32 CIOS24:1;     /* Channel 24 Interruput Overflow Status */
                vuint32 CIOS23:1;     /* Channel 23 Interruput Overflow Status */
                vuint32 CIOS22:1;     /* Channel 22 Interruput Overflow Status */
                vuint32 CIOS21:1;     /* Channel 21 Interruput Overflow Status */
                vuint32 CIOS20:1;     /* Channel 20 Interruput Overflow Status */
                vuint32 CIOS19:1;     /* Channel 19 Interruput Overflow Status */
                vuint32 CIOS18:1;     /* Channel 18 Interruput Overflow Status */
                vuint32 CIOS17:1;     /* Channel 17 Interruput Overflow Status */
                vuint32 CIOS16:1;     /* Channel 16 Interruput Overflow Status */
                vuint32 CIOS15:1;     /* Channel 15 Interruput Overflow Status */
                vuint32 CIOS14:1;     /* Channel 14 Interruput Overflow Status */
                vuint32 CIOS13:1;     /* Channel 13 Interruput Overflow Status */
                vuint32 CIOS12:1;     /* Channel 12 Interruput Overflow Status */
                vuint32 CIOS11:1;     /* Channel 11 Interruput Overflow Status */
                vuint32 CIOS10:1;     /* Channel 10 Interruput Overflow Status */
                vuint32 CIOS9:1;      /* Channel 9 Interruput Overflow Status */
                vuint32 CIOS8:1;      /* Channel 8 Interruput Overflow Status */
                vuint32 CIOS7:1;      /* Channel 7 Interruput Overflow Status */
                vuint32 CIOS6:1;      /* Channel 6 Interruput Overflow Status */
                vuint32 CIOS5:1;      /* Channel 5 Interruput Overflow Status */
                vuint32 CIOS4:1;      /* Channel 4 Interruput Overflow Status */
                vuint32 CIOS3:1;      /* Channel 3 Interruput Overflow Status */
                vuint32 CIOS2:1;      /* Channel 2 Interruput Overflow Status */
                vuint32 CIOS1:1;      /* Channel 1 Interruput Overflow Status */
                vuint32 CIOS0:1;      /* Channel 0 Interruput Overflow Status */
            } B;
        } CIOSR_B;
        
        uint32 eTPU_reserved0228[2];  /* 0x0228-0x022F */
        
        union {                 /* ETPU_A Data Transfer Overflow Status */
            vuint32 R;
            struct {
                vuint32 DTROS31:1;    /* Channel 31 Data Transfer Overflow Status */
                vuint32 DTROS30:1;    /* Channel 30 Data Transfer Overflow Status */
                vuint32 DTROS29:1;    /* Channel 29 Data Transfer Overflow Status */
                vuint32 DTROS28:1;    /* Channel 28 Data Transfer Overflow Status */
                vuint32 DTROS27:1;    /* Channel 27 Data Transfer Overflow Status */
                vuint32 DTROS26:1;    /* Channel 26 Data Transfer Overflow Status */
                vuint32 DTROS25:1;    /* Channel 25 Data Transfer Overflow Status */
                vuint32 DTROS24:1;    /* Channel 24 Data Transfer Overflow Status */
                vuint32 DTROS23:1;    /* Channel 23 Data Transfer Overflow Status */
                vuint32 DTROS22:1;    /* Channel 22 Data Transfer Overflow Status */
                vuint32 DTROS21:1;    /* Channel 21 Data Transfer Overflow Status */
                vuint32 DTROS20:1;    /* Channel 20 Data Transfer Overflow Status */
                vuint32 DTROS19:1;    /* Channel 19 Data Transfer Overflow Status */
                vuint32 DTROS18:1;    /* Channel 18 Data Transfer Overflow Status */
                vuint32 DTROS17:1;    /* Channel 17 Data Transfer Overflow Status */
                vuint32 DTROS16:1;    /* Channel 16 Data Transfer Overflow Status */
                vuint32 DTROS15:1;    /* Channel 15 Data Transfer Overflow Status */
                vuint32 DTROS14:1;    /* Channel 14 Data Transfer Overflow Status */
                vuint32 DTROS13:1;    /* Channel 13 Data Transfer Overflow Status */
                vuint32 DTROS12:1;    /* Channel 12 Data Transfer Overflow Status */
                vuint32 DTROS11:1;    /* Channel 11 Data Transfer Overflow Status */
                vuint32 DTROS10:1;    /* Channel 10 Data Transfer Overflow Status */
                vuint32 DTROS9:1;     /* Channel 9 Data Transfer Overflow Status */
                vuint32 DTROS8:1;     /* Channel 8 Data Transfer Overflow Status */
                vuint32 DTROS7:1;     /* Channel 7 Data Transfer Overflow Status */
                vuint32 DTROS6:1;     /* Channel 6 Data Transfer Overflow Status */
                vuint32 DTROS5:1;     /* Channel 5 Data Transfer Overflow Status */
                vuint32 DTROS4:1;     /* Channel 4 Data Transfer Overflow Status */
                vuint32 DTROS3:1;     /* Channel 3 Data Transfer Overflow Status */
                vuint32 DTROS2:1;     /* Channel 2 Data Transfer Overflow Status */
                vuint32 DTROS1:1;     /* Channel 1 Data Transfer Overflow Status */
                vuint32 DTROS0:1;     /* Channel 0 Data Transfer Overflow Status */
            } B;
        } CDTROSR_A;
        
        union {                 /* ETPU_B Data Transfer Overflow Status */
            vuint32 R;
            struct {
                vuint32 DTROS31:1;    /* Channel 31 Data Transfer Overflow Status */
                vuint32 DTROS30:1;    /* Channel 30 Data Transfer Overflow Status */
                vuint32 DTROS29:1;    /* Channel 29 Data Transfer Overflow Status */
                vuint32 DTROS28:1;    /* Channel 28 Data Transfer Overflow Status */
                vuint32 DTROS27:1;    /* Channel 27 Data Transfer Overflow Status */
                vuint32 DTROS26:1;    /* Channel 26 Data Transfer Overflow Status */
                vuint32 DTROS25:1;    /* Channel 25 Data Transfer Overflow Status */
                vuint32 DTROS24:1;    /* Channel 24 Data Transfer Overflow Status */
                vuint32 DTROS23:1;    /* Channel 23 Data Transfer Overflow Status */
                vuint32 DTROS22:1;    /* Channel 22 Data Transfer Overflow Status */
                vuint32 DTROS21:1;    /* Channel 21 Data Transfer Overflow Status */
                vuint32 DTROS20:1;    /* Channel 20 Data Transfer Overflow Status */
                vuint32 DTROS19:1;    /* Channel 19 Data Transfer Overflow Status */
                vuint32 DTROS18:1;    /* Channel 18 Data Transfer Overflow Status */
                vuint32 DTROS17:1;    /* Channel 17 Data Transfer Overflow Status */
                vuint32 DTROS16:1;    /* Channel 16 Data Transfer Overflow Status */
                vuint32 DTROS15:1;    /* Channel 15 Data Transfer Overflow Status */
                vuint32 DTROS14:1;    /* Channel 14 Data Transfer Overflow Status */
                vuint32 DTROS13:1;    /* Channel 13 Data Transfer Overflow Status */
                vuint32 DTROS12:1;    /* Channel 12 Data Transfer Overflow Status */
                vuint32 DTROS11:1;    /* Channel 11 Data Transfer Overflow Status */
                vuint32 DTROS10:1;    /* Channel 10 Data Transfer Overflow Status */
                vuint32 DTROS9:1;     /* Channel 9 Data Transfer Overflow Status */
                vuint32 DTROS8:1;     /* Channel 8 Data Transfer Overflow Status */
                vuint32 DTROS7:1;     /* Channel 7 Data Transfer Overflow Status */
                vuint32 DTROS6:1;     /* Channel 6 Data Transfer Overflow Status */
                vuint32 DTROS5:1;     /* Channel 5 Data Transfer Overflow Status */
                vuint32 DTROS4:1;     /* Channel 4 Data Transfer Overflow Status */
                vuint32 DTROS3:1;     /* Channel 3 Data Transfer Overflow Status */
                vuint32 DTROS2:1;     /* Channel 2 Data Transfer Overflow Status */
                vuint32 DTROS1:1;     /* Channel 1 Data Transfer Overflow Status */
                vuint32 DTROS0:1;     /* Channel 0 Data Transfer Overflow Status */
            } B;
        } CDTROSR_B;
        
        uint32 eTPU_reserved0238[2];  /* 0x0238-0x023F */
        
        union {                 /* ETPU_A Channel Interruput Enable */
            vuint32 R;
            struct {
                vuint32 CIE31:1;      /* Channel 31 Interruput Enable */
                vuint32 CIE30:1;      /* Channel 30 Interruput Enable */
                vuint32 CIE29:1;      /* Channel 29 Interruput Enable */
                vuint32 CIE28:1;      /* Channel 28 Interruput Enable */
                vuint32 CIE27:1;      /* Channel 27 Interruput Enable */
                vuint32 CIE26:1;      /* Channel 26 Interruput Enable */
                vuint32 CIE25:1;      /* Channel 25 Interruput Enable */
                vuint32 CIE24:1;      /* Channel 24 Interruput Enable */
                vuint32 CIE23:1;      /* Channel 23 Interruput Enable */
                vuint32 CIE22:1;      /* Channel 22 Interruput Enable */
                vuint32 CIE21:1;      /* Channel 21 Interruput Enable */
                vuint32 CIE20:1;      /* Channel 20 Interruput Enable */
                vuint32 CIE19:1;      /* Channel 19 Interruput Enable */
                vuint32 CIE18:1;      /* Channel 18 Interruput Enable */
                vuint32 CIE17:1;      /* Channel 17 Interruput Enable */
                vuint32 CIE16:1;      /* Channel 16 Interruput Enable */
                vuint32 CIE15:1;      /* Channel 15 Interruput Enable */
                vuint32 CIE14:1;      /* Channel 14 Interruput Enable */
                vuint32 CIE13:1;      /* Channel 13 Interruput Enable */
                vuint32 CIE12:1;      /* Channel 12 Interruput Enable */
                vuint32 CIE11:1;      /* Channel 11 Interruput Enable */
                vuint32 CIE10:1;      /* Channel 10 Interruput Enable */
                vuint32 CIE9:1;       /* Channel 9 Interruput Enable */
                vuint32 CIE8:1;       /* Channel 8 Interruput Enable */
                vuint32 CIE7:1;       /* Channel 7 Interruput Enable */
                vuint32 CIE6:1;       /* Channel 6 Interruput Enable */
                vuint32 CIE5:1;       /* Channel 5 Interruput Enable */
                vuint32 CIE4:1;       /* Channel 4 Interruput Enable */
                vuint32 CIE3:1;       /* Channel 3 Interruput Enable */
                vuint32 CIE2:1;       /* Channel 2 Interruput Enable */
                vuint32 CIE1:1;       /* Channel 1 Interruput Enable */
                vuint32 CIE0:1;       /* Channel 0 Interruput Enable */
            } B;
        } CIER_A;
        
        union {                 /* ETPU_B Channel Interruput Enable */
            vuint32 R;
            struct {
                vuint32 CIE31:1;      /* Channel 31 Interruput Enable */
                vuint32 CIE30:1;      /* Channel 30 Interruput Enable */
                vuint32 CIE29:1;      /* Channel 29 Interruput Enable */
                vuint32 CIE28:1;      /* Channel 28 Interruput Enable */
                vuint32 CIE27:1;      /* Channel 27 Interruput Enable */
                vuint32 CIE26:1;      /* Channel 26 Interruput Enable */
                vuint32 CIE25:1;      /* Channel 25 Interruput Enable */
                vuint32 CIE24:1;      /* Channel 24 Interruput Enable */
                vuint32 CIE23:1;      /* Channel 23 Interruput Enable */
                vuint32 CIE22:1;      /* Channel 22 Interruput Enable */
                vuint32 CIE21:1;      /* Channel 21 Interruput Enable */
                vuint32 CIE20:1;      /* Channel 20 Interruput Enable */
                vuint32 CIE19:1;      /* Channel 19 Interruput Enable */
                vuint32 CIE18:1;      /* Channel 18 Interruput Enable */
                vuint32 CIE17:1;      /* Channel 17 Interruput Enable */
                vuint32 CIE16:1;      /* Channel 16 Interruput Enable */
                vuint32 CIE15:1;      /* Channel 15 Interruput Enable */
                vuint32 CIE14:1;      /* Channel 14 Interruput Enable */
                vuint32 CIE13:1;      /* Channel 13 Interruput Enable */
                vuint32 CIE12:1;      /* Channel 12 Interruput Enable */
                vuint32 CIE11:1;      /* Channel 11 Interruput Enable */
                vuint32 CIE10:1;      /* Channel 10 Interruput Enable */
                vuint32 CIE9:1;       /* Channel 9 Interruput Enable */
                vuint32 CIE8:1;       /* Channel 8 Interruput Enable */
                vuint32 CIE7:1;       /* Channel 7 Interruput Enable */
                vuint32 CIE6:1;       /* Channel 6 Interruput Enable */
                vuint32 CIE5:1;       /* Channel 5 Interruput Enable */
                vuint32 CIE4:1;       /* Channel 4 Interruput Enable */
                vuint32 CIE3:1;       /* Channel 3 Interruput Enable */
                vuint32 CIE2:1;       /* Channel 2 Interruput Enable */
                vuint32 CIE1:1;       /* Channel 1 Interruput Enable */
                vuint32 CIE0:1;       /* Channel 0 Interruput Enable */
            } B;
        } CIER_B;
        
        uint32 eTPU_reserved0248[2];  /* 0x0248-0x024F */
        
        union {                 /* ETPU_A Channel Data Transfer Request Enable */
            vuint32 R;
            struct {
                vuint32 DTRE31:1;     /* Channel 31 Data Transfer Request Enable */
                vuint32 DTRE30:1;     /* Channel 30 Data Transfer Request Enable */
                vuint32 DTRE29:1;     /* Channel 29 Data Transfer Request Enable */
                vuint32 DTRE28:1;     /* Channel 28 Data Transfer Request Enable */
                vuint32 DTRE27:1;     /* Channel 27 Data Transfer Request Enable */
                vuint32 DTRE26:1;     /* Channel 26 Data Transfer Request Enable */
                vuint32 DTRE25:1;     /* Channel 25 Data Transfer Request Enable */
                vuint32 DTRE24:1;     /* Channel 24 Data Transfer Request Enable */
                vuint32 DTRE23:1;     /* Channel 23 Data Transfer Request Enable */
                vuint32 DTRE22:1;     /* Channel 22 Data Transfer Request Enable */
                vuint32 DTRE21:1;     /* Channel 21 Data Transfer Request Enable */
                vuint32 DTRE20:1;     /* Channel 20 Data Transfer Request Enable */
                vuint32 DTRE19:1;     /* Channel 19 Data Transfer Request Enable */
                vuint32 DTRE18:1;     /* Channel 18 Data Transfer Request Enable */
                vuint32 DTRE17:1;     /* Channel 17 Data Transfer Request Enable */
                vuint32 DTRE16:1;     /* Channel 16 Data Transfer Request Enable */
                vuint32 DTRE15:1;     /* Channel 15 Data Transfer Request Enable */
                vuint32 DTRE14:1;     /* Channel 14 Data Transfer Request Enable */
                vuint32 DTRE13:1;     /* Channel 13 Data Transfer Request Enable */
                vuint32 DTRE12:1;     /* Channel 12 Data Transfer Request Enable */
                vuint32 DTRE11:1;     /* Channel 11 Data Transfer Request Enable */
                vuint32 DTRE10:1;     /* Channel 10 Data Transfer Request Enable */
                vuint32 DTRE9:1;      /* Channel 9 Data Transfer Request Enable */
                vuint32 DTRE8:1;      /* Channel 8 Data Transfer Request Enable */
                vuint32 DTRE7:1;      /* Channel 7 Data Transfer Request Enable */
                vuint32 DTRE6:1;      /* Channel 6 Data Transfer Request Enable */
                vuint32 DTRE5:1;      /* Channel 5 Data Transfer Request Enable */
                vuint32 DTRE4:1;      /* Channel 4 Data Transfer Request Enable */
                vuint32 DTRE3:1;      /* Channel 3 Data Transfer Request Enable */
                vuint32 DTRE2:1;      /* Channel 2 Data Transfer Request Enable */
                vuint32 DTRE1:1;      /* Channel 1 Data Transfer Request Enable */
                vuint32 DTRE0:1;      /* Channel 0 Data Transfer Request Enable */
            } B;
        } CDTRER_A;
        
        union {                 /* ETPU_B Channel Data Transfer Request Enable */
            vuint32 R;
            struct {
                vuint32 DTRE31:1;     /* Channel 31 Data Transfer Request Enable */
                vuint32 DTRE30:1;     /* Channel 30 Data Transfer Request Enable */
                vuint32 DTRE29:1;     /* Channel 29 Data Transfer Request Enable */
                vuint32 DTRE28:1;     /* Channel 28 Data Transfer Request Enable */
                vuint32 DTRE27:1;     /* Channel 27 Data Transfer Request Enable */
                vuint32 DTRE26:1;     /* Channel 26 Data Transfer Request Enable */
                vuint32 DTRE25:1;     /* Channel 25 Data Transfer Request Enable */
                vuint32 DTRE24:1;     /* Channel 24 Data Transfer Request Enable */
                vuint32 DTRE23:1;     /* Channel 23 Data Transfer Request Enable */
                vuint32 DTRE22:1;     /* Channel 22 Data Transfer Request Enable */
                vuint32 DTRE21:1;     /* Channel 21 Data Transfer Request Enable */
                vuint32 DTRE20:1;     /* Channel 20 Data Transfer Request Enable */
                vuint32 DTRE19:1;     /* Channel 19 Data Transfer Request Enable */
                vuint32 DTRE18:1;     /* Channel 18 Data Transfer Request Enable */
                vuint32 DTRE17:1;     /* Channel 17 Data Transfer Request Enable */
                vuint32 DTRE16:1;     /* Channel 16 Data Transfer Request Enable */
                vuint32 DTRE15:1;     /* Channel 15 Data Transfer Request Enable */
                vuint32 DTRE14:1;     /* Channel 14 Data Transfer Request Enable */
                vuint32 DTRE13:1;     /* Channel 13 Data Transfer Request Enable */
                vuint32 DTRE12:1;     /* Channel 12 Data Transfer Request Enable */
                vuint32 DTRE11:1;     /* Channel 11 Data Transfer Request Enable */
                vuint32 DTRE10:1;     /* Channel 10 Data Transfer Request Enable */
                vuint32 DTRE9:1;      /* Channel 9 Data Transfer Request Enable */
                vuint32 DTRE8:1;      /* Channel 8 Data Transfer Request Enable */
                vuint32 DTRE7:1;      /* Channel 7 Data Transfer Request Enable */
                vuint32 DTRE6:1;      /* Channel 6 Data Transfer Request Enable */
                vuint32 DTRE5:1;      /* Channel 5 Data Transfer Request Enable */
                vuint32 DTRE4:1;      /* Channel 4 Data Transfer Request Enable */
                vuint32 DTRE3:1;      /* Channel 3 Data Transfer Request Enable */
                vuint32 DTRE2:1;      /* Channel 2 Data Transfer Request Enable */
                vuint32 DTRE1:1;      /* Channel 1 Data Transfer Request Enable */
                vuint32 DTRE0:1;      /* Channel 0 Data Transfer Request Enable */
            } B;
        } CDTRER_B;
        
        uint32 eTPU_reserved0258[2];  /* 0x0258-0x025F */
        
        union {                 /* Watchdog Status Register A */
            vuint32 R;
            struct {
                vuint32 WDS31:1;
                vuint32 WDS30:1;
                vuint32 WDS29:1;
                vuint32 WDS28:1;
                vuint32 WDS27:1;
                vuint32 WDS26:1;
                vuint32 WDS25:1;
                vuint32 WDS24:1;
                vuint32 WDS23:1;
                vuint32 WDS22:1;
                vuint32 WDS21:1;
                vuint32 WDS20:1;
                vuint32 WDS19:1;
                vuint32 WDS18:1;
                vuint32 WDS17:1;
                vuint32 WDS16:1;
                vuint32 WDS15:1;
                vuint32 WDS14:1;
                vuint32 WDS13:1;
                vuint32 WDS12:1;
                vuint32 WDS11:1;
                vuint32 WDS10:1;
                vuint32 WDS9:1;
                vuint32 WDS8:1;
                vuint32 WDS7:1;
                vuint32 WDS6:1;
                vuint32 WDS5:1;
                vuint32 WDS4:1;
                vuint32 WDS3:1;
                vuint32 WDS2:1;
                vuint32 WDS1:1;
                vuint32 WDS0:1;
            } B;
        } WDSR_A;
        
        union {                 /* Watchdog Status Register B */
            vuint32 R;
            struct {
                vuint32 WDS31:1;
                vuint32 WDS30:1;
                vuint32 WDS29:1;
                vuint32 WDS28:1;
                vuint32 WDS27:1;
                vuint32 WDS26:1;
                vuint32 WDS25:1;
                vuint32 WDS24:1;
                vuint32 WDS23:1;
                vuint32 WDS22:1;
                vuint32 WDS21:1;
                vuint32 WDS20:1;
                vuint32 WDS19:1;
                vuint32 WDS18:1;
                vuint32 WDS17:1;
                vuint32 WDS16:1;
                vuint32 WDS15:1;
                vuint32 WDS14:1;
                vuint32 WDS13:1;
                vuint32 WDS12:1;
                vuint32 WDS11:1;
                vuint32 WDS10:1;
                vuint32 WDS9:1;
                vuint32 WDS8:1;
                vuint32 WDS7:1;
                vuint32 WDS6:1;
                vuint32 WDS5:1;
                vuint32 WDS4:1;
                vuint32 WDS3:1;
                vuint32 WDS2:1;
                vuint32 WDS1:1;
                vuint32 WDS0:1;
            } B;
        } WDSR_B;
        
        uint32 eTPU_reserved0268[6];  /* 0x0268-0x027F */
        
        union {                 /* ETPU_A Channel Pending Service Status */
            vuint32 R;
            struct {
                vuint32 SR31:1;       /* Channel 31 Pending Service Status */
                vuint32 SR30:1;       /* Channel 30 Pending Service Status */
                vuint32 SR29:1;       /* Channel 29 Pending Service Status */
                vuint32 SR28:1;       /* Channel 28 Pending Service Status */
                vuint32 SR27:1;       /* Channel 27 Pending Service Status */
                vuint32 SR26:1;       /* Channel 26 Pending Service Status */
                vuint32 SR25:1;       /* Channel 25 Pending Service Status */
                vuint32 SR24:1;       /* Channel 24 Pending Service Status */
                vuint32 SR23:1;       /* Channel 23 Pending Service Status */
                vuint32 SR22:1;       /* Channel 22 Pending Service Status */
                vuint32 SR21:1;       /* Channel 21 Pending Service Status */
                vuint32 SR20:1;       /* Channel 20 Pending Service Status */
                vuint32 SR19:1;       /* Channel 19 Pending Service Status */
                vuint32 SR18:1;       /* Channel 18 Pending Service Status */
                vuint32 SR17:1;       /* Channel 17 Pending Service Status */
                vuint32 SR16:1;       /* Channel 16 Pending Service Status */
                vuint32 SR15:1;       /* Channel 15 Pending Service Status */
                vuint32 SR14:1;       /* Channel 14 Pending Service Status */
                vuint32 SR13:1;       /* Channel 13 Pending Service Status */
                vuint32 SR12:1;       /* Channel 12 Pending Service Status */
                vuint32 SR11:1;       /* Channel 11 Pending Service Status */
                vuint32 SR10:1;       /* Channel 10 Pending Service Status */
                vuint32 SR9:1;        /* Channel 9 Pending Service Status */
                vuint32 SR8:1;        /* Channel 8 Pending Service Status */
                vuint32 SR7:1;        /* Channel 7 Pending Service Status */
                vuint32 SR6:1;        /* Channel 6 Pending Service Status */
                vuint32 SR5:1;        /* Channel 5 Pending Service Status */
                vuint32 SR4:1;        /* Channel 4 Pending Service Status */
                vuint32 SR3:1;        /* Channel 3 Pending Service Status */
                vuint32 SR2:1;        /* Channel 2 Pending Service Status */
                vuint32 SR1:1;        /* Channel 1 Pending Service Status */
                vuint32 SR0:1;        /* Channel 0 Pending Service Status */
            } B;
        } CPSSR_A;
        
        union {                 /* ETPU_B Channel Pending Service Status */
            vuint32 R;
            struct {
                vuint32 SR31:1;       /* Channel 31 Pending Service Status */
                vuint32 SR30:1;       /* Channel 30 Pending Service Status */
                vuint32 SR29:1;       /* Channel 29 Pending Service Status */
                vuint32 SR28:1;       /* Channel 28 Pending Service Status */
                vuint32 SR27:1;       /* Channel 27 Pending Service Status */
                vuint32 SR26:1;       /* Channel 26 Pending Service Status */
                vuint32 SR25:1;       /* Channel 25 Pending Service Status */
                vuint32 SR24:1;       /* Channel 24 Pending Service Status */
                vuint32 SR23:1;       /* Channel 23 Pending Service Status */
                vuint32 SR22:1;       /* Channel 22 Pending Service Status */
                vuint32 SR21:1;       /* Channel 21 Pending Service Status */
                vuint32 SR20:1;       /* Channel 20 Pending Service Status */
                vuint32 SR19:1;       /* Channel 19 Pending Service Status */
                vuint32 SR18:1;       /* Channel 18 Pending Service Status */
                vuint32 SR17:1;       /* Channel 17 Pending Service Status */
                vuint32 SR16:1;       /* Channel 16 Pending Service Status */
                vuint32 SR15:1;       /* Channel 15 Pending Service Status */
                vuint32 SR14:1;       /* Channel 14 Pending Service Status */
                vuint32 SR13:1;       /* Channel 13 Pending Service Status */
                vuint32 SR12:1;       /* Channel 12 Pending Service Status */
                vuint32 SR11:1;       /* Channel 11 Pending Service Status */
                vuint32 SR10:1;       /* Channel 10 Pending Service Status */
                vuint32 SR9:1;        /* Channel 9 Pending Service Status */
                vuint32 SR8:1;        /* Channel 8 Pending Service Status */
                vuint32 SR7:1;        /* Channel 7 Pending Service Status */
                vuint32 SR6:1;        /* Channel 6 Pending Service Status */
                vuint32 SR5:1;        /* Channel 5 Pending Service Status */
                vuint32 SR4:1;        /* Channel 4 Pending Service Status */
                vuint32 SR3:1;        /* Channel 3 Pending Service Status */
                vuint32 SR2:1;        /* Channel 2 Pending Service Status */
                vuint32 SR1:1;        /* Channel 1 Pending Service Status */
                vuint32 SR0:1;        /* Channel 0 Pending Service Status */
            } B;
        } CPSSR_B;
        
        uint32 eTPU_reserved0288[2];  /* 0x0288-0x028F */
        
        union {                 /* ETPU_A Channel Service Status */
            vuint32 R;
            struct {
                vuint32 SS31:1;       /* Channel 31 Service Status */
                vuint32 SS30:1;       /* Channel 30 Service Status */
                vuint32 SS29:1;       /* Channel 29 Service Status */
                vuint32 SS28:1;       /* Channel 28 Service Status */
                vuint32 SS27:1;       /* Channel 27 Service Status */
                vuint32 SS26:1;       /* Channel 26 Service Status */
                vuint32 SS25:1;       /* Channel 25 Service Status */
                vuint32 SS24:1;       /* Channel 24 Service Status */
                vuint32 SS23:1;       /* Channel 23 Service Status */
                vuint32 SS22:1;       /* Channel 22 Service Status */
                vuint32 SS21:1;       /* Channel 21 Service Status */
                vuint32 SS20:1;       /* Channel 20 Service Status */
                vuint32 SS19:1;       /* Channel 19 Service Status */
                vuint32 SS18:1;       /* Channel 18 Service Status */
                vuint32 SS17:1;       /* Channel 17 Service Status */
                vuint32 SS16:1;       /* Channel 16 Service Status */
                vuint32 SS15:1;       /* Channel 15 Service Status */
                vuint32 SS14:1;       /* Channel 14 Service Status */
                vuint32 SS13:1;       /* Channel 13 Service Status */
                vuint32 SS12:1;       /* Channel 12 Service Status */
                vuint32 SS11:1;       /* Channel 11 Service Status */
                vuint32 SS10:1;       /* Channel 10 Service Status */
                vuint32 SS9:1;        /* Channel 9 Service Status */
                vuint32 SS8:1;        /* Channel 8 Service Status */
                vuint32 SS7:1;        /* Channel 7 Service Status */
                vuint32 SS6:1;        /* Channel 6 Service Status */
                vuint32 SS5:1;        /* Channel 5 Service Status */
                vuint32 SS4:1;        /* Channel 4 Service Status */
                vuint32 SS3:1;        /* Channel 3 Service Status */
                vuint32 SS2:1;        /* Channel 2 Service Status */
                vuint32 SS1:1;        /* Channel 1 Service Status */
                vuint32 SS0:1;        /* Channel 0 Service Status */
            } B;
        } CSSR_A;
        
        union {                 /* ETPU_B Channel Service Status */
            vuint32 R;
            struct {
                vuint32 SS31:1;       /* Channel 31 Service Status */
                vuint32 SS30:1;       /* Channel 30 Service Status */
                vuint32 SS29:1;       /* Channel 29 Service Status */
                vuint32 SS28:1;       /* Channel 28 Service Status */
                vuint32 SS27:1;       /* Channel 27 Service Status */
                vuint32 SS26:1;       /* Channel 26 Service Status */
                vuint32 SS25:1;       /* Channel 25 Service Status */
                vuint32 SS24:1;       /* Channel 24 Service Status */
                vuint32 SS23:1;       /* Channel 23 Service Status */
                vuint32 SS22:1;       /* Channel 22 Service Status */
                vuint32 SS21:1;       /* Channel 21 Service Status */
                vuint32 SS20:1;       /* Channel 20 Service Status */
                vuint32 SS19:1;       /* Channel 19 Service Status */
                vuint32 SS18:1;       /* Channel 18 Service Status */
                vuint32 SS17:1;       /* Channel 17 Service Status */
                vuint32 SS16:1;       /* Channel 16 Service Status */
                vuint32 SS15:1;       /* Channel 15 Service Status */
                vuint32 SS14:1;       /* Channel 14 Service Status */
                vuint32 SS13:1;       /* Channel 13 Service Status */
                vuint32 SS12:1;       /* Channel 12 Service Status */
                vuint32 SS11:1;       /* Channel 11 Service Status */
                vuint32 SS10:1;       /* Channel 10 Service Status */
                vuint32 SS9:1;        /* Channel 9 Service Status */
                vuint32 SS8:1;        /* Channel 8 Service Status */
                vuint32 SS7:1;        /* Channel 7 Service Status */
                vuint32 SS6:1;        /* Channel 6 Service Status */
                vuint32 SS5:1;        /* Channel 5 Service Status */
                vuint32 SS4:1;        /* Channel 4 Service Status */
                vuint32 SS3:1;        /* Channel 3 Service Status */
                vuint32 SS2:1;        /* Channel 2 Service Status */
                vuint32 SS1:1;        /* Channel 1 Service Status */
                vuint32 SS0:1;        /* Channel 0 Service Status */
            } B;
        } CSSR_B;
        
        uint32 eTPU_reserved0298[2];  /* 0x0298-0x029F */
        
        uint32 eTPU_reserved02A0[88];  /* 0x02A0-0x03FF */

/*****************************Channels********************************/

        struct {
            union {    /* Channel Configuration Register */
                vuint32 R;
                struct {
                    vuint32 CIE:1;    /* Channel Interruput Enable */
                    vuint32 DTRE:1;   /* Data Transfer Request Enable */
                    vuint32 CPR:2;    /* Channel Priority */
                    vuint32:2;
                    vuint32 ETPD:1;
                    vuint32 ETCS:1;   /* Entry Table Condition Select */
                    vuint32:3;
                    vuint32 CFS:5;    /* Channel Function Select */
                    vuint32 ODIS:1;   /* Output disable */
                    vuint32 OPOL:1;   /* output polarity */
                    vuint32:3;
                    vuint32 CPBA:11;  /* Channel Parameter Base Address */
                } B;
            } CR;
            
            union {    /* Channel Status Control Register */
                vuint32 R;
                struct {
                    vuint32 CIS:1;    /* Channel Interruput Status */
                    vuint32 CIOS:1;   /* Channel Interruput Overflow Status */
                    vuint32:6;
                    vuint32 DTRS:1;   /* Data Transfer Status */
                    vuint32 DTROS:1;  /* Data Transfer Overflow Status */
                    vuint32:6;
                    vuint32 IPS:1;    /* Input Pin State */
                    vuint32 OPS:1;    /* Output Pin State */
                    vuint32 OBE:1;    /* Output Buffer Enable */
                    vuint32:11;
                    vuint32 FM1:1;    /* Function mode */
                    vuint32 FM0:1;    /* Function mode */
                } B;
            } SCR;
            
            union {    /* Channel Host Service Request Register */
                vuint32 R;
                struct {
                    vuint32:29;       /* Host Service Request */
                    vuint32 HSR:3;
                } B;
            } HSRR;
            
            uint32 eTPU_ch_reserved00C;  /* channel offset 0x00C-0x00F */
            
        } CHAN[127];
        
        uint32 eTPU_reserved1000[7168];  /* 0x1000-0x7FFF */
        
    };



#ifdef __MWERKS__
#pragma pop
#endif

#ifdef  __cplusplus
}
#endif
#endif                          /* ifdef _ETPU_STRUCT_H_ */
/*********************************************************************
 *
 * Copyright:
 *  Freescale Semiconductor, INC. All Rights Reserved.
 *  You are hereby granted a copyright license to use, modify, and
 *  distribute the SOFTWARE so long as this entire notice is
 *  retained without alteration in any modified and/or redistributed
 *  versions, and that such modified versions are clearly identified
 *  as such. No licenses are granted by implication, estoppel or
 *  otherwise under any patents or trademarks of Freescale
 *  Semiconductor, Inc. This software is provided on an "AS IS"
 *  basis and without warranty.
 *
 *  To the maximum extent permitted by applicable law, Freescale
 *  Semiconductor DISCLAIMS ALL WARRANTIES WHETHER EXPRESS OR IMPLIED,
 *  INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A
 *  PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH
 *  REGARD TO THE SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF)
 *  AND ANY ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL Freescale Semiconductor BE LIABLE FOR ANY DAMAGES WHATSOEVER
 *  (INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS,
 *  BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, OR OTHER
 *  PECUNIARY LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Freescale Semiconductor assumes no responsibility for the
 *  maintenance and support of this software
 *
 ********************************************************************/
