
#include "stdafx.h"
#include "TW.h"
#include "TWInfo.h"
#include "TWDlg.h"
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

TWInfo::TWInfo(CWnd* pParent )
	: CDialog(TWInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(TWInfo)	
	m_date = __DATE__;
	m_time = __TIME__;
	//}}AFX_DATA_INIT
}


void TWInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TWInfo)
	DDX_Text(pDX, IDC_DATE, m_date);
	DDX_Text(pDX, IDC_TIME, m_time);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TWInfo, CDialog)
	//{{AFX_MSG_MAP(TWInfo)	
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL TWInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetTimer(1,1500,0);
	
	return 1;  	              
}

void TWInfo::OnTimer(UINT nIDEvent) 
{
	  CTWDlg ooo;
    //       ooo 
	int vvv= ooo.Info_sw();
	//  vvv
	if( vvv<1) CDialog::OnCancel();
	
	CDialog::OnTimer(nIDEvent);
}



