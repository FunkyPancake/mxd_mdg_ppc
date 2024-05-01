/* xcp_par.c */

#include "xcpBasic.h"
#include "xcp_par.h"

// Slave device id
#if defined ( kXcpStationIdLength )
  V_MEMROM0 MEMORY_ROM vuint8 kXcpStationId[kXcpStationIdLength] = kXcpStationIdString;
#endif


