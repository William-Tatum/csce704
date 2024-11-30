#include <stdio.h>
#include <limits.h>

int main() {
    int largeInt = INT_MAX;
    short coercedValue;

    coercedValue = largeInt;

    printf("Original int: %d\n", largeInt);
    printf("Coerced short: %d\n", coercedValue);

    return 0;
}