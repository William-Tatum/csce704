#include <stdio.h>
#include <limits.h>

int main() {
    long largeValue = LONG_MAX;
    if (largeValue > SHRT_MAX || largeValue < SHRT_MIN) {
        printf("Error: Value out of range for short type\n");
        return 1;
    }
    short truncatedValue = (short)largeValue;
    printf("Original value: %ld\n", largeValue);
    printf("Truncated value: %d\n", truncatedValue);
    return 0;
}