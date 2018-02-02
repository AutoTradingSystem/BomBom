//---------------------------------------------------------------------------
// IDevCommDbProc.h
// Author       : Sane
// LastModify   : 2016.05
// Comment      :
//---------------------------------------------------------------------------
#ifndef SigCommDbProcH
#define SigCommDbProcH
//---------------------------------------------------------------------------

#include <Data.DB.hpp>
#include <Data.DBXOracle.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <System.Classes.hpp>

#include "wzMQueue.h"
#include "Mios.h"
#include "IDevComm.h"

//---------------------------------------------------------------------------
class SigCommDbProc : public TThread
{
private:
	//wzQueue<MtPacket> 		  devPacketQ;
	wzQueue<ISPT_STAT>        isptStatQ;
	wzQueue<SSR_ISPT_RES>     ssrIsptLogQ;
	wzQueue<HL_ISPT_RES>      hlIsptLogQ;
	wzQueue<BS_ISPT_RES>      bsIsptLogQ;

	TSQLConnection 	*pDatabase;

	TSQLQuery    	*qryRcptUpd;
	TSQLQuery    	*qrySsrIsptLog;
	TSQLQuery    	*qryBsIsptLog;
	TSQLQuery    	*qryHlIsptLog;
	TSQLQuery    	*qryVehUpd;
	TSQLQuery    	*qryImgLog;
	TSQLQuery    	*qrySel;

	TSQLQuery    	*qrytodayBuy;
	TSQLQuery    	*qrytodaySell;


	AnsiString logDir;
	int seqNo;

	//-----------------------------------------------------------------
	int  __fastcall GetSeqNo();
    void __fastcall ConnectDB(void);
    void __fastcall DatabaseAfterConnect(TObject *Sender);
    void __fastcall DatabaseAfterDisconnect(TObject *Sender);
	void __fastcall DbProcLog(AnsiString str);

	//bool __fastcall ProcessPacket(const MtPacket *p);

	// DB FUNCTION
	int  __fastcall GetOracleError(AnsiString sErrMsg);
	int  __fastcall GetOracleErrorResult(int iOraErrCode);
	int  __fastcall OpenSQL(TSQLQuery *pQry, AnsiString strSql);
	int  __fastcall OpenSQL(TSQLQuery *pQry);
	int  __fastcall ExecSQL(TSQLQuery *pQry, AnsiString strSql);
	int  __fastcall ExecSQL(TSQLQuery *pQry);
    void __fastcall WriteQueryError(AnsiString strOraErr, AnsiString strSql);
	void __fastcall Finalize();

protected:
	virtual void __fastcall Execute(void);

public:
	bool idevVersionChanged;
	char strDbProcLogFile[128];

	__fastcall SigCommDbProc(AnsiString LogDir);

    void __fastcall StartProcess();
    void __fastcall StopProcess();
    bool __fastcall DBConnected();
	//void __fastcall AddPacket(const MtPacket *p);

	void __fastcall AddIsptStat(const LP_ISPT_STAT pStat);

	void __fastcall AddSsrIsptLog(const LP_SSR_ISPT_RES pRes);
	void __fastcall AddHlIsptLog(const LP_HL_ISPT_RES pRes);
	void __fastcall AddBsIsptLog(const LP_BS_ISPT_RES pRes);

	bool __fastcall UpdateIsptStat(const LP_ISPT_STAT pStat);
	bool __fastcall SaveSsrIsptLog(const LP_SSR_ISPT_RES pRes);
	bool __fastcall SaveBsIsptLog( const LP_BS_ISPT_RES pRes);
	bool __fastcall SaveHlIsptLog( const LP_HL_ISPT_RES pRes);

    bool __fastcall ChangeIDevInfo();
	void __fastcall LoadNewIDevInfo();
};
//---------------------------------------------------------------------------
extern SigCommDbProc *dbProc;
//---------------------------------------------------------------------------
#endif
