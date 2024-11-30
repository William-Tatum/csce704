#include <stdio.h>
#include <limits.h>

int main() {
    long largeValue = LONG_MAX;
    // Truncate largeValue to a short
    short truncatedValue = (short)largeValue;
    printf("Original value: %ld\n", largeValue);
    printf("Truncated value: %d\n", truncatedValue);
    return 0;
}