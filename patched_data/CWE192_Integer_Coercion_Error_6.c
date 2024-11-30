#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int largeValue = UINT_MAX;
    int coercedValue;
    
    if (largeValue > (unsigned int)INT_MAX) {
        printf("Error: Potential data truncation detected.\n");
        return 1;
    }
    
    coercedValue = (int)largeValue;
    printf("Coerced Value: %d\n", coercedValue);
    
    return 0;
}