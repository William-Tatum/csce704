#include <stdio.h>

void printArrayElement(int *arr, int size, int index) {
    if (index < 0 || index >= size) {
        printf("Index out of bounds\n");
        return;
    }
    printf("Element at index %d: %d\n", index, arr[index]);
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int index = 5; // Out of bounds index
    printArrayElement(numbers, size, index);
    return 0;
}