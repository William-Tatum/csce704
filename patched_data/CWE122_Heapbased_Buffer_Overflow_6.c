#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer;
    size_t bufferSize = 50;
    buffer = (char *)malloc(bufferSize);
    if (buffer == NULL) {
        return 1;
    }

    char *input = "This input is way too long for the buffer";

    strncpy(buffer, input, bufferSize - 1);
    buffer[bufferSize - 1] = '\0';

    printf("Buffer contains: %s\n", buffer);
    free(buffer);
    return 0;
}