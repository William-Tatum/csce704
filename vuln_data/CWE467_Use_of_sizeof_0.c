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

    // CWE-467: Incorrectly using sizeof() on a pointer
    printf("Size of buffer: %zu\n", sizeof(buffer));  // This will output the size of the pointer, not the allocated memory

    free(buffer);
    return 0;
}