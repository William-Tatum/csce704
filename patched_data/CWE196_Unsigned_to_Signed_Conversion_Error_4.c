#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int largeUnsignedValue = 4294967295; // 0xFFFFFFFF
    int buffer[10];

    if (largeUnsignedValue > INT_MAX) {
        printf("Value too large, ensuring safe operation.\n");
        return 1;
    }

    int safeIndex = largeUnsignedValue % 10;
    buffer[safeIndex] = 42;

    printf("Operation completed successfully.\n");
    return 0;
}