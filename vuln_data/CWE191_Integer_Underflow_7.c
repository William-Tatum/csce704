#include <stdio.h>
#include <limits.h>

int main() {
    int minInt = INT_MIN;
    int result;

    if (minInt == INT_MIN) {
        printf("Underflow prevented: cannot subtract from INT_MIN\n");
    } else {
        result = minInt - 1;
        printf("Result: %d\n", result);
    }
    
    unsigned int minUnsignedInt = 0;
    unsigned int uResult;

    if (minUnsignedInt == 0) {
        printf("Underflow prevented: cannot subtract from 0 in unsigned int\n");
    } else {
        uResult = minUnsignedInt - 1;
        printf("Unsigned Result: %u\n", uResult);
    }

    return 0;
}