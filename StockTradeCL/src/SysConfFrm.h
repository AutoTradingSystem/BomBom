//---------------------------------------------------------------------------

#ifndef SysConfFrmH
#define SysConfFrmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TSysConfF : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TEdit *edOrderCd;
	TLabel *Label9;
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label2;
private:	// User declarations
public:		// User declarations
	__fastcall TSysConfF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSysConfF *SysConfF;
//---------------------------------------------------------------------------
#endif
