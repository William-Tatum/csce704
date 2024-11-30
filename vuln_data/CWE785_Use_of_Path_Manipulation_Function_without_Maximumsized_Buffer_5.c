#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char path[128];
    char *res = realpath("/some/path/to/file", path);
    if (res == NULL) {
        perror("realpath error");
        return EXIT_FAILURE;
    }
    printf("Normalized Path: %s\n", path);
    return EXIT_SUCCESS;
}