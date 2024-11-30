#include <stdio.h>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;

    ptr += 1; // Should point to 20
    printf("Value at ptr: %d\n", *ptr); // Correctly prints 20

    char *charPtr = (char *)numbers;
    charPtr += 1; // Incorrect scaling, points into the middle of the first int
    printf("Incorrect value at charPtr: %d\n", *(int *)charPtr); // Likely incorrect value

    return 0;
}