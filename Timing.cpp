#include "Timing.h"
#include "head.h"
extern bool isDebugged;
void Timing::start()
{
	check1();
    
}

void Timing::check1()
{
    ULARGE_INTEGER Start, End;
    __asm
    {
        xor ecx, ecx
        rdtsc
        mov  Start.LowPart, eax
        mov  Start.HighPart, edx
    }
    // ... some work
    __asm
    {
        xor ecx, ecx
        rdtsc
        mov  End.LowPart, eax
        mov  End.HighPart, edx
    }
    //std::cout << (End.QuadPart - Start.QuadPart) << std::endl;
    if ((End.QuadPart - Start.QuadPart) > 100)
        isDebugged = true;
}
