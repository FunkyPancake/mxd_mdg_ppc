#include "CDD_MC33926_Out.h"

#define BSW_START_SEC_VAR_FAST_NOINIT_16BIT
#include "BSW_MemMap.h"
volatile static sint16 MC33926PwmDty;
#define BSW_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "BSW_MemMap.h"

#define BSW_START_SEC_CODE
#include "BSW_MemMap.h"
sint16 Get_MC33926PwmDty(void)
{
    return MC33926PwmDty;
}
void Set_MC33926PwmDty(sint16 value)
{
    MC33926PwmDty = value;
}
#define BSW_STOP_SEC_CODE
#include "BSW_MemMap.h"