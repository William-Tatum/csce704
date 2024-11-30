#include <stdio.h>

int* getStackVariableAddress() {
    int localVariable = 42;
    return &localVariable;
}

int main() {
    int *ptr = getStackVariableAddress();
    printf("Value at returned address: %d\n", *ptr);
    return 0;
}