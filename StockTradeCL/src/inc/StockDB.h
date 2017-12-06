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
	String accNo;   // ���� ��ȯ
	String accCnt;  // ���� ��
	String keyBs;   // Ű���� ����
	String fireSe;  // ��ȭ�� ��������
}USERINFO;
extern PACKAGE USERINFO UInfo;

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
