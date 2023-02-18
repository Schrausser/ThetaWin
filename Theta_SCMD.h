#if !defined(AFX_THETA_SCMD_H__DDE2F567_B94E_4A86_803E_3B17FE8AD8E8__INCLUDED_)
#define AFX_THETA_SCMD_H__DDE2F567_B94E_4A86_803E_3B17FE8AD8E8__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class Theta_SCMD : public CDialog
{
	public:
	Theta_SCMD(CWnd* pParent = NULL);  

	//{{AFX_DATA(Theta_SCMD)
	enum { IDD = IDD_THETA_S_CMD };
	CEdit	m_X_ctr;
	CString	m_CMD;
	CString	m_M;
	CString	m_S;
	CString	m_V;
	CString	m_X;
	int		m_QS;
	int		m_QQ;
	int		m_QP;
	CString	m_MAX;
	CString	m_MIN;
	CString	m_SEED;
	BOOL	m_ch_GZ;
	BOOL	m_ch_x;
	CString	m_GZ;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(Theta_SCMD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);   
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(Theta_SCMD)
	virtual BOOL OnInitDialog();
	afx_msg void OnInfo();
	virtual void OnOK();
	afx_msg void OnLog();
	afx_msg void OnCheckGz();
	afx_msg void OnCheckX();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
