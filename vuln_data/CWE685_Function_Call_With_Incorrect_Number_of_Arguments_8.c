#include <stdio.h>

// Function declaration with one parameter
void printMessage(const char* message);

int main() {
    // Calling the function with incorrect number of arguments
    printMessage("Hello, World!", 123);
    return 0;
}

// Function definition
void printMessage(const char* message) {
    printf("%s\n", message);
}