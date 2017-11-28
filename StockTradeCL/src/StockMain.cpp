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
//
//---------------------------------------------------------------------------
void __fastcall TStockMainF::SetSigLogGrid()
{
	sgSiglog->ColWidths[0] = 150;
	sgSiglog->ColWidths[1] = 70;
	sgSiglog->ColWidths[2] = 130;
	sgSiglog->ColWidths[3] = 70;
	sgSiglog->ColWidths[4] = 120;
	sgSiglog->ColWidths[5] = 120;
}
//---------------------------------------------------------------------------
// SetSigLogGridTitle
//---------------------------------------------------------------------------
void __fastcall TStockMainF::SetSigLogGridTitle()
{
	sgSiglog->RowCount = 1;
	TStrings *pRow = sgSiglog->Rows[0];

	pRow[0].Strings[0]="시간";
	pRow[0].Strings[1]="종목코드";
	pRow[0].Strings[2]="종목명";
	pRow[0].Strings[3]="주문구분";
	pRow[0].Strings[4]="시그널가격";
	pRow[0].Strings[5]="현제가";
}
//---------------------------------------------------------------------------
// Init
//---------------------------------------------------------------------------
bool __fastcall TStockMainF::Init()
{
	SetSigLogGrid();
	SetSigLogGridTitle();
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
//	long Result = KHOpenAPI->CommConnect();
//
//	if(Result != 0)
//		StatusBar->Panels->Items[2]->Text = "Login창 불러오기 실패";
//	else
//		StatusBar->Panels->Items[2]->Text = "Login창 열림";
	Init();
}
//---------------------------------------------------------------------------


void __fastcall TStockMainF::sgSiglogDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State)
{
//
	TStringGrid *pGrid = dynamic_cast<TStringGrid *>(Sender);
	TRect rtDraw = Rect;

//	wchar_t* wcstr = widen(cstr).c_str() ;

	UINT uFormat = DT_RIGHT;
	AnsiString sText = pGrid->Cells[ACol][ARow];
	if (ARow >= pGrid->FixedRows)
	{
		switch (ACol)
		{
		case 2:
			uFormat = DT_CENTER;
			break;
		case 3:
			uFormat = DT_LEFT;
			break;
		}
	}
	::InflateRect(&rtDraw, -2, -2);

	//::DrawText(pGrid->Canvas->Handle, sText.c_str(), sText.Length(), &rtDraw, DT_SINGLELINE | DT_VCENTER | uFormat);
	::DrawText(pGrid->Canvas->Handle, NULL, sText.Length(), &rtDraw, DT_SINGLELINE | DT_VCENTER | uFormat);
}
//---------------------------------------------------------------------------

