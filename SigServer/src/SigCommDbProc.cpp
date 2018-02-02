//---------------------------------------------------------------------------
// IDevCommDbProc.cpp
// Author       :
// LastModify   : 2016.05
// Comment      :
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MainU.h"
#include "SigCommDbProc.h"
#include "IDevCommServer.h"

#include "MtPacket23.h"
#include "Mios.h"

#define MODULE_NAME     "[DATA_PROC]"

SigCommDbProc *dbProc;
//---------------------------------------------------------------------------
__fastcall SigCommDbProc::SigCommDbProc(AnsiString LogDir) : TThread(true)
{
	FreeOnTerminate=true;
	seqNo = 1;

	pDatabase	= new TSQLConnection(NULL);
	qrytodayBuy = new TSQLQuery(NULL);
	qrytodaySell = new TSQLQuery(NULL);

	pDatabase->Connected 		= false;
	pDatabase->ConnectionName	= "MySQLConnection";
	pDatabase->DriverName  		= "MySQL";
	pDatabase->LibraryName 		= "dbxmys.dll";
	pDatabase->VendorLib   		= "LIBMYSQL.dll";
	pDatabase->KeepConnection	= true;
	pDatabase->Name		 		= "SIGCOMMSVR_DBP";
	pDatabase->LoginPrompt 		= false;
	pDatabase->GetDriverFunc	= "getSQLDriverMYSQL";
	pDatabase->SQLHourGlass 	= false;

	qrytodayBuy->SQLConnection 	= pDatabase;
	qrytodaySell->SQLConnection = pDatabase;

	qrytodayBuy->SQL->Text =
	"SELECT CODE, NAME, PRICE, MARK 										\
	   FROM signal_db 														\
	  WHERE DATE_FORMAT(REG_DATE,'%Y%m%d%') = DATE_FORMAT(NOW(),'%Y%m%d%')  \
		AND MARK ='B' 														\
		AND SN ='K1'";

	qrytodaySell->SQL->Text =
	"SELECT CODE, NAME, PRICE, MARK 										\
	   FROM signal_db 														\
	  WHERE DATE_FORMAT(REG_DATE,'%Y%m%d%') = DATE_FORMAT(NOW(),'%Y%m%d%')  \
		AND MARK ='B' 														\
		AND SN ='K1'";




	/*
	qryRcptUpd	  = new TSQLQuery(NULL);
	qrySsrIsptLog = new TSQLQuery(NULL);
	qryBsIsptLog  = new TSQLQuery(NULL);
	qryHlIsptLog  = new TSQLQuery(NULL);
	qryImgLog     = new TSQLQuery(NULL);
	qryVehUpd     = new TSQLQuery(NULL);

	qrySel		  = new TSQLQuery(NULL);




	qryRcptUpd->SQLConnection 		= pDatabase;
	qrySsrIsptLog->SQLConnection 	= pDatabase;
	qryBsIsptLog->SQLConnection 	= pDatabase;
	qryHlIsptLog->SQLConnection 	= pDatabase;
	qryImgLog->SQLConnection 	    = pDatabase;
	qryVehUpd->SQLConnection 	    = pDatabase;
	qrySel->SQLConnection 			= pDatabase;
	qryRcptUpd->SQL->Text =
	"UPDATE ISPT_RCPT SET RCPT_STAT = 2 WHERE RCPT_NO = :pRcptNo";

	qryImgLog->SQL->Text =
	"INSERT INTO ISPT_PIC ( RCPT_NO, PIC_TP, PIC_NM ) \
	VALUES ( :pRcptNo, :pPicType, :pPicName )";

	qrySsrIsptLog->SQL->Text =
	"INSERT INTO SSR_ISPT_LOG ( \
		RCPT_NO 			\
		, ISPT_DT 			\
		, ISPT_CRTR_ID 		\
		, SSR_RST_CD 		\
		, SSR_ISPT_DETAIL 	\
		, OPRT_ID 			\
	 ) VALUES ( :pRcptNo, 	\
		SYSDATE, 			\
		:pIsptCrtrID, 		\
		:pSsrRstCD, 		\
		:pSsrIsptDetail, 	\
		:pOprtID )";

	qryHlIsptLog->SQL->Text =
	"INSERT INTO BS_ISPT_LOG ( \
		,RCPT_NO             \
		,ISPT_DT             \
		,HL_LMNN_RFV_UPLM    \
		,HL_LMNN_RFV_LOWLM   \
		,HL_LMNN_MSV         \
		,HL_LMNN_RST_CD 	 \
		,HL_RNG_RFV_UP 		 \
		,HL_RNG_RFV_DN 		 \
		,HL_RNG_RFV_LT 		 \
		,HL_RNG_RFV_RT 		 \
		,HL_RNG_MSV_UP 		 \
		,HL_RNG_MSV_DN 		 \
		,HL_RNG_MSV_LT 		 \
		,HL_RNG_MSV_RT 		 \
		,HL_RNG_RST_CD 		 \
		,OPRT_ID      		 \
	) VALUES ( :pRCPT_NO,  	 \
		SYSDATE, 			 \
		:pHL_LMNN_RFV_UPLM,  \
		:pHL_LMNN_RFV_LOWLM, \
		:pHL_LMNN_MSV,       \
		:pHL_LMNN_RST_CD,    \
		:pHL_RNG_RFV_UP,     \
		:pHL_RNG_RFV_DN,     \
		:pHL_RNG_RFV_LT,     \
		:pHL_RNG_RFV_RT,     \
		:pHL_RNG_MSV_UP,     \
		:pHL_RNG_MSV_DN,     \
		:pHL_RNG_MSV_LT,     \
		:pHL_RNG_MSV_RT,     \
		:pHL_RNG_RST_CD,     \
		:pOPRT_ID)";


	qryBsIsptLog->SQL->Text =
	"INSERT INTO BS_ISPT_LOG ( \
		,RCPT_NO        	\
		,ISPT_DT        	\
		,BP_FA_WT       	\
		,BP_FA_RFV      	\
		,BP_FA_MSV      	\
		,BP_FA_RST_CD   	\
		,BP_RA_WT       	\
		,BP_RA_RFV      	\
		,BP_RA_MSV      	\
		,BP_RA_RST_CD   	\
		,BP_ALL_WT      	\
		,BP_ALL_RFV     	\
		,BP_ALL_MSV     	\
		,BP_ALL_RST_CD  	\
		,SPDMT_RFV      	\
		,SPDMT_MSV      	\
		,SPDMT_RST_CD       \
		,OPRT_ID 		  	\
	) VALUES ( :pRCPT_NO,  	\
		SYSDATE, 			\
		:pBP_FA_WT,     	\
		:pBP_FA_RFV,    	\
		:pBP_FA_MSV,    	\
		:pBP_FA_RST_CD, 	\
		:pBP_RA_WT,     	\
		:pBP_RA_RFV,    	\
		:pBP_RA_MSV,    	\
		:pBP_RA_RST_CD, 	\
		:pBP_ALL_WT, 		\
		:pBP_ALL_RFV, 		\
		:pBP_ALL_MSV, 		\
		:pBP_ALL_RST_CD, 	\
		:pSPDMT_RFV, 		\
		:pSPDMT_MSV, 		\
		:pSPDMT_RST_CD,     \
		:pOPRT_ID )";

	qryVehUpd->SQL->Text =
	"UPDATE VH SET RUN_DIST = :pRunDist 		\
		WHERE VIN = ( SELECT VIN FROM ISPT_RCPT \
			WHERE RCPT_NO = :pRcptNo)";

	logDir = LogDir;
	idevVersionChanged = false;            */
}

