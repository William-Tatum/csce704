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
    
    // Use the buffer safely, ensuring no overflow or misuse
    printf("Buffer allocated successfully.\n");
    
    // Clear the buffer if it contains sensitive information
    // memset(buffer, 0, 1024);

    free(buffer);
    buffer = NULL; // Avoid dangling pointers
    return 0;
}