#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {

    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Static Control";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

  
    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Criminal",
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

    static wchar_t *lyrics =  L"I know you told me I should stay away\n\
I know you said he's just a dog astray\n\
He is a bad boy with a tainted heart\n\
And even I know this ain't smart\n\
\n\
But mama, I'm in love with a criminal\n\
And this type of love isn't rational, it's physical\n\
Mama, please don't cry, I will be alright\n\
All reason aside, I just can't deny, love the guy\n\
";

    switch(msg) {

        case WM_CREATE:
      
            CreateWindowW(L"Static", lyrics, 
                WS_CHILD | WS_VISIBLE | SS_LEFT,
                20, 20, 300, 230, 
                hwnd, (HMENU) 1, NULL, NULL);
            break;

        case WM_DESTROY:

            PostQuitMessage(0);
            break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
