#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void processData(size_t dataSize) {
    if (dataSize > SIZE_MAX / sizeof(char)) {
        printf("Data size too large to process safely.\n");
        return;
    }

    char *buffer = (char *)malloc(dataSize);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (size_t i = 0; i < dataSize; i++) {
        buffer[i] = (char)(i % 256);
    }
    
    printf("Buffer processed safely.\n");
    free(buffer);
}

int main() {
    size_t largeUnsigned = 5000;
    processData(largeUnsigned);
    return 0;
}