#include "BrkVacPmpCtrl_Out.h"

#define ACTR_START_SEC_VAR_FAST_8BIT
#include "ACTR_MemMap.h"
volatile static boolean BrkBostRlyEn;
#define ACTR_STOP_SEC_VAR_FAST_8BIT
#include "ACTR_MemMap.h"

void Set_BrkBostRlyEn(boolean x)
{
	BrkBostRlyEn = x;
}

boolean Get_BrkBostRlyEn(void)
{
	return BrkBostRlyEn;
}
