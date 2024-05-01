/**************************************************************************/
/* FILE NAME: MPC5644A.h      COPYRIGHT(c) Freescale & STMicroelectronics */
/* VERSION:  0.8                           2011 - All Rights Reserved     */
/*                                                                        */
/* DESCRIPTION:                                                           */
/* This file contains all of the register and bit field definitions for   */
/* MPC5644A.                                                              */
/*========================================================================*/
/* UPDATE HISTORY                                                         */
/* REV      AUTHOR      DATE       DESCRIPTION OF CHANGE                  */
/* ---   -----------  ---------    ---------------------                  */
/* 0.1   R. MORAN     10/Aug/09    Initial Alpha version.                 */
/* 0.2   R. Moran     09/Nov/09    Several Updates:                       */
/*                                 - XBAR - MPR/SGPCR'3' changed to '2'   */
/*                                 - CFCR, IDCR, CFTCR array sizes altered*/
/*                                 - IDIS,CASCD added to DEC_Filter MCR   */
/*                                 - WDM fields changed in eTPU_WDTR reg  */
/*                                 - Additional ECSM registers added      */
/* 0.3   R. Moran     14/Jan/10    Several Updates:                       */
/*                                 - Flash User Test Register implemented */
/*                                 - MPU.EDR[3] register removed          */
/*                                 - Minor Loop TCD bits implemented      */                                   
/*                                 - Temperature Sensor implemented       */                                   
/*                                 - DSPI.MCR.B.PES implemented           */ 
/* 0.4   R. Moran     30/Mar/10    - Added DTS Module Registers           */
/*                                 - Added Reaction Module                */ 
/*								   - eQADC REDLCCR register				  */            
/*								   - Temp Sensor TCCR0 corrected 		  */
/*								   - CFTCR definition changed             */
/*                                 - EBI CAL_BR/OR updated                */
/*                                 - XBAR MPR0,1,3,7 fixed master fields  */
/*                                 - Decimation filter updated to support */
/*                                   Integration filter and rev2 changes  */
/* 0.5	 I. Harris	  25/May/10    - Updated ECSM_ESR with 1bit cor. fld  */
/*								   - Updated ECSM_ECR with 1bit cor. ena  */
/*								   - Corrected ECSM_MUDR endianness		  */
/*								   - Corrected ECSM_MWCR ENBWCR field name*/
/*								   - Updated SIU_IREEx fields			  */
/*                                 - Added EBI_MCR DBM field              */
/*								   - Added PBRIDGE Registers			  */
/*                                 - Added SIU EMPCR0 Register            */
/*                                 - Included FlexCAN RXFIFO structure    */
/* 0.6   I. Harris	  20/Oct/10    Several Updates:						  */
/*                                 - Updated SIU ISEL10, HLT and HLTACK   */
/*								   - SIU_PCR PA field increased           */
/*                                 - Added SIU_IFIR						  */
/* 								   - Removed DOZEN/DOZE from EMIOS + DSPI */
/*								   - ENGDIV is 8-bits                     */
/*                                 - renumbered MPCR, PACR and OPACR      */
/*                                 - Updated Flexray based on revised IP  */
/*								   - removed SWTR from ECSM MRSR          */
/*                                 - corrected ECSM MRSR, ETPU CDCR       */
/*                                 - corrected DECFIL VAL registers       */
/*                                 - corrected MPU masters and TSENS TCCR1*/
/*                                 - corrected REACM missing bits         */
/*                                 - corrected eSCI registers             */
/* 0.7   I. Harris	  25/Jan/11    - FlexRay reserved areas corrected	  */
/*                                 - Added BIUCR4              			  */
/* 0.8   I.Harris     26/Sept/11   - Corrected Flexray MCR bitfield from  */
/* 									BIRRATE to BITRATE 					  */
/*                                 - DECFIL_EDID size fix (16 to 32)	  */
/*                                 - eSCI_LTR LEN field size fix (1 to 8) */
/*                                 - Flexray frame header fixed			  */
/**************************************************************************/

/**************************************************************************/
/* Example instantiation and use:                                         */
/*                                                                        */
/*  <MODULE>.<REGISTER>.B.<BIT> = 1;                                      */
/*  <MODULE>.<REGISTER>.R       = 0x10000000;                             */
/*                                                                        */
/**************************************************************************/

#ifndef _MPC5644_H_
#define _MPC5644_H_

#include "Platform_Types.h"

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef __MWERKS__
#pragma push
#pragma ANSI_strict off
#endif

/****************************************************************************/
/*       DMA2 Transfer Control Descriptor                                   */
/****************************************************************************/

    struct EDMACD_STDag {          /* for "standard" format TCDs (when EDMA.TCD[x].CITER.E_LINK==BITER.E_LINK=0 && EDMA.EMLM=0 ) */
            /* 00 */
            vuint32 SADDR;    /* Source Address */
    
            /* 04 */            /* Transfer Attributes */
            vuint16 SMOD:5;   /* Source Address Modulo */
            vuint16 SSIZE:3;  /* Source Data Transfer Size */
            vuint16 DMOD:5;   /* Destination Address Modulo */
            vuint16 DSIZE:3;  /* Destination Data Transfer Size */
    
            /* 06 */
            vsint16 SOFF;      /* Signed Source Address Offset */
    
            /* 08 */
            vuint32 NBYTES;   /* Inner ("Minor") Byte Transfer Count */
    
            /* 0C */
            vsint32 SLAST;     /* Last Source Address Adjustment */
    
            /* 10 */
            vuint32 DADDR;    /* Destination Address */
    
            /* 14 */
            vuint16 CITERE_LINK:1;     /* Enable Channel-to-Channel        */
                                         /* Linking on Minor Loop Completion */
            vuint16 CITER:15;          /* Current Major Iteration Count    */
    
            /* 16 */
            vsint16 DOFF;      /* Signed Destination Address Offset */
    
            /* 18 */
            vsint32 DLAST_SGA; /* Last Destination Address Adjustment, or  */
                                /* Scatter/Gather Address (if E_SG = 1)     */
    
            /* 1C */
            vuint16 BITERE_LINK:1;    /* Enable Channel-to-Channel           */
                                        /* Linking on Minor Loop Complete      */
            vuint16 BITER:15;         /* Starting ("Major") Iteration Count */
    
            /* 1E */                    /* Channel Control/Status */
            vuint16 BWC:2;            /* Bandwidth Control */
            vuint16 MAJORLINKCH:6;    /* Link Channel Number */
            vuint16 DONE:1;           /* Channel Done */
            vuint16 ACTIVE:1;
            vuint16 MAJORE_LINK:1;    /* Enable Channel-to-Channel Link */
            vuint16 E_SG:1;           /* Enable Scatter/Gather Descriptor */
            vuint16 D_REQ:1;          /* Disable IPD_REQ When Done */
            vuint16 INT_HALF:1;       /* Interrupt on CITER = (BITER >> 1) */
            vuint16 INT_MAJ:1;        /* Interrupt on Major Loop Completion */
            vuint16 START:1;          /* Explicit Channel Start */
    };

    

    struct EDMACD_alt1ag {  /*for alternate format TCDs (when EDMA.TCD[x].CITER.E_LINK==BITER.E_LINK=1 ) */

            /* 00 */
            vuint32 SADDR;    /* Source Address */

            /* 04 */            /* Transfer Attributes */
            vuint16 SMOD:5;   /* Source Address Modulo */
            vuint16 SSIZE:3;  /* Source Data Transfer Size */
            vuint16 DMOD:5;   /* Destination Address Modulo */
            vuint16 DSIZE:3;  /* Destination Data Transfer Size */

            /* 06 */
            vsint16 SOFF;      /* Signed Source Address Offset */

            /* 08 */
            vuint32 NBYTES;   /* Inner ("Minor") Byte Transfer Count */

            /* 0C */
            vsint32 SLAST;     /* Last Source Address Adjustment */

            /* 10 */
            vuint32 DADDR;    /* Destination Address */

            /* 14 */
            vuint16 CITERE_LINK:1;     /* Enable Channel-to-Channel        */
                                         /* Linking on Minor Loop Completion */
            vuint16 CITERLINKCH:6;     /* Link Channel Number              */
            vuint16 CITER:9;           /* Current Major Iteration Count    */

            /* 16 */
            vsint16 DOFF;      /* Signed Destination Address Offset */

            /* 18 */
            vsint32 DLAST_SGA; /* Last Destination Address Adjustment, or  */
                                /* Scatter/Gather Address (if E_SG = 1)     */

            /* 1C */
            vuint16 BITERE_LINK:1;    /* Enable Channel-to-Channel           */
                                        /* Linking on Minor Loop Complete      */
            vuint16 BITERLINKCH:6;    /* Link Channel Number                 */
            vuint16 BITER:9;          /* Starting ("Major") Iteration Count  */

            /* 1E */                    /* Channel Control/Status */
            vuint16 BWC:2;            /* Bandwidth Control */
            vuint16 MAJORLINKCH:6;    /* Link Channel Number */
            vuint16 DONE:1;           /* Channel Done */
            vuint16 ACTIVE:1;         /* Channel Active */
            vuint16 MAJORE_LINK:1;    /* Enable Channel-to-Channel Link */
            vuint16 E_SG:1;           /* Enable Scatter/Gather Descriptor */
            vuint16 D_REQ:1;          /* Disable IPD_REQ When Done */
            vuint16 INT_HALF:1;       /* Interrupt on CITER = (BITER >> 1) */
            vuint16 INT_MAJ:1;        /* Interrupt on Major Loop Completion */
            vuint16 START:1;          /* Explicit Channel Start */
    };

    struct EDMACD_alt2ag {  /*       for alternate format TCDs (when EDMA.EMLM=1) */

            vuint32 SADDR;    /* source address */

            vuint16 SMOD:5;   /* source address modulo */
            vuint16 SSIZE:3;  /* source transfer size */
            vuint16 DMOD:5;   /* destination address modulo */
            vuint16 DSIZE:3;  /* destination transfer size */
            vsint16 SOFF;      /* signed source address offset */

            vuint16 SMLOE:1;  /* Source minor loop offset enable */
            vuint16 DMLOE:1;  /* Destination minor loop offset enable */
            vuint32 MLOFF:20; /* Minor loop Offset */
            vuint16 NBYTES:10;        /* inner (�minor�) byte count */

            vsint32 SLAST;     /* last destination address adjustment, or

                                   scatter/gather address (if e_sg = 1) */
            vuint32 DADDR;    /* destination address */

            vuint16 CITERE_LINK:1;
            vuint16 CITER:15;

            vsint16 DOFF;      /* signed destination address offset */

            vsint32 DLAST_SGA;

            vuint16 BITERE_LINK:1;    /* beginning ("major") iteration count */
            vuint16 BITER:15;

            vuint16 BWC:2;    /* bandwidth control */
            vuint16 MAJORLINKCH:6;    /* enable channel-to-channel link */
            vuint16 DONE:1;   /* channel done */
            vuint16 ACTIVE:1; /* channel active */
            vuint16 MAJORE_LINK:1;    /* enable channel-to-channel link */
            vuint16 E_SG:1;   /* enable scatter/gather descriptor */
            vuint16 D_REQ:1;  /* disable ipd_req when done */
            vuint16 INT_HALF:1;       /* interrupt on citer = (biter >> 1) */
            vuint16 INT_MAJ:1;        /* interrupt on major loop completion */
            vuint16 START:1;  /* explicit channel start */
    };
    

/****************************************************************************/
/*                          MODULE : eDMA                                   */
/****************************************************************************/

    struct EDMAag {

        union {
            vuint32 R;
            struct {
                vuint32:14;           /* Reserved */
                vuint32 CX:1;         /* Cancel Transfer */
                vuint32 ECX:1;        /* Error Cancel Transfer  */
                vuint32 GRP3PRI:2;    /* Channel Group 3 Priority  */
                vuint32 GRP2PRI:2;    /* Channel Group 2 Priority  */
                vuint32 GRP1PRI:2;    /* Channel Group 1 Priority  */
                vuint32 GRP0PRI:2;    /* Channel Group 0 Priority  */
                vuint32 EMLM:1;       /* Enable Minor Loop Mapping */
                vuint32 CLM:1;        /* Continuous Link Mode */
                vuint32 HALT:1;       /* Halt DMA Operations  */
                vuint32 HOE:1;        /* Halt On Error */
                vuint32 ERGA:1;       /* Enable Round Robin Group Arbitration */
                vuint32 ERCA:1;       /* Enable Round Robin Channel Arbitration */
                vuint32 EDBG:1;       /* Enable Debug */
                vuint32:1;            /* Enable Buffered Writes */
            } B;
        } CR;                /* DMA Control Register @baseaddress + 0x0 */

        union {
            vuint32 R;
            struct {
                vuint32 VLD:1;        /* Logical OR of all DMAERRH */
                vuint32:14;           /* Reserved */
                vuint32 ECX:1;        /* Transfer Canceled */
                vuint32 GPE:1;        /* Group Priority Error */
                vuint32 CPE:1;        /* Channel Priority Error  */
                vuint32 ERRCHN:6;     /* ERRCHN[5:0] Error Channel Number or The channel number of the last recorded error */
                vuint32 SAE:1;        /* Source Address Error 0  */
                vuint32 SOE:1;        /* Source Offset Error */
                vuint32 DAE:1;        /* Destination Address Error */
                vuint32 DOE:1;        /* Destination Offset Error */
                vuint32 NCE:1;        /* Nbytes/Citer Configuration Error */
                vuint32 SGE:1;        /* Scatter/Gather Configuration Error */
                vuint32 SBE:1;        /* Source Bus Error */
                vuint32 DBE:1;        /* Destination Bus Error  */
            } B;
        } ESR;               /* Error Status Register @baseaddress + 0x4 */

        union {
            vuint32 R;
            struct {
                vuint32 ERQ63:1;
                vuint32 ERQ62:1;
                vuint32 ERQ61:1;
                vuint32 ERQ60:1;
                vuint32 ERQ59:1;
                vuint32 ERQ58:1;
                vuint32 ERQ57:1;
                vuint32 ERQ56:1;
                vuint32 ERQ55:1;
                vuint32 ERQ54:1;
                vuint32 ERQ53:1;
                vuint32 ERQ52:1;
                vuint32 ERQ51:1;
                vuint32 ERQ50:1;
                vuint32 ERQ49:1;
                vuint32 ERQ48:1;
                vuint32 ERQ47:1;
                vuint32 ERQ46:1;
                vuint32 ERQ45:1;
                vuint32 ERQ44:1;
                vuint32 ERQ43:1;
                vuint32 ERQ42:1;
                vuint32 ERQ41:1;
                vuint32 ERQ40:1;
                vuint32 ERQ39:1;
                vuint32 ERQ38:1;
                vuint32 ERQ37:1;
                vuint32 ERQ36:1;
                vuint32 ERQ35:1;
                vuint32 ERQ34:1;
                vuint32 ERQ33:1;
                vuint32 ERQ32:1;
            } B;
        } ERQRH;              /* DMA Enable Request Register High @baseaddress + 0x8*/

        union {
            vuint32 R;
            struct {
                vuint32 ERQ31:1;
                vuint32 ERQ30:1;
                vuint32 ERQ29:1;
                vuint32 ERQ28:1;
                vuint32 ERQ27:1;
                vuint32 ERQ26:1;
                vuint32 ERQ25:1;
                vuint32 ERQ24:1;
                vuint32 ERQ23:1;
                vuint32 ERQ22:1;
                vuint32 ERQ21:1;
                vuint32 ERQ20:1;
                vuint32 ERQ19:1;
                vuint32 ERQ18:1;
                vuint32 ERQ17:1;
                vuint32 ERQ16:1;
                vuint32 ERQ15:1;
                vuint32 ERQ14:1;
                vuint32 ERQ13:1;
                vuint32 ERQ12:1;
                vuint32 ERQ11:1;
                vuint32 ERQ10:1;
                vuint32 ERQ09:1;
                vuint32 ERQ08:1;
                vuint32 ERQ07:1;
                vuint32 ERQ06:1;
                vuint32 ERQ05:1;
                vuint32 ERQ04:1;
                vuint32 ERQ03:1;
                vuint32 ERQ02:1;
                vuint32 ERQ01:1;
                vuint32 ERQ00:1;
            } B;
        } ERQRL;              /* DMA Enable Request Register Low @baseaddress + 0xC*/

        union {
            vuint32 R;
            struct {

                vuint32 EEI63:1;
                vuint32 EEI62:1;
                vuint32 EEI61:1;
                vuint32 EEI60:1;
                vuint32 EEI59:1;
                vuint32 EEI58:1;
                vuint32 EEI57:1;
                vuint32 EEI56:1;
                vuint32 EEI55:1;
                vuint32 EEI54:1;
                vuint32 EEI53:1;
                vuint32 EEI52:1;
                vuint32 EEI51:1;
                vuint32 EEI50:1;
                vuint32 EEI49:1;
                vuint32 EEI48:1;
                vuint32 EEI47:1;
                vuint32 EEI46:1;
                vuint32 EEI45:1;
                vuint32 EEI44:1;
                vuint32 EEI43:1;
                vuint32 EEI42:1;
                vuint32 EEI41:1;
                vuint32 EEI40:1;
                vuint32 EEI39:1;
                vuint32 EEI38:1;
                vuint32 EEI37:1;
                vuint32 EEI36:1;
                vuint32 EEI35:1;
                vuint32 EEI34:1;
                vuint32 EEI33:1;
                vuint32 EEI32:1;
            } B;
        } EEIRH;              /* DMA Enable Error Interrupt Register High @baseaddress + 0x10*/

        union {
            vuint32 R;
            struct {
                vuint32 EEI31:1;
                vuint32 EEI30:1;
                vuint32 EEI29:1;
                vuint32 EEI28:1;
                vuint32 EEI27:1;
                vuint32 EEI26:1;
                vuint32 EEI25:1;
                vuint32 EEI24:1;
                vuint32 EEI23:1;
                vuint32 EEI22:1;
                vuint32 EEI21:1;
                vuint32 EEI20:1;
                vuint32 EEI19:1;
                vuint32 EEI18:1;
                vuint32 EEI17:1;
                vuint32 EEI16:1;
                vuint32 EEI15:1;
                vuint32 EEI14:1;
                vuint32 EEI13:1;
                vuint32 EEI12:1;
                vuint32 EEI11:1;
                vuint32 EEI10:1;
                vuint32 EEI09:1;
                vuint32 EEI08:1;
                vuint32 EEI07:1;
                vuint32 EEI06:1;
                vuint32 EEI05:1;
                vuint32 EEI04:1;
                vuint32 EEI03:1;
                vuint32 EEI02:1;
                vuint32 EEI01:1;
                vuint32 EEI00:1;
            } B;
        } EEIRL;              /* DMA Enable Error Interrupt Register Low @baseaddress + 0x14*/

        union {
            vuint8 R;
            struct {
                vuint8 NOP:1;
                vuint8 SERQ:7;
            } B;
        } SERQR;              /* DMA Set Enable Request Register @baseaddress + 0x18*/

        union {
            vuint8 R;
            struct {
                vuint8 NOP:1;
                vuint8 CERQ:7;
            } B;
        } CERQR;              /* DMA Clear Enable Request Register @baseaddress + 0x19*/

        union {
            vuint8 R;
            struct {
                vuint8 NOP:1;
                vuint8 SEEI:7;
            } B;
        } SEEIR;              /* DMA Set Enable Error Interrupt Register @baseaddress + 0x1A*/

        union {
            vuint8 R;
            struct {
                vuint8 NOP:1;
                vuint8 CEEI:7;
            } B;
        } CEEIR;              /* DMA Clear Enable Error Interrupt Register @baseaddress + 0x1B*/

        union {
            vuint8 R;
            struct {
                vuint8 NOP:1;
                vuint8 CINT:7;
            } B;
        } CIRQR;              /* DMA Clear Interrupt Request Register @baseaddress + 0x1C */

        union {
            vuint8 R;
            struct {
                vuint8 NOP:1;
                vuint8 CERR:7;
            } B;
        } CER;                /* DMA Clear error Register @baseaddress + 0x1D */

        union {
            vuint8 R;
            struct {
                vuint8 NOP:1;
                vuint8 SSB:7;
            } B;
        } SSBR;               /* Set Start Bit Register @baseaddress + 0x1E */

        union {
            vuint8 R;
            struct {
                vuint8 NOP:1;
                vuint8 CDSB:7;
            } B;
        } CDSBR;              /* Clear Done Status Bit Register @baseaddress + 0x1F */

        union {
            vuint32 R;
            struct {
                vuint32 INT63:1;
                vuint32 INT62:1;
                vuint32 INT61:1;
                vuint32 INT60:1;
                vuint32 INT59:1;
                vuint32 INT58:1;
                vuint32 INT57:1;
                vuint32 INT56:1;
                vuint32 INT55:1;
                vuint32 INT54:1;
                vuint32 INT53:1;
                vuint32 INT52:1;
                vuint32 INT51:1;
                vuint32 INT50:1;
                vuint32 INT49:1;
                vuint32 INT48:1;
                vuint32 INT47:1;
                vuint32 INT46:1;
                vuint32 INT45:1;
                vuint32 INT44:1;
                vuint32 INT43:1;
                vuint32 INT42:1;
                vuint32 INT41:1;
                vuint32 INT40:1;
                vuint32 INT39:1;
                vuint32 INT38:1;
                vuint32 INT37:1;
                vuint32 INT36:1;
                vuint32 INT35:1;
                vuint32 INT34:1;
                vuint32 INT33:1;
                vuint32 sint32:1;
            } B;
        } IRQRH;              /* DMA Interrupt Request High @baseaddress + 0x20 */

        union {
            vuint32 R;
            struct {
                vuint32 INT31:1;
                vuint32 INT30:1;
                vuint32 INT29:1;
                vuint32 INT28:1;
                vuint32 INT27:1;
                vuint32 INT26:1;
                vuint32 INT25:1;
                vuint32 INT24:1;
                vuint32 INT23:1;
                vuint32 INT22:1;
                vuint32 INT21:1;
                vuint32 INT20:1;
                vuint32 INT19:1;
                vuint32 INT18:1;
                vuint32 INT17:1;
                vuint32 INT16:1;
                vuint32 INT15:1;
                vuint32 INT14:1;
                vuint32 INT13:1;
                vuint32 INT12:1;
                vuint32 INT11:1;
                vuint32 INT10:1;
                vuint32 INT09:1;
                vuint32 INT08:1;
                vuint32 INT07:1;
                vuint32 INT06:1;
                vuint32 INT05:1;
                vuint32 INT04:1;
                vuint32 INT03:1;
                vuint32 INT02:1;
                vuint32 INT01:1;
                vuint32 INT00:1;
            } B;
        } IRQRL;              /* DMA Interrupt Request Low @baseaddress + 0x24 */

        union {
            vuint32 R;
            struct {
                vuint32 ERR63:1;
                vuint32 ERR62:1;
                vuint32 ERR61:1;
                vuint32 ERR60:1;
                vuint32 ERR59:1;
                vuint32 ERR58:1;
                vuint32 ERR57:1;
                vuint32 ERR56:1;
                vuint32 ERR55:1;
                vuint32 ERR54:1;
                vuint32 ERR53:1;
                vuint32 ERR52:1;
                vuint32 ERR51:1;
                vuint32 ERR50:1;
                vuint32 ERR49:1;
                vuint32 ERR48:1;
                vuint32 ERR47:1;
                vuint32 ERR46:1;
                vuint32 ERR45:1;
                vuint32 ERR44:1;
                vuint32 ERR43:1;
                vuint32 ERR42:1;
                vuint32 ERR41:1;
                vuint32 ERR40:1;
                vuint32 ERR39:1;
                vuint32 ERR38:1;
                vuint32 ERR37:1;
                vuint32 ERR36:1;
                vuint32 ERR35:1;
                vuint32 ERR34:1;
                vuint32 ERR33:1;
                vuint32 ERR32:1;
            } B;
        } ERH;                /* DMA Error High @baseaddress + 0x28 */

        union {
            vuint32 R;
            struct {
                vuint32 ERR31:1;
                vuint32 ERR30:1;
                vuint32 ERR29:1;
                vuint32 ERR28:1;
                vuint32 ERR27:1;
                vuint32 ERR26:1;
                vuint32 ERR25:1;
                vuint32 ERR24:1;
                vuint32 ERR23:1;
                vuint32 ERR22:1;
                vuint32 ERR21:1;
                vuint32 ERR20:1;
                vuint32 ERR19:1;
                vuint32 ERR18:1;
                vuint32 ERR17:1;
                vuint32 ERR16:1;
                vuint32 ERR15:1;
                vuint32 ERR14:1;
                vuint32 ERR13:1;
                vuint32 ERR12:1;
                vuint32 ERR11:1;
                vuint32 ERR10:1;
                vuint32 ERR09:1;
                vuint32 ERR08:1;
                vuint32 ERR07:1;
                vuint32 ERR06:1;
                vuint32 ERR05:1;
                vuint32 ERR04:1;
                vuint32 ERR03:1;
                vuint32 ERR02:1;
                vuint32 ERR01:1;
                vuint32 ERR00:1;
            } B;
        } ERL;                /* DMA Error Low @baseaddress + 0x2C */

        union {
            vuint32 R;
            struct {
                vuint32 HRS63:1;
                vuint32 HRS62:1;
                vuint32 HRS61:1;
                vuint32 HRS60:1;
                vuint32 HRS59:1;
                vuint32 HRS58:1;
                vuint32 HRS57:1;
                vuint32 HRS56:1;
                vuint32 HRS55:1;
                vuint32 HRS54:1;
                vuint32 HRS53:1;
                vuint32 HRS52:1;
                vuint32 HRS51:1;
                vuint32 HRS50:1;
                vuint32 HRS49:1;
                vuint32 HRS48:1;
                vuint32 HRS47:1;
                vuint32 HRS46:1;
                vuint32 HRS45:1;
                vuint32 HRS44:1;
                vuint32 HRS43:1;
                vuint32 HRS42:1;
                vuint32 HRS41:1;
                vuint32 HRS40:1;
                vuint32 HRS39:1;
                vuint32 HRS38:1;
                vuint32 HRS37:1;
                vuint32 HRS36:1;
                vuint32 HRS35:1;
                vuint32 HRS34:1;
                vuint32 HRS33:1;
                vuint32 HRS32:1;
            } B;
        } HRSH;               /* hardware request status high @baseaddress + 0x30 */

        union {
            vuint32 R;
            struct {
                vuint32 HRS31:1;
                vuint32 HRS30:1;
                vuint32 HRS29:1;
                vuint32 HRS28:1;
                vuint32 HRS27:1;
                vuint32 HRS26:1;
                vuint32 HRS25:1;
                vuint32 HRS24:1;
                vuint32 HRS23:1;
                vuint32 HRS22:1;
                vuint32 HRS21:1;
                vuint32 HRS20:1;
                vuint32 HRS19:1;
                vuint32 HRS18:1;
                vuint32 HRS17:1;
                vuint32 HRS16:1;
                vuint32 HRS15:1;
                vuint32 HRS14:1;
                vuint32 HRS13:1;
                vuint32 HRS12:1;
                vuint32 HRS11:1;
                vuint32 HRS10:1;
                vuint32 HRS09:1;
                vuint32 HRS08:1;
                vuint32 HRS07:1;
                vuint32 HRS06:1;
                vuint32 HRS05:1;
                vuint32 HRS04:1;
                vuint32 HRS03:1;
                vuint32 HRS02:1;
                vuint32 HRS01:1;
                vuint32 HRS00:1;
            } B;
        } HRSL;               /* hardware request status low @baseaddress + 0x34 */

        uint32 eDMA_reserved0038[50];  /* 0x0038-0x00FF */

        union {
            vuint8 R;
            struct {
                vuint8 ECP:1;
                vuint8 DPA:1;
                vuint8 GRPPRI:2;
                vuint8 CHPRI:4;
            } B;
        } CPR[64];            /* Channel n Priority @baseaddress + 0x100 */

        uint32 eDMA_reserved0140[944];  /* 0x0140-0x0FFF */
        
        /* Select one of the following declarations depending on the DMA mode chosen */
        struct EDMACD_STDag TCD[64];              /* Standard Format   */
        /* struct EDMACD_alt1ag TCD[64]; */       /* CITER/BITER Link  */
        /* struct EDMACD_alt2ag TCD[64]; */       /* Minor Loop Offset */
        
        };



