#include <windows.h>
#include <wchar.h>

int wmain(void) { 

    SYSTEMTIME lt = {0};
    GetLocalTime(&lt);

    TIME_ZONE_INFORMATION tzi = {0};
    GetTimeZoneInformation(&tzi);

    SYSTEMTIME utm = {0};

    int r = TzSpecificLocalTimeToSystemTime(&tzi, &lt, &utm);
    
    if (r == 0) {

        wprintf(L"Failed to convert local time to system time %d\n)", 
            GetLastError());
        return 1;
    }

    wprintf(L"Date: %d/%d/%d\n", lt.wMonth, lt.wDay, lt.wYear);

    wprintf(L"The local time is: %02d:%02d:%02d\n", 
        lt.wHour, lt.wMinute, lt.wSecond);

    wprintf(L"The universal time is: %02d:%02d:%02d\n", 
        utm.wHour, utm.wMinute, utm.wSecond);

    return 0;
}
