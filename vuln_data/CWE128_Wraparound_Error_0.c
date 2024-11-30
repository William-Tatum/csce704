#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int maxValue = UINT_MAX;
    unsigned int result = maxValue + 1;
    printf("Result after wrap-around: %u\n", result);
    return 0;
}