#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int max = UINT_MAX;
    unsigned long long result = (unsigned long long)max + 1;
    printf("Result: %llu\n", result);
    return 0;
}