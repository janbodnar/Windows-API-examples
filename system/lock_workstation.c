#include <windows.h>
#include <wchar.h>

#pragma comment(lib, "user32.lib")

int wmain(void) { 

    int r = LockWorkStation();

    if( r == 0 ) {
	
        wprintf(L"LockWorkStation() failed %d\n", GetLastError());
        return 1;
    }

    return 0;
}
