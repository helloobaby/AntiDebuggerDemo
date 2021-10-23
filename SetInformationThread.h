#include"head.h"
class SetInformationThread
{
public:
    SetInformationThread()
    {
        HMODULE h = GetModuleHandleW(L"ntdll.dll");
        pfnNtSetInformationThread = (ULONG_PTR)GetProcAddress(h, "NtSetInformationThread");
        if (!pfnNtSetInformationThread)
            throw std::runtime_error("pfnNtSetInformationThread º¯ÊýÎ´ÕÒµ½");
    }
    typedef enum _THREADINFOCLASS {
        ThreadBasicInformation,
        ThreadTimes,
        ThreadPriority,
        ThreadBasePriority,
        ThreadAffinityMask,
        ThreadImpersonationToken,
        ThreadDescriptorTableEntry,
        ThreadEnableAlignmentFaultFixup,
        ThreadEventPair_Reusable,
        ThreadQuerySetWin32StartAddress,
        ThreadZeroTlsCell,
        ThreadPerformanceCount,
        ThreadAmILastThread,
        ThreadIdealProcessor,
        ThreadPriorityBoost,
        ThreadSetTlsArrayAddress,
        ThreadIsIoPending,
        ThreadHideFromDebugger,
        ThreadBreakOnTermination,
        MaxThreadInfoClass
    } THREADINFOCLASS;
    typedef NTSTATUS(WINAPI* NtSetInformationThreadPtr)(
        HANDLE threadHandle,
        THREADINFOCLASS threadInformationClass,
        PVOID threadInformation,
        ULONG threadInformationLength
        );
    ULONG_PTR pfnNtSetInformationThread;
    bool AntiDebug()
    {
        NtSetInformationThreadPtr p = (NtSetInformationThreadPtr)pfnNtSetInformationThread;
        NTSTATUS status = p(
            (HANDLE)-2,
            THREADINFOCLASS::ThreadHideFromDebugger,
            NULL,
            0);
        return status >= 0;
    }
    void start()
    {
        AntiDebug();
    }
};