#include <stdio.h>

int* getValue() {
    int stackVar = 42;
    return &stackVar;
}

int main() {
    int* ptr = getValue();
    printf("Value: %d\n", *ptr); // This may crash or print unexpected value
    return 0;
}