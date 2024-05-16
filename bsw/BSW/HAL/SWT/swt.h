/*
 * swt.h
 *
 *  Created on: Dec 30, 2018
 *      Author: Mati
 */

#ifndef SWT_H_
#define SWT_H_

#ifdef swt_C_
#define EXTERNAL_ 
#else
#define EXTERNAL_ extern
#endif
#define STD_KEY 
void SWT_Setup(uint32 timeout);
void SWT_Init(void);
void SWT_Enable(void);
void SWT_Disable(void);
void SWT_KickTheDog(void);
void SWT_SetWindow(uint32 window);
#ifdef EXTERNAL_
#undef EXTERNAL_
#endif
#endif /* SWT_H_ */
