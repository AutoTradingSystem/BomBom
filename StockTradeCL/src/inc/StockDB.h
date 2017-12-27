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
	int totalOrderablePrice;	// 총 매수 가능 금액
	int maxOrderCnt;            // 최대 매수 종목 수
	int buyPriceConf;			// 매수 가격 설정
	int sellPriceConf;			// 매도 가격 설정
	int sigValidTime;			// 시그널 유효 시간
}SignalConf;
extern PACKAGE SignalConf SigConf;

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

extern  TradeSigInfo TDSINFO;
extern  TradeSigInfo TDTotalBuyINFO[100];
extern  TradeSigInfo TDTotalSellINFO[100];
//---------------------------------------------------------------------------
// Order Info
//---------------------------------------------------------------------------
typedef struct
{
	String orderNo;     	// 주문번호
	String orderCode;   	// 종목 코드
	String orderSts;    	// 주문 상태
	String orderNm; 		// 종목 명
	String orderQty;    	// 주문 량
	String orderPrice;  	// 주문 가격
	String michegyeolQry;	// 미체결 량
	String chegyeolSumMoney;	// 체결 누계 금액
	String oneOrderNo;  	// 원주문번호
	String orderType;   	// 주문구분
	String tradeType;   	// 매매구분
	String time;    		// 주문 체결 시간
	String chegyeolNo;		// 체결번호
	String chegyeolPrice; 	// 체결 가격
	String chegyeolQry; 	// 체결량
	String currentPrice;    // 현재 가격
	String firstSellPrice;	// 최우선 매도 호가
	String firstBuyPrice;	// 최우선 매수 호가
	String denyReason;      // 거부 사유
	String screenNo;        // 화면번호
	String holdQty; 		// 보유 수량
	String totalBuyPrice;   // 총 매입 단가
	String orderableQty;    // 주문 가능 수량
	String basePrice;   	// 기준가
} OrderInfo;

extern PACKAGE OrderInfo OrdInfo;

//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
