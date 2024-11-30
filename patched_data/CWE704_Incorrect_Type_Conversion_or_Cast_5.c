#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool safeConversion(int32_t original, int16_t *converted) {
    if (original > INT16_MAX || original < INT16_MIN) {
        return false;
    }
    *converted = (int16_t)original;
    return true;
}

int main() {
    int32_t largeValue = 50000;
    int16_t smallValue;
    if (safeConversion(largeValue, &smallValue)) {
        printf("Original value: %d\n", largeValue);
        printf("Converted value: %d\n", smallValue);
    } else {
        printf("Error: Value %d is out of range for int16_t\n", largeValue);
    }
    return 0;
}