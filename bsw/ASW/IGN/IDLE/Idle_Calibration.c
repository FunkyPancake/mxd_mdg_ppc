
#define IDLE_START_SEC_CAL_8BIT
#include "ASW_MemMap.h"
const volatile boolean Idle_bPidEn_P = FALSE;
#define IDLE_STOP_SEC_CAL_8BIT
#include "ASW_MemMap.h"

#define IDLE_START_SEC_CAL_16BIT
#include "ASW_MemMap.h"
const volatile sint16 Idle_EnThThr_P = 5;
const volatile sint16 Idle_EnThRpm_P = 2500;
const volatile sint16 Idle_PidSat_Deg_P = 50;
const volatile sint16 Idle_PidDbRpm_P = 50;
const volatile uint16 Idle_TskPrd_P = 5;
const volatile sint16 Idle_FanUL_Deg_P = 20;
#define IDLE_STOP_SEC_CAL_16BIT
#include "ASW_MemMap.h"

#define IDLE_START_SEC_CAL_UNSPECIFIED
#include "ASW_MemMap.h"

const volatile sint16 Idle_TrgRpm_C[] = {5,0,20,30,50,80,1500,1200,1100,1000,900};

#define CAL_IDLE_ROW_SZ 14U
#define CAL_IDLE_COL_SZ 20U
// const volatile struct{
// 	sint16 Nx = 14U;
// 	sint16 Ny = 20U;
// 	sint16 Idle_MapClt_A
// }Idle_MapAdv_M
const volatile sint16 Idle_MapClt_A[CAL_IDLE_ROW_SZ] = {-10,0,10,20,30,40,50,55,60,65,70,80,90,100};
const volatile sint16 Idle_MapRpm_A[CAL_IDLE_COL_SZ] = {200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100};
const volatile sint16 Idle_MapAdv_M[CAL_IDLE_ROW_SZ*CAL_IDLE_COL_SZ] = {
		150,150,150,150,150,150,150,150,150,150,150,150,150,150,100,100,50,20,20,100,
		150,150,150,150,150,150,150,150,150,150,150,150,150,150,100,100,50,20,20,100,
		150,150,150,150,150,150,150,150,150,150,150,150,150,100,50,20,20,100,100,100,
		150,150,150,150,150,150,150,150,150,150,150,100,50,20,20,100,100,100,100,100,
		150,150,150,150,150,150,150,150,150,150,150,30,20,20,100,100,100,100,100,100,
		150,150,150,150,150,150,150,100,150,150,150,20,20,20,100,100,100,100,100,100,
		160,160,160,160,150,150,100,100,100,30,20,20,50,50,50,100,100,100,100,100,
		160,160,160,150,150,100,100,100,30,20,20,50,50,50,100,100,100,100,100,100,
		160,160,160,150,150,150,100,100,100,30,20,20,50,50,50,100,100,100,100,100,
		150,150,150,150,150,100,100,100,150,150,20,20,50,50,100,100,100,100,100,100,
		150,150,150,100,100,100,30,20,20,50,50,50,100,100,100,100,100,100,100,100,
		150,150,150,100,100,100,30,20,20,50,50,50,100,100,100,100,100,100,100,100,
		150,150,150,100,100,100,30,20,20,50,50,50,100,100,100,100,100,100,100,100,
		150,150,150,100,100,100,30,20,20,50,50,50,100,100,100,100,100,100,100,100,
};
#define IDLE_STOP_SEC_CAL_UNSPECIFIED
#include "ASW_MemMap.h"

#define IDLE_START_SEC_VAR_NOINIT_16BIT
#include "ASW_MemMap.h"
volatile static sint16 Idle_AdvPid_Deg;
volatile static sint16 Idle_AdvBase_Deg;
volatile static uint16 Idle_LoopTim;
#define IDLE_STOP_SEC_VAR_NOINIT_16BIT
#include "ASW_MemMap.h"