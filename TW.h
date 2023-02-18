#if !defined(AFX_TW_H__BAFB6F96_70D9_42A7_9D5E_D103B052A720__INCLUDED_)
#define AFX_TW_H__BAFB6F96_70D9_42A7_9D5E_D103B052A720__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		

class CTWApp : public CWinApp
{
	public:
	CTWApp();

	//{{AFX_VIRTUAL(CTWApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CTWApp)
	afx_msg void OnProgrammBeenden();
		afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnVerteilungsformTheta();
	afx_msg void OnProgrammInfo();
	afx_msg void OnVerteilungsformThetas();
	afx_msg void OnVerteilungsformThetaq();
	afx_msg void OnVerteilungsformThetaqv();
	afx_msg void OnVerteilungsformThetarq();
	afx_msg void OnDokumentationThetarq();
	afx_msg void OnDokumentationThetaq();
	//}}AFX_MSG
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
