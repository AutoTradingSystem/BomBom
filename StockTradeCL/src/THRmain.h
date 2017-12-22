//---------------------------------------------------------------------------
#ifndef THRmainH
#define THRmainH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "General.h"
#include "CLSlog.h"
#include "THRclient.h"
#include "THRprcsig.h"
//---------------------------------------------------------------------------
// Class
//---------------------------------------------------------------------------
class THRmain : public TThread
{
private:
    bool Active;
	bool needTerminate;

    bool __fastcall InitThread();
	bool __fastcall CLmanage(void);
	void __fastcall CLclearEnv(void);
protected:

	virtual void __fastcall Execute(void);

public:
	__fastcall THRmain(void);
	__fastcall ~THRmain();

	bool __fastcall InitEnv();
	void __fastcall start();
	void __fastcall stop();
};
#endif
