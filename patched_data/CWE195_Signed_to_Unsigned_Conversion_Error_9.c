#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyData(int size) {
    if (size <= 0) {
        printf("Error: Size must be positive.\n");
        return;
    }
    char *buffer = (char *)malloc(size);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    memset(buffer, 'A', size);
    printf("Memory allocated and buffer initialized.\n");
    free(buffer);
}

int main() {
    int size = 5; // Use a positive size for demonstration
    copyData(size);
    return 0;
}