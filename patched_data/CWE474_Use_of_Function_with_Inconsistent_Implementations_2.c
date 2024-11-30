#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <Windows.h>
#endif

void pause_program() {
#ifdef _WIN32
    printf("Press any key to continue...");
    fflush(stdout);
    getchar();
#else
    printf("Press Enter to continue...");
    getchar();
#endif
}

int main() {
    printf("This program will demonstrate consistent behavior across different platforms.\n");
    pause_program();
    return 0;
}