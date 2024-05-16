/*
 * xcp_if.h
 *
 *  Created on: Feb 6, 2019
 *      Author: Mati
 */

#ifndef XCP_IF_H_
#define XCP_IF_H_


#ifdef XCP_IF_C_
#define EXTERNAL_ 
#else
#define EXTERNAL_ extern
#endif

void XcpTxHandler(void);
void XcpRxHandler(void);

void Xcp_RxStartIsr(void);
void Xcp_TxStopIsr(void);
void Xcp_RxStopIsr(void);

static void Set_XcpTxBsy(boolean val);
static boolean Get_XcpTxBsy(void);

static void Set_XcpRxBsy(boolean val);
static boolean Get_XcpRxBsy(void);

#ifdef EXTERNAL_
#undef EXTERNAL_
#endif

#endif /* XCP_IF_H_ */
