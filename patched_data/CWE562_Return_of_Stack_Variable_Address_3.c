#include <stdio.h>
#include <stdlib.h>

int* getNumber() {
    int* number = malloc(sizeof(int));
    if (number != NULL) {
        *number = 42;
    }
    return number;
}

int main() {
    int* ptr = getNumber();
    if (ptr != NULL) {
        printf("Value at returned pointer: %d\n", *ptr);
        free(ptr);
    }
    return 0;
}