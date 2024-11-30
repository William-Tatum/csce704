#include <stdio.h>

int main() {
    int *ptr;
    int value = 42;
    ptr = &value;
    printf("Value pointed to by ptr: %d\n", *ptr);
    return 0;
}