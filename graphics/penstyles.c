#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void DrawLines(HWND);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR lpCmdLine, int nCmdShow) {
    
    MSG  msg;
    WNDCLASSW wc = {0};

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = L"Pens";
    wc.hInstance     = hInstance;
    wc.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Pens",
          WS_OVERLAPPEDWINDOW | WS_VISIBLE,
          100, 100, 250, 180, NULL, NULL, hInstance, NULL);

    while (GetMessage(&msg, NULL, 0, 0)) {
    
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {
    
    switch(msg) {
  
        case WM_PAINT:

            DrawLines(hwnd);
            break;

        case WM_DESTROY:

            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void DrawLines(HWND hwnd) {

    PAINTSTRUCT ps;

    HDC hdc = BeginPaint(hwnd, &ps);
    HPEN hPen1 = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    HPEN hPen2 = CreatePen(PS_DASH, 1, RGB(0, 0, 0));
    HPEN hPen3 = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
    HPEN hPen4 = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 0));
    HPEN hPen5 = CreatePen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));

    HPEN holdPen = SelectObject(hdc, hPen1);
    MoveToEx(hdc, 50, 30, NULL);
    LineTo(hdc, 200, 30);

    SelectObject(hdc, hPen2);
    MoveToEx(hdc, 50, 50, NULL);
    LineTo(hdc, 200, 50);

    SelectObject(hdc, hPen2);
    MoveToEx(hdc, 50, 70, NULL);
    LineTo(hdc, 200, 70);

    SelectObject(hdc, hPen3);
    MoveToEx(hdc, 50, 90, NULL);
    LineTo(hdc, 200, 90);

    SelectObject(hdc, hPen4);
    MoveToEx(hdc, 50, 110, NULL);
    LineTo(hdc, 200, 110);

    SelectObject(hdc, holdPen);
    DeleteObject(hPen1);
    DeleteObject(hPen2);
    DeleteObject(hPen3);
    DeleteObject(hPen4);
    DeleteObject(hPen5);

    EndPaint(hwnd, &ps);  
}
