; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=ThetaCMD
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TW.h"

ClassCount=11
Class1=CTWApp
Class2=CTWDlg
Class3=CAboutDlg

ResourceCount=24
Resource1=IDD_THETA_Qv_CMD
Resource2=IDR_MAINFRAME
Resource3=IDD_DOC_Q
Resource4=IDD_ABOUTBOX (COPY)
Class4=ThetaCMD
Resource5=IDR_MENU
Resource6=IDD_THETA_Q_CMD
Class5=TWInfo
Resource7=IDD_DOC_rQ
Class6=Theta_SCMD
Resource8=IDD_INFO
Class7=Theta_QCMD
Resource9=IDD_ABOUTBOX
Class8=Theta_QvCMD
Resource10=IDD_THETA_CMD
Class9=Theta_rQCMD
Resource11=IDD_THETA_S_CMD
Class10=doc_rQ
Resource12=IDD_THETA_rQ_CMD
Class11=doc_Q
Resource13=IDD_TW_DIALOG
Resource14=IDD_THETA_Q_CMD (German (Germany))
Resource15=IDD_THETA_CMD (German (Germany))
Resource16=IDD_ABOUTBOX (German (Germany))
Resource17=IDD_TW_DIALOG (German (Germany))
Resource18=IDD_INFO (German (Germany))
Resource19=IDD_THETA_S_CMD (German (Germany))
Resource20=IDD_THETA_Qv_CMD (German (Germany))
Resource21=IDD_THETA_rQ_CMD (German (Germany))
Resource22=IDD_DOC_rQ (German (Germany))
Resource23=IDD_DOC_Q (German (Germany))
Resource24=IDR_MENU (German (Germany))

[CLS:CTWApp]
Type=0
HeaderFile=TW.h
ImplementationFile=TW.cpp
Filter=N
LastObject=ID_DOKUMENTATION_THETAQ
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CTWDlg]
Type=0
HeaderFile=TWDlg.h
ImplementationFile=TWDlg.cpp
Filter=D
LastObject=CTWDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=TWDlg.h
ImplementationFile=TWDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_TW_DIALOG]
Type=1
Class=CTWDlg
ControlCount=1
Control1=IDCANCEL,button,1073807360

[MNU:IDR_MENU]
Type=1
Class=?
Command1=ID_PROGRAMM_INFO
Command2=ID_PROGRAMM_BEENDEN
Command3=ID_VERTEILUNGSFORM_THETA
Command4=ID_VERTEILUNGSFORM_THETAS
Command5=ID_VERTEILUNGSFORM_THETAQ
Command6=ID_VERTEILUNGSFORM_THETAQV
Command7=ID_VERTEILUNGSFORM_THETARQ
Command8=ID_DOKUMENTATION_THETARQ
Command9=ID_DOKUMENTATION_THETAQ
CommandCount=9

[DLG:IDD_THETA_CMD]
Type=1
Class=ThetaCMD
ControlCount=23
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342243072
Control3=IDC_COMBO_Q,combobox,1344274435
Control4=IDC_V,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280

[CLS:ThetaCMD]
Type=0
HeaderFile=ThetaCMD.h
ImplementationFile=ThetaCMD.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CHECK__X
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX (COPY)]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342374145

[DLG:IDD_INFO]
Type=1
Class=TWInfo
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_TIME,edit,1342179456
Control7=IDC_DATE,edit,1342179456

[CLS:TWInfo]
Type=0
HeaderFile=TWInfo.h
ImplementationFile=TWInfo.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_DATE

[DLG:IDD_THETA_S_CMD]
Type=1
Class=Theta_SCMD
ControlCount=27
Control1=IDCANCEL,button,1342243072
Control2=IDOK,button,1342242817
Control3=IDC_COMBO_QP,combobox,1344274435
Control4=IDC_M,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280
Control24=IDC_V,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_COMBO_QS,combobox,1344274435
Control27=IDC_STATIC,static,1342308352

[CLS:Theta_SCMD]
Type=0
HeaderFile=Theta_SCMD.h
ImplementationFile=Theta_SCMD.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_INFO

[DLG:IDD_THETA_Q_CMD]
Type=1
Class=Theta_QCMD
ControlCount=33
Control1=IDCANCEL,button,1342243072
Control2=IDOK,button,1342242817
Control3=IDC_COMBO_QP,combobox,1344274435
Control4=IDC_M,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280
Control24=IDC_V,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_COMBO_QS1,combobox,1344274435
Control27=IDC_STATIC,static,1342308352
Control28=IDC_COMBO_QS2,combobox,1344274435
Control29=IDC_STATIC,static,1342308352
Control30=IDC_N,edit,1350631552
Control31=IDC_STATIC,static,1342308352
Control32=IDC_COMBO_Q,combobox,1344274435
Control33=IDC_STATIC,static,1342308352

