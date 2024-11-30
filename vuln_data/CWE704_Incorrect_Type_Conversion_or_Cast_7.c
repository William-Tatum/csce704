#include <stdio.h>

void processValue(unsigned long long value) {
    printf("Processed value: %llu\n", value);
}

int main() {
    int negativeInt = -1;
    unsigned long long unsignedValue = (unsigned long long) negativeInt;
    processValue(unsignedValue);
    return 0;
}