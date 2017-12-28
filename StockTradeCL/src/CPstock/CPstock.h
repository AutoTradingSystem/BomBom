//---------------------------------------------------------------------------

#ifndef CPstockH
#define CPstockH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include "CLSstcokIF.h"
#include "CLSmap.h"
#include "CLSlog.h"
//---------------------------------------------------------------------------
// Class
//---------------------------------------------------------------------------
class CPstock
{
private:
	char *m_tcpClientIP;
	int port;
	CLSlog	m_log;
    BYTE m_seq;

	bool __fastcall InitNetwork();
	bool __fastcall InitStock();

	int __fastcall MainLoop();
public:
	CPstock(void);
	CPstock(const char *ipAddr, int port);
	~CPstock(void);

	bool __fastcall InitEnv();
	void __fastcall ClearEnv();
	void __fastcall ManageThread();

	bool __fastcall GetTcpStatus();
	bool __fastcall GetCommStatus();

	bool __fastcall SendEcho(char *str);
	bool __fastcall SendTotalBuySig();
	bool __fastcall SendTotalSellSig();
};
//---------------------------------------------------------------------------
// External
//---------------------------------------------------------------------------
extern CPstock *Pstock;

#endif
