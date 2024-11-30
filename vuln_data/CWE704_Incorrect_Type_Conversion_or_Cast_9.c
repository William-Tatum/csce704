#include <stdio.h>
#include <limits.h>

int main() {
    long largeNumber = 2147483648; // Larger than INT_MAX
    int smallerNumber = (int)largeNumber; // Incorrect type conversion
    printf("Original: %ld, After Conversion: %d\n", largeNumber, smallerNumber);
    return 0;
}