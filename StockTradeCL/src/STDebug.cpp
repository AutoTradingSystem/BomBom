//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "STDebug.h"
#include "StockDB.h"
//---------------------------------------------------------------------------
#include "CPstock.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSTDebugF *STDebugF;
//---------------------------------------------------------------------------
// Constuctor
//---------------------------------------------------------------------------
__fastcall TSTDebugF::TSTDebugF(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSTDebugF::btnEchoClick(TObject *Sender)
{
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
// Message process
//---------------------------------------------------------------------------
void __fastcall TSTDebugF::fnMessageLog(TMessage Msg)
{
	lbRecvLog->Items->Add(RecvMsgLog.str);
}
//---------------------------------------------------------------------------
void __fastcall TSTDebugF::fnMessageSendLog(TMessage Msg)
{
	lbSendLog->Items->Add(SendMsgLog.str);
}
//---------------------------------------------------------------------------
void __fastcall TSTDebugF::fnMessageSysLog(TMessage Msg)
{
	mmSysLog->Lines->Add(SysMsgLog.str);
}
