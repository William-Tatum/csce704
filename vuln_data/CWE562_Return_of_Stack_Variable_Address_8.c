#include <stdio.h>

int* dangerousFunction() {
    int localVariable = 42;
    return &localVariable;
}

int main() {
    int* ptr = dangerousFunction();
    printf("Dereferenced value: %d\n", *ptr);
    return 0;
}