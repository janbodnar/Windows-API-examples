#include <windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
               PWSTR szCmdLine, int CmdShow) {
               
    MessageBoxW(NULL, szCmdLine, L"Title", MB_OK);

    return 0;
}
