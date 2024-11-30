#include <stdio.h>

void calculateSize(int *array1, int *array2) {
    ptrdiff_t size1 = &array1[5] - &array1[0];
    ptrdiff_t size2 = &array2[5] - &array2[0];
    printf("Size calculated for array1: %td\n", size1);
    printf("Size calculated for array2: %td\n", size2);
}

int main() {
    int array1[10];
    int array2[10];
    calculateSize(array1, array2);
    return 0;
}