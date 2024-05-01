/*
 * IgnGov.h
 *
 *  Created on: Dec 20, 2018
 *      Author: Mati
 */

#ifndef IGNGOV_H_
#define IGNGOV_H_


typedef enum{
Init,
Startup,
Normal,
Overrrun
}IgnAdvGovStateEnum;

void IgnAdvGov(void);
void IgnDwlTmeCalc(void);

#endif /* IGNGOV_H_ */
