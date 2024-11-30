#include <stdio.h>
#include <limits.h>

int safe_shift(int value, int shift_amount) {
    if (shift_amount < 0 || shift_amount >= sizeof(int) * CHAR_BIT) {
        return value; 
    }
    return value << shift_amount;
}

int main() {
    int x = 1;
    int result = safe_shift(x, -1);
    printf("Result of safe shift: %d\n", result);

    result = safe_shift(x, sizeof(int) * CHAR_BIT);
    printf("Result of safe shift: %d\n", result);

    result = safe_shift(x, 2);
    printf("Result of safe shift: %d\n", result);

    return 0;
}