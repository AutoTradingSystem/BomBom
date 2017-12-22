//---------------------------------------------------------------------------

#pragma hdrstop

#include "THRprcsig.h"
#include "StockMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// External
//---------------------------------------------------------------------------
extern int global;
extern CLSlog Log;
extern CLSqueue Que;
extern THRprcsig *Thrprcsig;
//---------------------------------------------------------------------------
// THRclient
//---------------------------------------------------------------------------
__fastcall THRprcsig::THRprcsig(void) : TThread(true)
{

}
//---------------------------------------------------------------------------
// ~THRclient
//---------------------------------------------------------------------------
__fastcall THRprcsig::~THRprcsig()
{

}
bool __fastcall THRprcsig::IsRunning(void)
{
    return (Active);
}
//---------------------------------------------------------------------------
// start
//---------------------------------------------------------------------------
void __fastcall THRprcsig::start()
{
	Start();
}
//---------------------------------------------------------------------------
// stop
//---------------------------------------------------------------------------
void __fastcall THRprcsig::stop()
{
	Terminate();
}
void __fastcall THRprcsig::Kill(void)
{
	Terminate();
	TCLclearEnv();
}
bool __fastcall THRprcsig::NeedTerminate()
{
	return (StockSYS.Terminate);
}
//---------------------------------------------------------------------------
// TCLmanage
//---------------------------------------------------------------------------
bool __fastcall THRprcsig::TCLmanage(void)
{
	if(!(Que.EmptySellSig()))
	{
		Log.Write("QUE[SELL] 감지");
		PostMessage(StockMainF->Handle, WM_QUE_SELLSIG, (WPARAM)0, (LPARAM)0);
    }

	return (true);
}
void __fastcall THRprcsig::TCLclearEnv(void)
{

}
void __fastcall THRprcsig::ExitThread()
{
	Active = false;
}
//---------------------------------------------------------------------------
// Execute
//---------------------------------------------------------------------------
void __fastcall THRprcsig::Execute()
{
	Active = true;
	Log.Write("THRclient start");
	while( !Terminated && !NeedTerminate())
	{

		// Sig 관리
		TCLmanage();

		Sleep(1000);
	}
	Log.Write("THRprcsig end");
	TCLclearEnv();
	ExitThread();
}
