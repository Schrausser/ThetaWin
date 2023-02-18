// doc_Q.cpp : implementation file
//

#include "stdafx.h"
#include "TW.h"
#include "doc_Q.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// doc_Q dialog


doc_Q::doc_Q(CWnd* pParent /*=NULL*/)
	: CDialog(doc_Q::IDD, pParent)
{
	//{{AFX_DATA_INIT(doc_Q)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void doc_Q::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(doc_Q)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(doc_Q, CDialog)
	//{{AFX_MSG_MAP(doc_Q)
	ON_COMMAND(ID_DOKUMENTATION_THETAQ, OnDokumentationThetaq)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// doc_Q message handlers

void doc_Q::OnDokumentationThetaq() 
{
	// TODO: Add your command handler code here
	
}
