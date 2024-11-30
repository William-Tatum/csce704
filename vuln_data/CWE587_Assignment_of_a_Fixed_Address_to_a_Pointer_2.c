#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pointer;
    pointer = (int *)0x12345678;

    printf("Pointer address: %p\n", (void *)pointer);

    return 0;
}