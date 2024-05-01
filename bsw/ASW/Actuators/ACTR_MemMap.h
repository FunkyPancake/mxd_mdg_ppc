#define ACTR_MEMMAP_ERROR

/*Section start*/
#if defined(ACTR_START_SEC_CODE)
    #undef ACTR_START_SEC_CODE
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_CODE
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_8BIT)
    #undef ACTR_START_SEC_VAR_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_8BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_16BIT)
    #undef ACTR_START_SEC_VAR_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_16BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_32BIT)
    #undef ACTR_START_SEC_VAR_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_32BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_UNSPECIFIED)
    #undef ACTR_START_SEC_VAR_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_UNSPECIFIED
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_NOINIT_8BIT)
    #undef ACTR_START_SEC_VAR_NOINIT_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_NOINIT_8BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_NOINIT_16BIT)
    #undef ACTR_START_SEC_VAR_NOINIT_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_NOINIT_16BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_NOINIT_32BIT)
    #undef ACTR_START_SEC_VAR_NOINIT_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_NOINIT_32BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef ACTR_START_SEC_VAR_NOINIT_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_NOINIT_UNSPECIFIED
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_STBY_8BIT)
    #undef ACTR_START_SEC_VAR_STBY_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_STBY_8BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_STBY_16BIT)
    #undef ACTR_START_SEC_VAR_STBY_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_STBY_16BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_STBY_32BIT)
    #undef ACTR_START_SEC_VAR_STBY_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_STBY_32BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_STBY_UNSPECIFIED)
    #undef ACTR_START_SEC_VAR_STBY_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_STBY_UNSPECIFIED
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_FAST_8BIT)
    #undef ACTR_START_SEC_VAR_FAST_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_8BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_FAST_16BIT)
    #undef ACTR_START_SEC_VAR_FAST_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_16BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_FAST_32BIT)
    #undef ACTR_START_SEC_VAR_FAST_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_32BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_FAST_UNSPECIFIED)
    #undef ACTR_START_SEC_VAR_FAST_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_UNSPECIFIED
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_FAST_NOINIT_8BIT)
    #undef ACTR_START_SEC_VAR_FAST_NOINIT_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_NOINIT_8BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_FAST_NOINIT_16BIT)
    #undef ACTR_START_SEC_VAR_FAST_NOINIT_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_NOINIT_16BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_FAST_NOINIT_32BIT)
    #undef ACTR_START_SEC_VAR_FAST_NOINIT_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_NOINIT_32BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
    #undef ACTR_START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_CAL_8BIT)
    #undef ACTR_START_SEC_VAR_CAL_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_CAL_8BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_CAL_16BIT)
    #undef ACTR_START_SEC_VAR_CAL_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_CAL_16BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_CAL_32BIT)
    #undef ACTR_START_SEC_VAR_CAL_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_CAL_32BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_VAR_CAL_UNSPECIFIED)
    #undef ACTR_START_SEC_VAR_CAL_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_VAR_CAL_UNSPECIFIED
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_CONST_8BIT)
    #undef ACTR_START_SEC_CONST_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_CONST_8BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_CONST_16BIT)
    #undef ACTR_START_SEC_CONST_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_CONST_16BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_CONST_32BIT)
    #undef ACTR_START_SEC_CONST_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_CONST_32BIT
    #include "MemMap.h"


#elif defined(ACTR_START_SEC_CONST_UNSPECIFIED)
    #undef ACTR_START_SEC_CONST_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define START_SEC_CONST_UNSPECIFIED
    #include "MemMap.h"


/*Section stops*/

#elif defined(ACTR_STOP_SEC_VAR_8BIT)
    #undef ACTR_STOP_SEC_VAR_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_8BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_16BIT)
    #undef ACTR_STOP_SEC_VAR_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_16BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_32BIT)
    #undef ACTR_STOP_SEC_VAR_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_32BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_UNSPECIFIED)
    #undef ACTR_STOP_SEC_VAR_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_UNSPECIFIED
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_NOINIT_8BIT)
    #undef ACTR_STOP_SEC_VAR_NOINIT_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_NOINIT_8BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_NOINIT_16BIT)
    #undef ACTR_STOP_SEC_VAR_NOINIT_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_NOINIT_16BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_NOINIT_32BIT)
    #undef ACTR_STOP_SEC_VAR_NOINIT_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_NOINIT_32BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
    #undef ACTR_STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_NOINIT_UNSPECIFIED
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_STBY_8BIT)
    #undef ACTR_STOP_SEC_VAR_STBY_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_STBY_8BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_STBY_16BIT)
    #undef ACTR_STOP_SEC_VAR_STBY_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_STBY_16BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_STBY_32BIT)
    #undef ACTR_STOP_SEC_VAR_STBY_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_STBY_32BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_STBY_UNSPECIFIED)
    #undef ACTR_STOP_SEC_VAR_STBY_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_STBY_UNSPECIFIED
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_FAST_8BIT)
    #undef ACTR_STOP_SEC_VAR_FAST_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_8BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_FAST_16BIT)
    #undef ACTR_STOP_SEC_VAR_FAST_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_16BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_FAST_32BIT)
    #undef ACTR_STOP_SEC_VAR_FAST_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_32BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_FAST_UNSPECIFIED)
    #undef ACTR_STOP_SEC_VAR_FAST_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_UNSPECIFIED
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_FAST_NOINIT_8BIT)
    #undef ACTR_STOP_SEC_VAR_FAST_NOINIT_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_NOINIT_8BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_FAST_NOINIT_16BIT)
    #undef ACTR_STOP_SEC_VAR_FAST_NOINIT_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_NOINIT_16BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_FAST_NOINIT_32BIT)
    #undef ACTR_STOP_SEC_VAR_FAST_NOINIT_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_NOINIT_32BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED)
    #undef ACTR_STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_FAST_NOINIT_UNSPECIFIED
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_CAL_8BIT)
    #undef ACTR_STOP_SEC_VAR_CAL_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_CAL_8BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_CAL_16BIT)
    #undef ACTR_STOP_SEC_VAR_CAL_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_CAL_16BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_CAL_32BIT)
    #undef ACTR_STOP_SEC_VAR_CAL_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_CAL_32BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_VAR_CAL_UNSPECIFIED)
    #undef ACTR_STOP_SEC_VAR_CAL_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_VAR_CAL_UNSPECIFIED
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_CONST_8BIT)
    #undef ACTR_STOP_SEC_CONST_8BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_CONST_8BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_CONST_16BIT)
    #undef ACTR_STOP_SEC_CONST_16BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_CONST_16BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_CONST_32BIT)
    #undef ACTR_STOP_SEC_CONST_32BIT
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_CONST_32BIT
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_CONST_UNSPECIFIED)
    #undef ACTR_STOP_SEC_CONST_UNSPECIFIED
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_CONST_UNSPECIFIED
    #include "MemMap.h"

#elif defined(ACTR_STOP_SEC_CODE)
    #undef ACTR_STOP_SEC_CODE
    #undef ACTR_MEMMAP_ERROR
    #define STOP_SEC_CODE
    #include "MemMap.h"
#endif

#ifdef ACTR_MEMMAP_ERROR
    #error ("ACTR_MemMap error - no matching section")
#endif