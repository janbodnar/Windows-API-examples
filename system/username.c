#include <windows.h>
#include <Lmcons.h>
#include <wchar.h>

int wmain(void) {

    wchar_t username[UNLEN+1];
    DWORD len = sizeof(username) / sizeof(wchar_t);

    int r = GetUserNameW(username, &len);

    if (r == 0) {
        wprintf(L"Failed to get username %ld", GetLastError());
        return 1;
    }
  
    wprintf(L"User name: %ls\n", username);

    return 0;
}
