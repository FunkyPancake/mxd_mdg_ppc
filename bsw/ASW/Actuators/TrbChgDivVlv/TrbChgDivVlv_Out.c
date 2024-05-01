#include "TrbChgDivVlv_Out.h"


#define ACTR_START_SEC_VAR_FAST_8BIT
#include "ACTR_MemMap.h"
volatile static uint8 TrbChgDivVlvDty_Pct;
#define ACTR_STOP_SEC_VAR_FAST_8BIT
#include "ACTR_MemMap.h"

void Set_TrbChgDivVlvDty_Pct(uint8 value)
{
    TrbChgDivVlvDty_Pct = value;
}
uint8 Get_TrbChgDivVlvDty_Pct(void)
{
    return TrbChgDivVlvDty_Pct;
}