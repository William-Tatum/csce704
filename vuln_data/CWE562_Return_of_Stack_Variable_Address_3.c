#include <stdio.h>

int* getNumber() {
    int number = 42;
    return &number; // Returning address of a stack variable
}

int main() {
    int* ptr = getNumber();
    printf("Value at returned pointer: %d\n", *ptr); // Undefined behavior
    return 0;
}