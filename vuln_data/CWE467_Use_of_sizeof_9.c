#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = (char *)malloc(100 * sizeof(char));
    if (buffer == NULL) {
        return -1;
    }
    memset(buffer, 0, 100);
    printf("Size of buffer: %zu\n", sizeof(buffer));
    free(buffer);
    return 0;
}