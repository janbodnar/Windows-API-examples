#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND);

#define IDM_MODE_MAP 1
#define IDM_MODE_SAT 2
#define IDM_MODE_TRA 3
#define IDM_MODE_STR 4

HMENU hMenu;


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {
                     
    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Radio menu item";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Radio menu item",
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
          
              case IDM_MODE_MAP:
                  CheckMenuRadioItem(hMenu, IDM_MODE_MAP, IDM_MODE_STR, 
                      IDM_MODE_MAP, MF_BYCOMMAND);
                  MessageBeep(MB_ICONERROR);
                  break;

              case IDM_MODE_SAT:
                  CheckMenuRadioItem(hMenu, IDM_MODE_MAP, IDM_MODE_STR, 
                      IDM_MODE_SAT, MF_BYCOMMAND);
                  MessageBeep(0xFFFFFFFF);
                  break;

              case IDM_MODE_TRA:
                  CheckMenuRadioItem(hMenu, IDM_MODE_MAP, IDM_MODE_STR, 
                      IDM_MODE_TRA, MF_BYCOMMAND);
                  MessageBeep(MB_ICONWARNING);
                  break;

              case IDM_MODE_STR:
                  CheckMenuRadioItem(hMenu, IDM_MODE_MAP, IDM_MODE_STR, 
                      IDM_MODE_STR, MF_BYCOMMAND);
              
                  MessageBeep(MB_ICONINFORMATION);
                  break;
           }
           
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
    hMenu = CreateMenu();

    AppendMenuW(hMenu, MF_STRING, IDM_MODE_MAP, L"&Map");
    AppendMenuW(hMenu, MF_STRING, IDM_MODE_SAT, L"&Satellite");
    AppendMenuW(hMenu, MF_STRING, IDM_MODE_TRA, L"&Traffic");
    AppendMenuW(hMenu, MF_STRING, IDM_MODE_STR, L"Street &view");

    CheckMenuRadioItem(hMenu, IDM_MODE_MAP, IDM_MODE_STR, 
        IDM_MODE_MAP, MF_BYCOMMAND);

    AppendMenuW(hMenubar, MF_POPUP, (UINT_PTR) hMenu, L"&Map mode");
    SetMenu(hwnd, hMenubar);
}
