#include <windows.h>
#include <wchar.h>

int wmain(void) {

    SYSTEMTIME st = {0};
  
    GetLocalTime(&st);
  
    wprintf(L"Today is: %d-%02d-%02d\n", st.wYear, st.wMonth, st.wDay);

    return 0;
}
