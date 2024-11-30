#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int buffer_size = 10;
    char *buffer = (char *)malloc(buffer_size);

    if (!buffer) {
        return -1;
    }

    memset(buffer, 'A', buffer_size);

    // Vulnerable code: writing before the beginning of the buffer
    buffer -= 1; // Pointer decremented
    buffer[0] = 'B'; // Buffer underwrite

    buffer += 1; // Reset pointer to original position
    printf("Buffer: %.*s\n", buffer_size, buffer);

    free(buffer);
    return 0;
}