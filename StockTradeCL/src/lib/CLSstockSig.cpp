//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include "CLSstockSig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// CLSstockSig
//---------------------------------------------------------------------------
__fastcall CLSstockSig::CLSstockSig(void)
{
	memset(&SInfo, 0, TSIG_INFO_SIZE);
	memset(&BInfo, 0, TSIG_INFO_SIZE);
	memset(&Mng, 0, TRADE_MNG_SIZE);
	memset(&Opr, 0, TRADE_OPR_SIZE);

	m_sellGridIdx = 0;
    m_buyGridIdx = 0;
}
//---------------------------------------------------------------------------
// ~CLSstockSig
//---------------------------------------------------------------------------
__fastcall CLSstockSig::~CLSstockSig(void)
{
}
//---------------------------------------------------------------------------
// InitSell
//---------------------------------------------------------------------------
void CLSstockSig::InitSell(TradeSigInfo *pInfo)
{
	// Init Sell sig info
	memset(&SInfo, 0, TSIG_INFO_SIZE);
	SInfo.type = pInfo->type;
	SInfo.mon = pInfo->mon;
	SInfo.day = pInfo->day;
	SInfo.hour = pInfo->hour;
	SInfo.minute = pInfo->minute;
	sprintf(SInfo.stockCode, "%s", pInfo->stockCode);
	sprintf(SInfo.stockNm, "%s", pInfo->stockNm);
	SInfo.price = pInfo->price;
}
//---------------------------------------------------------------------------
// InitBuySig
//---------------------------------------------------------------------------
void CLSstockSig::InitBuySig(TradeSigInfo *pInfo)
{
// Init Sell sig info
	memset(&BInfo, 0, TSIG_INFO_SIZE);
	BInfo.type = pInfo->type;
	BInfo.mon = pInfo->mon;
	BInfo.day = pInfo->day;
	BInfo.hour = pInfo->hour;
	BInfo.minute = pInfo->minute;
	sprintf(BInfo.stockCode, "%s", pInfo->stockCode);
	sprintf(BInfo.stockNm, "%s", pInfo->stockNm);
	BInfo.price = pInfo->price;
}
//---------------------------------------------------------------------------
// SetSellOrderQty
//---------------------------------------------------------------------------
void CLSstockSig::SetSellOrderQty(int qty)
{
	Mng.sellOrderQty = qty;
}
//---------------------------------------------------------------------------
// SetBuyOrderQty
//---------------------------------------------------------------------------
void CLSstockSig::SetBuyOrderQty(int qty)
{
	Mng.buyOrderQty = qty;
}
//---------------------------------------------------------------------------
// SetSellQty
//---------------------------------------------------------------------------
void CLSstockSig::SetSellQty(int qty)
{
	Mng.sellQty = qty;
}
//---------------------------------------------------------------------------
// SetBuyQty
//---------------------------------------------------------------------------
void CLSstockSig::SetBuyQty(int qty)
{
	Mng.buyQty = qty;
}
//---------------------------------------------------------------------------
// SellIgnore
//---------------------------------------------------------------------------
bool CLSstockSig::SellIgnore(void)
{
	m_curTime = ((sTime.mon*1000000)
				+(sTime.day*10000)
				+(sTime.hour*100)
				+(sTime.min));

	int sigTm = ((SInfo.mon*1000000)
				+(SInfo.day*10000)
				+(SInfo.hour*100)
				+(SInfo.minute));

	int tmSub = m_curTime - sigTm;
	if (tmSub > IGNORE_TIME) {
		Opr.IgnoreSell = true;
		return (true);
	}

	return (false);
}
//---------------------------------------------------------------------------
// BuyIgnore
//---------------------------------------------------------------------------
bool CLSstockSig::BuyIgnore(void)
{
	m_curTime = ((sTime.mon*1000000)
				+(sTime.day*10000)
				+(sTime.hour*100)
				+(sTime.min));

	int sigTm = ((BInfo.mon*1000000)
				+(BInfo.day*10000)
				+(BInfo.hour*100)
				+(BInfo.minute));

	int tmSub = m_curTime - sigTm;
	if (tmSub > IGNORE_TIME) {
		Opr.IgnoreBuy = true;
		return (true);
	}

	return (false);
}
//---------------------------------------------------------------------------
// GetCodeName
//---------------------------------------------------------------------------
char *CLSstockSig::GetCodeName()
{
	return (SInfo.stockNm);
}
//---------------------------------------------------------------------------
// SetGridIndex_Sell
//---------------------------------------------------------------------------
void CLSstockSig::SetGridIndex_Sell(int grdIdx)
{
	m_sellGridIdx = grdIdx;
}
//---------------------------------------------------------------------------
// GetGridIndex_Sell
//---------------------------------------------------------------------------
int CLSstockSig::GetGridIndex_Sell(void)
{
	return m_sellGridIdx;
}
//---------------------------------------------------------------------------
// SetGridIndex_Buy
//---------------------------------------------------------------------------
void CLSstockSig::SetGridIndex_Buy(int grdIdx)
{
	m_buyGridIdx = grdIdx;
}
//---------------------------------------------------------------------------
// GetGridIndex_Buy
//---------------------------------------------------------------------------
int CLSstockSig::GetGridIndex_Buy(void)
{
	return m_buyGridIdx;
}

