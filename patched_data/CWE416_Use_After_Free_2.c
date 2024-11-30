#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int) * 5);
    if (!ptr) {
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        ptr[i] = i;
    }

    free(ptr);

    int *new_ptr = (int *)malloc(sizeof(int) * 5);
    if (!new_ptr) {
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        new_ptr[i] = i + 5;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", new_ptr[i]);
    }

    free(new_ptr);

    return 0;
}