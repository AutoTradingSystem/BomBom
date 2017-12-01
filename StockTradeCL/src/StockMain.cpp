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
char dbPath[256];
//---------------------------------------------------------------------------
__fastcall TStockMainF::TStockMainF(TComponent* Owner)
	: TForm(Owner)
{
	char logPath[256];
	//char dbPath[256];
	// Set Log directory
	ExeDir = ExtractFilePath(Application->ExeName);

	sprintf(logPath,"%s\\log", ExeDir.c_str());
	sprintf(dbPath,"%s\\DB",ExeDir.c_str());
	MakeDirectory(logPath);
	MakeDirectory(dbPath);

	Log = CLSlog("STOCKCL", logPath);
	Log.Write("Process start");

	mTcpSt = false;
//	Pstock = new CPstock("210.220.167.67", 12000);
	Pstock = new CPstock("192.168.6.129", 12000);
	tmStatus->Enabled = true;
	sgSiglog->FixedRows=1;
	Init();
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
	sgSiglog->DefaultDrawing = false;
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
	sgTradeLog->DefaultDrawing = false;
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
// ShowGridSigInfo
//---------------------------------------------------------------------------
void __fastcall TStockMainF::ShowGridSigInfo()
{
	sgSiglog->RowCount++;
	int row = sgSiglog->RowCount;
	TStrings *pRow = sgSiglog->Rows[row];

	AnsiString str1="";
	str1.printf("%d:%d:%d:%d,",TDSINFO.mon,TDSINFO.day,TDSINFO.hour,TDSINFO.minute);
	sgSiglog->Cells[0][row]=str1;

	str1 = TDSINFO.stockCode;
	sgSiglog->Cells[1][row]=str1;

	str1 = TDSINFO.stockNm;
	sgSiglog->Cells[2][row]=str1;

	str1 = TDSINFO.type;
	sgSiglog->Cells[3][row]=str1;

	str1.printf("%d,",TDSINFO.price);
	sgSiglog->Cells[4][row]=str1;

	sgSiglog->Cells[5][row]="-";

}
//---------------------------------------------------------------------------
// SaveCSV
//---------------------------------------------------------------------------
void __fastcall TStockMainF::SaveSigCSV_Grid(void)
{
	int length;
	char filename[256];
	FILE *fp;
	AnsiString sContent="시간,종목코드,종목명,주문구분,시그널가격,현제가\n";

	for(int iRow=1;iRow<sgSiglog->RowCount;iRow++)
	{
		for(int iCol=0;iCol<sgSiglog->ColCount;iCol++)
		{
			if(iCol== 5)	//마지막 컬럼 index
				continue;

			sContent += sgSiglog->Cells[iCol][iRow]+AnsiString(",");
		}
		sContent= sContent+AnsiString("\n");
	}

	//메시지 확인
	if((length = sContent.Length())<=0)
		return ;
	sprintf(filename, "%s/%04d%02d%02d.csv",dbPath, sTime.year, sTime.mon, sTime.day);
	if((fp = fopen(filename, "w+")) == NULL)
	{
		return ;
	}
	fwrite(sContent.c_str(), 1, length, fp);
	fclose(fp);

}
//---------------------------------------------------------------------------
// SaveSigCSV_RealTime
//---------------------------------------------------------------------------
void __fastcall TStockMainF::SaveSigCSV_RealTime(void)
{
    int length;
	char filename[256];
	FILE *fp;
	AnsiString sTitle="시간,종목코드,종목명,주문구분,시그널가격,현제가\n";
	AnsiString sContent="";

	//메시지 확인
	if((length = sTitle.Length())<=0)
		return ;
	sprintf(filename, "%s/[SIG_GRD]%04d%02d%02d.csv",dbPath, sTime.year, sTime.mon, sTime.day);

	if(!FileExists(filename))
	{
		if((fp = fopen(filename, "a+")) == NULL)
		{
			return ;
		}
		fwrite(sTitle.c_str(), 1, length, fp);
		fclose(fp);
	}

//	char type;
//	BYTE mon;
//	BYTE day;
//	BYTE hour;
//	BYTE minute;
//	char stockCode[7];
//	char stockNm[32];
//	unsigned int price;
//	bool valid;

	AnsiString str1="";
	str1.printf("%d:%d:%d:%d,",TDSINFO.mon,TDSINFO.day,TDSINFO.hour,TDSINFO.minute);
	sContent += str1;
	str1 = TDSINFO.stockCode;  	str1+=",";   sContent += str1;
	str1 = TDSINFO.stockNm; 	str1 += ","; sContent += str1;
	str1 = TDSINFO.type;    	str1+=",";   sContent += str1;
	str1.printf("%d,",TDSINFO.price);   	 sContent += str1;
	str1=",";    // Current price; (no information)
	sContent += str1;

	//메시지 확인
	if((length = sContent.Length())<=0)
		return ;
	sprintf(filename, "%s/[SIG_REAL]%04d%02d%02d.csv",dbPath, sTime.year, sTime.mon, sTime.day);
	if((fp = fopen(filename, "w+")) == NULL)
	{
		return ;
	}
	fwrite(sContent.c_str(), 1, length, fp);
	fclose(fp);

}
//---------------------------------------------------------------------------
// fnShowGrdSIGInfo
//---------------------------------------------------------------------------
void __fastcall TStockMainF::fnShowGrdSIGInfo(TMessage Msg)
{

}
//---------------------------------------------------------------------------
// fnSaveRealTimeSig
//---------------------------------------------------------------------------
void __fastcall TStockMainF::fnSaveRealTimeSig(TMessage Msg)
{
    SaveSigCSV_RealTime();
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
		StatusBar->Panels->Items[1]->Text = (mTcpSt)?"ON":"OFF";
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
	//Init();
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
		//InflateRect(&Rect,-2,-2);
		DrawText( pCanvas->Handle, sText.c_str(), -1, &Rect, Flags );
	}
	// Data
	else
	{
		Flags |= DT_CENTER;
		pCanvas->Font->Color = 0x00400000;    // black color
		pCanvas->FillRect( Rect );
		DrawText( pCanvas->Handle, sText.c_str(), -1, &Rect, Flags );
	}

}
//---------------------------------------------------------------------------
void __fastcall TStockMainF::btnSaveCsvClick(TObject *Sender)
{
//
	SaveSigCSV_Grid();

}
//---------------------------------------------------------------------------

