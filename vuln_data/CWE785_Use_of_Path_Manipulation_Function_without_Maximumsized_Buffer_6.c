#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int main() {
    char outputPath[50];  // Inadequately sized buffer
    const char *inputPath = "/some/example/long/path/that/could/overflow/the/buffer";

    if (realpath(inputPath, outputPath) == NULL) {
        perror("Error resolving path");
        return 1;
    }

    printf("Resolved Path: %s\n", outputPath);
    return 0;
}