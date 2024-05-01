/*
 * flash.h
 *
 *  Created on: Mar 23, 2017
 *      Author: Mati
 */

#ifndef FLASH_H_
#define FLASH_H_

/*
 * flash.c
 *
 *  Created on: Oct 31, 2016
 *      Author: Mati
 */


/*
*/
#ifdef FLASH_C_
    #define EXTERNAL_ 
#else
    #define EXTERNAL_ extern   
#endif

/*
 * Set of Flash functions for High adress space
 */

void FlashLock_HLR(void);

uint8 FlashUnlock_HLR(uint8 block_num);

uint8 FlashBlockErase_HLR(uint32 page_start_addr,uint8 block_num);

uint64*  FlashWriteQWord_HLR(uint64* data,uint32 adr_offset,uint32 page_start_addr);

uint8 FlashStatus_HLR(void);

void FlashFinish_HLR(void);


/*
 * Set of Flash functions for Low and Medium adress space
 */


void FlashLock_LMLR(void);

uint8 FlashUnlock_LMLR(uint8 block_num);

uint8 FlashBlockErase_LMLR(uint32 page_start_addr,uint8 block_num);

uint64*  FlashWriteQWord_LMLR(uint64* data,uint32 adr_offset,uint32 page_start_addr);

uint8 FlashStatus_LMLR(void);

void FlashFinish_LMLR(void);


/*
 * Support functions for flash programming
 */

uint8 FlashPageIsBlank(uint8 block_num);


uint8 PageIsBlank(uint32 page_start_addr, uint32 page_size);


#ifdef EXTERNAL_
#undef EXTERNAL_
#endif

#endif /* FLASH_H_ */
