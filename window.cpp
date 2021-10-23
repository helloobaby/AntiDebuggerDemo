#include"window.h"
extern bool isDebugged;

void window::start()
{
	EnumWindows(EnumWindowsProc, -1);
}

BOOL window::EnumWindowsProc(HWND hwnd, LPARAM lparam)
{
	std::wcout.imbue(std::locale("chs"));
	WCHAR szName[256] = {};
	GetWindowText(hwnd, szName, 512);
	std::wstring strName(szName);
	/*if (!strName.empty())
		std::wcout << strName << std::endl;*/
	if (strName.find(L"dbg") != std::wstring::npos ||
		strName.find(L"debug") != std::wstring::npos ||
		strName.find(L"ต๗สิ") != std::wstring::npos||
		strName.find(L"DEBUG") != std::wstring::npos||
		strName.find(L"DBG") != std::wstring::npos)
		isDebugged = true;
	return 1;
}
