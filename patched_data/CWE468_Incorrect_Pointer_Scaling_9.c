#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    ptr += 2;
    printf("%d\n", *ptr);
    int *correctPointer = ptr + 1;
    printf("%d\n", *correctPointer);
    return 0;
}