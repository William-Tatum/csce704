#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocate_memory(int size) {
    if (size <= 0) return NULL;
    return (char*)malloc(size * sizeof(char));
}

int main() {
    char *buffer = allocate_memory(11); // Allocate space for "Hello" + null terminator
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    strncpy(buffer, "Hello", 10); // Use strncpy to prevent overflow
    buffer[10] = '\0'; // Ensure null termination
    printf("%s\n", buffer);

    free(buffer);
    return 0;
}