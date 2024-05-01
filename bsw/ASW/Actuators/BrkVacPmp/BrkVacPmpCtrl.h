/*
 * BrkVacPmpCtrl.h
 *
 *  Created on: May 2, 2019
 *      Author: Mati
 */

#ifndef BRKVACPMPCTRL_H_
#define BRKVACPMPCTRL_H_

typedef enum {
     BrkBostSt_Init
    ,BrkBostSt_On
    ,BrkBostSt_Off
}BrkBstStateEnum;

void BrkVacPmpCtrl(void);

#endif /* BRKVACPMPCTRL_H_ */
