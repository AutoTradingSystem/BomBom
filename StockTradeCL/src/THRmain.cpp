//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include "THRmain.h"
#include "StockDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// External
//---------------------------------------------------------------------------
THRclient *ThrClient;
THRprcsig *Thrprcsig;
extern THRmain *ThrMain;
extern CLSlog Log;
//---------------------------------------------------------------------------
// THRmain
//---------------------------------------------------------------------------
__fastcall THRmain::THRmain(void) : TThread(true)
{
	needTerminate = false;
}
//---------------------------------------------------------------------------
// ~THRmain
//---------------------------------------------------------------------------
__fastcall THRmain::~THRmain()
{

}
bool __fastcall THRmain::InitEnv()
{
	InitThread();
    return true;
}
//---------------------------------------------------------------------------
// start
//---------------------------------------------------------------------------
void __fastcall THRmain::start()
{
    Start();
}
//---------------------------------------------------------------------------
// stop
//---------------------------------------------------------------------------
void __fastcall THRmain::stop()
{
	needTerminate = true;
}
//---------------------------------------------------------------------------
// InitThread
//---------------------------------------------------------------------------
bool __fastcall THRmain::InitThread()
{
	ThrClient = new THRclient();
	Log.Write("Sub Thread[THRclient] Start");
	ThrClient->start();

	Thrprcsig = new THRprcsig();
	Log.Write("Sub Thread[THRprcsig] Start");
	Thrprcsig->start();
}
//---------------------------------------------------------------------------
// CLmanage
//---------------------------------------------------------------------------
bool __fastcall THRmain::CLmanage(void)
{
	// Sub thread manage (THRclient)
	if(ThrClient!=NULL)
	{
		if(!ThrClient->IsRunning())
		{
			delete ThrClient;
			ThrClient = new THRclient();
			Log.Write("Manage [THRclient] Start");
			ThrClient->start();
		}
	}

	// Sub thread manage (THRprcsig)
	if(Thrprcsig!=NULL)
	{
		if(!Thrprcsig->IsRunning())
		{
			delete Thrprcsig;
			Thrprcsig = new THRprcsig();
			Log.Write("Manage [THRclient] Start");
			Thrprcsig->start();
		}
	}
}
//---------------------------------------------------------------------------
// CLclearEnv
//---------------------------------------------------------------------------
void __fastcall THRmain::CLclearEnv(void)
{
	StockSYS.Terminate = true;
	Active = false;
}
//---------------------------------------------------------------------------
// Execute(main)
//---------------------------------------------------------------------------
void __fastcall THRmain::Execute(void)
{
	Active = true;
	int cycle = 0;
	Log.Write("THRmain start");
	InitEnv();
	Sleep(100);
	while( !Terminated && !needTerminate)
	{
        CLmanage();	// thread manage
		Sleep(500);
	}
	Log.Write("THRmain exit");
	CLclearEnv();
}
