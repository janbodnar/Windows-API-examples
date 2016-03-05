#include <windows.h>
#include <commctrl.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CreateControls(HWND hwnd);
void UpdateLabel(void);

HWND hTrack;
HWND hlbl;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
  PWSTR lpCmdLine, int nCmdShow) {
  
    HWND hwnd;
    MSG  msg ;

    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Trackbar";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0,IDC_ARROW);
  
    RegisterClassW(&wc);
    hwnd = CreateWindowW(wc.lpszClassName, L"Trackbar", 
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 350, 180, 0, 0, hInstance, 0);
  
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
       CreateControls(hwnd);
       break;

     case WM_HSCROLL:
       UpdateLabel();
       break;

     case WM_DESTROY:
       PostQuitMessage(0);
       break; 
  }

  return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void CreateControls(HWND hwnd) {

    HWND hLeftLabel = CreateWindowW(L"Static", L"0", 
        WS_CHILD | WS_VISIBLE, 0, 0, 10, 30, hwnd, (HMENU)1, NULL, NULL);

    HWND hRightLabel = CreateWindowW(L"Static", L"100", 
        WS_CHILD | WS_VISIBLE, 0, 0, 30, 30, hwnd, (HMENU)2, NULL, NULL);

    hlbl = CreateWindowW(L"Static", L"0", WS_CHILD | WS_VISIBLE, 
        270, 20, 30, 30, hwnd, (HMENU)3, NULL, NULL);

    INITCOMMONCONTROLSEX icex;

    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC  = ICC_LISTVIEW_CLASSES;
    InitCommonControlsEx(&icex); 

    hTrack = CreateWindowW(TRACKBAR_CLASSW, L"",
        WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS,
        20, 20, 170, 30, hwnd, (HMENU) 3, NULL, NULL);

    SendMessageW(hTrack, TBM_SETRANGE,  TRUE, MAKELONG(0, 100)); 
    SendMessageW(hTrack, TBM_SETPAGESIZE, 0,  10); 
    SendMessageW(hTrack, TBM_SETTICFREQ, 10, 0); 
    SendMessageW(hTrack, TBM_SETPOS, FALSE, 0); 
    SendMessageW(hTrack, TBM_SETBUDDY, TRUE, (LPARAM) hLeftLabel); 
    SendMessageW(hTrack, TBM_SETBUDDY, FALSE, (LPARAM) hRightLabel); 
}

void UpdateLabel(void) {

    LRESULT pos = SendMessageW(hTrack, TBM_GETPOS, 0, 0);
    wchar_t buf[4];
    wsprintfW(buf, L"%ld", pos);

    SetWindowTextW(hlbl, buf);
}
