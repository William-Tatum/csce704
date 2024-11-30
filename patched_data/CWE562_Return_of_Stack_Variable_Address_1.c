#include <stdio.h>
#include <stdlib.h>

int* getNumber() {
    int *num = malloc(sizeof(int));
    if (num != NULL) {
        *num = 42;
    }
    return num;
}

int main() {
    int *ptr = getNumber();
    if (ptr != NULL) {
        printf("Value: %d\n", *ptr);
        free(ptr);
    }
    return 0;
}