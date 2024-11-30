#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;
    ptr = ptr + 2; // Moves to numbers[2] correctly
    printf("Value: %d\n", *ptr);

    int *intPtr = numbers;
    intPtr = intPtr + 2; // Moves to numbers[2] correctly
    printf("Correct Value: %d\n", *intPtr);

    return 0;
}