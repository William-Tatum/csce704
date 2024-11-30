#include <stdio.h>

int* getStackVariableAddress() {
    int stackVariable = 42;
    return &stackVariable;
}

int main() {
    int* ptr = getStackVariableAddress();
    printf("Value: %d\n", *ptr); // Undefined behavior: dereferencing a dangling pointer
    return 0;
}