#include <windows.h>
#include <wchar.h>

int wmain(void) {

    unsigned __int64 FreeBytesToCaller,
                     TotalBytes,
                     FreeBytes;

    int r = GetDiskFreeSpaceExW(L"C:\\", (PULARGE_INTEGER) &FreeBytesToCaller,
       (PULARGE_INTEGER) &TotalBytes, (PULARGE_INTEGER) &FreeBytes);

    if (r == 0) {
        wprintf(L"Failed to get free disk space %ld", GetLastError());
        return 1;
    }	

    wprintf(L"Available space to caller: %I64u MB\n", FreeBytesToCaller / (1024*1024));
    wprintf(L"Total space: %I64u MB\n", TotalBytes / (1024*1024));
    wprintf(L"Free space on drive: %I64u MB\n", FreeBytes / (1024*1024));
    
    return 0;
}
