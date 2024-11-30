#include <stdio.h>

void performAction(int option) {
    switch (option) {
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
    int userOption;
    printf("Please enter an option (1-3): ");
    if (scanf("%d", &userOption) != 1) {
        printf("Input error. Exiting.\n");
        return 1;
    }
    performAction(userOption);
    return 0;
}