// InteropDetailMfcCpp.h : main header file for the InteropDetailMfcCpp DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CInteropDetailMfcCppApp
// See InteropDetailMfcCpp.cpp for the implementation of this class
//

class CInteropDetailMfcCppApp : public CWinApp
{
public:
	CInteropDetailMfcCppApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
