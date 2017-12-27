//---------------------------------------------------------------------------

#pragma hdrstop

#include "StockDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// External Variable
//---------------------------------------------------------------------------
SysTime sTime;
TestMSG RecvMsgLog;
TestMSG SendMsgLog;
TestMSG SysMsgLog;
//---------------------------------------------------------------------------
SYSTEM StockSYS;
SignalConf SigConf;
USERINFO UInfo;
ACCINFO AccInfo;
TradeSigInfo TDSINFO;
TradeSigInfo TDTotalBuyINFO[100];
TradeSigInfo TDTotalSellINFO[100];
OrderInfo OrdInfo;
//---------------------------------------------------------------------------
// End of StockDB.cpp
//---------------------------------------------------------------------------
