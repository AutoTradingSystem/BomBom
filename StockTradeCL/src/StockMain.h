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
//#include "KHOpenAPILib_OCX.h"
#include <Vcl.OleCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
#include "Define.h"
#include "KHOpenAPILib_OCX.h"
//---------------------------------------------------------------------------
// Type definition
//---------------------------------------------------------------------------
typedef struct
{
    bool accountInfo;
} InitInfo;
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
	TComboBox *cbOrderType;
	TButton *btnOrderReset;
	TButton *btnOrder;
	TLabel *Label13;
	TLabel *Label14;
	TEdit *edOrderNumber;
	TPanel *pnlTradeLog;
	TLabel *Label15;
	TPanel *pnlSigLog;
	TLabel *Label16;
	TStringGrid *sgSiglog;
	TButton *btnOutstandingLog;
	TButton *Button1;
	TButton *Button2;
	TStringGrid *sgTradeLog;
	TButton *btnSaveCsv;
	TMainMenu *MainMenu1;
	TMenuItem *mn100;
	TMenuItem *mn101;
	TMenuItem *mn102;
	TMenuItem *mn104;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *lbKeyBs;
	TLabel *lbFireSe;
	TButton *Button3;
	TPanel *Panel3;
	TPanel *Panel4;
	TPanel *Panel5;
	TPanel *Panel6;
	TButton *Button4;
	TEdit *Edit1;
	TPanel *Panel7;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *Label23;
	TLabel *Label24;
	TLabel *Label25;
	TEdit *edDeposit;
	TEdit *edDeposit2;
	TEdit *edTotalPurchase;
	TEdit *edDayRate;
	TEdit *edCumulativePrice;
	TEdit *edCumulativeRate;
	TKHOpenAPI *KHOpenAPI;
	void __fastcall tmStatusTimer(TObject *Sender);
	void __fastcall btnDebugClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall sgSiglogDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall btnSaveCsvClick(TObject *Sender);
	void __fastcall mn100Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall KHOpenAPIEventConnect(TObject *Sender, long nErrCode);
	void __fastcall KHOpenAPIReceiveTrData(TObject *Sender, BSTR sScrNo, BSTR sRQName,
          BSTR sTrCode, BSTR sRecordName, BSTR sPrevNext, long nDataLength, BSTR sErrorCode,
          BSTR sMessage, BSTR sSplmMsg);
	void __fastcall btnOrderClick(TObject *Sender);
	void __fastcall KHOpenAPIReceiveChejanData(TObject *Sender, BSTR sGubun, long nItemCnt,
          BSTR sFIdList);
private:	// User declarations
	bool mTcpSt;
	TDateTime m_curTime;
    bool m_KWLogSt;
	InitInfo m_initInfo;

	bool __fastcall Init(void);
	bool __fastcall SetTrAccEstList(void);
	bool __fastcall KWLogin(void);
	bool __fastcall GetUserInfo(void);

	void __fastcall MakeDirectory(const char* path);
public:		// User declarations

	__fastcall TStockMainF(TComponent* Owner);

	void __fastcall SetSigLogGrid(void);
	void __fastcall SetSigLogGridTitle(void);
	void __fastcall SetTradeLogGrid(void);
	void __fastcall SetTradeLogGridTitle(void);
	void __fastcall SetAccInfo(void);

	void __fastcall ShowUserInfo();
	void __fastcall ShowSysStatus();
	void __fastcall ShowGridSigInfo();

	void __fastcall SaveSigCSV_Grid(void);
	void __fastcall SaveSigCSV_RealTime(void);


	void __fastcall ReqAccountInfo(void);
    void __fastcall ReqSendOrderTest(void);

	void __fastcall fnShowGrdSIGInfo(TMessage Msg);
	void __fastcall fnSaveRealTimeSig(TMessage Msg);


	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(WM_SHOW_GRD_SIG,     TMessage, fnShowGrdSIGInfo);
		VCL_MESSAGE_HANDLER(WM_SAVE_RT_SIG,     TMessage, fnSaveRealTimeSig);
	END_MESSAGE_MAP(TForm);
};
//---------------------------------------------------------------------------
extern PACKAGE TStockMainF *StockMainF;
//---------------------------------------------------------------------------
#endif
