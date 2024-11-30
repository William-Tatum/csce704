#include <stdio.h>
#include <limits.h>

int main() {
    unsigned long long max = 4294967295;
    unsigned long long overflow = max + 1;
    
    if (overflow > UINT_MAX) {
        printf("Overflow detected: value exceeds UINT_MAX\n");
    } else {
        printf("Expected: %llu, Actual: %llu\n", max + 1, overflow);
    }
    
    return 0;
}