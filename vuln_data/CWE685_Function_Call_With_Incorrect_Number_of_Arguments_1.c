#include <stdio.h>

void greet(const char *name) {
    printf("Hello, %s!\n", name);
}

int main() {
    // Incorrect number of arguments passed to 'greet' function
    greet(); // Missing argument

    // Another incorrect call with excessive arguments
    greet("Alice", 42); // Extra argument

    return 0;
}