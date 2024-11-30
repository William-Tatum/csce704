#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buffer1 = (char *)malloc(100);
    char *buffer2 = (char *)malloc(100);
    size_t incorrect_size = buffer2 - buffer1;
    printf("Incorrect Size: %zu\n", incorrect_size);
    free(buffer1);
    free(buffer2);
    return 0;
}