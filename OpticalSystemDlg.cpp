// OpticalSystemDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpticalSystem.h"
#include "OpticalSystemDlg.h"

#include "core.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpticalSystemDlg dialog

COpticalSystemDlg::COpticalSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COpticalSystemDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COpticalSystemDlg)
	m_infiniteObjectDistance = FALSE;
	m_fieldAngle = 0.0;
	m_objectDistance = 0.0;
	m_objectHeight = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpticalSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COpticalSystemDlg)
	DDX_Control(pDX, IDC_INFINITE_OBJECT_DISTANCE_CHECK, m_infiniteObjectDistanceCheck);
	DDX_Check(pDX, IDC_INFINITE_OBJECT_DISTANCE_CHECK, m_infiniteObjectDistance);
	DDX_Control(pDX, IDC_FIELD_ANGLE_EDIT, m_fieldAngleEdit);
	DDX_Text(pDX, IDC_FIELD_ANGLE_EDIT, m_fieldAngle);
	DDX_Control(pDX, IDC_FIELD_ANGLE_SPIN, m_fieldAngleSpin);
	DDX_Control(pDX, IDC_OBJECT_DISTANCE_EDIT, m_objectDistanceEdit);
	DDX_Text(pDX, IDC_OBJECT_DISTANCE_EDIT, m_objectDistance);
	DDX_Control(pDX, IDC_OBJECT_DISTANCE_SPIN, m_objectDistanceSpin);
	DDX_Control(pDX, IDC_OBJECT_HEIGHT_EDIT, m_objectHeightEdit);
	DDX_Text(pDX, IDC_OBJECT_HEIGHT_EDIT, m_objectHeight);
	DDX_Control(pDX, IDC_OBJECT_HEIGHT_SPIN, m_objectHeightSpin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COpticalSystemDlg, CDialog)
	//{{AFX_MSG_MAP(COpticalSystemDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_INFINITE_OBJECT_DISTANCE_CHECK, OnInfiniteObjectDistanceCheckClicked)
	ON_BN_CLICKED(IDC_COMPUTE_BUTTON, OnComputeButtonClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpticalSystemDlg message handlers

BOOL COpticalSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// Add extra initialization here
	m_fieldAngleSpin.SetRange32(INT_MIN, INT_MAX);
	m_objectDistanceSpin.SetRange32(INT_MIN, INT_MAX);
	m_objectHeightSpin.SetRange32(INT_MIN, INT_MAX);
	OnInfiniteObjectDistanceCheckClicked();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COpticalSystemDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COpticalSystemDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COpticalSystemDlg::OnInfiniteObjectDistanceCheckClicked() 
{
	UpdateData(TRUE);
	m_fieldAngleEdit.EnableWindow(m_infiniteObjectDistance);
	m_objectDistanceEdit.EnableWindow(!m_infiniteObjectDistance);
	m_objectHeightEdit.EnableWindow(!m_infiniteObjectDistance);
}

void COpticalSystemDlg::OnComputeButtonClicked() 
{
	if (!UpdateData(TRUE)) {
		return;
	}
    char *error = core(m_infiniteObjectDistance ? 1 : 0, m_fieldAngle, m_objectDistance, m_objectHeight);
    if (error == NULL) {
        AfxMessageBox(_T("����ɹ�"), MB_ICONINFORMATION | MB_OK);
    } else {
        AfxMessageBox(error, MB_ICONERROR | MB_OK);
    }
}
