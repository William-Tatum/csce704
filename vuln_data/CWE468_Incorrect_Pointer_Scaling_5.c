#include <stdio.h>

int main() {
    int arr[5] = {0, 1, 2, 3, 4};
    int *ptr = arr;
    // Incorrect pointer scaling
    ptr = ptr + 2; // Moves to arr[2]
    printf("Value: %d\n", *(char *)ptr); // Incorrectly uses a different data type, leading to incorrect result
    return 0;
}