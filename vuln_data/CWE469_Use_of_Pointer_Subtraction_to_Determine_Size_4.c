#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer1 = (char *)malloc(50);
    char *buffer2 = (char *)malloc(50);

    strncpy(buffer1, "Hello, World!", 50);
    strncpy(buffer2, "Another buffer", 50);

    ptrdiff_t difference = buffer2 - buffer1;
    size_t size = difference * sizeof(char);

    printf("Calculated size: %zu\n", size);

    free(buffer1);
    free(buffer2);

    return 0;
}