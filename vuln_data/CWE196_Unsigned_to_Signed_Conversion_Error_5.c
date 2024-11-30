#include <stdio.h>

int main() {
    unsigned int largeUnsignedValue = 4294967295; // Example large unsigned int
    int signedValue = (int)largeUnsignedValue;

    char buffer[10];
    if (signedValue < sizeof(buffer)) {
        buffer[signedValue] = 'A'; // Erroneous attempt due to improper casting
    }

    printf("Signed value: %d\n", signedValue);
    return 0;
}