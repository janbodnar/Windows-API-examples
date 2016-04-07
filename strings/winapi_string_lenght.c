#include <windows.h>
#include <wchar.h>

int wmain(void)  {

    char *name = "Jane";
    wchar_t *town = L"Bratislava";

    wprintf(L"The length of the name string is %d\n", lstrlenA(name));
    wprintf(L"The town string length is %d\n", lstrlenW(town));

    return 0;
}
