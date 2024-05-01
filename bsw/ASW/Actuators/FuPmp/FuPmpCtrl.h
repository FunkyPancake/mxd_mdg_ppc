/*
 * FuPmpCtrl.h
 *
 *  Created on: Apr 11, 2019
 *      Author: Mati
 */

#ifndef FUPMPCTRL_H_
#define FUPMPCTRL_H_
#include "Std_Types.h"
typedef enum
{
    Init,
    Prime,
    On,
    Off
} FuPmpCtrlStateEnum;

void FuPmpCtrl(void);

#endif /* FUPMPCTRL_H_ */