//---------------------------------------------------------------------------
int __fastcall SigCommDbProc::GetSeqNo()
{
	seqNo = ( seqNo == 65535 ) ? 1 : seqNo+1;
	return seqNo;
}

//---------------------------------------------------------------------------
//  ConnectDB
//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::ConnectDB(void)
{
	AnsiString strLog;
	try {
		pDatabase->Params->Values["Database" ] 	= "mcsig";
		pDatabase->Params->Values["User_Name"] 	= "mcadmin";
		pDatabase->Params->Values["PassWord" ] 	= "anchor21**";
		pDatabase->Params->Values["SchemaOverride"] = "%.dbo";
		pDatabase->Params->Values["ServerCharSet"] = "utf8";
		pDatabase->Connected   = true;
    }
	catch(...){
		pDatabase->Connected   = false;
		strLog.printf( "%s Database connection failed");
        pDatabase->Connected   = false;
	}

}

//---------------------------------------------------------------------------
bool __fastcall SigCommDbProc::DBConnected()
{
    return pDatabase->Connected;
}

//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::StartProcess()
{
    Start();
}

//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::StopProcess()
{
    Terminate();
}

//---------------------------------------------------------------------------
// Execute
//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::Execute()
{
    bool ret;
	MtPacket    devPacket;
    AnsiString  strLog;
    int qSize;
    int i;
	unsigned int mdtID;
    TDateTime curTime;
    double curTimeSec;
	int loopCnt;

	SSR_ISPT_RES ssrIstpRes;
	HL_ISPT_RES  hlIstpRes;
	BS_ISPT_RES  bsIstpRes;

	ISPT_STAT    isptStat;

    strLog.sprintf( "%s 시작됨",MODULE_NAME );
    MainF->SysLog(strLog.c_str(), 1, true);

    strLog.printf( "ConnectDB : start" );
    DbProcLog( strLog );

	while( !Terminated )
	{
		if( !pDatabase->Connected )
        {
			ConnectDB();
			if( !pDatabase->Connected )
			{
				Sleep(3000);
				//qSize = devPacketQ.size();
				//if(  qSize > 2048 ) devPacketQ.clear();

//				qSize = ssrIsptLogQ.size();
//				if(  qSize > 2048 ) ssrIsptLogQ.clear();

//				qSize = isptStatQ.size();
//				if(  qSize > 2048 ) isptStatQ.clear();
			}
		}
		else if( MainF->DB_READY )  // DB Reload
		{
			qSize = isptStatQ.size();
			for( i=0; i<qSize; i++)
			{
				isptStatQ.pop( &isptStat );
				if( !UpdateIsptStat(&isptStat) ) break;
			}

			/*
			qSize = devPacketQ.size();
			for( i=0; i<qSize; i++)
			{
				devPacketQ.pop( &devPacket );
				ProcessPacket(&devPacket);
			}
            */

			qSize = ssrIsptLogQ.size();
			for( i=0; i<qSize; i++)
			{
				ssrIsptLogQ.pop( &ssrIstpRes );
				if( !SaveSsrIsptLog(&ssrIstpRes) ) break;
			}

			qSize = hlIsptLogQ.size();
			for( i=0; i<qSize; i++)
			{
				hlIsptLogQ.pop( &hlIstpRes );
				if( !SaveHlIsptLog(&hlIstpRes) ) break;
			}

			qSize = bsIsptLogQ.size();
			for( i=0; i<qSize; i++)
			{
				bsIsptLogQ.pop( &bsIstpRes );
				if( !SaveBsIsptLog(&bsIstpRes) ) break;
			}

        }

        //================================================
        // DB 버전체크
        //================================================
		if( pDatabase->Connected && loopCnt >= 100 )
        {
            loopCnt = 0;
			if( idevVersionChanged || (ret = ChangeIDevInfo()) )
            {
				idevVersionChanged = false;
				LoadNewIDevInfo();
				MainF->ApplyNewIDevInfo();
			}

			if( !ret ) {
				pDatabase->Connected = false;
			}
        }
        else {
            loopCnt++;
        }

		if(!Terminated) Sleep(200);
  	}
    Finalize();
}

