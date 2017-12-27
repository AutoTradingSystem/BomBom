//---------------------------------------------------------------------------
// MtPacket41.cpp
// Author       :
// LastModify   : 2017.12
// Comment      :
// 매수 / 매도 매매 전송
//---------------------------------------------------------------------------

#pragma hdrstop
#include "SgPacket41.h"

//---------------------------------------------------------------------
SgPacket41::SgPacket41()
{
	clear();
}

//---------------------------------------------------------------------
void SgPacket41::clear()
{
	memset( buf, 0, sizeof(buf) );
	buf[0]  = 0x41;
	infoCnt = 0;
	setDataLength( 2 );
}

//---------------------------------------------------------------------
void SgPacket41::addReceiptInfo(LP_TradHis pInfo)
{
	int off = IOP_HEADER_SIZE + infoCnt*INFO_DATA_SIZE;  // +2;

	buf[off++] = pInfo->MARK;
	buf[off++] = pInfo->TIME_MON;
	buf[off++] = pInfo->TIME_DAY;
	buf[off++] = pInfo->TIME_HOUR;
	buf[off++] = pInfo->TIME_MIN;
	memcpy( &buf[off], pInfo->S_CODE, 7 ); off+=7;
	memcpy( &buf[off], pInfo->S_NAME, 32); off+=32;
	setInt4(buf,off, pInfo->PRICE); off+=4;

	infoCnt++;
	buf[IOP_HEADER_SIZE] = infoCnt;
	setDataLength( infoCnt*INFO_DATA_SIZE+1);
}


//---------------------------------------------------------------------
// STATIC FUNCTION
//---------------------------------------------------------------------

//---------------------------------------------------------------------
AnsiString SgPacket41::toString(char* pData)
{
	AnsiString str;
	AnsiString strRcpt;
	int infoCnt;
	RECEIPT Info;

	int off = 0;

	str = "";

	infoCnt = getUInt2( pData, off ); off+=2;
	for( int i=0; i<infoCnt; i++)
	{
		ZeroMemory( &Info, sizeof(RECEIPT) );
		memcpy( Info.RCPT_NO,   &pData[off], 18 ); off+=18;
		Info.ISPT_DIV_CD = pData[off++];
		Info.ISPT_TP     = pData[off++];
		memcpy( Info.VIN,       &pData[off], 18 ); off+=18;
		memcpy( Info.VH_REG_NO, &pData[off], 20 ); off+=20;

		off+=35;

		strRcpt.printf(
		"[%d] 접수: %s %d %d 차량: %s %s\r\n"
		, i+1
		, Info.RCPT_NO
		, Info.ISPT_DIV_CD
		, Info.ISPT_TP
		, Info.VIN
		, Info.VH_REG_NO  );
		str+= strRcpt;
	}
	return str;
}

//---------------------------------------------------------------------

