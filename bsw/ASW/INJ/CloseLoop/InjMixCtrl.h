/*
 * Inj_MixCtrl.h
 *
 *  Created on: Feb 16, 2019
 *      Author: Mati
 */

#ifndef INJMIXCTRL_H_
#define INJMIXCTRL_H_

#ifdef InjMixCtrl_C_
	#define EXTERNAL_
#else
	#define EXTERNAL_ extern
#endif

void InjCalcAfrMod(void);
boolean InjEnAfr(void);

#ifdef EXTERNAL_
#undef EXTERNAL_
#endif
#endif /* INJ_MIXCTRL_H_ */
