#include <stdio.h>
#include <stdlib.h>

void processData(size_t dataSize) {
    if (dataSize > INT_MAX) {
        printf("Data size too large to process safely.\n");
        return;
    }
    
    int signedSize = (int)dataSize;
    char *buffer = (char *)malloc(signedSize);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < signedSize; i++) {
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