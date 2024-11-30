#include <stdio.h>

int main() {
    int userInput;
    printf("Enter your choice: ");
    if (scanf("%d", &userInput) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Processing input...\n");
    if (userInput == 1) {
        printf("Option 1 selected.\n");
    } else {
        printf("Other option selected.\n");
    }
    return 0;
}