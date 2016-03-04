#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#define ID_BEEP 1
#define ID_QUIT 2

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {

    MSG  msg;
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Buttons";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Buttons",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  150, 150, 300, 200, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {
    
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
    WPARAM wParam, LPARAM lParam) {
    
    switch(msg) {

        case WM_CREATE:

            CreateWindowW(L"Button", L"Beep",
                WS_VISIBLE | WS_CHILD ,
                20, 50, 80, 25, hwnd, (HMENU) ID_BEEP, NULL, NULL);

            CreateWindowW(L"Button", L"Quit",
                WS_VISIBLE | WS_CHILD ,
                120, 50, 80, 25, hwnd, (HMENU) ID_QUIT, NULL, NULL);
            break;

        case WM_COMMAND:

            if (LOWORD(wParam) == ID_BEEP) {
            
                MessageBeep(MB_OK);
            }

            if (LOWORD(wParam) == ID_QUIT) {
            
                PostQuitMessage(0);
            }

            break;

        case WM_DESTROY:

            PostQuitMessage(0);
            break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
