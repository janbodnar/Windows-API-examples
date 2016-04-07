#include <windows.h>
#include <wchar.h>

int wmain(void) {

    SYSTEMTIME st = {0};
  
    GetSystemTime(&st);
  
    wprintf(L"The UTC time is: %02d:%02d:%02d\n", 
        st.wHour, st.wMinute, st.wSecond);

    return 0;
}
