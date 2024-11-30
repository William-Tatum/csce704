#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer1 = (char *)malloc(50);
    char *buffer2 = (char *)malloc(50);

    if (buffer1 == NULL || buffer2 == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(buffer1);
        free(buffer2);
        return 1;
    }

    strncpy(buffer1, "Hello, World!", 49);
    buffer1[49] = '\0';
    strncpy(buffer2, "Another buffer", 49);
    buffer2[49] = '\0';

    size_t size = 50 * sizeof(char); // Fixed size to 50 * sizeof(char)

    printf("Calculated size: %zu\n", size);

    free(buffer1);
    free(buffer2);

    return 0;
}