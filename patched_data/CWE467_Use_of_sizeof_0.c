#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer;
    size_t buffer_size = 100;

    buffer = (char *)malloc(buffer_size);
    if (buffer == NULL) {
        return 1;
    }

    strncpy(buffer, "Sample text", buffer_size - 1);
    buffer[buffer_size - 1] = '\0';

    printf("Size of buffer: %zu\n", buffer_size);

    free(buffer);
    return 0;
}