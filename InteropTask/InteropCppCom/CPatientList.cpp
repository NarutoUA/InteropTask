#include "stdafx.h"
#include "CPatientList.h"

#import "msado15.dll" rename_namespace("ADODB") rename("EOF", "EndOfFile") implementation_only

extern HINSTANCE g_hInstance;

std::vector<CPatientList::SPatientInfo> CPatientList::s_vecPatients;
std::wstring CPatientList::s_strConnectionString;
const std::string CPatientList::s_strAppTitle = "Native Interop GUI";
CPatientList::SHOWDETAILSPROC CPatientList::s_pfShowDetails = NULL;

BOOL CPatientList::ReceivePatientList(const wchar_t* szConnectionString)
{
	BOOL bCoInited = FALSE;

	if (FAILED(CoInitialize(NULL)))
	{
		return FALSE;
	}

	try
	{
		_bstr_t strCnn(szConnectionString);
		ADODB::_RecordsetPtr pPatientList = NULL;

		if (FAILED(pPatientList.CreateInstance(__uuidof(ADODB::Recordset))))
		{
			MessageBoxA(NULL, "Failed creating record set instance", s_strAppTitle.c_str(), MB_OK);
			return FALSE;
		}

		pPatientList->Open("SELECT * FROM tblPatients", strCnn, ADODB::adOpenStatic, ADODB::adLockReadOnly, ADODB::adCmdText);
		pPatientList->MoveFirst();

		if (!pPatientList->EndOfFile)
		{
			while (!pPatientList->EndOfFile)
			{
				SPatientInfo objPatient;
				objPatient.id = pPatientList->Fields->GetItem("id")->Value.intVal;
				wcsncpy_s(objPatient.szFirstName, (wchar_t*)pPatientList->Fields->GetItem("szFirstName")->Value.pcVal, MAX_NAME_LEN);
				wcsncpy_s(objPatient.szLastName, (wchar_t*)pPatientList->Fields->GetItem("szLastName")->Value.pcVal, MAX_NAME_LEN);
				s_vecPatients.emplace_back(objPatient);
				pPatientList->MoveNext();
			}
		}
	}
	catch (_com_error & ce)
	{
		MessageBoxA(NULL, (LPCSTR)ce.Description(), s_strAppTitle.c_str(), MB_OK);
		return FALSE;
	}

	CoUninitialize();
}

CPatientList::SPatientDetails CPatientList::ReceivePatientDetails(const wchar_t* szConnectionString, const wchar_t* szPatientId)
{
	SPatientDetails objDetails;

	if (FAILED(CoInitialize(NULL)))
	{
		return objDetails;
	}

	try
	{
		_bstr_t strCnn(szConnectionString);
		ADODB::_RecordsetPtr pDetails = NULL;

		if (FAILED(pDetails.CreateInstance(__uuidof(ADODB::Recordset))))
		{
			MessageBoxA(NULL, "Failed creating record set instance", "Error", MB_OK);
			return objDetails;
		}

		wchar_t szCmd[MAX_BUF_LEN];
		wsprintf(szCmd, L"SELECT * FROM tblDetails WHERE id = %s", szPatientId);
		pDetails->Open(szCmd, strCnn, ADODB::adOpenStatic, ADODB::adLockReadOnly, ADODB::adCmdText);
		pDetails->MoveFirst();

		if (!pDetails->EndOfFile)
		{
			objDetails.id = pDetails->Fields->GetItem("id")->Value.intVal;
			objDetails.iSkinId = pDetails->Fields->GetItem("iSkinId")->Value.intVal;
			wcsncpy_s(objDetails.szSkinModel, (wchar_t*)pDetails->Fields->GetItem("szSkinModel")->Value.pcVal, MAX_BUF_LEN);
			wcsncpy_s(objDetails.szSkinType, (wchar_t*)pDetails->Fields->GetItem("szSkinType")->Value.pcVal, MAX_BUF_LEN);
			wcsncpy_s(objDetails.szLocation, (wchar_t*)pDetails->Fields->GetItem("szLocation")->Value.pcVal, MAX_BUF_LEN);
			wcsncpy_s(objDetails.szGender, (wchar_t*)pDetails->Fields->GetItem("szGender")->Value.pcVal, MAX_BUF_LEN);
			wcsncpy_s(objDetails.szPicPath, (wchar_t*)pDetails->Fields->GetItem("szPicPath")->Value.pcVal, MAX_PATH);
		}
	}
	catch (_com_error & ce)
	{
		MessageBoxA(NULL, (LPCSTR)ce.Description(), s_strAppTitle.c_str(), MB_OK);
	}

	CoUninitialize();
	return objDetails;
}

void CPatientList::Initialize(const wchar_t* szConnectionString)
{
	s_strConnectionString = szConnectionString;
	INT_PTR nResult = DialogBoxA(g_hInstance, MAKEINTRESOURCEA(IDD_DIALOG1), NULL, (DLGPROC)MainDlgProc);

	if (nResult == 0 || nResult == -1)
	{
		char buf[256];
		sprintf_s(buf, "Unable to create dialog. Error: %d", GetLastError());
		MessageBoxA(NULL, buf, s_strAppTitle.c_str(), MB_OK);
	}
}

