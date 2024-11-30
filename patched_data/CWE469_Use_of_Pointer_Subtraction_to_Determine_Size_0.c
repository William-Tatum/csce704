#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void safe_function() {
    char *buffer1 = malloc(50);
    char *buffer2 = malloc(50);
    if (!buffer1 || !buffer2) {
        free(buffer1);
        free(buffer2);
        return;
    }
    strncpy(buffer1, "Hello", 49);
    buffer1[49] = '\0';
    strncpy(buffer2, "World", 49);
    buffer2[49] = '\0';
    ptrdiff_t diff = buffer2 - buffer1;
    printf("Difference: %td\n", diff);
    free(buffer1);
    free(buffer2);
}

int main() {
    safe_function();
    return 0;
}