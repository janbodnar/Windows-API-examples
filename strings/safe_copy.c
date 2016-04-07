#include <windows.h>
#include <strsafe.h>
#include <wchar.h>

int wmain(void) { 

    wchar_t *sentence = L"Today is a rainy day.";

    size_t size = wcslen(sentence) + 1;

    wchar_t buf[size];
    ZeroMemory(buf, size); 

    HRESULT r = StringCchCopyW(buf, size, sentence);

    if (SUCCEEDED(r)) {

        wprintf(L"%ls\n", buf);

    } else {

        wprintf(L"StringCchCopyW() failed\n"); 
        return 1;
    }

    return 0;
}
