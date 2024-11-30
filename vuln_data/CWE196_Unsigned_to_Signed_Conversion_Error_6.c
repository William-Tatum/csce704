#include <stdio.h>
#include <limits.h>

void processData(size_t dataSize) {
    if (dataSize > INT_MAX) {
        printf("Data size too large to process safely as a signed integer.\n");
        return;
    }

    int signedDataSize = (int)dataSize;
    char buffer[100];
    
    if (signedDataSize < 0 || signedDataSize >= 100) {
        printf("Invalid data size for buffer operation.\n");
        return;
    }

    for (int i = 0; i < signedDataSize; i++) {
        buffer[i] = 'A';
    }

    printf("Processed data: %.*s\n", signedDataSize, buffer);
}

int main() {
    size_t largeDataSize = UINT_MAX - 1;
    processData(largeDataSize);

    size_t validDataSize = 20;
    processData(validDataSize);

    return 0;
}