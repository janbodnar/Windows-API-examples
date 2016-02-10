#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);

#define IDM_FILE_NEW 1
#define IDM_FILE_IMPORT 2

#define IDM_IMPORT_MAIL 11


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {
                     
    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Submenu";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Submenu",
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
    
  switch(msg) {
  
      case WM_CREATE:
      
          AddMenus(hwnd);
          break;

      case WM_COMMAND:
      
          switch(LOWORD(wParam)) {
          
              case IDM_FILE_NEW:
                  MessageBoxW(NULL, L"New file selected", 
                        L"Information", MB_OK);
                  break;

              case IDM_IMPORT_MAIL:
                  MessageBoxW(NULL, L"Import mail selected", 
                        L"Information", MB_OK);
           }
           
           break;

      case WM_DESTROY:
      
          PostQuitMessage(0);
          break;
  }

  return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void AddMenus(HWND hwnd) {
  
    HMENU hMenubar = CreateMenu();
    HMENU hMenu = CreateMenu();
    HMENU hSubMenu = CreatePopupMenu();

    AppendMenuW(hMenu, MF_STRING, IDM_FILE_NEW, L"&New");

    AppendMenuW(hMenu, MF_STRING | MF_POPUP, (UINT_PTR) hSubMenu, L"&Import");
    AppendMenuW(hSubMenu, MF_STRING, IDM_IMPORT_MAIL, L"Import &mail");

    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu, L"&File");
    SetMenu(hwnd, hMenubar);
}
