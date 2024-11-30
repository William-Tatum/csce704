#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer;
    size_t bufferSize = 10;
    buffer = (char *)malloc(bufferSize);
    if (buffer == NULL) {
        return 1;
    }

    char *input = "This input is way too long for the buffer";
    if (strlen(input) >= bufferSize) {
        free(buffer);
        return 1;
    }

    strcpy(buffer, input);
    printf("Buffer contains: %s\n", buffer);
    free(buffer);
    return 0;
}