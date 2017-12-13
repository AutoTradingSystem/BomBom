//---------------------------------------------------------------------------
#ifndef CLSsystemH
#define CLSsystemH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include "General.h"
//---------------------------------------------------------------------------
// Class
//---------------------------------------------------------------------------
class CLSsystem
{
private:

public:
	int Sig;			// signal 수
    bool Terminate;		// 시스템 종료

	CLSsystem(void);
    ~CLSsystem(void);
};
//---------------------------------------------------------------------------
#endif CLSsystemH
//---------------------------------------------------------------------------
// End of CLSsystem.h
//---------------------------------------------------------------------------
