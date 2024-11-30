#include <stdio.h>
#include <limits.h>

int main() {
    int small_int = 123;
    long large_int;

    // Intentional coercion error: assigning a smaller type to a larger type
    // Leading to potential data integrity issues
    large_int = (long)small_int;

    // To demonstrate the anomaly, let's use a case with potential truncation
    large_int = INT_MAX + 10L; // Beyond the range of int
    small_int = (int)large_int; // Truncating

    printf("Coerced value: %d\n", small_int);
    return 0;
}