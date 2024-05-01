/*
 * IgnGov_Out.h
 *
 *  Created on: Dec 20, 2018
 *      Author: Mati
 */

#ifndef IGNGOV_OUT_H_
#define IGNGOV_OUT_H_

#include "Std_Types.h"
void Set_IgnEn(boolean value);
void Set_IgnAdv_Deg(sint16 value);
void Set_IgnTiDwl_uSec(sint16 value);
boolean Get_IgnEn(void);
sint16 Get_IgnAdv_Deg(void);
sint16 Get_IgnTiDwl_uSec(void);
#endif /*IGNGOV_OUT_H_*/