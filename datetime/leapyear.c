#include <windows.h>
#include <stdbool.h>
#include <wchar.h>

bool isLeapYear(int);

int wmain(void) {

    int years[] = { 2000, 2002, 2004, 2008, 2012, 2016, 2020,
        1900, 1800, 1600, 1200, 1000 };
  
    int size = sizeof(years) / sizeof(int);

    for (int i=0; i<size; i++) {

        if (isLeapYear(years[i])) {

            wprintf(L"%ld is a leap year\n", years[i]);
        } else {

            wprintf(L"%ld is not a leap year\n", years[i]);
        }
    }

    return 0;
}

bool isLeapYear(int year) {

    if ((year % 100 == 0) && (year % 400 == 0)) {
        return true;
    }
 
    if ((year % 4 == 0) && (year % 100 !=0)) {
        return true;
    }

    return false;
}
