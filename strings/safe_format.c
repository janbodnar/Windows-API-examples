#include <windows.h>
#include <strsafe.h>
#include <wchar.h>

#define BUF_LEN 256

int wmain(void) { 

    wchar_t *word = L"table";
    int count = 6;

    wchar_t buf[BUF_LEN] = {0}; 
    wchar_t *line = L"There are %d %lss";

    HRESULT r = StringCchPrintfW(buf, ARRAYSIZE(buf), line, count, word);   
        
    if (SUCCEEDED(r)) {

        wprintf(L"%ls\n", buf);

    } else {

        wprintf(L"StringCchPrintfW() failed\n"); 
        return 1;
    }

    return 0;
} 
