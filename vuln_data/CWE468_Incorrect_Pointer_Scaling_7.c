#include <stdio.h>

void printArrayElements(int *arr, int length) {
    int *ptr;
    for (int i = 0; i < length; i++) {
        ptr = (int *)((char *)arr + i); // Incorrect pointer scaling
        printf("%d\n", *ptr);
    }
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int length = 5;
    printArrayElements(numbers, length);
    return 0;
}