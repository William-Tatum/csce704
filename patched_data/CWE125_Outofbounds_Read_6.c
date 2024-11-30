#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int index, value;
    int array_size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Enter an index to read: ");
    scanf("%d", &index);

    if (index >= 0 && index < array_size) {
        value = numbers[index];
        printf("Value at index %d is %d\n", index, value);
    } else {
        printf("Error: Index out of bounds\n");
    }

    return 0;
}