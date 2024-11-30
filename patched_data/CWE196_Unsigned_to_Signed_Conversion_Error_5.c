#include <stdio.h>

int main() {
    unsigned int largeUnsignedValue = 4294967295; // Example large unsigned int
    int signedValue;

    if (largeUnsignedValue <= (unsigned int)INT_MAX) {
        signedValue = (int)largeUnsignedValue;
    } else {
        fprintf(stderr, "Error: Value too large to convert safely to a signed int\n");
        return 1;
    }

    char buffer[10];
    if (signedValue >= 0 && signedValue < (int)sizeof(buffer)) {
        buffer[signedValue] = 'A';
    }

    printf("Signed value: %d\n", signedValue);
    return 0;
}