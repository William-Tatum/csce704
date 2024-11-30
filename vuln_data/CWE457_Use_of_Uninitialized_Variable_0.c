#include <stdio.h>

void printValue() {
    int value;
    printf("Uninitialized value: %d\n", value);
}

int main() {
    printValue();
    return 0;
}