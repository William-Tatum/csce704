#include <stdio.h>

void processInput(int index) {
    int data[10] = {0}; // Initialize array to avoid undefined behavior
    if (index < 0 || index >= 10) {
        printf("Index out of bounds\n");
        return;
    }
    data[index] = 42;
    printf("Value at index %d is %d\n", index, data[index]);
}

int main() {
    int userInput;
    printf("Enter an index: ");
    if (scanf("%d", &userInput) != 1) { // Check if scanf was successful
        printf("Invalid input\n");
        return 1;
    }
    processInput(userInput);
    return 0;
}