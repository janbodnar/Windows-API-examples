#include <windows.h>
#include <wchar.h>

#define STR_EQUAL 0

int wmain(void) {

    wchar_t str1[] = L"There are 15 pines";

    wprintf(L"The length of the string is %lld characters\n", wcslen(str1));

    wchar_t buf[20];
    wcscpy(buf, L"Wuthering");
    wcscat(buf, L" heights\n");
    wprintf(buf);

    if (wcscmp(L"rain", L"rainy")== STR_EQUAL) {

        wprintf(L"rain and rainy are equal strings\n");
    } else {

        wprintf(L"rain and rainy are not equal strings\n");
    } 

    return 0;
}
