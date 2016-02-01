#include <windows.h>
#include <wchar.h>

int wmain(void) {

    SYSTEMTIME st1 = {0};
    SYSTEMTIME st2 = {0};
    FILETIME ft1 = {0};
    FILETIME ft2 = {0};

    st1.wYear = 2015;
    st1.wMonth = 4;
    st1.wDay = 12;

    st2.wYear = 2015;
    st2.wMonth = 5;
    st2.wDay = 12;

    int r1 = SystemTimeToFileTime(&st1, &ft1);

    if (r1 == 0) {

        wprintf(L"Failed to convert system time to file time\n (%d)", 
            GetLastError());
        return 1;
    }
  
    int r2 = SystemTimeToFileTime(&st2, &ft2);

    if (r2 == 0) {

        wprintf(L"Failed to convert system time to file time\n (%d)", 
            GetLastError());
        return 1;
    }
    
    short ct = CompareFileTime(&ft1, &ft2);

    if (ct == -1) {

        wprintf(L"4/12/2015 comes before 5/12/2015\n");
    } else if (ct == 0) {

        wprintf(L"4/12/2015 is equal to 5/12/2015\n");
    } else if (ct == 1) {

        wprintf(L"4/12/2015 comes after 5/12/2015\n");
    }

    return 0;
}
