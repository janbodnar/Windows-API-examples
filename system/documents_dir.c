#include <windows.h>
#include <initguid.h>
#include <KnownFolders.h>
#include <ShlObj.h>
#include <wchar.h>

int wmain(void) {

    PWSTR path = NULL;
    
    HRESULT hr = SHGetKnownFolderPath(&FOLDERID_Documents, 0, NULL, &path);

    if (SUCCEEDED(hr)) {
        wprintf(L"%ls\n", path);
    }

    CoTaskMemFree(path);

    return 0;
}
