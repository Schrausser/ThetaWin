
#include "stdafx.h"
#include "TW.h"
#include "Theta_QCMD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg_Q;

char  QQ_Q[10], QP_Q[10], QS1_Q[10], QS2_Q[10], Q_Q[10];

Theta_QCMD::Theta_QCMD(CWnd* pParent)
	: CDialog(Theta_QCMD::IDD, pParent)
{
	//{{AFX_DATA_INIT(Theta_QCMD)
	m_Q = 0;
	m_QP = 1;
	m_QQ = 1;
	m_QS1 = 1;
	m_QS2 = 1;
	m_SEED = "0";
	m_MIN = "40";
	m_MAX ="160";
	m_CMD = "Theta_Q";
	m_ch_GZ = 0;
	m_GZ = "";
	m_M = "30";
	m_N = "20";
	m_S = "30000";
	m_V = "5";
	m_X = "";
	m_ch_x = 0;
	//}}AFX_DATA_INIT
}


void Theta_QCMD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Theta_QCMD)
	DDX_Control(pDX, IDC_X, m_X_ctr);
	DDX_CBIndex(pDX, IDC_COMBO_Q, m_Q);
	DDX_CBIndex(pDX, IDC_COMBO_QP, m_QP);
	DDX_CBIndex(pDX, IDC_COMBO_QQ, m_QQ);
	DDX_CBIndex(pDX, IDC_COMBO_QS1, m_QS1);
	DDX_CBIndex(pDX, IDC_COMBO_QS2, m_QS2);
	DDX_CBString(pDX, IDC_COMBO_SEED, m_SEED);
	DDX_CBString(pDX, IDC_COMBO_Min, m_MIN);
	DDX_CBString(pDX, IDC_COMBO_Max, m_MAX);
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_Check(pDX, IDC_CHECK__GZ, m_ch_GZ);
	DDX_Text(pDX, IDC_GZ, m_GZ);
	DDX_Text(pDX, IDC_M, m_M);
	DDX_Text(pDX, IDC_N, m_N);
	DDX_Text(pDX, IDC_S, m_S);
	DDX_Text(pDX, IDC_V, m_V);
	DDX_Text(pDX, IDC_X, m_X);
	DDX_Check(pDX, IDC_CHECK__X, m_ch_x);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Theta_QCMD, CDialog)
	//{{AFX_MSG_MAP(Theta_QCMD)
	ON_BN_CLICKED(ID_INFO, OnInfo)
	ON_BN_CLICKED(ID_LOG, OnLog)
	ON_BN_CLICKED(IDC_CHECK__GZ, OnCheckGz)
	ON_BN_CLICKED(IDC_CHECK__X, OnCheckX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL Theta_QCMD::OnInitDialog() {CDialog::OnInitDialog();return 1; }

	
void Theta_QCMD::OnCheckX() 
{
	UpdateData(1); 
	
	m_X_ctr.SetReadOnly(!m_ch_x); 

	UpdateData(0);
	
	if(m_ch_x==0) Theta_QCMD::OnCheckGz();
	
}	
	
void Theta_QCMD::OnCheckGz() 
{
	UpdateData(1); 
	
	if(m_ch_x==1)
	{
		
					  m_GZ="";
		if(m_ch_GZ==1)m_GZ="EIN";

		
	}
	else {m_ch_GZ=0;m_GZ="";}
	
	UpdateData(0);
}	
	

void Theta_QCMD::OnInfo() {system("start Theta_Q.exe");   }

void Theta_QCMD::OnLog() {system("start Theta_Q_log.txt");     }

void Theta_QCMD::OnOK() 
{
    UpdateData(1);

	itoa(m_QQ,QQ_Q,  10);
	itoa(m_QP,QP_Q,  10);
	itoa(m_QS1,QS1_Q,10);
	itoa(m_QS2,QS2_Q,10);
	itoa(m_Q+1,Q_Q,  10); 
    
	UpdateData(0);

		          arg_Q+="Start ";
		          arg_Q+=m_CMD;  arg_Q+=" ";
		          arg_Q+=m_SEED; arg_Q+=" ";
		          arg_Q+=m_MIN;  arg_Q+=" ";
		          arg_Q+=m_MAX;  arg_Q+=" ";
		          arg_Q+=QQ_Q;   arg_Q+=" ";
		          arg_Q+=QP_Q;   arg_Q+=" ";
				  arg_Q+=QS1_Q;  arg_Q+=" ";
				  arg_Q+=QS2_Q;  arg_Q+=" ";
		          arg_Q+=Q_Q;    arg_Q+=" ";
				  arg_Q+=m_V;    arg_Q+=" ";
		          arg_Q+=m_M;    arg_Q+=" ";
				  arg_Q+=m_N;    arg_Q+=" ";
				  arg_Q+=m_S;    arg_Q+=" ";
    if(m_ch_x== 1)arg_Q+=m_X;    arg_Q+=" ";
	if(m_ch_GZ==1)arg_Q+="1";    
	
    system(       arg_Q );

	              arg_Q="";	
}