[CLS:Theta_QCMD]
Type=0
HeaderFile=Theta_QCMD.h
ImplementationFile=Theta_QCMD.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_INFO
VirtualFilter=dWC

[DLG:IDD_THETA_Qv_CMD]
Type=1
Class=Theta_QvCMD
ControlCount=33
Control1=IDCANCEL,button,1342243072
Control2=IDOK,button,1342242817
Control3=IDC_COMBO_QP,combobox,1344274435
Control4=IDC_N,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280
Control24=IDC_V,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_COMBO_QS1,combobox,1344274435
Control27=IDC_STATIC,static,1342308352
Control28=IDC_COMBO_QS2,combobox,1344274435
Control29=IDC_STATIC,static,1342308352
Control30=IDC_COMBO_Q,combobox,1344274435
Control31=IDC_STATIC,static,1342308352
Control32=IDC_COMBO_QQQ,combobox,1344274435
Control33=IDC_STATIC,static,1342308352

[CLS:Theta_QvCMD]
Type=0
HeaderFile=Theta_QvCMD.h
ImplementationFile=Theta_QvCMD.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_INFO
VirtualFilter=dWC

[CLS:Theta_rQCMD]
Type=0
HeaderFile=Theta_rQCMD.h
ImplementationFile=Theta_rQCMD.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_INFO
VirtualFilter=dWC

[DLG:IDD_THETA_rQ_CMD]
Type=1
Class=Theta_rQCMD
ControlCount=41
Control1=IDCANCEL,button,1342243072
Control2=IDOK,button,1342242817
Control3=IDC_COMBO_QP,combobox,1344274435
Control4=IDC_M,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280
Control24=IDC_V,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_COMBO_QS11,combobox,1344274435
Control27=IDC_STATIC,static,1342308352
Control28=IDC_COMBO_QS12,combobox,1344274435
Control29=IDC_STATIC,static,1342308352
Control30=IDC_COMBO_QR1,combobox,1344274435
Control31=IDC_STATIC,static,1342308352
Control32=IDC_COMBO_QQQ,combobox,1344274435
Control33=IDC_STATIC,static,1342308352
Control34=IDC_COMBO_QS21,combobox,1344274435
Control35=IDC_STATIC,static,1342308352
Control36=IDC_COMBO_QS22,combobox,1344274435
Control37=IDC_STATIC,static,1342308352
Control38=IDC_N,edit,1350631552
Control39=IDC_STATIC,static,1342308352
Control40=IDC_COMBO_QR2,combobox,1344274435
Control41=IDC_STATIC,static,1342308352

[DLG:IDD_DOC_rQ]
Type=1
Class=doc_rQ
ControlCount=2
Control1=IDC_STATIC,static,1342177294
Control2=IDCANCEL,button,1342177536

[CLS:doc_rQ]
Type=0
HeaderFile=doc_rQ.h
ImplementationFile=doc_rQ.cpp
BaseClass=CDialog
Filter=D
LastObject=IDCANCEL

[DLG:IDD_DOC_Q]
Type=1
Class=doc_Q
ControlCount=2
Control1=IDC_STATIC,static,1342177294
Control2=IDCANCEL,button,1342243072

[CLS:doc_Q]
Type=0
HeaderFile=doc_Q.h
ImplementationFile=doc_Q.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_DOKUMENTATION_THETAQ
VirtualFilter=dWC

[DLG:IDD_THETA_Q_CMD (German (Germany))]
Type=1
ControlCount=33
Control1=IDCANCEL,button,1342243072
Control2=IDOK,button,1342242817
Control3=IDC_COMBO_QP,combobox,1344274435
Control4=IDC_M,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280
Control24=IDC_V,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_COMBO_QS1,combobox,1344274435
Control27=IDC_STATIC,static,1342308352
Control28=IDC_COMBO_QS2,combobox,1344274435
Control29=IDC_STATIC,static,1342308352
Control30=IDC_N,edit,1350631552
Control31=IDC_STATIC,static,1342308352
Control32=IDC_COMBO_Q,combobox,1344274435
Control33=IDC_STATIC,static,1342308352

