#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char inputPath[PATH_MAX];
    char resolvedPath[PATH_MAX];
    if (fgets(inputPath, sizeof(inputPath), stdin) != NULL) {
        // Remove newline character from input
        inputPath[strcspn(inputPath, "\n")] = '\0';

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