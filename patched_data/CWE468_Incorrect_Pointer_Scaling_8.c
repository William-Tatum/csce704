#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *intPtr = arr;
    printf("Using intPtr: %d\n", *(intPtr + 1));
    return 0;
}