#include <stdio.h>

int main() {
    int number = 0; // Initialize variable to prevent undefined behavior
    printf("Enter a number: ");
    if (scanf("%d", &number) != 1) { // Check if input was successful
        fprintf(stderr, "Invalid input.\n");
        return 1; // Return error code if input fails
    }
    if (number > 0) {
        printf("Number is positive: %d\n", number);
    } else {
        printf("Number is zero or negative: %d\n", number);
    }
    return 0;
}