#include <stdio.h>
#include <limits.h>

int main() {
    int value = 1;
    int shift_amount;
    
    printf("Enter shift amount: ");
    scanf("%d", &shift_amount);

    if (shift_amount < 0 || shift_amount >= sizeof(int) * CHAR_BIT) {
        printf("Shift amount is invalid.\n");
    } else {
        int shifted_value = value << shift_amount;
        printf("Shifted value: %d\n", shifted_value);
    }

    return 0;
}