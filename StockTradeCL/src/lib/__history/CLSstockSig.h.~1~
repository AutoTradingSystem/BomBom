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
	bool isBuyCompleted;    // 매수 완료
	bool isSellCompleted;   // 매도 완료
	int buyQty;				// 매수 수량
	int sellQty;    		// 매도 수량
	int buyOrderQty;		// 매수 주문 량
	int sellOrderQty;   	// 매도 주문 량
	// 미체결 량은 OrderQry - buyQty
} TRADE_MNG;

#define TRADE_MNG_SIZE      sizeof(TRADE_MNG)
//---------------------------------------------------------------------------
// Class
//---------------------------------------------------------------------------
class CLSstockSig
{
private:

public:
	TSIG_INFO TSInfo;
	TRADE_MNG Mng;

	__fastcall CLSstockSig(void);
	__fastcall ~CLSstockSig(void);

    void Init(TradeSigInfo *pInfo);

};
//---------------------------------------------------------------------------
#endif  // CLSstockSigH
//---------------------------------------------------------------------------
// End of CLSstockSig.h
//---------------------------------------------------------------------------

