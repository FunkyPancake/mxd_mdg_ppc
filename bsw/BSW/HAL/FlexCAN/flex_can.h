/*
 * flex_can.h
 *
 *  Created on: May 26, 2019
 *      Author: Mati
 */

#ifndef FLEX_CAN_H_
#define FLEX_CAN_H_
#ifdef FLEX_CAN_C_
	#define EXTERNAL_
#else
	#define EXTERNAL_ extern
#endif
#include "ComStack_Types.h"
#include "Can_Cfg.h"
#include "Can_GeneralTypes.h"
#include "OS.h" //GetCounterValue

void Can_Init(const Can_ConfigType* Config);
void Can_GetVersionInfo(Std_VersionInfoType* versioninfo);
void Can_DeInit(void);
Std_ReturnType Can_SetBaudrate(uint8 Controller,uint16 BaudRateConfigID);
Std_ReturnType Can_SetControllerMode(uint8 Controller,Can_ControllerStateType Transition);
void Can_DisableControllerInterrupts(uint8 Controller);
void Can_EnableControllerInterrupts(uint8 Controller);
Std_ReturnType Can_CheckWakeup(uint8 Controller);
Std_ReturnType Can_GetControllerErrorState(uint8 ControllerId,Can_ErrorStateType* ErrorStatePtr);
Std_ReturnType Can_GetControllerMode(uint8 Controller,Can_ControllerStateType* ControllerModePtr);

/*Services affecting hardware handle */
Std_ReturnType Can_Write(Can_HwHandleType Hth,const Can_PduType* PduInfo);

/* Scheduled functions */
void Can_MainFunction_Write(void);
void Can_MainFunction_Read(void);
void Can_MainFunction_BusOff(void);
void Can_MainFunction_Wakeup(void);
void Can_MainFunction_Mode(void);
#ifdef EXTERNAL_
#undef EXTERNAL_
#endif
#endif /* FLEX_CAN_H_ */
