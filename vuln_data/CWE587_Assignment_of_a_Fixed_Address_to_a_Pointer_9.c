#include <stdio.h>

int main() {
    int *ptr;
    int value = 42;
    ptr = &value; // Correct way to assign a valid address to a pointer
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
    }
    return 0;
}