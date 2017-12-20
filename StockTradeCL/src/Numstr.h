//---------------------------------------------------------------------------
#ifndef NumstrH
#define NumstrH
//---------------------------------------------------------------------------
#include <System.hpp>
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
namespace Numstr {

int __fastcall TimeStrToInt(const String AValue);
String __fastcall IntToTimeStr(int AValue);
String __fastcall SToNForStr(String AValue);


};
//---------------------------------------------------------------------------
#endif
