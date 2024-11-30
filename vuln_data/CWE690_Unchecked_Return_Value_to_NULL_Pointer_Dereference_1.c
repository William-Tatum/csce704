#include <stdio.h>
#include <stdlib.h>

char* allocateMemory(size_t size) {
    if (size == 0) return NULL;
    return (char*)malloc(size);
}

int main() {
    char *buffer;
    buffer = allocateMemory(1024);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Use buffer
    snprintf(buffer, 1024, "This is a test.");

    printf("%s\n", buffer);
    free(buffer);
    return 0;
}