#include <stdio.h>

void processData(size_t unsignedValue) {
    int signedValue;
    if (unsignedValue > INT_MAX) {
        printf("Error: Value too large to convert safely\n");
        return;
    }
    signedValue = (int)unsignedValue;
    char buffer[100];
    if (signedValue < 0 || signedValue >= sizeof(buffer)) {
        printf("Error: Unsafe buffer index\n");
        return;
    }
    buffer[signedValue] = 'A';
    printf("Successfully wrote to buffer at index %d\n", signedValue);
}

int main() {
    size_t largeUnsignedValue = 200;
    processData(largeUnsignedValue);
    return 0;
}