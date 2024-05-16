/*
 * dspi.h
 *
 *  Created on: Apr 9, 2016
 *      Author: Mati
 */

#ifndef DSPI_H_
#define DSPI_H_
#include "Std_Types.h"
// FIFO PUSH REGISTER
#define PUSHR_CONT (1 << 31)
#define PUSHR_CTAS(n) ((n) << (31 - 3))
#define PUSHR_EOQ (1 << (31 - 4))
#define PUSHR_CTCNT (1 << (31 - 5))
#define PUSHR_PE (1 << (31 - 6))
#define PUSHR_PP (1 << (31 - 7))
#define PUSHR_PCS(n) ((n) << (31 - 15))
#define PUSHR_DATA(n) (n)

// DSPI CTAR REGISTER
#define CTAR_DBR (1 << (31 - 0))
#define CTAR_FMSZ(n) ((n) << (31 - 4))
#define CTAR_CPOL (1 << (31 - 5))
#define CTAR_CPHA (1 << (31 - 6))
#define CTAR_LSBFE (1 << (31 - 7))
#define CTAR_PCSSCK(n) ((n) << (31 - 9))
#define CTAR_PASC(n) ((n) << (31 - 11))
#define CTAR_PDT(n) ((n) << (31 - 13))
#define CTAR_PBR(n) ((n) << (31 - 15))
#define CTAR_CSSCK(n) ((n) << (31 - 19))
#define CTAR_ASC(n) ((n) << (31 - 23))
#define CTAR_DT(n) ((n) << (31 - 27))
#define CTAR_BR(n) (n)

Std_ReturnType SPI_Config(void);
Std_ReturnType SPI_SetBaudrate(void);
Std_ReturnType SPI_TransmissionPoll(void);
Std_ReturnType SPI_AddJob(void);
Std_ReturnType SPI_Enable(void);
Std_ReturnType SPI_Disable(void);
Std_ReturnType SPI_ReadErrors(void);
Std_ReturnType SPI_ClearErrors(void);

#endif /* DSPI_H_ */