/****************************************************************************/
/*                     MODULE : XBAR                                      */
/****************************************************************************/
    struct XBARag {
        union {
            vuint32 R;
            struct {
                  vuint32:1;
                vuint32 MSTR7:3;      /* Master 7 Priority - Reserved */
                  vuint32:1;          
                vuint32 MSTR6:3;      /* Master 6 Priority - FlexRay */  
                  vuint32:4;			/* Master 5 Priority - Not implemented */
                  vuint32:1;
                vuint32 MSTR4:3;      /* Master 4 Priority - eDMA */
                  vuint32:4;          /* Master 3 Priority - Not implemented */
                  vuint32:4;          /* Master 2 Priority - Not implemented */
                  vuint32:1;
                vuint32 MSTR1:3;      /* Master 1 Priority - e200z4 Core load/store & Nexus port  */
                  vuint32:1;
                vuint32 MSTR0:3;      /* Master 0 Priority - e200z4 core Instruction */
            } B;
        } MPR0;                 /* Master Priority Register for Slave port 0 (Flash) @baseaddress + 0x00 */

        sint32 XBAR_reserved_0004[3];      /* 0x0004 - 0x000F */

        union {
            vuint32 R;
            struct {
                vuint32 RO:1;
                vuint32 HLP:1;        /* Halt Low Priority */
                  vuint32:6;
                vuint32 HPE7:1;       /* High Priority Enable */
                vuint32 HPE6:1;       /* High Priority Enable */
                  vuint32:1;
                vuint32 HPE4:1;       /* High Priority Enable */
                  vuint32:1;
                  vuint32:1;
                vuint32 HPE1:1;       /* High Priority Enable */
                vuint32 HPE0:1;       /* High Priority Enable */
                  vuint32:6;
                vuint32 ARB:2;
                vuint32:2;
                vuint32 PCTL:2;
                vuint32:1;
                vuint32 PARK:3;
            } B;
        } SGPCR0;               /* Slave General Purpose Control Register 0 (Flash) @baseaddress + 0x10 */

        sint32 XBAR_reserved_0014[59];     /* 0x0014 - 0x01FF */

        union {
            vuint32 R;
            struct {
                  vuint32:1;
                vuint32 MSTR7:3;      /* Master 7 Priority - Reserved */
                  vuint32:1;          
                vuint32 MSTR6:3;      /* Master 6 Priority - FlexRay */  
                  vuint32:4;			/* Master 5 Priority - Not implemented */
                  vuint32:1;
                vuint32 MSTR4:3;      /* Master 4 Priority - eDMA */
                  vuint32:4;          /* Master 3 Priority - Not implemented */
                  vuint32:4;          /* Master 2 Priority - Not implemented */
                  vuint32:1;
                vuint32 MSTR1:3;      /* Master 1 Priority - e200z4 Core load/store & Nexus port  */
                  vuint32:1;
                vuint32 MSTR0:3;      /* Master 0 Priority - e200z4 core Instruction */
            } B;
        } MPR1;                 /* Master Priority Register for Slave port 1 (EBI) @baseaddress + 0x100 */

        sint32 XBAR_reserved_0100[3];      /* 0x0100 - 0x010F */

        union {
            vuint32 R;
            struct {
                vuint32 RO:1;
                vuint32 HLP:1;        /* Halt Low Priority */
                  vuint32:6;
                vuint32 HPE7:1;       /* High Priority Enable */
                vuint32 HPE6:1;       /* High Priority Enable */
                  vuint32:1;
                vuint32 HPE4:1;       /* High Priority Enable */
                  vuint32:1;
                  vuint32:1;
                vuint32 HPE1:1;       /* High Priority Enable */
                vuint32 HPE0:1;       /* High Priority Enable */
                  vuint32:6;
                vuint32 ARB:2;
                vuint32:2;
                vuint32 PCTL:2;
                vuint32:1;
                vuint32 PARK:3;
            } B;
        } SGPCR1;               /* Slave General Purpose Control Register 1 (EBI) @baseaddress + 0x110 */

        sint32 XBAR_reserved_0114[59]; /* 0x0114 - 0x01FF */

        union {
            vuint32 R;
            struct {
                  vuint32:1;
                vuint32 MSTR7:3;      /* Master 7 Priority - Reserved */
                  vuint32:1;          
                vuint32 MSTR6:3;      /* Master 6 Priority - FlexRay */  
                  vuint32:4;			/* Master 5 Priority - Not implemented */
                  vuint32:1;
                vuint32 MSTR4:3;      /* Master 4 Priority - eDMA */
                  vuint32:4;          /* Master 3 Priority - Not implemented */
                  vuint32:4;          /* Master 2 Priority - Not implemented */
                  vuint32:1;
                vuint32 MSTR1:3;      /* Master 1 Priority - e200z4 Core load/store & Nexus port  */
                  vuint32:1;
                vuint32 MSTR0:3;      /* Master 0 Priority - e200z4 core Instruction */
            } B;
        } MPR2;                 /* Master Priority Register for Slave port 2 (RAM) @baseaddress + 0x200 */

        sint32 XBAR_reserved_0204[3];      /* 0x0204 - 0x020F */

        union {
            vuint32 R;
            struct {
                vuint32 RO:1;
                vuint32 HLP:1;        /* Halt Low Priority */
                  vuint32:6;
                vuint32 HPE7:1;       /* High Priority Enable */
                vuint32 HPE6:1;       /* High Priority Enable */
                  vuint32:1;
                vuint32 HPE4:1;       /* High Priority Enable */
                  vuint32:1;
                  vuint32:1;
                vuint32 HPE1:1;       /* High Priority Enable */
                vuint32 HPE0:1;       /* High Priority Enable */
                  vuint32:6;
                vuint32 ARB:2;
                vuint32:2;
                vuint32 PCTL:2;
                vuint32:1;
                vuint32 PARK:3;
            } B;
        } SGPCR2;               /* Slave General Purpose Control Register 2 (RAM)@baseaddress + 0x210 */

        sint32 XBAR_reserved_0214[59];     /* 0x0214 - 0x02FF */

        /* Slave General Purpose Control Register 3 @baseaddress + 0x310 - not implemented */

        sint32 XBAR_reserved_0300[64];     /* 0x0300 - 0x03FF */

        /* Slave General Purpose Control Register 4 @baseaddress + 0x410 - not implemented */

        sint32 XBAR_reserved_0400[64];     /* 0x0400 - 0x04FF */

        /* Slave XBAR Port 5 Not implemented @baseaddress + 0x510 */

        sint32 XBAR_reserved_0500[64];     /* 0x0500 - 0x05FF */

        /* Slave Port 6 not implemented @baseaddress + 0x610 */

        sint32 XBAR_reserved_0600[64];     /* 0x0600 - 0x06FF */

        union {
            vuint32 R;
            struct {
                  vuint32:1;
                vuint32 MSTR7:3;      /* Master 7 Priority - Reserved */
                  vuint32:1;          
                vuint32 MSTR6:3;      /* Master 6 Priority - FlexRay */  
                  vuint32:4;			/* Master 5 Priority - Not implemented */
                  vuint32:1;
                vuint32 MSTR4:3;      /* Master 4 Priority - eDMA */
                  vuint32:4;          /* Master 3 Priority - Not implemented */
                  vuint32:4;          /* Master 2 Priority - Not implemented */
                  vuint32:1;
                vuint32 MSTR1:3;      /* Master 1 Priority - e200z4 Core load/store & Nexus port  */
                  vuint32:1;
                vuint32 MSTR0:3;      /* Master 0 Priority - e200z4 core Instruction */
            } B;
        } MPR7;                 /* Master Priority Register for Slave port 7 @baseaddress + 0x700 */

        sint32 XBAR_reserved_0704[3];          /* 0x0704 - 0x070F */

        union {
            vuint32 R;
            struct {
                vuint32 RO:1;
                vuint32 HLP:1;        /* Halt Low Priority */
                  vuint32:6;
                vuint32 HPE7:1;       /* High Priority Enable */
                vuint32 HPE6:1;       /* High Priority Enable */
                  vuint32:1;
                vuint32 HPE4:1;       /* High Priority Enable */
                  vuint32:1;
                  vuint32:1;
                vuint32 HPE1:1;       /* High Priority Enable */
                vuint32 HPE0:1;       /* High Priority Enable */
                  vuint32:6;
                vuint32 ARB:2;
                vuint32:2;
                vuint32 PCTL:2;
                vuint32:1;
                vuint32 PARK:3;
            } B;
        } SGPCR7;               /* Slave General Purpose Control Register 7 @baseaddress + 0x710 */

        sint32 XBAR_reserved_0714[59];         /* 0x0714 - 0x07FF */

        sint32 XBAR_reserved_0800[3584];       /* 0x0800-0x3FFF */

    };


/****************************************************************************/
/*                          MODULE : PBRIDGE Peripheral Bridge            */
/****************************************************************************/

	struct PBRIDGEag {
		
		union {                               /* Master Privilege Registers 0-7 @baseaddress + 0x00*/
            vuint32 R;
			struct {
				 vuint32:1;      
				vuint32  MTR0:1;      /* z4 core: Master 0 Trusted for Reads */
				vuint32  MTW0:1;      /* z4 core: Master 0 Trusted for Writes */
				vuint32  MPL0:1;      /* z4 core: Master 0 Priviledge Level */
				 vuint32:13;      
				vuint32  MTR4:1;      /* DMA: Master 4 Trusted for Reads */
				vuint32  MTW4:1;      /* DMA: Master 4 Trusted for Writes */
				vuint32  MPL4:1;      /* DMA: Master 4 Priviledge Level */
				 vuint32:5;      
				vuint32  MTR6:1;      /* FlexRay: Master 6 Trusted for Reads */
				vuint32  MTW6:1;      /* FlexRay: Master 6 Trusted for Writes */
				vuint32  MPL6:1;      /* FlexRay: Master 6 Priviledge Level */
				 vuint32:1;      
				vuint32  MTR7:1;      /* EBI: Master 7 Trusted for Reads */
				vuint32  MTW7:1;      /* EBI: Master 7 Trusted for Writes */
				vuint32  MPL7:1;      /* EBI: Master 7 Priviledge Level */
            } B;
        } MPCR0;
		
		union {                               /* Master Privilege Registers 8-15 @baseaddress + 0x04*/
            vuint32 R;
			struct {
                 vuint32:1;      
				vuint32  MTR8:1;      /* Nexus: Master 8 Trusted for Reads */
				vuint32  MTW8:1;      /* Nexus: Master 8 Trusted for Writes */
				vuint32  MPL8:1;      /* Nexus: Master 8 Priviledge Level */
				 vuint32:28;      
            } B;
        } MPCR1;
		
		uint32 PRIDGE_reserved0008[6];        /* 0x0008-0x001F */
		
		union {                             /* Peripheral Access Conrol Registers 0-7 @baseaddress + 0x20*/
            vuint32 R;
			struct {
				 vuint32:5;    
				vuint32  SP1:1;        /* Crossbar: Supervisor Protect */
				vuint32  WP1:1;        /* Crossbar: Write Protect */
				vuint32  TP1:1;        /* Crossbar: Trusted Protect */
				 vuint32:9;      
				vuint32  SP4:1;        /* MPU: Supervisor Protect */
				vuint32  WP4:1;        /* MPU: Write Protect */
				vuint32  TP4:1;        /* MPU: Trusted Protect */
				 vuint32:12;  
            } B;
        } PACR0;
		
		union {                             /* Peripheral Access Conrol Registers 8-15 @baseaddress + 0x24*/
            vuint32 R;
			struct {
				vuint32:25;    
				vuint32  SP14:1;        /* SWT: Supervisor Protect */
				vuint32  WP14:1;        /* SWT: Write Protect */
				vuint32  TP14:1;        /* SWT: Trusted Protect */
				 vuint32:1;      
				vuint32  SP15:1;        /* STM: Supervisor Protect */
				vuint32  WP15:1;        /* STM: Write Protect */
				vuint32  TP15:1;        /* STM: Trusted Protect */ 
            } B;
        } PACR1;
		
		union {                             /* Peripheral Access Conrol Registers 16-23 @baseaddress + 0x28*/
            vuint32 R;
			struct {
				vuint32:1;    
				vuint32  SP16:1;        /* ECSM: Supervisor Protect */
				vuint32  WP16:1;        /* ECSM: Write Protect */
				vuint32  TP16:1;        /* ECSM: Trusted Protect */
				 vuint32:1;      
				vuint32  SP17:1;        /* DMA: Supervisor Protect */
				vuint32  WP17:1;        /* DMA: Write Protect */
				vuint32  TP17:1;        /* DMA: Trusted Protect */ 
				 vuint32:1;      
				vuint32  SP18:1;        /* INTC: Supervisor Protect */
				vuint32  WP18:1;        /* INTC: Write Protect */
				vuint32  TP18:1;        /* INTC: Trusted Protect */ 
				 vuint32:20; 
            } B;
        } PACR2;
		
		union {                             /* Peripheral Access Conrol Registers 24-31 @baseaddress + 0x2C*/
            vuint32 R;
			struct {
				 vuint32:32;    
			} B;
        } PACR3;
		
		uint32 PRIDGE_reserved0030[4];        /* 0x0030-0x003C */
		
		union {                             /* Off-Platform Access Control Registers 0-7 @baseaddress + 0x40*/
            vuint32 R;
			struct {
                 vuint32:1;      
				vuint32  SP0:1;       /* eQADC: Supervisor Protect */
				vuint32  WP0:1;       /* eQADC: Write Protect */
				vuint32  TP0:1;       /* eQADC: Trusted Protect */
				 vuint32:5; 
				vuint32  SP2:1;       /* Dec Filter A: Supervisor Protect */
				vuint32  WP2:1;       /* Dec Filter A: Write Protect */
				vuint32  TP2:1;       /* Dec Filter A: Trusted Protect */
				vuint32:1;       
				vuint32  SP3:1;       /* Dec Filter B: Supervisor Protect */
				vuint32  WP3:1;       /* Dec Filter B: Write Protect */
				vuint32  TP3:1;       /* Dec Filter B: Trusted Protect */
				vuint32:5;       
				vuint32  SP5:1;       /* DSPIB: Supervisor Protect */
				vuint32  WP5:1;       /* DSPIB: Write Protect */
				vuint32  TP5:1;       /* DSPIB: Trusted Protect */
				vuint32:1;     
				vuint32  SP6:1;       /* DSPIC: Supervisor Protect */
				vuint32  WP6:1;       /* DSPIC: Write Protect */
				vuint32  TP6:1;       /* DSPIC: Trusted Protect */
				vuint32:1; 
				vuint32  SP7:1;       /* DSPID: Supervisor Protect */
				vuint32  WP7:1;       /* DSPID: Write Protect */
				vuint32  TP7:1;       /* DSPID: Trusted Protect */
            } B;
        } OPACR0;
		
		union {   							/* Off-Platform Access Control Registers 8-15 @baseaddress + 0x44*/
			vuint32 R;
			struct {
				 vuint32:17;      
				vuint32  SP12:1;      /* eSCIA: Supervisor Protect */
				vuint32  WP12:1;      /* eSCIA: Write Protect */
				vuint32  TP12:1;      /* eSCIA: Trusted Protect */
				 vuint32:1;    
				vuint32  SP13:1;      /* eSCIB: Supervisor Protect */
				vuint32  WP13:1;      /* eSCIB: Write Protect */
				vuint32  TP13:1;      /* eSCIB: Trusted Protect */
				 vuint32:1;   
				vuint32  SP14:1;      /* eSCIC: Supervisor Protect */
				vuint32  WP14:1;      /* eSCIC: Write Protect */
				vuint32  TP14:1;      /* eSCIC: Trusted Protect */
				 vuint32:4;
			} B;
        } OPACR1;	 
		   
		union {   							/* Off-Platform Access Control Registers 16-23 @baseaddress + 0x48*/
			vuint32 R;
			struct {
				 vuint32:1;      
				vuint32  SP16:1;      /* FlexCANA: Supervisor Protect */
				vuint32  WP16:1;      /* FlexCANA: Write Protect */
				vuint32  TP16:1;      /* FlexCANA: Trusted Protect */
				 vuint32:1;    
				vuint32  SP17:1;      /* FlexCANB: Supervisor Protect */
				vuint32  WP17:1;      /* FlexCANB: Write Protect */
				vuint32  TP17:1;      /* FlexCANB: Trusted Protect */
				 vuint32:1;   
				vuint32  SP18:1;      /* FlexCANC: Supervisor Protect */
				vuint32  WP18:1;      /* FlexCANC: Write Protect */
				vuint32  TP18:1;      /* FlexCANC: Trusted Protect */
				 vuint32:20;
			} B;
		} OPACR2;
		   
		union {   							/* Off-Platform Access Control Registers 24-31 @baseaddress + 0x4C*/
			vuint32 R;
			struct {
				 vuint32:1;      
				vuint32  SP24:1;      /* FlexRay: Supervisor Protect */
				vuint32  WP24:1;      /* FlexRay: Write Protect */
				vuint32  TP24:1;      /* FlexRay: Trusted Protect */
				 vuint32:9;    
				vuint32  SP27:1;      /* SIM: Supervisor Protect */
				vuint32  WP27:1;      /* SIM: Write Protect */
				vuint32  TP27:1;      /* SIM: Trusted Protect */
				 vuint32:13;   
				vuint32  SP31:1;      /* BAM: Supervisor Protect */
				vuint32  WP31:1;      /* BAM: Write Protect */
				vuint32  TP31:1;      /* BAM: Trusted Protect */
			} B;
		} OPACR3;
		
		union {   							/* Off-Platform Access Control Registers 32-39 @baseaddress + 0x50*/
			vuint32 R;
			struct {
				 vuint32:32;      
			} B;
		} OPACR4;
		
		union {   							/* Off-Platform Access Control Registers 40-47 @baseaddress + 0x54*/
			vuint32 R;
			struct {
				 vuint32:32;      
			} B;
		} OPACR5;
		
		union {   							/* Off-Platform Access Control Registers 48-55 @baseaddress + 0x58*/
			vuint32 R;
			struct {
				 vuint32:32;      
			} B;
		} OPACR6;
		
		union {   							/* Off-Platform Access Control Registers 56-63 @baseaddress + 0x5C*/
			vuint32 R;
			struct {
				 vuint32:9;  
				vuint32  SP58:1;      /* CRC: Supervisor Protect */
				vuint32  WP58:1;      /* CRC: Write Protect */
				vuint32  TP58:1;      /* CRC: Trusted Protect */
				 vuint32:20; 
			} B;
		} OPACR7;
		
		union {   							/* Off-Platform Access Control Registers 64-71 @baseaddress + 0x60*/
			vuint32 R;
			struct {
				 vuint32:1;  
				vuint32  SP64:1;      /* FMPLL: Supervisor Protect */
				vuint32  WP64:1;      /* FMPLL: Write Protect */
				vuint32  TP64:1;      /* FMPLL: Trusted Protect */
				 vuint32:1;  
				vuint32  SP65:1;      /* EBI: Supervisor Protect */
				vuint32  WP65:1;      /* EBI: Write Protect */
				vuint32  TP65:1;      /* EBI: Trusted Protect */
				 vuint32:1;  
				vuint32  SP66:1;      /* FlashA: Supervisor Protect */
				vuint32  WP66:1;      /* FlashA: Write Protect */
				vuint32  TP66:1;      /* FlashA: Trusted Protect */
				 vuint32:1;  
				vuint32  SP67:1;      /* FlashB: Supervisor Protect */
				vuint32  WP67:1;      /* FlashB: Write Protect */
				vuint32  TP67:1;      /* FlashB: Trusted Protect */
				 vuint32:1;  
				vuint32  SP68:1;      /* SIU: Supervisor Protect */
				vuint32  WP68:1;      /* SIU: Write Protect */
				vuint32  TP68:1;      /* SIU: Trusted Protect */
				 vuint32:9;  
				vuint32  SP71:1;      /* DTS: Supervisor Protect */
				vuint32  WP71:1;      /* DTS: Write Protect */
				vuint32  TP71:1;      /* DTS: Trusted Protect */
			} B;
		} OPACR8;
		
		union {   							/* Off-Platform Access Control Registers 72-79 @baseaddress + 0x64*/
			vuint32 R;
			struct {
				 vuint32:1;  
				vuint32  SP72:1;      /* eMIOS: Supervisor Protect */
				vuint32  WP72:1;      /* eMIOS: Write Protect */
				vuint32  TP72:1;      /* eMIOS: Trusted Protect */
				 vuint32:25;  
				vuint32  SP79:1;      /* PMC: Supervisor Protect */
				vuint32  WP79:1;      /* PMC: Write Protect */
				vuint32  TP79:1;      /* PMC: Trusted Protect */
			} B;
		} OPACR9;
		
		union {   							/* Off-Platform Access Control Registers 80-87 @baseaddress + 0x68*/
			vuint32 R;
			struct {
				 vuint32:1;  
				vuint32  SP80:1;      /* eTPU2: Supervisor Protect */
				vuint32  WP80:1;      /* eTPU2: Write Protect */
				vuint32  TP80:1;      /* eTPU2: Trusted Protect */
				 vuint32:1;  
				vuint32  SP81:1;      /* REACM: Supervisor Protect */
				vuint32  WP81:1;      /* REACM: Write Protect */
				vuint32  TP81:1;      /* REACM: Trusted Protect */
				 vuint32:1;  
				vuint32  SP82:1;      /* eTPU PRAM: Supervisor Protect */
				vuint32  WP82:1;      /* eTPU PRAM: Write Protect */
				vuint32  TP82:1;      /* eTPU PRAM: Trusted Protect */
				 vuint32:1;  
				vuint32  SP83:1;      /* eTPU PRAM mirror: Supervisor Protect */
				vuint32  WP83:1;      /* eTPU PRAM mirror: Write Protect */
				vuint32  TP83:1;      /* eTPU PRAM mirror: Trusted Protect */
				 vuint32:1;  
				vuint32  SP84:1;      /* eTPU CRAM: Supervisor Protect */
				vuint32  WP84:1;      /* eTPU CRAM: Write Protect */
				vuint32  TP84:1;      /* eTPU CRAM: Trusted Protect */
				 vuint32:12;  
			} B;
		} OPACR10;
		
		union {   							/* Off-Platform Access Control Registers 88-95 @baseaddress + 0x6C*/
			vuint32 R;
			struct {
				 vuint32:17;  
				vuint32  SP92:1;      /* PIT: Supervisor Protect */
				vuint32  WP92:1;      /* PIT: Write Protect */
				vuint32  TP92:1;      /* PIT: Trusted Protect */
				 vuint32:12; 
			} B;
		} OPACR11;
		
		uint32 PRIDGE_reserved0070[4068];        /* 0x0070-0x3FFF */
		
	};

/****************************************************************************/
/*                     MODULE : FLASH                                       */
/****************************************************************************/

    struct FLASHag {

        union {                             /* Module Configuration Register @baseaddress + 0x00*/
            vuint32 R;
            struct {
                vuint32:5;
                vuint32 SIZE:3;
                vuint32:1;
                vuint32 LAS:3;
                vuint32:3;
                vuint32 MAS:1;
                vuint32 EER:1;
                vuint32 RWE:1;
                vuint32 SBC:1;
                vuint32:1;
                vuint32 PEAS:1;
                vuint32 DONE:1;
                vuint32 PEG:1;
                vuint32:4;
                vuint32 PGM:1;
                vuint32 PSUS:1;
                vuint32 ERS:1;
                vuint32 ESUS:1;
                vuint32 EHV:1;
            } B;
        } MCR;

        union {
            vuint32 R;
            struct {
                vuint32 LME:1;
                vuint32:10;
                vuint32 SLOCK:1;
                vuint32:2;
                vuint32 MLOCK:2;
                vuint32:6;
                vuint32 LLOCK:10;
            } B;                            /* Low/Mid Address Space Block Locking Register @baseaddress + 0x04*/
        } LMLR;

        union {
            vuint32 R;
            struct {
                vuint32 HBE:1;
                vuint32:25;
                vuint32 HBLOCK:6;
            } B;
        } HLR;                              /* High Address Space Block Locking Register @baseaddress + 0x08*/

        union {
            vuint32 R;
            struct {
                vuint32 SLE:1;
                vuint32:10;
                vuint32 SSLOCK:1;
                vuint32:2;
                vuint32 SMLOCK:2;
                vuint32:6;
                vuint32 SLLOCK:10;
            } B;
        } SLMLR;                            /* Secondary Low/Mid Block Locking Register @baseaddress + 0x0C*/

        union {
            vuint32 R;
            struct {
                vuint32:14;
                vuint32 MSEL:2;
                vuint32:6;
                vuint32 LSEL:10;
            } B;
        } LMSR;                             /* Low/Mid Address Space Block Select Register @baseaddress + 0x10*/

        union {
            vuint32 R;
            struct {
                vuint32:26;
                vuint32 HBSEL:6;
            } B;
        } HSR;                              /* High Address Space Block Select Register @baseaddress + 0x14*/

        union {
            vuint32 R;
            struct {
                vuint32 SAD:1;
                vuint32:13;
                vuint32 ADDR:15;
                vuint32:3;
            } B;
        } AR;                               /* Address Register @baseaddress + 0x18*/

        union {
            vuint32 R;
            struct {
                vuint32:7;
                vuint32:1;           /* Reserved */
                vuint32:1;           /* EBI Testing - Reserved */
                vuint32 M6PFE:1;     /* FlexRay  */
                vuint32:1;           /* Reserved */
                vuint32 M4PFE:1;     /* eDMA     */
                vuint32:1;           /* Reserved */
                vuint32:1;           /* Reserved */
                vuint32 M1PFE:1;     /* z4 Core Load/Store  */
                vuint32 M0PFE:1;     /* z4 Core Instruction */
                vuint32 APC:3;
                vuint32 WWSC:2;
                vuint32 RWSC:3;
                vuint32:1;
                vuint32 DPFEN:1;
                vuint32:1;
                vuint32 IPFEN:1;
                vuint32:1;
                vuint32 PFLIM:2;
                vuint32 BFEN:1;
            } B;
        } BIUCR;                            /* Bus Interface Unit Configuration Register 1 @baseaddress + 0x1C*/

        union {
            vuint32 R;
            struct {
                vuint32:14;
                vuint32:2;          /* Reserved */
                vuint32:2;          /* EBI Testing - Reserved */
                vuint32 M6AP:2;     /* FlexRay  */
                vuint32:2;          /* Reserved */
                vuint32 M4AP:2;     /* eDMA_A   */
                vuint32:2;          /* Reserved */
                vuint32:2;          /* Reserved */
                vuint32 M1AP:2;     /* z4 Core Load/Store  */
                vuint32 M0AP:2;     /* z4 Core Instruction */
            } B;
        } BIUAPR;                           /*Bus Interface Unit Access Protection Register @baseaddress + 0x20*/

        union {
            vuint32 R;
            struct {
                vuint32 LBCFG:2;
                vuint32:30;
            } B;
        } BIUCR2;                           /* Bus Interface Unit Configuration Register 2 @baseaddress + 0x24*/

        uint32 FLASH_reserved0028[1];  /* 0x0028 */
		
		 union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 V33DIS:1;
            } B;
        } BIUCR4;                           /* Bus Interface Unit Configuration Register 4 @baseaddress + 0x2C*/
		
		uint32 FLASH_reserved0030[3];  /* 0x0030-0x003B */
        
        union {                 /* User Test 0 (UT0) register@baseaddress + 0x3C */
            vuint32 R;
            struct {
                vuint32 UTE:1;        /* User test enable (Read/Clear) */
                vuint32 SBCE:1;       /* Single bit correction enable (Read/Clear) */
                  vuint32:6;  /* Reserved */
                vuint32 DSI:8;        /* Data syndrome input (Read/Write) */
                  vuint32:9;  /* Reserved */
                  vuint32:1;  /* Reserved (Read/Write) */
                vuint32 MRE:1;        /* Margin Read Enable (Read/Write) */
                vuint32 MRV:1;        /* Margin Read Value (Read/Write) */
                vuint32 EIE:1;        /* ECC data Input Enable (Read/Write) */
                vuint32 AIS:1;        /* Array Integrity Sequence (Read/Write) */
                vuint32 AIE:1;        /* Array Integrity Enable (Read/Write) */
                vuint32 AID:1;        /* Array Integrity Done (Read Only) */
            } B;
        } UT0;

        union {                 /* User Test 1 (UT1) register@baseaddress + 0x40 */
            vuint32 R;
            struct {
                vuint32 DAI:32;       /* Data Array Input (Read/Write) */
            } B;
        } UT1;

        union {                 /* User Test 2 (UT2) register@baseaddress + 0x44 */
            vuint32 R;
            struct {
                vuint32 DAI:32;       /* Data Array Input (Read/Write) */
            } B;
        } UT2;

        union {                 /* User Multiple Input Signature Register 0-5 (UMISR[5])@baseaddress + 0x48 */
            vuint32 R;
            struct {
                vuint32 MS:32;        /* Multiple input Signature (Read/Write) */
            } B;
        } UMISR[5];
        
        uint32 FLASH_reserved005C[4073];  /* 0x005C-0x3FFF */
    };
    
/****************************************************************************/
/*                     MODULE : EBI                                         */
/****************************************************************************/
    struct CSag {
        union {
            vuint32 R;
            struct {
                vuint32 BA:17;
                vuint32:3;
                vuint32 PS:1;
                vuint32:3;
                vuint32 AD_MUX:1;
                vuint32 BL:1;
                vuint32 WEBS:1;
                vuint32 TBDIP:1;
                vuint32:1;
                vuint32 SETA:1;
                vuint32 BI:1;
                vuint32 V:1;
            } B;
        } BR;                           /* EBI Base Registers (BR) @baseaddress + 0x10 - 0x28 */
        union {
            vuint32 R;
            struct {
                vuint32 AM:17;
                vuint32:7;
                vuint32 SCY:4;
                vuint32:1;
                vuint32 BSCY:2;
                vuint32:1;
            } B;
        } OR;                           /* EBI Option Registers (OR) @baseaddress + 0x14 - 0x2C */
    };
    struct CAL_CSag {
        union {
            vuint32 R;
            struct {
                vuint32 BA:17;
                vuint32:3;
                vuint32 PS:1;
                vuint32:3;
                vuint32 AD_MUX:1;
                vuint32 BL:1;
                vuint32 WEBS:1;
                vuint32 TBDIP:1;
                vuint32:1;
                vuint32 SETA:1;
                vuint32 BI:1;	
                vuint32 V:1;
            } B;
        } BR;                           /* EBI CAL Base Registers (CAL_BR) @baseaddress + 0x40 - 0x58 */
        union {
            vuint32 R;
            struct {
                vuint32 AM:17;
                vuint32:7;
                vuint32 SCY:4;
                vuint32:1;
                vuint32 BSCY:2;
                vuint32:1;

            } B;
        } OR;                           /* EBI CAL Option Registers (CAL_OR) @baseaddress + 0x44 - 0x5C */
    };


    struct EBIag {
        union {
            vuint32 R;
            struct {
                 vuint32:16;
                vuint32 ACGE:1;
                 vuint32:8;
                vuint32 MDIS:1;
                 vuint32:3;
                vuint32 D16_31:1;
                vuint32 AD_MUX:1;
                vuint32 DBM:1;
            } B;
        } MCR;                          /* EBI Module Configuration Register (MCR) @baseaddress + 0x00 */
        
		uint32 EBI_reserved0004[1];   /* 0x0004-0x0008 */
        
		union {
            vuint32 R;
            struct {
                 vuint32:31;
                vuint32 BMTF:1;
            } B;
        } TESR;                         /* EBI Transfer Error Status Register (TESR) @baseaddress + 0x08 */
        
		union {
            vuint32 R;
            struct {
                 vuint32:16;
                vuint32 BMT:8;
                vuint32 BME:1;
                  vuint32:7;
            } B;
        } BMCR;                         /* EBI Bus Montior Control Register (BMCR) @baseaddress + 0x0C */

        struct CSag CS[4];            /* EBI CS Registers (BR / OR) @baseaddress + 0x10 - 0x2C */

        uint32 EBI_reserved0030[4];   /* 0x0030 - 0x003C */

        struct CAL_CSag CAL_CS[4];    /* EBI CAL_CS Registers (CAL_BR / CAL_OR) @baseaddress + 0x40 - 0x5C */
    };


/****************************************************************************/
/*                     MODULE : INTC                                      */
/****************************************************************************/
    struct INTCag {
        union {
            vuint32 R;
            struct {
                vuint32:18;   /* Reserved */
                  vuint32:1;  /* Reserved */
                  vuint32:4;  /* Reserved */
                  vuint32:1;  /* Reserved */
                  vuint32:2;  /* Reserved */
                vuint32 VTES:1;       /* Vector Table Entry Size */
                  vuint32:4;  /* Reserved */
                vuint32 HVEN:1;       /* Hardware Vector Enable */
            } B;
        } MCR;                  /* INTC Module Configuration Register (MCR) @baseaddress + 0x00 */

        sint32 INTC_Reserved_0004[1];     /* 0x0004 - 0x0007 */

        union {
            vuint32 R;
            struct {
                vuint32:28;   /* Reserved */
                vuint32 PRI:4;        /* Priority */
            } B;
        } CPR;                  /* INTC Current Priority Register (CPR) @baseaddress + 0x08 */

        sint32 INTC_reserved_000C;        /* 0x000C - 0x000F */

        union {
            vuint32 R;
            struct {
                vuint32 VTBA:21;      /* Vector Table Base Address */
                vuint32 INTVEC:9;     /* Interrupt Vector */
                  vuint32:2;          /* Reserved */
            } B;
        } IACKR;                /* INTC Interrupt Acknowledge Register (IACKR) @baseaddress + 0x10 */

        sint32 INTC_Reserved_0014;       /* 0x0014 - 0x00017 */

        union {
            vuint32 R;
            struct {
                vuint32:32;   /* Reserved */
            } B;
        } EOIR;                 /* INTC End of Interrupt Register (EOIR) @baseaddress + 0x18 */

        sint32 INTC_Reserved_001C;       /* 0x001C - 0x001F */

        union {
            vuint8 R;
            struct {
                vuint8:6;     /* Reserved */
                vuint8 SET:1; /* Set Flag bits */
                vuint8 CLR:1; /* Clear Flag bits */
            } B;
        } SSCIR[8];             /* INTC Software Set/Clear Interrupt Registers (SSCIR) @baseaddress + 0x20 */

        sint32 INTC_Reserved_0028[6];     /* 0x0028 - 0x003F */

        union {
            vuint8 R;
            struct {
                  vuint8:2;   /* Reserved */
                  vuint8:2;   /* Reserved */
                vuint8 PRI:4; /* Priority Select */
            } B;
        } PSR[512];             /* INTC Priority Select Registers (PSR) @baseaddress + 0x40 */

    };


