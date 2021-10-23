#include "Exceptions.h"
#include"head.h"
bool isDebugging = true;
extern bool isDebugged;
void Exceptions::start()
{
	AddVectoredExceptionHandler((ULONG)1,(PVECTORED_EXCEPTION_HANDLER)vectoredExceptionHandler);
	DebugBreak();
	if (isDebugging)
		isDebugged = true;
}

LONG Exceptions::vectoredExceptionHandler(_EXCEPTION_POINTERS* ExceptionInfo)
{
	isDebugging = false;
	ExceptionInfo->ContextRecord->Eip++;
	return -1;
}

