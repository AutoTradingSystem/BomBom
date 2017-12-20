//---------------------------------------------------------------------------

#ifndef StockDBH
#define StockDBH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
// System
//---------------------------------------------------------------------------
typedef struct
{
	bool Terminate;
}SYSTEM;
extern SYSTEM StockSYS;
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

//---------------------------------------------------------------------------
// User information
//---------------------------------------------------------------------------
typedef struct
{
	String uName;
	String uID;
	String accNo;   // 계좌 반환
	String accCnt;  // 계좌 수
	String keyBs;   // 키보드 보안
	String fireSe;  // 방화벽 설정여부
}USERINFO;
extern PACKAGE USERINFO UInfo;

//---------------------------------------------------------------------------
// User information
//---------------------------------------------------------------------------
typedef struct
{
	String Deposit;
	String Deposit2;
	String TotalPurchase;
	String Day_P_L_Rate;
	String CumulativeRate;  // 누적 손익율
	String CumulativePrice; // 누적 투자 손익
}ACCINFO;
extern PACKAGE ACCINFO AccInfo;

//---------------------------------------------------------------------------
// TradeInfo SIG
//---------------------------------------------------------------------------
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
} TradeSigInfo;

extern TradeSigInfo TDSINFO;

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
