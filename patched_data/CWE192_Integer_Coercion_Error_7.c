#include <stdio.h>
#include <limits.h>

int main() {
    int largeInt = INT_MAX;
    short coercedValue;

    if (largeInt > SHRT_MAX || largeInt < SHRT_MIN) {
        fprintf(stderr, "Error: Value out of range for short\n");
        return 1;
    }

    coercedValue = (short)largeInt;

    printf("Original int: %d\n", largeInt);
    printf("Coerced short: %d\n", coercedValue);

    return 0;
}