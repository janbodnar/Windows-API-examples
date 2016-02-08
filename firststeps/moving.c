#include <windows.h>
#include <wchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CreateLabels(HWND);

HWND hwndSta1;
HWND hwndSta2;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                    PWSTR pCmdLine, int CmdShow) {
    HWND hwnd;
    MSG  msg;

    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Moving";
    wc.hInstance     = hInstance ;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);
  
    RegisterClassW(&wc);
    hwnd = CreateWindowW(wc.lpszClassName, L"Moving",
                         WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                         150, 150, 250, 180, 0, 0, hInstance, 0);

    while(GetMessage(&msg, NULL, 0, 0)) {
    
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
    WPARAM wParam, LPARAM lParam) {

    wchar_t buf[10];
    RECT rect;

    switch(msg) {
    
      case WM_CREATE:
      
        CreateLabels(hwnd);
        break;

      case WM_MOVE:
      
        GetWindowRect(hwnd, &rect);

        StringCbPrintfW(buf, BUF_LEN, L"%ld", rect.left);  
        SetWindowTextW(hwndSta1, buf);

        StringCbPrintfW(buf, BUF_LEN, L"%ld", rect.top);  
        SetWindowTextW(hwndSta2, buf);

        break;

      case WM_DESTROY:
      
        PostQuitMessage(0);
        break; 
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void CreateLabels(HWND hwnd) {

    CreateWindowW(L"static", L"x: ",
        WS_CHILD | WS_VISIBLE,
        10, 10, 25, 25, 
        hwnd, (HMENU) 1, NULL, NULL);

    hwndSta1 = CreateWindowW(L"static", L"150",
        WS_CHILD | WS_VISIBLE,
        40, 10, 55, 25, 
       hwnd, (HMENU) 2, NULL, NULL);

    CreateWindowW(L"static", L"y: ",
        WS_CHILD | WS_VISIBLE,
        10, 30, 25, 25, 
        hwnd, (HMENU) 3, NULL, NULL);

    hwndSta2 = CreateWindowW(L"static", L"150",
        WS_CHILD | WS_VISIBLE,
        40, 30, 55, 25, 
        hwnd, (HMENU) 4, NULL, NULL);
}
