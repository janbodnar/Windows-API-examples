#include <windows.h>
#include <wchar.h>

int wmain(void) {

    TIME_ZONE_INFORMATION tzi = {0};
    
    int r = GetTimeZoneInformation(&tzi);

    if (r == TIME_ZONE_ID_INVALID) {

        wprintf(L"Failed to get time zone %d", GetLastError());
        return 1;
    }

    wprintf(L"Time zone: %ls\n", tzi.StandardName);
    wprintf(L"The bias is: %ld minutes\n", tzi.Bias);

    return 0;
}
