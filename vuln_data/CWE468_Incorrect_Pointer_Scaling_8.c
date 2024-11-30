#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    char *charPtr = (char *)arr;
    int *intPtr = arr;
    printf("Using charPtr: %d\n", *(int *)(charPtr + 1 * sizeof(int)));
    printf("Using intPtr: %d\n", *(intPtr + 1));
    return 0;
}