#include "main.h"
#include "DetailsDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CDetailsDlg, CDialog)

CDetailsDlg::CDetailsDlg(CWnd* pWnd /*= NULL*/)
	: CDialog(IDD_DLG_DETAILS, pWnd)
{
	m_pImage = NULL;
}

CDetailsDlg::~CDetailsDlg()
{
	if (m_pImage != NULL)
	{
		DeleteObject(m_pImage);
		m_pImage = NULL;
	}
}

BOOL CDetailsDlg::OnInitDialog()
{
	BOOL bResult = CDialog::OnInitDialog();

	CStatic *m_pImage = (CStatic*)this->GetDlgItem(IDC_IMAGE);
	m_pImage->SetBitmap((HBITMAP)::LoadImageA(NULL, m_szPicPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));

	CEdit *pEditBox = (CEdit*)this->GetDlgItem(IDC_EDIT_SKINID);
	char szSkinId[16];
	_itoa_s(m_iSkinId, szSkinId, 10);
	pEditBox->SetWindowTextA(szSkinId);
	pEditBox = (CEdit*)this->GetDlgItem(IDC_EDIT_SKINMODEL);
	pEditBox->SetWindowTextA(m_szSkinModel);
	pEditBox = (CEdit*)this->GetDlgItem(IDC_EDIT_SKINTYPE);
	pEditBox->SetWindowTextA(m_szSkinType);
	pEditBox = (CEdit*)this->GetDlgItem(IDC_EDIT_LOCATION);
	pEditBox->SetWindowTextA(m_szLocation);
	pEditBox = (CEdit*)this->GetDlgItem(IDC_EDIT_GENDER);
	pEditBox->SetWindowTextA(m_szGender);
	return bResult;
}

void CDetailsDlg::Initialize(const int iPatientId, const int iSkinId, const char* szSkinModel, const char* szSkinType, const char* szLocation, const char* szGender, const char* szPicPath)
{
	m_iPatientId = iPatientId;
	m_iSkinId = iSkinId;
	m_szSkinModel = szSkinModel;
	m_szSkinType = szSkinType;
	m_szLocation = szLocation;
	m_szGender = szGender;
	m_szPicPath = szPicPath;
}

BEGIN_MESSAGE_MAP(CDetailsDlg, CDialog)
END_MESSAGE_MAP()
