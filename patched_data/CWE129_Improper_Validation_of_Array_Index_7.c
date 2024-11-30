#include <stdio.h>
#include <stdlib.h>

int getUserInput();
void handleArrayValue(int value);

int main() {
    int array[10] = {0}; // Initialize the array to prevent using uninitialized values
    int index = getUserInput();
    if (index >= 0 && index < 10) {
        handleArrayValue(array[index]);
    } else {
        fprintf(stderr, "Invalid array index.\n");
    }
    return 0;
}

int getUserInput() {
    int input;
    printf("Enter an index: ");
    if (scanf("%d", &input) != 1) {
        fprintf(stderr, "Error reading input.\n");
        exit(EXIT_FAILURE);
    }
    return input;
}

void handleArrayValue(int value) {
    printf("Array value: %d\n", value);
}