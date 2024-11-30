#include <stdio.h>

int main() {
    int arr[10] = {0}; // Initialize array elements to 0
    int index;

    printf("Enter an array index: ");
    if (scanf("%d", &index) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (index < 0 || index >= 10) {
        printf("Index out of bounds.\n");
        return 1;
    }

    arr[index] = 100;
    printf("Element at index %d set to 100.\n", index);

    return 0;
}