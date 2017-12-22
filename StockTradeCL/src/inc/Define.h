//------------------------------------------------------------------------------
#ifndef	DefineH
#define	DefineH
//---------------------------------------------------------------------------
// Include
//---------------------------------------------------------------------------
// User Message
//---------------------------------------------------------------------------
#define WM_MSGLOG               (WM_USER + 0x01)
#define WM_SENDLOG              (WM_USER + 0x02)
#define WM_SYSLOG              	(WM_USER + 0x03)
//---------------------------------------------------------------------------
#define WM_SHOW_GRD_SIG         (WM_USER + 0x04)    // Show Grid SIG Info
#define WM_SAVE_RT_SIG          (WM_USER + 0x05)    // Save Realtime SIG info
//------------------------------------------------------------------------------
#define WM_QUE_SELLSIG          (WM_USER + 0x06)    // Sell signal
#define WM_QUE_BUYSIG           (WM_USER + 0x07)    // Buy signal
//------------------------------------------------------------------------------
// Constant
//------------------------------------------------------------------------------
#define MAX_STOCK   1000;
//------------------------------------------------------------------------------
// Error Code
//------------------------------------------------------------------------------
const int OP_ERR_NONE               = 0;    // 정상처리
const int OP_ERR_FAIL               = -10;  // 실패
const int OP_ERR_LOGIN              = -100; // 사용자정보교환실패
const int OP_ERR_CONNECT            = -101; // 서버접속실패
const int OP_ERR_VERSION            = -102; // 버전처리실패
const int OP_ERR_FIREWALL           = -103; // 개인방화벽실패
const int OP_ERR_MEMORY             = -104; // 메모리보호실패
const int OP_ERR_INPUT              = -105; // 함수입력값오류
const int OP_ERR_SOCKET_CLOSED      = -106; // 통신연결종료
const int OP_ERR_SISE_OVERFLOW      = -200; // 시세조회과부하
const int OP_ERR_RQ_STRUCT_FAIL     = -201; // 전문작성초기화실패
const int OP_ERR_RQ_STRING_FAIL     = -202; // 전문작성입력값오류
const int OP_ERR_NO_DATA            = -203; // 데이터없음.
const int OP_ERR_OVER_MAX_DATA      = -204; // 조회가능한종목수초과
const int OP_ERR_DATA_RCV_FAIL      = -205; // 데이터수신실패
const int OP_ERR_OVER_MAX_FID       = -206; // 조회가능한FID수초과
const int OP_ERR_REAL_CANCEL        = -207; // 실시간해제오류
const int OP_ERR_ORD_WRONG_INPUT    = -300; // 입력값오류
const int OP_ERR_ORD_WRONG_ACCTN    = -301; // 계좌비밀번호없음
const int OP_ERR_OTHER_ACC_USE      = -302; // 타인계좌사용오류
const int OP_ERR_MIS_2BILL_EXC      = -303; // 주문가격이20억원을초과
const int OP_ERR_MIS_5BILL_EXC      = -304; // 주문가격이50억원을초과
const int OP_ERR_MIS_1PER_EXC       = -305; // 주문수량이총발행주수의1%초과오류
const int OP_ERR_MIS_3PER_EXC 	    = -306;	// 주문수량은총발행주수의3%초과오류
const int OP_ERR_SEND_FAIL 		    = -307;	// 주문전송실패
const int OP_ERR_ORD_OVERFLOW 	    = -308;	// 주문전송과부하
const int OP_ERR_MIS_300CNT_EXC     = -309;	// 주문수량300계약초과
const int OP_ERR_MIS_500CNT_EXC     = -310;	// 주문수량500계약초과
const int OP_ERR_ORD_WRONG_ACCTINFO = -340;	// 계좌정보없음
const int OP_ERR_ORD_SYMCODE_EMPTY 	= -500;	// 종목코드없음
//------------------------------------------------------------------------------
// Type definition
//------------------------------------------------------------------------------
typedef struct
{
	BSTR TRCODE;
	BSTR TRRECORD_Nm;
	BSTR IT_AccNM;
	BSTR IT_Deposit;
	BSTR IT_Deposit2;
	BSTR IT_TotalPurchase;  // 총 매입금액
	BSTR IT_Day_P_L_Rate;	// 당일 손익률
	BSTR IT_CumulativeRate;  // 누적 손익율
	BSTR IT_CumulativePrice; // 누적 투자 손익

}OPW00004;
//------------------------------------------------------------------------------
typedef struct
{
	OPW00004 TR_ACC_EST;	// 계좌평가현황요청 ( OPW00004 )
}TRLIST;
extern TRLIST TrList;
//------------------------------------------------------------------------------
#endif // DefineH
//------------------------------------------------------------------------------
// End of Define.h
//------------------------------------------------------------------------------

