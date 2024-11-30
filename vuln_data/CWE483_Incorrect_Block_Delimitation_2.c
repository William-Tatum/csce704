#include <stdio.h>

int main() {
    int value = 3;

    if (value > 0)
        printf("Value is positive\n");
        value = -value; // This statement is not part of the intended block

    printf("Absolute value: %d\n", value);

    return 0;
}