/*
 * flex_can.c
 *
 *  Created on: May 26, 2019
 *      Author: Mati
 */
#ifndef FLEX_CAN_C_
#define FLEX_CAN_C_
#endif

#include "Std_Types.h"
#include "flex_can.h"
#include "MPC5644A.h"

/* Equal Split between mailboxes:
 * 32 Tx bufs and 32Rx Bufs
 * Tx buf have idx 32 : 63
 */
typedef struct {
    uint32 id;
    uint32 data[2];
    uint16 timestamp;
    boolean b_ex_id;
    uint8 dlc;
} can_frame_t;
#define FLEXCAN_A 0u
#define FLEXCAN_B 1u
#define FLEXCAN_C 2u
typedef enum 
__inline__ void FlexCan_GetChnStruct(uint8 can_chn_idx,struct FLEXCAN2ag * can_struct)
{
    const struct FLEXCAN2ag * can_chn_ptr[2] =
    {
        &CAN_A,
        &CAN_B,
        &CAN_C
    };
    can_struct = can_chn_ptr[can_chn_idx];    
}

void Can_Init(const Can_ConfigType* Config)
{
    
}
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


#ifdef FLEX_CAN_C_
#undef FLEX_CAN_C_
#endif
