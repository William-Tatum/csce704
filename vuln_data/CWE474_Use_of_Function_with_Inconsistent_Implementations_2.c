#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

void pause_program() {
#ifdef _WIN32
    system("pause");
#else
    printf("Press Enter to continue...");
    getchar();
#endif
}

int main() {
    printf("This program will demonstrate inconsistent behavior across different platforms.\n");
    pause_program();
    return 0;
}