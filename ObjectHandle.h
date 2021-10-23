#include"head.h"
class ObjectHandle
{
    typedef DWORD(WINAPI* TCsrGetProcessId)(VOID);
public:
	void check1();
	bool check2();
	bool check3();
	void start();
	
};