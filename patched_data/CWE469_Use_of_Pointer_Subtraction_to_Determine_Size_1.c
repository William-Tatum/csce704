#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer1 = (char *)malloc(100);
    if (!buffer1) {
        perror("Failed to allocate memory for buffer1");
        exit(EXIT_FAILURE);
    }

    char *buffer2 = (char *)malloc(100);
    if (!buffer2) {
        perror("Failed to allocate memory for buffer2");
        free(buffer1);
        exit(EXIT_FAILURE);
    }

    size_t fixed_size = 100;
    printf("Fixed Size: %zu\n", fixed_size);

    free(buffer1);
    free(buffer2);
    return 0;
}