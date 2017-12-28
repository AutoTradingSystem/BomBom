//---------------------------------------------------------------------------

#ifndef CLSstockSigH
#define CLSstockSigH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include "StockDB.h"
#include "CLSlog.h"
//---------------------------------------------------------------------------
// Constant
//---------------------------------------------------------------------------
#define IGNORE_TIME 		3   // 3 minute
//---------------------------------------------------------------------------
// Type definition
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
} TSIG_INFO;

#define TSIG_INFO_SIZE      sizeof(TSIG_INFO)
//---------------------------------------------------------------------------
// TradeInfo Manage
//---------------------------------------------------------------------------
typedef struct
{
	int buyQty;				// 매수 수량 (매수 체결량)
	int sellQty;    		// 매도 수량 (매도 체결량)
	int buyOrderQty;		// 매수 주문 량
	int sellOrderQty;   	// 매도 주문 량
	int buySignPrice;		// 매도 체결 가격
	int sellSignPrice;		// 매수 체결 가격
	// 미체결 량은 OrderQry - buyQty
} TRADE_MNG;

#define TRADE_MNG_SIZE      sizeof(TRADE_MNG)
//---------------------------------------------------------------------------
// 주식 체결 상태
//---------------------------------------------------------------------------
typedef enum { ZERO_CONCLUSION, PART_CONCLUSION, ALL_CONCLUSION } CONCLUSION_STAT; 	//( 체결 없음, 일부 체결, 모두 체결)
//---------------------------------------------------------------------------
// TradeInfo OPR
//---------------------------------------------------------------------------
typedef struct
{
	bool IgnoreSell;            // Sell 신호 무시 상태 (ture : 무시)
	bool IgnoreBuy;             // Buy 신호 무시 상태 (ture : 무시)
	CONCLUSION_STAT stsSell;    // Sell 신호 체결 상태
	CONCLUSION_STAT stsBuy;     // Buy 신호 체결 상태
} TRADE_OPR;

#define TRADE_OPR_SIZE      sizeof(TRADE_OPR)
//---------------------------------------------------------------------------
// Class
//---------------------------------------------------------------------------
class CLSstockSig
{
private:
	int m_curTime;
	int m_sellGridIdx;
    int m_buyGridIdx;

public:
	TSIG_INFO SInfo;        // Sell sig info
	TSIG_INFO BInfo;        // Buy sig info
	TRADE_MNG Mng;  		// 매수매도 관리
	TRADE_OPR Opr;          // 체결 관리 (체결 상태 및 신호를 무시 할 것인지.)


	__fastcall CLSstockSig(void);
	__fastcall ~CLSstockSig(void);

	void InitSell(TradeSigInfo *pInfo);
	void InitBuySig(TradeSigInfo *pInfo);

	void SetSellOrderQty(int qty);  // 매도 주문량
	void SetBuyOrderQty(int qty);   // 매수 주문량
	void SetSellQty(int qty);		// 매도량.
	void SetBuyQty(int qty);        // 매수량.

	bool SellIgnore(void);          // 매도 무시할 것인지.
	bool BuyIgnore(void);   		// 매수 무시할 것인지.

	char *GetCodeName();

	void SetGridIndex_Sell(int grdIdx);
	int GetGridIndex_Sell(void);
	void SetGridIndex_Buy(int grdIdx);
	int GetGridIndex_Buy(void);
};
//---------------------------------------------------------------------------
#endif  // CLSstockSigH
//---------------------------------------------------------------------------
// End of CLSstockSig.h
//---------------------------------------------------------------------------

