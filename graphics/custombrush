#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR lpCmdLine, int nCmdShow) {
    
    MSG  msg;
    WNDCLASSW wc = {0};

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = L"Custom brush";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Custom brush",
          WS_OVERLAPPEDWINDOW | WS_VISIBLE,
          100, 100, 300, 200, NULL, NULL, hInstance, NULL);

    while (GetMessage(&msg, NULL, 0, 0)) {
        
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {
    
    HDC hdc;
    PAINTSTRUCT ps;
    static HBITMAP hBtm;

    UINT bits[8] = { 0x111111ff, 0xffffffff, 0xffffffff, 0xffffffff,
        0x00000000, 0x00000000, 0x00000000, 0x00000000 };

    switch(msg) {

        case WM_CREATE:

            hBtm = CreateBitmap(8, 8, 1, 1, (LPBYTE) bits);

            break;
    
        case WM_PAINT:

            hdc = BeginPaint(hwnd, &ps);
            
            HBRUSH hCustomBrush = CreatePatternBrush(hBtm);
            HBRUSH hOldBrush = SelectObject(hdc, hCustomBrush);

            SelectObject(hdc, GetStockObject(NULL_PEN));

            Rectangle(hdc, 20, 20, 250, 160);

            SelectObject(hdc, hOldBrush);
            DeleteObject(hCustomBrush);

            SelectObject(hdc, GetStockObject(BLACK_PEN));

            EndPaint(hwnd, &ps);
            break;

        case WM_DESTROY:
 
            DeleteObject(hBtm);
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
