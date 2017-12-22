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
#include "CLSqueue.h"
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
CLSqueue Que;

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

	pRow[0].Strings[0]="�ð�";
	pRow[0].Strings[1]="�����ڵ�";
	pRow[0].Strings[2]="�����";
	pRow[0].Strings[3]="�ֹ�����";
	pRow[0].Strings[4]="�ñ׳ΰ���";
	pRow[0].Strings[5]="������";
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

	pRow[0].Strings[0]="�ð�";
	pRow[0].Strings[1]="�����ڵ�";
	pRow[0].Strings[2]="�����";
	pRow[0].Strings[3]="�ֹ���";
	pRow[0].Strings[4]="ü�ᷮ";
	pRow[0].Strings[5]="�ֹ���";
	pRow[0].Strings[6]="ü�ᰡ";
	pRow[0].Strings[7]="�ŸŻ���";
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

	lbKeyBs->Caption = (UInfo.keyBs=="0"?"����":"����");
	lbFireSe->Caption = (UInfo.fireSe=="0"?"�̼���":(UInfo.fireSe=="1")?"����":"����");
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
	AnsiString sContent="�ð�,�����ڵ�,�����,�ֹ�����,�ñ׳ΰ���,������\n";

	for(int iRow=1;iRow<sgSiglog->RowCount;iRow++)
	{
		for(int iCol=0;iCol<sgSiglog->ColCount;iCol++)
		{
			if(iCol== 5)	//������ �÷� index
				continue;

			sContent += sgSiglog->Cells[iCol][iRow]+AnsiString(",");
		}
		sContent= sContent+AnsiString("\n");
	}

	//�޽��� Ȯ��
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
	AnsiString sTitle="�ð�,�����ڵ�,�����,�ֹ�����,�ñ׳ΰ���,������\n";
	AnsiString sContent="";

	//�޽��� Ȯ��
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

	//�޽��� Ȯ��
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
// ReqAccountInfo
//---------------------------------------------------------------------------
void __fastcall TStockMainF::ReqAccountInfo(void)
{
	int nRet;
	UnicodeString strData="";
	strData=StringReplace(UInfo.accNo, ";" ,"", Sysutils::TReplaceFlags() << Sysutils::rfReplaceAll);

	BSTR pSetAccno 	 	  = SysAllocString(L"���¹�ȣ");
	BSTR pMyAccNO_MO 	  = SysAllocString(strData.w_str());
//	BSTR pMyAccNO_MO = SysAllocString(L"8097831511");
	BSTR pPassWord	 	  = SysAllocString(L"��й�ȣ");
	BSTR pValueEmpty 	  = SysAllocString(L"");
	BSTR pSangPe 	 	  = SysAllocString(L"����������ȸ����");
	BSTR pTemp  	 	  = SysAllocString(L"0");
	BSTR pPWinputType 	  = SysAllocString(L"��й�ȣ�Է¸�ü����");
	BSTR pValue00 	 	  = SysAllocString(L"00");
	BSTR pReqAccoNO  	  = SysAllocString(L"��������Ȳ��û");
	BSTR pTrCode_OPW00004 = SysAllocString(L"OPW00004");
	BSTR pScreenNo_6001   = SysAllocString(L"6001");

	try
	{
		KHOpenAPI->SetInputValue(pSetAccno, pMyAccNO_MO); 	// ���¹�ȣ("���¹�ȣ",000000000)
		KHOpenAPI->SetInputValue(pPassWord, pValueEmpty);   // ��й�ȣ
		KHOpenAPI->SetInputValue(pSangPe, pTemp);         	// ����������ȸ����
		KHOpenAPI->SetInputValue(pPWinputType, pValue00);   // ��й�ȣ�Է¸�ü����
		nRet = KHOpenAPI->CommRqData(pReqAccoNO, pTrCode_OPW00004, 0,pScreenNo_6001);
	}__finally
	{
		StatusBar->Panels->Items[3]->Text = "���:"+IntToStr(nRet) ;
	}
}
//---------------------------------------------------------------------------
// ReqSendOrderTest
//---------------------------------------------------------------------------
void __fastcall TStockMainF::ReqSendOrderTest(void)
{
    UnicodeString strData="";
	strData=StringReplace(UInfo.accNo, ";" ,"", Sysutils::TReplaceFlags() << Sysutils::rfReplaceAll);

	BSTR pStockOrder = SysAllocString(L"RQ_1");
	BSTR pScreenNo_0101 = SysAllocString(L"0101");
	BSTR pCode = SysAllocString(edOrderCd->Text.c_str());
	BSTR pMyAccNO_MO = SysAllocString(strData.w_str());
	BSTR pValue00 = SysAllocString(L"00");
	BSTR pValueEmpty = SysAllocString(L"");
	long pOrderType = cbOrderType->ItemIndex + 1;
	long pQuantity = StrToIntDef(edOrderQuantity->Text,0);
	long pPrice = StrToIntDef(edOrderPrice->Text,0);
	long result;
	try
	{
		result = KHOpenAPI->SendOrder(pStockOrder, pScreenNo_0101, pMyAccNO_MO, pOrderType, pCode, pQuantity, pPrice, pValue00, pValueEmpty);

	}__finally
	{
		ShowMessage(result);
		if(result == 0)
		{
			StatusBar->Panels->Items[4]->Text = "�ֹ����� ����";
			SysMsgLog.str.printf("TP:%d  CD:%s  QYT:%d, PRICE:%d", pOrderType, edOrderCd->Text.c_str(), pQuantity, pPrice);
			STDebugF->AddLog(SysMsgLog.str);
		}
		else
			StatusBar->Panels->Items[4]->Text = "�ֹ����� ����";
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
// fnQSellSig
//---------------------------------------------------------------------------
void __fastcall TStockMainF::fnQSellSig(TMessage Msg)
{
	if(Que.EmptySellSig())
		return ;

	TradeSigInfo sInfo;
	sInfo = Que.FrontSellSig();
	STDebugF->AddLog(" QUE_SELL===================================");
	AnsiString str="";
	str.printf("[%c] [%d:%d:%d:%d] [%s] [%s] [%d]",
		sInfo.type, sInfo.mon, sInfo.day, sInfo.hour, sInfo.minute, sInfo.stockCode, sInfo.stockNm, sInfo.price);

	STDebugF->AddLog(str);
    Que.PopSellSig();
}
//---------------------------------------------------------------------------
// fnQBuySig
//---------------------------------------------------------------------------
void __fastcall TStockMainF::fnQBuySig(TMessage Msg)
{

}
//---------------------------------------------------------------------------
// Init
//---------------------------------------------------------------------------
bool __fastcall TStockMainF::Init()
{
	// TR ACC ESTIMATE LIST �ʱ�ȭ
	SetTrAccEstList();

	// String �׸��� �⺻ ȭ�� �ʱ�ȭ
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
	// OPW00004 (��������Ȳ��ȸ)
	TrList.TR_ACC_EST.TRCODE 		   = SysAllocString(L"OPW00004");
	TrList.TR_ACC_EST.TRRECORD_Nm 	   = SysAllocString(L"��������Ȳ��û");
	TrList.TR_ACC_EST.IT_AccNM 		   = SysAllocString(L"���¸�");
	TrList.TR_ACC_EST.IT_Deposit 	   = SysAllocString(L"������");
	TrList.TR_ACC_EST.IT_Deposit2 	   = SysAllocString(L"D+2����������");
	TrList.TR_ACC_EST.IT_TotalPurchase = SysAllocString(L"�Ѹ��Աݾ�");
	TrList.TR_ACC_EST.IT_Day_P_L_Rate  = SysAllocString(L"���ϼ�����");
	TrList.TR_ACC_EST.IT_TotalPurchase = SysAllocString(L"����������");
	TrList.TR_ACC_EST.IT_Day_P_L_Rate  = SysAllocString(L"�������ڼ���");
}
//---------------------------------------------------------------------------
// KWLogin
//---------------------------------------------------------------------------
bool __fastcall TStockMainF::KWLogin(void)
{
	long Result = KHOpenAPI->CommConnect();

	if(Result != 0)
		StatusBar->Panels->Items[2]->Text = "Loginâ �ҷ����� ����";
	else
		StatusBar->Panels->Items[2]->Text = "Loginâ ����";

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
		StatusBar->Panels->Items[2]->Text = "Login ����";
		m_KWLogSt = true;
		// User info
		GetUserInfo();
        // Account info
        ReqAccountInfo();
	}
	else
	{
		m_KWLogSt = false;
		StatusBar->Panels->Items[2]->Text = "Login ����";
	}
}
//---------------------------------------------------------------------------
// KHOpenAPIEvent (ReceiveTrData)
//---------------------------------------------------------------------------
void __fastcall TStockMainF::KHOpenAPIReceiveTrData(TObject *Sender, BSTR sScrNo,
		  BSTR sRQName, BSTR sTrCode, BSTR sRecordName, BSTR sPrevNext, long nDataLength,
		  BSTR sErrorCode, BSTR sMessage, BSTR sSplmMsg)
{
	if(wcscmp(L"��������Ȳ��û",sRQName) == 0)
	{
		//SetTrAccEstList();
		// ��������Ȳ
		BSTR pDeposit     = SysAllocString(L"������");      // ������
		BSTR pDeposit_2d  = SysAllocString(L"D+2����������");   // D+2����������
		BSTR pToPurch     = SysAllocString(L"�Ѹ��Աݾ�");      // �Ѹ��Աݾ�
		BSTR pOneDayRate  = SysAllocString(L"���ϼ�����");   // ���ϼ�����
		BSTR pMoaMoaRate  = SysAllocString(L"����������");   // ����������
		BSTR pMoaMoaPrice = SysAllocString(L"�������ڼ���");  // �������ڼ���

		AccInfo.Deposit = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"��������Ȳ��û"),0,pDeposit);
		AccInfo.Deposit2 = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"��������Ȳ��û"),0,pDeposit_2d);
		AccInfo.TotalPurchase = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"��������Ȳ��û"),0,pToPurch);
		AccInfo.Day_P_L_Rate = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"��������Ȳ��û"),0,pOneDayRate);
		AccInfo.CumulativeRate = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"��������Ȳ��û"),0,pMoaMoaRate);
		AccInfo.CumulativePrice = KHOpenAPI->GetCommData(SysAllocString(L"OPW00004"),SysAllocString(L"��������Ȳ��û"),0,pMoaMoaPrice);

		SetAccInfo();
	}
}
//---------------------------------------------------------------------------
// KHOpenAPIEvent (ReceiveChejanData)
//---------------------------------------------------------------------------S
void __fastcall TStockMainF::KHOpenAPIReceiveChejanData(TObject *Sender, BSTR sGubun,
		  long nItemCnt, BSTR sFIdList)
{
//
	ShowMessage(sGubun);

	//������ ü��.
	if(wcscmp(L"0",sGubun) == 0)
	{
		// �ֹ���ȣ         9203
		// ���� �ڵ�        9001
		// �ֹ� ����        913
		// ���� ��          302
		// �ֹ� ��          900
		// �ֹ� ����        901
		// ��ü�� ��        902
		// �ǰ� ���� �ݾ�   903
		// �� �ֹ���ȣ      904
		// �ֹ� ����        905
		// �Ÿű���         906
		// �ֺ� ü�� �ð�   908
		// ü�� ��ȣ        909
		// ü�� ����        910
		// ü�ᷮ           911
		// ���� ����        10
		// �ֿ켱 �ŵ�ȣ��  27
		// �ֿ켱 �ż�ȣ��  28
		// �źλ���         919
		// ȭ���ȣ         920
		// ���� ����        930
		// �� ���� ��       932
		// �ֹ� ���� ����   933
		// ���ذ�           307
		OrdInfo.orderNo 	  	 = KHOpenAPI->GetChejanData(9203);		// �ֹ���ȣ         9203
		OrdInfo.orderCode 	  	 = KHOpenAPI->GetChejanData(9001);		// ���� �ڵ�        9001
		OrdInfo.orderSts 	  	 = KHOpenAPI->GetChejanData(913);		// �ֹ� ����        913
		OrdInfo.orderNm 	  	 = KHOpenAPI->GetChejanData(302);		// ���� ��          302
		OrdInfo.orderQty 	  	 = KHOpenAPI->GetChejanData(900);		// �ֹ� ��          900
		OrdInfo.orderPrice 	  	 = KHOpenAPI->GetChejanData(901);		// �ֹ� ����        901
		OrdInfo.michegyeolQry 	 = KHOpenAPI->GetChejanData(902);		// ��ü�� ��        902
		OrdInfo.chegyeolSumMoney = KHOpenAPI->GetChejanData(903);		// �ǰ� ���� �ݾ�   903
		OrdInfo.oneOrderNo 	  	 = KHOpenAPI->GetChejanData(904);		// �� �ֹ���ȣ      904
		OrdInfo.orderType 	  	 = KHOpenAPI->GetChejanData(905);		// �ֹ� ����        905
		OrdInfo.tradeType 	  	 = KHOpenAPI->GetChejanData(906);		// �Ÿű���         906
		OrdInfo.time 	  		 = KHOpenAPI->GetChejanData(908);		// �ֹ� ü�� �ð�   908
		OrdInfo.chegyeolNo 	  	 = KHOpenAPI->GetChejanData(909);		// ü�� ��ȣ        909
		OrdInfo.chegyeolPrice 	 = KHOpenAPI->GetChejanData(910);		// ü�� ����        910
		OrdInfo.chegyeolQry 	 = KHOpenAPI->GetChejanData(911);		// ü�ᷮ           911
		OrdInfo.currentPrice 	 = KHOpenAPI->GetChejanData(10);		// ���� ����        10
		OrdInfo.firstSellPrice 	 = KHOpenAPI->GetChejanData(27);		// �ֿ켱 �ŵ�ȣ��  27
		OrdInfo.firstBuyPrice 	 = KHOpenAPI->GetChejanData(28);		// �ֿ켱 �ż�ȣ��  28
		OrdInfo.denyReason 	  	 = KHOpenAPI->GetChejanData(919);		// �źλ���         919
		OrdInfo.screenNo 	  	 = KHOpenAPI->GetChejanData(920);		// ȭ���ȣ         920
		OrdInfo.holdQty 	  	 = KHOpenAPI->GetChejanData(930);		// ���� ����        930
		OrdInfo.totalBuyPrice 	 = KHOpenAPI->GetChejanData(932);		// �� ���� ��       932
		OrdInfo.orderableQty 	 = KHOpenAPI->GetChejanData(933);		// �ֹ� ���� ����   933
		OrdInfo.basePrice 	  	 = KHOpenAPI->GetChejanData(307);		// ���ذ�           307

		STDebugF->AddLog("=================���� ü��=================");
		STDebugF->AddLog("�ֹ���ȣ: "+OrdInfo.orderNo);
		STDebugF->AddLog("�����ڵ�: "+OrdInfo.orderCode);
		STDebugF->AddLog("�ֹ�����: "+OrdInfo.orderSts);
		STDebugF->AddLog("�����: "+OrdInfo.orderNm);
		STDebugF->AddLog("�ֹ�����: "+OrdInfo.orderQty);
		STDebugF->AddLog("�ֹ�����: "+OrdInfo.orderPrice);
		STDebugF->AddLog("��ü�� ����: "+OrdInfo.michegyeolQry);
		STDebugF->AddLog("ü�ᴩ��ݾ�: "+OrdInfo.chegyeolSumMoney);
		STDebugF->AddLog("���ֹ���ȣ: "+OrdInfo.oneOrderNo);
		STDebugF->AddLog("�ֹ�����: "+OrdInfo.orderType);
		STDebugF->AddLog("�ŷ�����: "+OrdInfo.tradeType);
		STDebugF->AddLog("�ֹ�ü��ð�: "+OrdInfo.time);
		STDebugF->AddLog("ü���ȣ: "+OrdInfo.chegyeolNo);
		STDebugF->AddLog("ü�ᰡ��: "+OrdInfo.chegyeolPrice);
		STDebugF->AddLog("ü�ᷮ: "+OrdInfo.chegyeolQry);
		STDebugF->AddLog("���簡��: "+OrdInfo.currentPrice);
		STDebugF->AddLog("�ֿ켱�ŵ�ȣ��: "+OrdInfo.firstSellPrice);
		STDebugF->AddLog("�ֿ켱�ż�ȣ��: "+OrdInfo.firstBuyPrice);
		STDebugF->AddLog("�źλ���: "+OrdInfo.denyReason);
		STDebugF->AddLog("ȭ���ȣ: "+OrdInfo.screenNo);
		STDebugF->AddLog("������: "+OrdInfo.holdQty);
		STDebugF->AddLog("�Ѹż�����: "+OrdInfo.totalBuyPrice);
		STDebugF->AddLog("�ֹ����ɼ���: "+OrdInfo.orderableQty);
		STDebugF->AddLog("�⺻����: "+OrdInfo.basePrice);
	}
	// �ܰ� ����.
	else if(wcscmp(L"1",sGubun) == 0)
	{
		// ��ü��� �߻��ϴ� �ǰ�?

		OrdInfo.orderNo 	  	 = KHOpenAPI->GetChejanData(9203);		// �ֹ���ȣ         9203
		OrdInfo.orderCode 	  	 = KHOpenAPI->GetChejanData(9001);		// ���� �ڵ�        9001
		OrdInfo.orderSts 	  	 = KHOpenAPI->GetChejanData(913);		// �ֹ� ����        913
		OrdInfo.orderNm 	  	 = KHOpenAPI->GetChejanData(302);		// ���� ��          302
		OrdInfo.orderQty 	  	 = KHOpenAPI->GetChejanData(900);		// �ֹ� ��          900
		OrdInfo.orderPrice 	  	 = KHOpenAPI->GetChejanData(901);		// �ֹ� ����        901
		OrdInfo.michegyeolQry 	 = KHOpenAPI->GetChejanData(902);		// ��ü�� ��        902
		OrdInfo.chegyeolSumMoney = KHOpenAPI->GetChejanData(903);		// �ǰ� ���� �ݾ�   903
		OrdInfo.oneOrderNo 	  	 = KHOpenAPI->GetChejanData(904);		// �� �ֹ���ȣ      904
		OrdInfo.orderType 	  	 = KHOpenAPI->GetChejanData(905);		// �ֹ� ����        905
		OrdInfo.tradeType 	  	 = KHOpenAPI->GetChejanData(906);		// �Ÿű���         906
		OrdInfo.time 	  		 = KHOpenAPI->GetChejanData(908);		// �ֹ� ü�� �ð�   908
		OrdInfo.chegyeolNo 	  	 = KHOpenAPI->GetChejanData(909);		// ü�� ��ȣ        909
		OrdInfo.chegyeolPrice 	 = KHOpenAPI->GetChejanData(910);		// ü�� ����        910
		OrdInfo.chegyeolQry 	 = KHOpenAPI->GetChejanData(911);		// ü�ᷮ           911
		OrdInfo.currentPrice 	 = KHOpenAPI->GetChejanData(10);		// ���� ����        10
		OrdInfo.firstSellPrice 	 = KHOpenAPI->GetChejanData(27);		// �ֿ켱 �ŵ�ȣ��  27
		OrdInfo.firstBuyPrice 	 = KHOpenAPI->GetChejanData(28);		// �ֿ켱 �ż�ȣ��  28
		OrdInfo.denyReason 	  	 = KHOpenAPI->GetChejanData(919);		// �źλ���         919
		OrdInfo.screenNo 	  	 = KHOpenAPI->GetChejanData(920);		// ȭ���ȣ         920
		OrdInfo.holdQty 	  	 = KHOpenAPI->GetChejanData(930);		// ���� ����        930
		OrdInfo.totalBuyPrice 	 = KHOpenAPI->GetChejanData(932);		// �� ���� ��       932
		OrdInfo.orderableQty 	 = KHOpenAPI->GetChejanData(933);		// �ֹ� ���� ����   933
		OrdInfo.basePrice 	  	 = KHOpenAPI->GetChejanData(307);		// ���ذ�           307

		STDebugF->AddLog("=================�ܰ� ����=================");
		STDebugF->AddLog("�ֹ���ȣ: "+OrdInfo.orderNo);
		STDebugF->AddLog("�����ڵ�: "+OrdInfo.orderCode);
		STDebugF->AddLog("�ֹ�����: "+OrdInfo.orderSts);
		STDebugF->AddLog("�����: "+OrdInfo.orderNm);
		STDebugF->AddLog("�ֹ�����: "+OrdInfo.orderQty);
		STDebugF->AddLog("�ֹ�����: "+OrdInfo.orderPrice);
		STDebugF->AddLog("��ü�� ����: "+OrdInfo.michegyeolQry);
		STDebugF->AddLog("ü�ᴩ��ݾ�: "+OrdInfo.chegyeolSumMoney);
		STDebugF->AddLog("���ֹ���ȣ: "+OrdInfo.oneOrderNo);
		STDebugF->AddLog("�ֹ�����: "+OrdInfo.orderType);
		STDebugF->AddLog("�ŷ�����: "+OrdInfo.tradeType);
		STDebugF->AddLog("�ֹ�ü��ð�: "+OrdInfo.time);
		STDebugF->AddLog("ü���ȣ: "+OrdInfo.chegyeolNo);
		STDebugF->AddLog("ü�ᰡ��: "+OrdInfo.chegyeolPrice);
		STDebugF->AddLog("ü�ᷮ: "+OrdInfo.chegyeolQry);
		STDebugF->AddLog("���簡��: "+OrdInfo.currentPrice);
		STDebugF->AddLog("�ֿ켱�ŵ�ȣ��: "+OrdInfo.firstSellPrice);
		STDebugF->AddLog("�ֿ켱�ż�ȣ��: "+OrdInfo.firstBuyPrice);
		STDebugF->AddLog("�źλ���: "+OrdInfo.denyReason);
		STDebugF->AddLog("ȭ���ȣ: "+OrdInfo.screenNo);
		STDebugF->AddLog("������: "+OrdInfo.holdQty);
		STDebugF->AddLog("�Ѹż�����: "+OrdInfo.totalBuyPrice);
		STDebugF->AddLog("�ֹ����ɼ���: "+OrdInfo.orderableQty);
		STDebugF->AddLog("�⺻����: "+OrdInfo.basePrice);
	}
	else if(wcscmp(L"3",sGubun) == 0)
	{

	}
	else
	{

	}

	// �������� ȣ��
	ReqAccountInfo();
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
//		StatusBar->Panels->Items[2]->Text = "Loginâ �ҷ����� ����";
//	else
//		StatusBar->Panels->Items[2]->Text = "Loginâ ����";
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
	ReqAccountInfo();
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


void __fastcall TStockMainF::btnOrderClick(TObject *Sender)
{
//
    ReqSendOrderTest();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

