//---------------------------------------------------------------------------

#ifndef CLSqueueH
#define CLSqueueH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
#include <queue>
#include <string>
#include "StockDB.h"
#include "CLSlog.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
// Type definition
//---------------------------------------------------------------------------
// QUE_SIG
//---------------------------------------------------------------------------
typedef queue <TradeSigInfo> QUE_SIG;
//---------------------------------------------------------------------------
// Class
//---------------------------------------------------------------------------
class CLSqueue
{
private:

public:
	QUE_SIG SSig;       // Sell sig que
	QUE_SIG BSig;       // Buy sig que

	CLSqueue(void);
	~CLSqueue(void);

	void PushSellSig(TradeSigInfo info);
	void PushBuySig(TradeSigInfo info);

	void PopSellSig(void);
	void PopBuySig(void);

	TradeSigInfo FrontSellSig();
	TradeSigInfo FrontBuySig();

	bool EmptySellSig(void);
    bool EmptyBuySig(void);
};
//---------------------------------------------------------------------------
#endif 	// CLSqueueH
//---------------------------------------------------------------------------
// End of CLSqueue.h
//---------------------------------------------------------------------------
