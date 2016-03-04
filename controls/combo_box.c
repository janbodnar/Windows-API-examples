#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE g_hinst;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {

    HWND hwnd;
    MSG  msg ;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Application";
    wc.hInstance     = hInstance ;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc ;
    wc.hCursor       = LoadCursor(0,IDC_ARROW);

    g_hinst = hInstance;
  
    RegisterClassW(&wc);
    hwnd = CreateWindowW(wc.lpszClassName, L"Combo box",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 270, 170, 0, 0, hInstance, 0);  


    while (GetMessage(&msg, NULL, 0, 0)) {
    
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
        WPARAM wParam, LPARAM lParam) {

    static HWND hwndCombo, hwndStatic;
    const wchar_t *items[] = { L"FreeBSD", L"OpenBSD", 
        L"NetBSD", L"Solaris", L"Arch" };

    switch(msg) {
    
        case WM_CREATE:
        
              hwndCombo = CreateWindowW(L"Combobox", NULL, 
                    WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
                    10, 10, 120, 110, hwnd, NULL, g_hinst, NULL);   

              CreateWindowW(L"Button", L"Drop down", 
                    WS_CHILD | WS_VISIBLE,
                    150, 10, 90, 25, hwnd, (HMENU) 1, g_hinst, NULL); 

              hwndStatic = CreateWindowW(L"Static", L"", 
                    WS_CHILD | WS_VISIBLE,
                    150, 80, 90, 25, hwnd, NULL, g_hinst, NULL); 

              for (int i = 0; i < 4; i++ ) {
              
                  SendMessageW(hwndCombo, CB_ADDSTRING, 0, (LPARAM) items[i]);
              }

              break;

        case WM_COMMAND:
        
             if (HIWORD(wParam) == BN_CLICKED) {
             
                  SendMessage(hwndCombo, CB_SHOWDROPDOWN, (WPARAM) TRUE, 0);
             }
             
             if (HIWORD(wParam) == CBN_SELCHANGE) {      
             
                  LRESULT sel = SendMessage(hwndCombo, CB_GETCURSEL, 0, 0);
                  SetWindowTextW(hwndStatic, items[sel]);
             }
             break;

        case WM_DESTROY:
        
            PostQuitMessage(0);
            break; 
    }
  
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
