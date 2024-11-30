#include <stdio.h>

int process_value(int value, int max) {
    int min = 0;
    if (value < min || value > max) {
        printf("Error: Value out of range!\n");
        return -1;
    }
    // Perform operations assuming value is within the valid range
    printf("Value is within the valid range.\n");
    return 0;
}

int main() {
    int value = -5;
    int max = 10;
    process_value(value, max);
    return 0;
}