// dllmain.h : Declaration of module class.

class CInteropCppComModule : public ATL::CAtlDllModuleT< CInteropCppComModule >
{
public:
	DECLARE_LIBID(LIBID_InteropCppComLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_INTEROPCPPCOM, "{93CACDBA-1EDA-4B46-ABEB-2020C72DA47E}")
};

extern class CInteropCppComModule _AtlModule;
extern HINSTANCE g_hInstance;
