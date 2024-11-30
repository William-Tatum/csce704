#include <stdio.h>
#include <stdlib.h>

int main() {
    int value = 42;
    int *ptr = &value;
    *ptr = 42;
    printf("Value: %d\n", *ptr);
    return 0;
}