
#include "stdafx.h"
#include "TW.h"
#include "TWDlg.h"
#include "TWInfo.h"
#include "ThetaCMD.h"
#include "Theta_SCMD.h"
#include "Theta_QCMD.h"
#include "Theta_QvCMD.h"
#include "Theta_rQCMD.h"
#include "doc_rQ.h"
#include "doc_Q.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CTWApp, CWinApp)
	//{{AFX_MSG_MAP(CTWApp)
	ON_COMMAND(ID_PROGRAMM_BEENDEN, OnProgrammBeenden)
	ON_COMMAND(ID_VERTEILUNGSFORM_THETA, OnVerteilungsformTheta)
	ON_COMMAND(ID_PROGRAMM_INFO, OnProgrammInfo)
	ON_COMMAND(ID_VERTEILUNGSFORM_THETAS, OnVerteilungsformThetas)
	ON_COMMAND(ID_VERTEILUNGSFORM_THETAQ, OnVerteilungsformThetaq)
	ON_COMMAND(ID_VERTEILUNGSFORM_THETAQV, OnVerteilungsformThetaqv)
	ON_COMMAND(ID_VERTEILUNGSFORM_THETARQ, OnVerteilungsformThetarq)
	ON_COMMAND(ID_DOKUMENTATION_THETARQ, OnDokumentationThetarq)
	ON_COMMAND(ID_DOKUMENTATION_THETAQ, OnDokumentationThetaq)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()


CTWApp::CTWApp(){}
CTWApp theApp;


BOOL CTWApp::InitInstance()
{

	#ifdef _AFXDLL
	Enable3dControls();			
	#else
	Enable3dControlsStatic();	
	#endif
	
	CTWApp::OnProgrammInfo();
	  
	
	         CTWDlg obj;
	  m_pMainWnd = &obj;
	     int var =  obj.DoModal();

	if      (var == IDOK){}
	else if (var == IDCANCEL){}

	
	return 0;
}



void CTWApp::OnVerteilungsformTheta()  { ThetaCMD    obj;
												     obj.DoModal();}
	      
void CTWApp::OnVerteilungsformThetas() { Theta_SCMD  obj;
												     obj.DoModal();}
	
void CTWApp::OnVerteilungsformThetaq() { Theta_QCMD  obj;
												     obj.DoModal();}
	
void CTWApp::OnVerteilungsformThetaqv(){ Theta_QvCMD obj;
												     obj.DoModal();}

void CTWApp::OnVerteilungsformThetarq(){ Theta_rQCMD obj;
												     obj.DoModal();}

void CTWApp::OnDokumentationThetaq() { doc_Q         obj;
												     obj.DoModal();}


void CTWApp::OnDokumentationThetarq(){ doc_rQ        obj;
												     obj.DoModal();}


void CTWApp::OnProgrammInfo()          { TWInfo      obj;
										             obj.DoModal();}



	        
void CTWApp::OnProgrammBeenden() {	OnSysCommand(SC_CLOSE, 0);}	
	
void CTWApp::OnSysCommand(UINT nID, LPARAM lParam)
{
	if(nID==SC_CLOSE)
	{
		CTWDlg obj;
			   obj.DestroyWindow();
	}
		
	OnSysCommand(nID, lParam);	
}












 



