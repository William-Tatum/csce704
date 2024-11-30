#include <stdio.h>

int main() {
    unsigned int value = 32;
    int shiftAmount;
    printf("Enter shift amount: ");
    scanf("%d", &shiftAmount);

    if (shiftAmount < 0 || shiftAmount >= sizeof(unsigned int) * 8) {
        printf("Invalid shift amount\n");
        return 1;
    }

    unsigned int result = value << shiftAmount;
    printf("Result of shifting: %u\n", result);

    return 0;
}