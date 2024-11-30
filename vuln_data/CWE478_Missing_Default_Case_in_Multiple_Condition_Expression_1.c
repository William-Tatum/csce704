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
    int userCommand = 4;
    processCommand(userCommand);
    return 0;
}