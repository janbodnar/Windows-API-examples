#include <windows.h>
#include <wchar.h>

#define BUFSIZE MAX_PATH

int wmain(int argc, wchar_t **argv) {

    wchar_t buf[BUFSIZE];
    
    if(argc != 2) {

      wprintf(L"Usage: %ls <dir>\n", argv[0]);
      return 1;
    }

    DWORD dwRet = SetCurrentDirectoryW(argv[1]);

    if (dwRet == 0) {

      wprintf(L"SetCurrentDirectoryW() failed (%ld)\n", GetLastError());
      return 1;
    }

    dwRet = GetCurrentDirectoryW(BUFSIZE, buf);

    if (dwRet == 0) {

      wprintf(L"GetCurrentDirectoryW() failed (%ld)\n", GetLastError());
      return 1;
    }

    if (dwRet > BUFSIZE) {

      wprintf(L"Buffer too small; needs %d characters\n", dwRet);
      return 1;
    }

    wprintf(L"Current directory is: %ls\n", buf);

    return 0;
}
