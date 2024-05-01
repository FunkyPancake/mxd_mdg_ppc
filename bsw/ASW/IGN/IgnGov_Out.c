#include "IgnGov_Out.h"

#define IGN_START_SEC_VAR_FAST_NOINIT_16BIT
#include "IGN_MemMap.h"
volatile static sint16 IgnAdv_Deg;
volatile static sint16 IgnTiDwl_uSec;
#define IGN_STOP_SEC_VAR_FAST_NOINIT_16BIT
#include "IGN_MemMap.h"

#define IGN_START_SEC_CODE
#include "IGN_MemMap.h"
void Set_IgnAdv_Deg(sint16 value)
{
	IgnAdv_Deg = value;
}
void Set_IgnTiDwl_uSec(sint16 value)
{
	IgnTiDwl_uSec = value;
}
sint16 Get_IgnAdv_Deg(void)
{
	return IgnAdv_Deg;
}
sint16 Get_IgnTiDwl_uSec(void)
{
	return IgnTiDwl_uSec;
}
#define IGN_STOP_SEC_CODE
#include "IGN_MemMap.h"