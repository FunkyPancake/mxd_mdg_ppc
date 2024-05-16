/*****************************************************************************
 | Project Name:   XCP V1.0 - Driver
 |    File Name:   xcp_if.c
 |
 |  Description: 
 |   XCP driver custom module 
 |   This module provides the adaption to a particular platform
 |   It contains all platform specific functions
 |
 |***************************************************************************/
#ifndef IL_ESCI_C_
#define IL_ESCI_C_ 
#endif

#include "Std_Types.h"
#include "XcpBasic.h"
#include "esci.h"
#include "../../../os/eecfg.h"
#include "ee.h"

#define XCP_PACKET_CHECKSUM

//------------------------------------------------------------------------------

#ifdef XCP_INTERRUPT_CONTROL
unsigned char gInteruptLevel = 0;
unsigned char gInterupt = 0;
#endif

//------------------------------------------------------------------------------
// Transport Layer

#define SLIP_SYNC 0x9A
#define SLIP_ESC  0x9B

#if xcpMaxCTO>255
#error
#endif
static vuint8 XcpRxBuf[kXcpMaxCTO + 2];
static vuint8 XcpTxBuf[kXcpMaxCTO + 2]; // + Header + Checksum
static boolean XcpTxBsy;


static void Set_XcpTxBsy(boolean val)
{
	XcpTxBsy = val;
}
static boolean Get_XcpTxBsy(void)
{
	return XcpTxBsy;
}


static boolean XcpRxBsy;
static void Set_XcpRxBsy(boolean val)
{
	XcpRxBsy = val;
}
static boolean Get_XcpRxBsy(void)
{
	return XcpRxBsy;
}

static boolean XcpRxNew;
static void Set_XcpRxNew(boolean val)
{
	XcpRxNew = val;
}
static boolean Get_XcpRxNew(void)
{
	return XcpRxNew;
}

ISR2(Xcp_RxStartIsr)
{
	uint8 data;
	static uint8 i;
	data = ESCI_A_RxIsr();
	XcpRxBuf[0] = data; //first byte is always length
	ESCI_A_ReadDma((void*)(XcpRxBuf + 1), (uint16)(data + 1));
	Set_XcpRxBsy(STD_TRUE);
}

ISR2(Xcp_RxStopIsr)
{
	ESCI_A_RdmaIsr();
	Set_XcpRxBsy(STD_FALSE);
	Set_XcpRxNew(STD_TRUE);
}

ISR2(Xcp_TxStopIsr)
{
	ESCI_A_TdmaIsr();
	Set_XcpTxBsy(STD_FALSE);
}
static vuint8 xcpReceive(void)
{
	vuint8 idx = 0;
	vuint8 len = 0;
	vuint8 checksum = 0;

	if (Get_XcpRxBsy() == STD_TRUE)
	{
		return 0;
	}
	if(Get_XcpRxNew() == STD_TRUE)
	{
		for (;;)
		{
			len = XcpRxBuf[0]; // sBuf[0] always is the packet length
			// Check if this is a valid packet
			if (len == 0)
				return 0;
	
			// Verify checksum
	#ifdef XCP_PACKET_CHECKSUM_PLUS_LEN
			checksum = len;
	#else
			checksum = 0;
	#endif
			for (idx = 0; idx < len; idx++)
			{
				checksum += XcpRxBuf[idx + 1];
			}
	
	#ifdef XCP_PACKET_CHECKSUM
			if (checksum != XcpRxBuf[len + 1])
			{
				// Checksum error
				return 0;
			}
	#endif
			Set_XcpRxNew(STD_FALSE);
			return 1;
			
		}
	} // for (;;)
	return 0;
}



// Transmit a XCP packet
// Called by the XCP driver
void ApplXcpSend(vuint8 len, MEMORY_ROM BYTEPTR msg1 )
{
	
	vuint8 b;
	vuint8 idx =1;

	BYTEPTR msg = (BYTEPTR)msg1;
#ifdef XCP_PACKET_CHECKSUM
        vuint8 checksum;
#endif
        if (Get_XcpTxBsy() == STD_TRUE)
        {
                return;
        }
		if (len==0||len>kXcpMaxDTO)
		{
			return; // should not happen
	}
		XcpTxBuf[0] = len;
#ifdef XCP_PACKET_CHECKSUM
#ifdef XCP_PACKET_CHECKSUM_PLUS_LEN
		checksum = len;
#else
		checksum = 0;
#endif
#endif
		for (idx = 0;idx<len;idx++)
		{
			b = *msg++;
#ifdef XCP_PACKET_CHECKSUM
		checksum += b;
#endif
		XcpTxBuf[idx+1] = b;
		
	}
#ifdef XCP_PACKET_CHECKSUM
		XcpTxBuf[len+1] = checksum;
#endif 
		ESCI_A_WriteDma((void*)XcpTxBuf,(uint8)(len+2));
		Set_XcpTxBsy(STD_TRUE);
	}

vuint8 ApplXcpSendStall(void)
{

	while (!0)
		;
	XcpSendCallBack();
	return 1;
}

void XcpTxHandler(void)
{
	if (Get_XcpTxBsy() == STD_FALSE)
	{
		XcpSendCallBack();
	}
}

// Receive a XCP packet
void XcpRxHandler(void)
{
	if (xcpReceive())
	{
		XcpCommand((void*) &XcpRxBuf[1]);
	}
}
vuint8 ApplXcpUserService ( MEMORY_ROM BYTEPTR pCmd )
{
//	Set_Fls_Srvc_StReq(STD_TRUE);
	return XCP_CMD_OK ;
}
//------------------------------------------------------------------------------
// Platform dependend functions
// Convert a XCP address to a pointer
MTABYTEPTR ApplXcpGetPointer(vuint8 addr_ext, vuint32 addr)
{

	PARAM_UNUSED(addr_ext);
	return (MTABYTEPTR) addr;
}

#ifdef IL_ESCI_C_
#undef IL_ESCI_C_ 
#endif

