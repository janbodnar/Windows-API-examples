#include <windows.h>
#include <strsafe.h>
#include <wchar.h>

#define BUF_LEN 256

int wmain(void) { 

    wchar_t buf[BUF_LEN] = {0};      

    HRESULT r = StringCchCatW(buf, BUF_LEN, L"Hello "); 
        
    if (FAILED(r)) {

        wprintf(L"StringCchCatW() failed\n"); 
        return 1;
    }

    r = StringCchCatW(buf, BUF_LEN, L"there"); 
    
    if (FAILED(r)) {

        wprintf(L"StringCchCatW() failed\n"); 
        return 1;
    }

    wprintf(L"%ls\n", buf);

    return 0;
}
