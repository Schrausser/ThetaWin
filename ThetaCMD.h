#if !defined(AFX_THETACMD_H__A8DF3FD5_E6AE_4468_8D33_A79176FE13C5__INCLUDED_)
#define AFX_THETACMD_H__A8DF3FD5_E6AE_4468_8D33_A79176FE13C5__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class ThetaCMD : public CDialog
{
	public:
	ThetaCMD(CWnd* pParent = NULL);   

	//{{AFX_DATA(ThetaCMD)
	enum { IDD = IDD_THETA_CMD };
	CEdit	m_X_ctr;
	CString	m_CMD;
	CString	m_SEED;
	CString	m_MAX;
	CString	m_MIN;
	int		m_QQ;
	int		m_Q;
	CString	m_V;
	CString	m_X;
	CString	m_S;
	BOOL	m_ch_x;
	CString	m_GZ;
	BOOL	m_ch_GZ;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(ThetaCMD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL


	protected:
	//{{AFX_MSG(ThetaCMD)
	virtual void OnOK();
	afx_msg void OnInfo();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckX();
	afx_msg void OnCheckGz();
	afx_msg void OnLog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
