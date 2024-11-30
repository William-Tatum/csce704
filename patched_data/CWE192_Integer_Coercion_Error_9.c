#include <stdio.h>
#include <limits.h>

void safeFunction() {
    unsigned int large_unsigned = UINT_MAX;
    printf("Large unsigned: %u\n", large_unsigned);

    if (large_unsigned > INT_MAX) {
        printf("Coerced signed: Overflow error\n");
    } else {
        int coerced_signed = (int)large_unsigned;
        printf("Coerced signed: %d\n", coerced_signed);
    }
}

int main() {
    safeFunction();
    return 0;
}