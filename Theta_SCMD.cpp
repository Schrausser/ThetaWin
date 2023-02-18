#include "stdafx.h"
#include "TW.h"
#include "Theta_SCMD.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg_S;

char QP[10], QS[10], QQ_S[10];

Theta_SCMD::Theta_SCMD(CWnd* pParent )
	: CDialog(Theta_SCMD::IDD, pParent)
{
	//{{AFX_DATA_INIT(Theta_SCMD)
	m_CMD = "Theta_S";
	m_M = "30";
	m_S = "30000";
	m_V = "5";
	m_X = "";
	m_QS = 1;
	m_QQ = 1;
	m_QP = 1;
	m_MAX = "160";
	m_MIN = "40";
	m_SEED = "0";
	m_ch_GZ = 0;
	m_ch_x = 0;
	m_GZ = "";
	//}}AFX_DATA_INIT
}


void Theta_SCMD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Theta_SCMD)
	DDX_Control(pDX, IDC_X, m_X_ctr);
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_Text(pDX, IDC_M, m_M);
	DDX_Text(pDX, IDC_S, m_S);
	DDX_Text(pDX, IDC_V, m_V);
	DDX_Text(pDX, IDC_X, m_X);
	DDX_CBIndex(pDX, IDC_COMBO_QS, m_QS);
	DDX_CBIndex(pDX, IDC_COMBO_QQ, m_QQ);
	DDX_CBIndex(pDX, IDC_COMBO_QP, m_QP);
	DDX_CBString(pDX, IDC_COMBO_Max, m_MAX);
	DDX_CBString(pDX, IDC_COMBO_Min, m_MIN);
	DDX_CBString(pDX, IDC_COMBO_SEED, m_SEED);
	DDX_Check(pDX, IDC_CHECK__GZ, m_ch_GZ);
	DDX_Check(pDX, IDC_CHECK__X, m_ch_x);
	DDX_Text(pDX, IDC_GZ, m_GZ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Theta_SCMD, CDialog)
	//{{AFX_MSG_MAP(Theta_SCMD)
	ON_BN_CLICKED(ID_INFO, OnInfo)
	ON_BN_CLICKED(ID_LOG, OnLog)
	ON_BN_CLICKED(IDC_CHECK__GZ, OnCheckGz)
	ON_BN_CLICKED(IDC_CHECK__X, OnCheckX)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL Theta_SCMD::OnInitDialog() {CDialog::OnInitDialog(); return 1; }



void Theta_SCMD::OnCheckX() 
{
	UpdateData(1); 
	
	m_X_ctr.SetReadOnly(!m_ch_x); 

	UpdateData(0);
	
	if(m_ch_x==0) Theta_SCMD::OnCheckGz();
	
}	

void Theta_SCMD::OnCheckGz() 
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
	
void Theta_SCMD::OnInfo() {system("start Theta_S.exe");}

void Theta_SCMD::OnLog() {system("start Theta_S_log.txt");}


void Theta_SCMD::OnOK() 
{
    UpdateData(1);

	itoa(m_QQ,QQ_S,10);
	itoa(m_QP,QP,  10);
	itoa(m_QS,QS,  10);

    UpdateData(0);

		          arg_S+="Start ";
		          arg_S+=m_CMD;  arg_S+=" ";
		          arg_S+=m_SEED; arg_S+=" ";
		          arg_S+=m_MIN;  arg_S+=" ";
		          arg_S+=m_MAX;  arg_S+=" ";
		          arg_S+=QQ_S;   arg_S+=" ";
		          arg_S+=QP;     arg_S+=" ";
				  arg_S+=QS;     arg_S+=" ";
		          arg_S+=m_V;    arg_S+=" ";
		          arg_S+=m_M;    arg_S+=" ";
				  arg_S+=m_S;    arg_S+=" ";
    if(m_ch_x== 1)arg_S+=m_X;    arg_S+=" ";
	if(m_ch_GZ==1)arg_S+="1";    
	
    system(       arg_S );

	              arg_S="";
}
