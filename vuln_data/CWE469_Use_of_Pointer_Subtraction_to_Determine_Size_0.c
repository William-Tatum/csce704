#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unsafe_function() {
    char *buffer1 = malloc(50);
    char *buffer2 = malloc(50);
    if (!buffer1 || !buffer2) {
        if (buffer1) free(buffer1);
        if (buffer2) free(buffer2);
        return;
    }
    strcpy(buffer1, "Hello");
    strcpy(buffer2, "World");
    intptr_t diff = buffer2 - buffer1;
    printf("Difference: %ld\n", diff);
    free(buffer1);
    free(buffer2);
}

int main() {
    unsafe_function();
    return 0;
}