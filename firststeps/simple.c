#include <windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                    PWSTR pCmdLine, int CmdShow) {
                    
    MessageBoxW(NULL, L"First Program", L"First", MB_OK);

    return 0;
}
