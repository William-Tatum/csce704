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

    // Simulate an operation that throws an exception (e.g., division by zero)
    int exceptionOccurred = 1;
    if (exceptionOccurred) {
        printf("Exception occurred\n");
        // Improper cleanup: buffer is not freed before returning
        return;
    }

    // Normal processing
    printf("Normal processing\n");

    cleanup(buffer);
}

int main() {
    riskyFunction();
    return 0;
}