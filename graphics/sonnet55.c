
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR lpCmdLine, int nCmdShow) {
    
    MSG  msg ;
    WNDCLASSW wc = {0};

    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = L"Sonnet 55";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Sonnet 55",
          WS_OVERLAPPEDWINDOW | WS_VISIBLE,
          100, 100, 390, 350, NULL, NULL, hInstance, NULL);

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

    DWORD color;

    HFONT hFont, holdFont;

    static wchar_t *ver1 = L"Not marble, nor the gilded monuments";
    static wchar_t *ver2 = L"Of princes, shall outlive this powerful rhyme;";
    static wchar_t *ver3 = L"But you shall shine more bright in these contents";
    static wchar_t *ver4 = L"Than unswept stone, besmear'd with sluttish time.";
    static wchar_t *ver5 = L"When wasteful war shall statues overturn,";
    static wchar_t *ver6 = L"And broils root out the work of masonry,";
    static wchar_t *ver7 = L"Nor Mars his sword, nor war's quick fire shall burn";
    static wchar_t *ver8 = L"The living record of your memory.";
    static wchar_t *ver9 = L"'Gainst death, and all oblivious enmity";
    static wchar_t *ver10 = L"Shall you pace forth; your praise shall still find room";
    static wchar_t *ver11 = L"Even in the eyes of all posterity";
    static wchar_t *ver12 = L"That wear this world out to the ending doom.";
    static wchar_t *ver13 = L"So, till the judgment that yourself arise,";
    static wchar_t *ver14 = L"You live in this, and dwell in lovers' eyes.";

    switch(msg) {
    
        case WM_PAINT:

            hdc = BeginPaint(hwnd, &ps);

            color = GetSysColor(COLOR_BTNFACE);
            SetBkColor(hdc, color);

            hFont = CreateFontW(15, 0, 0, 0, FW_MEDIUM, 0, 0, 0, 0,
                                0, 0, 0, 0, L"Georgia");
            holdFont = SelectObject(hdc, hFont);

            TextOutW(hdc, 50, 20,  ver1,  lstrlenW(ver1));
            TextOutW(hdc, 50, 40,  ver2,  lstrlenW(ver2));
            TextOutW(hdc, 50, 60,  ver3,  lstrlenW(ver3));
            TextOutW(hdc, 50, 80,  ver4,  lstrlenW(ver4));
            TextOutW(hdc, 50, 100, ver5,  lstrlenW(ver5));
            TextOutW(hdc, 50, 120, ver6,  lstrlenW(ver6));
            TextOutW(hdc, 50, 140, ver7,  lstrlenW(ver7));
            TextOutW(hdc, 50, 160, ver8,  lstrlenW(ver8));
            TextOutW(hdc, 50, 180, ver9,  lstrlenW(ver9));
            TextOutW(hdc, 50, 200, ver10, lstrlenW(ver10));
            TextOutW(hdc, 50, 220, ver11, lstrlenW(ver11));
            TextOutW(hdc, 50, 240, ver12, lstrlenW(ver12));
            TextOutW(hdc, 50, 260, ver13, lstrlenW(ver13));
            TextOu tW(hdc, 50, 280, ver14, lstrlenW(ver14));

            SelectObject(hdc, holdFont);
            DeleteObject(hFont);

            EndPaint(hwnd, &ps);
            break;

        case WM_DESTROY:

            PostQuitMessage(0);
           return 0;
    }
  
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
