#include <stdio.h>
#include <stdlib.h>

void double_free_example() {
    char *buffer = malloc(100);
    if (buffer == NULL) {
        return;
    }

    free(buffer);
    buffer = NULL; // Preventing double free by nullifying the pointer
}

int main() {
    double_free_example();
    return 0;
}