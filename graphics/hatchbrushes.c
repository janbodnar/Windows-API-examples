#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void DrawRectangles(HWND hwnd);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR lpCmdLine, int nCmdShow) {
    
    MSG  msg;
    WNDCLASSW wc = {0};

    wc.style = CS_VREDRAW | CS_HREDRAW;
    wc.lpszClassName = L"Brush";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Hatch brushes",
          WS_OVERLAPPEDWINDOW | WS_VISIBLE,
          100, 100, 300, 220, NULL, NULL, hInstance, NULL);

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

          DrawRectangles(hwnd);
          break;

      case WM_DESTROY:

          PostQuitMessage(0);
          return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void DrawRectangles(HWND hwnd) {

    PAINTSTRUCT ps;

    HDC hdc = BeginPaint(hwnd, &ps);
    HPEN hPen = CreatePen(PS_NULL, 1, RGB(0, 0, 0));
    HPEN holdPen = SelectObject(hdc, hPen);

    HBRUSH hBrush1 = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 0));
    HBRUSH hBrush2 = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 0, 0));
    HBRUSH hBrush3 = CreateHatchBrush(HS_CROSS, RGB(0, 0, 0));
    HBRUSH hBrush4 = CreateHatchBrush(HS_HORIZONTAL, RGB(0, 0, 0));
    HBRUSH hBrush5 = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 0, 0));
    HBRUSH hBrush6 = CreateHatchBrush(HS_VERTICAL, RGB(0, 0, 0));

    HBRUSH holdBrush = SelectObject(hdc, hBrush1);

    DWORD col = GetSysColor(COLOR_BTNFACE);
    SetBkColor(hdc, col);

    Rectangle(hdc, 30, 30, 100, 80);
    SelectObject(hdc, hBrush2);
    Rectangle(hdc, 110, 30, 180, 80);
    SelectObject(hdc, hBrush3);
    Rectangle(hdc, 190, 30, 260, 80);
    SelectObject(hdc, hBrush4);
    Rectangle(hdc, 30, 110, 100, 160);
    SelectObject(hdc, hBrush5);
    Rectangle(hdc, 110, 110, 180, 160);
    SelectObject(hdc, hBrush6);
    Rectangle(hdc, 190, 110, 260, 160);

    SelectObject(hdc, holdPen);
    SelectObject(hdc, holdBrush);

    DeleteObject(hPen);
    DeleteObject(hBrush1);
    DeleteObject(hBrush2);
    DeleteObject(hBrush3);
    DeleteObject(hBrush4);
    DeleteObject(hBrush5);
    DeleteObject(hBrush6);

    EndPaint(hwnd, &ps);
}
