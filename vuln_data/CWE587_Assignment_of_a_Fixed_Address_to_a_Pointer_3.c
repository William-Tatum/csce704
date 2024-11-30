#include <stdio.h>

void example() {
    int *ptr;
    int value = 42;
    ptr = &value;
    printf("The value is: %d\n", *ptr);
}

int main() {
    example();
    return 0;
}