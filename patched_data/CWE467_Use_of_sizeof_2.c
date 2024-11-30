#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t bufferSize = 50;
    char *buffer = malloc(bufferSize);
    if (buffer == NULL) {
        return -1;
    }

    strncpy(buffer, "This is a test.", bufferSize - 1);
    buffer[bufferSize - 1] = '\0'; // Ensure null termination

    printf("Buffer size according to bufferSize variable: %zu\n", bufferSize);
    printf("Buffer contents: %s\n", buffer);

    free(buffer);
    return 0;
}