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
	bool isBuyCompleted;    // �ż� �Ϸ�
	bool isSellCompleted;   // �ŵ� �Ϸ�
	int buyQty;				// �ż� ����
	int sellQty;    		// �ŵ� ����
	int buyOrderQty;		// �ż� �ֹ� ��
	int sellOrderQty;   	// �ŵ� �ֹ� ��
	// ��ü�� ���� OrderQry - buyQty
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

