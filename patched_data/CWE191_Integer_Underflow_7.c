#include <stdio.h>
#include <limits.h>

int main() {
    int minInt = INT_MIN;
    int result;

    // Securely handle possible underflow for signed integers
    if (minInt > INT_MIN) {
        result = minInt - 1;
        printf("Result: %d\n", result);
    } else {
        printf("Underflow prevented: cannot subtract from INT_MIN\n");
    }
    
    unsigned int minUnsignedInt = 0;
    unsigned int uResult;

    // Securely handle possible underflow for unsigned integers
    if (minUnsignedInt > 0) {
        uResult = minUnsignedInt - 1;
        printf("Unsigned Result: %u\n", uResult);
    } else {
        printf("Underflow prevented: cannot subtract from 0 in unsigned int\n");
    }

    return 0;
}