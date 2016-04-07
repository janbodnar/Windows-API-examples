#include <windows.h>
#include <strsafe.h>
#include <wchar.h>

int wmain(void) { 

    wchar_t str[] = L"ZetCode";
    size_t target_size = 0;

    size_t size = sizeof(str);

    HRESULT r = StringCbLengthW(str, size, &target_size);
    
    if (SUCCEEDED(r)) {

        wprintf(L"The string has %lld bytes\n", target_size);
    } else {

        wprintf(L"StringCbLengthW() failed\n"); 
        return 1;
    }

    size = sizeof(str)/sizeof(wchar_t);

    r = StringCchLengthW(str, size, &target_size);
    
    if (SUCCEEDED(r)) {

        wprintf(L"The string has %lld characters\n", target_size);
    } else {

        wprintf(L"StringCchLengthW() failed\n"); 
        return 1;
    }

    return 0;
}
