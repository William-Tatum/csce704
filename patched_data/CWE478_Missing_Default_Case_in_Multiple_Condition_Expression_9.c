#include <stdio.h>

void processInput(int input) {
    switch(input) {
        case 1:
            printf("Processing case 1.\n");
            break;
        case 2:
            printf("Processing case 2.\n");
            break;
        case 3:
            printf("Processing case 3.\n");
            break;
        default:
            printf("Default case handling.\n");
            break;
    }
}

int main() {
    int input;
    printf("Enter a number: ");
    if (scanf("%d", &input) != 1) {
        fprintf(stderr, "Invalid input. Exiting.\n");
        return 1;
    }
    processInput(input);
    return 0;
}