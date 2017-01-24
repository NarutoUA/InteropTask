// Connect.h : Declaration of the CConnect

#pragma once
#include <windows.h>

#include "resource.h"

#include "InteropCppCom_i.h"
#include "_IConnectEvents_CP.h"

#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

class ATL_NO_VTABLE CConnect :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CConnect, &CLSID_Connect>,
	public IConnectionPointContainerImpl<CConnect>,
	public CProxy_IConnectEvents<CConnect>,
	public IDispatchImpl<IConnect, &IID_IConnect, &LIBID_InteropCppComLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CConnect()
	{
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_CONNECT)

	BEGIN_COM_MAP(CConnect)
		COM_INTERFACE_ENTRY(IConnect)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY(IConnectionPointContainer)
	END_COM_MAP()

	BEGIN_CONNECTION_POINT_MAP(CConnect)
		CONNECTION_POINT_ENTRY(__uuidof(_IConnectEvents))
	END_CONNECTION_POINT_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(Connect)(BSTR szConnectionString);
};

OBJECT_ENTRY_AUTO(__uuidof(Connect), CConnect)
