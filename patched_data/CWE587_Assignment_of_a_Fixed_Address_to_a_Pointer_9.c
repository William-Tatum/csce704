#include <stdio.h>

int main() {
    int *ptr = NULL;
    int value = 42;
    ptr = &value;
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
    }
    return 0;
}