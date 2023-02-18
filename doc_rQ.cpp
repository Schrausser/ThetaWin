// doc_rQ.cpp : implementation file
//

#include "stdafx.h"
#include "TW.h"
#include "doc_rQ.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// doc_rQ dialog


doc_rQ::doc_rQ(CWnd* pParent /*=NULL*/)
	: CDialog(doc_rQ::IDD, pParent)
{
	//{{AFX_DATA_INIT(doc_rQ)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void doc_rQ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(doc_rQ)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(doc_rQ, CDialog)
	//{{AFX_MSG_MAP(doc_rQ)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// doc_rQ message handlers
