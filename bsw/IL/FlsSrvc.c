/*
 * FlsSrvc.c
 *
 *  Created on: Feb 18, 2019
 *      Author: Mati
 */
#ifndef FlsSrvc_C_
#define FlsSrvc_C_
#endif

#include "Std_Types.h"
#include "FlsSrvc.h"
#include "MPC5644A.h"
#include "flash.h"
#include <string.h>

//#pragma push
//#pragma section all_types ".meas_ram" ".meas_ram"
volatile static boolean Fls_Srvc_StReq = 0;
//#pragma pop

boolean Get_Fls_Srvc_StReq(void) {
	return Fls_Srvc_StReq;
}

void Set_Fls_Srvc_StReq(boolean x) {
	Fls_Srvc_StReq = x;
}
typedef enum{
	EE_WAIT,
	EE_START,
	EE_CHECK,
	EE_WRITE,
	EE_ERASE,
	
}Fls_Srvc_St_e;

Fls_Srvc_St_e Fls_state = EE_WAIT;
#define EE_OFFSET_LIMIT 0x00002000
#define EE_BASE_ADR 0x00010000

__declspec(section ".rodata") uint64* ptr =(uint64*)((uint32)0x40008000);
__declspec(section ".rodata") const uint8 bank = 4;

//executed in main
void Fls_Srvc(void)
{
	static sint16 offset;
	register boolean st_rqst; 
	switch(Fls_state)
	{
	case EE_WAIT:
		st_rqst = Get_Fls_Srvc_StReq();
		if(st_rqst == STD_TRUE)
		{
			Fls_state = EE_START;
		}
			break;
	case EE_START:
		
		offset = 0;
		FlashUnlock_LMLR(bank);
		Fls_state = EE_ERASE;
		break;
	case EE_CHECK:
		if(FlashStatus_LMLR()==0)
		{
			if(offset == EE_OFFSET_LIMIT)
			{
				FlashFinish_LMLR();
				FlashLock_LMLR();
				Fls_state = EE_WAIT;
				Set_Fls_Srvc_StReq(STD_FALSE);
			}
			else
			{
				if(offset ==0)
					FlashFinish_LMLR();
				// FLASH_B.MCR.B.EHV = 0;
				FLASH_A.MCR.B.EHV = 0;
				Fls_state = EE_WRITE;
			}
		}
		break;
	case EE_WRITE:
		FlashWriteQWord_LMLR(ptr+offset,offset,EE_BASE_ADR);
		offset++;
		Fls_state = EE_CHECK;
		break;
	case EE_ERASE:
		if(PageIsBlank(EE_BASE_ADR,EE_OFFSET_LIMIT)==0)
		{
			FlashBlockErase_LMLR(EE_BASE_ADR,bank);
			Fls_state = EE_CHECK;
		}
		else
		{
			Fls_state = EE_WRITE;
		}
		break;
	default:
		Fls_state = EE_WAIT;
		break;
	}
	
}

#ifdef FlsSrvc_C_
#undef FlsSrvc_C_
#endif
