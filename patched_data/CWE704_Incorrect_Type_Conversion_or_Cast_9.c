#include <stdio.h>
#include <limits.h>

int main() {
    long largeNumber = 2147483648;
    if (largeNumber > INT_MAX || largeNumber < INT_MIN) {
        fprintf(stderr, "Error: Conversion results in overflow.\n");
        return 1;
    }
    int smallerNumber = (int)largeNumber;
    printf("Original: %ld, After Conversion: %d\n", largeNumber, smallerNumber);
    return 0;
}