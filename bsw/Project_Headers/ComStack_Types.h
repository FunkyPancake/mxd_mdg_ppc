#ifndef COMSTACK_TYPES_H
#define COMSTACK_TYPES_H

#include "Std_Types.h"
#include "ComStack_Cfg.h"
typedef struct 
{
    uint8* SduDataPtr;
    uint8* MetaDataPtr;
    PduLengthType SduLength;
}PduInfoType;


typedef uint8 PNCHandleType;

typedef enum 
{
    TP_STMIN,
    TP_BS,
    TP_BC
}TPParameterType;

typedef enum
{
    BUFREQ_OK,
    BUFREQ_E_NOT_OK,
    BUFREQ_E_BUSY,
    BUFREQ_E_OVFL
}BufReq_ReturnType;

typedef enum 
{
    TP_DATACONF,
    TP_DATARETRY,
    TP_CONFPENDING
}TpDataStateType;

trypedef struct 
{
   TpDataStateType TpDataState;
   PduLengthType TxTpDataCnt;
}RetryInfoType;

typedef uint8 NetworkHandleType;

typedef uint8 IcomConfigIdType;

typedef enum
{
    ICOM_SWITCH_E_OK,
    ICOM_SWITCH_E_FAILED
}IcomSwitch_ErrorType;


#endif /* COMSTACK_TYPES_H */
