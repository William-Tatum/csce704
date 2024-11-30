#include <stdio.h>

int main() {
    int *ptr;
    int someData = 123;
    
    ptr = &someData; // Correct way to assign a pointer
    printf("Value at ptr: %d\n", *ptr);
    
    return 0;
}