#include "IL_Tasks.h"
#include "IL_GPIO.h"
#include "IL_An.h"
#include "IL_PWM.h"

#define IL_START_SEC_CODE
#include "IL_MemMap.h"
void Task_IL_Pre_100ms()
{
	IL_An_100ms();
}

void Task_IL_Post_100ms()
{
	//    IL_BrkPmpRlyGpio();
	//    IL_FuPmpRlyGpio();
	//    IL_CltFanRlyGpio();
}

void Task_IL_Pre_20ms()
{
	IL_An_20ms();
}

void Task_IL_Post_20ms()
{
	IL_PWM_20ms();
}

void Task_IL_Pre_1ms()
{
	IL_An_1ms();
}

void Task_IL_Post_1ms()
{
}

void Task_IL_Pre_Async()
{
}

void Task_IL_Post_Async()
{
}
#define IL_STOP_SEC_CODE
#include "IL_MemMap.h"
