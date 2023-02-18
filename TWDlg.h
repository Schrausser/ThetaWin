
#if !defined(AFX_TWDLG_H__B1250C0A_E6B6_4EE7_BC41_63D2CD8619CB__INCLUDED_)
#define AFX_TWDLG_H__B1250C0A_E6B6_4EE7_BC41_63D2CD8619CB__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 


class CTWDlg : public CDialog
{

	public:
	CTWDlg(CWnd* pParent = NULL);	

	int Info_sw();

	//{{AFX_DATA(CTWDlg)
	enum { IDD = IDD_TW_DIALOG };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CTWDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

	protected:
	HICON m_hIcon;

	//{{AFX_MSG(CTWDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif
