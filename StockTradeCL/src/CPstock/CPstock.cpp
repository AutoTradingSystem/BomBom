//---------------------------------------------------------------------------

#pragma hdrstop

#include "CPstock.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// Global Variable
//---------------------------------------------------------------------------
int global;
extern CLSlog Log;
CLSstockIF TcpClient;
CLSmap Map;
CPstock *Pstock;
PUBLIC_MEM PublicMem;
//---------------------------------------------------------------------------
// Constuctor
//---------------------------------------------------------------------------
CPstock::CPstock(void)
{
	Log.Write("CPstock start");
}
//---------------------------------------------------------------------------
CPstock::CPstock(const char *ipAddr, int port)
{
	Log.Write("CPstock start");
	TcpClient = CLSstockIF("STOCKTCP",port, ipAddr, TCP_CLIENT);
	InitEnv();  //작업환경 초기화
}
//---------------------------------------------------------------------------
// ~CPstock
//---------------------------------------------------------------------------
CPstock::~CPstock(void)
{
	//
}
//---------------------------------------------------------------------------
// InitNetwork
//---------------------------------------------------------------------------
bool __fastcall CPstock::InitNetwork()
{
	//open client socket
	if(!TcpClient.Open())
		return (false);

    Log.Write("socket open");
	return (true);
}
//---------------------------------------------------------------------------
// InitStock
//---------------------------------------------------------------------------
bool __fastcall CPstock::InitStock()
{
	CLSstockSig *pStock = (CLSstockSig *)&PublicMem.stock;
	CLSsystem *pSys = (CLSsystem*)&PublicMem.system;
    pSys->Sig = 0;
}
//---------------------------------------------------------------------------
// InitEnv
//---------------------------------------------------------------------------
bool __fastcall CPstock::InitEnv()
{
    // Map 생성
	Map = CLSmap();

    //Network 초기화
	if(!InitNetwork())
	{
		return (false);
	}
}
//---------------------------------------------------------------------------
// ClearEnv
//---------------------------------------------------------------------------
void __fastcall CPstock::ClearEnv()
{
	TcpClient.CloseNetwork("program exit");
}
//---------------------------------------------------------------------------
// ManageThread
//---------------------------------------------------------------------------
void __fastcall CPstock::ManageThread()
{

}
//---------------------------------------------------------------------------
// GetTcpStatus
//---------------------------------------------------------------------------
bool __fastcall CPstock::GetTcpStatus()
{
	return (TcpClient.Connected);
}
//---------------------------------------------------------------------------
// GetCommStatus
//---------------------------------------------------------------------------
bool __fastcall CPstock::GetCommStatus()
{
	return (TcpClient.Connected);
}
//---------------------------------------------------------------------------
// SendEcho
//---------------------------------------------------------------------------
bool __fastcall CPstock::SendEcho(char *str)
{
	return (TcpClient.SendEcho(str));
}
