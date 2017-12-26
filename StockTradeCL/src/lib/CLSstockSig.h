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
	int buyQty;				// �ż� ���� (�ż� ü�ᷮ)
	int sellQty;    		// �ŵ� ���� (�ŵ� ü�ᷮ)
	int buyOrderQty;		// �ż� �ֹ� ��
	int sellOrderQty;   	// �ŵ� �ֹ� ��
	int buySignPrice;		// �ŵ� ü�� ����
	int sellSignPrice;		// �ż� ü�� ����
	// ��ü�� ���� OrderQry - buyQty
} TRADE_MNG;

#define TRADE_MNG_SIZE      sizeof(TRADE_MNG)
//---------------------------------------------------------------------------
// �ֽ� ü�� ����
//---------------------------------------------------------------------------
typedef enum { ZERO_CONCLUSION, PART_CONCLUSION, ALL_CONCLUSION } CONCLUSION_STAT; 	//( ü�� ����, �Ϻ� ü��, ��� ü��)
//---------------------------------------------------------------------------
// TradeInfo OPR
//---------------------------------------------------------------------------
typedef struct
{
	bool IgnoreSell;            // Sell ��ȣ ���� ���� (ture : ����)
	bool IgnoreBuy;             // Buy ��ȣ ���� ���� (ture : ����)
	CONCLUSION_STAT stsSell;    // Sell ��ȣ ü�� ����
	CONCLUSION_STAT stsBuy;     // Buy ��ȣ ü�� ����
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
	TRADE_MNG Mng;  		// �ż��ŵ� ����
	TRADE_OPR Opr;          // ü�� ���� (ü�� ���� �� ��ȣ�� ���� �� ������.)


	__fastcall CLSstockSig(void);
	__fastcall ~CLSstockSig(void);

	void InitSell(TradeSigInfo *pInfo);
	void InitBuySig(TradeSigInfo *pInfo);

	void SetSellOrderQty(int qty);  // �ŵ� �ֹ���
	void SetBuyOrderQty(int qty);   // �ż� �ֹ���
	void SetSellQty(int qty);		// �ŵ���.
	void SetBuyQty(int qty);        // �ż���.

	bool SellIgnore(void);          // �ŵ� ������ ������.
	bool BuyIgnore(void);   		// �ż� ������ ������.

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

