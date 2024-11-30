#include <stdio.h>

int main() {
    int largeValue = 300;
    char smallValue;

    smallValue = largeValue;

    printf("Original value: %d\n", largeValue);
    printf("Truncated value: %d\n", smallValue);

    return 0;
}