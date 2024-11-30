#include <stdio.h>
#include <stdint.h>

int main() {
    int32_t largeValue = 50000;
    int16_t smallValue;
    smallValue = (int16_t)largeValue;
    printf("Original value: %d\n", largeValue);
    printf("Converted value: %d\n", smallValue);
    return 0;
}