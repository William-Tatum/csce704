#include <stdio.h>
#include <limits.h>

int main() {
    unsigned int largeValue = 4000000000;
    long long convertedValue = (long long) largeValue;

    if (convertedValue > INT_MAX) {
        printf("Converted value exceeds int range, using placeholder for display.\n");
    } else {
        printf("Original unsigned int value: %u\n", largeValue);
        printf("Converted int value: %d\n", (int)convertedValue);
    }

    return 0;
}