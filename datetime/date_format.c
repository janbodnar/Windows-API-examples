#include <windows.h>
#include <wchar.h>

int wmain(void) {

    PDWORD cChars = NULL;
    HANDLE std = GetStdHandle(STD_OUTPUT_HANDLE);   
    
    if (std == INVALID_HANDLE_VALUE) {
        wprintf(L"Cannot retrieve standard output handle %d\n", 
            GetLastError());
        return 1;
    }
 
    SYSTEMTIME lt = {0};
    GetLocalTime(&lt);
     
    wchar_t buf[128] = {0};
     
    int r = GetDateFormatEx(LOCALE_NAME_USER_DEFAULT, DATE_LONGDATE, 
                &lt, NULL, buf, sizeof(buf)/sizeof(buf[0]), NULL);

    if (r == 0) {
    
        wprintf(L"GetDateFormatEx function failed %d\n", 
            GetLastError());
            
        CloseHandle(std);
        
        return 1;
    }

    WriteConsoleW(std, buf, wcslen(buf), cChars, NULL);
    
    r = CloseHandle(std);

    if (r == 0) {
    
        wprintf(L"Cannot close console handle %d\n", 
            GetLastError());
        return 1;    
    }
    
    CloseHandle(std);

    return 0;
}
