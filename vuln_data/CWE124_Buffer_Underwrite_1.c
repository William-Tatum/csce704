#include <stdio.h>
#include <stdlib.h>

void bufferUnderwriteExample() {
    int *buffer = (int *)malloc(5 * sizeof(int));
    if (!buffer) {
        exit(1);
    }

    int *ptr = buffer;
    for (int i = 0; i < 5; i++) {
        buffer[i] = i;
    }

    ptr = buffer - 1;
    *ptr = 42; // Writing to memory before the beginning of the buffer

    free(buffer);
}

int main() {
    bufferUnderwriteExample();
    return 0;
}