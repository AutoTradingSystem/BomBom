//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StockMain.h"
#include "STDebug.h"
//---------------------------------------------------------------------------
#include "StockDB.h"
#include "CPstock.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "KHOpenAPILib_OCX"
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
	char logPath[256];
	// Set Log directory
	ExeDir = ExtractFilePath(Application->ExeName);

	sprintf(logPath,"%s\\log", ExeDir.c_str());
	MakeDirectory(logPath);

	Log = CLSlog("STOCKCL", logPath);
	Log.Write("Process start");

	mTcpSt = false;
	Pstock = new CPstock("210.220.167.67", 12000);
	tmStatus->Enabled = true;
}
//---------------------------------------------------------------------------
// MakeDirectory
//---------------------------------------------------------------------------
void __fastcall TStockMainF::MakeDirectory(const char* path)
{
	CreateDir(path);         // make log directory
}
//---------------------------------------------------------------------------
// Timer (tmStatusTimer)
//---------------------------------------------------------------------------
void __fastcall TStockMainF::tmStatusTimer(TObject *Sender)
{
	if(mTcpSt != Pstock->GetTcpStatus())
	{
		mTcpSt = Pstock->GetTcpStatus();
		StatusBar->Panels->Items[3]->Text = (mTcpSt)?"ON":"OFF";
	}

    // time set
	m_curTime = Now();
	m_curTime.DecodeDate(&sTime.year, &sTime.mon, &sTime.day);
	m_curTime.DecodeTime(&sTime.hour, &sTime.min, &sTime.sec, &sTime.mSec);
	AnsiString s="";
	s.printf("%04d-%02d-%02d %02d:%02d:%02d", sTime.year, sTime.mon, sTime.day, sTime.hour, sTime.min, sTime.sec);
	StatusBar->Panels->Items[3]->Text=s;
}
//---------------------------------------------------------------------------
// Button Event (btnDebugClick)
//---------------------------------------------------------------------------
void __fastcall TStockMainF::btnDebugClick(TObject *Sender)
{
//
	if (STDebugF == NULL) STDebugF = new TSTDebugF(this);
	if( !STDebugF->Visible ) STDebugF->Show();
	if( STDebugF->WindowState == wsMinimized ) STDebugF->WindowState = wsNormal;
}
//---------------------------------------------------------------------------

void __fastcall TStockMainF::FormShow(TObject *Sender)
{
	long Result = KHOpenAPI->CommConnect();

	if(Result != 0)
		StatusBar->Panels->Items[2]->Text = "Login창 불러오기 실패";
	else
		StatusBar->Panels->Items[2]->Text = "Login창 열림";
}
//---------------------------------------------------------------------------


