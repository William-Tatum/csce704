#include <stdio.h>
#include <limits.h>

int main() {
    long large_value = LONG_MAX;
    int coerced_value = (int)large_value;
    printf("Original long value: %ld\n", large_value);
    printf("Coerced int value: %d\n", coerced_value);
    return 0;
}