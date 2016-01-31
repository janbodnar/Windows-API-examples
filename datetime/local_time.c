#include <windows.h>
#include <wchar.h>

int wmain(void) {

    SYSTEMTIME lt = {0};
  
    GetLocalTime(&lt);
  
    wprintf(L"The local time is: %02d:%02d:%02d\n", 
        lt.wHour, lt.wMinute, lt.wSecond);

    return 0;
}
