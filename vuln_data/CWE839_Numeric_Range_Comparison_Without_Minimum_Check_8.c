#include <stdio.h>
#include <stdlib.h>

void processInput(int input) {
    int min = 0;
    int max = 10;

    if (input >= min && input <= max) {
        printf("Input is within the valid range.\n");
        // Additional logic for processing the valid input
    } else {
        printf("Input is out of the valid range.\n");
        // Handle out of range input
    }
}

int main() {
    int userInput;
    printf("Enter a number: ");
    if (scanf("%d", &userInput) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    processInput(userInput);
    return 0;
}