#include <stdio.h>

int main() {
    unsigned int largeUnsignedValue = 4294967295; // 0xFFFFFFFF
    signed int signedValue = (signed int)largeUnsignedValue;
    
    if (signedValue < 0) {
        printf("Negative value detected, risky zone!\n");
        return 1;
    }

    int buffer[10];
    buffer[signedValue % 10] = 42; // Potentially dangerous write

    printf("Operation completed successfully.\n");
    return 0;
}