//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::DatabaseAfterConnect(TObject *Sender)
{
    AnsiString strLog;
	strLog.sprintf( "%s DB Connected", MODULE_NAME );
	MainF->SysLog(strLog.c_str(), 1, true);
}

//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::DatabaseAfterDisconnect(TObject *Sender)
{
	if( !Terminated )
	{
		AnsiString strLog;
		strLog.sprintf( "%s DB Disconnected", MODULE_NAME );
        MainF->SysLog(strLog.c_str(), 1, true);
    }
}

/*
//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::AddPacket(const MtPacket *p)
{
	devPacketQ.push( *p );
}
*/

//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::AddIsptStat(const LP_ISPT_STAT pStat)
{
	isptStatQ.push( *pStat );
}


//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::AddSsrIsptLog(const LP_SSR_ISPT_RES pRes)
{
	ssrIsptLogQ.push( *pRes );
}


//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::AddHlIsptLog(const LP_HL_ISPT_RES pRes)
{
	hlIsptLogQ.push( *pRes );
}

//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::AddBsIsptLog(const LP_BS_ISPT_RES pRes)
{
	bsIsptLogQ.push( *pRes );
}



//---------------------------------------------------------------------------
//  IDEV정보 변경 Check
//---------------------------------------------------------------------------
bool __fastcall SigCommDbProc::ChangeIDevInfo()
{
    AnsiString strSql;
	int result;

	if( MainF->IDdevDbVersion == 0 ) return false;

	strSql = "SELECT CONFIG_VAL FROM SYS_CONFIG WHERE CONFIG_ID = 30";
	if((result = OpenSQL(qrySel, strSql)) < 0) return false;

	if(!qrySel->Eof)
	{
        int version = qrySel->FieldByName("CONFIG_VAL")->AsInteger;
		if( version > 0 && version != MainF->IDdevDbVersion )
        {
			MainF->IDdevDbVersion = version;

            AnsiString strLog;
            strLog.sprintf( "%s ChangeVersion: %d", MODULE_NAME, version );
            MainF->SysLog(strLog.c_str(), 1, true);

            qrySel->Close();
            return true;
        }
    }
    qrySel->Close();
    return false;
}

