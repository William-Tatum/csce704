#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

int main() {
    char inputPath[PATH_MAX];
    char resolvedPath[PATH_MAX];
    
    printf("Enter the path: ");
    if (fgets(inputPath, sizeof(inputPath), stdin) == NULL) {
        perror("Input error");
        exit(EXIT_FAILURE);
    }

    inputPath[strcspn(inputPath, "\n")] = '\0';  // Removing newline character

    if (!realpath(inputPath, resolvedPath)) {
        fprintf(stderr, "Error resolving path: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    printf("Resolved Path: %s\n", resolvedPath);
    return 0;
}