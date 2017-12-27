//---------------------------------------------------------------------------
// MtPacket41.h
// Author       :
// LastModify   : 2016.05
// Comment      : 접수정보 전송
//---------------------------------------------------------------------------
#ifndef SgPacket41H
#define SgPacket41H
//---------------------------------------------------------------------------
#include "SgPacket.h"
#include "Mios.h"

//----------------------------------------------------------------------------
class SgPacket41 : public SgPacket
{
private:
	int infoCnt;

public:
	static const int INFO_DATA_SIZE = 48; // 종목정보

	SgPacket41();

	void clear();
	void addReceiptInfo(LP_TradHis pInfo);

	//------------------------------------------------------------------------
	// STATIC FUNCTION
	//------------------------------------------------------------------------
	static AnsiString toString(char* pData);
};

//----------------------------------------------------------------------------
#endif