/****************************************************************************/
/*                     MODULE : SIU                                      */
/****************************************************************************/
    struct SIUag {
        union {
            vuint32 R;
            struct {
                vuint32 S_F:1;                /* Identifies the Manufacturer */
                vuint32 FLASH_SIZE_1:4;       /* Define major Flash memory size (see Table 15-4 for details) */
                vuint32 FLASH_SIZE_2:4;       /* Define Flash memory size, small granularity  */
                vuint32 TEMP_RANGE:2;         /* Define maximum operating range  */
                  vuint32:1;                  /* Reserved for future enhancements */
                vuint32 MAX_FREQ:2;           /* Define maximum device speed  */
                  vuint32:1;                  /* Reserved for future enhancements */
                vuint32 SUPPLY:1;             /* Defines if the part is 5V or 3V  */
                vuint32 PART_NUMBER:8;        /* Contain the ASCII representation of the character that indicates the product  */
                vuint32 TBD:1;                /* 1-bit field defined by SoC to describe optional feature, e.g., additional SPI */
                  vuint32:2;                  /* Reserved for future enhancements */
                vuint32 EE:1;                 /* Indicates if Data Flash is present */
                  vuint32:3;                  /* Reserved for future enhancements */
                vuint32 FR:1;                 /* Indicates if Data FlexRay is present */
            } B;
        } MIDR2;                /* MCU ID Register 2  @baseaddress + 0x0 */

        union {
            vuint32 R;
            struct {
                vuint32 PARTNUM:16;   /* Device part number */
                vuint32 CSP:1;        /* CSP configuration */
                vuint32 PKG:5;        /* Indicate the package the die is mounted in. */
                  vuint32:2;          /* Reserved */
                vuint32 MASKNUM:8;    /* MCU major mask number; updated for each complete resynthesis. MCU minor mask number; updated for each mask revision */
            } B;
        } MIDR;                 /* MCU ID Register (MIDR) @baseaddress + 0x4 */

        sint32 SIU_Reserved_0008;     /* 0x0008 - 0x000B */

        union {
            vuint32 R;
            struct {
                vuint32 PORS:1;       /*  Power-On Reset Status */
                vuint32 ERS:1;        /*  External Reset Status */
                vuint32 LLRS:1;       /*  Loss of Lock Reset Status */
                vuint32 LCRS:1;       /*  Loss of Clock Reset Status */
                vuint32 WDRS:1;       /*  Watchdog Timer/Debug Reset Status */
                vuint32 :1;
                vuint32 SWTRS:1;      /*  Software Watchdog Timer Reset Status */
                  vuint32:7;
                vuint32 SSRS:1;       /*  Software System Reset Status */
                vuint32 SERF:1;       /*  Software External Reset Flag */
                vuint32 WKPCFG:1;     /*  Weak Pull Configuration Pin Status */
                  vuint32:11;
                vuint32 ABR:1;        /*  Auto Baud Rate */
                vuint32 BOOTCFG:2;    /*  Reset Configuration Pin Status  */
                vuint32 RGF:1;        /*  RESET Glitch Flag */
            } B;
        } RSR;                  /* Reset Status Register (SIU_RSR) @baseaddress + 0xC */

        union {
            vuint32 R;
            struct {
                vuint32 SSR:1;        /*  Software System Reset */
                vuint32 SER:1;        /*  Software External Reset */
                  vuint32:14;
                  vuint32:1;
                  vuint32:15;
            } B;
        } SRCR;                 /* System Reset Control Register (SRCR) @baseaddress + 0x10 */

        union {
            vuint32 R;
            struct {
                vuint32 NMI:1;        /* Non-Maskable Interrupt Flag */
                  vuint32:7;  /*  */
                vuint32 SWT:1;        /* Software Watch Dog Timer Interrupt Flag, from platform */
                  vuint32:7;  /*  */
                vuint32 EIF15:1;      /* External Interrupt Request Flag x */
                vuint32 EIF14:1;      /* External Interrupt Request Flag x */
                vuint32 EIF13:1;      /* External Interrupt Request Flag x */
                vuint32 EIF12:1;      /* External Interrupt Request Flag x */
                vuint32 EIF11:1;      /* External Interrupt Request Flag x */
                vuint32 EIF10:1;      /* External Interrupt Request Flag x */
                vuint32 EIF9:1;       /* External Interrupt Request Flag x */
                vuint32 EIF8:1;       /* External Interrupt Request Flag x */
                vuint32 EIF7:1;       /* External Interrupt Request Flag x */
                vuint32 EIF6:1;       /* External Interrupt Request Flag x */
                vuint32 EIF5:1;       /* External Interrupt Request Flag x */
                vuint32 EIF4:1;       /* External Interrupt Request Flag x */
                vuint32 EIF3:1;       /* External Interrupt Request Flag x */
                vuint32 EIF2:1;       /* External Interrupt Request Flag x */
                vuint32 EIF1:1;       /* External Interrupt Request Flag x */
                vuint32 EIF0:1;       /* External Interrupt Request Flag x */
            } B;
        } EISR;                 /* SIU External Interrupt Status Register (EISR) @baseaddress + 0x14 */

        union {
            vuint32 R;
            struct {
                vuint32 NMI_SEL:1;    /* NMI Interrupt Platform Input Selection */
                  vuint32:7;
                vuint32 NMISEL0:1;    /* SWT Interrupt Platform Input Selection */
                  vuint32:7;
                vuint32 EIRE15:1;     /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE14:1;     /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE13:1;     /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE12:1;     /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE11:1;     /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE10:1;     /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE9:1;      /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE8:1;      /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE7:1;      /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE6:1;      /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE5:1;      /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE4:1;      /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE3:1;      /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE2:1;      /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE1:1;      /* External DMA/Interrupt Request Enable x */
                vuint32 EIRE0:1;      /* External DMA/Interrupt Request Enable x */
            } B;
        } DIRER;                /* DMA/Interrupt Request Enable Register (DIRER) @baseaddress + 0x18 */

        union {
            vuint32 R;
            struct {
                vuint32:28;   /*  */
                vuint32 DIRS3:1;      /* DMA/Interrupt Request Select x */
                vuint32 DIRS2:1;      /* DMA/Interrupt Request Select x */
                vuint32 DIRS1:1;      /* DMA/Interrupt Request Select x */
                vuint32 DIRS0:1;      /* DMA/Interrupt Request Select x */
            } B;
        } DIRSR;                /* DMA/Interrupt Request Select Register (DIRSR) @baseaddress + 0x1C */

        union {
            vuint32 R;
            struct {
                vuint32:16;   /*  */
                vuint32 OVF15:1;      /* Overrun Flag x */
                vuint32 OVF14:1;      /* Overrun Flag x */
                vuint32 OVF13:1;      /* Overrun Flag x */
                vuint32 OVF12:1;      /* Overrun Flag x */
                vuint32 OVF11:1;      /* Overrun Flag x */
                vuint32 OVF10:1;      /* Overrun Flag x */
                vuint32 OVF9:1;       /* Overrun Flag x */
                vuint32 OVF8:1;       /* Overrun Flag x */
                vuint32 OVF7:1;       /* Overrun Flag x */
                vuint32 OVF6:1;       /* Overrun Flag x */
                vuint32 OVF5:1;       /* Overrun Flag x */
                vuint32 OVF4:1;       /* Overrun Flag x */
                vuint32 OVF3:1;       /* Overrun Flag x */
                vuint32 OVF2:1;       /* Overrun Flag x */
                vuint32 OVF1:1;       /* Overrun Flag x */
                vuint32 OVF0:1;       /* Overrun Flag x */
            } B;
        } OSR;                  /* Overrun Status Register (OSR) @baseaddress + 0x20 */

        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 ORE15:1;      /* Overrun Request Enable x */
                vuint32 ORE14:1;      /* Overrun Request Enable x */
                vuint32 ORE13:1;      /* Overrun Request Enable x */
                vuint32 ORE12:1;      /* Overrun Request Enable x */
                vuint32 ORE11:1;      /* Overrun Request Enable x */
                vuint32 ORE10:1;      /* Overrun Request Enable x */
                vuint32 ORE9:1;       /* Overrun Request Enable x */
                vuint32 ORE8:1;       /* Overrun Request Enable x */
                vuint32 ORE7:1;       /* Overrun Request Enable x */
                vuint32 ORE6:1;       /* Overrun Request Enable x */
                vuint32 ORE5:1;       /* Overrun Request Enable x */
                vuint32 ORE4:1;       /* Overrun Request Enable x */
                vuint32 ORE3:1;       /* Overrun Request Enable x */
                vuint32 ORE2:1;       /* Overrun Request Enable x */
                vuint32 ORE1:1;       /* Overrun Request Enable x */
                vuint32 ORE0:1;       /* Overrun Request Enable x */
            } B;
        } ORER;                 /* Overrun Request Enable Register (ORER) @baseaddress + 0x24 */

        union {
            vuint32 R;
            struct {
                vuint32 NMIRE:1;      /* NMI Rising-Edge Event Enable x  */
                 vuint32:7; 
				vuint32 NMIRE0:1;     /* NMI Falling-Edge Event Enable (SWT) x */
                 vuint32:7; 
				vuint32 IREE15:1;     /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE14:1;     /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE13:1;     /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE12:1;     /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE11:1;     /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE10:1;     /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE9:1;      /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE8:1;      /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE7:1;      /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE6:1;      /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE5:1;      /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE4:1;      /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE3:1;      /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE2:1;      /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE1:1;      /* IRQ Rising-Edge Event Enable x */
                vuint32 IREE0:1;      /* IRQ Rising-Edge Event Enable x */
            } B;
        } IREER;                /* External IRQ Rising-Edge Event Enable Register (IREER)  @baseaddress + 0x28 */

        union {
            vuint32 R;
            struct {
                vuint32 NMIFE:1;      /* NMI Falling-Edge Event Enable (NMI Input) x */
                 vuint32:7; 
				vuint32 NMIFE0:1;     /* NMI Falling-Edge Event Enable (SWT) x */
                 vuint32:7; 
				vuint32 IFEE15:1;     /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE14:1;     /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE13:1;     /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE12:1;     /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE11:1;     /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE10:1;     /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE9:1;      /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE8:1;      /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE7:1;      /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE6:1;      /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE5:1;      /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE4:1;      /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE3:1;      /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE2:1;      /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE1:1;      /* IRQ Falling-Edge Event Enable x */
                vuint32 IFEE0:1;      /* IRQ Falling-Edge Event Enable x */
            } B;
        } IFEER;                /* External IRQ Falling-Edge Event Enable Regi (IFEER) @baseaddress + 0x2C */

        union {
            vuint32 R;
            struct {
                vuint32:28;
                vuint32 DFL:4;        /* Digital Filter Length */
            } B;
        } IDFR;                 /* External IRQ Digital Filter Register (IDFR) @baseaddress + 0x30 */

         union {
            vuint32 R;
            struct {
                vuint32 FI31:1;
				  vuint32:7;
				vuint32 FI23:1;
				  vuint32:7;
                vuint32 FI15:1; 
				vuint32 FI14:1; 
				vuint32 FI13:1; 
				vuint32 FI12:1; 
				vuint32 FI11:1; 
				vuint32 FI10:1; 
				vuint32 FI9:1; 
				vuint32 FI8:1; 
				vuint32 FI7:1; 
				vuint32:1;
				vuint32 FI5:1; 
				vuint32 FI4:1; 
				vuint32 FI3:1; 
				vuint32 FI2:1; 
				vuint32 FI1:1; 
				vuint32 FI0:1; 
            } B;
        } IFIR;                 /* IRQ Filtered Input Register (IFIR) @baseaddress + 0x34 */
		
		vuint32 SIU_Reserved_0038[2];      /* 0x0038 - 0x003F */

        union {
            vuint16 R;
            struct {
                vuint16:2;
                vuint16 PA:4;
                vuint16 OBE:1;
                vuint16 IBE:1;
                vuint16 DSC:2;
                vuint16 ODE:1;
                vuint16 HYS:1;
                vuint16 SRC:2;
                vuint16 WPE:1;
                vuint16 WPS:1;
            } B;
        } PCR[512];             /* Pad Configuration Register  (PCR) @baseaddress + 0x40 */

        sint32 SIU_Reserved_0374[112];    /* 0x0374 - 0x05FF */

        union {
            vuint8 R;
            struct {
                vuint8:7;
                vuint8 PDO:1;
            } B;
        } GPDO[512];            /* GPIO Pin Data Output Register (GPDO) @baseaddress + 0x600 */

        union {
            vuint8 R;
            struct {
                vuint8:7;
                vuint8 PDI:1;
            } B;
        } GPDI[256];            /* GPIO Pin Data Input Register (GDPI) @baseaddress + 0x800 */

        union {
            vuint32 R;
            struct {
                vuint32 TSEL5:2;      /* eQADC Trigger 5 Input */
                vuint32 TSEL4:2;      /* eQADC Trigger 4 Input */
                vuint32 TSEL3:2;      /* eQADC Trigger 3 Input */
                vuint32 TSEL2:2;      /* eQADC Trigger 4 Input */
                vuint32 TSEL1:2;      /* eQADC Trigger 1 Input */
                vuint32 TSEL0:2;      /* eQADC Trigger 0 Input */
                  vuint32:20; /*  */
            } B;
        } ETISR;                /* eQADC Trigger Input Select Register (ETISR) @baseaddress + 0x900 */

        union {
            vuint32 R;
            struct {
                vuint32 ESEL15:2;     /* External IRQ Input Select x */
                vuint32 ESEL14:2;     /* External IRQ Input Select x */
                vuint32 ESEL13:2;     /* External IRQ Input Select x */
                vuint32 ESEL12:2;     /* External IRQ Input Select x */
                vuint32 ESEL11:2;     /* External IRQ Input Select x */
                vuint32 ESEL10:2;     /* External IRQ Input Select x */
                vuint32 ESEL9:2;      /* External IRQ Input Select x */
                vuint32 ESEL8:2;      /* External IRQ Input Select x */
                vuint32 ESEL7:2;      /* External IRQ Input Select x */
                vuint32 ESEL6:2;      /* External IRQ Input Select x */
                vuint32 ESEL5:2;      /* External IRQ Input Select x */
                vuint32 ESEL4:2;      /* External IRQ Input Select x */
                vuint32 ESEL3:2;      /* External IRQ Input Select x */
                vuint32 ESEL2:2;      /* External IRQ Input Select x */
                vuint32 ESEL1:2;      /* External IRQ Input Select x */
                vuint32 ESEL0:2;      /* External IRQ Input Select x */
            } B;
        } EIISR;                /* External IRQ Input Select Register (EIISR) @baseaddress + 0x904 */

        union {
            vuint32 R;
            struct {
                vuint32:8;
                vuint32 SINSELB:2;    /* DSPI_B Data Input Select  */
                vuint32 SSSELB:2;     /* DSPI_B Slave Select Input Select */
                vuint32 SCKSELB:2;    /* DSPI_B Clock Input Select */
                vuint32 TRIGSELB:2;   /* DSPI_B Trigger Input Select */
                vuint32 SINSELC:2;    /* DSPI_C Data Input Select */
                vuint32 SSSELC:2;     /* DSPI_C Slave Select Input Select */
                vuint32 SCKSELC:2;    /* DSPI_C Clock Input Select */
                vuint32 TRIGSELC:2;   /* DSPI_C Trigger Input Select  */
                vuint32 SINSELD:2;    /* DSPI_D Data Input Select */
                vuint32 SSSELD:2;     /* DSPI_D Slave Select Input Select */
                vuint32 SCKSELD:2;    /* DSPI_D Clock Input Select */
                vuint32 TRIGSELD:2;   /* DSPI_D Trigger Input Select  */
            } B;
        } DISR;                 /* DSPI Input Select Register (DISR) @baseaddress + 0x908 */

        union {
            vuint32 R;
            struct {
                vuint32:2;    /*  */
                vuint32 ETSEL5:5;     /* eQADC queue X Enhanced Trigger Selection */
                vuint32 ETSEL4:5;     /* eQADC queue X Enhanced Trigger Selection */
                vuint32 ETSEL3:5;     /* eQADC queue X Enhanced Trigger Selection */
                vuint32 ETSEL2:5;     /* eQADC queue X Enhanced Trigger Selection */
                vuint32 ETSEL1:5;     /* eQADC queue X Enhanced Trigger Selection */
                vuint32 ETSEL0:5;     /* eQADC queue X Enhanced Trigger Selection */
            } B;
        } ISEL3;                /* MUX Select Register 3 (ISEL3) @baseaddress + 0x90C */

        sint32 SIU_Reserved_0910[4];      /* 0x0910 - 0x091F */

        union {
            vuint32 R;
            struct {
                vuint32:11;
                vuint32 ESEL5:1;
                  vuint32:3;
                vuint32 ESEL4:1;
                  vuint32:3;
                vuint32 ESEL3:1;
                  vuint32:3;
                vuint32 ESEL2:1;
                  vuint32:3;
                vuint32 ESEL1:1;
                  vuint32:3;
                vuint32 ESEL0:1;
            } B;
        } ISEL8;                /* MUX Select Register 8 (ISEL8) @baseaddress + 0x920 */

        union {
            vuint32 R;
            struct {
                vuint32:27;
                vuint32 ETSEL0A:5;
            } B;
        } ISEL9;                /* MUX Select Register 9(ISEL9) @baseaddress + 0x924 */

		union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 HSELB:4;
				vuint32 ZSELB:4;
				vuint32 HSELA:4;
				vuint32 ZSELA:4;
            } B;
        } ISEL10;                /* MUX Select Register 10(ISEL10) @baseaddress + 0x928 */
		
        sint32 SIU_Reserved_0928[21];     /* 0x092C - 0x097F */

        union {
            vuint32 R;
            struct {
                vuint32:14;
                vuint32 MATCH:1;      /*  Compare Register Match */
                vuint32 DISNEX:1;     /*  Disable Nexus */
                  vuint32:14;
                vuint32 CRSE:1;       /*  Calibration Reflection Suppression Enable */
                  vuint32:1;
            } B;
        } CCR;                  /* Chip Configuration Register (CCR) @baseaddress + 0x980 */

        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 ENGDIV:8;
                vuint32 ENGSSE:1;
                  vuint32:3;
                vuint32 EBTS:1;
                  vuint32:1;
                vuint32 EBDF:2;
            } B;
        } ECCR;                 /* External Clock Control Register (ECCR) @baseaddress + 0x984 */

        union {
            vuint32 R;
            struct {
                vuint32 CMPAH:32;
            } B;
        } CARH;                 /* Compare A High Register (CARH) @baseaddress + 0x988 */

        union {
            vuint32 R;
            struct {
                vuint32 CMPAL:32;
            } B;
        } CARL;                 /* Compare A Low Register (CARL) @baseaddress + 0x98C */

        union {
            vuint32 R;
            struct {
                vuint32 CMPBH:32;
            } B;
        } CBRH;                 /* Compare B High Register (CBRH) @baseaddress + 0x990 */

        union {
            vuint32 R;
            struct {
                vuint32 CMPBL:32;
            } B;
        } CBRL;                 /* Compare B Low Register (CBRL) @baseaddress + 0x994 */

        sint32 SIU_Reserved_0998[2];      /* 0x0998 - 0x099F */

        union {
            vuint32 R;
            struct {
                vuint32:15;
                vuint32 CAN_SRC:1;    /* CAN 2:1 Mode */
                vuint32:11;
                vuint32 BYPASS:1;     /* Bypass bit  */
                vuint32 SYSCLKDIV:2;  /* System Clock Divide */
                  vuint32:2;
            } B;
        } SYSDIV;               /* System Clock Register (SYSDIV) @baseaddress + 0x9A0 */

        union {
            vuint32 R;
            struct {
                vuint32 CPUSTP:1;     /* CPU stop request. When asserted, a stop request is sent to the following modules: */
                  vuint32:2;  /* Reserved */
                  vuint32:1;
                  vuint32:1;  /* Reserved */
                vuint32 TPUSTP:1;     /* eTPU stop request. When asserted, a stop request is sent to the eTPU module. */
                vuint32 NPCSTP:1;     /* Nexus stop request. When asserted, a stop request is sent to the Nexus Controller. */
                vuint32 EBISTP:1;     /* EBI stop request. When asserted, a stop request is sent to the external bus */
                vuint32 ADCSTP:1;     /* eQADC stop request. When asserted, a stop request is sent to the eQADC module. */
                vuint32 REACMSTP:1;   /* REACM stop request. When asserted, a stop request is sent to the REACM module. */
                vuint32 MIOSSTP:1;    /* Stop mode request */
                vuint32 DFILSTP:1;    /* Decimation filter stop request. When asserted, a stop request is sent to the */
                  vuint32:1;  /* Reserved */
                vuint32 PITSTP:1;     /* PIT stop request. When asserted, a stop request is sent to the periodical internal */
                  vuint32:3;  /* Reserved */
                vuint32 CNCSTP:1;     /* FlexCAN C stop request. When asserted, a stop request is sent to the FlexCAN C */
                vuint32 CNBSTP:1;     /* FlexCAN B stop request. When asserted, a stop request is sent to the FlexCAN B */
                vuint32 CNASTP:1;     /* FlexCAN A stop request. When asserted, a stop request is sent to the FlexCAN A */
                vuint32 SPIDSTP:1;    /* DSPI D stop request. When asserted, a stop request is sent to the DSPI D. */
                vuint32 SPICSTP:1;    /* DSPI C stop request. When asserted, a stop request is sent to the DSPI C. */
                vuint32 SPIBSTP:1;    /* DSPI B stop request. When asserted, a stop request is sent to the DSPI B. */
                  vuint32:6;  /* Reserved */
                vuint32 SCICSTP:1;    /* eSCI C stop request. When asserted, a stop request is sent to the eSCI C module. */
                vuint32 SCIBSTP:1;    /* eSCI B stop request. When asserted, a stop request is sent to the eSCI B module. */
                vuint32 SCIASTP:1;    /* eSCI A stop request. When asserted, a stop request is sent to the eSCIA module. */
            } B;
        } HLT;                  /* Halt Register (HLT) @baseaddress + 0x9A4 */

        union {
            vuint32 R;
            struct {
                vuint32 CPUACK:1;     /* CPU stop acknowledge. When asserted, indicates that a stop acknowledge was */
                  vuint32:3;  /* Reserved */
                vuint32 NSETIACK:1;   /* eTPU Nexus module stop acknowledge. When asserted, indicates that a stop acknowledge was */
                vuint32 TPUACK:1;     /* eTPU stop acknowledge. When asserted, indicates that a stop acknowledge was */
                vuint32 NPCACK:1;     /* Nexus stop acknowledge. When asserted, indicates that a stop acknowledge was */
                vuint32 EBIACK:1;     /* EBI stop acknowledge. When asserted, indicates that a stop acknowledge was */
                vuint32 ADCACK:1;     /* eQADC stop acknowledge. When asserted, indicates that a stop acknowledge was */
                vuint32 REACMACK:1;   /* Reaction module stop acknowledge. When asserted, indicates that a stop acknowledge was*/
                vuint32 MIOSACK:1;    /* eMIOS stop acknowledge. When asserted, indicates that a stop acknowledge was */
                vuint32 DFILACK:1;    /* Decimation filter stop acknowledge. When asserted, indicates that a stop */
                  vuint32:1;  /* Reserved */
                vuint32 PITACK:1;     /* PIT stop acknowledge. When asserted, indicates that a stop acknowledge was */
                  vuint32:3;  /* Reserved */
                vuint32 CNCACK:1;     /* FlexCAN C stop acknowledge. When asserted, indicates that a stop acknowledge */
                vuint32 CNBACK:1;     /* FlexCAN B stop acknowledge. When asserted, indicates that a stop acknowledge */
                vuint32 CNAACK:1;     /* FlexCAN A stop acknowledge. When asserted, indicates that a stop acknowledge */
                vuint32 SPIDACK:1;    /* DSPI D stop acknowledge. When asserted, indicates that a stop acknowledge was */
                vuint32 SPICACK:1;    /* DSPI C stop acknowledge. When asserted, indicates that a stop acknowledge was */
                vuint32 SPIBACK:1;    /* DSPI B stop acknowledge. When asserted, indicates that a stop acknowledge was */
                  vuint32:6;  /* Reserved */
                vuint32 SCICACK:1;    /* eSCI C stop acknowledge */
                vuint32 SCIBACK:1;    /* eSCI B stop acknowledge */
                vuint32 SCIAACK:1;    /* eSCI A stop acknowledge. */
            } B;
        } HLTACK;               /* Halt Acknowledge Register (HLTACK) @baseaddress + 0x9A8 */

        sint32 SIU_reserved09AC[2];       /* 0x09AC - 0x09B0 */
		
		 union {
            vuint32 R;
            struct {
				vuint32 EXT_PID_EN:1;     /* External PID Selection Enable */
                vuint32 EXT_PID_SYNC0:1;  /* External PID Synchronization 0 */
                 vuint32:28;              /* Reserved */
				vuint32 EXT_PID6:1;       /* EXT_PID6 */
                vuint32 EXT_PID7:1;       /* EXT_PID7 */
			} B;
		} EMPCR0;				/* Core MMU PID Control Register (EMPCR0) @baseaddress + 0x9B4 */
		
		sint32 SIU_reserved09B8[19];       /* 0x09B8 - 0x09B0 */

    };


/****************************************************************************/
/*                     MODULE : FMPLL                                       */
/****************************************************************************/
    struct FMPLLag {
        union {
            vuint32 R;
            struct {
                vuint32:1;
                vuint32 PREDIV:3;
                vuint32 MFD:5;
                  vuint32:1;
                vuint32 RFD:3;
                vuint32 LOCEN:1;
                vuint32 LOLRE:1;
                vuint32 LOCRE:1;
                  vuint32:1;
                vuint32 LOLIRQ:1;
                vuint32 LOCIRQ:1;
                  vuint32:13;
            } B;
        } SYNCR;                /* Synthesizer Control Register (SYNCR) @baseaddress + 0x0000 */

        union {
            vuint32 R;
            struct {
                vuint32:22;
                vuint32 LOLF:1;
                vuint32 LOC:1;
                vuint32 MODE:1;
                vuint32 PLLSEL:1;
                vuint32 PLLREF:1;
                vuint32 LOCKS:1;
                vuint32 LOCK:1;
                vuint32 LOCF:1;
                  vuint32:2;
            } B;
        } SYNSR;                /* Synthesizer Status Register (SYNSR) @baseaddress + 0x0004 */

        union {
            vuint32 R;
            struct {
                vuint32 EMODE:1;
                vuint32 CLKCFG:3;
                  vuint32:8;
                vuint32 EPREDIV:4;
                  vuint32:9;
                vuint32 EMFD:7;
            } B;
        } ESYNCR1;              /* Enhanced Synthesizer Control Register 1 (ESYNCR1) @baseaddress + 0x0008 */

        union {
            vuint32 R;
            struct {
                vuint32:8;
                vuint32 LOCEN:1;
                vuint32 LOLRE:1;
                vuint32 LOCRE:1;
                vuint32 LOLIRQ:1;
                vuint32 LOCIRQ:1;
                  vuint32:17;
                vuint32 ERFD:2;
            } B;
        } ESYNCR2;              /* Enhanced Synthesizer Control Register 2 (ESYNCR2) @baseaddress + 0x000C */

        sint32 FMPLL_reserved0010[2];      /* 0x0010-0x0017 */

        union {
            vuint32 R;
            struct {
                vuint32 BSY:1;
                vuint32 MODEN:1;
                vuint32 MODSEL:1;
                vuint32 MODPERIOD:13;
                  vuint32:1;
                vuint32 INCSTEP:15;
            } B;
        } SYNFMMR;              /* Synthesizer FM Modulation Register (SYNFMMR) @baseaddress + 0x0018 */
    };


/****************************************************************************/
/*                     MODULE : ECSM                                       */
/****************************************************************************/
    struct ECSMag {

        union {                /* Processor core type */
            vuint16 R;
        } PCT;
        
        union {                /* Platform revision */
            vuint16 R;
        } REV;
        
        union {                /* AXBS Master Configuration */
            vuint16 R;
        } AMC;
        
        union {                /* AXBS Slave Configuration */
            vuint16 R;
        } ASC;
        
        union {                 /* IPS Module Configuration */
            vuint32 R;
        } IMC;
        
        uint8 ECSM_reserved000C[3];  /* 0x000C-0x000E */
        
        union {                 /* Miscellaneous Reset Status Register */
            vuint8 R;
            struct {
                vuint8 POR:1;
                vuint8 DIR:1;
                 vuint8:6;
            } B;
        } MRSR;

        uint8 ECSM_reserved0010[3];   /* 0x0010-0x0012 */
        
        union {                         /* Miscellaneous Wakeup Control */
            vuint8 R;
            struct {
                vuint8 ENBWCR:1;
                 vuint8:3;
                vuint8 PRILVL:4;
            } B;
        } MWCR;
                
        uint32 ecsm_reserved0014[4];  /* 0x0014 - 0x0023 */
        
        union {                         /* Miscellaneous User Defined Control */
            vuint32 R;
            struct {
                 vuint32:1;
                vuint32 SWSC:1;
                 vuint32:30;
            } B;
        } MUDCR;

        uint32 ecsm_reserved0028[6];      /* 0x0028 - 0x003C*/
        
        uint8 ecsm_reserved0040[3];       /* 0x0040 - 0x0042*/

        union {
            vuint8 R;
            struct {
                 vuint8:2;
				vuint8 ER1BR:1;
                vuint8 EF1BR:1;
                 vuint8:2;
                vuint8 ERNCR:1;
                vuint8 EFNCR:1;
            } B;
        } ECR;                  /* ECC Configuration Register @baseaddress + 0x43 */

        uint8 ecsm_reserved0044[3];      /* 0x0044 - 0x0046*/

        union {
            vuint8 R;
            struct {
                 vuint8:2;
				vuint8 R1BC:1;
                vuint8 F1BC:1;
                 vuint8:2;
				vuint8 RNCE:1;
                vuint8 FNCE:1;
            } B;
        } ESR;                  /* ECC Status Register @baseaddress + 0x47 */

        uint8 ecsm_reserved0048[2];      /* 0x0048 - 0x0049*/
        
        union {
            vuint16 R;
            struct {
                vuint16 FRCAP:1;
                vuint16:1;
                vuint16 FRC1BI:1;
                vuint16 FR11BI:1;
                vuint16:2;
                vuint16 FRCNCI:1;
                vuint16 FR1NCI:1;
                vuint16:1;
                vuint16 ERRBIT:7;
            } B;
        } EEGR;                 /* ECC Error Generation Register @baseaddress + 0x4A */
        
        uint32 ecsm_reserved004C;      /* 0x004C - 0x004F*/
                
        union {
            vuint32 R;
            struct {
                vuint32 FEAR:32;
            } B;
        } FEAR;                 /* Flash ECC Address Register @baseaddress + 0x50 */

        uint16 ecsm_reserved0054;          /* 0x0054 - 0x0055*/

        union {
            vuint8 R;
            struct {
                vuint8:4;
                vuint8 FEMR:4;
            } B;
        } FEMR;                 /* Flash ECC Master Register @baseaddress + 0x56 */

        union {
            vuint8 R;
            struct {
                vuint8 WRITE:1;
                vuint8 SIZE:3;
                vuint8 PROT0:1;
                vuint8 PROT1:1;
                vuint8 PROT2:1;
                vuint8 PROT3:1;
            } B;
        } FEAT;                 /* Flash ECC Attributes Register @baseaddress + 0x57 */

        union {
            vuint32 R;
            struct {
                vuint32 FEDH:32;
            } B;
        } FEDRH;                /* Flash ECC Data High Register @baseaddress + 0x58 */

        union {
            vuint32 R;
            struct {
                vuint32 FEDL:32;
            } B;
        } FEDRL;                /* Flash ECC Data Low Register @baseaddress + 0x5C */

        union {
            vuint32 R;
            struct {
                vuint32 REAR:32;
            } B;
        } REAR;                 /* RAM ECC Address @baseaddress + 0x60 */

        uint8 ecsm_reserved0064;          /* 0x0064 - 0x0065*/

        union {
            vuint8 R;
            struct {
                vuint8 PRESR:8;
            } B;
        } PRESR;                /* RAM ECC Syndrome @baseaddress + 0x65 */

        union {
            vuint8 R;
            struct {
                vuint8:4;
                vuint8 REMR:4;
            } B;
        } REMR;                 /* RAM ECC Master @baseaddress + 0x66  */

        union {
            vuint8 R;
            struct {
                vuint8 WRITE:1;
                vuint8 SIZE:3;
                vuint8 PROT0:1;
                vuint8 PROT1:1;
                vuint8 PROT2:1;
                vuint8 PROT3:1;
            } B;
        } REAT;                 /*  RAM ECC Attributes Register @baseaddress + 0x67 */

        union {
            vuint32 R;
            struct {
                vuint32 REDH:32;
            } B;
        } REDRH;                /* RAM ECC Data High Register @baseaddress + 0x68 */

        union {
            vuint32 R;
            struct {
                vuint32 REDL:32;
            } B;
        } REDRL;                /* RAMECC Data Low Register @baseaddress + 0x6C */

    };

