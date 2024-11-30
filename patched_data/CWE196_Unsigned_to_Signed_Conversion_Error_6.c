#include <stdio.h>
#include <limits.h>

void processData(size_t dataSize) {
    if (dataSize > 99) {
        printf("Data size too large for buffer operation.\n");
        return;
    }

    char buffer[100];
    for (size_t i = 0; i < dataSize; i++) {
        buffer[i] = 'A';
    }

    printf("Processed data: %.*s\n", (int)dataSize, buffer);
}

int main() {
    size_t largeDataSize = UINT_MAX - 1;
    processData(largeDataSize);

    size_t validDataSize = 20;
    processData(validDataSize);

    return 0;
}