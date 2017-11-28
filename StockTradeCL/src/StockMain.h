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
#include <Vcl.Grids.hpp>
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
	TPanel *pnlBgd;
	TPanel *pnlTop;
	TPanel *pnlTitle;
	TPanel *pnlTopMenu;
	TLabel *Label1;
	TButton *btnDebug;
	TKHOpenAPI *KHOpenAPI;
	TPanel *pnlLeft;
	TPanel *pnlMain;
	TPanel *pnlUserInfo;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *edUserName;
	TEdit *edAccNumber;
	TEdit *edAccCnt;
	TEdit *edBalance;
	TPanel *pnlSearch;
	TLabel *Label7;
	TEdit *edStocks;
	TButton *btnStockSearch;
	TPanel *Panel1;
	TPanel *Panel2;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *edOrderPrice;
	TEdit *edOrderQuantity;
	TEdit *edOrderCd;
	TRadioButton *rbUser;
	TRadioButton *rbMarket;
	TRadioButton *rbCurrent;
	TComboBox *cbTradeType;
	TButton *btnTradeInit;
	TButton *btnTradeOk;
	TLabel *Label13;
	TLabel *Label14;
	TEdit *edOrderNumber;
	TPanel *Panel3;
	TLabel *Label15;
	TStringGrid *sgSiglog;
	void __fastcall tmStatusTimer(TObject *Sender);
	void __fastcall btnDebugClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall sgSiglogDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
private:	// User declarations
	bool mTcpSt;
	TDateTime m_curTime;

    bool __fastcall Init();

	void __fastcall MakeDirectory(const char* path);
public:		// User declarations

	__fastcall TStockMainF(TComponent* Owner);

	void __fastcall SetSigLogGrid();
	void __fastcall SetSigLogGridTitle();
};
//---------------------------------------------------------------------------
extern PACKAGE TStockMainF *StockMainF;
//---------------------------------------------------------------------------
#endif
