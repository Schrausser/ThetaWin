#if !defined(AFX_THETA_RQCMD_H__0935113A_4B54_4A47_A1C3_C9384D3587A2__INCLUDED_)
#define AFX_THETA_RQCMD_H__0935113A_4B54_4A47_A1C3_C9384D3587A2__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 


class Theta_rQCMD : public CDialog
{
	public:
	Theta_rQCMD(CWnd* pParent = NULL);   

	//{{AFX_DATA(Theta_rQCMD)
	enum { IDD = IDD_THETA_rQ_CMD };
	CEdit	m_X_ctr;
	BOOL	m_ch_GZ;
	BOOL	m_ch_x;
	CString	m_CMD;
	CString	m_MAX;
	CString	m_MIN;
	int		m_QP;
	int		m_QQ;
	int		m_QQQ;
	int		m_QR1;
	int		m_QR2;
	int		m_QS11;
	int		m_QS12;
	int		m_QS21;
	int		m_QS22;
	CString	m_SEED;
	CString	m_GZ;
	CString	m_M;
	CString	m_N;
	CString	m_S;
	CString	m_V;
	CString	m_X;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(Theta_rQCMD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(Theta_rQCMD)
	afx_msg void OnInfo();
	afx_msg void OnLog();
	afx_msg void OnCheckGz();
	afx_msg void OnCheckX();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
