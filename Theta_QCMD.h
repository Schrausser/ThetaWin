#if !defined(AFX_THETA_QCMD_H__9CA38810_46E3_4D35_867E_BF8B0D18DA56__INCLUDED_)
#define AFX_THETA_QCMD_H__9CA38810_46E3_4D35_867E_BF8B0D18DA56__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class Theta_QCMD : public CDialog
{
	public:
	Theta_QCMD(CWnd* pParent = NULL);   

	//{{AFX_DATA(Theta_QCMD)
	enum { IDD = IDD_THETA_Q_CMD };
	CEdit	m_X_ctr;
	int		m_Q;
	int		m_QP;
	int		m_QQ;
	int		m_QS1;
	int		m_QS2;
	CString	m_SEED;
	CString	m_MIN;
	CString	m_MAX;
	CString	m_CMD;
	BOOL	m_ch_GZ;
	CString	m_GZ;
	CString	m_M;
	CString	m_N;
	CString	m_S;
	CString	m_V;
	CString	m_X;
	BOOL	m_ch_x;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(Theta_QCMD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);   
	//}}AFX_VIRTUAL


	protected:
	//{{AFX_MSG(Theta_QCMD)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnInfo();
	afx_msg void OnLog();
	afx_msg void OnCheckGz();
	afx_msg void OnCheckX();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
