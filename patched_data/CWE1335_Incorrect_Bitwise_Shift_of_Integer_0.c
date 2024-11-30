#include <stdio.h>
#include <limits.h>

int safe_left_shift(int value, int shift) {
    if (shift < 0 || shift >= sizeof(int) * CHAR_BIT) {
        fprintf(stderr, "Shift amount is out of valid range\n");
        return -1;
    }
    if (value > INT_MAX >> shift) {
        fprintf(stderr, "Shift would cause an overflow\n");
        return -1;
    }
    return value << shift;
}

int main() {
    int num = 2;
    int shift_amount = 29;

    int result = safe_left_shift(num, shift_amount);
    if (result != -1) {
        printf("Result: %d\n", result);
    }
    
    return 0;
}