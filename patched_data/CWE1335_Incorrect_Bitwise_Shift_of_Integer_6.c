#include <stdio.h>

int main() {
    int value = 1024;
    int shiftAmount = -3; // Vulnerable shift amount

    if (shiftAmount < 0 || shiftAmount >= sizeof(int) * 8) {
        printf("Error: Invalid shift amount.\n");
        return 1;
    }

    int result = value << shiftAmount;
    printf("Result: %d\n", result);

    return 0;
}