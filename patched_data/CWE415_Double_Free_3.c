#include <stdlib.h>
#include <stdio.h>

int main() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        return 1;
    }

    *ptr = 42;
    printf("%d\n", *ptr);

    free(ptr);
    ptr = NULL;

    return 0;
}