//---------------------------------------------------------------------------

#ifndef THRprcsigH
#define THRprcsigH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "General.h"
#include "CLSlog.h"
#include "CLSqueue.h"
//---------------------------------------------------------------------------
// Constant
//---------------------------------------------------------------------------
// Forward Declaration
//---------------------------------------------------------------------------
//class CLSBsHlIF;
//---------------------------------------------------------------------------
// Class
//---------------------------------------------------------------------------
class THRprcsig : public TThread
{
private:
	bool Active;


	bool __fastcall TCLmanage(void);
	void __fastcall TCLclearEnv(void);
    void __fastcall ExitThread();
protected:
	virtual void __fastcall Execute(void);

public:
	__fastcall THRprcsig(void);
	__fastcall ~THRprcsig();

	bool __fastcall IsRunning(void);
	void __fastcall start();
	void __fastcall stop();
	void __fastcall Kill(void);
	bool __fastcall NeedTerminate();
};
//---------------------------------------------------------------------------
#endif
