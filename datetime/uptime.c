#include <windows.h>
#include <wchar.h>

int wmain(void) {  

    DWORD tc = GetTickCount();

    short seconds = tc / 1000 % 60; 
    short minutes = tc / 1000 / 60 % 60; 
    short hours = tc / 1000 / 60 / 60 % 24; 
    short days = tc / 1000 / 60 / 60 / 24 % 7;  
    short weeks = tc / 1000 / 60 / 60 / 24 / 7 % 52; 

    wprintf(L"Computer has been running for: ");
                    
    if (weeks > 0 && weeks != 1) {

        wprintf(L"%hi weeks ", weeks);
    } else if (weeks == 1) {

        wprintf(L"1 week ");
    }

    if (days > 0 && days != 1) {

        wprintf(L"%hi days ", days);
    } else if (days == 1) {

        wprintf(L"1 day ");
    }

    if (hours > 0 && hours != 1) {

        wprintf(L"%hi hours ", hours);
    } else if (hours == 1) {

        wprintf(L"1 hour ");
    }

    if (minutes > 0 && minutes != 1) {

        wprintf(L"%hi minutes ", minutes); 
    } else if (minutes == 1) {

        wprintf(L"1 minute ");
    }

    wprintf(L"and %hi seconds\n", seconds);

    return 0;
}
