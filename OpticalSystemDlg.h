// OpticalSystemDlg.h : header file
//

#if !defined(AFX_OPTICALSYSTEMDLG_H__D6587ED5_5263_4892_84C0_075F23BBCAB2__INCLUDED_)
#define AFX_OPTICALSYSTEMDLG_H__D6587ED5_5263_4892_84C0_075F23BBCAB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COpticalSystemDlg dialog

class COpticalSystemDlg : public CDialog
{
// Construction
public:
	COpticalSystemDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COpticalSystemDlg)
	enum { IDD = IDD_OPTICALSYSTEM_DIALOG };
	CButton	m_infiniteObjectDistanceCheck;
	BOOL	m_infiniteObjectDistance;
	CEdit	m_fieldAngleEdit;
	double	m_fieldAngle;
	CSpinButtonCtrl	m_fieldAngleSpin;
	CEdit	m_objectDistanceEdit;
	double	m_objectDistance;
	CSpinButtonCtrl	m_objectDistanceSpin;
	CEdit	m_objectHeightEdit;
	double	m_objectHeight;
	CSpinButtonCtrl	m_objectHeightSpin;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpticalSystemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COpticalSystemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnInfiniteObjectDistanceCheckClicked();
	afx_msg void OnComputeButtonClicked();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTICALSYSTEMDLG_H__D6587ED5_5263_4892_84C0_075F23BBCAB2__INCLUDED_)
