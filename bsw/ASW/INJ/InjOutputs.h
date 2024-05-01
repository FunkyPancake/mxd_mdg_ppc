/*
 * InjOutputs.h
 *
 *  Created on: May 1, 2019
 *      Author: Mati
 */

#ifndef INJOUTPUTS_H_
#define INJOUTPUTS_H_


boolean Get_Inj_bStModDis(void) ;
void Set_Inj_bStModDis(boolean x) ;

boolean Get_Inj_bOffCut(void) ;
void Set_Inj_bOffCut(boolean x) ;

real_t Get_Inj_StUpMod_Pct(void) ;
void Set_Inj_StUpMod_Pct(real_t x);

real_t Get_Inj_PulEnd_Deg(void);
void Set_Inj_PulEnd_Deg(real_t x);

real_t Get_Inj_PulDur_ms(void) ;
void Set_Inj_PulDur_ms(real_t x) ;

real_t Get_Inj_BseDur_ms(void) ;
void Set_Inj_BseDur_ms(real_t x);


real_t Get_Inj_AfrMod(void);
void Set_Inj_AfrMod(real_t x);


#endif /* INJOUTPUTS_H_ */
