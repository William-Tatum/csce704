#include <stdio.h>

int* returnStackAddress() {
    int localVar = 42;
    return &localVar;
}

int main() {
    int* ptr = returnStackAddress();
    printf("Value: %d\n", *ptr); // Undefined behavior
    return 0;
}