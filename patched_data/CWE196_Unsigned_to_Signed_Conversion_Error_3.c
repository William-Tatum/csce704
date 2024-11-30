#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void processData(size_t bufferSize) {
    char *buffer = (char *)malloc(bufferSize);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    unsigned int largeValue = 4294967295; // 0xFFFFFFFF
    int signedValue;

    if (largeValue > INT_MAX) {
        printf("Unsigned value is too large to convert to signed int\n");
        free(buffer);
        return;
    } else {
        signedValue = (int)largeValue;
    }

    if ((unsigned int)signedValue < bufferSize) {
        buffer[signedValue] = 'X'; 
        printf("Buffer index accessed\n");
    } else {
        printf("Index out of bounds\n");
    }

    free(buffer);
}

int main() {
    processData(100);
    return 0;
}