//---------------------------------------------------------------------------
//  IDEV 변경정보 로드
//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::LoadNewIDevInfo()
{
	int result;
	AnsiString strLog;
	int devID;
	int i;

	TmpTotalIDev = 0;

	qrySel->SQL->Text =
	"SELECT ISPT_EQUIP_ID, ISPT_EQUIP_TP, ISPT_EQUIP_NM \
		FROM ISPT_EQUIP                                 \
	WHERE USE_YN = 'Y'                                  \
	ORDER BY ISPT_EQUIP_ID";

	i = 0;
	if((result = OpenSQL(qrySel)) > 0)
	{
        try {
			while( !qrySel->Eof)
            {
				devID = qrySel->FieldByName("ISPT_EQUIP_ID" )->AsInteger;

				TmpIDevInfos[i].devID   = devID;
				TmpIDevInfos[i].devType = qrySel->FieldByName("ISPT_EQUIP_TP")->AsInteger;
				snprintf( TmpIDevInfos[i].devName,  16, "%s", qrySel->FieldByName("ISPT_EQUIP_NM")->AsAnsiString.c_str() );

				i++;
				qrySel->Next();
			}
        }catch(...){
			strLog.sprintf( "%s LOAD IDEV : %d Loading Fail", MODULE_NAME, i );
            MainF->SysLog(strLog.c_str(), 1, true);
        }

		TmpTotalIDev = i;
    }
    qrySel->Close();
}

//---------------------------------------------------------------------------
/*
bool __fastcall SigCommDbProc::ProcessPacket(const MtPacket *p)
{
	const unsigned char* pData;
	unsigned char reqOpCode;

	bool ret = true;
	switch( p->getOpCode() )
	{
		//case 0x51 : // 관능검사결과 저장
		//	SaveSsrIsptLog(p);
			break;
		default  :
			break;
	}
	return ret;
}
*/

//---------------------------------------------------------------------------
bool __fastcall SigCommDbProc::UpdateIsptStat(const LP_ISPT_STAT pStat)
{
	AnsiString strLog;
	bool ret;

	strLog.sprintf( "[검사시작 업데이트] %s", pStat->RCPT_NO );
	DbProcLog(strLog);

	try {
		qryRcptUpd->ParamByName("pRcptNo")->AsAnsiString = pStat->RCPT_NO;

		ret = ExecSQL( qryRcptUpd );
		if( ret == ORAERR_NOT_CONNECTED || ret == ORAERR_NOT_LOGGED_ON ) {
			pDatabase->Connected = false;
			return false;
		}
	}catch(...){
		strLog.sprintf( "[검사시작 업데이트] Param Set failed");
		DbProcLog(strLog);
	}

	return true;
}


