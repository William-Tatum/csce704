#include <stdio.h>

int main() {
    unsigned int largeValue = 4000000000;
    int convertedValue = (int) largeValue;

    printf("Original unsigned int value: %u\n", largeValue);
    printf("Converted int value: %d\n", convertedValue);

    return 0;
}