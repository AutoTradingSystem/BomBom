//---------------------------------------------------------------------------

#ifndef STDebugH
#define STDebugH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "Define.h"
//---------------------------------------------------------------------------
class TSTDebugF : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlMain;
	TPanel *pnlTop;
	TPanel *pnlLeft;
	TPanel *pnlRight;
	TPanel *pnlBottom;
	TButton *btnEcho;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TListBox *lbRecvLog;
	TListBox *lbSendLog;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TMemo *mmSysLog;
	TButton *btnClear;
	void __fastcall btnEchoClick(TObject *Sender);
	void __fastcall btnClearClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSTDebugF(TComponent* Owner);

    void __fastcall AddLog(UnicodeString msg);

	void __fastcall fnMessageLog(TMessage Msg);
	void __fastcall fnMessageSendLog(TMessage Msg);
	void __fastcall fnMessageSysLog(TMessage Msg);

	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(WM_MSGLOG,     TMessage, fnMessageLog);
		VCL_MESSAGE_HANDLER(WM_SENDLOG,     TMessage, fnMessageSendLog);
		VCL_MESSAGE_HANDLER(WM_SYSLOG,     TMessage, fnMessageSysLog);
	END_MESSAGE_MAP(TForm);
};
//---------------------------------------------------------------------------
extern PACKAGE TSTDebugF *STDebugF;
//---------------------------------------------------------------------------
#endif
