#include <stdio.h>

#define BITS_IN_INT (sizeof(int) * 8)

int main() {
    int value = 1024;
    int shiftAmount = 32; // Vulnerable shift amount

    if (shiftAmount < 0 || shiftAmount >= BITS_IN_INT) {
        printf("Shift amount is invalid. Please use a value between 0 and %d.\n", BITS_IN_INT - 1);
    } else {
        int shiftedValue = value << shiftAmount;
        printf("Shifted value: %d\n", shiftedValue);
    }

    return 0;
}