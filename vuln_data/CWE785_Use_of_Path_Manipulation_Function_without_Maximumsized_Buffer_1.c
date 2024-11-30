#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char inputPath[PATH_MAX];
    char resolvedPath[128];
    
    printf("Enter the path: ");
    if (fgets(inputPath, sizeof(inputPath), stdin) == NULL) {
        perror("Input error");
        exit(EXIT_FAILURE);
    }

    if (!realpath(inputPath, resolvedPath)) {
        perror("Error resolving path");
        exit(EXIT_FAILURE);
    }
    
    printf("Resolved Path: %s\n", resolvedPath);
    return 0;
}