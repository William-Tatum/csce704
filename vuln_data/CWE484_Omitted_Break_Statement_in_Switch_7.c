#include <stdio.h>

void processInput(int input) {
    switch (input) {
        case 1:
            printf("Processing option 1\n");
        case 2:
            printf("Processing option 2\n");
            break;
        case 3:
            printf("Processing option 3\n");
            break;
        default:
            printf("Invalid option\n");
    }
}

int main() {
    int userInput;
    printf("Enter an option (1, 2, 3): ");
    scanf("%d", &userInput);
    processInput(userInput);
    return 0;
}