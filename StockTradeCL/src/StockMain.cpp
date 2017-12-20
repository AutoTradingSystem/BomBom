//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StockMain.h"
//---------------------------------------------------------------------------
#include "STDebug.h"
#include "SysConfFrm.h"
//---------------------------------------------------------------------------
#include "Numstr.h"
#include "StockDB.h"
#include "CPstock.h"
#include "THRmain.h"
#include "CLSmap.h"
#include "CLSstockSig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//#pragma link "KHOpenAPILib_OCX"
#pragma link "KHOpenAPILib_OCX"
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
// Global Variable
//---------------------------------------------------------------------------
TStockMainF *StockMainF;
THRmain *ThrMain; 		// main thread
CLSlog Log;
TRLIST TrList;

extern THRclient *ThrClient;
extern CLSmap Map;
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
//	Pstock = new CPstock("192.168.6.129", 12000);   // home
	Pstock = new CPstock("192.168.42.128", 12000);  // lux
//	Pstock = new CPstock("127.0.0.1", 12000);

	// Main thread init
	ThrMain = new THRmain();
	ThrMain->start();

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
//
//---------------------------------------------------------------------------
void __fastcall TStockMainF::SetAccInfo(void)
{
	edDeposit->Text = Numstr::SToNForStr(AccInfo.Deposit);
	edDeposit2->Text = Numstr::SToNForStr(AccInfo.Deposit2);
	edTotalPurchase->Text = Numstr::SToNForStr(AccInfo.TotalPurchase);
	edDayRate->Text = Numstr::SToNForStr(AccInfo.Day_P_L_Rate);
	edCumulativeRate->Text = Numstr::SToNForStr(AccInfo.CumulativeRate);
	edCumulativePrice->Text = Numstr::SToNForStr(AccInfo.CumulativePrice);
}
//---------------------------------------------------------------------------
// ShowUserInfo
//---------------------------------------------------------------------------
void __fastcall TStockMainF::ShowUserInfo()
{
	if(!m_KWLogSt)
		return ;

	edUserName->Text = UInfo.uName;
	edAccNumber->Text = UInfo.accNo;
	edAccCnt->Text = UInfo.accCnt;
}
//---------------------------------------------------------------------------
// ShowSysStatus
//---------------------------------------------------------------------------
void __fastcall TStockMainF::ShowSysStatus()
{
	if(!m_KWLogSt)
		return ;

	lbKeyBs->Caption = (UInfo.keyBs=="0"?"정상":"해지");
	lbFireSe->Caption = (UInfo.fireSe=="0"?"미설정":(UInfo.fireSe=="1")?"설정":"해지");
}
//---------------------------------------------------------------------------
// ShowGridSigInfo
//---------------------------------------------------------------------------
void __fastcall TStockMainF::ShowGridSigInfo()
{
	int row = sgSiglog->RowCount;
	sgSiglog->RowCount++;
	TStrings *pRow = sgSiglog->Rows[row];

	AnsiString str1="";
	str1.printf("%d/%d %d:%d",TDSINFO.mon,TDSINFO.day,TDSINFO.hour,TDSINFO.minute);
	sgSiglog->Cells[0][row]=str1;

	str1 = TDSINFO.stockCode;
	sgSiglog->Cells[1][row]=str1;

	str1 = TDSINFO.stockNm;
	sgSiglog->Cells[2][row]=str1;

	str1 = TDSINFO.type;
	sgSiglog->Cells[3][row]=str1;

	str1.printf("%d",TDSINFO.price);
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
	sprintf(filename, "%s/[SIG_GRD]%04d%02d%02d.csv",dbPath, sTime.year, sTime.mon, sTime.day);
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
	sprintf(filename, "%s/[SIG_REAL]%04d%02d%02d.csv",dbPath, sTime.year, sTime.mon, sTime.day);

	if(!FileExists(filename))
	{
		if((fp = fopen(filename, "a+")) == NULL)
		{
			return ;
		}
		fwrite(sTitle.c_str(), 1, length, fp);
		fclose(fp);
	}

	AnsiString str1="";
	str1.printf("%d:%d:%d:%d,",TDSINFO.mon,TDSINFO.day,TDSINFO.hour,TDSINFO.minute);
	sContent += str1;
	str1 = TDSINFO.stockCode;  	str1+=",";   sContent += str1;
	str1 = TDSINFO.stockNm; 	str1 += ","; sContent += str1;
	str1 = TDSINFO.type;    	str1+=",";   sContent += str1;
	str1.printf("%d,",TDSINFO.price);   	 sContent += str1;
	str1=",\n";    // Current price; (no information)
	sContent += str1;

	//메시지 확인
	if((length = sContent.Length())<=0)
		return ;
	sprintf(filename, "%s/[SIG_REAL]%04d%02d%02d.csv",dbPath, sTime.year, sTime.mon, sTime.day);
	if((fp = fopen(filename, "a+")) == NULL)
	{
		return ;
	}
	fwrite(sContent.c_str(), 1, length, fp);
	fclose(fp);
}
//---------------------------------------------------------------------------
// ReqAccInfo
//---------------------------------------------------------------------------
void __fastcall TStockMainF::ReqAccInfo(void)
{
	int nRet;
	UnicodeString strData="";
	strData=StringReplace(UInfo.accNo, ";" ,"", Sysutils::TReplaceFlags() << Sysutils::rfReplaceAll);

	BSTR pSetAccno 	 	  = SysAllocString(L"계좌번호");
	BSTR pMyAccNO_MO 	  = SysAllocString(strData.w_str());
//	BSTR pMyAccNO_MO = SysAllocString(L"8097831511");
	BSTR pPassWord	 	  = SysAllocString(L"비밀번호");
	BSTR pValueEmpty 	  = SysAllocString(L"");
	BSTR pSangPe 	 	  = SysAllocString(L"상장폐지조회구분");
	BSTR pTemp  	 	  = SysAllocString(L"0");
	BSTR pPWinputType 	  = SysAllocString(L"비밀번호입력매체구분");
	BSTR pValue00 	 	  = SysAllocString(L"00");
	BSTR pReqAccoNO  	  = SysAllocString(L"계좌평가현황요청");
	BSTR pTrCode_OPW00004 = SysAllocString(L"OPW00004");
	BSTR pScreenNo_6001   = SysAllocString(L"6001");

	try
	{
		KHOpenAPI->SetInputValue(pSetAccno, pMyAccNO_MO); 	// 계좌번호("계좌번호",000000000)
		KHOpenAPI->SetInputValue(pPassWord, pValueEmpty);   // 비밀번호
		KHOpenAPI->SetInputValue(pSangPe, pTemp);         	// 상장폐지조회구분
		KHOpenAPI->SetInputValue(pPWinputType, pValue00);   // 비밀번호입력매체구분
		nRet = KHOpenAPI->CommRqData(pReqAccoNO, pTrCode_OPW00004, 0,pScreenNo_6001);
	}__finally
	{
		StatusBar->Panels->Items[3]->Text = "결과:"+IntToStr(nRet) ;
	}
}
//---------------------------------------------------------------------------
// fnShowGrdSIGInfo
//---------------------------------------------------------------------------
void __fastcall TStockMainF::fnShowGrdSIGInfo(TMessage Msg)
{
	ShowGridSigInfo();
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
	// TR ACC ESTIMATE LIST 초기화
	SetTrAccEstList();

	// String 그리드 기본 화면 초기화
	SetSigLogGrid();
	SetSigLogGridTitle();
	SetTradeLogGrid();
	SetTradeLogGridTitle();
}
//---------------------------------------------------------------------------
// SetTrAccEstList
//---------------------------------------------------------------------------
bool __fastcall TStockMainF::SetTrAccEstList(void)
{
	// OPW00004 (계좌평가현황조회)
	TrList.TR_ACC_EST.TRCODE 		   = SysAllocString(L"OPW00004");
	TrList.TR_ACC_EST.TRRECORD_Nm 	   = SysAllocString(L"계좌평가현황요청");
	TrList.TR_ACC_EST.IT_AccNM 		   = SysAllocString(L"계좌명");
	TrList.TR_ACC_EST.IT_Deposit 	   = SysAllocString(L"예수금");
	TrList.TR_ACC_EST.IT_Deposit2 	   = SysAllocString(L"D+2추정예수금");
	TrList.TR_ACC_EST.IT_TotalPurchase = SysAllocString(L"총매입금액");
	TrList.TR_ACC_EST.IT_Day_P_L_Rate  = SysAllocString(L"당일손익율");
	TrList.TR_ACC_EST.IT_TotalPurchase = SysAllocString(L"누적손익율");
	TrList.TR_ACC_EST.IT_Day_P_L_Rate  = SysAllocString(L"누적투자손익");
}
//---------------------------------------------------------------------------
// KWLogin
//---------------------------------------------------------------------------
bool __fastcall TStockMainF::KWLogin(void)
{
	long Result = KHOpenAPI->CommConnect();

	if(Result != 0)
		StatusBar->Panels->Items[2]->Text = "Login창 불러오기 실패";
	else
		StatusBar->Panels->Items[2]->Text = "Login창 열림";

}
//---------------------------------------------------------------------------
// GetUserInfo
//---------------------------------------------------------------------------
bool __fastcall TStockMainF::GetUserInfo()
{
	BSTR pUSER_ID 	  =SysAllocString(L"USER_ID");
	BSTR pUSER_NAME   =SysAllocString(L"USER_NAME");
	BSTR pACCOUNT_CNT =SysAllocString(L"ACCOUNT_CNT");
	BSTR pACCNO 	  =SysAllocString(L"ACCNO");
	BSTR pKEY_BSECGB  =SysAllocString(L"KEY_BSECGB");
	BSTR pFIREW_SECGB =SysAllocString(L"FIREW_SECGB");

	UInfo.uName = KHOpenAPI->GetLoginInfo(pUSER_NAME);
	UInfo.uID  = KHOpenAPI->GetLoginInfo(pUSER_ID);
	UInfo.accNo = KHOpenAPI->GetLoginInfo(pACCNO);
	UInfo.accCnt = KHOpenAPI->GetLoginInfo(pACCOUNT_CNT);
	UInfo.keyBs = KHOpenAPI->GetLoginInfo(pKEY_BSECGB);
	UInfo.fireSe = KHOpenAPI->GetLoginInfo(pFIREW_SECGB);

	ShowUserInfo();
	ShowSysStatus();
}
//---------------------------------------------------------------------------
// MakeDirectory
//---------------------------------------------------------------------------
void __fastcall TStockMainF::MakeDirectory(const char* path)
{
	CreateDir(path);         // make log directory
}
//---------------------------------------------------------------------------
// KHOpenAPIEvent (Connect)
//---------------------------------------------------------------------------
void __fastcall TStockMainF::KHOpenAPIEventConnect(TObject *Sender, long nErrCode)

