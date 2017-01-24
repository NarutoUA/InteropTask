#pragma once
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

extern "C" __declspec(dllexport) void __stdcall ShowForm(const int iPatientId, const int iSkinId, const wchar_t* szSkinModel, const wchar_t* szSkinType, const wchar_t* szLocation, const wchar_t* szGender, const wchar_t* szPicPath)
{
	InteropDetailCliDll::MainForm ^ objForm = gcnew InteropDetailCliDll::MainForm();

	objForm->lblSkinIdA->Text = Convert::ToString(iSkinId);
	objForm->lblSkinModelA->Text = gcnew String(szSkinModel);
	objForm->lblSkinTypeA->Text = gcnew String(szSkinType);
	objForm->lblLocationA->Text = gcnew String(szLocation);
	objForm->lblGenderA->Text = gcnew String(szGender);
	objForm->picSkin->Load(gcnew String(szPicPath));

	objForm->Show();
}