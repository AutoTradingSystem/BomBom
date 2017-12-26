//---------------------------------------------------------------------------

#pragma hdrstop

#include "THRclient.h"
#include "StockDB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
// External
//---------------------------------------------------------------------------
extern int global;
extern CLSlog Log;
extern THRclient *ThrClient;
extern CLSstockIF TcpClient;
//---------------------------------------------------------------------------
// THRclient
//---------------------------------------------------------------------------
__fastcall THRclient::THRclient(void) : TThread(true)
{

}
//---------------------------------------------------------------------------
// ~THRclient
//---------------------------------------------------------------------------
__fastcall THRclient::~THRclient()
{

}
bool __fastcall THRclient::IsRunning(void)
{
    return (Active);
}
//---------------------------------------------------------------------------
// test
//---------------------------------------------------------------------------
void __fastcall THRclient::test()
{
	ostringstream oss;
	oss<<global;
	string s=oss.str();

	Log.Write(s.c_str());
}
//---------------------------------------------------------------------------
// start
//---------------------------------------------------------------------------
void __fastcall THRclient::start()
{
	Start();
}
//---------------------------------------------------------------------------
// stop
//---------------------------------------------------------------------------
void __fastcall THRclient::stop()
{
	Terminate();
}
void __fastcall THRclient::Kill(void)
{
	Terminate();
	TCLclearEnv();
}
bool __fastcall THRclient::NeedTerminate()
{
	return (StockSYS.Terminate);
}
//---------------------------------------------------------------------------
// TCLmanage
//---------------------------------------------------------------------------
bool __fastcall THRclient::TCLmanage(void)
{
	return (TcpClient.Manage());
	//return (true);
}
void __fastcall THRclient::TCLclearEnv(void)
{
	TcpClient.CloseNetwork("Socket Close");
}
void __fastcall THRclient::ExitThread()
{
	Active = false;
}
//---------------------------------------------------------------------------
// Execute
//---------------------------------------------------------------------------
void __fastcall THRclient::Execute()
{
	Active = true;
	int cycle = 0;
	Log.Write("THRclient start");
	while( !Terminated && !NeedTerminate())
	{
//		if (cycle % 10 == 0) {
//			cycle++;
//			Log.Write("thread run[%d]", cycle);
//			if (cycle == 100000000) cycle = 0;
//		}

		// 立加 包府
		if (!TCLmanage())
		{
			Log.Write("TCP Mng false");
			TCLclearEnv();
//			break;
		}

		Sleep(1000);
	}
	Log.Write("THRclient end");
	TCLclearEnv();
	ExitThread();
}
