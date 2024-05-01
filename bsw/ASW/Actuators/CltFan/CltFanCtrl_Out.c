#include "CltFanCtrl_Out.h"

#define ACTR_START_SEC_VAR_FAST_8BIT
#include "ACTR_MemMap.h"
	volatile static boolean CltFanRlySt;
#define ACTR_STOP_SEC_VAR_FAST_8BIT
#include "ACTR_MemMap.h"		
	
boolean	Get_CltFanRlySt(void)
{
	return CltFanRlySt;
}
void Set_CltFanRlySt(boolean x)	
{
	CltFanRlySt = x;
}