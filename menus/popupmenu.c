#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

#define IDM_FILE_NEW 1
#define IDM_FILE_OPEN 2
#define IDM_FILE_QUIT 3


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {
    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Popup menu";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Popup menu",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 350, 250, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {
    
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {
    
    HMENU hMenu;
    POINT point;

    switch(msg) {
  
      case WM_COMMAND:
    
          switch(LOWORD(wParam)) {
        
              case IDM_FILE_NEW:
              case IDM_FILE_OPEN:
            
                  MessageBeep(MB_ICONINFORMATION);
                  break;
                
              case IDM_FILE_QUIT:
            
                  SendMessage(hwnd, WM_CLOSE, 0, 0);
                  break;
          }
        
          break;

      case WM_RBUTTONUP:
     
          point.x = LOWORD(lParam);
          point.y = HIWORD(lParam);
        
          hMenu = CreatePopupMenu();
          ClientToScreen(hwnd, &point);

          AppendMenuW(hMenu, MF_STRING, IDM_FILE_NEW, L"&New");
          AppendMenuW(hMenu, MF_STRING, IDM_FILE_OPEN, L"&Open");
          AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
          AppendMenuW(hMenu, MF_STRING, IDM_FILE_QUIT, L"&Quit");
                    
          TrackPopupMenu(hMenu, TPM_RIGHTBUTTON, point.x, point.y, 0, hwnd, NULL);
          DestroyMenu(hMenu);
          break;

      case WM_DESTROY:
     
          PostQuitMessage(0);
          break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
