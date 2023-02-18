#if !defined(AFX_THETA_QVCMD_H__FEBACEEE_E7D4_4606_B492_8F05CB6EC6D8__INCLUDED_)
#define AFX_THETA_QVCMD_H__FEBACEEE_E7D4_4606_B492_8F05CB6EC6D8__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class Theta_QvCMD : public CDialog
{
	public:
	Theta_QvCMD(CWnd* pParent = NULL);		

	//{{AFX_DATA(Theta_QvCMD)
	enum { IDD = IDD_THETA_Qv_CMD };
	CEdit	m_X_ctr;
	BOOL	m_ch_GZ;
	BOOL	m_ch_x;
	CString	m_CMD;
	CString	m_MAX;
	CString	m_MIN;
	int		m_Q;
	int		m_QP;
	int		m_QQ;
	int		m_QS1;
	int		m_QS2;
	CString	m_SEED;
	CString	m_GZ;
	CString	m_N;
	CString	m_V;
	CString	m_S;
	CString	m_X;
	int		m_QQQ;
	//}}AFX_DATA


	//{{AFX_VIRTUAL(Theta_QvCMD)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL


	protected:
	//{{AFX_MSG(Theta_QvCMD)
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
