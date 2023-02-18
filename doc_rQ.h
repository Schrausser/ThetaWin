#if !defined(AFX_DOC_RQ_H__51A8915B_4E23_42BE_BAFB_BBE2E493073D__INCLUDED_)
#define AFX_DOC_RQ_H__51A8915B_4E23_42BE_BAFB_BBE2E493073D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// doc_rQ.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// doc_rQ dialog

class doc_rQ : public CDialog
{
// Construction
public:
	doc_rQ(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(doc_rQ)
	enum { IDD = IDD_DOC_rQ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(doc_rQ)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(doc_rQ)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOC_RQ_H__51A8915B_4E23_42BE_BAFB_BBE2E493073D__INCLUDED_)
