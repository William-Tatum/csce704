#include <stdio.h>

void calculateSize(int *array1, size_t size1, int *array2, size_t size2) {
    printf("Size calculated for array1: %zu\n", size1);
    printf("Size calculated for array2: %zu\n", size2);
}

int main() {
    int array1[10];
    int array2[10];
    calculateSize(array1, sizeof(array1) / sizeof(array1[0]), array2, sizeof(array2) / sizeof(array2[0]));
    return 0;
}