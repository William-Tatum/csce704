#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int buffer_size = 10;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));
    if (!buffer) {
        return 1;
    }
    memset(buffer, 'A', buffer_size - 1);
    buffer[buffer_size - 1] = '\0';
    if (buffer_size > 0) {
        buffer[buffer_size - 2] = 'B';
    }
    printf("Buffer: %s\n", buffer);
    free(buffer);
    return 0;
}