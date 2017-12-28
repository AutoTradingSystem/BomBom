//---------------------------------------------------------------------------

#ifndef SigConfFrmH
#define SigConfFrmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TSigConfF : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *edOrderablePrice;
	TEdit *edMaxOrderCnt;
	TEdit *edSigValidTime;
	TComboBox *cbBuyConf;
	TComboBox *cbSellConf;
	TLabel *Label6;
	TPanel *Panel2;
	TLabel *Label7;
	TPanel *Panel3;
	TButton *btnOk;
	TButton *btnCancel;
private:	// User declarations
public:		// User declarations
	__fastcall TSigConfF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSigConfF *SigConfF;
//---------------------------------------------------------------------------
#endif
