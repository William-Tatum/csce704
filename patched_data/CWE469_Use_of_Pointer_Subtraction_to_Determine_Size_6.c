#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2;
    size_t size;

    ptr1 = (int*)malloc(5 * sizeof(int));
    if (ptr1 == NULL) {
        return 1;
    }

    ptr2 = (int*)malloc(5 * sizeof(int));
    if (ptr2 == NULL) {
        free(ptr1);
        return 1;
    }

    size = 5 * sizeof(int); // Correct size is known from allocation
    printf("Correct size calculated: %zu\n", size);

    free(ptr1);
    free(ptr2);

    return 0;
}