#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10];
    int index;
    printf("Enter an index: ");
    if (scanf("%d", &index) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    if (index < 0 || index >= 10) {
        printf("Index out of bounds\n");
        return 1;
    }
    array[index] = 42;
    printf("Value at index %d is %d\n", index, array[index]);
    return 0;
}