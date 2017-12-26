//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SysConfFrm.h"
#include "CLSstcokIF.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
// Global
//---------------------------------------------------------------------------
TSysConfF *SysConfF;
extern CLSstockIF TcpClient;
//---------------------------------------------------------------------------
__fastcall TSysConfF::TSysConfF(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TSysConfF::btnOkClick(TObject *Sender)
{
//
	AnsiString strIp = edOrderCd->Text;
    int port = StrToInt(edPort->Text);

	TcpClient.SetNetworkInfo(strIp.c_str(), port);
	ShowMessage("»Æ¿Œ.");
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TSysConfF::btnCancelClick(TObject *Sender)
{
//
    Close();
}
//---------------------------------------------------------------------------

