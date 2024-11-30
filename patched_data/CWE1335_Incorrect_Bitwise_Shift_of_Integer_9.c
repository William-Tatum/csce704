#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t num = 16;
    int shift_amount = 36;

    if (shift_amount < 0 || shift_amount >= (int)(sizeof(num) * 8)) {
        printf("Shift amount %d is invalid.\n", shift_amount);
    } else {
        uint32_t result = num << shift_amount;
        printf("Result of shifting: %u\n", result);
    }

    return 0;
}