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
// User Message
//---------------------------------------------------------------------------
#define WM_MSGLOG              (WM_USER + 0x01)
#define WM_SENDLOG              (WM_USER + 0x02)
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
	void __fastcall btnEchoClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSTDebugF(TComponent* Owner);

	void __fastcall fnMessageLog(TMessage Msg);
	void __fastcall fnMessageSendLog(TMessage Msg);

	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(WM_MSGLOG,     TMessage, fnMessageLog);
		VCL_MESSAGE_HANDLER(WM_SENDLOG,     TMessage, fnMessageSendLog);
	END_MESSAGE_MAP(TForm);
};
//---------------------------------------------------------------------------
extern PACKAGE TSTDebugF *STDebugF;
//---------------------------------------------------------------------------
#endif
