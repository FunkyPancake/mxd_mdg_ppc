#include "FuPmpCtrl_Out.h"



#define ACTR_START_SEC_VAR_FAST_8BIT
#include "ACTR_MemMap.h"
 	 volatile boolean FuPmpRlySt; 
#define ACTR_STOP_SEC_VAR_FAST_8BIT
#include "ACTR_MemMap.h"


 __inline__ void Set_FuPmpRlySt(boolean data)
 {
 	FuPmpRlySt = data;
 }
  
 boolean Get_FuPmpRlySt(void)
 {
 	return FuPmpRlySt;
 }