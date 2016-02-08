#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK PanelProc(HWND, UINT, WPARAM, LPARAM);

void RegisterRedPanelClass(void);
void RegisterBluePanelClass(void);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {
    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Windows";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);
  
    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Windows",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 250, 180, 0, 0, hInstance, 0);  

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

            RegisterRedPanelClass();

            CreateWindowW(L"RedPanelClass", NULL, 
                          WS_CHILD | WS_VISIBLE,
                          20, 20, 80, 80,
                          hwnd, (HMENU) 1, NULL, NULL);

            RegisterBluePanelClass();

            CreateWindowW(L"BluePanelClass", NULL, 
                          WS_CHILD | WS_VISIBLE,
                          120, 20, 80, 80,
                          hwnd, (HMENU) 2, NULL, NULL);
            break;

        case WM_DESTROY:
    
            PostQuitMessage(0);
            return 0; 
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK PanelProc(HWND hwnd, UINT msg, 
    WPARAM wParam, LPARAM lParam) {
    
    switch(msg) {
  
        case WM_LBUTTONUP:
    
            MessageBeep(MB_OK);
            break;    
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void RegisterRedPanelClass(void) {

    HBRUSH hbrush = CreateSolidBrush(RGB(255, 0, 0));

    WNDCLASSW rwc = {0};
    
    rwc.lpszClassName = L"RedPanelClass";
    rwc.hbrBackground = hbrush;
    rwc.lpfnWndProc   = PanelProc;
    rwc.hCursor       = LoadCursor(0, IDC_ARROW);
    RegisterClassW(&rwc); 
}

void RegisterBluePanelClass(void) {

    HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 255));

    WNDCLASSW rwc = {0};
    
    rwc.lpszClassName = L"BluePanelClass";
    rwc.hbrBackground = hbrush;
    rwc.lpfnWndProc   = PanelProc;
    rwc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&rwc);
}
