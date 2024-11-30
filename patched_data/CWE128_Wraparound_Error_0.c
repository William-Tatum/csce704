#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int maxValue = UINT_MAX;
    unsigned long long result = (unsigned long long)maxValue + 1;
    printf("Result after addition: %llu\n", result);
    return 0;
}