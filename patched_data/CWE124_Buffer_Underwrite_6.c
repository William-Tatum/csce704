#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buffer_underwrite() {
    char *buffer = (char *)malloc(10);
    if (buffer == NULL) exit(1);

    // Correctly point to the start of the buffer
    char *ptr = buffer;

    // Write within the bounds of the allocated buffer
    memset(ptr, 'A', 1);

    free(buffer);
}

int main() {
    buffer_underwrite();
    return 0;
}