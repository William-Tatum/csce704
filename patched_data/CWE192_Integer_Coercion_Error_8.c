#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    long large_value = LONG_MAX;
    int coerced_value;

    if (large_value > INT_MAX || large_value < INT_MIN) {
        printf("Error: Value out of int range\n");
        return 1;
    } else {
        coerced_value = (int)large_value;
    }
    
    printf("Original long value: %ld\n", large_value);
    printf("Coerced int value: %d\n", coerced_value);
    return 0;
}