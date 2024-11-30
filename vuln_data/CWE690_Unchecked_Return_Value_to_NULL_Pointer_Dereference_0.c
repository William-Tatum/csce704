#include <stdio.h>
#include <stdlib.h>

char* allocateMemory(size_t size) {
    return (char*)malloc(size);
}

int main() {
    char* buffer = allocateMemory(1024);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    // Use the buffer
    printf("Buffer allocated successfully.\n");
    
    free(buffer);
    return 0;
}