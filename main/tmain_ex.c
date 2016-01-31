#define _UNICODE
#define UNICODE

#include <windows.h>
#include <tchar.h>

int _tmain(int argc, TCHAR *argv[]) {

    PDWORD cChars = NULL;
    HANDLE std = GetStdHandle(STD_OUTPUT_HANDLE);

    if (std == INVALID_HANDLE_VALUE) {
        _tprintf(L"Cannot retrieve standard output handle\n (%d)", 
            GetLastError());
    }  
        
    WriteConsole(std, argv[1], _tcslen(argv[1]), cChars, NULL);

    return EXIT_SUCCESS;
}