/****************************************************************************/
/*                     MODULE : System Timer Module (STM)                   */
/****************************************************************************/
    struct STMag {
        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 CPS:8;
                  vuint32:6;
                vuint32 FRZ:1;
                vuint32 TEN:1;
            } B;
        } CR;                   /* STM Control Register @baseaddress + 0x0000 */

        union {
            vuint32 R;
        } CNT;                  /* STM Count Register @baseaddress + 0x0004 */

        uint32 stm_reserved0008[2];      /* 0x0008 - 0x000F */

        union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 CEN:1;
            } B;
        } CCR0;                 /* STM Channel Control Register @baseaddress + 0x0010 */

        union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 CIF:1;
            } B;
        } CIR0;                 /* STM Channel Interrupt Register @baseaddress + 0x0014 */

        union {
            vuint32 R;
            struct {
                vuint32 CMP;
            } B;
        } CMP0;                 /* STM Channel Compare Register @baseaddress + 0x0018 */

        uint32 stm_reserved001C; /* 0x001C - 0x001F*/

        union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 CEN:1;
            } B;
        } CCR1;                 /* STM Channel Control Register @baseaddress + 0x0020 */

        union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 CIF:1;
            } B;
        } CIR1;                 /* STM Channel Interrupt Register @baseaddress + 0x0024 */

        union {
            vuint32 R;
            struct {
                vuint32 CMP;
            } B;
        } CMP1;                 /* STM Channel Compare Register @baseaddress + 0x0028 */

        uint32 stm_reserved002C; /* 0x002C - 0x002F */

        union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 CEN:1;
            } B;
        } CCR2;                 /* STM Channel Control Register @baseaddress + 0x0030 */

        union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 CIF:1;
            } B;
        } CIR2;                 /* STM Channel Interrupt Register @baseaddress + 0x0034 */

        union {
            vuint32 R;
            struct {
                vuint32 CMP;
            } B;
        } CMP2;                 /* STM Channel Compare Register @baseaddress + 0x0038 */

        uint32 stm_reserved003C; /* 0x003C - 0x003F */

        union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 CEN:1;
            } B;
        } CCR3;                 /* STM Channel Control Register @baseaddress + 0x0040 */

        union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 CIF:1;
            } B;
        } CIR3;                 /* STM Channel Interrupt Register @baseaddress + 0x0044 */

        union {
            vuint32 R;
            struct {
                vuint32 CMP;
            } B;
        } CMP3;                 /* STM Channel Compare Register @baseaddress + 0x0048 */

        uint32 stm_reserved004C; /* 0x004C - 0x004F */
    };


/****************************************************************************/
/*                     MODULE : SWT                                         */
/****************************************************************************/

    struct SWTag {
        union {
            vuint32 R;
            struct {
                vuint32 MAP0:1;
                vuint32 MAP1:1;
                vuint32 MAP2:1;
                vuint32 MAP3:1;
                vuint32 MAP4:1;
                vuint32 MAP5:1;
                vuint32 MAP6:1;
                vuint32 MAP7:1;
                  vuint32:14;
                vuint32 KEY:1;
                vuint32 RIA:1;
                vuint32 WND:1;
                vuint32 ITR:1;
                vuint32 HLK:1;
                vuint32 SLK:1;
                vuint32 CSL:1;
                vuint32 STP:1;
                vuint32 FRZ:1;
                vuint32 WEN:1;
            } B;
        } MCR;                  /* Module Configuration Register @baseaddress + 0x00 */

        union {
            vuint32 R;
            struct {
                vuint32:31;
                vuint32 TIF:1;
            } B;
        } IR;                   /* Interrupt register @baseaddress + 0x04 */

        union {
            vuint32 R;
            struct {
                vuint32 WTO:32;
            } B;
        } TO;                   /* Timeout register @baseaddress + 0x08 */

        union {
            vuint32 R;
            struct {
                vuint32 WST:32;

            } B;
        } WN;                   /* Window register @baseaddress + 0x0C */

        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 WSC:16;
            } B;
        } SR;                   /* Service register @baseaddress + 0x10 */

        union {
            vuint32 R;
            struct {
                vuint32 CNT:32;
            } B;
        } CO;                   /* Counter output register @baseaddress + 0x14 */

        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 SK:16;
            } B;
        } SK;                   /* Service key register @baseaddress + 0x18 */
    };

/****************************************************************************/
/*                     MODULE : EMIOS                                      */
/****************************************************************************/
    struct EMIOSag {
        union {
            vuint32 R;
            struct {
                  vuint32:1;
                vuint32 MDIS:1;
                vuint32 FRZ:1;
                vuint32 GTBE:1;
                vuint32 ETB:1;
                vuint32 GPREN:1;
                  vuint32:6;
                vuint32 SRV:4;
                vuint32 GPRE:8;
                  vuint32:8;
            } B;
        } MCR;                  /* Module Configuration Register @baseaddress + 0x00 */

        union {
            vuint32 R;
            struct {
                  vuint32:8;
                vuint32 F23:1;
                vuint32 F22:1;
                vuint32 F21:1;
                vuint32 F20:1;
                vuint32 F19:1;
                vuint32 F18:1;
                vuint32 F17:1;
                vuint32 F16:1;
                vuint32 F15:1;
                vuint32 F14:1;
                vuint32 F13:1;
                vuint32 F12:1;
                vuint32 F11:1;
                vuint32 F10:1;
                vuint32 F9:1;
                vuint32 F8:1;
                vuint32 F7:1;
                vuint32 F6:1;
                vuint32 F5:1;
                vuint32 F4:1;
                vuint32 F3:1;
                vuint32 F2:1;
                vuint32 F1:1;
                vuint32 F0:1;
            } B;
        } GFR;                  /* Global FLAG Register @baseaddress + 0x04 */

        union {
            vuint32 R;
            struct {
                vuint32:8;
                vuint32 OU23:1;
                vuint32 OU22:1;
                vuint32 OU21:1;
                vuint32 OU20:1;
                vuint32 OU19:1;
                vuint32 OU18:1;
                vuint32 OU17:1;
                vuint32 OU16:1;
                vuint32 OU15:1;
                vuint32 OU14:1;
                vuint32 OU13:1;
                vuint32 OU12:1;
                vuint32 OU11:1;
                vuint32 OU10:1;
                vuint32 OU9:1;
                vuint32 OU8:1;
                vuint32 OU7:1;
                vuint32 OU6:1;
                vuint32 OU5:1;
                vuint32 OU4:1;
                vuint32 OU3:1;
                vuint32 OU2:1;
                vuint32 OU1:1;
                vuint32 OU0:1;
            } B;
        } OUDR;                 /* Output Update Disable Register @baseaddress + 0x08 */

        union {
            vuint32 R;
            struct {
                vuint32:8;    /*  */
                vuint32 CHDIS23:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS22:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS21:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS20:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS19:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS18:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS17:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS16:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS15:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS14:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS13:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS12:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS11:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS10:1;    /* Enable Channel [n] bit */
                vuint32 CHDIS9:1;     /* Enable Channel [n] bit */
                vuint32 CHDIS8:1;     /* Enable Channel [n] bit */
                vuint32 CHDIS7:1;     /* Enable Channel [n] bit */
                vuint32 CHDIS6:1;     /* Enable Channel [n] bit */
                vuint32 CHDIS5:1;     /* Enable Channel [n] bit */
                vuint32 CHDIS4:1;     /* Enable Channel [n] bit */
                vuint32 CHDIS3:1;     /* Enable Channel [n] bit */
                vuint32 CHDIS2:1;     /* Enable Channel [n] bit */
                vuint32 CHDIS1:1;     /* Enable Channel [n] bit */
                vuint32 CHDIS0:1;     /* Enable Channel [n] bit */
            } B;
        } UCDIS;                /* Disable Channel (EMIOSUCDIS) @baseaddress + 0x0C */

        sint32 EMIOS_Reserved_0010[4];    /* 0x0010 - 0x001F */

        struct {
            union {
                vuint32 R;
                struct {
                    vuint32 A;
                }B;
            } CADR;             /* Channel A Data Register */

            union {
                vuint32 R;
                struct {
                    vuint32 B;
                }B;
            } CBDR;             /* Channel B Data Register */

            union {
                vuint32 R;
                struct {
                    vuint32 C;
                }B;
            } CCNTR;            /* Channel Counter Register */

            union {
                vuint32 R;
                struct {
                    vuint32 FREN:1;
                    vuint32 ODIS:1;
                    vuint32 ODISSL:2;
                    vuint32 UCPRE:2;
                    vuint32 UCPREN:1;
                    vuint32 DMA:1;
                    vuint32:1;
                    vuint32 IF:4;
                    vuint32 FCK:1;
                    vuint32 FEN:1;
                    vuint32:3;
                    vuint32 FORCMA:1;
                    vuint32 FORCMB:1;
                    vuint32:1;
                    vuint32 BSL:2;
                    vuint32 EDSEL:1;
                    vuint32 EDPOL:1;
                    vuint32 MODE:7;
                } B;
            } CCR;              /* Channel Control Register */

            union {
                vuint32 R;
                struct {
                    vuint32 OVR:1;
                      vuint32:15;
                    vuint32 OVFL:1;
                      vuint32:12;
                    vuint32 UCIN:1;
                    vuint32 UCOUT:1;
                    vuint32 FLAG:1;
                } B;
            } CSR;              /* Channel Status Register */

            union {
                vuint32 R;
                struct {
                    vuint32 ALTA;
                } B;
            } ALTA;             /* Alternate Channel A Data Register */

            uint32 emios_channel_reserved[2];

        } CH[24];

    };

/****************************************************************************/
/*                     MODULE : ETPU                                      */
/****************************************************************************/
    struct ETPUag {
        union {
            vuint32 R;
            struct {
                vuint32 GEC:1;        /*  Global Exception Clear  */
                vuint32 SDMERR:1;     /*  */
                vuint32 WDTOA:1;      /*  */
                vuint32 WDTOB:1;      /*  */
                vuint32 MGE1:1;       /* */
                vuint32 MGE2:1;       /* */
                vuint32 ILF1:1;       /* Invalid instruction flag eTPU A.  */
                vuint32 ILF2:1;       /* Invalid instruction flag eTPU B.  */
                vuint32 SCMERR:1;     /* . */
                  vuint32:2;  /*  */
                vuint32 SCMSIZE:5;    /*  Shared Code Memory size  */
                  vuint32:4;  /*  */
                vuint32 SCMMISC:1;    /*  SCM MISC Flag  */
                vuint32 SCMMISF:1;    /*  SCM MISC Flag  */
                vuint32 SCMMISEN:1;   /*  SCM MISC Enable  */
                  vuint32:2;  /*  */
                vuint32 VIS:1;        /*  SCM Visability  */
                  vuint32:5;  /*  */
                vuint32 GTBE:1;       /*  Global Time Base Enable  */
            } B;
        } MCR;                  /* eTPU module configuration register@baseaddress + 0x00 */


        union {
            vuint32 R;
            struct {
                vuint32 STS:1;        /*  Start Status bit  */
                vuint32 CTBASE:5;     /*  Channel Transfer Base  */
                vuint32 PBBASE:10;    /*  Parameter Buffer Base Address */
                vuint32 PWIDTH:1;     /*  Parameter Width  */
                vuint32 PARAM0:7;     /*  Channel Parameter 0  */
                vuint32 WR:1; /*  */
                vuint32 PARAM1:7;     /*  Channel Parameter 1  */
            } B;
        } CDCR;                 /* eTPU coherent dual-parameter controller register@baseaddress + 0x04 */

        vuint32 ETPU_reserved_0008;   /* 0x0008 - 0x000B */


        union {
            vuint32 R;
            struct {
                vuint32 ETPUMISCCMP:32;       /* Expected multiple input signature calculator compare register value.  */
            } B;
        } MISCCMPR;             /* eTPU MISC Compare Register@baseaddress + 0x0c */


        union {
            vuint32 R;
            struct {
                vuint32 ETPUSCMOFFDATA:32;    /* SCM Off-range read data value. */
            } B;
        } SCMOFFDATAR;          /* eTPU SCM Off-Range Data Register@baseaddress + 0x10 */


        union {
            vuint32 R;
            struct {
                vuint32 FEND:1;       /*  Force END  */
                vuint32 MDIS:1;       /*  Low power Stop  */
                  vuint32:1;  /*  */
                vuint32 STF:1;        /*  Stop Flag  */
                  vuint32:4;  /*  */
                vuint32 HLTF:1;       /*  Halt Mode Flag  */
                  vuint32:3;  /*  */
                vuint32 FCSS:1;
                vuint32 FPSCK:3;      /*  Filter Prescaler Clock Control  */
                vuint32 CDFC:2;       /*  */
                  vuint32:1;  /*  */
                vuint32 ERBA:5;       /*  */
                vuint32 SPPDIS:1;     /*  */
                  vuint32:2;  /*  */
                vuint32 ETB:5;        /*  Entry Table Base  */
            } B;
        } ECR_A;               /* eTPU Engine Configuration Register (ETPUA_ECR)@baseaddress + 0x14 */

        vuint32 ETPU_reserved_0018[2];        /* 0x0018 - 0x001B */

        union {
            vuint32 R;
            struct {
                vuint32 TCR2CTL:3;    /*  TCR2 Clock/Gate Control  */
                vuint32 TCRCF:2;      /*  TCRCLK Signal Filter Control  */
                vuint32 AM:2; /*  Angle Mode  */
                  vuint32:3;  /*  */
                vuint32 TCR2P:6;      /*  TCR2 Prescaler Control  */
                vuint32 TCR1CTL:2;    /*  TCR1 Clock/Gate Control  */
                vuint32 TCR1CS:1;     /*  */
                  vuint32:5;  /*  */
                vuint32 TCR1P:8;      /*  TCR1 Prescaler Control  */
            } B;
        } TBCR_A;                       /* eTPU Time Base Configuration Register (ETPUBCR)@baseaddress + 0x20 */

        /* offset 0x0024 */
        union {
            vuint32 R;
            struct {
                vuint32:8;    /*  */
                vuint32 TCR1:24;      /* TCR1 value. Used on matches and captures. For more information, see the eTPU reference manual. */
            } B;
        } TB1R_A;                /* eTPU Time Base 1 (TCR1) Visibility Register (ETPUB1R)@baseaddress + 0x24 */

        /* offset 0x0028 */
        union {
            vuint32 R;
            struct {
                vuint32:8;    /*  */
                vuint32 TCR2:24;      /* TCR2 value. Used on matches and captures. For information on TCR2, see the eTPU reference manual. */
            } B;
        } TB2R_A;               /* eTPU Time Base 2 (TCR2) Visibility Register (ETPUB2R)@baseaddress + 0x28 */


        union {
            vuint32 R;
            struct {
                vuint32 REN1:1;       /*  Resource Enable TCR1  */
                vuint32 RSC1:1;       /*  Resource Control TCR1  */
                  vuint32:2;  /*  */
                vuint32 SERVER_ID1:4; /*  */
                  vuint32:4;  /*  */
                vuint32 SRV1:4;       /*  Resource Server Slot  */
                vuint32 REN2:1;       /*  Resource Enable TCR2  */
                vuint32 RSC2:1;       /*  Resource Control TCR2  */
                  vuint32:2;  /*  */
                vuint32 SERVER_ID2:4; /*  */
                  vuint32:4;  /*  */
                vuint32 SRV2:4;       /*  Resource Server Slot  */
            } B;
        } REDCR_A;                 /* STAC Bus Configuration Register (ETPU_STACCR)@baseaddress + 0x2c */

        vuint32 ETPU_reserved_0030[12];       /* 0x0030 - 0x005F */


        union {
            vuint32 R;
            struct {
                vuint32 WDM:2;
                  vuint32:14;
                vuint32 WDCNT:16;
            } B;
        } WDTR_A;                 /* ETPU1 WDTR Register @baseaddress + 0x60 */

        vuint32 ETPU1_reserved_0064;  /* 0x0064 - 0x0067 */


        union {
            vuint32 R;
            struct {
                vuint32 IDLE_CNT:31;
                vuint32 ICLR:1;
            } B;
        } IDLE_A;                  /* ETPU1 IDLE Register @baseaddress + 0x68 */

        vuint32 ETPU_reserved_006C[101];      /* 0x006C - 0x01FF */


        union {
            vuint32 R;
            struct {
                vuint32 CIS31:1;      /*  Channel 31 Interrut Status  */
                vuint32 CIS30:1;      /*  Channel 30 Interrut Status  */
                vuint32 CIS29:1;      /*  Channel 29 Interrut Status  */
                vuint32 CIS28:1;      /*  Channel 28 Interrut Status  */
                vuint32 CIS27:1;      /*  Channel 27 Interrut Status  */
                vuint32 CIS26:1;      /*  Channel 26 Interrut Status  */
                vuint32 CIS25:1;      /*  Channel 25 Interrut Status  */
                vuint32 CIS24:1;      /*  Channel 24 Interrut Status  */
                vuint32 CIS23:1;      /*  Channel 23 Interrut Status  */
                vuint32 CIS22:1;      /*  Channel 22 Interrut Status  */
                vuint32 CIS21:1;      /*  Channel 21 Interrut Status  */
                vuint32 CIS20:1;      /*  Channel 20 Interrut Status  */
                vuint32 CIS19:1;      /*  Channel 19 Interrut Status  */
                vuint32 CIS18:1;      /*  Channel 18 Interrut Status  */
                vuint32 CIS17:1;      /*  Channel 17 Interrut Status  */
                vuint32 CIS16:1;      /*  Channel 16 Interrut Status  */
                vuint32 CIS15:1;      /*  Channel 15 Interrut Status  */
                vuint32 CIS14:1;      /*  Channel 14 Interrut Status  */
                vuint32 CIS13:1;      /*  Channel 13 Interrut Status  */
                vuint32 CIS12:1;      /*  Channel 12 Interrut Status  */
                vuint32 CIS11:1;      /*  Channel 11 Interrut Status  */
                vuint32 CIS10:1;      /*  Channel 10 Interrut Status  */
                vuint32 CIS9:1;       /*  Channel 9 Interrut Status  */
                vuint32 CIS8:1;       /*  Channel 8 Interrut Status  */
                vuint32 CIS7:1;       /*  Channel 7 Interrut Status  */
                vuint32 CIS6:1;       /*  Channel 6 Interrut Status  */
                vuint32 CIS5:1;       /*  Channel 5 Interrut Status  */
                vuint32 CIS4:1;       /*  Channel 4 Interrut Status  */
                vuint32 CIS3:1;       /*  Channel 3 Interrut Status  */
                vuint32 CIS2:1;       /*  Channel 2 Interrut Status  */
                vuint32 CIS1:1;       /*  Channel 1 Interrut Status  */
                vuint32 CIS0:1;       /*  Channel 0 Interrut Status  */
            } B;
        } CISR_A;               /* eTPU Channel Interrupt Status Register (ETPU_CISR)@baseaddress + 0x200 */

        sint32 ETPU_reserved_0204[3];      /* 0x0204 - 0x20F */

        union {
            vuint32 R;
            struct {
                vuint32 DTRS31:1;     /*  Channel 31 Data Transfer Request Status  */
                vuint32 DTRS30:1;     /*  Channel 30 Data Transfer Request Status  */
                vuint32 DTRS29:1;     /*  Channel 29 Data Transfer Request Status  */
                vuint32 DTRS28:1;     /*  Channel 28 Data Transfer Request Status  */
                vuint32 DTRS27:1;     /*  Channel 27 Data Transfer Request Status  */
                vuint32 DTRS26:1;     /*  Channel 26 Data Transfer Request Status  */
                vuint32 DTRS25:1;     /*  Channel 25 Data Transfer Request Status  */
                vuint32 DTRS24:1;     /*  Channel 24 Data Transfer Request Status  */
                vuint32 DTRS23:1;     /*  Channel 23 Data Transfer Request Status  */
                vuint32 DTRS22:1;     /*  Channel 22 Data Transfer Request Status  */
                vuint32 DTRS21:1;     /*  Channel 21 Data Transfer Request Status  */
                vuint32 DTRS20:1;     /*  Channel 20 Data Transfer Request Status  */
                vuint32 DTRS19:1;     /*  Channel 19 Data Transfer Request Status  */
                vuint32 DTRS18:1;     /*  Channel 18 Data Transfer Request Status  */
                vuint32 DTRS17:1;     /*  Channel 17 Data Transfer Request Status  */
                vuint32 DTRS16:1;     /*  Channel 16 Data Transfer Request Status  */
                vuint32 DTRS15:1;     /*  Channel 15 Data Transfer Request Status  */
                vuint32 DTRS14:1;     /*  Channel 14 Data Transfer Request Status  */
                vuint32 DTRS13:1;     /*  Channel 13 Data Transfer Request Status  */
                vuint32 DTRS12:1;     /*  Channel 12 Data Transfer Request Status  */
                vuint32 DTRS11:1;     /*  Channel 11 Data Transfer Request Status  */
                vuint32 DTRS10:1;     /*  Channel 10 Data Transfer Request Status  */
                vuint32 DTRS9:1;      /*  Channel 9 Data Transfer Request Status  */
                vuint32 DTRS8:1;      /*  Channel 8 Data Transfer Request Status  */
                vuint32 DTRS7:1;      /*  Channel 7 Data Transfer Request Status  */
                vuint32 DTRS6:1;      /*  Channel 6 Data Transfer Request Status  */
                vuint32 DTRS5:1;      /*  Channel 5 Data Transfer Request Status  */
                vuint32 DTRS4:1;      /*  Channel 4 Data Transfer Request Status  */
                vuint32 DTRS3:1;      /*  Channel 3 Data Transfer Request Status  */
                vuint32 DTRS2:1;      /*  Channel 2 Data Transfer Request Status  */
                vuint32 DTRS1:1;      /*  Channel 1 Data Transfer Request Status  */
                vuint32 DTRS0:1;      /*  Channel 0 Data Transfer Request Status  */
            } B;
        } CDTRSR_A;             /* eTPU Channel Data Transfer Request Status Register (ETPU_CDTRSR) @baseaddress + 0x210 */

        sint32 ETPU_reserved_0214[3];      /* 0x0214 - 0x021F */


        union {
            vuint32 R;
            struct {
                vuint32 CIOS31:1;     /*  Channel 31 Interruput Overflow Status  */
                vuint32 CIOS30:1;     /*  Channel 30 Interruput Overflow Status  */
                vuint32 CIOS29:1;     /*  Channel 29 Interruput Overflow Status  */
                vuint32 CIOS28:1;     /*  Channel 28 Interruput Overflow Status  */
                vuint32 CIOS27:1;     /*  Channel 27 Interruput Overflow Status  */
                vuint32 CIOS26:1;     /*  Channel 26 Interruput Overflow Status  */
                vuint32 CIOS25:1;     /*  Channel 25 Interruput Overflow Status  */
                vuint32 CIOS24:1;     /*  Channel 24 Interruput Overflow Status  */
                vuint32 CIOS23:1;     /*  Channel 23 Interruput Overflow Status  */
                vuint32 CIOS22:1;     /*  Channel 22 Interruput Overflow Status  */
                vuint32 CIOS21:1;     /*  Channel 21 Interruput Overflow Status  */
                vuint32 CIOS20:1;     /*  Channel 20 Interruput Overflow Status  */
                vuint32 CIOS19:1;     /*  Channel 19 Interruput Overflow Status  */
                vuint32 CIOS18:1;     /*  Channel 18 Interruput Overflow Status  */
                vuint32 CIOS17:1;     /*  Channel 17 Interruput Overflow Status  */
                vuint32 CIOS16:1;     /*  Channel 16 Interruput Overflow Status  */
                vuint32 CIOS15:1;     /*  Channel 15 Interruput Overflow Status  */
                vuint32 CIOS14:1;     /*  Channel 14 Interruput Overflow Status  */
                vuint32 CIOS13:1;     /*  Channel 13 Interruput Overflow Status  */
                vuint32 CIOS12:1;     /*  Channel 12 Interruput Overflow Status  */
                vuint32 CIOS11:1;     /*  Channel 11 Interruput Overflow Status  */
                vuint32 CIOS10:1;     /*  Channel 10 Interruput Overflow Status  */
                vuint32 CIOS9:1;      /*  Channel 9 Interruput Overflow Status  */
                vuint32 CIOS8:1;      /*  Channel 8 Interruput Overflow Status  */
                vuint32 CIOS7:1;      /*  Channel 7 Interruput Overflow Status  */
                vuint32 CIOS6:1;      /*  Channel 6 Interruput Overflow Status  */
                vuint32 CIOS5:1;      /*  Channel 5 Interruput Overflow Status  */
                vuint32 CIOS4:1;      /*  Channel 4 Interruput Overflow Status  */
                vuint32 CIOS3:1;      /*  Channel 3 Interruput Overflow Status  */
                vuint32 CIOS2:1;      /*  Channel 2 Interruput Overflow Status  */
                vuint32 CIOS1:1;      /*  Channel 1 Interruput Overflow Status  */
                vuint32 CIOS0:1;      /*  Channel 0 Interruput Overflow Status  */
            } B;
        } CIOSR_A;              /* eTPU Channel Interrupt Overflow Status Register (ETPU_CIOSR)@baseaddress + 0x220 */

        sint32 ETPU_reserved_0224[3];      /* 0x0224 - 0x022F */


        union {
            vuint32 R;
            struct {
                vuint32 DTROS31:1;    /*  Channel 31 Data Transfer Overflow Status  */
                vuint32 DTROS30:1;    /*  Channel 30 Data Transfer Overflow Status  */
                vuint32 DTROS29:1;    /*  Channel 29 Data Transfer Overflow Status  */
                vuint32 DTROS28:1;    /*  Channel 28 Data Transfer Overflow Status  */
                vuint32 DTROS27:1;    /*  Channel 27 Data Transfer Overflow Status  */
                vuint32 DTROS26:1;    /*  Channel 26 Data Transfer Overflow Status  */
                vuint32 DTROS25:1;    /*  Channel 25 Data Transfer Overflow Status  */
                vuint32 DTROS24:1;    /*  Channel 24 Data Transfer Overflow Status  */
                vuint32 DTROS23:1;    /*  Channel 23 Data Transfer Overflow Status  */
                vuint32 DTROS22:1;    /*  Channel 22 Data Transfer Overflow Status  */
                vuint32 DTROS21:1;    /*  Channel 21 Data Transfer Overflow Status  */
                vuint32 DTROS20:1;    /*  Channel 20 Data Transfer Overflow Status  */
                vuint32 DTROS19:1;    /*  Channel 19 Data Transfer Overflow Status  */
                vuint32 DTROS18:1;    /*  Channel 18 Data Transfer Overflow Status  */
                vuint32 DTROS17:1;    /*  Channel 17 Data Transfer Overflow Status  */
                vuint32 DTROS16:1;    /*  Channel 16 Data Transfer Overflow Status  */
                vuint32 DTROS15:1;    /*  Channel 15 Data Transfer Overflow Status  */
                vuint32 DTROS14:1;    /*  Channel 14 Data Transfer Overflow Status  */
                vuint32 DTROS13:1;    /*  Channel 13 Data Transfer Overflow Status  */
                vuint32 DTROS12:1;    /*  Channel 12 Data Transfer Overflow Status  */
                vuint32 DTROS11:1;    /*  Channel 11 Data Transfer Overflow Status  */
                vuint32 DTROS10:1;    /*  Channel 10 Data Transfer Overflow Status  */
                vuint32 DTROS9:1;     /*  Channel 9 Data Transfer Overflow Status  */
                vuint32 DTROS8:1;     /*  Channel 8 Data Transfer Overflow Status  */
                vuint32 DTROS7:1;     /*  Channel 7 Data Transfer Overflow Status  */
                vuint32 DTROS6:1;     /*  Channel 6 Data Transfer Overflow Status  */
                vuint32 DTROS5:1;     /*  Channel 5 Data Transfer Overflow Status  */
                vuint32 DTROS4:1;     /*  Channel 4 Data Transfer Overflow Status  */
                vuint32 DTROS3:1;     /*  Channel 3 Data Transfer Overflow Status  */
                vuint32 DTROS2:1;     /*  Channel 2 Data Transfer Overflow Status  */
                vuint32 DTROS1:1;     /*  Channel 1 Data Transfer Overflow Status  */
                vuint32 DTROS0:1;     /*  Channel 0 Data Transfer Overflow Status  */
            } B;
        } CDTROSR_A;            /* eTPU Channel Data Transfer Request Overflow Status Register@baseaddress + 0x230 */

        sint32 ETPU_reserved_0234[3];      /* 0x0234 - 0x023F */


        union {
            vuint32 R;
            struct {
                vuint32 CIE31:1;      /*  Channel 31 Interruput Enable  */
                vuint32 CIE30:1;      /*  Channel 30 Interruput Enable  */
                vuint32 CIE29:1;      /*  Channel 29 Interruput Enable  */
                vuint32 CIE28:1;      /*  Channel 28 Interruput Enable  */
                vuint32 CIE27:1;      /*  Channel 27 Interruput Enable  */
                vuint32 CIE26:1;      /*  Channel 26 Interruput Enable  */
                vuint32 CIE25:1;      /*  Channel 25 Interruput Enable  */
                vuint32 CIE24:1;      /*  Channel 24 Interruput Enable  */
                vuint32 CIE23:1;      /*  Channel 23 Interruput Enable  */
                vuint32 CIE22:1;      /*  Channel 22 Interruput Enable  */
                vuint32 CIE21:1;      /*  Channel 21 Interruput Enable  */
                vuint32 CIE20:1;      /*  Channel 20 Interruput Enable  */
                vuint32 CIE19:1;      /*  Channel 19 Interruput Enable  */
                vuint32 CIE18:1;      /*  Channel 18 Interruput Enable  */
                vuint32 CIE17:1;      /*  Channel 17 Interruput Enable  */
                vuint32 CIE16:1;      /*  Channel 16 Interruput Enable  */
                vuint32 CIE15:1;      /*  Channel 15 Interruput Enable  */
                vuint32 CIE14:1;      /*  Channel 14 Interruput Enable  */
                vuint32 CIE13:1;      /*  Channel 13 Interruput Enable  */
                vuint32 CIE12:1;      /*  Channel 12 Interruput Enable  */
                vuint32 CIE11:1;      /*  Channel 11 Interruput Enable  */
                vuint32 CIE10:1;      /*  Channel 10 Interruput Enable  */
                vuint32 CIE9:1;       /*  Channel 9 Interruput Enable  */
                vuint32 CIE8:1;       /*  Channel 8 Interruput Enable  */
                vuint32 CIE7:1;       /*  Channel 7 Interruput Enable  */
                vuint32 CIE6:1;       /*  Channel 6 Interruput Enable  */
                vuint32 CIE5:1;       /*  Channel 5 Interruput Enable  */
                vuint32 CIE4:1;       /*  Channel 4 Interruput Enable  */
                vuint32 CIE3:1;       /*  Channel 3 Interruput Enable  */
                vuint32 CIE2:1;       /*  Channel 2 Interruput Enable  */
                vuint32 CIE1:1;       /*  Channel 1 Interruput Enable  */
                vuint32 CIE0:1;       /*  Channel 0 Interruput Enable  */
            } B;
        } CIER_A;               /* eTPU Channel Interrupt Enable Register (ETPU_CIER)@baseaddress + 0x240 */

        sint32 ETPU_reserved_0244[3];      /* 0x0244 - 0x25F */


        union {
            vuint32 R;
            struct {
                vuint32 DTRE31:1;     /*  Channel 31 Data Transfer Request Enable  */
                vuint32 DTRE30:1;     /*  Channel 30 Data Transfer Request Enable  */
                vuint32 DTRE29:1;     /*  Channel 29 Data Transfer Request Enable  */
                vuint32 DTRE28:1;     /*  Channel 28 Data Transfer Request Enable  */
                vuint32 DTRE27:1;     /*  Channel 27 Data Transfer Request Enable  */
                vuint32 DTRE26:1;     /*  Channel 26 Data Transfer Request Enable  */
                vuint32 DTRE25:1;     /*  Channel 25 Data Transfer Request Enable  */
                vuint32 DTRE24:1;     /*  Channel 24 Data Transfer Request Enable  */
                vuint32 DTRE23:1;     /*  Channel 23 Data Transfer Request Enable  */
                vuint32 DTRE22:1;     /*  Channel 22 Data Transfer Request Enable  */
                vuint32 DTRE21:1;     /*  Channel 21 Data Transfer Request Enable  */
                vuint32 DTRE20:1;     /*  Channel 20 Data Transfer Request Enable  */
                vuint32 DTRE19:1;     /*  Channel 19 Data Transfer Request Enable  */
                vuint32 DTRE18:1;     /*  Channel 18 Data Transfer Request Enable  */
                vuint32 DTRE17:1;     /*  Channel 17 Data Transfer Request Enable  */
                vuint32 DTRE16:1;     /*  Channel 16 Data Transfer Request Enable  */
                vuint32 DTRE15:1;     /*  Channel 15 Data Transfer Request Enable  */
                vuint32 DTRE14:1;     /*  Channel 14 Data Transfer Request Enable  */
                vuint32 DTRE13:1;     /*  Channel 13 Data Transfer Request Enable  */
                vuint32 DTRE12:1;     /*  Channel 12 Data Transfer Request Enable  */
                vuint32 DTRE11:1;     /*  Channel 11 Data Transfer Request Enable  */
                vuint32 DTRE10:1;     /*  Channel 10 Data Transfer Request Enable  */
                vuint32 DTRE9:1;      /*  Channel 9 Data Transfer Request Enable  */
                vuint32 DTRE8:1;      /*  Channel 8 Data Transfer Request Enable  */
                vuint32 DTRE7:1;      /*  Channel 7 Data Transfer Request Enable  */
                vuint32 DTRE6:1;      /*  Channel 6 Data Transfer Request Enable  */
                vuint32 DTRE5:1;      /*  Channel 5 Data Transfer Request Enable  */
                vuint32 DTRE4:1;      /*  Channel 4 Data Transfer Request Enable  */
                vuint32 DTRE3:1;      /*  Channel 3 Data Transfer Request Enable  */
                vuint32 DTRE2:1;      /*  Channel 2 Data Transfer Request Enable  */
                vuint32 DTRE1:1;      /*  Channel 1 Data Transfer Request Enable  */
                vuint32 DTRE0:1;      /*  Channel 0 Data Transfer Request Enable  */
            } B;
        } CDTRER_A;             /* eTPU Channel Data Transfer Request Enable Register (ETPU_CDTRER)@baseaddress + 0x250 */

        sint32 ETPU_reserved_0254[3];      /* 0x0254 - 0x025F */


        union {
            vuint32 R;
            struct {
                vuint32 WDS31:1;      /*  Channel 31 Data Transfer Request Enable  */
                vuint32 WDS30:1;      /*  Channel 30 Data Transfer Request Enable  */
                vuint32 WDS29:1;      /*  Channel 29 Data Transfer Request Enable  */
                vuint32 WDS28:1;      /*  Channel 28 Data Transfer Request Enable  */
                vuint32 WDS27:1;      /*  Channel 27 Data Transfer Request Enable  */
                vuint32 WDS26:1;      /*  Channel 26 Data Transfer Request Enable  */
                vuint32 WDS25:1;      /*  Channel 25 Data Transfer Request Enable  */
                vuint32 WDS24:1;      /*  Channel 24 Data Transfer Request Enable  */
                vuint32 WDS23:1;      /*  Channel 23 Data Transfer Request Enable  */
                vuint32 WDS22:1;      /*  Channel 22 Data Transfer Request Enable  */
                vuint32 WDS21:1;      /*  Channel 21 Data Transfer Request Enable  */
                vuint32 WDS20:1;      /*  Channel 20 Data Transfer Request Enable  */
                vuint32 WDS19:1;      /*  Channel 19 Data Transfer Request Enable  */
                vuint32 WDS18:1;      /*  Channel 18 Data Transfer Request Enable  */
                vuint32 WDS17:1;      /*  Channel 17 Data Transfer Request Enable  */
                vuint32 WDS16:1;      /*  Channel 16 Data Transfer Request Enable  */
                vuint32 WDS15:1;      /*  Channel 15 Data Transfer Request Enable  */
                vuint32 WDS14:1;      /*  Channel 14 Data Transfer Request Enable  */
                vuint32 WDS13:1;      /*  Channel 13 Data Transfer Request Enable  */
                vuint32 WDS12:1;      /*  Channel 12 Data Transfer Request Enable  */
                vuint32 WDS11:1;      /*  Channel 11 Data Transfer Request Enable  */
                vuint32 WDS10:1;      /*  Channel 10 Data Transfer Request Enable  */
                vuint32 WDS9:1;       /*  Channel 9 Data Transfer Request Enable  */
                vuint32 WDS8:1;       /*  Channel 8 Data Transfer Request Enable  */
                vuint32 WDS7:1;       /*  Channel 7 Data Transfer Request Enable  */
                vuint32 WDS6:1;       /*  Channel 6 Data Transfer Request Enable  */
                vuint32 WDS5:1;       /*  Channel 5 Data Transfer Request Enable  */
                vuint32 WDS4:1;       /*  Channel 4 Data Transfer Request Enable  */
                vuint32 WDS3:1;       /*  Channel 3 Data Transfer Request Enable  */
                vuint32 WDS2:1;       /*  Channel 2 Data Transfer Request Enable  */
                vuint32 WDS1:1;       /*  Channel 1 Data Transfer Request Enable  */
                vuint32 WDS0:1;       /*  Channel 0 Data Transfer Request Enable  */
            } B;
        } WDSR_A;              /* ETPUWDSR - eTPU Watchdog Status Register @baseaddress + 0x260 */

        sint32 ETPU_reserved_0264[7];      /* 0x0264 - 0x027F */


        union {
            vuint32 R;
            struct {
                vuint32 SR31:1;       /*  Channel 31 Data Transfer Request Enable  */
                vuint32 SR30:1;       /*  Channel 30 Data Transfer Request Enable  */
                vuint32 SR29:1;       /*  Channel 29 Data Transfer Request Enable  */
                vuint32 SR28:1;       /*  Channel 28 Data Transfer Request Enable  */
                vuint32 SR27:1;       /*  Channel 27 Data Transfer Request Enable  */
                vuint32 SR26:1;       /*  Channel 26 Data Transfer Request Enable  */
                vuint32 SR25:1;       /*  Channel 25 Data Transfer Request Enable  */
                vuint32 SR24:1;       /*  Channel 24 Data Transfer Request Enable  */
                vuint32 SR23:1;       /*  Channel 23 Data Transfer Request Enable  */
                vuint32 SR22:1;       /*  Channel 22 Data Transfer Request Enable  */
                vuint32 SR21:1;       /*  Channel 21 Data Transfer Request Enable  */
                vuint32 SR20:1;       /*  Channel 20 Data Transfer Request Enable  */
                vuint32 SR19:1;       /*  Channel 19 Data Transfer Request Enable  */
                vuint32 SR18:1;       /*  Channel 18 Data Transfer Request Enable  */
                vuint32 SR17:1;       /*  Channel 17 Data Transfer Request Enable  */
                vuint32 SR16:1;       /*  Channel 16 Data Transfer Request Enable  */
                vuint32 SR15:1;       /*  Channel 15 Data Transfer Request Enable  */
                vuint32 SR14:1;       /*  Channel 14 Data Transfer Request Enable  */
                vuint32 SR13:1;       /*  Channel 13 Data Transfer Request Enable  */
                vuint32 SR12:1;       /*  Channel 12 Data Transfer Request Enable  */
                vuint32 SR11:1;       /*  Channel 11 Data Transfer Request Enable  */
                vuint32 SR10:1;       /*  Channel 10 Data Transfer Request Enable  */
                vuint32 SR9:1;        /*  Channel 9 Data Transfer Request Enable  */
                vuint32 SR8:1;        /*  Channel 8 Data Transfer Request Enable  */
                vuint32 SR7:1;        /*  Channel 7 Data Transfer Request Enable  */
                vuint32 SR6:1;        /*  Channel 6 Data Transfer Request Enable  */
                vuint32 SR5:1;        /*  Channel 5 Data Transfer Request Enable  */
                vuint32 SR4:1;        /*  Channel 4 Data Transfer Request Enable  */
                vuint32 SR3:1;        /*  Channel 3 Data Transfer Request Enable  */
                vuint32 SR2:1;        /*  Channel 2 Data Transfer Request Enable  */
                vuint32 SR1:1;        /*  Channel 1 Data Transfer Request Enable  */
                vuint32 SR0:1;        /*  Channel 0 Data Transfer Request Enable  */
            } B;
        } CPSSR_A;              /* ETPUCPSSR - eTPU Channel Pending Service Status Register @baseaddress + 0x280  */

        sint32 ETPU_reserved_0x0284[3];        /* 0x0284 - 0x028F  */


        union {
            vuint32 R;
            struct {
                vuint32 SS31:1;       /*  Channel 31 Data Transfer Request Enable  */
                vuint32 SS30:1;       /*  Channel 30 Data Transfer Request Enable  */
                vuint32 SS29:1;       /*  Channel 29 Data Transfer Request Enable  */
                vuint32 SS28:1;       /*  Channel 28 Data Transfer Request Enable  */
                vuint32 SS27:1;       /*  Channel 27 Data Transfer Request Enable  */
                vuint32 SS26:1;       /*  Channel 26 Data Transfer Request Enable  */
                vuint32 SS25:1;       /*  Channel 25 Data Transfer Request Enable  */
                vuint32 SS24:1;       /*  Channel 24 Data Transfer Request Enable  */
                vuint32 SS23:1;       /*  Channel 23 Data Transfer Request Enable  */
                vuint32 SS22:1;       /*  Channel 22 Data Transfer Request Enable  */
                vuint32 SS21:1;       /*  Channel 21 Data Transfer Request Enable  */
                vuint32 SS20:1;       /*  Channel 20 Data Transfer Request Enable  */
                vuint32 SS19:1;       /*  Channel 19 Data Transfer Request Enable  */
                vuint32 SS18:1;       /*  Channel 18 Data Transfer Request Enable  */
                vuint32 SS17:1;       /*  Channel 17 Data Transfer Request Enable  */
                vuint32 SS16:1;       /*  Channel 16 Data Transfer Request Enable  */
                vuint32 SS15:1;       /*  Channel 15 Data Transfer Request Enable  */
                vuint32 SS14:1;       /*  Channel 14 Data Transfer Request Enable  */
                vuint32 SS13:1;       /*  Channel 13 Data Transfer Request Enable  */
                vuint32 SS12:1;       /*  Channel 12 Data Transfer Request Enable  */
                vuint32 SS11:1;       /*  Channel 11 Data Transfer Request Enable  */
                vuint32 SS10:1;       /*  Channel 10 Data Transfer Request Enable  */
                vuint32 SS9:1;        /*  Channel 9 Data Transfer Request Enable  */
                vuint32 SS8:1;        /*  Channel 8 Data Transfer Request Enable  */
                vuint32 SS7:1;        /*  Channel 7 Data Transfer Request Enable  */
                vuint32 SS6:1;        /*  Channel 6 Data Transfer Request Enable  */
                vuint32 SS5:1;        /*  Channel 5 Data Transfer Request Enable  */
                vuint32 SS4:1;        /*  Channel 4 Data Transfer Request Enable  */
                vuint32 SS3:1;        /*  Channel 3 Data Transfer Request Enable  */
                vuint32 SS2:1;        /*  Channel 2 Data Transfer Request Enable  */
                vuint32 SS1:1;        /*  Channel 1 Data Transfer Request Enable  */
                vuint32 SS0:1;        /*  Channel 0 Data Transfer Request Enable  */
            } B;
        } CSSR_A;               /* ETPUCSSR - eTPU Channel Service Status Register @baseaddress + 0x290  */

        sint32 ETPU_reserved_0294[91];         /* 0x0294 - 0x03FF */


/***************************** Channels ********************************/
/* Note not all devices implement all channels or even 2 engines       */
/* Each eTPU engine can implement 64 channels, however most devcies    */
/* only implemnet 32 channels. The eTPU block can implement 1 or 2     */
/* engines per instantiation                                           */
/***********************************************************************/

        struct {
            union {
                vuint32 R;
                struct {
                    vuint32 CIE:1;    /*  Channel Interruput Enable  */
                    vuint32 DTRE:1;   /*  Data Transfer Request Enable  */
                    vuint32 CPR:2;    /*  Channel Priority  */
                      vuint32:2;      /*  */
                    vuint32 ETPD:1;   /*  This bit selects which channel signal, input or output, is used in the entry point selection */
                    vuint32 ETCS:1;   /*  Entry Table Condition Select  */
                      vuint32:3;      /*  */
                    vuint32 CFS:5;    /*  Channel Function Select  */
                    vuint32 ODIS:1;   /*  Output disable  */
                    vuint32 OPOL:1;   /*  output polarity  */
                      vuint32:3;      /*  */
                    vuint32 CPBA:11;  /*  Channel Parameter Base Address  */
                } B;
            } CR;               /* eTPU Channel n Configuration Register (ETPU_CnCR)@baseaddress + 0x400 */

            union {
                vuint32 R;
                struct {
                    vuint32 CIS:1;    /*  Channel Interruput Status  */
                    vuint32 CIOS:1;   /*  Channel Interruput Overflow Status  */
                      vuint32:6;      /*  */
                    vuint32 DTRS:1;   /*  Data Transfer Status  */
                    vuint32 DTROS:1;  /*  Data Transfer Overflow Status  */
                      vuint32:6;      /*  */
                    vuint32 IPS:1;    /*  Input Pin State  */
                    vuint32 OPS:1;    /*  Output Pin State  */
                    vuint32 OBE:1;    /*  Output Pin State  */
                      vuint32:11;     /*  */
                    vuint32 FM1:1;    /* Function mode */
                    vuint32 FM0:1;    /* Function mode */
                } B;
            } SCR;              /* eTPU Channel n Status Control Register (ETPU_CnSCR)@baseaddress + 0x404 */

            union {
                vuint32 R;
                struct {
                    vuint32:29;       /*  Host Service Request  */
                    vuint32 HSR:3;    /*  */
                } B;
            } HSRR;             /* eTPU channel host service request register (ETPU_CnHSRR)@baseaddress + 0x408 */

            sint32 ETPU_reserved_0C;       /* CHAN Base + 0x0C */

        } CHAN[127];
                 /**** Note: Not all channels implemented on all devices. *******/
    };

