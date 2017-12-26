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
const int OP_ERR_NONE               = 0;    // ����ó��
const int OP_ERR_FAIL               = -10;  // ����
const int OP_ERR_LOGIN              = -100; // �����������ȯ����
const int OP_ERR_CONNECT            = -101; // �������ӽ���
const int OP_ERR_VERSION            = -102; // ����ó������
const int OP_ERR_FIREWALL           = -103; // ���ι�ȭ������
const int OP_ERR_MEMORY             = -104; // �޸𸮺�ȣ����
const int OP_ERR_INPUT              = -105; // �Լ��Է°�����
const int OP_ERR_SOCKET_CLOSED      = -106; // ��ſ�������
const int OP_ERR_SISE_OVERFLOW      = -200; // �ü���ȸ������
const int OP_ERR_RQ_STRUCT_FAIL     = -201; // �����ۼ��ʱ�ȭ����
const int OP_ERR_RQ_STRING_FAIL     = -202; // �����ۼ��Է°�����
const int OP_ERR_NO_DATA            = -203; // �����;���.
const int OP_ERR_OVER_MAX_DATA      = -204; // ��ȸ������������ʰ�
const int OP_ERR_DATA_RCV_FAIL      = -205; // �����ͼ��Ž���
const int OP_ERR_OVER_MAX_FID       = -206; // ��ȸ������FID���ʰ�
const int OP_ERR_REAL_CANCEL        = -207; // �ǽð���������
const int OP_ERR_ORD_WRONG_INPUT    = -300; // �Է°�����
const int OP_ERR_ORD_WRONG_ACCTN    = -301; // ���º�й�ȣ����
const int OP_ERR_OTHER_ACC_USE      = -302; // Ÿ�ΰ��»�����
const int OP_ERR_MIS_2BILL_EXC      = -303; // �ֹ�������20������ʰ�
const int OP_ERR_MIS_5BILL_EXC      = -304; // �ֹ�������50������ʰ�
const int OP_ERR_MIS_1PER_EXC       = -305; // �ֹ��������ѹ����ּ���1%�ʰ�����
const int OP_ERR_MIS_3PER_EXC 	    = -306;	// �ֹ��������ѹ����ּ���3%�ʰ�����
const int OP_ERR_SEND_FAIL 		    = -307;	// �ֹ����۽���
const int OP_ERR_ORD_OVERFLOW 	    = -308;	// �ֹ����۰�����
const int OP_ERR_MIS_300CNT_EXC     = -309;	// �ֹ�����300����ʰ�
const int OP_ERR_MIS_500CNT_EXC     = -310;	// �ֹ�����500����ʰ�
const int OP_ERR_ORD_WRONG_ACCTINFO = -340;	// ������������
const int OP_ERR_ORD_SYMCODE_EMPTY 	= -500;	// �����ڵ����
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
	BSTR IT_TotalPurchase;  // �� ���Աݾ�
	BSTR IT_Day_P_L_Rate;	// ���� ���ͷ�
	BSTR IT_CumulativeRate;  // ���� ������
	BSTR IT_CumulativePrice; // ���� ���� ����

}OPW00004;
//------------------------------------------------------------------------------
typedef struct
{
	OPW00004 TR_ACC_EST;	// ��������Ȳ��û ( OPW00004 )
}TRLIST;
extern TRLIST TrList;
//------------------------------------------------------------------------------
#endif // DefineH
//------------------------------------------------------------------------------
// End of Define.h
//------------------------------------------------------------------------------

