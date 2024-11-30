#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;
    ptr = ptr + 2; // Incorrect scaling, moves to numbers[2] correctly
    printf("Value: %d\n", *ptr);

    char *charPtr = (char *) numbers;
    charPtr = charPtr + 2; // Incorrect scaling, moves 2 bytes instead of 2 integers
    printf("Incorrect Value: %d\n", *((int *)charPtr));

    return 0;
}