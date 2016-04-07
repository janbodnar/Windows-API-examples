#include <windows.h>
#include <wchar.h>

#define BUF_LEN 25

int wmain(void) {

    wchar_t str1[] = L"There are 15 pines";

    const int MAX_CHARS = 50;
    size_t count = wcsnlen_s(str1, MAX_CHARS); 

    wprintf(L"The length of the string is %ld characters\n", count);

    wchar_t buf[BUF_LEN] = {0};

    int r = wcscpy_s(buf, BUF_LEN, L"Wuthering");

    if (r != 0) {

        wprintf(L"wcscpy_s() failed %ld", r);
    }

    r = wcscat_s(buf, BUF_LEN, L" heights\n");

    if (r != 0) {

        wcscat_s(L"wcscat_s() failed %ld", r);
    }

    wprintf_s(buf);

    return 0;
}
