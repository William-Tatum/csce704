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
    if (snprintf(buffer, 1024, "This is a test.") >= 1024) {
        fprintf(stderr, "Buffer overflow detected\n");
        free(buffer);
        return 1;
    }

    printf("%s\n", buffer);
    free(buffer);
    return 0;
}