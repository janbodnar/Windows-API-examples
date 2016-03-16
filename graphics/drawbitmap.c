#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR lpCmdLine, int nCmdShow) {

    MSG  msg;
    WNDCLASSW wc = {0};

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = L"Draw Bitmap";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Draw Bitmap",
          WS_OVERLAPPEDWINDOW | WS_VISIBLE,
          100, 100, 280, 220, NULL, NULL, hInstance, NULL);

    while (GetMessage(&msg, NULL, 0, 0)) {
        
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {

    static HBITMAP hBitmap;
    HDC hdc;
    PAINTSTRUCT ps;
    BITMAP bitmap;
    HDC hdcMem;
    HGDIOBJ oldBitmap;

    switch(msg) {

        case WM_CREATE:
     
             hBitmap = (HBITMAP) LoadImageW(NULL, L"C:\\prog\\slovakia.bmp", 
                        IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

             if (hBitmap == NULL) {
                 MessageBoxW(hwnd, L"Failed to load image", L"Error", MB_OK); 
             }

             break;      

        case WM_PAINT:
        
             hdc = BeginPaint(hwnd, &ps);

             hdcMem = CreateCompatibleDC(hdc);
             oldBitmap = SelectObject(hdcMem, hBitmap);

             GetObject(hBitmap, sizeof(bitmap), &bitmap);
             BitBlt(hdc, 5, 5, bitmap.bmWidth, bitmap.bmHeight, 
                 hdcMem, 0, 0, SRCCOPY);

             SelectObject(hdcMem, oldBitmap);
             DeleteDC(hdcMem);

             EndPaint(hwnd, &ps);

             break;

        case WM_DESTROY:

            DeleteObject(hBitmap);
            PostQuitMessage(0);
            
            return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
