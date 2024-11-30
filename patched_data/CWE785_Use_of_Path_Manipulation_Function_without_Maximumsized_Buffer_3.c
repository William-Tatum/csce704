#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    char path[PATH_MAX];
    const char *input_path = "/some/very/long/path/that/may/exceed/the/boundary/of/the/path/buffer/and/leads/to/overflow.";
    if (realpath(input_path, path) == NULL) {
        perror("realpath error");
        exit(EXIT_FAILURE);
    }
    printf("Resolved path: %s\n", path);
    return 0;
}