
#include "stdafx.h"
#include "TW.h"
#include "Theta_QvCMD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg_Qv;

char  QQ_Qv[10], QP_Qv[10], QS1_Qv[10], QS2_Qv[10], Q_QQv[10], Q_Qv[10];

Theta_QvCMD::Theta_QvCMD(CWnd* pParent )
	: CDialog(Theta_QvCMD::IDD, pParent)
{
	//{{AFX_DATA_INIT(Theta_QvCMD)
	m_ch_GZ = 0;
	m_ch_x = 0;
	m_CMD = "Theta_Qv";
	m_MAX = "160";
	m_MIN = "40";
	m_Q = 0;
	m_QP = 1;
	m_QQ = 1;
	m_QS1 = 1;
	m_QS2 = 1;
	m_SEED ="0";
	m_GZ = "";
	m_N = "30";
	m_V = "5";
	m_S = "30000";
	m_X = "";
	m_QQQ = 1;
	//}}AFX_DATA_INIT
}


void Theta_QvCMD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Theta_QvCMD)
	DDX_Control(pDX, IDC_X, m_X_ctr);
	DDX_Check(pDX, IDC_CHECK__GZ, m_ch_GZ);
	DDX_Check(pDX, IDC_CHECK__X, m_ch_x);
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_COMBO_Max, m_MAX);
	DDX_CBString(pDX, IDC_COMBO_Min, m_MIN);
	DDX_CBIndex(pDX, IDC_COMBO_Q, m_Q);
	DDX_CBIndex(pDX, IDC_COMBO_QP, m_QP);
	DDX_CBIndex(pDX, IDC_COMBO_QQ, m_QQ);
	DDX_CBIndex(pDX, IDC_COMBO_QS1, m_QS1);
	DDX_CBIndex(pDX, IDC_COMBO_QS2, m_QS2);
	DDX_CBString(pDX, IDC_COMBO_SEED, m_SEED);
	DDX_Text(pDX, IDC_GZ, m_GZ);
	DDX_Text(pDX, IDC_N, m_N);
	DDX_Text(pDX, IDC_V, m_V);
	DDX_Text(pDX, IDC_S, m_S);
	DDX_Text(pDX, IDC_X, m_X);
	DDX_CBIndex(pDX, IDC_COMBO_QQQ, m_QQQ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Theta_QvCMD, CDialog)
	//{{AFX_MSG_MAP(Theta_QvCMD)
	ON_BN_CLICKED(ID_INFO, OnInfo)
	ON_BN_CLICKED(ID_LOG, OnLog)
	ON_BN_CLICKED(IDC_CHECK__GZ, OnCheckGz)
	ON_BN_CLICKED(IDC_CHECK__X, OnCheckX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL Theta_QvCMD::OnInitDialog(){ CDialog::OnInitDialog();return 1;}

void Theta_QvCMD::OnCheckX() 
{
	UpdateData(1); 
	
	m_X_ctr.SetReadOnly(!m_ch_x); 

	UpdateData(0);
	
	if(m_ch_x==0) Theta_QvCMD::OnCheckGz();	
	
}

void Theta_QvCMD::OnCheckGz() 
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
	
void Theta_QvCMD::OnInfo() {system("start Theta_Qv.exe");   }

void Theta_QvCMD::OnLog() {system("start Theta_Qv_log.txt");     }	

		             
void Theta_QvCMD::OnOK() 
{
    UpdateData(1);

	itoa(m_QQ,QQ_Qv,  10);
	itoa(m_QP,QP_Qv,  10);
	itoa(m_QS1,QS1_Qv,10);
	itoa(m_QS2,QS2_Qv,10);
	itoa(m_QQQ,Q_QQv, 10);
	itoa(m_Q+1,Q_Qv,  10); 
    
	UpdateData(0);

		          arg_Qv+="Start ";
		          arg_Qv+=m_CMD;  arg_Qv+=" ";
		          arg_Qv+=m_SEED; arg_Qv+=" ";
		          arg_Qv+=m_MIN;  arg_Qv+=" ";
		          arg_Qv+=m_MAX;  arg_Qv+=" ";
		          arg_Qv+=QQ_Qv;  arg_Qv+=" ";
		          arg_Qv+=QP_Qv;  arg_Qv+=" ";
				  arg_Qv+=QS1_Qv; arg_Qv+=" ";
				  arg_Qv+=QS2_Qv; arg_Qv+=" ";
		          arg_Qv+=Q_QQv;  arg_Qv+=" ";
				  arg_Qv+=Q_Qv;   arg_Qv+=" ";
				  arg_Qv+=m_V;    arg_Qv+=" ";
				  arg_Qv+=m_N;    arg_Qv+=" ";
				  arg_Qv+=m_S;    arg_Qv+=" ";
    if(m_ch_x== 1)arg_Qv+=m_X;    arg_Qv+=" ";
	if(m_ch_GZ==1)arg_Qv+="1";    

    system(       arg_Qv );

	              arg_Qv="";	
}
