#include <windows.h>
#include <wchar.h>

int wmain(void) {

    MEMORYSTATUSEX mem;

    mem.dwLength = sizeof(mem);

    int r = GlobalMemoryStatusEx(&mem);

    if (r == 0) {
        wprintf(L"Failed to memory status %ld", GetLastError());
        return 1;
    }

    wprintf(L"Memory in use: %ld percent\n", mem.dwMemoryLoad);
    wprintf(L"Total physical memory: %lld\n", mem.ullTotalPhys);
    wprintf(L"Free physical memory: %lld\n", mem.ullAvailPhys);
    wprintf(L"Total virtual memory: %lld\n", mem.ullTotalVirtual);
    wprintf(L"Free virtual memory: %lld\n", mem.ullAvailVirtual);
    
    return 0;
}
