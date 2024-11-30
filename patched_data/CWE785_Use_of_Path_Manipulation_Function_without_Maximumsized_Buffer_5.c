#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

int main() {
    char path[PATH_MAX];
    char *res = realpath("/some/path/to/file", path);
    if (res == NULL) {
        perror("realpath error");
        return EXIT_FAILURE;
    }
    printf("Normalized Path: %s\n", path);
    return EXIT_SUCCESS;
}