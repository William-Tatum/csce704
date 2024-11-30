#include <stdio.h>
#include <stdlib.h>

void cleanup(char *buffer) {
    if (buffer) {
        free(buffer);
    }
}

void riskyFunction() {
    char *buffer = malloc(256);
    if (!buffer) {
        printf("Memory allocation failed\n");
        return;
    }

    int exceptionOccurred = 1;
    if (exceptionOccurred) {
        printf("Exception occurred\n");
        cleanup(buffer);
        return;
    }

    printf("Normal processing\n");

    cleanup(buffer);
}

int main() {
    riskyFunction();
    return 0;
}