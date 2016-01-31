#include <windows.h>
#include <wchar.h>
#include <VersionHelpers.h>

int wmain(void) {

    //if (IsWindows10OrGreater()) {
        
    //    wprintf(L"This is Windows 10+");
    // }
    if (IsWindows8Point1OrGreater()) {
        wprintf(L"This is Windows 8.1+\n");
    } else if (IsWindows8OrGreater()) {
        wprintf(L"This is Windows 8\n");
    } else if (IsWindows7OrGreater ()) {
        wprintf(L"This is Windows 7\n");
    } else if (IsWindowsVistaOrGreater ()) {
        wprintf(L"This is Windows Vista\n");
    } else if (IsWindowsXPOrGreater()) {
        wprintf(L"This is Windows XP\n");
    }

    return 0;
}
