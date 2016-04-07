#include <windows.h>
#include <wchar.h>
#include <stdbool.h>
#include "Shlwapi.h"

#pragma comment(lib, "Shlwapi.lib")

int wmain(void) {

    wchar_t buf[] = L"23tennis74";
    wchar_t trim[] = L"0123456789";

    wprintf(L"Original string: %ls\n", buf);

    bool r = StrTrimW(buf, trim);

    if (r == true) {
        
        wprintf(L"The StrTrim() trimmed some characters\n", buf);
    } else {

        wprintf(L"No characters were trimmed\n", buf);
    }

    wprintf(L"Trimmed string: %ls\n", buf);

    return 0;
}
