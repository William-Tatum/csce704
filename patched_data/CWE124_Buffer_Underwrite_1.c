#include <stdio.h>
#include <stdlib.h>

void bufferSecureExample() {
    int *buffer = (int *)malloc(5 * sizeof(int));
    if (!buffer) {
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        buffer[i] = i;
    }

    // Ensure there is no underwrite by removing invalid pointer manipulation
    buffer[0] = 42; // Example of safe usage without underwrite

    free(buffer);
}

int main() {
    bufferSecureExample();
    return 0;
}