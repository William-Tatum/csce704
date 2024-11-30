#include <stdio.h>
#include <limits.h>

int main() {
    int largeValue = 300;
    short truncatedValue;
    
    if (largeValue > SHRT_MAX || largeValue < SHRT_MIN) {
        fprintf(stderr, "Error: Value out of range for 'short' type\n");
        return 1;
    }
    
    truncatedValue = (short)largeValue;
    
    printf("Original value: %d\n", largeValue);
    printf("Truncated value: %d\n", truncatedValue);
    
    return 0;
}