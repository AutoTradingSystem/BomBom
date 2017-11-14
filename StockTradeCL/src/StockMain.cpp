//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StockMain.h"
#include "StockDB.h"
#include "CPstock.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
// Global
//---------------------------------------------------------------------------
TStockMainF *StockMainF;
CLSlog Log;
//---------------------------------------------------------------------------
// Local
//---------------------------------------------------------------------------
AnsiString ExeDir;
//---------------------------------------------------------------------------
__fastcall TStockMainF::TStockMainF(TComponent* Owner)
	: TForm(Owner)
{
	// test fetch
	char logPath[256];
	// Set Log directory
	ExeDir = ExtractFilePath(Application->ExeName);

	sprintf(logPath,"%s\\log", ExeDir.c_str());
	MakeDirectory(logPath);

	Log = CLSlog("STOCKCL", logPath);
	Log.Write("Process start");

	mTcpSt = false;
	Pstock = new CPstock("210.220.167.67", 12000);
	tmTcpSt->Enabled = true;
}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
void __fastcall TStockMainF::MakeDirectory(const char* path)
{
	CreateDir(path);         // make log directory
}
//---------------------------------------------------------------------------
void __fastcall TStockMainF::tmTcpStTimer(TObject *Sender)
{
	if(mTcpSt != Pstock->GetTcpStatus())
	{
		mTcpSt = Pstock->GetTcpStatus();
		lbCommSt->Caption = (mTcpSt)?"ON":"OFF";
	}
}
//---------------------------------------------------------------------------
void __fastcall TStockMainF::btnEchoClick(TObject *Sender)
{
//
	if(Pstock->SendEcho("Hello world"))
	{
		ShowMessage("success");
	}
	else
	{
        ShowMessage("fail");
    }

}
//---------------------------------------------------------------------------
void __fastcall TStockMainF::fnMessageLog(TMessage Msg)
{
	lbLog->Items->Add(Message.str);
}
void __fastcall TStockMainF::fnMessageSendLog(TMessage Msg)
{
    lbSendLog->Items->Add(SendMsgLog.str);
}