{
//
	if(nErrCode == 0)
	{
		StatusBar->Panels->Items[2]->Text = "Login 성공";
		m_KWLogSt = true;
		// User info
		GetUserInfo();
        // Account info
        ReqAccInfo();
	}
	else
	{
		m_KWLogSt = false;
		StatusBar->Panels->Items[2]->Text = "Login 실패";
	}
}
//---------------------------------------------------------------------------
// KHOpenAPIEvent (ReceiveTrData)
//---------------------------------------------------------------------------
void __fastcall TStockMainF::KHOpenAPIReceiveTrData(TObject *Sender, BSTR sScrNo,
		  BSTR sRQName, BSTR sTrCode, BSTR sRecordName, BSTR sPrevNext, long nDataLength,
		  BSTR sErrorCode, BSTR sMessage, BSTR sSplmMsg)
{
	if(wcscmp(L"계좌평가현황요청",sRQName) == 0)
	{
		//SetTrAccEstList();
		// 계좌평가현황
		BSTR pDeposit     = SysAllocString(L"예수금");      // 예수금
		BSTR pDeposit_2d  = SysAllocString(L"D+2추정예수금");   // D+2추정예수금
		BSTR pToPurch     = SysAllocString(L"총매입금액");      // 총매입금액
		BSTR pOneDayRate  = SysAllocString(L"당일손익율");   // 당일손익율
		BSTR pMoaMoaRate  = SysAllocString(L"누적손익율");   // 누적손익율
		BSTR pMoaMoaPrice = SysAllocString(L"누적투자손익");  // 누적투자손익

//		AccInfo.Deposit = KHOpenAPI->GetCommData(TrList.TR_ACC_EST.TRCODE, TrList.TR_ACC_EST.TRRECORD_Nm,0,TrList.TR_ACC_EST.IT_Deposit);
//		AccInfo.Deposit2 = KHOpenAPI->GetCommData(TrList.TR_ACC_EST.TRCODE, TrList.TR_ACC_EST.TRRECORD_Nm,0,TrList.TR_ACC_EST.IT_Deposit2);
//		AccInfo.TotalPurchase = KHOpenAPI->GetCommData(TrList.TR_ACC_EST.TRCODE, TrList.TR_ACC_EST.TRRECORD_Nm,0,TrList.TR_ACC_EST.IT_TotalPurchase);
//		AccInfo.Day_P_L_Rate = KHOpenAPI->GetCommData(TrList.TR_ACC_EST.TRCODE, TrList.TR_ACC_EST.TRRECORD_Nm,0,TrList.TR_ACC_EST.IT_Day_P_L_Rate);
//		AccInfo.CumulativeRate = KHOpenAPI->GetCommData(TrList.TR_ACC_EST.TRCODE, TrList.TR_ACC_EST.TRRECORD_Nm,0,TrList.TR_ACC_EST.IT_CumulativeRate);
//		AccInfo.CumulativePrice = KHOpenAPI->GetCommData(TrList.TR_ACC_EST.TRCODE, TrList.TR_ACC_EST.TRRECORD_Nm,0,TrList.TR_ACC_EST.IT_CumulativePrice);
		AccInfo.Deposit = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"계좌평가현황요청"),0,pDeposit);
		AccInfo.Deposit2 = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"계좌평가현황요청"),0,pDeposit_2d);
		AccInfo.TotalPurchase = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"계좌평가현황요청"),0,pToPurch);
		AccInfo.Day_P_L_Rate = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"계좌평가현황요청"),0,pOneDayRate);
		AccInfo.CumulativeRate = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"계좌평가현황요청"),0,pMoaMoaRate);
		AccInfo.CumulativePrice = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"계좌평가현황요청"),0,pMoaMoaPrice);

		SetAccInfo();
	}
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
	StatusBar->Panels->Items[5]->Text=s;
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
	//String sText = pGrid->Cells[ ACol ][ ARow ];

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
void __fastcall TStockMainF::mn100Click(TObject *Sender)
{
//
	TMenuItem *pItem = static_cast<TMenuItem*>(Sender);
	switch(pItem->Tag)
	{
	case 1:	// sys config;
		if (SysConfF == NULL) SysConfF = new TSysConfF(this);
		if( !SysConfF->Visible ) SysConfF->Show();
		if( SysConfF->WindowState == wsMinimized ) SysConfF->WindowState = wsNormal;
		break;
	case 2: // login & logout
		KWLogin();
		break;
	case 3: // program exit
        Close();
		break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TStockMainF::FormClose(TObject *Sender, TCloseAction &Action)
{
//
	Log.Write("Process exit");
}
//---------------------------------------------------------------------------
void __fastcall TStockMainF::Button3Click(TObject *Sender)
{
//
//	ThrClient->Kill();
    ReqAccInfo();
}
//---------------------------------------------------------------------------
void __fastcall TStockMainF::Button4Click(TObject *Sender)
{
//
	AnsiString codenm;
	CLSstockSig *pSig;
	AnsiString str = Edit1->Text;
    char *pCode = str.c_str();

//	if((pSig = Map.Get(str.c_str())) != NULL)
	if((pSig = Map.Get(pCode)) != NULL)
	{
		codenm = pSig->GetCodeName();
		ShowMessage(codenm);
	}
	else
	{
		ShowMessage("Map NULL");
    }
}
//---------------------------------------------------------------------------

