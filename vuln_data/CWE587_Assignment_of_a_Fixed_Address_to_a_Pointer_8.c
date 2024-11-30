#include <stdio.h>

int main() {
    int *ptr = (int *)0x12345678; // This is a bad practice: assigning a fixed address
    if (ptr != NULL) {
        printf("Pointer is set to a fixed address: %p\n", ptr);
    } else {
        printf("Pointer is NULL.\n");
    }
    return 0;
}