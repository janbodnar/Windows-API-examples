#include <windows.h>
#include <wchar.h>

#define STR_EQUAL 0

int wmain(void) {

    wchar_t *s1 = L"Strong";
    wchar_t *s2 = L"strong";
  
    if (lstrcmpW(s1, s2) == STR_EQUAL) {
  
        wprintf(L"%ls and %ls are equal\n", s1, s2);
    } else {
  
        wprintf(L"%ls and %ls are not equal\n", s1, s2);
    }

    wprintf(L"When applying case insensitive comparison:\n");
    
    if (lstrcmpiW(s1, s2) == STR_EQUAL) {
  
        wprintf(L"%ls and %ls are equal\n", s1, s2);
    } else {
  
        wprintf(L"%ls and %ls are not equal\n", s1, s2);
    }

    return 0;
}
