#include <stdio.h>

int main() {
    int largeValue = 300;
    char smallValue;

    if (largeValue > CHAR_MAX || largeValue < CHAR_MIN) {
        fprintf(stderr, "Error: value out of range for char type.\n");
        return 1;
    }

    smallValue = (char)largeValue;

    printf("Original value: %d\n", largeValue);
    printf("Truncated value: %d\n", smallValue);

    return 0;
}