/****************************************************************************/
/*                          MODULE : EQADC                                  */
/****************************************************************************/
    struct EQADCag {
        union {
            vuint32 R;
            struct {
                vuint32:24;
                vuint32 ICEA0:1;
                vuint32 ICEA1:1;
                  vuint32:1;
                vuint32 ESSIE:2;
                  vuint32:1;
                vuint32 DBG:2;
            } B;
        } MCR;                  /* Module Configuration Register */

        sint32 EQADC_reserved0004;     /* 0x0004 - 0x0007 */

        union {
            vuint32 R;
            struct {
                vuint32:6;
                vuint32 NMF:26;
            } B;
        } NMSFR;                /* Null Message Send Format Register */

        union {
            vuint32 R;
            struct {
                vuint32:28;
                vuint32 DFL:4;
            } B;
        } ETDFR;                /* External Trigger Digital Filter Register */

        union {
            vuint32 R;
            struct {
                vuint32 CFPUSH:32;
            } B;
        } CFPR[6];              /* CFIFO Push Registers */

        uint32 eqadc_reserved1;

        uint32 eqadc_reserved2;

        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 RFPOP:16;
            } B;
        } RFPR[6];              /* Result FIFO Pop Registers*/

        uint32 eqadc_reserved3;

        uint32 eqadc_reserved4;

        union {
            vuint16 R;
            struct {
                vuint16:3;
                vuint16 CFEE0:1;
                vuint16 STRME0:1;
                vuint16 SSE:1;
                vuint16 CFINV:1;
                  vuint16:1;
                vuint16 MODE:4;
                vuint16 AMODE0:4;     /* CFIFO0 only */
            } B;
        } CFCR[6];              /* CFIFO Control Registers */

        uint32 eqadc_reserved5;

        union {
            vuint16 R;
            struct {
                vuint16 NCIE:1;
                vuint16 TORIE:1;
                vuint16 PIE:1;
                vuint16 EOQIE:1;
                vuint16 CFUIE:1;
                  vuint16:1;
                vuint16 CFFE:1;
                vuint16 CFFS:1;
                  vuint16:4;
                vuint16 RFOIE:1;
                  vuint16:1;
                vuint16 RFDE:1;
                vuint16 RFDS:1;
            } B;
        } IDCR[6];              /* Interrupt and DMA Control Registers */

        uint32 eqadc_reserved6;

        union {
            vuint32 R;
            struct {
                vuint32 NCF:1;
                vuint32 TORF:1;
                vuint32 PF:1;
                vuint32 EOQF:1;
                vuint32 CFUF:1;
                vuint32 SSS:1;
                vuint32 CFFF:1;
                  vuint32:5;
                vuint32 RFOF:1;
                  vuint32:1;
                vuint32 RFDF:1;
                  vuint32:1;
                vuint32 CFCTR:4;
                vuint32 TNXTPTR:4;
                vuint32 RFCTR:4;
                vuint32 POPNXTPTR:4;
            } B;
        } FISR[6];              /* FIFO and Interrupt Status Registers */

        uint32 eqadc_reserved7;

        uint32 eqadc_reserved8;

        union {
            vuint16 R;
            struct {
                vuint16:5;
                vuint16 TCCF:11;
            } B;
        } CFTCR[6];             /* CFIFO Transfer Counter Registers */

        uint32 eqadc_reserved9;

        union {
            vuint32 R;
            struct {
                vuint32 CFS0:2;
                vuint32 CFS1:2;
                vuint32 CFS2:2;
                vuint32 CFS3:2;
                vuint32 CFS4:2;
                vuint32 CFS5:2;
                  vuint32:5;
                vuint32 LCFTCB0:4;
                vuint32 TC_LCFTCB0:11;
            } B;
        } CFSSR0;               /* CFIFO Status Register 0 */

        union {
            vuint32 R;
            struct {
                vuint32 CFS0:2;
                vuint32 CFS1:2;
                vuint32 CFS2:2;
                vuint32 CFS3:2;
                vuint32 CFS4:2;
                vuint32 CFS5:2;
                  vuint32:5;
                vuint32 LCFTCB1:4;
                vuint32 TC_LCFTCB1:11;
            } B;
        } CFSSR1;               /* CFIFO Status Register 1 */

        union {
            vuint32 R;
            struct {
                vuint32 CFS0:2;
                vuint32 CFS1:2;
                vuint32 CFS2:2;
                vuint32 CFS3:2;
                vuint32 CFS4:2;
                vuint32 CFS5:2;
                  vuint32:4;
                vuint32 ECBNI:1;
                vuint32 LCFTSSI:4;
                vuint32 TC_LCFTSSI:11;
            } B;
        } CFSSR2;               /* CFIFO Status Register 2 */

        union {
            vuint32 R;
            struct {
                vuint32 CFS0:2;
                vuint32 CFS1:2;
                vuint32 CFS2:2;
                vuint32 CFS3:2;
                vuint32 CFS4:2;
                vuint32 CFS5:2;
                  vuint32:20;
            } B;
        } CFSR;

        uint32 eqadc_reserved11;

        union {
            vuint32 R;
            struct {
                vuint32:21;
                vuint32 MDT:3;
                  vuint32:4;
                vuint32 BR:4;
            } B;
        } SSICR;                /* SSI Control Register */

        union {
            vuint32 R;
            struct {
                vuint32 RDV:1;
                  vuint32:5;
                vuint32 RDATA:26;
            } B;
        } SSIRDR;               /* SSI Recieve Data Register @ baseaddress + 0xB8 */

        uint32 eqadc_reserved11b[5];

        union {
            vuint32 R;
            struct {
                 vuint32:16;
                vuint32 REDBS2:4;
                vuint32 SRV2:4;
                vuint32 REDBS1:4;
                vuint32 SRV1:4;
            } B;
        } REDLCCR;               /* STAC Bus Clent Configuration Register @ baseaddress + 0xD0 */


        uint32 eqadc_reserved12[11];

        struct {
            union {
                vuint32 R;
                struct {
                    vuint32:32;
                } B;
            } R[4];

            union {
                vuint32 R;
                struct {
                    vuint32:32;
                } B;
            } EDATA[4];

            uint32 eqadc_reserved13[8];

        } CF[6];

        uint32 eqadc_reserved14[32];

        struct {
            union {
                vuint32 R;
                struct {
                    vuint32:32;
                } B;
            } R[4];

            uint32 eqadc_reserved15[12];

        } RF[6];

    };

/****************************************************************************/
/*                     MODULE : Decimation Filter (DECFIL)                  */
/****************************************************************************/
    struct DECFILag {
        union {
            vuint32 R;
            struct {
                vuint32 MDIS:1;
                vuint32 FREN:1;
                  vuint32:1;
                vuint32 FRZ:1;
                vuint32 SRES:1;
                vuint32 CASCD:2;
                vuint32 IDEN:1;
                vuint32 ODEN:1;
                vuint32 ERREN:1;
                  vuint32:1;
                vuint32 FTYPE:2;
                  vuint32:1;
                vuint32 SCAL:2;
                vuint32 IDIS:1;
                vuint32 SAT:1;
                vuint32 ISEL:1;
                vuint32 MIXM:1;
                vuint32 DEC_RATE:4;
                vuint32 SDIE:1;
                vuint32 DSEL:1;
                vuint32 IBIE:1;
                vuint32 OBIE:1;
                vuint32 EDME:1;
                vuint32 TORE:1;
                vuint32 TMODE:2;
            } B;
        } MCR;                  /* Configuration Register @baseaddress + 0x00 */

        union {
            vuint32 R;
            struct {
                vuint32 BSY:1;
                  vuint32:1;
                vuint32 DEC_COUNTER:4;
                vuint32 IDFC:1;
                vuint32 ODFC:1;
                  vuint32:1;
                vuint32 IBIC:1;
                vuint32 OBIC:1;
                  vuint32:1;
                vuint32 DIVRC:1;
                vuint32 OVFC:1;
                vuint32 OVRC:1;
                vuint32 IVRC:1;
                  vuint32:6;
                vuint32 IDF:1;
                vuint32 ODF:1;
                  vuint32:1;
                vuint32 IBIF:1;
                vuint32 OBIF:1;
                  vuint32:1;
                vuint32 DIVR:1;
                vuint32 OVF:1;
                vuint32 OVR:1;
                vuint32 IVR:1;
            } B;
        } MSR;                  /* Status Register @baseaddress + 0x04 */

 		union {
            vuint32 R;
            struct {
                vuint32 SDMAE:1;
                vuint32 SSIG:1;
                vuint32 SSAT:1;
                vuint32 SCSAT:1;
                  vuint32:10;
                vuint32 SRQ:1;
                vuint32 SZRO:1;  
                vuint32 SISEL:1;  
                  vuint32:1;
                vuint32 SZROSEL:2;    
                  vuint32:2;
                vuint32 SHLTSEL:2;      
                  vuint32:1;
                vuint32 SRQSEL:3;        
                  vuint32:2;
                vuint32 SENSEL:2;          
            } B;
        } MXCR;                   /* Extended Config Register @baseaddress + 0x8  */
        
        union {
            vuint32 R;
            struct {
                  vuint32:7;
                vuint32 SDFC:1;
                  vuint32:2;
                vuint32 SSEC:1;
                vuint32 SCEC:1;
                  vuint32:1;
                vuint32 SSOVFC:1;
                vuint32 SCOVFC:1;
                vuint32 SVRC:1;  
                  vuint32:7;
                vuint32 SDF:1;
                  vuint32:2;
                vuint32 SSE:1;
                vuint32 SCE:1;
                  vuint32:1;
                vuint32 SSOVF:1;
                vuint32 SCOVF:1;
                vuint32 SVR:1;    
            } B;
        } MXSR;                   /* Extended Status Register @baseaddress + 0xC  */       
        

        union {
            vuint32 R;
            struct {
                  vuint32:4;
                vuint32 INTAG:4;  
                  vuint32:6;
                vuint32 PREFILL:1;
                vuint32 FLUSH:1;
                vuint32 INPBUF:16;
            } B;
        } IB;                   /* Interface Input Buffer @baseaddress + 0x10  */

        union {
            vuint32 R;
            struct {
                vuint32:12;
                vuint32 OUTTAG:4;
                vuint32 OUTBUF:16;
            } B;
        } OB;                   /* Interface Output Buffer @baseaddress + 0x14  */

        uint32 decfil_reserved0018[2];        /* 0x0018 - 0x001F */

        union {
            vuint32 R;
            struct {
                vuint32:8;
                vuint32 COEF:24;
            } B;
        } COEF[9];              /* Filter Coefficient Registers @baseaddress + 0x20 - 0x40  */

        uint32 decfil_reserved0044[13];       /* 0x0044 - 0x0077 */

        union {
            vuint32 R;
            struct {
                vuint32:8;
                vuint32 TAP:24;
            } B;
        } TAP[8];               /* Filter TAP Registers @baseaddress + 0x78 - 0x94 */

        uint32 decfil_reserved00D0[14];       /* 0x00D0 - 0x00D3 */

        /* 0x0D0 */
        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 SAMP_DATA:16;
            } B;
        } EDID;                 /* Filter EDID Registers @baseaddress + 0xD0 */

        uint32 decfil_reserved00D4[3];    /* 0x00D4 - 0x00DF */

        union {
            vuint32 R;
            struct {
                vuint32 SUM_VALUE:32;
            } B;
        } FINTVAL;                   /* Final Integr. Value Register @baseaddress + 0xE0  */       

       union {
            vuint32 R;
            struct {
                vuint32 COUNT:32;
            } B;
        } FINTCNT;                   /* Final Integr. Count Register @baseaddress + 0xE0  */       

       union {
            vuint32 R;
            struct {
                vuint32 SUM_VALUE:32;
            } B;
        } CINTVAL;                   /* Current Integr. Value Register @baseaddress + 0xE0  */       

       union {
            vuint32 R;
            struct {
                vuint32 COUNT:32;
            } B;
        } CINTCNT;                   /* Current Integr. Count Register @baseaddress + 0xE0  */       

    };

/****************************************************************************/
/*                          MODULE : CRC                                   */
/****************************************************************************/
   struct CRCag {
        union {
            vuint32 R;
            struct {
                vuint32:29;
                vuint32 POLY:1;
                vuint32 SWAP:1;
                vuint32 INV:1;
            } B;
        } CFG;                      /* Configuration Register @baseaddress + 0x00 */

        union {
            vuint32 R;
            struct{
                vuint32 INP:32;
            } B;
        } INP;                      /* Input Register @baseaddress + 0x04 */

        union {
            vuint32 R;
            struct{
                vuint32 CSTAT:32;
            } B;
        } CSTAT;                    /* Current Status Register @baseaddress + 0x08 */

        union {
            vuint32 R;
            struct {
                vuint32 OUTP:32;
            } B;
        } OUTP;                     /* Output Register @baseaddress + 0x0C */
    };

