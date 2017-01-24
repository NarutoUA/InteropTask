#pragma once
#include <vector>
#include <commctrl.h>

#pragma comment(lib, "ComCtl32.Lib")

#import "msado15.dll" rename_namespace("ADODB") rename("EOF", "EndOfFile") no_implementation

class CPatientList
{
private:
	enum EConst
	{
		MAX_NAME_LEN = 32,
		MAX_BUF_LEN = 64,
		LV_COLUMN_COUNT = 3,
		INVALID_ID = -1,
	};

	struct SPatientInfo
	{
		int id;
		wchar_t szFirstName[MAX_NAME_LEN];
		wchar_t szLastName[MAX_NAME_LEN];
	};

	struct SPatientDetails
	{
		int id;
		int iSkinId;
		wchar_t szSkinModel[MAX_BUF_LEN];
		wchar_t szSkinType[MAX_BUF_LEN];
		wchar_t szLocation[MAX_BUF_LEN];
		wchar_t szGender[MAX_NAME_LEN];
		wchar_t szPicPath[MAX_PATH];

		SPatientDetails()
		{
			id = EConst::INVALID_ID;
		}
	};

	static HRESULT CALLBACK MainDlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static HWND CreateListView(HWND hWndParent, UINT uId);
	static int SetListViewColumns(HWND hWndLV, int colNum, int textMaxLen, wchar_t** header);
	static BOOL WINAPI AddListViewRow(HWND hWndLV, SPatientInfo &rPatient);
	static BOOL ReceivePatientList(const wchar_t* szConnectionString);
	static SPatientDetails ReceivePatientDetails(const wchar_t* szConnectionString, const wchar_t* szPatientId);
	static void OnDialogInit(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static void OnListDoubleClick(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	static std::vector<SPatientInfo> s_vecPatients;
	static std::wstring s_strConnectionString;
	const static std::string s_strAppTitle;

	typedef void(__stdcall *SHOWDETAILSPROC)(const int, const int, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*);

	static SHOWDETAILSPROC s_pfShowDetails;

public:
	static void Initialize(const wchar_t* szConnectionString);
};
