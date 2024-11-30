#include <stdio.h>

int main() {
    int arr[5] = {0, 1, 2, 3, 4};
    int *ptr = arr;
    ptr = ptr + 2; // Moves to arr[2]
    printf("Value: %d\n", *ptr);
    return 0;
}