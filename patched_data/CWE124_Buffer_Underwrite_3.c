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

    // Corrected code: Ensure no writing outside buffer boundaries
    buffer[0] = 'B';

    printf("Buffer: %.*s\n", buffer_size, buffer);

    free(buffer);
    return 0;
}