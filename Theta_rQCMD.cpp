
#include "stdafx.h"
#include "TW.h"
#include "Theta_rQCMD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg_rQ;

char  QQ_rQ[10], QP_rQ[10], QS11[10], QS12[10], QS21[10], QS22[10], QR1[10], QR2[10],Q_QrQ[10], Q_rQ[10];

Theta_rQCMD::Theta_rQCMD(CWnd* pParent )
	: CDialog(Theta_rQCMD::IDD, pParent)
{
	//{{AFX_DATA_INIT(Theta_rQCMD)
	m_ch_GZ = 0;
	m_ch_x = 0;
	m_CMD = "Theta_rQ";
	m_MAX = "160";
	m_MIN = "40";
	m_QP = 1;
	m_QQ = 1;
	m_QQQ = 0;
	m_QR1 = 0;
	m_QR2 = 0;
	m_QS11 = 1;
	m_QS12 = 1;
	m_QS21 = 1;
	m_QS22 = 1;
	m_SEED = "0";
	m_GZ = "";
	m_M = "30";
	m_N = "20";
	m_S = "30000";
	m_V = "5";
	m_X = "";
	//}}AFX_DATA_INIT
}


void Theta_rQCMD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Theta_rQCMD)
	DDX_Control(pDX, IDC_X, m_X_ctr);
	DDX_Check(pDX, IDC_CHECK__GZ, m_ch_GZ);
	DDX_Check(pDX, IDC_CHECK__X, m_ch_x);
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_COMBO_Max, m_MAX);
	DDX_CBString(pDX, IDC_COMBO_Min, m_MIN);
	DDX_CBIndex(pDX, IDC_COMBO_QP, m_QP);
	DDX_CBIndex(pDX, IDC_COMBO_QQ, m_QQ);
	DDX_CBIndex(pDX, IDC_COMBO_QQQ, m_QQQ);
	DDX_CBIndex(pDX, IDC_COMBO_QR1, m_QR1);
	DDX_CBIndex(pDX, IDC_COMBO_QR2, m_QR2);
	DDX_CBIndex(pDX, IDC_COMBO_QS11, m_QS11);
	DDX_CBIndex(pDX, IDC_COMBO_QS12, m_QS12);
	DDX_CBIndex(pDX, IDC_COMBO_QS21, m_QS21);
	DDX_CBIndex(pDX, IDC_COMBO_QS22, m_QS22);
	DDX_CBString(pDX, IDC_COMBO_SEED, m_SEED);
	DDX_Text(pDX, IDC_GZ, m_GZ);
	DDX_Text(pDX, IDC_M, m_M);
	DDX_Text(pDX, IDC_N, m_N);
	DDX_Text(pDX, IDC_S, m_S);
	DDX_Text(pDX, IDC_V, m_V);
	DDX_Text(pDX, IDC_X, m_X);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Theta_rQCMD, CDialog)
	//{{AFX_MSG_MAP(Theta_rQCMD)
	ON_BN_CLICKED(ID_INFO, OnInfo)
	ON_BN_CLICKED(ID_LOG, OnLog)
	ON_BN_CLICKED(IDC_CHECK__GZ, OnCheckGz)
	ON_BN_CLICKED(IDC_CHECK__X, OnCheckX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL Theta_rQCMD::OnInitDialog() { CDialog::OnInitDialog();return 1; }

void Theta_rQCMD::OnCheckX() 
{
	UpdateData(1); 
	
	m_X_ctr.SetReadOnly(!m_ch_x); 

	UpdateData(0);
	
	if(m_ch_x==0) Theta_rQCMD::OnCheckGz();		
}

void Theta_rQCMD::OnCheckGz() 
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


void Theta_rQCMD::OnInfo() { system("start Theta_rQ.exe"); }

void Theta_rQCMD::OnLog() 	{ system("start Theta_rQ_log.txt");  }	

void Theta_rQCMD::OnOK() 
{
    UpdateData(1);

	itoa(m_QQ,QQ_rQ,    10);
	itoa(m_QP,QP_rQ,    10);
	itoa(m_QS11,QS11,   10);
	itoa(m_QS12,QS12,   10);
	itoa(m_QS21,QS21,   10);
	itoa(m_QS22,QS22,   10);
	itoa(m_QR1+1,QR1,   10);
	itoa(m_QR2+1,QR2,   10);
	itoa(m_QQQ+1,Q_rQ,  10); 
    
	UpdateData(0);

		          arg_rQ+="Start ";
		          arg_rQ+=m_CMD;  arg_rQ+=" ";
		          arg_rQ+=m_SEED; arg_rQ+=" ";
		          arg_rQ+=m_MIN;  arg_rQ+=" ";
		          arg_rQ+=m_MAX;  arg_rQ+=" ";
		          arg_rQ+=QQ_rQ;  arg_rQ+=" ";
		          arg_rQ+=QP_rQ;  arg_rQ+=" ";
				  arg_rQ+=QS11;   arg_rQ+=" ";
				  arg_rQ+=QS12;   arg_rQ+=" ";
				  arg_rQ+=QS21;   arg_rQ+=" ";
				  arg_rQ+=QS22;   arg_rQ+=" ";
				  arg_rQ+=QR1;    arg_rQ+=" ";
				  arg_rQ+=QR2;    arg_rQ+=" ";
				  arg_rQ+=Q_rQ;   arg_rQ+=" ";
				  arg_rQ+=m_V;    arg_rQ+=" ";
				  arg_rQ+=m_M;    arg_rQ+=" ";
				  arg_rQ+=m_N;    arg_rQ+=" ";
				  arg_rQ+=m_S;    arg_rQ+=" ";
    if(m_ch_x== 1)arg_rQ+=m_X;    arg_rQ+=" ";
	if(m_ch_GZ==1)arg_rQ+="1";    

    system(       arg_rQ );

	              arg_rQ="";
}	
	  






	

