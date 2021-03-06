#include "Thread.h"

static DWORD CALLBACK ThreadProc (LPVOID pf) {
Proc* f = (Proc*)pf;
(*f)();
delete f;
return 0;
}

void Thread::init (Proc* f) {
handle = CreateThread(NULL, 0, ThreadProc, (LPVOID)f, 0, NULL);
}

bool Thread::join (DWORD time) {
return WaitForSingleObject(handle, time) == WAIT_OBJECT_0;
}
