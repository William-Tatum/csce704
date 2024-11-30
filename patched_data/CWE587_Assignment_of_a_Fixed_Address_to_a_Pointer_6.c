#include <stdio.h>

int main() {
    int value = 42;
    int *ptr = &value;
    if (ptr != NULL) {
        printf("Value pointed to by ptr: %d\n", *ptr);
    } else {
        printf("Pointer is NULL.\n");
    }
    return 0;
}