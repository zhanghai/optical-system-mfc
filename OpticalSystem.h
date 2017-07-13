// OpticalSystem.h : main header file for the OPTICALSYSTEM application
//

#if !defined(AFX_OPTICALSYSTEM_H__2764BF14_CF89_455E_9FC8_B0F7743F4568__INCLUDED_)
#define AFX_OPTICALSYSTEM_H__2764BF14_CF89_455E_9FC8_B0F7743F4568__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COpticalSystemApp:
// See OpticalSystem.cpp for the implementation of this class
//

class COpticalSystemApp : public CWinApp
{
public:
	COpticalSystemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpticalSystemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COpticalSystemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTICALSYSTEM_H__2764BF14_CF89_455E_9FC8_B0F7743F4568__INCLUDED_)
