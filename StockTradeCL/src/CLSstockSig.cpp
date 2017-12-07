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

}
//---------------------------------------------------------------------------
// ~CLSstockSig
//---------------------------------------------------------------------------
__fastcall CLSstockSig::~CLSstockSig(void)
{
}
//---------------------------------------------------------------------------
// Init
//---------------------------------------------------------------------------
void CLSstockSig::Init(TradeSigInfo *pInfo)
{
    memset(&TSInfo, 0, TSIG_INFO_SIZE);
	TSInfo.type = pInfo->type;
	TSInfo.mon = pInfo->mon;
	TSInfo.day = pInfo->day;
	TSInfo.hour = pInfo->hour;
	TSInfo.minute = pInfo->minute;
	sprintf(TSInfo.stockCode, "%s", pInfo->stockCode);
	sprintf(TSInfo.stockNm, "%s", pInfo->stockNm);
	TSInfo.price = pInfo->price;
}
