#include <stdio.h>

int main() {
    unsigned int value = 8;
    int shiftAmount;

    printf("Enter shift amount (0-31): ");
    scanf("%d", &shiftAmount);

    if (shiftAmount < 0 || shiftAmount >= sizeof(unsigned int) * 8) {
        printf("Invalid shift amount. Must be between 0 and %lu.\n", sizeof(unsigned int) * 8 - 1);
    } else {
        unsigned int result = value << shiftAmount;
        printf("Result after shifting: %u\n", result);
    }
    
    return 0;
}