//---------------------------------------------------------------------------
bool __fastcall SigCommDbProc::SaveSsrIsptLog(const LP_SSR_ISPT_RES pRes)
{
	AnsiString strLog;
	bool ret;

	strLog.sprintf( "[관능검사결과 이력저장] %s CNT:%d CAPMODE:%d",
		pRes->RCPT_NO, pRes->ITEM_CNT, pRes->CAP_MODE );
	DbProcLog(strLog);

	//========================================================
	// 주행거리 업데이트
    //========================================================
	try
	{
		qryVehUpd->ParamByName("pRcptNo"  )->AsAnsiString = pRes->RCPT_NO;
		qryVehUpd->ParamByName("pRunDist" )->AsInteger    = pRes->RUN_DISTANCE;

		ret = ExecSQL( qryVehUpd );
		if( ret == ORAERR_NOT_CONNECTED || ret == ORAERR_NOT_LOGGED_ON ) {
			pDatabase->Connected = false;
			return false;
		}
	}catch(...){
		strLog.sprintf( "[주행거리 업데이트] Param Set failed");
		DbProcLog(strLog);
	}

	//========================================================
	// 검사이미지 저장
	//========================================================
	if( (pRes->CAP_MODE & 0x01) == 0x01 )
	{
		try {
			qryImgLog->ParamByName("pRcptNo"  )->AsAnsiString = pRes->RCPT_NO;
			qryImgLog->ParamByName("pPicType" )->AsInteger    = 1;
			qryImgLog->ParamByName("pPicName" )->AsAnsiString = pRes->FRONT_IMG;

			ret = ExecSQL( qryImgLog );
			if( ret == ORAERR_NOT_CONNECTED || ret == ORAERR_NOT_LOGGED_ON ) {
				pDatabase->Connected = false;
				return false;
			}
		}catch(...){
			strLog.sprintf( "[관능검사이미지 저장] Param Set failed");
			DbProcLog(strLog);
		}
	}


	if( (pRes->CAP_MODE & 0x02) == 0x02 )
	{
		try {
			qryImgLog->ParamByName("pRcptNo"  )->AsAnsiString = pRes->RCPT_NO;
			qryImgLog->ParamByName("pPicType" )->AsInteger    = 2;
			qryImgLog->ParamByName("pPicName" )->AsAnsiString = pRes->SIDE_IMG;

			ret = ExecSQL( qryImgLog );
			if( ret == ORAERR_NOT_CONNECTED || ret == ORAERR_NOT_LOGGED_ON ) {
				pDatabase->Connected = false;
				return false;
			}
		}catch(...){
			strLog.sprintf( "[관능검사이미지 저장] Param Set failed");
			DbProcLog(strLog);
		}
	}


    if( (pRes->CAP_MODE & 0x04) == 0x04 )
	{
		try {
			qryImgLog->ParamByName("pRcptNo"  )->AsAnsiString = pRes->RCPT_NO;
			qryImgLog->ParamByName("pPicType" )->AsInteger    = 3;
			qryImgLog->ParamByName("pPicName" )->AsAnsiString = pRes->REAR_IMG;

			ret = ExecSQL( qryImgLog );
			if( ret == ORAERR_NOT_CONNECTED || ret == ORAERR_NOT_LOGGED_ON ) {
				pDatabase->Connected = false;
				return false;
			}
		}catch(...){
			strLog.sprintf( "[관능검사이미지 저장] Param Set failed");
			DbProcLog(strLog);
		}
	}


	//========================================================
	// 검사결과 저장
	//========================================================
	try {
		for( int i=0; i< pRes->ITEM_CNT; i++)
		{
			qrySsrIsptLog->ParamByName("pRcptNo"    )->AsAnsiString = pRes->RCPT_NO;
			qrySsrIsptLog->ParamByName("pIsptCrtrID")->AsAnsiString = pRes->ITEM[i].ISPT_CODE;
			qrySsrIsptLog->ParamByName("pSsrRstCD"  )->AsInteger    = pRes->ITEM[i].ISPT_RESULT;
			qrySsrIsptLog->ParamByName("pOprtID"    )->AsAnsiString = pRes->OPRT_ID;

			if( pRes->ITEM[i].ISPT_ETC_LEN > 0 )
			{
				qrySsrIsptLog->ParamByName("pSsrIsptDetail")->AsAnsiString = pRes->ITEM[i].ISPT_ETC;
			}
			else {
				qrySsrIsptLog->ParamByName("pSsrIsptDetail")->AsAnsiString = "-";
            }

			ret = ExecSQL( qrySsrIsptLog );
			if( ret == ORAERR_NOT_CONNECTED || ret == ORAERR_NOT_LOGGED_ON ) {
				pDatabase->Connected = false;
				return false;
			}
		}
	}catch(...){
		strLog.sprintf( "[관능검사결과 이력저장] Param Set failed");
		DbProcLog(strLog);
	}

	return true;
}

