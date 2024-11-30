#include <stdio.h>

void printArrayElements(int *arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int length = 5;
    printArrayElements(numbers, length);
    return 0;
}