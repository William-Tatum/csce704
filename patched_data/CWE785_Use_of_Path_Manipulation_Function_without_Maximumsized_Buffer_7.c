#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    char resolved_path[PATH_MAX];
    const char *path = "/etc/passwd";

    if (realpath(path, resolved_path) == NULL) {
        perror("realpath failed");
        exit(EXIT_FAILURE);
    }

    printf("Resolved path: %s\n", resolved_path);
    return 0;
}