/****************************************************************************/
/*                          MODULE : DSPI                                   */
/****************************************************************************/
    struct DSPIag {
        union {
            vuint32 R;
            struct {
                vuint32 MSTR:1;
                vuint32 CONT_SCKE:1;
                vuint32 DCONF:2;
                vuint32 FRZ:1;
                vuint32 MTFE:1;
                vuint32 PCSSE:1;
                vuint32 ROOE:1;
                vuint32 PCSIS7:1;
                vuint32 PCSIS6:1;
                vuint32 PCSIS5:1;
                vuint32 PCSIS4:1;
                vuint32 PCSIS3:1;
                vuint32 PCSIS2:1;
                vuint32 PCSIS1:1;
                vuint32 PCSIS0:1;
				  vuint32:1;
                vuint32 MDIS:1;
                vuint32 DISXF:1;
                vuint32 DIS_RXF:1;
                vuint32 CLRXF:1;
                vuint32 CLR_RXF:1;
                vuint32 SMPL_PT:2;
                  vuint32:6;
                vuint32 PES:1;  
                vuint32 HALT:1;
            } B;
        } MCR;                  /* Module Configuration Register @baseaddress + 0x00 */

        uint32 dspi_reserved0004;         /* 0x0004-0x008 */

        union {
            vuint32 R;
            struct {
                vuint32 TCNT:16;
                  vuint32:16;
            } B;
        } TCR;                  /* DSPI Transfer Count Register  @baseaddress + 0x08 */

        union {
            vuint32 R;
            struct {
                vuint32 DBR:1;
                vuint32 FMSZ:4;
                vuint32 CPOL:1;
                vuint32 CPHA:1;
                vuint32 LSBFE:1;
                vuint32 PCSSCK:2;
                vuint32 PASC:2;
                vuint32 PDT:2;
                vuint32 PBR:2;
                vuint32 CSSCK:4;
                vuint32 ASC:4;
                vuint32 DT:4;
                vuint32 BR:4;
            } B;
        } CTAR[8];              /* Clock and Transfer Attributes Registers @baseaddress + 0x0C - 0x28 */

        union {
            vuint32 R;
            struct {
                vuint32 TCF:1;
                vuint32 TXRXS:1;
                  vuint32:1;
                vuint32 EOQF:1;
                vuint32 TFUF:1;
                  vuint32:1;
                vuint32 TFFF:1;
                  vuint32:2;
                vuint32 DPEF:1;
                vuint32 SPEF:1;
                vuint32 DDIF:1;
                vuint32 RFOF:1;
                  vuint32:1;
                vuint32 RFDF:1;
                  vuint32:1;
                vuint32 TXCTR:4;
                vuint32 TXNXTPTR:4;
                vuint32 RXCTR:4;
                vuint32 POPNXTPTR:4;
            } B;
        } SR;                   /* Status Register @baseaddress + 0x2C */

        union {
            vuint32 R;
            struct {
                vuint32 TCFRE:1;
                  vuint32:2;
                vuint32 EOQFRE:1;
                vuint32 TFUFRE:1;
                  vuint32:1;
                vuint32 TFFFRE:1;
                vuint32 TFFFDIRS:1;
                  vuint32:1;
                vuint32 DPEFRE:1;
                vuint32 SPEFRE:1;
                vuint32 DDIFRE:1;  
                vuint32 RFOFRE:1;
                  vuint32:1;
                vuint32 RFDFRE:1;
                vuint32 RFDFDIRS:1;
                  vuint32:16;
            } B;
        } RSER;                 /* DMA/Interrupt Request Select and Enable Register @baseaddress + 0x30 */

        union {
            vuint32 R;
            struct {
                vuint32 CONT:1;
                vuint32 CTAS:3;
                vuint32 EOQ:1;
                vuint32 CTCNT:1;
                vuint32 PE:1;
                vuint32 PP:1;
                vuint32 PCS7:1;       /* new in MPC563xM */
                vuint32 PCS6:1;       /* new in MPC563xM */
                vuint32 PCS5:1;
                vuint32 PCS4:1;
                vuint32 PCS3:1;
                vuint32 PCS2:1;
                vuint32 PCS1:1;
                vuint32 PCS0:1;
                vuint32 TXDATA:16;
            } B;
        } PUSHR;                /* PUSH TX FIFO Register @baseaddress + 0x34 */

        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 RXDATA:16;
            } B;
        } POPR;                 /* POP RX FIFO Register @baseaddress + 0x38 */

        union {
            vuint32 R;
            struct {
                vuint32 TXCMD:16;
                vuint32 TXDATA:16;
            } B;
        } TXFR[4];              /* Transmit FIFO Registers @baseaddress + 0x3c - 0x78 */

        vuint32 DSPI_reserved_004C[12];   /* 0x004C-0x0078 */

        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 RXDATA:16;
            } B;
        } RXFR[4];              /* Transmit FIFO Registers @baseaddress + 0x7c - 0xB8 */

        vuint32 DSPI_reserved_008C[12];   /* 0x008C-0x00B8 */

        union {
            vuint32 R;
            struct {
                vuint32 MTOE:1;
                vuint32 FMSZ4:1;
                vuint32 MTOCNT:6;
                  vuint32:3;
                vuint32 TSBC:1;
                vuint32 TXSS:1;
                vuint32 TPOL:1;
                vuint32 TRRE:1;
                vuint32 CID:1;
                vuint32 DCONT:1;
                vuint32 DSICTAS:3;
                  vuint32:4;
                vuint32 DPCS7:1;
                vuint32 DPCS6:1;
                vuint32 DPCS5:1;
                vuint32 DPCS4:1;
                vuint32 DPCS3:1;
                vuint32 DPCS2:1;
                vuint32 DPCS1:1;
                vuint32 DPCS0:1;
            } B;
        } DSICR;                /* DSI Configuration Register @baseaddress + 0xBC */

        union {
            vuint32 R;
            struct {
                vuint32 SER_DATA:32;
            } B;
        } SDR;                  /* DSI Serialization Data Register @baseaddress + 0xC0 */

        union {
            vuint32 R;
            struct {
                vuint32 ASER_DATA:32;
            } B;
        } ASDR;                 /* DSI Alternate Serialization Data Register @baseaddress + 0xC4 */

        union {
            vuint32 R;
            struct {
                vuint32 COMP_DATA:32;
            } B;
        } COMPR;                /* DSI Transmit Comparison Register @baseaddress + 0xC8 */

        union {
            vuint32 R;
            struct {
                vuint32 DESER_DATA:32;
            } B;
        } DDR;                  /* DSI deserialization Data Register @baseaddress + 0xCC */

        union {
            vuint32 R;
            struct {
                vuint32:3;
                vuint32 TSBCNT:5;
                  vuint32:16;
                vuint32 DPCS1_7:1;
                vuint32 DPCS1_6:1;
                vuint32 DPCS1_5:1;
                vuint32 DPCS1_4:1;
                vuint32 DPCS1_3:1;
                vuint32 DPCS1_2:1;
                vuint32 DPCS1_1:1;
                vuint32 DPCS1_0:1;
            } B;
        } DSICR1;               /* DSI Configuration Register 1 @baseaddress + 0xD0 */

    };

/****************************************************************************/
/*                          MODULE : eSCI                                   */
/****************************************************************************/
    struct ESCIag {
        union {
            vuint32 R;
            struct {
                  vuint32:3;
                vuint32 SBR:13;
                vuint32 LOOPS:1;
                  vuint32:1;
                vuint32 RSRC:1;
                vuint32 M:1;
                vuint32 WAKE:1;
                vuint32 ILT:1;
                vuint32 PE:1;
                vuint32 PT:1;
                vuint32 TIE:1;
                vuint32 TCIE:1;
                vuint32 RIE:1;
                vuint32 ILIE:1;
                vuint32 TE:1;
                vuint32 RE:1;
                vuint32 RWU:1;
                vuint32 SBK:1;
            } B;
        } CR1;                  /* Control Register 1  @baseaddress + 0x00 */

        union {
            vuint16 R;
            struct {
                vuint16 MDIS:1;
                vuint16 FBR:1;
                vuint16 BSTP:1;
                vuint16 IEBERR:1;
                vuint16 RXDMA:1;
                vuint16 TXDMA:1;
                vuint16 BRK13:1;
                vuint16 TXDIR:1;
                vuint16 BESM13:1;
                vuint16 SBSTP:1;
                vuint16 RXPOL:1;
                vuint16 PMSK:1;
                vuint16 ORIE:1;
                vuint16 NFIE:1;
                vuint16 FEIE:1;
                vuint16 PFIE:1;
            } B;
        } CR2;                  /* Control Register 2 @baseaddress + 0x04 */

        union {
            vuint16 R;
            struct {
                vuint16 R8:1;
                vuint16 T8:1;
                vuint16 ERR:1;
                  vuint16:1;
                vuint16 R:4;
                vuint8 D;
            } B;
        } DR;                   /* Data Register @baseaddress + 0x06 */

        union {
            vuint32 R;
            struct {
                vuint32 TDRE:1;
                vuint32 TC:1;
                vuint32 RDRF:1;
                vuint32 IDLE:1;
                vuint32 OR:1;
                vuint32 NF:1;
                vuint32 FE:1;
                vuint32 PF:1;
                  vuint32:3;
                vuint32 BERR:1;
                  vuint32:2;
                vuint32 TACT:1;
                vuint32 RAF:1;
                vuint32 RXRDY:1;
                vuint32 TXRDY:1;
                vuint32 LWAKE:1;
                vuint32 STO:1;
                vuint32 PBERR:1;
                vuint32 CERR:1;
                vuint32 CKERR:1;
                vuint32 FRC:1;
                  vuint32:6;
                vuint32 UREQ:1;
                vuint32 OVFL:1;
            } B;
        } SR;                   /* Status Register   @baseaddress + 0x08 */

        union {
            vuint32 R;
            struct {
                vuint32 LRES:1;
                vuint32 WU:1;
                vuint32 WUD0:1;
                vuint32 WUD1:1;
                vuint32 LDBG:1;
                vuint32 DSF:1;
                vuint32 PRTY:1;
                vuint32 LIN:1;
                vuint32 RXIE:1;
                vuint32 TXIE:1;
                vuint32 WUIE:1;
                vuint32 STIE:1;
                vuint32 PBIE:1;
                vuint32 CIE:1;
                vuint32 CKIE:1;
                vuint32 FCIE:1;
                  vuint32:6;
                vuint32 UQIE:1;
                vuint32 OFIE:1;
                  vuint32:8;
            } B;
        } LCR;                  /* LIN Control Register @baseaddress + 0x0C  */

        union {
			vuint8 R;
			struct W1 {
				vuint8 P:2;
				vuint8 ID:6;
			} B1;
			struct W2 {
				vuint8 LEN:8;
			} B2;
			struct W3 {
				vuint8 CSM:1;
				vuint8 CSE:1;
				vuint8 CRC:1;
				vuint8 TD:1;
				vuint8 T0:4;
			} B3;
			struct W4 {
				vuint8 D:8;
			} B4;
		} LTR;					/* LIN Transmit Register @baseaddress + 0x10 */
    
		uint8 reserved0[3];
		
		union {
			vuint8 R;
			struct {
				vuint8 D:8;
			} B;
		} LRR;					/* LIN Receive Register @baseaddress + 0x14 */
		
		uint8 reserved1[3];
			
		union {
			vuint16 R;
			struct {
				vuint16 P:16;
			} B;
		} LPR;					/* LIN CRC Polynomial Register @baseaddress + 0x18 */

		union {
			vuint16 R;
			struct {
				vuint16:3;
				vuint16 SYNM:1;
				vuint16 EROE:1;
				vuint16 ERFE:1;
				vuint16 ERPE:1;
				vuint16 M2:1;
				vuint16:8;
			} B;
		} CR3;                  /* eSCI Control Register 3 @baseaddress + 0x1A */
    };
/****************************************************************************/
/*                          MODULE : eSCI                                   */
/****************************************************************************/
    struct ESCI_12_13_bitag {
        union {
            vuint16 R;
            struct {
                vuint16 R8:1;
                vuint16 T8:1;
                vuint16 ERR:1;
                  vuint16:1;
                vuint16 D:12;
            } B;
        } DR;                   /* Data Register */
    };

/****************************************************************************/
/*                          MODULE : FlexCAN                                */
/****************************************************************************/
    struct FLEXCAN_BUF {
        union {
            vuint32 R;
            struct {
                vuint32:4;
                vuint32 CODE:4;
                  vuint32:1;
                vuint32 SRR:1;
                vuint32 IDE:1;
                vuint32 RTR:1;
                vuint32 LENGTH:4;
                vuint32 TIMESTAMP:16;
            } B;
        } CS;

        union {
            vuint32 R;
            struct {
                vuint32 PRIO:3;
                vuint32 STD_ID:11;
                vuint32 EXT_ID:18;
            } B;
        } ID;

        union {
            /*vuint8  B[8]; *//* Data buffer in Bytes (8 bits) *//* Not used in MPC563xM */
            /*vuint16 H[4]; *//* Data buffer in Half-words (16 bits) *//* Not used in MPC563xM */
            vuint32 W[2];     /* Data buffer in words (32 bits) */
            /*vuint32 R[2]; *//* Data buffer in words (32 bits) *//* Not used in MPC563xM */
        } DATA;

    };                          /* end of FLEXCAN_BUF */

    struct FLEXCAN_RXFIFO {
        union {
            vuint32 R;
            struct {
                vuint32:9;
                vuint32 SRR:1;
                vuint32 IDE:1;
                vuint32 RTR:1;
                vuint32 LENGTH:4;
                vuint32 TIMESTAMP:16;
            } B;
        } CS;

        union {
            vuint32 R;
            struct {
                vuint32:3;
                vuint32 STD_ID:11;
                vuint32 EXT_ID:18;
            } B;
        } ID;

        union {
            /*vuint8  B[8]; *//* Data buffer in Bytes (8 bits) *//* Not used in MPC563xM */
            /*vuint16 H[4]; *//* Data buffer in Half-words (16 bits) *//* Not used in MPC563xM */
            vuint32 W[2];     /* Data buffer in words (32 bits) */
            /*vuint32 R[2]; *//* Data buffer in words (32 bits) *//* Not used in MPC563xM */
        } DATA;

        uint32 FLEXCAN_RXFIFO_reserved[20];   /* {0x00E0-0x0090}/0x4 = 0x14 */

        union {
            vuint32 R;
        } IDTABLE[8];

    };                          /* end of FLEXCAN_RXFIFO */

    struct FLEXCAN2ag {
        union {
            vuint32 R;
            struct {
                vuint32 MDIS:1;
                vuint32 FRZ:1;
                vuint32 FEN:1;
                vuint32 HALT:1;
                vuint32 NOTRDY:1;
                vuint32 WAK_MSK:1;
                vuint32 SOFTRST:1;
                vuint32 FRZACK:1;
                vuint32 SUPV:1;
                vuint32 SLF_WAK:1;

                vuint32 WRNEN:1;

                vuint32 MDISACK:1;
                vuint32 WAK_SRC:1;
                vuint32 DOZE:1;

                vuint32 SRXDIS:1;
                vuint32 MBFEN:1;
                  vuint32:2;

                vuint32 LPRIO_EN:1;
                vuint32 AEN:1;
                  vuint32:2;
                vuint32 IDAM:2;
                  vuint32:2;

                vuint32 MAXMB:6;
            } B;
        } MCR;                  /* Module Configuration Register @baseaddress + 0x00 */

        union {
            vuint32 R;
            struct {
                vuint32 PRESDIV:8;
                vuint32 RJW:2;
                vuint32 PSEG1:3;
                vuint32 PSEG2:3;
                vuint32 BOFFMSK:1;
                vuint32 ERRMSK:1;
                vuint32 CLKSRC:1;
                vuint32 LPB:1;
                vuint32 TWRNMSK:1;
                vuint32 RWRNMSK:1;
                  vuint32:2;
                vuint32 SMP:1;
                vuint32 BOFFREC:1;
                vuint32 TSYN:1;
                vuint32 LBUF:1;
                vuint32 LOM:1;
                vuint32 PROPSEG:3;
            } B;                /* Control Register @baseaddress + 0x04 */
        } CR;

        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 TIMER:16;
            } B;
        } TIMER;                /* Free Running Timer @baseaddress + 0x08 */

        sint32 FLEXCAN_reserved00;

        union {
            vuint32 R;
            struct {
                vuint32:3;
                vuint32 MI:29;
            } B;
        } RXGMASK;              /* RX Global Mask @baseaddress + 0x0C */

        union {
            vuint32 R;
            struct {
                vuint32:3;
                vuint32 MI:29;
            } B;
        } RX14MASK;             /* RX 14 Mask @baseaddress + 0x10 */

        union {
            vuint32 R;
            struct {
                vuint32:3;
                vuint32 MI:29;
            } B;
        } RX15MASK;             /* RX 15 Mask @baseaddress + 0x14 */

        union {
            vuint32 R;
            struct {
                vuint32:16;
                vuint32 RXECNT:8;
                vuint32 TXECNT:8;
            } B;
        } ECR;                  /* Error Counter Register @baseaddress + 0x18 */

        union {
            vuint32 R;
            struct {
                vuint32:14;
                vuint32 TWRNINT:1;
                vuint32 RWRNINT:1;
                vuint32 BIT1ERR:1;
                vuint32 BIT0ERR:1;
                vuint32 ACKERR:1;
                vuint32 CRCERR:1;
                vuint32 FRMERR:1;
                vuint32 STFERR:1;
                vuint32 TXWRN:1;
                vuint32 RXWRN:1;
                vuint32 IDLE:1;
                vuint32 TXRX:1;
                vuint32 FLTCONF:2;
                  vuint32:1;
                vuint32 BOFFINT:1;
                vuint32 ERRINT:1;
                vuint32 WAK_INT:1;
            } B;
        } ESR;                  /* Error and Status Register @baseaddress + 0x1C */

        union {
            vuint32 R;
            struct {
                vuint32 BUF63M:1;
                vuint32 BUF62M:1;
                vuint32 BUF61M:1;
                vuint32 BUF60M:1;
                vuint32 BUF59M:1;
                vuint32 BUF58M:1;
                vuint32 BUF57M:1;
                vuint32 BUF56M:1;
                vuint32 BUF55M:1;
                vuint32 BUF54M:1;
                vuint32 BUF53M:1;
                vuint32 BUF52M:1;
                vuint32 BUF51M:1;
                vuint32 BUF50M:1;
                vuint32 BUF49M:1;
                vuint32 BUF48M:1;
                vuint32 BUF47M:1;
                vuint32 BUF46M:1;
                vuint32 BUF45M:1;
                vuint32 BUF44M:1;
                vuint32 BUF43M:1;
                vuint32 BUF42M:1;
                vuint32 BUF41M:1;
                vuint32 BUF40M:1;
                vuint32 BUF39M:1;
                vuint32 BUF38M:1;
                vuint32 BUF37M:1;
                vuint32 BUF36M:1;
                vuint32 BUF35M:1;
                vuint32 BUF34M:1;
                vuint32 BUF33M:1;
                vuint32 BUF32M:1;
            } B;                /* Interruput Masks Register @baseaddress + 0x20 */
        } IMRH;

        union {
            vuint32 R;
            struct {
                vuint32 BUF31M:1;
                vuint32 BUF30M:1;
                vuint32 BUF29M:1;
                vuint32 BUF28M:1;
                vuint32 BUF27M:1;
                vuint32 BUF26M:1;
                vuint32 BUF25M:1;
                vuint32 BUF24M:1;
                vuint32 BUF23M:1;
                vuint32 BUF22M:1;
                vuint32 BUF21M:1;
                vuint32 BUF20M:1;
                vuint32 BUF19M:1;
                vuint32 BUF18M:1;
                vuint32 BUF17M:1;
                vuint32 BUF16M:1;
                vuint32 BUF15M:1;
                vuint32 BUF14M:1;
                vuint32 BUF13M:1;
                vuint32 BUF12M:1;
                vuint32 BUF11M:1;
                vuint32 BUF10M:1;
                vuint32 BUF09M:1;
                vuint32 BUF08M:1;
                vuint32 BUF07M:1;
                vuint32 BUF06M:1;
                vuint32 BUF05M:1;
                vuint32 BUF04M:1;
                vuint32 BUF03M:1;
                vuint32 BUF02M:1;
                vuint32 BUF01M:1;
                vuint32 BUF00M:1;
            } B;                /* Interruput Masks Register @baseaddress + 0x24 */
        } IMRL;

        union {
            vuint32 R;
            struct {
                vuint32 BUF63I:1;
                vuint32 BUF62I:1;
                vuint32 BUF61I:1;
                vuint32 BUF60I:1;
                vuint32 BUF59I:1;
                vuint32 BUF58I:1;
                vuint32 BUF57I:1;
                vuint32 BUF56I:1;
                vuint32 BUF55I:1;
                vuint32 BUF54I:1;
                vuint32 BUF53I:1;
                vuint32 BUF52I:1;
                vuint32 BUF51I:1;
                vuint32 BUF50I:1;
                vuint32 BUF49I:1;
                vuint32 BUF48I:1;
                vuint32 BUF47I:1;
                vuint32 BUF46I:1;
                vuint32 BUF45I:1;
                vuint32 BUF44I:1;
                vuint32 BUF43I:1;
                vuint32 BUF42I:1;
                vuint32 BUF41I:1;
                vuint32 BUF40I:1;
                vuint32 BUF39I:1;
                vuint32 BUF38I:1;
                vuint32 BUF37I:1;
                vuint32 BUF36I:1;
                vuint32 BUF35I:1;
                vuint32 BUF34I:1;
                vuint32 BUF33I:1;
                vuint32 BUF32I:1;
            } B;                /* Interruput Flag Register @baseaddress + 0x28 */
        } IFRH;

        union {
            vuint32 R;
            struct {
                vuint32 BUF31I:1;
                vuint32 BUF30I:1;
                vuint32 BUF29I:1;
                vuint32 BUF28I:1;
                vuint32 BUF27I:1;
                vuint32 BUF26I:1;
                vuint32 BUF25I:1;
                vuint32 BUF24I:1;
                vuint32 BUF23I:1;
                vuint32 BUF22I:1;
                vuint32 BUF21I:1;
                vuint32 BUF20I:1;
                vuint32 BUF19I:1;
                vuint32 BUF18I:1;
                vuint32 BUF17I:1;
                vuint32 BUF16I:1;
                vuint32 BUF15I:1;
                vuint32 BUF14I:1;
                vuint32 BUF13I:1;
                vuint32 BUF12I:1;
                vuint32 BUF11I:1;
                vuint32 BUF10I:1;
                vuint32 BUF09I:1;
                vuint32 BUF08I:1;
                vuint32 BUF07I:1;
                vuint32 BUF06I:1;
                vuint32 BUF05I:1;
                vuint32 BUF04I:1;
                vuint32 BUF03I:1;
                vuint32 BUF02I:1;
                vuint32 BUF01I:1;
                vuint32 BUF00I:1;
            } B;                /* Interruput Flag Register @baseaddress + 0x2C */
        } IFRL;

        uint32 flexcan2_reserved2[19];

/****************************************************************************/
/* Use either Standard Buffer Structure OR RX FIFO and Buffer Structure     */
/****************************************************************************/
        /* Standard Buffer Structure */
        struct FLEXCAN_BUF BUF[64];

        /* RX FIFO and Buffer Structure */
        /*struct FLEXCAN_RXFIFO RXFIFO; */
        /*struct FLEXCAN_BUF BUF[56];   */
/****************************************************************************/

        uint32 FLEXCAN_reserved3[256];        /* {0x0880-0x0480}/0x4 = 0x100 */

        union {
            vuint32 R;
            struct {
                vuint32 MI:32;
            } B;                /* RX Individual Mask Registers @baseaddress + 0x0880 */
        } RXIMR[64];

    };                          /* end of FLEXCANag */

/****************************************************************************/
/*                     MODULE : Periodic Interval Timer (PIT)               */
/****************************************************************************/
    struct PITag {

        union {
            vuint32 R;
            struct {
                vuint32:29;
                vuint32 MDIS_RTI:1;
                vuint32 MDIS:1;
                vuint32 FRZ:1;
            } B;
        } PITMCR;               /* PIT Module Control Register @baseaddress + 0x00 */

        uint32 pit_reserved1[59];

        struct {
            union {
                vuint32 R;
            } LDVAL;            /* Timer Load Value Register @baseaddress + 0xF0 */

            union {
                vuint32 R;
            } CVAL;             /* Current Timer Value Register @baseaddress + 0xF4 */

            union {
                vuint32 R;
                struct {
                    vuint32:30;
                    vuint32 TIE:1;
                    vuint32 TEN:1;
                } B;
            } TCTRL;            /* Timer Control Register @baseaddress + 0xF8 */

            union {
                vuint32 R;
                struct {
                    vuint32:31;
                    vuint32 TIF:1;
                } B;
            } TFLG;             /* Timer Flag Register */
        } RTI;                  /* RTI Channel @baseaddress + 0xFC */

        struct {
            union {
                vuint32 R;
            } LDVAL;            /* Timer Load Value Register @baseaddress + CH + 0x0 */

            union {
                vuint32 R;
            } CVAL;             /* Current Timer Value Register @baseaddress + CH + 0x4 */

            union {
                vuint32 R;
                struct {
                    vuint32:30;
                    vuint32 TIE:1;
                    vuint32 TEN:1;
                } B;
            } TCTRL;            /* Timer Control Register @baseaddress + CH + 0x8 */

            union {
                vuint32 R;
                struct {
                    vuint32:31;
                    vuint32 TIF:1;
                } B;
            } TFLG;             /* Timer Flag Register @baseaddress + CH + 0xC */
        } TIMER[4];             /* Timer Channels @baseaddress + 0x100 */

    };

/****************************************************************************/
/*                          MODULE : FlexRay                                */
/****************************************************************************/

    typedef union uMVR {
        vuint16 R;
        struct {
            vuint16 CHIVER:8; /* CHI Version Number */
            vuint16 PEVER:8;  /* PE Version Number */
        } B;
    } MVR;

    typedef union uMCR {
        vuint16 R;
        struct {
            vuint16 MEN:1;    /* module enable */
            vuint16 SBFF:1;   /* system bus failure freeze */
            vuint16 SCM:1;    /* single channel device mode */
            vuint16 CHB:1;    /* channel B enable */
            vuint16 CHA:1;    /* channel A enable */
            vuint16 SFFE:1;   /* synchronization frame filter enable */
            vuint16 ECCE:1;   /* ECC functionality enable */
			 vuint16:1;
			vuint16 FUM:1;    /* FIFO update mode */
			vuint16 FAM:1;    /* FIFO address mode */
             vuint16:1;
			vuint16 CLKSEL:1; /* protocol engine clock source select */
            vuint16 BITRATE:3;/* flexray bus bit rate */
              vuint16:1;
        } B;
    } MCR;
	
	typedef union uSYMBADHR {
        vuint16 R;
        struct {
            vuint16 SMBA:16;  /* system memory base addess high */
        } B;
    } SYMBADHR;
	
	typedef union uSYMBADLR {
        vuint16 R;
        struct {
            vuint16 SMBA:12;  /* system memory base addess high */
			 vuint16:4;  
        } B;
    } SYMBADLR;

    typedef union uSTBSCR {
        vuint16 R;
        struct {
            vuint16 WMD:1;    /* write mode */
              vuint16:3;
            vuint16 STBSSEL:4;        /* strobe signal select */
              vuint16:3;
            vuint16 ENB:1;    /* strobe signal enable */
              vuint16:2;
            vuint16 STBPSEL:2;        /* strobe port select */
        } B;
    } STBSCR;
	
    typedef union uMBDSR {
        vuint16 R;
        struct {
            vuint16:1;
            vuint16 MBSEG2DS:7;       /* message buffer segment 2 data size */
              vuint16:1;
            vuint16 MBSEG1DS:7;       /* message buffer segment 1 data size */
        } B;
    } MBDSR;
    
	typedef union uMBSSUTR {
        vuint16 R;
        struct {
            vuint16:1;
            vuint16 LAST_MB_SEG1:7;   /* last message buffer control register for message buffer segment 1 */
              vuint16:1;
            vuint16 LAST_MB_UTIL:7;   /* last message buffer utilized */
        } B;
    } MBSSUTR;
	
	typedef union uPEDRAR {
        vuint16 R;
        struct {
            vuint16 INST:4;    /* PE DRAM access instruction */
            vuint16 ADDR:11;   /* PE DRAM access address */
            vuint16 DAD:1;     /* PE DRAM access done */
		} B;
    } PEDRAR;
	
	typedef union uPEDRDR {
        vuint16 R;
        struct {
            vuint16 DATA:16;    /* PE DRAM access instruction */
        } B;
    } PEDRDR;

    typedef union uPOCR {
        vuint16 R;
        struct {
            vuint16 WME:1;    /* write mode external correction command */
              vuint16:3;
            vuint16 EOC_AP:2; /* external offset correction application */
            vuint16 ERC_AP:2; /* external rate correction application */
            vuint16 BSY:1;    /* command write busy / write mode command */
              vuint16:3;
            vuint16 POCCMD:4; /* protocol command */
        } B;
    } POCR;
	
    typedef union uGIFER {
        vuint16 R;
        struct {
            vuint16 MIF:1;    /* module interrupt flag */
            vuint16 PRIF:1;   /* protocol interrupt flag */
            vuint16 CHIF:1;   /* CHI interrupt flag */
            vuint16 WKUPIF:1; /* wakeup interrupt flag */
            vuint16 FNEBIF:1; /* receive FIFO channel B not empty interrupt flag */
            vuint16 FNEAIF:1; /* receive FIFO channel A not empty interrupt flag */
            vuint16 RBIF:1;   /* receive message buffer interrupt flag */
            vuint16 TBIF:1;   /* transmit buffer interrupt flag */
            vuint16 MIE:1;    /* module interrupt enable */
            vuint16 PRIE:1;   /* protocol interrupt enable */
            vuint16 CHIE:1;   /* CHI interrupt enable */
            vuint16 WKUPIE:1; /* wakeup interrupt enable */
            vuint16 FNEBIE:1; /* receive FIFO channel B not empty interrupt enable */
            vuint16 FNEAIE:1; /* receive FIFO channel A not empty interrupt enable */
            vuint16 RBIE:1;   /* receive message buffer interrupt enable */
            vuint16 TBIE:1;   /* transmit buffer interrupt enable */
        } B;
    } GIFER;
    typedef union uPIFR0 {
        vuint16 R;
        struct {
            vuint16 FATLIF:1; /* fatal protocol error interrupt flag */
            vuint16 INTLIF:1; /* internal protocol error interrupt flag */
            vuint16 ILCFIF:1; /* illegal protocol configuration flag */
            vuint16 CSAIF:1;  /* cold start abort interrupt flag */
            vuint16 MRCIF:1;  /* missing rate correctio interrupt flag */
            vuint16 MOCIF:1;  /* missing offset correctio interrupt flag */
            vuint16 CCLIF:1;  /* clock correction limit reached interrupt flag */
            vuint16 MXSIF:1;  /* max sync frames detected interrupt flag */
            vuint16 MTXIF:1;  /* media access test symbol received flag */
            vuint16 LTXBIF:1; /* pdLatestTx violation on channel B interrupt flag */
            vuint16 LTXAIF:1; /* pdLatestTx violation on channel A interrupt flag */
            vuint16 TBVBIF:1; /* Transmission across boundary on channel B Interrupt Flag */
            vuint16 TBVAIF:1; /* Transmission across boundary on channel A Interrupt Flag */
            vuint16 TI2IF:1;  /* timer 2 expired interrupt flag */
            vuint16 TI1IF:1;  /* timer 1 expired interrupt flag */
            vuint16 CYSIF:1;  /* cycle start interrupt flag */
        } B;
    } PIFR0;

    typedef union uPIFR1 {
        vuint16 R;
        struct {
            vuint16 EMCIF:1;  /* error mode changed interrupt flag */
            vuint16 IPCIF:1;  /* illegal protocol command interrupt flag */
            vuint16 PECFIF:1; /* protocol engine communication failure interrupt flag */
            vuint16 PSCIF:1;  /* Protocol State Changed Interrupt Flag */
            vuint16 SSI3IF:1; /* slot status counter incremented interrupt flag */
            vuint16 SSI2IF:1; /* slot status counter incremented interrupt flag */
            vuint16 SSI1IF:1; /* slot status counter incremented interrupt flag */
            vuint16 SSI0IF:1; /* slot status counter incremented interrupt flag */
              vuint16:2;
            vuint16 EVTIF:1;  /* even cycle table written interrupt flag */
            vuint16 ODTIF:1;  /* odd cycle table written interrupt flag */
              vuint16:4;
        } B;
    } PIFR1;
	
    typedef union uPIER0 {
        vuint16 R;
        struct {
            vuint16 FATLIE:1; /* fatal protocol error interrupt enable */
            vuint16 INTLIE:1; /* internal protocol error interrupt interrupt enable  */
            vuint16 ILCFIE:1; /* illegal protocol configuration interrupt enable */
            vuint16 CSAIE:1;  /* cold start abort interrupt enable */
            vuint16 MRCIE:1;  /* missing rate correctio interrupt enable */
            vuint16 MOCIE:1;  /* missing offset correctio interrupt enable */
            vuint16 CCLIE:1;  /* clock correction limit reached interrupt enable */
            vuint16 MXSIE:1;  /* max sync frames detected interrupt enable */
            vuint16 MTXIE:1;  /* media access test symbol received interrupt enable */
            vuint16 LTXBIE:1; /* pdLatestTx violation on channel B interrupt enable */
            vuint16 LTXAIE:1; /* pdLatestTx violation on channel A interrupt enable */
            vuint16 TBVBIE:1; /* Transmission across boundary on channel B Interrupt enable */
            vuint16 TBVAIE:1; /* Transmission across boundary on channel A Interrupt enable */
            vuint16 TI2IE:1;  /* timer 2 expired interrupt enable */
            vuint16 TI1IE:1;  /* timer 1 expired interrupt enable */
            vuint16 CYSIE:1;  /* cycle start interrupt enable */
        } B;
    } PIER0;
	
    typedef union uPIER1 {
        vuint16 R;
        struct {
            vuint16 EMCIE:1;  /* error mode changed interrupt enable */
            vuint16 IPCIE:1;  /* illegal protocol command interrupt enable */
            vuint16 PECFIE:1; /* protocol engine communication failure interrupt enable */
            vuint16 PSCIE:1;  /* Protocol State Changed Interrupt enable */
            vuint16 SSI3IE:1; /* slot status counter incremented interrupt enable */
            vuint16 SSI2IE:1; /* slot status counter incremented interrupt enable */
            vuint16 SSI1IE:1; /* slot status counter incremented interrupt enable */
            vuint16 SSI0IE:1; /* slot status counter incremented interrupt enable */
              vuint16:2;
            vuint16 EVTIE:1;  /* even cycle table written interrupt enable */
            vuint16 ODTIE:1;  /* odd cycle table written interrupt enable */
              vuint16:4;
        } B;
    } PIER1;
	
    typedef union uCHIERFR {
        vuint16 R;
        struct {
            vuint16 FRLBEF:1; /* flame lost channel B error flag */
            vuint16 FRLAEF:1; /* frame lost channel A error flag */
            vuint16 PCMIEF:1; /* command ignored error flag */
            vuint16 FOVBEF:1; /* receive FIFO overrun channel B error flag */
            vuint16 FOVAEF:1; /* receive FIFO overrun channel A error flag */
            vuint16 MSBEF:1;  /* message buffer search error flag */
            vuint16 MBUEF:1;  /* message buffer utilization error flag */
            vuint16 LCKEF:1;  /* lock error flag */
            vuint16 DBLEF:1;  /* double transmit message buffer lock error flag */
            vuint16 SBCFEF:1; /* system bus communication failure error flag */
            vuint16 FIDEF:1;  /* frame ID error flag */
            vuint16 DPLEF:1;  /* dynamic payload length error flag */
            vuint16 SPLEF:1;  /* static payload length error flag */
            vuint16 NMLEF:1;  /* network management length error flag */
            vuint16 NMFEF:1;  /* network management frame error flag */
            vuint16 ILSAEF:1; /* illegal access error flag */
        } B;
    } CHIERFR;
	
    typedef union uMBIVEC {
        vuint16 R;
        struct {
            vuint16:1;
            vuint16 TBIVEC:7; /* transmit buffer interrupt vector */
              vuint16:1;
            vuint16 RBIVEC:7; /* receive buffer interrupt vector */
        } B;
    } MBIVEC;
	
	typedef union uCASERCR {
        vuint16 R;
        struct {
            vuint16 STATUSERRCNT:16; /* channel status error counter */
        } B;
    } CASERCR;
	
	typedef union uCBSERCR {
        vuint16 R;
        struct {
            vuint16 STATUSERRCNT:16; /* channel status error counter */
        } B;
    } CBSERCR;

    typedef union uPSR0 {
        vuint16 R;
        struct {
            vuint16 ERRMODE:2;        /* error mode */
            vuint16 SLOTMODE:2;       /* slot mode */
              vuint16:1;
            vuint16 PROTSTATE:3;      /* protocol state */
            vuint16 SUBSTATE:4;       /* protocol sub state */
              vuint16:1;
            vuint16 WAKEUPSTATUS:3;   /* wakeup status */
        } B;
    } PSR0;

