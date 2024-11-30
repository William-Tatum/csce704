#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int max_value = UINT_MAX;
    if (max_value < UINT_MAX) {
        max_value += 1;
    } else {
        printf("Overflow prevented, max value reached: %u\n", max_value);
    }
    return 0;
}