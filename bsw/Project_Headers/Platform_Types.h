/**************************************************************************
 * FILE NAME: $RCSfile: typedefs.h,v $       COPYRIGHT (c) Freescale 2005 *
 * DESCRIPTION:                                     All Rights Reserved   *
 * This file defines all of the data types for the Motorola header file.  *
 *========================================================================*
 * ORIGINAL AUTHOR: Jeff Loeliger (r12110)                                *
 * $Log: typedefs.h,v $
 * Revision 1.1  2010/07/21 13:28:05  dmihail1
 * Add to DataBase: 'runtime' folder
 * See: MTWX40737, MTWX40738, MTWX40743, MTWX42016
 *
 * Revision 1.7  2007/05/02 22:46:00  dfreeland
 * Use latest web version
 *
 * Revision 1.4  2006/03/27 09:59:34  r47354
 * change __GHS__ to __ghs__. As per bug 13213
 *
 * Revision 1.3  2005/02/22 13:09:38  r47354
 * Fix copyright date.
 *
 * Revision 1.2  2004/11/17 12:43:12  r12110
 * -Removed #ifdef DEBUG from around initial comment block.
 *
 * Revision 1.1  2004/11/17 12:38:48  r12110
 * -Initial version checked into CVS.
 * -Updated copyright from Motorola to Freescale.
 *
 *........................................................................*
 * 0.1   J. Loeliger  17/Feb/03    Initial version of file.               *
 * 0.2   J. Loeliger  06/Mar/03    Added DCC support.                     *
 * 0.3   J. Loeliger  07/May/03    Change to fully use ISO data types.    *
 * 0.4   J. Loeliger  17/Jun/03    Change name to motint.h and merge      *
 *                                  MPC5500 and MAC7100 files.            *
 * 0.5   J. Loeliger  04/Nov/03    Changed name to typedefs.h.            *
 * 0.6   J. Loeliger  09/May/04    Changed to support GHS and GCC.        *
 **************************************************************************/

#ifndef _PLATFORM_TYPES_H_
#define _PLATFORM_TYPES_H_
   
/* AUTOSAR Platform Types */
    typedef volatile unsigned char  vuint8;
    typedef volatile signed char    vsint8;   
    typedef volatile unsigned short vuint16;
    typedef volatile signed short   vsint16;
    typedef volatile unsigned long  vuint32; 
    typedef volatile signed long    vsint32;
    typedef unsigned char  uint8;
    typedef signed char    sint8;   
    typedef unsigned short uint16;
    typedef signed short   sint16;
    typedef unsigned long  uint32; 
    typedef signed long    sint32;
    typedef unsigned long long  uint64;
    typedef signed long long    sint64;

    typedef uint8 boolean;
    typedef float float32;

/*AUTOSAR *_least types */
    typedef unsigned long  uint8_least;
    typedef signed long    sint8_least;   
    typedef unsigned long uint16_least;
    typedef signed long   sint16_least;
    typedef unsigned long  uint32_least; 
    typedef signed long    sint32_least;

/*AUTOSAR Platform Definitions */
#define CPU_TYPE_8        8 
#define CPU_TYPE_16       16 
#define CPU_TYPE_32       32 
#define MSB_FIRST         0 
#define LSB_FIRST         1 
#define HIGH_BYTE_FIRST   0 
#define LOW_BYTE_FIRST    1
#ifndef TRUE  
    #define TRUE   ((boolean) 1) 
#endif 
#ifndef FALSE 
    #define FALSE  ((boolean) 0) 
#endif
/* CPU Configuration */
#define CPU_TYPE CPU_TYPE_32
#define CPU_BIT_ORDER MSB_FIRST
#define CPU_BYTE_ORDER HIGH_BYTE_FIRST


#endif
