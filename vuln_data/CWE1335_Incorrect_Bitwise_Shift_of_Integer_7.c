#include <stdio.h>

int main() {
    unsigned int value = 1;
    unsigned int shiftAmount;
    
    printf("Enter shift amount (0-31): ");
    scanf("%u", &shiftAmount);

    if (shiftAmount >= 0 && shiftAmount < sizeof(unsigned int) * 8) {
        unsigned int result = value << shiftAmount;
        printf("Result: %u\n", result);
    } else {
        printf("Shift amount out of range\n");
    }

    return 0;
}