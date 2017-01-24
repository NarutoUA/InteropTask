// Connect.cpp : Implementation of CConnect

#include "stdafx.h"
#include "Connect.h"

// CConnect
#include <string>
using namespace std;

#include "CPatientList.h"

STDMETHODIMP CConnect::Connect(BSTR szConnectionString)
{
	CPatientList::Initialize(szConnectionString);
	return S_OK;
}