//---------------------------------------------------------------------------
bool __fastcall SigCommDbProc::SaveHlIsptLog( const LP_HL_ISPT_RES pRes)
{
	AnsiString strLog;
	AnsiString strIsptDate;
	bool ret;

	strLog.sprintf( "[전조등검사결과 이력저장] %s", pRes->RCPT_NO );
	DbProcLog(strLog);

	//MtPacket52::getInspectionResult(p->getBody(), &res);

	try {
		/*
		strIsptDate.printf("%4d%02hu%02hu%02hu%02hu%02hu",
			res.ISPT_DATE[0], res.ISPT_DATE[1], res.ISPT_DATE[2],
			res.ISPT_DATE[3], res.ISPT_DATE[4], res.ISPT_DATE[5] );
		*/
		qryHlIsptLog->ParamByName("pRCPT_NO"          )->AsString  = pRes->RCPT_NO;
		qryHlIsptLog->ParamByName("pHL_LMNN_RFV_UPLM" )->AsInteger = pRes->HL_LMNN_RFV_UPLM;
		qryHlIsptLog->ParamByName("pHL_LMNN_RFV_LOWLM")->AsInteger = pRes->HL_LMNN_RFV_LOWLM;
		qryHlIsptLog->ParamByName("pHL_LMNN_MSV"      )->AsInteger = pRes->HL_LMNN_MSV;
		qryHlIsptLog->ParamByName("pHL_LMNN_RST_CD"   )->AsInteger = pRes->HL_LMNN_RST_CD;

		qryHlIsptLog->ParamByName("pHL_RNG_RFV_UP"    )->AsInteger = pRes->HL_RNG_RFV_UP;
		qryHlIsptLog->ParamByName("pHL_RNG_RFV_DN"    )->AsInteger = pRes->HL_RNG_RFV_DN;
		qryHlIsptLog->ParamByName("pHL_RNG_RFV_LT"    )->AsInteger = pRes->HL_RNG_RFV_LT;
		qryHlIsptLog->ParamByName("pHL_RNG_RFV_RT"    )->AsInteger = pRes->HL_RNG_RFV_RT;

		qryHlIsptLog->ParamByName("pHL_RNG_MSV_UP"    )->AsFloat   = pRes->HL_RNG_MSV_UP;
		qryHlIsptLog->ParamByName("pHL_RNG_MSV_DN"    )->AsFloat   = pRes->HL_RNG_MSV_DN;
		qryHlIsptLog->ParamByName("pHL_RNG_MSV_LT"    )->AsFloat   = pRes->HL_RNG_MSV_LT;
		qryHlIsptLog->ParamByName("pHL_RNG_MSV_RT"    )->AsFloat   = pRes->HL_RNG_MSV_RT;
		qryHlIsptLog->ParamByName("pHL_RNG_RST_CD"    )->AsInteger = pRes->HL_RNG_RST_CD;

		qryHlIsptLog->ParamByName("pOPRT_ID"          )->AsString  = pRes->OPRT_ID;

		ret = ExecSQL( qryHlIsptLog );
		if( ret == ORAERR_NOT_CONNECTED || ret == ORAERR_NOT_LOGGED_ON ) {
			pDatabase->Connected = false;
			return false;
		}
	}catch(...){
		strLog.sprintf( "[전조등검사결과 이력저장] Param Set failed");
		DbProcLog(strLog);
	}

	return true;
}