/* protocol states */
/* protocol sub-states */
/* wakeup status */
    typedef union uPSR1 {
        vuint16 R;
        struct {
            vuint16 CSAA:1;   /* cold start attempt abort flag */
            vuint16 CSP:1;    /* cold start path */
              vuint16:1;
            vuint16 REMCSAT:5;        /* remanining coldstart attempts */
            vuint16 CPN:1;    /* cold start noise path */
            vuint16 HHR:1;    /* host halt request pending */
            vuint16 FRZ:1;    /* freeze occured */
            vuint16 APTAC:5;  /* allow passive to active counter */
        } B;
    } PSR1;
	
    typedef union uPSR2 {
        vuint16 R;
        struct {
            vuint16 NBVB:1;   /* NIT boundary violation on channel B */
            vuint16 NSEB:1;   /* NIT syntax error on channel B */
            vuint16 STCB:1;   /* symbol window transmit conflict on channel B */
            vuint16 SBVB:1;   /* symbol window boundary violation on channel B */
            vuint16 SSEB:1;   /* symbol window syntax error on channel B */
            vuint16 MTB:1;    /* media access test symbol MTS received on channel B */
            vuint16 NBVA:1;   /* NIT boundary violation on channel A */
            vuint16 NSEA:1;   /* NIT syntax error on channel A */
            vuint16 STCA:1;   /* symbol window transmit conflict on channel A */
            vuint16 SBVA:1;   /* symbol window boundary violation on channel A */
            vuint16 SSEA:1;   /* symbol window syntax error on channel A */
            vuint16 MTA:1;    /* media access test symbol MTS received on channel A */
            vuint16 CLKCORRFAILCNT:4; /* clock correction failed counter */
        } B;
    } PSR2;
	
    typedef union uPSR3 {
        vuint16 R;
        struct {
            vuint16:2;
            vuint16 WUB:1;    /* wakeup symbol received on channel B */
            vuint16 ABVB:1;   /* aggregated boundary violation on channel B */
            vuint16 AACB:1;   /* aggregated additional communication on channel B */
            vuint16 ACEB:1;   /* aggregated content error on channel B */
            vuint16 ASEB:1;   /* aggregated syntax error on channel B */
            vuint16 AVFB:1;   /* aggregated valid frame on channel B */
              vuint16:2;
            vuint16 WUA:1;    /* wakeup symbol received on channel A */
            vuint16 ABVA:1;   /* aggregated boundary violation on channel A */
            vuint16 AACA:1;   /* aggregated additional communication on channel A */
            vuint16 ACEA:1;   /* aggregated content error on channel A */
            vuint16 ASEA:1;   /* aggregated syntax error on channel A */
            vuint16 AVFA:1;   /* aggregated valid frame on channel A */
        } B;
    } PSR3;
	
	typedef union uMTCTR {
        vuint16 R;
        struct {
            vuint16 MTCT:16; /* macrotick counter */
        } B;
    } MTCTR;
	
	typedef union uCYCTR {
        vuint16 R;
        struct {
             vuint16 :10; 
			vuint16 CYCCNT:6; /* cycle counter */
        } B;
    } CYCTR;
	
	typedef union uSLTCTAR {
        vuint16 R;
        struct {
             vuint16 :5; 
			vuint16 SLOTCNTA:11; /* slot counter value for channel A */
        } B;
    } SLTCTAR;
	
	typedef union uSLTCTBR {
        vuint16 R;
        struct {
             vuint16 :5; 
			vuint16 SLOTCNTB:11; /* slot counter value for channel B */
        } B;
    } SLTCTBR;
	
	typedef union uRTCORVR {
        vuint16 R;
        struct {
            vuint16 RATECORR:16; /* rate correction value */
        } B;
    } RTCORVR;
	
	typedef union uOFCORVR {
        vuint16 R;
        struct {
            vuint16 OFFSETCORR:16; /* offset correction value */
        } B;
    } OFCORVR;
	
    typedef union uCIFR {
        vuint16 R;
        struct {
            vuint16:8;
            vuint16 MIFR:1;   /* module interrupt flag */
            vuint16 PRIFR:1;  /* protocol interrupt flag */
            vuint16 CHIFR:1;  /* CHI interrupt flag */
            vuint16 WUPIFR:1; /* wakeup interrupt flag */
            vuint16 FNEBIFR:1;        /* receive fifo channel B no empty interrupt flag */
            vuint16 FNEAIFR:1;        /* receive fifo channel A no empty interrupt flag */
            vuint16 RBIFR:1;  /* receive message buffer interrupt flag */
            vuint16 TBIFR:1;  /* transmit buffer interrupt flag */
        } B;
    } CIFR;
	
	typedef union uSYMATOR {
        vuint16 R;
        struct {
             vuint16 :8; 
			vuint16 TIMEOUT:8; /* system memory access timeout */
        } B;
    } SYMATOR;
	
    typedef union uSFCNTR {
        vuint16 R;
        struct {
            vuint16 SFEVB:4;  /* sync frames channel B, even cycle */
            vuint16 SFEVA:4;  /* sync frames channel A, even cycle */
            vuint16 SFODB:4;  /* sync frames channel B, odd cycle */
            vuint16 SFODA:4;  /* sync frames channel A, odd cycle */
        } B;
    } SFCNTR;
	
	typedef union uSFTOR {
        vuint16 R;
        struct {
             vuint16 SFTOFFSET:15; /* synch frame table offset */
			vuint16 :1; 
        } B;
    } SFTOR;

    typedef union uSFTCCSR {
        vuint16 R;
        struct {
            vuint16 ELKT:1;   /* even cycle tables lock and unlock trigger */
            vuint16 OLKT:1;   /* odd cycle tables lock and unlock trigger */
            vuint16 CYCNUM:6; /* cycle number */
            vuint16 ELKS:1;   /* even cycle tables lock status */
            vuint16 OLKS:1;   /* odd cycle tables lock status */
            vuint16 EVAL:1;   /* even cycle tables valid */
            vuint16 OVAL:1;   /* odd cycle tables valid */
              vuint16:1;
            vuint16 OPT:1;    /*one pair trigger */
            vuint16 SDVEN:1;  /* sync frame deviation table enable */
            vuint16 SIDEN:1;  /* sync frame ID table enable */
        } B;
    } SFTCCSR;
	
    typedef union uSFIDRFR {
        vuint16 R;
        struct {
            vuint16:6;
            vuint16 SYNFRID:10;       /* sync frame rejection ID */
        } B;
    } SFIDRFR;
	
	typedef union uSFIDAFVR {
        vuint16 R;
        struct {
            vuint16:6;
            vuint16 FVAL:10;       /* filter value */
        } B;
    } SFIDAFVR;
	
	typedef union uSFIDAFMR {
        vuint16 R;
        struct {
            vuint16:6;
            vuint16 FMSK:10;       /* filter mask */
        } B;
    } SFIDAFMR;
	
	typedef union uNMVR {
        vuint16 R;
        struct {
            vuint16 NMVP:16;
        } B;
    } NMVR;
	
	typedef union uNMVLR {
        vuint16 R;
        struct {
              vuint16:12;
			vuint16 NMVL:4;
        } B;
    } NMVLR;
	
	typedef union uTICCR {
        vuint16 R;
        struct {
            vuint16:2;
            vuint16 T2CFG:1;  /* timer 2 configuration */
            vuint16 T2REP:1;  /* timer 2 repetitive mode */
              vuint16:1;
            vuint16 T2SP:1;   /* timer 2 stop */
            vuint16 T2TR:1;   /* timer 2 trigger */
            vuint16 T2ST:1;   /* timer 2 state */
              vuint16:3;
            vuint16 T1REP:1;  /* timer 1 repetitive mode */
              vuint16:1;
            vuint16 T1SP:1;   /* timer 1 stop */
            vuint16 T1TR:1;   /* timer 1 trigger */
            vuint16 T1ST:1;   /* timer 1 state */

        } B;
    } TICCR;
	
    typedef union uTI1CYSR {
        vuint16 R;
        struct {
            vuint16:2;
            vuint16 TI1CYCVAL:6;      /* timer 1 cycle filter value */
              vuint16:2;
            vuint16 TI1CYCMSK:6;      /* timer 1 cycle filter mask */
        } B;
    } TI1CYSR;
	
	typedef union uTI1MTOR {
        vuint16 R;
        struct {
            vuint16:2;
            vuint16 TI1MTOFFSET:14;      /* timer 1 macrotick offset */
        } B;
    } TI1MTOR;
	
	typedef union uTI2CR0 {
        vuint16 R;
        struct {
            vuint16 TI2MTCNT:16;      /* timer 2 macrotick high word */
        } B;
    } TI2CR0;
	
	typedef union uTI2CR1 {
        vuint16 R;
        struct {
            vuint16 TI2MTCNT:16;      /* timer 2 macrotick low word */
        } B;
    } TI2CR1;

    typedef union uSSSR {
        vuint16 R;
        struct {
            vuint16 WMD:1;    /* write mode */
              vuint16:1;
            vuint16 SEL:2;    /* static slot number */
              vuint16:1;
            vuint16 SLOTNUMBER:11;    /* selector */
        } B;
    } SSSR;

    typedef union uSSCCR {
        vuint16 R;
        struct {
            vuint16 WMD:1;    /* write mode */
              vuint16:1;
            vuint16 SEL:2;    /* selector */
              vuint16:1;
            vuint16 CNTCFG:2; /* counter configuration */
            vuint16 MCY:1;    /* multi cycle selection */
            vuint16 VFR:1;    /* valid frame selection */
            vuint16 SYF:1;    /* sync frame selection */
            vuint16 NUF:1;    /* null frame selection  */
            vuint16 SUF:1;    /* startup frame selection */
            vuint16 STATUSMASK:4;     /* slot status mask */
        } B;
    } SSCCR;
	
    typedef union uSSR {
        vuint16 R;
        struct {
            vuint16 VFB:1;    /* valid frame on channel B */
            vuint16 SYB:1;    /* valid sync frame on channel B */
            vuint16 NFB:1;    /* valid null frame on channel B */
            vuint16 SUB:1;    /* valid startup frame on channel B */
            vuint16 SEB:1;    /* syntax error on channel B */
            vuint16 CEB:1;    /* content error on channel B */
            vuint16 BVB:1;    /* boundary violation on channel B */
            vuint16 TCB:1;    /* tx conflict on channel B */
            vuint16 VFA:1;    /* valid frame on channel A */
            vuint16 SYA:1;    /* valid sync frame on channel A */
            vuint16 NFA:1;    /* valid null frame on channel A */
            vuint16 SUA:1;    /* valid startup frame on channel A */
            vuint16 SEA:1;    /* syntax error on channel A */
            vuint16 CEA:1;    /* content error on channel A */
            vuint16 BVA:1;    /* boundary violation on channel A */
            vuint16 TCA:1;    /* tx conflict on channel A */
        } B;
    } SSR;
	
	typedef union uSSCR {
        vuint16 R;
        struct {
            vuint16 SLOTSTATUSCNT:16;      /* slot status counter */
        } B;
    } SSCR;
	
	typedef union uMTSACFR {
        vuint16 R;
        struct {
            vuint16 MTE:1;    /* media access test symbol transmission enable */
              vuint16:1;
            vuint16 CYCCNTMSK:6;      /* cycle counter mask */
              vuint16:2;
            vuint16 CYCCNTVAL:6;      /* cycle counter value */
        } B;
    } MTSACFR;
	
	typedef union uMTSBCFR {
        vuint16 R;
        struct {
            vuint16 MTE:1;    /* media access test symbol transmission enable */
              vuint16:1;
            vuint16 CYCCNTMSK:6;      /* cycle counter mask */
              vuint16:2;
            vuint16 CYCCNTVAL:6;      /* cycle counter value */
        } B;
    } MTSBCFR;
	
    typedef union uRSBIR {
        vuint16 R;
        struct {
            vuint16 WMD:1;    /* write mode */
              vuint16:1;
            vuint16 SEL:2;    /* selector */
              vuint16:4;
            vuint16 RSBIDX:8; /* receive shadow buffer index */
        } B;
    } RSBIR;
	
	typedef union uRFSYMBADHR {
        vuint16 R;
        struct {
            vuint16 SMBA:16;    /* systen memory base address */
        } B;
    } RFSYMBADHR;
	
	typedef union uRFSYMBADLR {
        vuint16 R;
        struct {
            vuint16 SMBA:12;    /* systen memory base address */
			  vuint16:4;
        } B;
    } RFSYMBADLR;
	
	typedef union uRFPTR {
        vuint16 R;
        struct {
              vuint16:2;
            vuint16 PTD:14;      /* periodic timer duration */
        } B;
    } RFPTR;
	
	typedef union uRFWMSR {
        vuint16 R;
        struct {
            vuint16 WM:8;      /* watermark */
              vuint16:7;
            vuint16 SEL:1;      /* select */
        } B;
    } RFWMSR;
	
	typedef union uRFSIR {
        vuint16 R;
        struct {
              vuint16:6;
            vuint16 SIDX:10;      /* start index */
        } B;
    } RFSIR;
	
    typedef union uRFDSR {
        vuint16 R;
        struct {
            vuint16 FIFODEPTH:8;      /* fifo depth */
              vuint16:1;
            vuint16 ENTRYSIZE:7;      /* entry size */
        } B;
    } RFDSR;
	
	typedef union uRFARIR {
        vuint16 R;
        struct {
              vuint16:6;
            vuint16 RDIDX:10;      /* read index */
        } B;
    } RFARIR;
	
	typedef union uRFBRIR {
        vuint16 R;
        struct {
              vuint16:6;
            vuint16 RDIDX:10;      /* read index */
        } B;
    } RFBRIR;
	
	typedef union uRFFLPCR {
        vuint16 R;
        struct {
            vuint16 PCB:8;      /* pop count FIFO B */
            vuint16 PCA:8;      /* pop count FIFO A */
        } B;
    } RFFLPCR;

    typedef union uRFMIDAFVR {
        vuint16 R;
        struct {
            vuint16 MIDAFVAL:16;      /* message ID acceptance filter */
        } B;
    } RFMIDAFVR;
	
	typedef union uRFMIDAFMR {
        vuint16 R;
        struct {
            vuint16 MIDAFMSK:16;      /* message ID acceptance filter mask */
        } B;
    } RFMIDAFMR;
	
	typedef union uRFFIDRFVR {
        vuint16 R;
        struct {
              vuint16:5;
            vuint16 FIDRFVAL:11;      /* frame ID rejection filter value */
        } B;
    } RFFIDRFVR;
	
	typedef union uRFFIDRFMR {
        vuint16 R;
        struct {
              vuint16:5;
            vuint16 FIDRFMSK:11;      /* frame ID rejection filter mask */
        } B;
    } RFFIDRFMR;
	
	typedef union uRFRFCFR {
        vuint16 R;
        struct {
            vuint16 WMD:1;    /* write mode */
            vuint16 IBD:1;    /* interval boundary */
            vuint16 SEL:2;    /* filter number */
              vuint16:1;
            vuint16 SID:11;   /* slot ID */
        } B;
    } RFRFCFR;

    typedef union uRFRFCTR {
        vuint16 R;
        struct {
            vuint16:4;
            vuint16 F3MD:1;   /* filter mode */
            vuint16 F2MD:1;   /* filter mode */
            vuint16 F1MD:1;   /* filter mode */
            vuint16 F0MD:1;   /* filter mode */
              vuint16:4;
            vuint16 F3EN:1;   /* filter enable */
            vuint16 F2EN:1;   /* filter enable */
            vuint16 F1EN:1;   /* filter enable */
            vuint16 F0EN:1;   /* filter enable */
        } B;
    } RFRFCTR;
	
	typedef union uLDTXSLAR {
        vuint16 R;
        struct {
              vuint16:5;
            vuint16 LASTDYNTXSLOTA:11;      /* last dynamic transmission slot channel A */
        } B;
    } LDTXSLAR;
	
	typedef union uLDTXSLBR {
        vuint16 R;
        struct {
              vuint16:5;
            vuint16 LASTDYNTXSLOTB:11;      /* last dynamic transmission slot channel B */
        } B;
    } LDTXSLBR;
	
    typedef union uPCR0 {
        vuint16 R;
        struct {
            vuint16 ACTION_POINT_OFFSET:6;
            vuint16 STATIC_SLOT_LENGTH:10;
        } B;
    } PCR0;

    typedef union uPCR1 {
        vuint16 R;
        struct {
            vuint16:2;
            vuint16 MACRO_AFTER_FIRST_STATIC_SLOT:14;
        } B;
    } PCR1;

    typedef union uPCR2 {
        vuint16 R;
        struct {
            vuint16 MINISLOT_AFTER_ACTION_POINT:6;
            vuint16 NUMBER_OF_STATIC_SLOTS:10;
        } B;
    } PCR2;

    typedef union uPCR3 {
        vuint16 R;
        struct {
            vuint16 WAKEUP_SYMBOL_RX_LOW:6;
            vuint16 MINISLOT_ACTION_POINT_OFFSET:5;
            vuint16 COLDSTART_ATTEMPTS:5;
        } B;
    } PCR3;

    typedef union uPCR4 {
        vuint16 R;
        struct {
            vuint16 CAS_RX_LOW_MAX:7;
            vuint16 WAKEUP_SYMBOL_RX_WINDOW:9;
        } B;
    } PCR4;

    typedef union uPCR5 {
        vuint16 R;
        struct {
            vuint16 TSSRANSMITTER:4;
            vuint16 WAKEUP_SYMBOLX_LOW:6;
            vuint16 WAKEUP_SYMBOL_RX_IDLE:6;
        } B;
    } PCR5;

    typedef union uPCR6 {
        vuint16 R;
        struct {
            vuint16:1;
            vuint16 SYMBOL_WINDOW_AFTER_ACTION_POINT:8;
            vuint16 MACRO_INITIAL_OFFSET_A:7;
        } B;
    } PCR6;

    typedef union uPCR7 {
        vuint16 R;
        struct {
            vuint16 DECODING_CORRECTION_B:9;
            vuint16 MICRO_PER_MACRO_NOM_HALF:7;
        } B;
    } PCR7;

    typedef union uPCR8 {
        vuint16 R;
        struct {
            vuint16 MAX_WITHOUT_CLOCK_CORRECTION_FATAL:4;
            vuint16 MAX_WITHOUT_CLOCK_CORRECTION_PASSIVE:4;
            vuint16 WAKEUP_SYMBOLX_IDLE:8;
        } B;
    } PCR8;

    typedef union uPCR9 {
        vuint16 R;
        struct {
            vuint16 MINISLOT_EXISTS:1;
            vuint16 SYMBOL_WINDOW_EXISTS:1;
            vuint16 OFFSET_CORRECTION_OUT:14;
        } B;
    } PCR9;

    typedef union uPCR10 {
        vuint16 R;
        struct {
            vuint16 SINGLE_SLOT_ENABLED:1;
            vuint16 WAKEUP_CHANNEL:1;
            vuint16 MACRO_PER_CYCLE:14;
        } B;
    } PCR10;

    typedef union uPCR11 {
        vuint16 R;
        struct {
            vuint16 KEY_SLOT_USED_FOR_STARTUP:1;
            vuint16 KEY_SLOT_USED_FOR_SYNC:1;
            vuint16 OFFSET_CORRECTION_START:14;
        } B;
    } PCR11;

    typedef union uPCR12 {
        vuint16 R;
        struct {
            vuint16 ALLOW_PASSIVEO_ACTIVE:5;
            vuint16 KEY_SLOT_HEADER_CRC:11;
        } B;
    } PCR12;

    typedef union uPCR13 {
        vuint16 R;
        struct {
            vuint16 FIRST_MINISLOT_ACTION_POINT_OFFSET:6;
            vuint16 STATIC_SLOT_AFTER_ACTION_POINT:10;
        } B;
    } PCR13;

    typedef union uPCR14 {
        vuint16 R;
        struct {
            vuint16 RATE_CORRECTION_OUT:11;
            vuint16 LISTENIMEOUT_H:5;
        } B;
    } PCR14;

    typedef union uPCR15 {
        vuint16 R;
        struct {
            vuint16 LISTENIMEOUT_L:16;
        } B;
    } PCR15;

    typedef union uPCR16 {
        vuint16 R;
        struct {
            vuint16 MACRO_INITIAL_OFFSET_B:7;
            vuint16 NOISE_LISTENIMEOUT_H:9;
        } B;
    } PCR16;

    typedef union uPCR17 {
        vuint16 R;
        struct {
            vuint16 NOISE_LISTENIMEOUT_L:16;
        } B;
    } PCR17;

    typedef union uPCR18 {
        vuint16 R;
        struct {
            vuint16 WAKEUP_PATTERN:6;
            vuint16 KEY_SLOT_ID:10;
        } B;
    } PCR18;

    typedef union uPCR19 {
        vuint16 R;
        struct {
            vuint16 DECODING_CORRECTION_A:9;
            vuint16 PAYLOAD_LENGTH_STATIC:7;
        } B;
    } PCR19;

    typedef union uPCR20 {
        vuint16 R;
        struct {
            vuint16 MICRO_INITIAL_OFFSET_B:8;
            vuint16 MICRO_INITIAL_OFFSET_A:8;
        } B;
    } PCR20;

    typedef union uPCR21 {
        vuint16 R;
        struct {
            vuint16 EXTERN_RATE_CORRECTION:3;
            vuint16 LATESTX:13;
        } B;
    } PCR21;

    typedef union uPCR22 {
        vuint16 R;
        struct {
            vuint16:1;
            vuint16 COMP_ACCEPTED_STARTUP_RANGE_A:11;
            vuint16 MICRO_PER_CYCLE_H:4;
        } B;
    } PCR22;

    typedef union uPCR23 {
        vuint16 R;
        struct {
            vuint16 micro_per_cycle_l:16;
        } B;
    } PCR23;

    typedef union uPCR24 {
        vuint16 R;
        struct {
            vuint16 CLUSTER_DRIFT_DAMPING:5;
            vuint16 MAX_PAYLOAD_LENGTH_DYNAMIC:7;
            vuint16 MICRO_PER_CYCLE_MIN_H:4;
        } B;
    } PCR24;

    typedef union uPCR25 {
        vuint16 R;
        struct {
            vuint16 MICRO_PER_CYCLE_MIN_L:16;
        } B;
    } PCR25;

    typedef union uPCR26 {
        vuint16 R;
        struct {
            vuint16 ALLOW_HALT_DUEO_CLOCK:1;
            vuint16 COMP_ACCEPTED_STARTUP_RANGE_B:11;
            vuint16 MICRO_PER_CYCLE_MAX_H:4;
        } B;
    } PCR26;

    typedef union uPCR27 {
        vuint16 R;
        struct {
            vuint16 MICRO_PER_CYCLE_MAX_L:16;
        } B;
    } PCR27;

    typedef union uPCR28 {
        vuint16 R;
        struct {
            vuint16 DYNAMIC_SLOT_IDLE_PHASE:2;
            vuint16 MACRO_AFTER_OFFSET_CORRECTION:14;
        } B;
    } PCR28;

    typedef union uPCR29 {
        vuint16 R;
        struct {
            vuint16 EXTERN_OFFSET_CORRECTION:3;
            vuint16 MINISLOTS_MAX:13;
        } B;
    } PCR29;

    typedef union uPCR30 {
        vuint16 R;
        struct {
            vuint16:12;
            vuint16 SYNC_NODE_MAX:4;
        } B;
    } PCR30;
	
	typedef union uEEIFER {
        vuint16 R;
        struct {
            vuint16 LRNE_OF:1;     /* LRAM non corrected error overflow flag */
            vuint16 LRCE_OF:1;     /* LRAM corrected error overflow flag */
			vuint16 DRNE_OF:1;     /* DRAM non corrected error overflow flag */
			vuint16 DRCE_OF:1;     /* DRAM corrected error overflow flag */
			vuint16 LRNE_IF:1;     /* LRAM non corrected error interrupt flag */
			vuint16 LRCE_IF:1;     /* LRAM corrected error interrupt flag */
			vuint16 DRNE_IF:1;     /* DRAM non corrected error interrupt flag */
			vuint16 DRCE_IF:1;     /* DRAM corrected error interrupt flag */
			  vuint16:4;
			vuint16 LRNE_IE:1;     /* LRAM non corrected error interrupt enable */
			vuint16 LRCE_IE:1;     /* LRAM corrected error interrupt enable */
			vuint16 DRNE_IE:1;     /* DRAM non corrected error interrupt enable */
			vuint16 DRCE_IE:1;     /* DRAM corrected error interrupt enable */
        } B;
    } EEIFER;
	
	typedef union uEERICR {
        vuint16 R;
        struct {
            vuint16 BSY:1;     /* regsiter update busy */
            vuint16:5;    
			vuint16 ERS:2;     /* error report select */
			vuint16:3;     
			vuint16 ERM:1;     /* error report mode */
			vuint16:2;     
			vuint16 EIM:1;     /* error injection mode */
			vuint16 EIE:1;     /* error injection enable */
        } B;
    } EERICR;
	
	typedef union uEERAR {
        vuint16 R;
        struct {
            vuint16 MID:1;     /* memory identifier */
            vuint16 BANK:3;    /* memory bank */
			vuint16 ADDR:12;     /* memory address */
        } B;
    } EERAR;
	
	typedef union uEERDR {
        vuint16 R;
        struct {
            vuint16 DATA:16;
        } B;
    } EERDR;
	
	typedef union uEERCR {
        vuint16 R;
        struct {
            vuint16:11;     
            vuint16 CODE:5;   
        } B;
    } EERCR;
	
	typedef union uEEIAR {
        vuint16 R;
        struct {
            vuint16 MID:1;     /* memory identifier */
            vuint16 BANK:3;    /* memory bank */
			vuint16 ADDR:12;     /* memory address */
        } B;
    } EEIAR;
	
	typedef union uEEIDR {
        vuint16 R;
        struct {
            vuint16 DATA:16;
        } B;
    } EEIDR;
	
	typedef union uEEICR {
        vuint16 R;
        struct {
            vuint16:11;     
            vuint16 CODE:5;   
        } B;
    } EEICR;

    typedef struct uMSG_BUFF_CCS {
        union {
            vuint16 R;
            struct {
                vuint16:1;
                vuint16 MCM:1;        /* message buffer commit mode */
                vuint16 MBT:1;        /* message buffer type */
                vuint16 MTD:1;        /* message buffer direction */
                vuint16 CMT:1;        /* commit for transmission */
                vuint16 EDT:1;        /* enable / disable trigger */
                vuint16 LCKT:1;       /* lock request trigger */
                vuint16 MBIE:1;       /* message buffer interrupt enable */
                  vuint16:3;
                vuint16 DUP:1;        /* data updated  */
                vuint16 DVAL:1;       /* data valid */
                vuint16 EDS:1;        /* lock status */
                vuint16 LCKS:1;       /* enable / disable status */
                vuint16 MBIF:1;       /* message buffer interrupt flag */
            } B;
        } MBCCSR;
        union {
            vuint16 R;
            struct {
                vuint16 MTM:1;        /* message buffer transmission mode */
                vuint16 CHNLA:1;      /* channel assignement */
                vuint16 CHNLB:1;      /* channel assignement */
                vuint16 CCFE:1;       /* cycle counter filter enable */
                vuint16 CCFMSK:6;     /* cycle counter filter mask */
                vuint16 CCFVAL:6;     /* cycle counter filter value */
            } B;
        } MBCCFR;
        union {
            vuint16 R;
            struct {
                vuint16:5;
                vuint16 FID:11;       /* frame ID */
            } B;
        } MBFIDR;
        union {
            vuint16 R;
            struct {
                vuint16:8;
                vuint16 MBIDX:8;      /* message buffer index */
            } B;
        } MBIDXR;
    } MSG_BUFF_CCS;
    

    typedef struct FRag {
        volatile MVR MVR;     /*module version register *//*0  */
        volatile MCR MCR;     /*module configuration register *//*2  */
        volatile SYMBADHR SYMBADHR;   /*system memory base address high register *//*4        */
        volatile SYMBADLR SYMBADLR;   /*system memory base address low register *//*6         */
        volatile STBSCR STBSCR;       /*strobe signal control register *//*8      */
        vuint16 reserved1[1];        /*A */
        volatile MBDSR MBDSR; /*message buffer data size register *//*C  */
        volatile MBSSUTR MBSSUTR;     /*message buffer segment size and utilization register *//*E  */
        volatile PEDRAR PEDRAR;        /*PE access register *//*10 */
        volatile PEDRDR PEDRDR;   /*PE data register *//*12 */
        volatile POCR POCR;   /*Protocol operation control register *//*14 */
        volatile GIFER GIFER; /*global interrupt flag and enable register *//*16 */
        volatile PIFR0 PIFR0; /*protocol interrupt flag register 0 *//*18 */
        volatile PIFR1 PIFR1; /*protocol interrupt flag register 1 *//*1A */
        volatile PIER0 PIER0; /*protocol interrupt enable register 0 *//*1C */
        volatile PIER1 PIER1; /*protocol interrupt enable register 1 *//*1E */
        volatile CHIERFR CHIERFR;     /*CHI error flag register *//*20 */
        volatile MBIVEC MBIVEC;       /*message buffer interrupt vector register *//*22 */
        volatile CASERCR CASERCR;     /*channel A status error counter register *//*24 */
        volatile CBSERCR CBSERCR;     /*channel B status error counter register *//*26 */
        volatile PSR0 PSR0;   /*protocol status register 0 *//*28 */
        volatile PSR1 PSR1;   /*protocol status register 1 *//*2A */
        volatile PSR2 PSR2;   /*protocol status register 2 *//*2C */
        volatile PSR3 PSR3;   /*protocol status register 3 *//*2E */
        volatile MTCTR MTCTR; /*macrotick counter register *//*30 */
        volatile CYCTR CYCTR; /*cycle counter register *//*32 */
        volatile SLTCTAR SLTCTAR;     /*slot counter channel A register *//*34 */
        volatile SLTCTBR SLTCTBR;     /*slot counter channel B register *//*36 */
        volatile RTCORVR RTCORVR;     /*rate correction value register *//*38 */
        volatile OFCORVR OFCORVR;     /*offset correction value register *//*3A */
        volatile CIFR CIFR; /*combined interrupt flag register *//*3C */
        volatile SYMATOR SYMATOR; /* System Memory Access Time-Out Register *//*3E */
        volatile SFCNTR SFCNTR;       /*sync frame counter register *//*40 */
        volatile SFTOR SFTOR; /*sync frame table offset register *//*42 */
        volatile SFTCCSR SFTCCSR;     /*sync frame table configuration, control, status register *//*44 */
        volatile SFIDRFR SFIDRFR;     /*sync frame ID rejection filter register *//*46 */
        volatile SFIDAFVR SFIDAFVR;   /*sync frame ID acceptance filter value regiater *//*48 */
        volatile SFIDAFMR SFIDAFMR;   /*sync frame ID acceptance filter mask register *//*4A */
        volatile NMVR NMVR[6];        /*network management vector registers (12 bytes) *//*4C */
        volatile NMVLR NMVLR; /*network management vector length register *//*58 */
        volatile TICCR TICCR; /*timer configuration and control register *//*5A */
        volatile TI1CYSR TI1CYSR;     /*timer 1 cycle set register *//*5C */
        volatile TI1MTOR T1MTOR;       /*timer 1 macrotick offset register *//*5E */
        volatile TI2CR0 TI2CR0;       /*timer 2 configuration register 0 *//*60 */
        volatile TI2CR1 TI2CR1;       /*timer 2 configuration register 1 *//*62 */
        volatile SSSR SSSR;   /*slot status selection register *//*64 */
        volatile SSCCR SSCCR; /*slot status counter condition register *//*66 */
        volatile SSR SSR[8];  /*slot status registers 0-7 *//*68 */
        volatile SSCR SSCR[4];        /*slot status counter registers 0-3 *//*78 */
        volatile MTSACFR MTSACFR;      /*mts a config register *//*80 */
        volatile MTSBCFR MTSBCFR;      /*mts b config register *//*82 */
        volatile RSBIR RSBIR; /*receive shadow buffer index register *//*84 */
        volatile RFWMSR RFWMSR;   /*Receive FIFO Watermark and Selection Register *//*86 */
        volatile RFSIR RFSIR; /*receive fifo start index register *//*88 */
        volatile RFDSR RFDSR; /*Receive FIFO Depth and Size Register*//*8A */
        volatile RFARIR RFARIR;       /*receive fifo a read index register *//*8C */
        volatile RFBRIR RFBRIR;       /*receive fifo b read index register *//*8E */
        volatile RFMIDAFVR RFMIDAFVR; /*receive fifo message ID acceptance filter value register *//*90 */
        volatile RFMIDAFMR RFMIDAFMR;   /*receive fifo message ID acceptance filter mask register *//*92 */
        volatile RFFIDRFVR RFFIDRFVR; /*receive fifo frame ID rejection filter value register *//*94 */
        volatile RFFIDRFMR RFFIDRFMR; /*receive fifo frame ID rejection filter mask register *//*96 */
        volatile RFRFCFR RFRFCFR;     /*receive fifo range filter configuration register *//*98 */
        volatile RFRFCTR RFRFCTR;     /*receive fifo range filter control register *//*9A */
        volatile LDTXSLAR LDTXSLAR;   /*last dynamic transmit slot channel A register *//*9C */
        volatile LDTXSLBR LDTXSLBR;   /*last dynamic transmit slot channel B register *//*9E */
        volatile PCR0 PCR0;   /*protocol configuration register 0 *//*A0 */
        volatile PCR1 PCR1;   /*protocol configuration register 1 *//*A2 */
        volatile PCR2 PCR2;   /*protocol configuration register 2 *//*A4 */
        volatile PCR3 PCR3;   /*protocol configuration register 3 *//*A6 */
        volatile PCR4 PCR4;   /*protocol configuration register 4 *//*A8 */
        volatile PCR5 PCR5;   /*protocol configuration register 5 *//*AA */
        volatile PCR6 PCR6;   /*protocol configuration register 6 *//*AC */
        volatile PCR7 PCR7;   /*protocol configuration register 7 *//*AE */
        volatile PCR8 PCR8;   /*protocol configuration register 8 *//*B0 */
        volatile PCR9 PCR9;   /*protocol configuration register 9 *//*B2 */
        volatile PCR10 PCR10; /*protocol configuration register 10 *//*B4 */
        volatile PCR11 PCR11; /*protocol configuration register 11 *//*B6 */
        volatile PCR12 PCR12; /*protocol configuration register 12 *//*B8 */
        volatile PCR13 PCR13; /*protocol configuration register 13 *//*BA */
        volatile PCR14 PCR14; /*protocol configuration register 14 *//*BC */
        volatile PCR15 PCR15; /*protocol configuration register 15 *//*BE */
        volatile PCR16 PCR16; /*protocol configuration register 16 *//*C0 */
        volatile PCR17 PCR17; /*protocol configuration register 17 *//*C2 */
        volatile PCR18 PCR18; /*protocol configuration register 18 *//*C4 */
        volatile PCR19 PCR19; /*protocol configuration register 19 *//*C6 */
        volatile PCR20 PCR20; /*protocol configuration register 20 *//*C8 */
        volatile PCR21 PCR21; /*protocol configuration register 21 *//*CA */
        volatile PCR22 PCR22; /*protocol configuration register 22 *//*CC */
        volatile PCR23 PCR23; /*protocol configuration register 23 *//*CE */
        volatile PCR24 PCR24; /*protocol configuration register 24 *//*D0 */
        volatile PCR25 PCR25; /*protocol configuration register 25 *//*D2 */
        volatile PCR26 PCR26; /*protocol configuration register 26 *//*D4 */
        volatile PCR27 PCR27; /*protocol configuration register 27 *//*D6 */
        volatile PCR28 PCR28; /*protocol configuration register 28 *//*D8 */
        volatile PCR29 PCR29; /*protocol configuration register 29 *//*DA */
        volatile PCR30 PCR30; /*protocol configuration register 30 *//*DC */
		vuint16 reserved2[5];
		volatile RFSYMBADHR RFSYMBADHR; /*Receive FIFO System Memory Base Address High Register *//*E8*/
		volatile RFSYMBADLR RFSYMBADLR; /*Receive FIFO System Memory Base Address Low Register *//*EA*/
		volatile RFPTR RFPTR; /*Receive FIFO Periodic Timer Register *//*EC*/
		volatile RFFLPCR RFFLPCR; /*Receive FIFO Fill Level and POP Count Register *//*EE*/
		volatile EEIFER EEIFER; /*ECC Error Interrupt Flag and Enable Register*//*F0*/
        volatile EERICR EERICR; /*ECC Error Report and Injection Control Register*//*F2*/
		volatile EERAR EERAR; /*ECC Error Report Address Register*//*F4*/
		volatile EERDR EERDR; /*ECC Error Report Data Register*//*F6*/
		volatile EERCR EERCR; /*ECC Error Report Code Register*//*F8*/
		volatile EEIAR EEIAR; /*ECC Error Injection Address Register *//*FA*/
		volatile EEIDR EEIDR; /*ECC Error Injection Data Register *//*FC*/
		volatile EEICR EEICR; /*ECC Error Injection Code Register *//*FE*/
        volatile MSG_BUFF_CCS MBCCS[128];     /* message buffer configuration, control & status registers 0-31 *//*100 */
    } FRag;

    typedef union uF_HEADER     /* frame header */
    {
        struct {
            vuint16:1;
            vuint16 PPI:1;    /* Payload Preamble Indicator */
            vuint16 NUF:1;    /* Null Frame Indicator */
            vuint16 SYF:1;    /* Sync Frame Indicator */
            vuint16 SUF:1;    /* Startup Frame Indicator */
            vuint16 FID:11;   /* Frame ID */
            vuint16:2;
            vuint16 CYCCNT:6; /* Cycle Count */
            vuint16:1;
            vuint16 PLDLEN:7; /* Payload Length */
            vuint16:5;
            vuint16 HDCRC:11; /* Header CRC */
        } B;
        vuint16 WORDS[3];
    } F_HEADER;
    typedef union uS_STSTUS     /* slot status */
    {
        struct {
            vuint16 VFB:1;    /* Valid Frame on channel B */
            vuint16 SYB:1;    /* Sync Frame Indicator channel B */
            vuint16 NFB:1;    /* Null Frame Indicator channel B */
            vuint16 SUB:1;    /* Startup Frame Indicator channel B */
            vuint16 SEB:1;    /* Syntax Error on channel B */
            vuint16 CEB:1;    /* Content Error on channel B */
            vuint16 BVB:1;    /* Boundary Violation on channel B */
            vuint16 CH:1;     /* Channel */
            vuint16 VFA:1;    /* Valid Frame on channel A */
            vuint16 SYA:1;    /* Sync Frame Indicator channel A */
            vuint16 NFA:1;    /* Null Frame Indicator channel A */
            vuint16 SUA:1;    /* Startup Frame Indicator channel A */
            vuint16 SEA:1;    /* Syntax Error on channel A */
            vuint16 CEA:1;    /* Content Error on channel A */
            vuint16 BVA:1;    /* Boundary Violation on channel A */
              vuint16:1;
        } RX;
        struct {
            vuint16 VFB:1;    /* Valid Frame on channel B */
            vuint16 SYB:1;    /* Sync Frame Indicator channel B */
            vuint16 NFB:1;    /* Null Frame Indicator channel B */
            vuint16 SUB:1;    /* Startup Frame Indicator channel B */
            vuint16 SEB:1;    /* Syntax Error on channel B */
            vuint16 CEB:1;    /* Content Error on channel B */
            vuint16 BVB:1;    /* Boundary Violation on channel B */
            vuint16 TCB:1;    /* Tx Conflict on channel B */
            vuint16 VFA:1;    /* Valid Frame on channel A */
            vuint16 SYA:1;    /* Sync Frame Indicator channel A */
            vuint16 NFA:1;    /* Null Frame Indicator channel A */
            vuint16 SUA:1;    /* Startup Frame Indicator channel A */
            vuint16 SEA:1;    /* Syntax Error on channel A */
            vuint16 CEA:1;    /* Content Error on channel A */
            vuint16 BVA:1;    /* Boundary Violation on channel A */
            vuint16 TCA:1;    /* Tx Conflict on channel A */
        } TX;
        vuint16 R;
    } S_STATUS;

    typedef struct uMB_HEADER   /* message buffer header */
    {
        F_HEADER FRAME_HEADER;
        vuint16 DATA_OFFSET;
        S_STATUS SLOT_STATUS;
    } MB_HEADER;

