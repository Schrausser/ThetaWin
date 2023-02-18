
#include "stdafx.h"
#include "TW.h"
#include "TWDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int i_sw= -1;

class CAboutDlg : public CDialog
{
	public:
	CAboutDlg();

	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CTWDlg::CTWDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTWDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTWDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTWDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTWDlg, CDialog)
	//{{AFX_MSG_MAP(CTWDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CTWDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu*  zgr = GetSystemMenu(0);
	if (    zgr != 0)
	{
		CString obj;
		        obj.LoadString(IDS_ABOUTBOX);
		if (   !obj.IsEmpty())
		{
			zgr->AppendMenu(MF_SEPARATOR);
			zgr->AppendMenu(MF_STRING, IDM_ABOUTBOX, obj);
		}
	}

	SetIcon(m_hIcon, 1);SetIcon(m_hIcon, 0);	return 1;				
}

void CTWDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg obj;
		          obj.DoModal();
	}
	else{CDialog::OnSysCommand(nID, lParam);}	
}


void CTWDlg::OnPaint() {CDialog::OnPaint();}

HCURSOR CTWDlg::OnQueryDragIcon(){	return (HCURSOR) m_hIcon;}

int CTWDlg::Info_sw(){i_sw ++; return i_sw;}

