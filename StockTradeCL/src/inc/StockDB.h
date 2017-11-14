//---------------------------------------------------------------------------

#ifndef StockDBH
#define StockDBH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
// Type Definition
//---------------------------------------------------------------------------
typedef struct
{
	unsigned short year;
	unsigned short mon;
	unsigned short day;
	unsigned short hour;
	unsigned short min;
	unsigned short sec;
	unsigned short mSec;
} SysTime;
extern SysTime sTime;
//---------------------------------------------------------------------------
typedef struct
{
	AnsiString str;
} TestMSG;
extern PACKAGE TestMSG RecvMsgLog;
extern PACKAGE TestMSG SendMsgLog;

typedef struct
{
	char type;
	BYTE mon;
	BYTE day;
	BYTE hour;
	BYTE minute;
	char stockCode[7];
	char stockNm[32];
	unsigned int price;
	bool valid;
} TradeInfo;

extern TradeInfo TDINFO;

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
