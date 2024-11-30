#include <stdio.h>
#include <limits.h>

int main() {
    int a = INT_MIN;
    int b = 1;
    int result;

    if (a - b > a) {
        printf("Integer underflow detected\n");
    } else {
        result = a - b;
        printf("Result: %d\n", result);
    }

    unsigned int c = 0;
    unsigned int d = 1;
    unsigned int unsigned_result;

    if (c < d) {
        printf("Unsigned integer underflow detected\n");
    } else {
        unsigned_result = c - d;
        printf("Unsigned Result: %u\n", unsigned_result);
    }

    return 0;
}