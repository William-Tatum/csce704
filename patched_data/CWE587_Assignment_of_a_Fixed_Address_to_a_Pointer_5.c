#include <stdio.h>

int main() {
    int *ptr;
    int someData = 123;
    
    // Properly initialize the pointer
    ptr = &someData; 
    // Check if the pointer is not null before dereferencing
    if (ptr != NULL) {
        printf("Value at ptr: %d\n", *ptr);
    } else {
        printf("Pointer is null.\n");
    }
    
    return 0;
}