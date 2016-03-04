#include <windows.h>
#include <stdbool.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {
                    
    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Check Box";
    wc.hInstance     = hInstance ;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Check Box",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  150, 150, 230, 150, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {
    
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
    WPARAM wParam, LPARAM lParam) {
    
    bool checked = true;

    switch(msg) {
  
        case WM_CREATE:

            CreateWindowW(L"Button", L"Show Title",
                WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                20, 20, 185, 35, hwnd, (HMENU) 1, 
                NULL, NULL);

            CheckDlgButton(hwnd, 1, BST_CHECKED);
            break;

        case WM_COMMAND:

            checked = IsDlgButtonChecked(hwnd, 1);

            if (checked) {

                CheckDlgButton(hwnd, 1, BST_UNCHECKED);
                SetWindowTextW(hwnd, L"");

            } else {

               CheckDlgButton(hwnd, 1, BST_CHECKED);
               SetWindowTextW(hwnd, L"Check Box");
            }
      
            break;
 
       case WM_DESTROY:

            PostQuitMessage(0);
            break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
