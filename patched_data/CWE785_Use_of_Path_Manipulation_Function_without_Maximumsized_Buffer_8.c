#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int main() {
    char actualpath[PATH_MAX];
    const char *path = "/usr/local/bin";

    if (realpath(path, actualpath) == NULL) {
        perror("realpath");
        return EXIT_FAILURE;
    }

    printf("The resolved path is: %s\n", actualpath);
    return EXIT_SUCCESS;
}