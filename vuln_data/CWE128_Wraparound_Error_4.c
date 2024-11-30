#include <stdio.h>

int main() {
    unsigned int max = 4294967295;
    unsigned int overflow = max + 1;
    
    printf("Expected: %u, Actual: %u\n", max + 1, overflow);
    
    return 0;
}