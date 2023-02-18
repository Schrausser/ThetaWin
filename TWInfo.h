#if !defined(AFX_TWINFO_H__5930E568_A1EA_4A96_A635_48726F2C1BB9__INCLUDED_)
#define AFX_TWINFO_H__5930E568_A1EA_4A96_A635_48726F2C1BB9__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

class TWInfo : public CDialog
{
	public:
	TWInfo(CWnd* pParent = NULL);   

	//{{AFX_DATA(TWInfo)
	enum { IDD = IDD_INFO };
	CString	m_date;
	CString	m_time;
	//}}AFX_DATA
	//{{AFX_VIRTUAL(TWInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

	protected:
	//{{AFX_MSG(TWInfo)	
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}


#endif 
