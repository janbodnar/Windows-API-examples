#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void LoadMyImage(void);

HBITMAP hBitmap;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {

    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Static image";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0,IDC_ARROW);

  
    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Static image",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 330, 270, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {
    
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

  return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
    WPARAM wParam, LPARAM lParam) {
    
    HWND hsti;

    switch(msg) {

        case WM_CREATE:
    
            LoadMyImage();
            hsti = CreateWindowW(L"Static", L"", 
                WS_CHILD | WS_VISIBLE | SS_BITMAP,
                5, 5, 300, 300, hwnd, (HMENU) 1, NULL, NULL);

            SendMessage(hsti, STM_SETIMAGE,
                (WPARAM) IMAGE_BITMAP, (LPARAM) hBitmap); 
            break;

        case WM_DESTROY:

            DeleteObject(hBitmap);
            PostQuitMessage(0);
            break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void LoadMyImage(void) {

    hBitmap = LoadImageW(NULL, L"C:\\prog\\slovakia.bmp", IMAGE_BITMAP,
        0, 0, LR_LOADFROMFILE);
}
