//---------------------------------------------------------------------------

#ifndef StockMainH
#define StockMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include "KHOpenAPILib_OCX.h"
#include <Vcl.OleCtrls.hpp>
//---------------------------------------------------------------------------
// User Message
//---------------------------------------------------------------------------
// Class
//---------------------------------------------------------------------------
class TStockMainF : public TForm
{
__published:	// IDE-managed Components
	TTimer *tmStatus;
	TStatusBar *StatusBar;
	TPanel *pnlMain;
	TPanel *pnlTop;
	TPanel *pnlTitle;
	TPanel *pnlTopMenu;
	TLabel *Label1;
	TButton *btnDebug;
	TKHOpenAPI *KHOpenAPI;
	void __fastcall tmStatusTimer(TObject *Sender);
	void __fastcall btnDebugClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	bool mTcpSt;
	TDateTime m_curTime;

	void __fastcall MakeDirectory(const char* path);
public:		// User declarations

	__fastcall TStockMainF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStockMainF *StockMainF;
//---------------------------------------------------------------------------
#endif
