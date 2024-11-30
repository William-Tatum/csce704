#include <stdio.h>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int index, value;

    printf("Enter an index to read: ");
    scanf("%d", &index);

    // Vulnerability: No bounds checking on index
    value = numbers[index];

    printf("Value at index %d is %d\n", index, value);

    return 0;
}