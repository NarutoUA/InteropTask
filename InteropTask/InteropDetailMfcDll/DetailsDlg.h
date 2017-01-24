#pragma once
#include <afxbutton.h>

class CDetailsDlg : public CDialog
{
	DECLARE_DYNAMIC(CDetailsDlg)

public:
	CDetailsDlg(CWnd* pWnd = NULL);
	virtual ~CDetailsDlg();

	virtual BOOL OnInitDialog();
	void Initialize(const int iPatientId, const int iSkinId, const char* szSkinModel, const char* szSkinType, const char* szLocation, const char* szGender, const char* szPicPath);

protected:
	DECLARE_MESSAGE_MAP()

private:
	int m_iPatientId;
	int m_iSkinId;
	const char* m_szSkinModel;
	const char* m_szSkinType;
	const char* m_szLocation;
	const char* m_szGender;
	const char* m_szPicPath;
	CStatic* m_pImage;
};
