#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t buffer_size = 100;
    char *buffer = malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        return 1;
    }
    strncpy(buffer, "Hello, world!", buffer_size - 1);
    buffer[buffer_size - 1] = '\0';  
    printf("String: %s\n", buffer);
    printf("Correct size of memory allocated: %zu\n", buffer_size * sizeof(char));
    free(buffer);
    return 0;
}