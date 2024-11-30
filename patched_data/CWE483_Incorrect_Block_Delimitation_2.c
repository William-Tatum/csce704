#include <stdio.h>

int main() {
    int value = 3;

    if (value > 0) {
        printf("Value is positive\n");
        value = -value;
    }

    printf("Absolute value: %d\n", value);

    return 0;
}