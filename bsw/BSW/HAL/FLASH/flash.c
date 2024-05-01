/*
 * flash.c
 *
 *  Created on: Oct 31, 2016
 *      Author: Mati
 */


/*
*/
#include "MPC5644A.h"
#include "flash.h"
#include <string.h>

//in highspace data are interlevaed between flash_a and flash_b controller
//L4->
//L5->

uint8 FlashUnlock_HLR(uint8 block_num)
{
	FLASH_B.HLR.R = 0xB2B22222; //Write password to unlock flash modification
	FLASH_A.HLR.R = 0xB2B22222; //Write password to unlock flash modification
	if(FLASH_B.HLR.B.HBE != 1)
	{
		return 1;
	}
	if(FLASH_A.HLR.B.HBE != 1)
	{
		return 1;
	}
	FLASH_B.HLR.R &= ~(1<<block_num); //Unlock block n
	FLASH_A.HLR.R &= ~(1<<block_num); //Unlock block n
	return 0;
}

uint8 FlashUnlock_LMLR(uint8 block_num)
{
    FLASH_A.LMLR.R = 0xA1A11111; //Write password to unlock flash modification
    if(FLASH_A.LMLR.B.LME != 1)
    {
        return 1;
    }
    FLASH_A.LMLR.R &= ~(1<<block_num); //Unlock block n
    
    FLASH_A.SLMLR.R = 0xC3C33333; //Write password to unlock flash modification
    if(FLASH_A.SLMLR.B.SLE != 1)
    {
        return 1;
    }
    FLASH_A.SLMLR.R &= ~(1<<block_num); //Unlock block n
    return 0;
}

void FlashLock_HLR(void)
{
	FLASH_A.HLR.R = 0x3f;
	FLASH_B.HLR.R = 0x3f;
}

void FlashLock_LMLR(void)
{
    FLASH_A.LMLR.R = 0x3f;
}

uint8 FlashBlockErase_HLR(uint32 page_start_addr,uint8 block_num)
{
	volatile uint64* ptr;
	FLASH_B.MCR.B.ERS = 1;
	FLASH_A.MCR.B.ERS = 1;
	FLASH_A.HSR.R = (1<<block_num);
	FLASH_B.HSR.R = (1<<block_num);
	ptr = (uint64*)(page_start_addr+0x10);
	*ptr = 0xffffffff;
	FLASH_B.MCR.B.EHV =1;
	ptr = (uint64*)page_start_addr;
	*ptr = 0xffffffff;
	FLASH_A.MCR.B.EHV =1;
	return 0;
}

uint8 FlashBlockErase_LMLR(uint32 page_start_addr,uint8 block_num)
{
    volatile uint64* ptr;
    FLASH_A.MCR.B.ERS = 1;
    FLASH_A.LMSR.R = (1<<block_num);
    ptr = (uint64*)page_start_addr;
    *ptr = 0xffffffff;
    FLASH_A.MCR.B.EHV =1;
    return 0;
}

uint64*  FlashWriteQWord_HLR(uint64* data,uint32 adr_offset,uint32 page_start_addr)
{
	uint64 * ptr = (uint64 *) page_start_addr;
	FLASH_B.MCR.B.PGM = 1;
	FLASH_A.MCR.B.PGM = 1;
	ptr += adr_offset;
	*ptr = *data;
	FLASH_B.MCR.B.EHV =1;
	FLASH_A.MCR.B.EHV =1;
	return ptr; 
}

uint64*  FlashWriteQWord_LMLR(uint64* data,uint32 adr_offset,uint32 page_start_addr)
{
    uint64 * ptr = (uint64 *) page_start_addr;
    FLASH_A.MCR.B.PGM = 1;
    ptr += adr_offset;
    *ptr = *data;
    FLASH_A.MCR.B.EHV =1;
    return ptr; 
}

uint8 FlashStatus_HLR(void)
{
	if(FLASH_B.MCR.B.DONE == 1 && FLASH_A.MCR.B.DONE == 1)
	{
		if(FLASH_B.MCR.B.PEG ==1 && FLASH_A.MCR.B.PEG ==1)
		{
			return 0;
		}
		return 1;
	}
	return 2;
}

uint8 FlashStatus_LMLR(void)
{
    if(FLASH_A.MCR.B.DONE == 1)
    {
        if(FLASH_A.MCR.B.PEG ==1)
        {
            return 0;
        }
        return 1;
    }
    return 2;
}

void FlashFinish_HLR(void)
{
			FLASH_B.MCR.B.EHV = 0;
			FLASH_B.MCR.B.ERS = 0;
			FLASH_B.MCR.B.PGM = 0;
			FLASH_A.MCR.B.EHV = 0;
			FLASH_A.MCR.B.ERS = 0;
			FLASH_A.MCR.B.PGM = 0;
}

void FlashFinish_LMLR(void)
{
            FLASH_A.MCR.B.EHV = 0;
            FLASH_A.MCR.B.ERS = 0;
            FLASH_A.MCR.B.PGM = 0;
}

uint8 PageIsBlank(uint32 page_start_addr, uint32 page_size)
{
      uint32 * ptr32 = (uint32 *) page_start_addr;  // faster to do 4 bytes at a time
      int i;

      for (i = 0; i < page_size; i += sizeof(uint32)) 
      {
          if (*ptr32  != 0xffffffff)  // 0xff is value of erased flash
             return 0;
          ++ptr32;                  // move to next word
      } 
      return 1;
}
