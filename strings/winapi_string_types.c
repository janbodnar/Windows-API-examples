#include <windows.h>
#include <wchar.h>
#include <stdbool.h>

int wmain(void) {

    wchar_t str[] = L"7 white, 3 red roses.\n";

    int alphas = 0;
    int digits = 0;
    int spaces = 0;
    int puncts = 0;
    int contrs = 0;

    int size = lstrlenW(str);
    WORD types[size];
    ZeroMemory(types, size);

    bool rv = GetStringTypeW(CT_CTYPE1, str, size, types);

    if (!rv) {
    
        wprintf(L"Could not get character types (%ld)", GetLastError());
        return EXIT_FAILURE;
    }

    for (int i=0; i<size; i++) {

        if (types[i] & C1_ALPHA) {
        
            alphas++;
        }

        if (types[i] & C1_DIGIT) {
        
            digits++;
        }

        if (types[i] & C1_SPACE) {
        
            spaces++;
        }

        if (types[i] & C1_PUNCT) {
        
            puncts++;
        }

        if (types[i] & C1_CNTRL) {
        
            contrs++;
        }
    }

    wprintf(L"There are %ld letter(s), %ld digit(s), "
        L"%ld space(s), %ld punctuation character(s), "
        L"and %ld control character(s)\n", alphas, digits, 
        spaces, puncts, contrs);  

    return 0;
}
