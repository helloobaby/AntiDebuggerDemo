#include"head.h"
class Exceptions
{
public:
	void start();
	static LONG vectoredExceptionHandler(_EXCEPTION_POINTERS* ExceptionInfo);
};