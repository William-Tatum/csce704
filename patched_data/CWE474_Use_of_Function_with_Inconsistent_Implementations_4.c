#include <stdio.h>
#include <stdlib.h>

int main() {
    int result;
    #ifdef _WIN32
    result = system("cmd /C dir 2>&1");
    #else
    result = system("ls 2>&1");
    #endif
    if (result == -1) {
        printf("Command execution failed\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}