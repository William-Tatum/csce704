#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>

void getCurrentDirectory() {
    TCHAR buffer[MAX_PATH];
    DWORD result = GetCurrentDirectory(MAX_PATH, buffer);
    if(result != 0) {
        _tprintf(_T("Current Directory: %s\n"), buffer);
    } else {
        _tprintf(_T("Error retrieving current directory.\n"));
    }
}
#else
#include <unistd.h>
#include <limits.h>

void getCurrentDirectory() {
    char buffer[PATH_MAX];
    if(getcwd(buffer, sizeof(buffer)) != NULL) {
        printf("Current Directory: %s\n", buffer);
    } else {
        perror("Error retrieving current directory");
    }
}
#endif

int main() {
    getCurrentDirectory();
    return 0;
}