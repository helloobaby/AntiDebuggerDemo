#include"head.h"
class window
{
public:
	void start();
	static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lparam);
};