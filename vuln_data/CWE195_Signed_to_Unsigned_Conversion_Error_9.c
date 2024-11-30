#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyData(int size) {
    if (size < 0) {
        printf("Error: Negative size is invalid.\n");
        return;
    }
    unsigned int unsignedSize = (unsigned int)size;
    char *buffer = (char *)malloc(unsignedSize);
    if (buffer == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    memset(buffer, 'A', unsignedSize);
    printf("Memory allocated and buffer initialized.\n");
    free(buffer);
}

int main() {
    int size = -5;
    copyData(size);
    return 0;
}