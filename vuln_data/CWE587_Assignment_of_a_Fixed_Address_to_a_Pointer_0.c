#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)0x1000; 
    *ptr = 42; 
    printf("Value at fixed address: %d\n", *ptr);
    return 0;
}