LRESULT CALLBACK CPatientList::MainDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		OnDialogInit(hWnd, uMsg, wParam, lParam);
		break;

	case WM_COMMAND:
		if (wParam == IDOK)
		{
			EndDialog(hWnd, IDOK);
		}
		break;

	case WM_NOTIFY:
		OnListDoubleClick(hWnd, uMsg, wParam, lParam);
		break;

	case WM_CLOSE:
		EndDialog(hWnd, IDCANCEL);
		break;

	default:
		return FALSE;
	}
	return TRUE;
}

void CPatientList::OnDialogInit(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hWndLV = NULL;
	wchar_t* pszHeaders[EConst::LV_COLUMN_COUNT] = { L"id", L"FirstName", L"LastName" };

	if ((hWndLV = CreateListView(hWnd, IDC_LISTVIEW)) == NULL)
	{
		MessageBoxA(NULL, "Unable to create ListView", s_strAppTitle.c_str(), MB_OK);
		EndDialog(hWnd, IDCANCEL);
		return;
	}

	if (s_vecPatients.empty() == false)
	{
		s_vecPatients.clear();
	}

	if (ReceivePatientList(s_strConnectionString.c_str()) == FALSE)
	{
		MessageBoxA(NULL, "Unable to do smth", s_strAppTitle.c_str(), MB_OK);
		EndDialog(hWnd, IDCANCEL);
		return;
	}

	SetListViewColumns(hWndLV, EConst::LV_COLUMN_COUNT, EConst::MAX_NAME_LEN, pszHeaders);
	for (auto &it : s_vecPatients)
	{
		AddListViewRow(hWndLV, it);
	}

	ShowWindow(hWndLV, SW_SHOWDEFAULT);
}

void CPatientList::OnListDoubleClick(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LPNMHDR lpnmHdr = (LPNMHDR)lParam;

	if ((lpnmHdr->idFrom == IDC_LISTVIEW) && (lpnmHdr->code == NM_DBLCLK))
	{
		LPNMLISTVIEW pnmLV = (LPNMLISTVIEW)lParam;
		wchar_t szId[EConst::MAX_NAME_LEN];

		ListView_GetItemText(lpnmHdr->hwndFrom, pnmLV->iItem, 0, szId, EConst::MAX_NAME_LEN);

		HMODULE hLib = LoadLibraryA("InteropDetailCliDll.dll");
		if (hLib != NULL)
		{
			s_pfShowDetails = reinterpret_cast<CPatientList::SHOWDETAILSPROC>(GetProcAddress(hLib, "_ShowForm@28"));
			if (s_pfShowDetails != NULL)
			{
				SPatientDetails objDetails = ReceivePatientDetails(s_strConnectionString.c_str(), szId);
				if (objDetails.id != -1)
				{
					s_pfShowDetails(objDetails.id, objDetails.iSkinId, objDetails.szSkinModel, objDetails.szSkinType, objDetails.szLocation, objDetails.szGender, objDetails.szPicPath);
				}
				else
				{
					MessageBoxA(NULL, "Invalid data", s_strAppTitle.c_str(), MB_OK);
				}
			}
		}
	}
}

BOOL WINAPI CPatientList::AddListViewRow(HWND hWndLV, CPatientList::SPatientInfo &rPatient)
{
	int iLastIndex = ListView_GetItemCount(hWndLV);

	LVITEM lvi;
	lvi.mask = LVIF_TEXT;
	lvi.cchTextMax = EConst::MAX_NAME_LEN;
	lvi.iItem = iLastIndex;
	lvi.pszText = rPatient.szFirstName;
	lvi.iSubItem = 0;

	if (ListView_InsertItem(hWndLV, &lvi) == -1)
	{
		return FALSE;
	}

	wchar_t szId[EConst::MAX_NAME_LEN];
	_itow_s(rPatient.id, szId, 10);

	ListView_SetItemText(hWndLV, iLastIndex, 0, szId);
	ListView_SetItemText(hWndLV, iLastIndex, 1, rPatient.szFirstName);
	ListView_SetItemText(hWndLV, iLastIndex, 2, rPatient.szLastName);

	return TRUE;
}

int CPatientList::SetListViewColumns(HWND hWndLV, int colNum, int textMaxLen, wchar_t** header)
{
	RECT rcl;
	GetClientRect(hWndLV, &rcl);

	int index = -1;

	LVCOLUMN lvc;
	lvc.mask = LVCF_TEXT | LVCF_WIDTH;
	lvc.cx = (rcl.right - rcl.left) / colNum;
	lvc.cchTextMax = textMaxLen;

	for (int i = 0; i < colNum; i++)
	{
		lvc.pszText = header[i];
		index = ListView_InsertColumn(hWndLV, i, &lvc);
		if (index == -1) break;
	}

	return index;
}

HWND CPatientList::CreateListView(HWND hWndParent, UINT uId)
{
	INITCOMMONCONTROLSEX icex;
	icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
	icex.dwICC = ICC_LISTVIEW_CLASSES;
	InitCommonControlsEx(&icex);

	RECT rcl;
	GetClientRect(hWndParent, &rcl);

	HWND hWndLV = CreateWindow(WC_LISTVIEW, L"",
		WS_CHILD | LVS_REPORT,
		0, 0, rcl.right - rcl.left, rcl.bottom - rcl.top - 50,
		hWndParent, (HMENU)uId, GetModuleHandle(NULL), NULL);

	ListView_SetExtendedListViewStyleEx(hWndLV, 0, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return (hWndLV);
}