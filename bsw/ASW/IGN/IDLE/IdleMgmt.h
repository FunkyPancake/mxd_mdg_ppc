/*
 * EngIdle_Mgmt.h
 *
 *  Created on: Dec 23, 2018
 *      Author: Mati
 */

#ifndef IDLE_MGMT_H_
#define IDLE_MGMT_H_

typedef enum{
Intit,
Off,
Lock,
On
}IdleSpdGovStateEnum;

void IdleSpdGov(void);

#endif /* ENGIdle_MGMT_H_ */
