#include "Memory.h"
extern bool isDebugged;
void Memory::start()
{
	check1();
}

void Memory::check1()
{
	bool isDebugerExist = false;
	if (IsDebuggerPresent())
		isDebugged = true;
	///*CheckRemoteDebuggerPresent((HANDLE)-1, (PBOOL)&isDebugerExist);
	//if (isDebugerExist)
	//	isDebugged = true;*/
	return;
}
