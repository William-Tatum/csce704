#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int buffer_size = 10;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));
    if (!buffer) {
        return 1;
    }
    memset(buffer, 'A', buffer_size);
    int negative_index = -1;
    buffer[negative_index] = 'B';
    printf("Buffer: %s\n", buffer);
    free(buffer);
    return 0;
}