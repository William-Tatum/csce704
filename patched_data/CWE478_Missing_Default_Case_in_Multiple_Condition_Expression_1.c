#include <stdio.h>

void processCommand(int command) {
    switch (command) {
        case 1:
            printf("Process command 1\n");
            break;
        case 2:
            printf("Process command 2\n");
            break;
        case 3:
            printf("Process command 3\n");
            break;
        default:
            printf("Unknown command\n");
            break;
    }
}

int main() {
    int userCommand;
    printf("Enter a command (1-3): ");
    if (scanf("%d", &userCommand) != 1 || (userCommand < 1 || userCommand > 3)) {
        printf("Invalid input. Please enter a number between 1 and 3.\n");
    } else {
        processCommand(userCommand);
    }
    return 0;
}