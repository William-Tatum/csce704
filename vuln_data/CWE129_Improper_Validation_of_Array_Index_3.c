#include <stdio.h>

void processInput(int index) {
    int data[10];
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
    scanf("%d", &userInput);
    processInput(userInput);
    return 0;
}