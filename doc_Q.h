#if !defined(AFX_DOC_Q_H__70861077_4EF9_4F3E_AD80_E3A9ACCD8C64__INCLUDED_)
#define AFX_DOC_Q_H__70861077_4EF9_4F3E_AD80_E3A9ACCD8C64__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// doc_Q.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// doc_Q dialog

class doc_Q : public CDialog
{
// Construction
public:
	doc_Q(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(doc_Q)
	enum { IDD = IDD_DOC_Q };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(doc_Q)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(doc_Q)
	afx_msg void OnDokumentationThetaq();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOC_Q_H__70861077_4EF9_4F3E_AD80_E3A9ACCD8C64__INCLUDED_)