//---------------------------------------------------------------------------
bool __fastcall SigCommDbProc::SaveBsIsptLog( const LP_BS_ISPT_RES pRes )
{
	AnsiString strLog;
	AnsiString strIsptDate;
	bool ret;

	strLog.sprintf( "[BS검사결과 이력저장] %s", pRes->RCPT_NO );
	DbProcLog(strLog);

	//MtPacket53::getInspectionResult(p->getBody(), &res);

	try {
		/*
		strIsptDate.printf("%4d%02hu%02hu%02hu%02hu%02hu",
			res.ISPT_DATE[0], res.ISPT_DATE[1], res.ISPT_DATE[2],
			res.ISPT_DATE[3], res.ISPT_DATE[4], res.ISPT_DATE[5] );
		*/
		qryBsIsptLog->ParamByName("pRCPT_NO"      )->AsString  = pRes->RCPT_NO;

		qryBsIsptLog->ParamByName("pBP_FA_WT"     )->AsInteger = pRes->BP_FA_WT;
		qryBsIsptLog->ParamByName("pBP_FA_RFV"    )->AsInteger = pRes->BP_FA_RFV;
		qryBsIsptLog->ParamByName("pBP_FA_MSV"    )->AsInteger = pRes->BP_FA_MSV;
		qryBsIsptLog->ParamByName("pBP_FA_RST_CD" )->AsInteger = pRes->BP_FA_RST_CD;

		qryBsIsptLog->ParamByName("pBP_RA_WT"     )->AsInteger = pRes->BP_RA_WT;
		qryBsIsptLog->ParamByName("pBP_RA_RFV"    )->AsInteger = pRes->BP_RA_RFV;
		qryBsIsptLog->ParamByName("pBP_RA_MSV"    )->AsInteger = pRes->BP_RA_MSV;
		qryBsIsptLog->ParamByName("pBP_RA_RST_CD" )->AsInteger = pRes->BP_RA_RST_CD;

		qryBsIsptLog->ParamByName("pBP_ALL_WT"    )->AsInteger = pRes->BP_ALL_WT;
		qryBsIsptLog->ParamByName("pBP_ALL_RFV"   )->AsInteger = pRes->BP_ALL_RFV;
		qryBsIsptLog->ParamByName("pBP_ALL_MSV"   )->AsInteger = pRes->BP_ALL_MSV;
		qryBsIsptLog->ParamByName("pBP_ALL_RST_CD")->AsInteger = pRes->BP_ALL_RST_CD;

		qryBsIsptLog->ParamByName("pSPDMT_RFV"    )->AsInteger = pRes->SPDMT_RFV;
		qryBsIsptLog->ParamByName("pSPDMT_MSV"    )->AsInteger = pRes->SPDMT_MSV;
		qryBsIsptLog->ParamByName("pSPDMT_RST_CD" )->AsInteger = pRes->SPDMT_RST_CD;

		qryBsIsptLog->ParamByName("pOPRT_ID"      )->AsString  = pRes->OPRT_ID;
		ret = ExecSQL( qryBsIsptLog );
		if( ret == ORAERR_NOT_CONNECTED || ret == ORAERR_NOT_LOGGED_ON ) {
			pDatabase->Connected = false;
			return false;
		}
	}catch(...){
		strLog.sprintf( "[BS검사결과 이력저장] Param Set failed");
		DbProcLog(strLog);
	}

	return true;
}


//---------------------------------------------------------------------------
int  __fastcall SigCommDbProc::OpenSQL(TSQLQuery *pQry, AnsiString strSql)
{
	int iOraErr;
	int iResult = 1;

	try{
		if(!pDatabase->Connected) return ORAERR_NOT_CONNECTED;
		if(pQry->Active) pQry->Close();
		pQry->SQL->Text = strSql;
		pQry->Open();
		//iResult = pQry->RecordCount;
    }catch(const Exception &E){
        iOraErr = GetOracleError(E.Message);
        iResult = GetOracleErrorResult( iOraErr );
        WriteQueryError(E.Message, strSql);
    }
    return iResult;
}

//---------------------------------------------------------------------------
int  __fastcall SigCommDbProc::OpenSQL(TSQLQuery *pQry)
{
    int iOraErr;
	int iResult = 1;

    try{
		if(!pDatabase->Connected) return ORAERR_NOT_CONNECTED;
        if(pQry->Active) pQry->Close();
        pQry->Open();
		//iResult = pQry->RecordCount;
    }catch(const Exception &E){
        iOraErr = GetOracleError(E.Message);
		iResult = GetOracleErrorResult( iOraErr );
        WriteQueryError(E.Message, pQry->SQL->Text);
    }
    return iResult;
}

//---------------------------------------------------------------------------
int  __fastcall SigCommDbProc::ExecSQL(TSQLQuery *pQry)
{
    int iOraErr;
    int iResult = -1;

	if( !pDatabase->Connected ) return ORAERR_NOT_CONNECTED;
    if( pQry->Active ) pQry->Close();
    try{
        pQry->ExecSQL();
        iResult = pQry->RowsAffected;
	}
	catch(const Exception &E){
        iOraErr = GetOracleError(E.Message);
        if     (iOraErr == 1012) iResult = ORAERR_NOT_LOGGED_ON;
        else if(iOraErr == 3114) iResult = ORAERR_NOT_CONNECTED;
        WriteQueryError(E.Message, pQry->SQL->Text);
    }
    return iResult;
}

