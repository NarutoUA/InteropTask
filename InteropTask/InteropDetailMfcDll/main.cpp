// InteropDetailMfcDll.cpp : Defines the initialization routines for the DLL.
//
#include "main.h"
#include "DetailsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CInteropDetailMfcDllApp

BEGIN_MESSAGE_MAP(CInteropDetailMfcDllApp, CWinApp)
END_MESSAGE_MAP()

CInteropDetailMfcDllApp theApp;
CInteropDetailMfcDllApp::CInteropDetailMfcDllApp() {};
BOOL CInteropDetailMfcDllApp::InitInstance()
{
	CWinApp::InitInstance();
	return TRUE;
}

void __stdcall ShowForm(const int iPatientId, int iSkinId, const char* szSkinModel, const char* szSkinType, const char* szLocation, const char* szGender, const char* szPicPath)
{
	HINSTANCE hOldInstance = AfxGetResourceHandle();
	AfxSetResourceHandle(LoadLibrary("InteropResourceDll.dll"));

	CDetailsDlg dlg;
	dlg.Initialize(iPatientId, iSkinId, szSkinModel, szSkinType, szLocation, szGender, szPicPath);
	dlg.DoModal();

	AfxSetResourceHandle(hOldInstance);
}