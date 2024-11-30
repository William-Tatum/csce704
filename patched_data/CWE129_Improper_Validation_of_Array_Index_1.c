#include <stdio.h>

void printElement(int index) {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(array[0]);

    if (index >= 0 && index < size) {
        printf("Element at index %d is %d\n", index, array[index]);
    } else {
        printf("Invalid index: %d\n", index);
    }
}

int main() {
    int userInput;
    printf("Enter an array index: ");
    if (scanf("%d", &userInput) == 1) {
        printElement(userInput);
    } else {
        printf("Invalid input\n");
        while (getchar() != '\n'); // Clear the input buffer
    }
    return 0;
}