/****************************************************************************/
/*                     MODULE : Power Management Controller (PMC)           */
/****************************************************************************/
    struct PMCag {
        union {
            vuint32 R;
            struct {
                vuint32 LVRER:1;
                vuint32 LVREH:1;
                vuint32 LVRE50:1;
                vuint32 LVRE33:1;
                vuint32 LVREC:1;
                  vuint32:3;
                vuint32 LVIER:1;
                vuint32 LVIEH:1;
                vuint32 LVIE50:1;
                vuint32 LVIE33:1;
                vuint32 LVIC:1;
                  vuint32:2;
                vuint32 TLK:1;
                  vuint32:16;
            } B;
        } MCR;                  /* Module Configuration register @baseaddress + 0x00 */

        union {
            vuint32 R;
            struct {
                vuint32:12;
                vuint32 LVDREGTRIM:4;
                vuint32 VDD33TRIM:4;
                vuint32 LVD33TRIM:4;
                vuint32 VDDCTRIM:4;
                vuint32 LVDCTRIM:4;
            } B;
        } TRIMR;                /* Trimming register @baseaddress + 0x00 */

        union {
            vuint32 R;
            struct {
                vuint32:5;
                vuint32 LVFVSTBY:1;
                vuint32 BGRDY:1;
                vuint32 BGTS:1;
                  vuint32:5;
                vuint32 LVFCSTBY:1;
                  vuint32:1;
                vuint32 V33DIS:1;
                vuint32 LVFCR:1;
                vuint32 LVFCH:1;
                vuint32 LVFC50:1;
                vuint32 LVFC33:1;
                vuint32 LVFCC:1;
                  vuint32:3;
                vuint32 LVFR:1;
                vuint32 LVFH:1;
                vuint32 LVF50:1;
                vuint32 LVF33:1;
                vuint32 LVFC:1;
                  vuint32:3;
            } B;
        } SR;                   /* status register @baseaddress + 0x00 */
    };

/****************************************************************************/
/*                          MODULE : MPU                                    */
/****************************************************************************/

    struct MPUag {

        union {                 /* Module Control/Error Status Register */
            vuint32 R;
            struct {
                vuint32 SPERR:8;
                  vuint32:4;
                vuint32 HRL:4;
                vuint32 NSP:4;
                vuint32 NRGD:4;
                  vuint32:7;
                vuint32 VLD:1;
            } B;
        } CESR;

        uint32 MPU_reserved0004[3]; /* 0x0004-0x000F */

        struct {
            union {             /* MPU Error Address Registers */
                vuint32 R;
                struct {
                    vuint32 EADDR:32;
                } B;
            } EAR;

            union {             /* MPU Error Detail Registers */
                vuint32 R;
                struct {
                    vuint32 EACD:16;
                    vuint32 EPID:8;
                    vuint32 EMN:4;
                    vuint32 EATTR:3;
                    vuint32 ERW:1;
                } B;
            } EDR;
        } PORT[2];

        uint32 MPU_reserved0020[248];  /* 0x0020-0x03FF */

        struct {
            union {            /* Region Descriptor n Word 0 */
                vuint32 R;
                struct {
                    vuint32 SRTADDR:27;
                    vuint32:5;
                } B;
            } WORD0;

            union {            /* Region Descriptor n Word 1 */
                vuint32 R;
                struct {
                    vuint32 ENDADDR:27;
                    vuint32:5;
                } B;
            } WORD1;

            union {            /* Region Descriptor n Word 2 */
                vuint32 R;
                struct {
                    vuint32 M7RE:1;
                    vuint32 M7WE:1;
                    vuint32 M6RE:1;
                    vuint32 M6WE:1;
                    vuint32:2;
                    vuint32 M4RE:1;
                    vuint32 M4WE:1;
                      vuint32:18;
                    vuint32 M0PE:1;
                    vuint32 M0SM:2;
                    vuint32 M0UM:3;
                } B;
            } WORD2;

            union {            /* Region Descriptor n Word 3 */
                vuint32 R;
                struct {
                    vuint32 PID:8;
                    vuint32 PIDMASK:8;
                      vuint32:15;
                    vuint32 VLD:1;
                } B;
            } WORD3;
        } RGD[16];

        uint32 MPU_reserved0500[192];  /* 0x0500-0x07FF */

        union {           /* Region Descriptor Alternate Access Control n */
            vuint32 R;
            struct {
                vuint32 M7RE:1;
                vuint32 M7WE:1;
                vuint32 M6RE:1;
                vuint32 M6WE:1;
                vuint32:2;
                vuint32 M4RE:1;
                vuint32 M4WE:1;
                vuint32:18;
                vuint32 M0PE:1;
                vuint32 M0SM:2;
                vuint32 M0UM:3;
            } B;
        } RGDAAC[16];

        uint32 MPU_reserved0840[3568];  /* 0x0840-0x3FFF */

    };

/****************************************************************************/
/*                          MODULE : TSENS (Temperature Sensor)             */
/****************************************************************************/

    struct TSENSag {

        union {                
            vuint32 R;
            struct {
                vuint32 TSCV2:16;
                vuint32 TSCV1:16;
            } B;
        } TCCR0;                 /* Temperature Sensor Calculation Constants 0 @baseaddress + 0x00 */

        union {                
            vuint32 R;
            struct {
                 vuint32:2;
				vuint32 TSCV3:14;
				 vuint32:16;
            } B;    
        } TCCR1;                 /* Temperature Sensor Calculation Constants 1 @baseaddress + 0x04 */
        
        uint32 TSENS_reserved0008[16382]; /* 0x0008-0xFFFF */

    };

/****************************************************************************/
/*					   MODULE : DTS (Development Trigger Semaphor)          */
/****************************************************************************/
    struct DTSag {
	    
	  union {
		  vuint32 R;
		  struct {
		  	   vuint32:31;
	      	  vuint32 DTS_EN:1;
		  }B;  
  	  } ENABLE; 					/* DTS Output Enable Register @baseaddress + 0x0 */

	  union {
		  vuint32 R;
		  struct{
			  vuint32 AD31:1;
			  vuint32 AD30:1;
			  vuint32 AD29:1;
			  vuint32 AD28:1;
			  vuint32 AD27:1;
			  vuint32 AD26:1;
			  vuint32 AD25:1;
			  vuint32 AD24:1;
			  vuint32 AD23:1;
			  vuint32 AD22:1;
			  vuint32 AD21:1;
			  vuint32 AD20:1;
			  vuint32 AD19:1;
			  vuint32 AD18:1;
			  vuint32 AD17:1;
			  vuint32 AD16:1;
			  vuint32 AD15:1;
			  vuint32 AD14:1;
			  vuint32 AD13:1;
			  vuint32 AD12:1;
			  vuint32 AD11:1;
			  vuint32 AD10:1;
			  vuint32 AD9:1;
			  vuint32 AD8:1;
			  vuint32 AD7:1;
			  vuint32 AD6:1;
			  vuint32 AD5:1;
			  vuint32 AD4:1;
			  vuint32 AD3:1;
			  vuint32 AD2:1;
			  vuint32 AD1:1;
			  vuint32 AD0:1;
		  }B;  
  	  } STARTUP;					/* DTS Startup Register @baseaddress + 0x4 */
	  
	  union {
		  vuint32 R;
		  struct {
			  vuint32 ST31:1;
			  vuint32 ST30:1;
			  vuint32 ST29:1;
			  vuint32 ST28:1;
			  vuint32 ST27:1;
			  vuint32 ST26:1;
			  vuint32 ST25:1;
			  vuint32 ST24:1;
			  vuint32 ST23:1;
			  vuint32 ST22:1;
			  vuint32 ST21:1;
			  vuint32 ST20:1;
			  vuint32 ST19:1;
			  vuint32 ST18:1;
			  vuint32 ST17:1;
			  vuint32 ST16:1;
			  vuint32 ST15:1;
			  vuint32 ST14:1;
			  vuint32 ST13:1;
			  vuint32 ST12:1;
			  vuint32 ST11:1;
			  vuint32 ST10:1;
			  vuint32 ST9:1;
			  vuint32 ST8:1;
			  vuint32 ST7:1;
			  vuint32 ST6:1;
			  vuint32 ST5:1;
			  vuint32 ST4:1;
			  vuint32 ST3:1;
			  vuint32 ST2:1;
			  vuint32 ST1:1;
			  vuint32 ST0:1;
		  }B;  
      } SEMAPHORE;				/* DTS Semaphore Register @baseaddress + 0x8 */
	  
	  uint32 DTS_reserved000C[16381]; /* 0x000C-0xFFFF */	    
   
    };
    
/****************************************************************************/
/*					   MODULE : REACM (Reaction Module)          			*/
/****************************************************************************/
    struct REACMag {
	    
	  union {
		  vuint32 R;
		  struct {
		  	  vuint32 OVRC:1;
		  	  vuint32 MDIS:1;
		  	  vuint32 FRZ:1;
			   vuint32:1;
			  vuint32 FREN:1;
			  vuint32 TPREN:1;
			  vuint32 HPREN:1;
			  vuint32 GIEN:1;
			  vuint32 OVREN:1; 
	      	   vuint32:23;
		  } B;  
      } MCR; 					/* REACM Module Configuration @baseaddress + 0x0 */
    
      union {
		  vuint32 R;
		  struct {
		  	   vuint32:4;
	      	  vuint32 HPRE:12;
	      	   vuint32:8;
	      	  vuint32 TPRE:8;
		  } B;  
      } TCR; 					/* REACM Timer Configuration @baseaddress + 0x4 */
      
      union {
		  vuint32 R;
		  struct {
		  	   vuint32:6;
	      	  vuint32 WREN1:1;
	      	  vuint32 WREN0:1;
	      	   vuint32:12;
	      	  vuint32 THRADC1:4; 
	      	   vuint32:4;
	      	  vuint32 THRADC0:4; 
		  } B;  
      } THRR; 					/* REACM Threshold Router @baseaddress + 0x8 */
      
      uint32 REACM_reserved000C[1]; /* 0x000C-0x000F */
      
      union {
		  vuint32 R;
		  struct {
		  	   vuint32:12;
		  	  vuint32 ADCAG:4; 
	      	  vuint32 ADC_RESULT:16;
		  } B;  
      } SINR; 					/* REACM ADC Sensor Input Register @baseaddress + 0x10 */
      
      uint32 REACM_reserved0014[3]; /* 0x0014-0x0001F */
      
      union {
		  vuint32 R;
		  struct {
		  	  vuint32 OVR:1;
			   vuint32:25;
	      	  vuint32 EF5:1;
	      	  vuint32 EF4:1;
	      	  vuint32 EF3:1;
	      	  vuint32 EF2:1;
	      	  vuint32 EF1:1;
	      	  vuint32 EF0:1;
		  } B;  
      } GEFR; 					/* REACM Global Error Flag @baseaddress + 0x20 */
      
	  uint32 REACM_reserved0024[55]; /* 0x0024-0x00FF */      
	  
	  struct {
	  	  union {
			  vuint32 R;
			  struct {
			  	  vuint32 CHEN:2;
			  	  vuint32 SWMC:1;
			  	  vuint32 MAXLEN:1;
			  	  vuint32 OCDFEN:1;
			  	  vuint32 SCDFEN:1;
			  	  vuint32 TAEREN:1;
			  	  vuint32 SQEREN:1;
			  	  vuint32 RAEREN:1;
				  vuint32 DMAEN:1;
		      	  vuint32 CHOFF:1;
		      	   vuint32:2;
		      	  vuint32 DOFF:3;
		      	   vuint32:5;
		      	  vuint32 BSB:3;
		      	   vuint32:2;
		      	  vuint32 MODULATION_ADDR:6;
			  } B;  
	      } CR; 					/* REACM Channel n Configuration @baseaddress + 0x100 + (n*0x10) + 0x0 */
	      
		  union {
			  vuint32 R;
			  struct {
			  	   vuint32:2;
		      	  vuint32 MODACT:1;
		      	  vuint32 MAXL:1;
		      	  vuint32 OCDF:1;
		      	  vuint32 SCDF:1;
		      	  vuint32 TAER:1;
		      	  vuint32 SQER:1;
		      	  vuint32 RAER:1;
		      	  vuint32 CHOUT:3;
		      	   vuint32:7;
		      	  vuint32 MAXLC:1;
		      	  vuint32 OCDFC:1;
		      	  vuint32 SCDFC:1;
		      	  vuint32 TAERC:1;
		      	  vuint32 SQERC:1;
		      	  vuint32 RAERC:1; 
		      	   vuint32:1;
		      	  vuint32 MODULATION_POINTER:6; 
			  } B;  
	      } SR; 					/* REACM Channel n Status @baseaddress + 0x100 + (n*0x10) + 0x4 */
		  
	      union {
			  vuint32 R;
			  struct {
		      	   vuint32:12;
		      	  vuint32 ADCR:4;
		      	   vuint32:12;
		      	  vuint32 CHIR:4;
			  } B;  
	      } RR; 					/* REACM Channel n Router @baseaddress + 0x100 + (n*0x10) + 0x8 */
	      
	      uint32 REACM_reserved01xC; /* 0x01xC-0x01xF */      
	      
      } CH[6];

      uint32 REACM_reserved0160[104]; /* 0x0160-0x02FF */      
      
      union {
		  vuint32 R;
		  struct {
		  	   vuint32:16;
	      	  vuint32 SHAREDIMER:16;
		  } B;  
      } STBK[16]; 					/* REACM Shared Timer Bank @baseaddress + 0x300 */
      
      uint32 REACM_reserved0340[16]; /* 0x0340-0x037F */      
      
      union {
		  vuint32 R;
		  struct {
		  	   vuint32:20;
	      	  vuint32 HOLD_OFF:12;
		  } B;  
      } HOTBK[16]; 					/* REACM Hold-off Timer Bank @baseaddress + 0x380 */
      
      uint32 REACM_reserved03C0[16]; /* 0x03C0-0x03FF */      
      
      union {
		  vuint32 R;
		  struct {
		  	   vuint32:16;
	      	  vuint32 THRESHOLD_VALUE:16;
		  } B;  
      } THBK[32]; 					/* REACM Threshold Timer Bank @baseaddress + 0x400 */
      
      uint32 REACM_reserved0480[96]; /* 0x0480-0x05FF */      
      
      union {
		  vuint32 R;
		  struct {
		  	   vuint32:16;
	      	  vuint32 ADC_MAX_LIMIT:16;
		  } B;  
      } ADCMAX; 					/* REACM ADC Result Max Limit Check @baseaddress + 0x600 */
      
      uint32 REACM_reserved0604[31]; /* 0x0604-0x067F */      
      
      union {
		  vuint32 R;
		  struct {
		  	   vuint32:20;
	      	  vuint32 RANGE_PWD:12;
		  } B;  
      } RANGEPWD; 					/* REACM Modulation Range Pulse Width @baseaddress + 0x680 */
      
      uint32 REACM_reserved0684[15]; /* 0x0684-0x06BF */      
      
      union {
		  vuint32 R;
		  struct {
		  	   vuint32:20;
	      	  vuint32 MIN_PWD:12;
		  } B;  
      } MINPWD; 					/* REACM Modulation Minimum Pulse Width @baseaddress + 0x6C0 */
      
      uint32 REACM_reserved06C4[15]; /* 0x06C4-0x06FF */      
      
      union {
		  vuint32 R;
		  struct {
		  	  vuint32 LOOP:1;
		  	  vuint32 IOSS:1;
			   vuint32:1;
	      	  vuint32 MM:2;
	      	   vuint32:1;
	      	  vuint32 SM:2;
	      	   vuint32:1;
	      	  vuint32 HOD:3;
	      	   vuint32:1;
	      	  vuint32 LOD:3;
	      	   vuint32:1;
	      	  vuint32 THRESPT:6;
	      	  vuint32 STPT:4;
	      	   vuint32:1;
	      	  vuint32 HDOFFTPT:4;
		  } B;  
      } MWBK[64]; 					/* REACM Modulation Control Word Bank @baseaddress + 0x700 */
     
	};

    
/* Define memories */

#define SRAM_START    0x40000000
#define SRAM_SIZE        0x30000
#define SRAM_END      0x4002FFFF

#define FLASH_START   0x00000000
#define FLASH_SIZE      0x400000
#define FLASH_END     0x003FFFFF

/* Define instances of modules */
#define FMPLL     (*( volatile struct FMPLLag *)      0xC3F80000)
#define EBI       (*( volatile struct EBIag *)        0xC3F84000)
#define FLASH_A   (*( volatile struct FLASHag *)      0xC3F88000)
#define FLASH_B   (*( volatile struct FLASHag *)      0xC3F8C000)
#define SIU       (*( volatile struct SIUag *)        0xC3F90000)
#define DTS       (*( volatile struct DTSag *)        0xC3F9C000)

#define EMIOS     (*( volatile struct EMIOSag *)      0xC3FA0000)
#define PMC       (*( volatile struct PMCag *)        0xC3FBC000)

#define ETPU      (*( volatile struct ETPUag *)       0xC3FC0000)
#define ETPU_DATA_RAM      (*( uint32 *)              0xC3FC8000)
#define ETPU_DATA_RAM_END                               0xC3FC8BFC
#define ETPU_DATA_RAM_EXT  (*( uint32 *)              0xC3FCC000)
#define CODE_RAM           (*( uint32 *)              0xC3FD0000)
#define ETPU_CODE_RAM      (*( uint32 *)              0xC3FD0000)

#define REACM	  (*( volatile struct REACMag *)      0xC3FC7000)

#define PIT       (*( volatile struct PITag *)        0xC3FF0000)

#define CRC       (*( volatile struct CRCag *)        0xFFE68000)

#define PBRIDGE   (*( volatile struct PBRIDGEag *)    0xFFF00000)
#define XBAR      (*( volatile struct XBARag *)       0xFFF04000)
#define MPU       (*( volatile struct MPUag *)        0xFFF10000)
#define SWT       (*( volatile struct SWTag *)        0xFFF38000)
#define STM       (*( volatile struct STMag *)        0xFFF3C000)
#define ECSM      (*( volatile struct ECSMag *)       0xFFF40000)
#define EDMA      (*( volatile struct EDMAag *)       0xFFF44000)
#define INTC      (*( volatile struct INTCag *)       0xFFF48000)

#define EQADC     (*( volatile struct EQADCag *)      0xFFF80000)

#define DECFIL_A   (*( volatile struct DECFILag *)      0xFFF88000)
#define DECFIL_B   (*( volatile struct DECFILag *)      0xFFF8C000)

#define DSPI_B    (*( volatile struct DSPIag *)       0xFFF94000)
#define DSPI_C    (*( volatile struct DSPIag *)       0xFFF98000)
#define DSPI_D    (*( volatile struct DSPIag *)       0xFFF9C000)

#define ESCI_A    (*( volatile struct ESCIag *)       0xFFFB0000)
#define ESCI_B    (*( volatile struct ESCIag *)       0xFFFB4000)
#define ESCI_C    (*( volatile struct ESCIag *)       0xFFFB8000)

#define CAN_A     (*( volatile struct FLEXCAN2ag *)   0xFFFC0000)
#define CAN_B     (*( volatile struct FLEXCAN2ag *)   0xFFFC4000)
#define CAN_C     (*( volatile struct FLEXCAN2ag *)   0xFFFC8000)

#define FR        (*( volatile struct FRag *)         0xFFFE0000)
#define TSENS     (*( volatile struct TSENSag *)      0xFFFEC000)


#ifdef __MWERKS__
#pragma pop
#endif

#ifdef  __cplusplus
}
#endif

#endif                          /* ifdef _MPC5644_H */

/*********************************************************************
 *
 * Copyright:
 *  Freescale Semiconductor, INC. & STMicroelectronics All Rights Reserved.
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
 *  Semiconductor & STMicroelectronics DISCLAIMS ALL WARRANTIES WHETHER 
 *  EXPRESS OR IMPLIED,INCLUDING IMPLIED WARRANTIES OF MERCHANTABILITY OR 
 *  FITNESS FOR A PARTICULAR PURPOSE AND ANY WARRANTY AGAINST INFRINGEMENT WITH
 *  REGARD TO THE SOFTWARE (INCLUDING ANY MODIFIED VERSIONS THEREOF)
 *  AND ANY ACCOMPANYING WRITTEN MATERIALS.
 *
 *  To the maximum extent permitted by applicable law, IN NO EVENT
 *  SHALL Freescale Semiconductor or STMicroelectronics BE LIABLE FOR ANY 
 *  DAMAGES WHATSOEVER (INCLUDING WITHOUT LIMITATION, DAMAGES FOR LOSS OF 
 *  BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF BUSINESS INFORMATION, 
 *  OR OTHER PECUNIARY LOSS) ARISING OF THE USE OR INABILITY TO USE THE SOFTWARE.
 *
 *  Freescale Semiconductor & STMicroelectronics assumes no responsibility 
 *  for the maintenance and support of this software
 *
 ********************************************************************/
