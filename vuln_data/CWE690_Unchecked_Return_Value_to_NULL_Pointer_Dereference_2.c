#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocate_memory(int size) {
    if (size <= 0) return NULL;
    return (char*)malloc(size * sizeof(char));
}

int main() {
    char *buffer = allocate_memory(10);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    strcpy(buffer, "Hello");
    printf("%s\n", buffer);

    free(buffer);
    return 0;
}