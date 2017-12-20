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

}
//---------------------------------------------------------------------------
// CheckSellSig
//---------------------------------------------------------------------------
bool CLSstockSig::CheckSellSig(int *necessaryQty)
{
    return (true);
}
//---------------------------------------------------------------------------
// GetCodeName
//---------------------------------------------------------------------------
char *CLSstockSig::GetCodeName()
{
    return (SInfo.stockNm);
}
