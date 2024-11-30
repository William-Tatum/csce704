#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main() {
    char inputPath[PATH_MAX];
    char resolvedPath[128];
    if (fgets(inputPath, sizeof(inputPath), stdin) != NULL) {
        if (realpath(inputPath, resolvedPath) == NULL) {
            perror("Error resolving path");
            return 1;
        }
        printf("Resolved Path: %s\n", resolvedPath);
    } else {
        fprintf(stderr, "Error reading input path\n");
        return 1;
    }
    return 0;
}