#include <stdio.h>
#include <stdlib.h>

int main() {
    char *chunk1 = malloc(100);
    char *chunk2 = malloc(100);
    if (chunk1 == NULL || chunk2 == NULL) {
        return 1;
    }

    size_t distance = chunk2 - chunk1;
    printf("Distance: %zu\n", distance);

    free(chunk1);
    free(chunk2);
    return 0;
}