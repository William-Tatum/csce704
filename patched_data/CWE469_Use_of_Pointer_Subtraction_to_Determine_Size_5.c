#include <stdio.h>
#include <stdlib.h>

int main() {
    char *chunk1 = malloc(100);
    if (chunk1 == NULL) {
        return 1;
    }

    char *chunk2 = malloc(100);
    if (chunk2 == NULL) {
        free(chunk1);
        return 1;
    }

    ptrdiff_t distance = chunk2 - chunk1;
    printf("Distance: %td\n", distance);

    free(chunk1);
    free(chunk2);
    return 0;
}