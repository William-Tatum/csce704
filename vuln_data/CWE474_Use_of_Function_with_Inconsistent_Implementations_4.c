#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define SYSTEM_COMMAND "dir"
#else
#define SYSTEM_COMMAND "ls"
#endif

int main() {
    int result;
    result = system(SYSTEM_COMMAND);
    if (result == -1) {
        printf("Command execution failed\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}