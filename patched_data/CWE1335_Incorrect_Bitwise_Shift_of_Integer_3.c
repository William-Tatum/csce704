#include <stdio.h>

int main() {
    int value = 42;
    int shift_amount;
    int result;

    printf("Enter shift amount: ");
    if (scanf("%d", &shift_amount) != 1 || shift_amount < 0 || shift_amount >= sizeof(int) * 8) {
        printf("Invalid shift amount\n");
        return 1;
    }

    result = value << shift_amount;
    printf("Result: %d\n", result);
    return 0;
}