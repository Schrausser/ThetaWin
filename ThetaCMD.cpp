
#include "stdafx.h"
#include "TW.h"
#include "ThetaCMD.h"
#include <process.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString arg;

char Q[10], QQ[10];

ThetaCMD::ThetaCMD(CWnd* pParent )
	: CDialog(ThetaCMD::IDD, pParent)
{
	//{{AFX_DATA_INIT(ThetaCMD)
	m_CMD = "Theta";
	m_SEED = "0";
	m_MAX = "160";
	m_MIN = "40";
	m_QQ = 1;
	m_Q = 1;
	m_V = "5";
	m_X = "";
	m_S = "30000";
	m_ch_x = 0;
	m_GZ = "";
	m_ch_GZ = 0;
	//}}AFX_DATA_INIT
}


void ThetaCMD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ThetaCMD)
	DDX_Control(pDX, IDC_X, m_X_ctr);
	DDX_Text(pDX, IDC_CMD, m_CMD);
	DDX_CBString(pDX, IDC_COMBO_SEED, m_SEED);
	DDX_CBString(pDX, IDC_COMBO_Max, m_MAX);
	DDX_CBString(pDX, IDC_COMBO_Min, m_MIN);
	DDX_CBIndex(pDX, IDC_COMBO_QQ, m_QQ);
	DDX_CBIndex(pDX, IDC_COMBO_Q, m_Q);
	DDX_Text(pDX, IDC_V, m_V);
	DDX_Text(pDX, IDC_X, m_X);
	DDX_Text(pDX, IDC_S, m_S);
	DDX_Check(pDX, IDC_CHECK__X, m_ch_x);
	DDX_Text(pDX, IDC_GZ, m_GZ);
	DDX_Check(pDX, IDC_CHECK__GZ, m_ch_GZ);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ThetaCMD, CDialog)
	//{{AFX_MSG_MAP(ThetaCMD)
	ON_BN_CLICKED(ID_INFO, OnInfo)
	ON_BN_CLICKED(IDC_CHECK__X, OnCheckX)
	ON_BN_CLICKED(IDC_CHECK__GZ, OnCheckGz)
	ON_BN_CLICKED(ID_LOG, OnLog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL ThetaCMD::OnInitDialog() 
{
	CDialog::OnInitDialog();

	return 1; 
}

void ThetaCMD::OnCheckX() 
{
	UpdateData(1); 
	
	m_X_ctr.SetReadOnly(!m_ch_x); // ! invertierung von status check

	UpdateData(0);
	
	if(m_ch_x==0) ThetaCMD::OnCheckGz();
}

void ThetaCMD::OnCheckGz() 
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


void ThetaCMD::OnInfo(){ system("start Theta.exe");}

void ThetaCMD::OnLog() {system("start Theta_log.txt");}
	
void ThetaCMD::OnOK() 
{	
    UpdateData(1);

	itoa(m_QQ,QQ,10);
	itoa(m_Q,Q,10);

    UpdateData(0);

		          arg+="Start ";
		          arg+=m_CMD;  arg+=" ";
		          arg+=m_SEED; arg+=" ";
		          arg+=m_MIN;  arg+=" ";
		          arg+=m_MAX;  arg+=" ";
		          arg+=QQ;     arg+=" ";
		          arg+=Q;      arg+=" ";
		          arg+=m_V;    arg+=" ";
		          arg+=m_S;    arg+=" ";
    if(m_ch_x== 1)arg+=m_X;    arg+=" ";
	if(m_ch_GZ==1)arg+="1";    
	
    system(       arg );

	              arg="";
}
