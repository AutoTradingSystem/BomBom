//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Numstr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
int __fastcall Numstr::TimeStrToInt(const String AValue)
{
	return AValue.SubString(1, 2).ToInt() * 60 * 60
		+ AValue.SubString(4, 2).ToInt() * 60
		+ AValue.SubString(7, 2).ToInt();
}
//---------------------------------------------------------------------------
String __fastcall Numstr::IntToTimeStr(int AValue)
{
	return String().sprintf(_T(L"%02d:%02d:%02d"), AValue / 10000, AValue / 100 % 100, AValue % 100);
}
//---------------------------------------------------------------------------
String __fastcall Numstr::SToNForStr(String AValue)
{
	if (AValue.IsEmpty()) {
		return AValue;
	}
	int cNumber = StrToIntDef(AValue,0);
	return FormatFloat("#,##0", cNumber);
}

