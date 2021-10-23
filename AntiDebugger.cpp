#include"head.h"
#include"SelfDebugger.h"
#include"SetInformationThread.h"
#include"window.h"
#include"ObjectHandle.h"
#include"Exceptions.h"
#include"Timing.h"
#include"Memory.h"
#include"DebugFlags.h"

#define FirstStart L"FirstStart"
HANDLE FirstStartEvent;
bool a_exit;
bool isDebugged;
SelfDebugging method1;
SetInformationThread method2;
window method3;
ObjectHandle method4;
Exceptions method5;
Timing method6;
Memory method7;
DebugFlag method8;

int main(int argc,char** argv)
{
    FirstStartEvent = CreateEventW(NULL, FALSE, FALSE, FirstStart);
    if (GetLastError() == ERROR_ALREADY_EXISTS)
        a_exit = true;
    method1.start(argc, argv);
    if (a_exit)
        return 0;
    method2.start();
    method3.start();
    method4.start();
    method5.start();
    method6.start();
    method7.start();
    method8.start();



    if (isDebugged)
        MessageBoxW(NULL, L"发现调试器", L"警告", MB_APPLMODAL);
    else
    {
        std::cout << "古德！" << std::endl;
        getchar();
    }
    return 0;
}

