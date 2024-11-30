#include <stdio.h>

int main() {
    long largeValue = 300; 
    short truncatedValue;

    if (largeValue > SHRT_MAX || largeValue < SHRT_MIN) {
        printf("Truncation error: value is out of range for conversion.\n");
        return 1;
    }

    truncatedValue = (short)largeValue;
    printf("Original value: %ld\n", largeValue);
    printf("Truncated value: %d\n", truncatedValue);

    return 0;
}