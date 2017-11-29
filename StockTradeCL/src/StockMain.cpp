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
	int w0 = 150, w1 = 70, w2 = 130, w3 = 70, w4 = 120, w5 = 120;
	int sgWidth = w0 + w1 + w2 + w3 + w4 + w5+4;
	sgSiglog->ColWidths[0] = 150;
	sgSiglog->ColWidths[1] = 70;
	sgSiglog->ColWidths[2] = 130;
	sgSiglog->ColWidths[4] = 120;
	sgSiglog->ColWidths[5] = 120;
	sgSiglog->Width = sgWidth;
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
// SetTradeLogGrid
//---------------------------------------------------------------------------
void __fastcall TStockMainF::SetTradeLogGrid()
{
	//sgTradeLog 892
	int w0 = 100, w1 = 100, w2 = 130, w3 = 100, w4 = 100, w5 = 100, w6 = 100, w7 = 150;
	int sgWidth = w0 + w1 + w2 + w3 + w4 + w5+ w6 + w7 + 12;
	sgTradeLog->ColWidths[0] = 100;
	sgTradeLog->ColWidths[1] = 100;
	sgTradeLog->ColWidths[2] = 130;
	sgTradeLog->ColWidths[3] = 100;
	sgTradeLog->ColWidths[4] = 100;
	sgTradeLog->ColWidths[5] = 100;
	sgTradeLog->ColWidths[6] = 100;
	sgTradeLog->ColWidths[7] = 150;
	sgTradeLog->Width = sgWidth;
}
//---------------------------------------------------------------------------
// SetTradeLogGridTitle
//---------------------------------------------------------------------------
void __fastcall TStockMainF::SetTradeLogGridTitle()
{

	sgTradeLog->RowCount = 1;
	TStrings *pRow = sgTradeLog->Rows[0];

	pRow[0].Strings[0]="시간";
	pRow[0].Strings[1]="종목코드";
	pRow[0].Strings[2]="종목명";
	pRow[0].Strings[3]="주문량";
	pRow[0].Strings[4]="체결량";
	pRow[0].Strings[5]="주문가";
	pRow[0].Strings[6]="체결가";
	pRow[0].Strings[7]="매매상태";
}
//---------------------------------------------------------------------------
// Init
//---------------------------------------------------------------------------
bool __fastcall TStockMainF::Init()
{
	SetSigLogGrid();
	SetSigLogGridTitle();
	SetTradeLogGrid();
	SetTradeLogGridTitle();
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
	TStringGrid * pGrid = static_cast<TStringGrid *>(Sender);
	TCanvas *pCanvas = pGrid->Canvas;

	UINT Flags = DT_SINGLELINE | DT_VCENTER;
	AnsiString sText = pGrid->Cells[ ACol ][ ARow ];

	AnsiString sTitle="";

	// Title setting
	if(ARow == 0)
	{
		Flags |= DT_CENTER;  // center the text
		//pCanvas->Font->Style = fsBold;
		Flags |= DT_CENTER;  // center the text

		switch(pGrid->Tag)
		{
		case 0:	// Sig Grid
			pCanvas->Font->Color = clHighlight;
			break;
		case 1:	// TradeLog Grid
			pCanvas->Font->Color = clHighlight;
			break;
		}
		pCanvas->FillRect( Rect );
		DrawText( pCanvas->Handle, sText.c_str(), -1, &Rect, Flags );
	}
}
//---------------------------------------------------------------------------

