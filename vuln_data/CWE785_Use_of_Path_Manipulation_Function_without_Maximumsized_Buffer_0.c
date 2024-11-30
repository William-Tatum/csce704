#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char resolved_path[PATH_MAX];
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }
    if (realpath(argv[1], resolved_path) == NULL) {
        perror("realpath");
        return 1;
    }
    printf("Resolved path: %s\n", resolved_path);
    return 0;
}