#define IGN_MEMMAP_ERROR

/*Section start*/
#if defined(IGN_START_SEC_CODE)
    #undef IGN_START_SEC_CODE
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_CODE
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_8BIT)
    #undef IGN_START_SEC_VAR_8BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_8BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_16BIT)
    #undef IGN_START_SEC_VAR_16BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_16BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_32BIT)
    #undef IGN_START_SEC_VAR_32BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_32BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_UNSPECIFIED)
    #undef IGN_START_SEC_VAR_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_UNSPECIFIED
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_NOINIT_8BIT)
    #undef IGN_START_SEC_VAR_NOINIT_8BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_NOINIT_8BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_NOINIT_16BIT)
    #undef IGN_START_SEC_VAR_NOINIT_16BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_NOINIT_16BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_NOINIT_32BIT)
    #undef IGN_START_SEC_VAR_NOINIT_32BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_NOINIT_32BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef IGN_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_STBY_8BIT)
    #undef IGN_START_SEC_VAR_STBY_8BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_STBY_8BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_STBY_16BIT)
    #undef IGN_START_SEC_VAR_STBY_16BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_STBY_16BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_STBY_32BIT)
    #undef IGN_START_SEC_VAR_STBY_32BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_STBY_32BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_STBY_UNSPECIFIED)
    #undef IGN_START_SEC_VAR_STBY_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_STBY_UNSPECIFIED
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_FAST_8BIT)
    #undef IGN_START_SEC_VAR_FAST_8BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_8BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_FAST_16BIT)
    #undef IGN_START_SEC_VAR_FAST_16BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_16BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_FAST_32BIT)
    #undef IGN_START_SEC_VAR_FAST_32BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_32BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_FAST_UNSPECIFIED)
    #undef IGN_START_SEC_VAR_FAST_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_UNSPECIFIED
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_FAST_NOINIT_8BIT)
    #undef IGN_START_SEC_VAR_FAST_NOINIT_8BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_NOINIT_8BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_FAST_NOINIT_16BIT)
    #undef IGN_START_SEC_VAR_FAST_NOINIT_16BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_NOINIT_16BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_FAST_NOINIT_32BIT)
    #undef IGN_START_SEC_VAR_FAST_NOINIT_32BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_NOINIT_32BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
    #undef IGN_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_CAL_8BIT)
    #undef IGN_START_SEC_VAR_CAL_8BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_CAL_8BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_CAL_16BIT)
    #undef IGN_START_SEC_VAR_CAL_16BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_CAL_16BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_CAL_32BIT)
    #undef IGN_START_SEC_VAR_CAL_32BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_CAL_32BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_VAR_CAL_UNSPECIFIED)
    #undef IGN_START_SEC_VAR_CAL_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_VAR_CAL_UNSPECIFIED
    #include "MemMap.h"


#elif defined(IGN_START_SEC_CONST_8BIT)
    #undef IGN_START_SEC_CONST_8BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_CONST_8BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_CONST_16BIT)
    #undef IGN_START_SEC_CONST_16BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_CONST_16BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_CONST_32BIT)
    #undef IGN_START_SEC_CONST_32BIT
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_CONST_32BIT
    #include "MemMap.h"


#elif defined(IGN_START_SEC_CONST_UNSPECIFIED)
    #undef IGN_START_SEC_CONST_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define START_SEC_CONST_UNSPECIFIED
    #include "MemMap.h"


/*Section stops*/

#elif defined(IGN_STOP_SEC_VAR_8BIT)
    #undef IGN_STOP_SEC_VAR_8BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_8BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_16BIT)
    #undef IGN_STOP_SEC_VAR_16BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_16BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_32BIT)
    #undef IGN_STOP_SEC_VAR_32BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_32BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_UNSPECIFIED)
    #undef IGN_STOP_SEC_VAR_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_UNSPECIFIED
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_NOINIT_8BIT)
    #undef IGN_STOP_SEC_VAR_NOINIT_8BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_NOINIT_8BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_NOINIT_16BIT)
    #undef IGN_STOP_SEC_VAR_NOINIT_16BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_NOINIT_16BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_NOINIT_32BIT)
    #undef IGN_STOP_SEC_VAR_NOINIT_32BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_NOINIT_32BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef IGN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_STBY_8BIT)
    #undef IGN_STOP_SEC_VAR_STBY_8BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_STBY_8BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_STBY_16BIT)
    #undef IGN_STOP_SEC_VAR_STBY_16BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_STBY_16BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_STBY_32BIT)
    #undef IGN_STOP_SEC_VAR_STBY_32BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_STBY_32BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_STBY_UNSPECIFIED)
    #undef IGN_STOP_SEC_VAR_STBY_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_STBY_UNSPECIFIED
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_FAST_8BIT)
    #undef IGN_STOP_SEC_VAR_FAST_8BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_8BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_FAST_16BIT)
    #undef IGN_STOP_SEC_VAR_FAST_16BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_16BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_FAST_32BIT)
    #undef IGN_STOP_SEC_VAR_FAST_32BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_32BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_FAST_UNSPECIFIED)
    #undef IGN_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_UNSPECIFIED
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_FAST_NOINIT_8BIT)
    #undef IGN_STOP_SEC_VAR_FAST_NOINIT_8BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_NOINIT_8BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_FAST_NOINIT_16BIT)
    #undef IGN_STOP_SEC_VAR_FAST_NOINIT_16BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_NOINIT_16BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_FAST_NOINIT_32BIT)
    #undef IGN_STOP_SEC_VAR_FAST_NOINIT_32BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_NOINIT_32BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
    #undef IGN_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_CAL_8BIT)
    #undef IGN_STOP_SEC_VAR_CAL_8BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_CAL_8BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_CAL_16BIT)
    #undef IGN_STOP_SEC_VAR_CAL_16BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_CAL_16BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_CAL_32BIT)
    #undef IGN_STOP_SEC_VAR_CAL_32BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_CAL_32BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_VAR_CAL_UNSPECIFIED)
    #undef IGN_STOP_SEC_VAR_CAL_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_VAR_CAL_UNSPECIFIED
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_CONST_8BIT)
    #undef IGN_STOP_SEC_CONST_8BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_CONST_8BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_CONST_16BIT)
    #undef IGN_STOP_SEC_CONST_16BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_CONST_16BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_CONST_32BIT)
    #undef IGN_STOP_SEC_CONST_32BIT
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_CONST_32BIT
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_CONST_UNSPECIFIED)
    #undef IGN_STOP_SEC_CONST_UNSPECIFIED
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_CONST_UNSPECIFIED
    #include "MemMap.h"

#elif defined(IGN_STOP_SEC_CODE)
    #undef IGN_STOP_SEC_CODE
    #undef IGN_MEMMAP_ERROR
    #define STOP_SEC_CODE
    #include "MemMap.h"
#endif

#ifdef IGN_MEMMAP_ERROR
    #error ("IGN_MemMap error - no matching section")
#endif