#include <stdio.h>
#include <limits.h>

void potentialTruncationError(unsigned int x) {
    short y = x;
    printf("Value of y: %d\n", y);
}

int main() {
    unsigned int bigNumber = UINT_MAX;
    potentialTruncationError(bigNumber);
    return 0;
}