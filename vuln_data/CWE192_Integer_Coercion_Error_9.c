#include <stdio.h>
#include <limits.h>

void unsafeFunction() {
    unsigned int large_unsigned = UINT_MAX;
    int coerced_signed = (int)large_unsigned;

    printf("Large unsigned: %u\n", large_unsigned);
    printf("Coerced signed: %d\n", coerced_signed);
}

int main() {
    unsafeFunction();
    return 0;
}