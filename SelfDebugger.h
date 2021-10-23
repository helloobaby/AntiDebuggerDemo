#include"head.h"
#define EVENT_SELFDBG_EVENT_NAME L"SelfDebugging"
#define FirstStart L"FirstStart"
class SelfDebugging
{
public:
	bool EnableDebugPrivilege();
	bool IsDebugged();
	void start(int argc, char** argv);
};