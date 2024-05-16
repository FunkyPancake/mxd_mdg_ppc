#ifndef CAN_GENERAL_TYPES
#define CAN_GENERAL_TYPES

typedef struct{
    PduIdType swPduHandle;
    uint8 length;
    Can_IdType id;
    uint8* sdu;
}Can_PduType;

/*  
 *  Represents the Identifier of an L-PDU. 
 *  The two most significant bits specify the frame type:
 *  00 CAN message with Standard CAN ID
 *  01 CAN FD frame with Standard CAN ID
 *  10 CAN message with Extended CAN ID
 *  11 CAN FD frame with Extended CAN ID
 */
typedef uint32 Can_IdType;

typedef uint8 Can_HwHandleType;

typedef struct
{
    Can_IdType CanId;
    Can_HwHandleType Hoh;
    uint8 ControllerId;
}Can_HwType;

#define CAN_BUSY 0x02

typedef enum 
{
    CAN_ERRORSTATE_ACTIVE,
    CAN_ERRORSTATE_PASSIVE,
    CAN_ERRORSTATE_BUSOFF
}Can_ErrorStateType;

typedef enum 
{
    CAN_CS_UNINIT,
    CAN_CS_STARTED,
    CAN_CS_STOPPED,
    CAN_CS_SLEEP
}Can_ControllerStateType;
#endif /*end CAN_GENERAL_TYPES */