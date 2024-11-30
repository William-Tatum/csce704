#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;

    ptr += 1; // Correctly points to 20
    printf("Value at ptr: %d\n", *ptr); // Correctly prints 20

    int *intPtr = numbers;
    intPtr += 1; // Correct scaling for int pointer
    printf("Correct value at intPtr: %d\n", *intPtr); // Correct value

    return 0;
}