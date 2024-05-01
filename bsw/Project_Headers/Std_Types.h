#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

#include "Platform_Types.h"
#include "Compiler.h"
#include "ee_types.h"
//#define NULL 0

#define STD_HIGH  0x01   /* Physical state 5V or 3.3V */ 
#define STD_LOW   0x00   /* Physical state 0V         */


#define STD_ACTIVE  0x01   /* Logical state active */ 
#define STD_IDLE    0x00   /* Logical state idle   */

#define STD_ON    0x01 
#define STD_OFF   0x00

#define STD_TRUE    0x01 
#define STD_FALSE   0x00


#ifndef STATUSTYPEDEFINED  
  #define STATUSTYPEDEFINED  
  #define E_OK    0x00 
  typedef unsigned char StatusType; /* OSEK compliance */ 
#endif 
#define E_NOT_OK  0x01
typedef uint8 Std_ReturnType;

typedef struct 
{ 
        uint16 vendorID;
        uint16 moduleID;
        uint8 instanceID;
        uint8 sw_major_version;
        uint8 sw_minor_version;
        uint8 sw_patch_version;
} Std_VersionInfoType; 


#endif
