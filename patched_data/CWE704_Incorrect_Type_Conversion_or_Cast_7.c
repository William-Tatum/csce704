#include <stdio.h>
#include <limits.h>

void processValue(unsigned long long value) {
    printf("Processed value: %llu\n", value);
}

int main() {
    long long signedValue = -1;
    unsigned long long unsignedValue;

    if (signedValue >= 0) {
        unsignedValue = (unsigned long long) signedValue;
    } else {
        unsignedValue = 0;
        printf("Warning: Negative value converted to zero for unsigned representation.\n");
    }
    
    processValue(unsignedValue);
    return 0;
}