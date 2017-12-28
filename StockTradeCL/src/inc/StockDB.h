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
extern PACKAGE TestMSG SysMsgLog;

//---------------------------------------------------------------------------
// Signal order configuration
//---------------------------------------------------------------------------
typedef struct
{
	int totalOrderablePrice;	// �� �ż� ���� �ݾ�
	int maxOrderCnt;            // �ִ� �ż� ���� ��
	int buyPriceConf;			// �ż� ���� ����
	int sellPriceConf;			// �ŵ� ���� ����
	int sigValidTime;			// �ñ׳� ��ȿ �ð�
}SignalConf;
extern PACKAGE SignalConf SigConf;

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
// User information
//---------------------------------------------------------------------------
typedef struct
{
	String Deposit;
	String Deposit2;
	String TotalPurchase;
	String Day_P_L_Rate;
	String CumulativeRate;  // ���� ������
	String CumulativePrice; // ���� ���� ����
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

extern  TradeSigInfo TDSINFO;
extern  TradeSigInfo TDTotalBuyINFO[100];
extern  TradeSigInfo TDTotalSellINFO[100];
//---------------------------------------------------------------------------
// Order Info
//---------------------------------------------------------------------------
typedef struct
{
	String orderNo;     	// �ֹ���ȣ
	String orderCode;   	// ���� �ڵ�
	String orderSts;    	// �ֹ� ����
	String orderNm; 		// ���� ��
	String orderQty;    	// �ֹ� ��
	String orderPrice;  	// �ֹ� ����
	String michegyeolQry;	// ��ü�� ��
	String chegyeolSumMoney;	// ü�� ���� �ݾ�
	String oneOrderNo;  	// ���ֹ���ȣ
	String orderType;   	// �ֹ�����
	String tradeType;   	// �Ÿű���
	String time;    		// �ֹ� ü�� �ð�
	String chegyeolNo;		// ü���ȣ
	String chegyeolPrice; 	// ü�� ����
	String chegyeolQry; 	// ü�ᷮ
	String currentPrice;    // ���� ����
	String firstSellPrice;	// �ֿ켱 �ŵ� ȣ��
	String firstBuyPrice;	// �ֿ켱 �ż� ȣ��
	String denyReason;      // �ź� ����
	String screenNo;        // ȭ���ȣ
	String holdQty; 		// ���� ����
	String totalBuyPrice;   // �� ���� �ܰ�
	String orderableQty;    // �ֹ� ���� ����
	String basePrice;   	// ���ذ�
} OrderInfo;

extern PACKAGE OrderInfo OrdInfo;

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
