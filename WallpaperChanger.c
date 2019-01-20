#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <tchar.h>

int WINAPI WinMain(
  HINSTANCE hCurInst,
  HINSTANCE hPrevInst,
  LPSTR lpsCmdLine,
  int nCmdShow)
{
    int    i;
    int    nArgs;
    LPTSTR *lplpszArgs;
    
    lplpszArgs = CommandLineToArgvW(GetCommandLine(), &nArgs);

    // Check argument count
    if (nArgs == 2) {
        if (!SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, lplpszArgs[1], SPIF_UPDATEINIFILE | SPIF_SENDWININICHANGE)) {
            MessageBox(NULL, lplpszArgs[1], TEXT("Apply error(WallpaperChanger)"), MB_OK | MB_ICONINFORMATION);
        }
    } else {
        MessageBox(NULL, TEXT("Invalid argument."), TEXT("WallpaperChanger"), MB_OK | MB_ICONERROR);
    }

    LocalFree(lplpszArgs);
    return 0;
}
