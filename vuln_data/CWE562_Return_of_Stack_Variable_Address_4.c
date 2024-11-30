#include <stdio.h>

int* returnStackVariableAddress() {
    int x = 42;
    return &x;
}

int main() {
    int* dangerousPointer = returnStackVariableAddress();
    printf("Value: %d\n", *dangerousPointer);
    return 0;
}