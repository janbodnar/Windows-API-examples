#include <windows.h>
#include <commctrl.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);

#define IDM_VIEW_STB 1

HWND ghSb;
HMENU ghMenu;


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {
                    
    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Check menu item";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Check menu item",
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
    
    UINT state;

    switch(msg) {
    
      case WM_CREATE:
      
          AddMenus(hwnd);          
          InitCommonControls();

          ghSb = CreateWindowExW(0, STATUSCLASSNAMEW, NULL, 
              WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hwnd, 
              (HMENU) 1, GetModuleHandle(NULL), NULL);

          break;

      case WM_COMMAND:
          
          switch(LOWORD(wParam)) {
          
              case IDM_VIEW_STB:                                    
                  
                  state = GetMenuState(ghMenu, IDM_VIEW_STB, MF_BYCOMMAND); 

                  if (state == MF_CHECKED) {
                  
                      ShowWindow(ghSb, SW_HIDE);
                      CheckMenuItem(ghMenu, IDM_VIEW_STB, MF_UNCHECKED);  
                  } else {
                  
                      ShowWindow(ghSb, SW_SHOWNA);
                      CheckMenuItem(ghMenu, IDM_VIEW_STB, MF_CHECKED);  
                  }
                  
                  break;
          }
          
          break;

      case WM_SIZE:
      
          SendMessage(ghSb, WM_SIZE, wParam, lParam);          
          break;

      case WM_DESTROY:
      
          PostQuitMessage(0);
          break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}


void AddMenus(HWND hwnd) {

    HMENU hMenubar;

    hMenubar = CreateMenu();
    ghMenu = CreateMenu();

    AppendMenuW(ghMenu, MF_STRING, IDM_VIEW_STB, L"&Statusbar");
    CheckMenuItem(ghMenu, IDM_VIEW_STB, MF_CHECKED);  

    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) ghMenu, L"&View");
  
    SetMenu(hwnd, hMenubar);
}