[DLG:IDD_THETA_CMD (German (Germany))]
Type=1
ControlCount=23
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342243072
Control3=IDC_COMBO_Q,combobox,1344274435
Control4=IDC_V,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280

[DLG:IDD_ABOUTBOX (German (Germany))]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342374145

[DLG:IDD_TW_DIALOG (German (Germany))]
Type=1
ControlCount=1
Control1=IDCANCEL,button,1073807360

[DLG:IDD_INFO (German (Germany))]
Type=1
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_TIME,edit,1342179456
Control7=IDC_DATE,edit,1342179456

[DLG:IDD_THETA_S_CMD (German (Germany))]
Type=1
ControlCount=27
Control1=IDCANCEL,button,1342243072
Control2=IDOK,button,1342242817
Control3=IDC_COMBO_QP,combobox,1344274435
Control4=IDC_M,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280
Control24=IDC_V,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_COMBO_QS,combobox,1344274435
Control27=IDC_STATIC,static,1342308352

[DLG:IDD_THETA_Qv_CMD (German (Germany))]
Type=1
ControlCount=33
Control1=IDCANCEL,button,1342243072
Control2=IDOK,button,1342242817
Control3=IDC_COMBO_QP,combobox,1344274435
Control4=IDC_N,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280
Control24=IDC_V,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_COMBO_QS1,combobox,1344274435
Control27=IDC_STATIC,static,1342308352
Control28=IDC_COMBO_QS2,combobox,1344274435
Control29=IDC_STATIC,static,1342308352
Control30=IDC_COMBO_Q,combobox,1344274435
Control31=IDC_STATIC,static,1342308352
Control32=IDC_COMBO_QQQ,combobox,1344274435
Control33=IDC_STATIC,static,1342308352

[DLG:IDD_THETA_rQ_CMD (German (Germany))]
Type=1
ControlCount=41
Control1=IDCANCEL,button,1342243072
Control2=IDOK,button,1342242817
Control3=IDC_COMBO_QP,combobox,1344274435
Control4=IDC_M,edit,1350631552
Control5=IDC_S,edit,1350631552
Control6=IDC_X,edit,1350633600
Control7=IDC_CHECK__GZ,button,1342247171
Control8=IDC_CHECK__X,button,1342247171
Control9=IDC_GZ,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_COMBO_QQ,combobox,1344274435
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_Max,combobox,1344339970
Control19=IDC_COMBO_Min,combobox,1344339970
Control20=IDC_CMD,edit,1350633600
Control21=IDC_COMBO_SEED,combobox,1344274434
Control22=ID_INFO,button,1342177280
Control23=ID_LOG,button,1342177280
Control24=IDC_V,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_COMBO_QS11,combobox,1344274435
Control27=IDC_STATIC,static,1342308352
Control28=IDC_COMBO_QS12,combobox,1344274435
Control29=IDC_STATIC,static,1342308352
Control30=IDC_COMBO_QR1,combobox,1344274435
Control31=IDC_STATIC,static,1342308352
Control32=IDC_COMBO_QQQ,combobox,1344274435
Control33=IDC_STATIC,static,1342308352
Control34=IDC_COMBO_QS21,combobox,1344274435
Control35=IDC_STATIC,static,1342308352
Control36=IDC_COMBO_QS22,combobox,1344274435
Control37=IDC_STATIC,static,1342308352
Control38=IDC_N,edit,1350631552
Control39=IDC_STATIC,static,1342308352
Control40=IDC_COMBO_QR2,combobox,1344274435
Control41=IDC_STATIC,static,1342308352

[DLG:IDD_DOC_rQ (German (Germany))]
Type=1
ControlCount=2
Control1=IDC_STATIC,static,1342177294
Control2=IDCANCEL,button,1342177536

[DLG:IDD_DOC_Q (German (Germany))]
Type=1
ControlCount=2
Control1=IDC_STATIC,static,1342177294
Control2=IDCANCEL,button,1342243072

[MNU:IDR_MENU (German (Germany))]
Type=1
Command1=ID_PROGRAMM_INFO
Command2=ID_PROGRAMM_BEENDEN
Command3=ID_VERTEILUNGSFORM_THETA
Command4=ID_VERTEILUNGSFORM_THETAS
Command5=ID_VERTEILUNGSFORM_THETAQ
Command6=ID_VERTEILUNGSFORM_THETAQV
Command7=ID_VERTEILUNGSFORM_THETARQ
Command8=ID_DOKUMENTATION_THETARQ
Command9=ID_DOKUMENTATION_THETAQ
CommandCount=9

