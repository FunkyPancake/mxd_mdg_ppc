#ifndef BSW_TASKS_H_
#define BSW_TASKS_H_
void Task_BSW_Pre_100ms();
void Task_BSW_Post_100ms();

void Task_BSW_Pre_20ms();
void Task_BSW_Post_20ms();

void Task_BSW_Pre_1ms();
void Task_BSW_Post_1ms();

void Task_BSW_Pre_Async();
void Task_BSW_Post_Async();

void StartupHook_BSW(void);

#endif /*BSW_TASKS_H_*/