/*
 * fmpll.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Mati
 */

#ifndef FMPLL_H_
#define FMPLL_H_


#ifdef  FMPLL_C_
    #define EXTERNAL_ 
#else
    #define EXTERNAL_ extern   
#endif


void fmpll_config(void);

#ifdef EXTERNAL_
#undef EXTERNAL_
#endif

#endif /* FMPLL_H_ */
