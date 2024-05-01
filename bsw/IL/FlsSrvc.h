/*
 * FlsSrvc.h
 *
 *  Created on: Feb 18, 2019
 *      Author: Mati
 */

#ifndef FLSSRVC_H_
#define FLSSRVC_H_
#ifdef FlsSrvc_C_
	#define EXTERNAL_
#else
	#define EXTERNAL_ extern
#endif

boolean Get_Fls_Srvc_StReq(void);
void Set_Fls_Srvc_StReq(boolean x);
void Fls_Srvc(void);
#ifdef EXTERNAL_
#undef EXTERNAL_
#endif
#endif /* FLSSRVC_H_ */
