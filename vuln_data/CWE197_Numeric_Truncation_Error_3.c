#include <stdio.h>

int main() {
    int largeValue = 300;
    short truncatedValue;
    
    /* Potential truncation error */
    truncatedValue = (short)largeValue;
    
    printf("Original value: %d\n", largeValue);
    printf("Truncated value: %d\n", truncatedValue);
    
    return 0;
}