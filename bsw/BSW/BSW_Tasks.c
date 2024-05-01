
#include "BSW_Tasks.h"

#include "CDD_MC33926.h"
#include "EQADC_Cfg.h"

void Task_BSW_Pre_100ms()
{
	EQADC_ReadResults_100ms();
}
void Task_BSW_Post_100ms()
{
}

void Task_BSW_Pre_20ms()
{
	EQADC_ReadResults_20ms();
}
void Task_BSW_Post_20ms()
{
	CDD_MC33926_PwmCtrl();
}

void Task_BSW_Pre_1ms()
{
	EQADC_ReadResults_1ms();
}
void Task_BSW_Post_1ms()
{
}

void Task_BSW_Pre_Async()
{
}
void Task_BSW_Post_Async()
{
}
void StartupHook_BSW(void)
{
	CDD_MC33926_Init();
}