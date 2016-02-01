#include <windows.h>
#include <wchar.h>

int wmain(void) {

    FILETIME ft1 = {0};
    FILETIME ft2 = {0};
    SYSTEMTIME st = {0};  
    LARGE_INTEGER li1 = {0};    
    LARGE_INTEGER li2 = {0}; 

    st.wYear = 2016;
    st.wMonth = 12;
    st.wDay = 25;
 
    int r = SystemTimeToFileTime(&st, &ft1);

    if (r == 0) {

        wprintf(L"Failed to convert system time to file time\n (%d)", 
            GetLastError());
        return 1;
    }
  
    GetSystemTimeAsFileTime(&ft2);
   
    li1.LowPart = ft1.dwLowDateTime;
    li1.HighPart = ft1.dwHighDateTime;
 
    li2.LowPart = ft2.dwLowDateTime;
    li2.HighPart = ft2.dwHighDateTime;

    long long int dif = li1.QuadPart - li2.QuadPart;

    int days2xmas = dif / 10000000L / 60 / 60 / 24;

    if (days2xmas == 1) {

        wprintf(L"There is one day until Christmas\n", days2xmas);
    } else if (days2xmas == 0) {

        wprintf(L"Today is Chritmas\n");
    } else {

        wprintf(L"There are %d days until Christmas\n", days2xmas);
    }
  
    return 0;
}
