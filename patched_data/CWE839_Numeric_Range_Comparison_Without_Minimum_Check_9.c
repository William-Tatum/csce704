#include <stdio.h>

int process_value(int value, int min, int max) {
    if (value < min || value > max) {
        printf("Error: Value out of range!\n");
        return -1;
    }
    printf("Value is within the valid range.\n");
    return 0;
}

int main() {
    int value = -5;
    int min = 0;
    int max = 10;
    process_value(value, min, max);
    return 0;
}