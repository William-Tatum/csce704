#include <stdio.h>

void example() {
    int value = 42;
    int *ptr = &value;
    printf("The value is: %d\n", *ptr);
}

int main() {
    example();
    return 0;
}