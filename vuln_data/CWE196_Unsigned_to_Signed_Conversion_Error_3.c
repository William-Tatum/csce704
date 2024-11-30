#include <stdio.h>
#include <stdlib.h>

void processData(size_t bufferSize) {
    char *buffer = (char *)malloc(bufferSize);
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    unsigned int largeValue = 4294967295; // 0xFFFFFFFF
    int signedValue = (int)largeValue;

    if (signedValue < 0) {
        printf("Signed conversion result is negative\n");
    } else {
        printf("Signed conversion result is positive or zero\n");
    }

    if (signedValue < bufferSize) {
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