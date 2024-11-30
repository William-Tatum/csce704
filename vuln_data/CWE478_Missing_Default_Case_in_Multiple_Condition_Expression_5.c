#include <stdio.h>

void processInput(int input) {
    switch (input) {
        case 1:
            printf("Option 1 selected.\n");
            break;
        case 2:
            printf("Option 2 selected.\n");
            break;
        case 3:
            printf("Option 3 selected.\n");
            break;
        default:
            printf("Invalid option selected.\n");
            break;
    }
}

int main() {
    int user_input;
    printf("Enter an option (1-3): ");
    scanf("%d", &user_input);
    processInput(user_input);
    return 0;
}