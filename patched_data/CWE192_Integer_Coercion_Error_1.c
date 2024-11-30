#include <stdio.h>
#include <limits.h>

void potentialTruncationError(unsigned int x) {
    if (x > SHRT_MAX) {
        printf("Value is too large to fit in a short.\n");
    } else {
        short y = (short)x;
        printf("Value of y: %d\n", y);
    }
}

int main() {
    unsigned int bigNumber = UINT_MAX;
    potentialTruncationError(bigNumber);
    return 0;
}