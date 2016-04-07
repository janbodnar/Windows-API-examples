#include <windows.h>
#include <wchar.h>

int main(void) {

    wchar_t *s1 = L"ZetCode, ";
    wchar_t *s2 = L"tutorials ";
    wchar_t *s3 = L"for ";
    wchar_t *s4 = L"programmers.\n";

    int len = lstrlenW(s1) + lstrlenW(s2) 
        + lstrlenW(s3) + lstrlenW(s4);
    wchar_t buf[len+1];
  
    lstrcpyW(buf, s1);
    lstrcatW(buf, s2);
    lstrcatW(buf, s3);
    lstrcatW(buf, s4);

    wprintf(buf);    

    return 0;
}