//---------------------------------------------------------------------------
int  __fastcall SigCommDbProc::ExecSQL(TSQLQuery *pQry, AnsiString strSql)
{
    int iOraErr;
    int iResult = -1;

    if(!pDatabase->Connected) return ORAERR_NOT_CONNECTED;
    if(pQry->Active) pQry->Close();
    pQry->SQL->Text = strSql;
    try{
        pQry->ExecSQL();
        iResult = pQry->RowsAffected;
    }catch(const Exception &E){
        iOraErr = GetOracleError(E.Message);
        if     (iOraErr == 1012) iResult = ORAERR_NOT_LOGGED_ON;
        else if(iOraErr == 3114) iResult = ORAERR_NOT_CONNECTED;
        WriteQueryError(E.Message, strSql);
    }
    return iResult;
}

//---------------------------------------------------------------------------
int  __fastcall SigCommDbProc::GetOracleError(AnsiString sErrMsg)
{
    int iErrNo = 0;
    for(int i=1; i<sErrMsg.Length()-7; i++)
    {
        if(sErrMsg.SubString(i, 4) == "ORA-"){
            iErrNo = StrToIntDef( sErrMsg.SubString(i+4, 5), 0);
            break;
        }
    }
    return iErrNo;
}

//---------------------------------------------------------------------------
int  __fastcall SigCommDbProc::GetOracleErrorResult(int iOraErrCode)
{
	int iResult;
	switch( iOraErrCode )
	{
		case 1012	: iResult = ORAERR_NOT_LOGGED_ON;  break;
		case 3114	:
		case 12150	:
		case 12151	:
		case 12152	:
		case 12153  : iResult = ORAERR_NOT_CONNECTED;  break;
		default		: iResult = 1;
	}
	return iResult;
}

//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::WriteQueryError(AnsiString strOraErr, AnsiString strSql)
{
    HANDLE     hFile;
    DWORD      dwWriteSize;
    AnsiString strFName;
	AnsiString strMsg;

	strFName.printf("%s\\ORAERR_%hu-%02hu-%02hu.txt",
		MainF->LOG_ROOT, MainF->sysYear, MainF->sysMon, MainF->sysDay );

    if((hFile = CreateFile(strFName.c_str(),
                        GENERIC_READ|GENERIC_WRITE,
                        FILE_SHARE_READ,
                        NULL,
                        OPEN_ALWAYS,
                        FILE_ATTRIBUTE_NORMAL,
						NULL)) == INVALID_HANDLE_VALUE) return;

    SetFilePointer(hFile, 0, NULL, FILE_END);

	strMsg = Now().FormatString("yyyy-mm-dd hh:nn:ss") + "\r\n";
	WriteFile(hFile, strMsg.c_str(), strMsg.Length(), &dwWriteSize, NULL);

	strMsg = strOraErr + "\r\n";
	WriteFile(hFile, strMsg.c_str(), strMsg.Length(), &dwWriteSize, NULL);

    strMsg = strSql + "\r\n";
    WriteFile(hFile, strMsg.c_str(), strMsg.Length(), &dwWriteSize, NULL);
    CloseHandle(hFile);
}

//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::DbProcLog(AnsiString str)
{
    HANDLE     hFile;
	DWORD      dwWriteSize;
	AnsiString strLog;

	strLog.printf("[%02hu:%02hu:%02hu] %s\r\n", MainF->sysHour, MainF->sysMin, MainF->sysSec, str.c_str() );

	MainF->logDateChange();
	if((hFile = CreateFile(strDbProcLogFile,
						   GENERIC_READ|GENERIC_WRITE,
						   FILE_SHARE_READ,
						   NULL,
						   OPEN_ALWAYS,
                           FILE_ATTRIBUTE_NORMAL,
                           NULL)) == INVALID_HANDLE_VALUE) return;
    SetFilePointer(hFile, 0, NULL, FILE_END);

    WriteFile(hFile, strLog.c_str(), strLog.Length(), &dwWriteSize, NULL);
    CloseHandle(hFile);
}

//---------------------------------------------------------------------------
void __fastcall SigCommDbProc::Finalize()
{
	delete qryRcptUpd;
	delete qrySsrIsptLog;
	delete qryBsIsptLog;
	delete qryHlIsptLog;
	delete qryImgLog;
	delete qryVehUpd;
	delete qrySel;

	AnsiString strLog;
	strLog.sprintf( "%s Stopped", MODULE_NAME);
	MainF->SysLog(strLog.c_str(), 1, true);
}
//---------------------------------------------------------------------------







