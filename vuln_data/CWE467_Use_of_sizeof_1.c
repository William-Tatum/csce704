#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = malloc(100 * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }
    strncpy(buffer, "Hello, world!", 100);
    printf("String: %s\n", buffer);
    printf("Size of memory allocated incorrectly: %zu\n", sizeof(buffer));
    printf("Correct size of memory allocated: %zu\n", 100 * sizeof(char));
    free(buffer);
    return 0;
}