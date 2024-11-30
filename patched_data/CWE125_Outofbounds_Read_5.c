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
    int index;
    printf("Enter an index (0 to %d): ", size - 1);
    if (scanf("%d", &index) != 1 || index < 0 || index >= size) {
        printf("Invalid input or index out of bounds\n");
        return 1;
    }
    printArrayElement(numbers, size, index);
    return 0;
}