#include <stdio.h>
#include <limits.h>

int main() {
    int small_int = 123;
    long large_int;

    large_int = (long)small_int;

    large_int = INT_MAX + 10L;
    
    if (large_int > INT_MAX || large_int < INT_MIN) {
        fprintf(stderr, "Error: Value out of range for int type.\n");
        return 1;
    } else {
        small_int = (int)large_int;
        printf("Coerced value: %d\n", small_int);
    }

    return 0;
}