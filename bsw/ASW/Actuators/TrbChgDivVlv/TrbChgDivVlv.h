#ifndef TRBCHGDIVVLV_H_
#define TRBCHGDIVVLV_H_

#include "Std_Types.h"

typedef enum
{
    Init,
    Off,
    Open,
    Hold
}TrbChgDivVlvStateEnum;

void TrbChgDivVlvCtrl(void);

#endif /*TRBCHGDIVVLV_H_*/
